const express = require('express');
const rclnodejs = require('./node_modules/rclnodejs/index.js')
const LoadMission = rclnodejs.require('trident_msgs/srv/LoadMission');

waypointAction = {
  NO_ACTION:0,
  HOLD:1
}
let prefixTopics = "gc/";

class Server
{
  constructor()
  {
    this.express = express;
    //Setup express node and port
    this.app = this.express();
    this.port = process.env.PORT || 8080;
  }

  init()
  {
    // route user to gui folder
    this.app.use(this.express.static('../gui'));
    //Allow gui to send POST message in JSON format to index.js
    this.app.use(this.express.json());
    this.app.use(this.express.urlencoded({ extended: true }));
  }

  start()
  {
    this.app.listen(this.port);
    console.log('Server started at http://localhost:' + this.port);

    process.on('SIGINT', function() {
      console.log('Shutting down server.');
      process.exit();
    });
  }

  handleReq(ROS2handle)
  {
    //Handler for heartbeat
    this.app.post('/heartbeat', function(req,res) {
      res.send({'athena':ROS2handle.heartbeatAthena.active, 'naiad':ROS2handle.heartbeatNaiad.active});
      //Reset Athena and Naiad active status
      ROS2handle.heartbeatAthena.active = false;
      ROS2handle.heartbeatNaiad.active = false;
    });

    //Handler for service: toggle_manual_control
    this.app.post('/manual_override', function(req,res) {
      const request = {target:req.body.target, mode:req.body.mode};
      ROS2handle.manualOverride._serviceName = prefixTopics+req.body.target+"/motor_control/manual_override";
      ROS2handle.manualOverride.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        console.log(`Sending: ${typeof request}`, request);
        ROS2handle.toggleControlMode.sendRequest(request, (response) => {
          res.send({'success':response.success, 'target':req.body.target});
        });
      });
    });

    //Handler for service: load_mission_plan
    this.app.post('/load_mission_plan', function(req,res) {
      
      //Setup mission parameters
      let mission = rclnodejs.createMessageObject('trident_msgs/msg/Mission');
      let waypoint = rclnodejs.createMessageObject('trident_msgs/msg/Waypoint');
      let wpAction = rclnodejs.createMessageObject('trident_msgs/msg/WaypointAction');
      let pose = rclnodejs.createMessageObject('geometry_msgs/msg/Pose');
      let point = rclnodejs.createMessageObject('geometry_msgs/msg/Point');
      let quaternion = rclnodejs.createMessageObject('geometry_msgs/msg/Quaternion');
      let loadMission = new LoadMission.Request();

      for (var wp of req.body.waypoints)
      {
        wpAction.action_type = waypointAction.NO_ACTION;
        wpAction.action_param = 0;
        point.x = wp[0];
        point.y = wp[1];
        point.z = wp[2];
        //Temporarily set orientation to zero
        quaternion.x = 0.0;
        quaternion.y = 0.0;
        quaternion.z = 0.0;
        quaternion.w = 0.0;
        pose.position = point;
        pose.orientation = quaternion;
        waypoint.pose = pose;
        waypoint.action = wpAction;
        mission.waypoints.push(waypoint);
      }
      loadMission.mission = mission;
      ROS2handle.loadMissionPlan._serviceName = prefixTopics+req.body.target+"/mission_control/mission/load";
      ROS2handle.loadMissionPlan.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        //console.log(`Sending: ${typeof loadMission}`, loadMission);
        ROS2handle.loadMissionPlan.sendRequest(loadMission, (response) => {
          res.send({'success':response.success, 'target':req.body.target});
        });
      });
      
    });

    //Handler for service: abort
    this.app.post('/abort', function(req,res) {
      const request = {target:req.body.target};
      ROS2handle.abort.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.abort.sendRequest(request, (response) => {
          res.send({'success':response.success, 'target':req.body.target});
        });
      });
    });
  }
}

class ROS2
{
  constructor()
  {
    this.rclnodejs = rclnodejs;
    //Require interfaces
    this.node = null;
    this.heartbeatAthena = {handle:null,active:false};
    this.heartbeatNaiad  = {handle:null,active:false};
    this.manualOverride = null;
    this.loadMissionPlan = null;
    this.startMissionPlan = null;
    this.abort = null;
  }

  init()
  {
    //Initialize rclnodejs
    this.rclnodejs.init();
    this.node = new this.rclnodejs.Node('ground_control');
  }

  startInterfaces()
  {
    //Create and start heartbeat listener Athena
    this.heartbeatAthena.handle = this.node.createSubscription('trident_msgs/msg/Num',prefixTopics+'athena/heartbeat', (msg) => {
      this.heartbeatAthena.active = true;
    });

    //Create and start heartbeat listener Naiad
    this.heartbeatNaiad.handle = this.node.createSubscription('trident_msgs/msg/Num',prefixTopics+'naiad/heartbeat', (msg) => {
      this.heartbeatNaiad.active = true;
    });

    //Create service: manual_override (athena)
    this.manualOverrideAthena = this.node.createClient('std_srvs/srv/SetBool', prefixTopics+'athena/motor_control/manual_override');
    //this.manualOverrideAthena._serviceName = 'naiad/motor_control_manual_override';
    //console.log(this.manualOverrideAthena);

    //Create service: load_mission_plan
    this.loadMissionPlan = this.node.createClient('trident_msgs/srv/LoadMission', prefixTopics+'athena/mission_control/mission/load');
    //this.loadMissionPlanNaiad = this.node.createClient('std_srvs/srv/Trigger', 'load_mission_plan/naiad');

    //Create service: start_mission
    //this.startMissionPlanAthena = new StartMissionActionClient(this.node);
    //this.startMissionPlanAthena.sendMission();

    //Create service: abort
    this.abort = this.node.createClient('trident_msgs/srv/Abort', 'abort');

    this.node.spin();
  }
}

/*
  Action classes
*/
class StartMissionActionClient {
  constructor(node) {
    this._node = node;

    this._actionClient = new rclnodejs.ActionClient(
      node,
      'trident_msgs/msg/Mission',
      'startMission'
    );
  }

  async sendMission() {
    this._node.getLogger().info('Waiting for action server...');
    await this._actionClient.waitForServer();

    const mission = {};

    this._node.getLogger().info('Sending goal request...');
    const goalHandle = await this._actionClient.sendMission(mission, (feedback) =>
      this.feedbackCallback(feedback)
    );

    if (!goalHandle.isAccepted()) {
      this._node.getLogger().info('Goal rejected');
      return;
    }

    this._node.getLogger().info('Goal accepted');

    const result = await goalHandle.getResult();

    if (goalHandle.isSucceeded()) {
      this._node
        .getLogger()
        .info(`Goal suceeded with result: ${result.sequence}`);
    } else {
      this._node.getLogger().info(`Goal failed with status: ${status}`);
    }

    //rclnodejs.shutdown();
  }

  feedbackCallback(feedback) {
    this._node.getLogger().info(`Received feedback: ${feedback.sequence}`);
  }
}

function main()
{
  let server = new Server();
  let ros2 = new ROS2();

  //Setup server and start it
  server.init();
  server.start();
  server.handleReq(ros2);

  //Setup ros2 and serve messages/services/actions
  ros2.init();
  ros2.startInterfaces();

  
}

main();