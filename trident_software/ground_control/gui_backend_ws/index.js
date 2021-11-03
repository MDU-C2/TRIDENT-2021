


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
    this.express = require('express');
    //Setup express node and port
    this.app = this.express();
    this.port = process.env.PORT || 8080;
    this.server = null;
    this.io = null;
  }

  init()
  {
    // route user to gui folder
    this.app.use(this.express.static('../gui'));
    //Allow gui to send POST message in JSON format to index.js
    this.app.use(this.express.json());
    this.app.use(this.express.urlencoded({ extended: true }));
    //Setup http server, which will server the socket.io server
    this.server = require('http').createServer(this.app);
    //Setup socket.io server
    this.io = require("socket.io")(this.server, {  
      cors: {
        origin: "http://localhost:8080",
        methods: ["GET", "POST"]  
      }
    });
  }

  start(ROS2handle)
  {

    this.heartbeat(ROS2handle); //Heartbeat handler
    this.getStates(ROS2handle); //Get states handler
    this.server.listen(this.port);
    console.log('Server started at http://localhost:' + this.port);

    process.on('SIGINT', function() {
      console.log('Shutting down server.');
      process.exit();
    });
  }

  heartbeat(ROS2handle)
  {
    //Check for hearbeat every 1s
    setInterval(() => {
      this.io.emit('heartbeat',{'athena':ROS2handle.heartbeatAthena.active, 'naiad':ROS2handle.heartbeatNaiad.active});
      ROS2handle.heartbeatAthena.active = false;
            ROS2handle.heartbeatNaiad.active = false;
    },1000);
  }

  getStates(ROS2handle)
  {
    //Fetch states from each module every 1s
    setInterval(() => {
      var request = {}; //Empty request

      /*
        Athena
      */
      //Get state from Athena mission control module
      ROS2handle.getStatesAthena.missionControl.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesAthena.missionControl.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Athena',module:'missionControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena navigation module
      ROS2handle.getStatesAthena.navigation.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesAthena.navigation.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Athena',module:'navigation',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena motor control module
      ROS2handle.getStatesAthena.motorControl.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesAthena.motorControl.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Athena',module:'motorControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena motor driver module
      ROS2handle.getStatesAthena.motorDriver.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesAthena.motorDriver.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Athena',module:'motorDriver',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena position module
      ROS2handle.getStatesAthena.position.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesAthena.position.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Athena',module:'position',state:response.state,intState:response.int_state})
        });
      });

      /*
        Naiad
      */
      //Get state from Athena mission control module
      ROS2handle.getStatesNaiad.missionControl.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesNaiad.missionControl.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Naiad',module:'missionControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad navigation module
      ROS2handle.getStatesNaiad.navigation.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesNaiad.navigation.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Naiad',module:'navigation',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad motor control module
      ROS2handle.getStatesNaiad.motorControl.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesNaiad.motorControl.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Naiad',module:'motorControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad motor driver module
      ROS2handle.getStatesNaiad.motorDriver.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesNaiad.motorDriver.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Naiad',module:'motorDriver',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad position module
      ROS2handle.getStatesNaiad.position.waitForService(1000).then((result) => {
        if (!result) {
          console.log('Error: service not available');
          return;
        }
        ROS2handle.getStatesNaiad.position.sendRequest(request, (response) => {
          this.io.emit('getStates',{target:'Naiad',module:'position',state:response.state,intState:response.int_state})
        });
      });
    },2000);
  }

  handleReq(ROS2handle)
  {
    this.io.on('connect', socket => {
      /*
        Handle requests by client
      */
      socket.on("request", req => {
        switch(req.data.function) {
          /*
            Request to load mission plan
          */
          case 'load_mission_plan':
            //Setup mission parameters
            let mission = rclnodejs.createMessageObject('trident_msgs/msg/Mission');
            let waypoint = rclnodejs.createMessageObject('trident_msgs/msg/Waypoint');
            let wpAction = rclnodejs.createMessageObject('trident_msgs/msg/WaypointAction');
            let pose = rclnodejs.createMessageObject('geometry_msgs/msg/Pose');
            let point = rclnodejs.createMessageObject('geometry_msgs/msg/Point');
            let quaternion = rclnodejs.createMessageObject('geometry_msgs/msg/Quaternion');
            let loadMission = new LoadMission.Request();

            for (var wp of req.data.waypoints)
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
            ROS2handle.loadMissionPlan._serviceName = prefixTopics+req.data.target+"/mission_control/mission/load";
            ROS2handle.loadMissionPlan.waitForService(1000).then((result) => {
              if (!result) {
                console.log('Error: service not available');
                return;
              }
              //console.log(`Sending: ${typeof loadMission}`, loadMission);
              ROS2handle.loadMissionPlan.sendRequest(loadMission, (response) => {
                //Send response back to client
                socket.emit('response',{data:response});
                //Close connection
                socket.disconnect();
              });
            });
            break;
          case 'start_mission_plan':
            const client = new ActionClient(ROS2handle.node, req.data.target);
            client.sendMission();
            break;
          /*
            Request to toggle manual override
          */
          case 'toggle_manual_override':
            var request = {data:req.data.bool};
            ROS2handle.manualOverride._serviceName = prefixTopics+req.data.target+"/motor_control/manual_override";
            ROS2handle.manualOverride.waitForService(1000).then((result) => {
              if (!result) {
                console.log('Error: service not available');
                return;
              }
              ROS2handle.manualOverride.sendRequest(request, (response) => {
                //Send response back to client
                socket.emit('response',{data:response});
                //Close connection
                socket.disconnect();
              });
            });
            break;
          /*
            Request to abort
          */
          case 'abort':
            var request = {};
            ROS2handle.abort._serviceName = prefixTopics+req.data.target+"/abort";
            ROS2handle.abort.waitForService(1000).then((result) => {
              if (!result) {
                console.log('Error: service not available');
                return;
              }
              ROS2handle.abort.sendRequest(request, (response) => {
                //Send response back to client
                socket.emit('response',{data:response});
                //Close connection
                socket.disconnect();
              });
            });
        }
        
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
    this.getStatesAthena = {missionControl:null,navigation:null,motorControl:null,motorDriver:null,position:null};
    this.getStatesNaiad = {missionControl:null,navigation:null,motorControl:null,motorDriver:null,position:null};
    this.startMission = null;
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
    this.manualOverride = this.node.createClient('std_srvs/srv/SetBool', prefixTopics+'athena/motor_control/manual_override');
    //this.manualOverrideAthena._serviceName = 'naiad/motor_control_manual_override';
    //console.log(this.manualOverrideAthena);

    //Create service: load_mission_plan
    this.loadMissionPlan = this.node.createClient('trident_msgs/srv/LoadMission', prefixTopics+'athena/mission_control/mission/load');

    /*
      Create services to get states from Athena and Naiad
    */
    this.getStatesAthena.missionControl = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'athena/mission_control/state/get');
    this.getStatesAthena.navigation     = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'athena/navigation/state/get');
    this.getStatesAthena.motorControl   = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'athena/motor_control/state/get');
    this.getStatesAthena.motorDriver    = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'athena/motor_driver/state/get');
    this.getStatesAthena.position       = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'athena/position/state/get');

    this.getStatesNaiad.missionControl = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'naiad/mission_control/state/get');
    this.getStatesNaiad.navigation     = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'naiad/navigation/state/get');
    this.getStatesNaiad.motorControl   = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'naiad/motor_control/state/get');
    this.getStatesNaiad.motorDriver    = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'naiad/motor_driver/state/get');
    this.getStatesNaiad.position       = this.node.createClient('trident_msgs/srv/GetState', prefixTopics+'naiad/position/state/get');

    //Create service: abort
    this.abort = this.node.createClient('std_srvs/srv/Trigger', prefixTopics+'athena/abort');

    //Create action: start_mission
    //this.startMission = this.node.ActionClient('trident_msgs/action/StartMission', prefixTopics+'athena/mission_control/mission/start');

    this.node.spin();
  }
}

/*
  Action classes
*/
class ActionClient {
  constructor(node,target) {
    this._node = node;
    this.target = target;
    this._actionClient = new rclnodejs.ActionClient(
      node,
      'trident_msgs/action/StartMission',
      prefixTopics+this.target+'/mission_control/mission/start'
    );
  }

  async sendMission() {
    this._node.getLogger().info('Waiting for action server...');
    await this._actionClient.waitForServer();

    const mission = {};

    this._node.getLogger().info('Sending goal request...');
    const goalHandle = await this._actionClient.sendGoal(mission, (feedback) =>
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
        .info(`Goal suceeded with result: ${result}`);
    } else {
      this._node.getLogger().info(`Goal failed with status: ${status}`);
    }

    //rclnodejs.shutdown();
  }

  feedbackCallback(feedback) {
    this._node.getLogger().info(`Received feedback: ${feedback}`);
  }
}

function main()
{
  let server = new Server();
  let ros2 = new ROS2();

  //Setup server and start it
  server.init();
  server.start(ros2);
  server.handleReq(ros2);

  //Setup ros2 and serve messages/services/actions
  ros2.init();
  ros2.startInterfaces();
  
}

main();