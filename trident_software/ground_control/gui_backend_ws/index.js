const express = require('express');
const rclnodejs = require('./node_modules/rclnodejs/index.js')
const Mission = rclnodejs.require('trident_msgs/msg/Mission');
const LoadMission = rclnodejs.require('trident_msgs/srv/LoadMission');
const Waypoint = rclnodejs.require('trident_msgs/msg/Waypoint');
const WaypointAction = rclnodejs.require('trident_msgs/msg/WaypointAction');
const Pose = rclnodejs.require('geometry_msgs/msg/Pose');

waypointAction = {
  NO_ACTION:0,
  HOLD:1
}

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
    this.app.post('/toggleControl', function(req,res) {
      const request = {target:req.body.target, mode:req.body.mode};
      ROS2handle.toggleControlMode.waitForService(1000).then((result) => {
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
      const request = {};
      //console.log(req.body.waypoints);
      //Setup mission parameters
      let mission = new Mission()
      let waypoint = new Waypoint()
      let wpAction = new WaypointAction()
      wpAction.action_type = waypointAction.NO_ACTION;
      wpAction.action_param = 0;
      let pose = new Pose();
      pose.position.x = 3;
      pose.position.y = 3.0;
      pose.position.z = 3.0;
      pose.orientation.x = 0.0;
      pose.orientation.y = 0.0;
      pose.orientation.z = 0.0;
      pose.orientation.w = 1.0;
      waypoint.pose = pose;
      waypoint.action = wpAction;
      mission.waypoints = [waypoint];
      console.log(mission.waypoints);
      let loadMission = new LoadMission();
      loadMission.mission = mission;
      //this._node.getLogger().info('Loaded mission');
      switch(req.body.target) {
        case 'athena':
          ROS2handle.loadMissionPlanAthena.waitForService(1000).then((result) => {
            if (!result) {
              console.log('Error: service not available');
              return;
            }
            //console.log(`Sending: ${typeof loadMission}`, loadMission);
            ROS2handle.loadMissionPlanAthena.sendRequest(loadMission, (response) => {
              res.send({'success':response.success, 'target':req.body.target});
            });
          });
          break;
        case 'naiad':
          ROS2handle.loadMissionPlanNaiad.waitForService(1000).then((result) => {
            if (!result) {
              console.log('Error: service not available');
              return;
            }
            console.log(`Sending: ${typeof request}`, request);
            ROS2handle.loadMissionPlanNaiad.sendRequest(request, (response) => {
              res.send({'success':response.success, 'target':req.body.target});
            });
          });
          break;
      }
      
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
    this.toggleControlMode = null;
    this.loadMissionPlanAthena = null;
    this.loadMissionPlanNaiad = null;
    this.startMissionPlanAthena = null;
    this.startMissionPlanNaiad = null;
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
    this.heartbeatAthena.handle = this.node.createSubscription('trident_msgs/msg/Num','hearbeat/athena', (msg) => {
      this.heartbeatAthena.active = true;
    });

    //Create and start heartbeat listener Naiad
    this.heartbeatNaiad.handle = this.node.createSubscription('trident_msgs/msg/Num','hearbeat/naiad', (msg) => {
      this.heartbeatNaiad.active = true;
    });

    //Create service: toggle_manual_control
    this.toggleControlMode = this.node.createClient('trident_msgs/srv/ToggleControl', 'toggle_control_mode');

    //Create service: load_mission_plan
    this.loadMissionPlanAthena = this.node.createClient('trident_msgs/srv/LoadMission', 'load_mission_plan/athena');
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