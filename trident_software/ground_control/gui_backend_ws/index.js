const rclnodejs = require('./node_modules/rclnodejs/index.js'); //ROS2 javascript library
const LoadMission = rclnodejs.require('trident_msgs/srv/LoadMission');
var fs = require('fs'); //File system library
var THREE = require('three');

let prefixTopics = "gc/"; //Prefix used during testing

class Server
{
  constructor()
  {
    //Setup express node and port
    this.express = require('express');
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
        origin: "http://localhost:"+this.port,
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
    //Shutdown program on Ctrl + C
    process.on('SIGINT', function() {
      console.log('Shutting down server.');
      process.exit();
    });
  }

  heartbeat(ROS2handle)
  {
    //Send connection status to gui every 2s and reset status bools.
    //These staus bools are set to true when a new message is received
    setInterval(() => {
      this.io.emit('heartbeat',{'athena':ROS2handle.heartbeatAthena.active, 'naiad':ROS2handle.heartbeatNaiad.active});
        ROS2handle.heartbeatAthena.active = false;
        ROS2handle.heartbeatNaiad.active = false;
    },2000);
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
      ROS2handle.getStatesAthena.missionControl.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesAthena.missionControl._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesAthena.missionControl.sendRequest(request, (response) => {
          this.io.emit('state/get/mission_control',{target:'Athena',module:'missionControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena navigation module
      ROS2handle.getStatesAthena.navigation.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesAthena.missionControl._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesAthena.navigation.sendRequest(request, (response) => {
          this.io.emit('state/get/navigation',{target:'Athena',module:'navigation',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena motor control module
      ROS2handle.getStatesAthena.motorControl.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesAthena.motorControl._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesAthena.motorControl.sendRequest(request, (response) => {
          this.io.emit('state/get/motor_control',{target:'Athena',module:'motorControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena motor driver module
      ROS2handle.getStatesAthena.motorDriver.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesAthena.motorDriver._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesAthena.motorDriver.sendRequest(request, (response) => {
          this.io.emit('state/get/motor_driver',{target:'Athena',module:'motorDriver',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Athena position module
      ROS2handle.getStatesAthena.position.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesAthena.position._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesAthena.position.sendRequest(request, (response) => {
          this.io.emit('state/get/position',{target:'Athena',module:'position',state:response.state,intState:response.int_state})
        });
      });

      /*
        Naiad
      */
      //Get state from Athena mission control module
      ROS2handle.getStatesNaiad.missionControl.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesNaiad.missionControl._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesNaiad.missionControl.sendRequest(request, (response) => {
          this.io.emit('state/get/mission_control',{target:'Naiad',module:'missionControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad navigation module
      ROS2handle.getStatesNaiad.navigation.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesNaiad.navigation._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesNaiad.navigation.sendRequest(request, (response) => {
          this.io.emit('state/get/navigation',{target:'Naiad',module:'navigation',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad motor control module
      ROS2handle.getStatesNaiad.motorControl.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesNaiad.motorControl._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesNaiad.motorControl.sendRequest(request, (response) => {
          this.io.emit('state/get/motor_control',{target:'Naiad',module:'motorControl',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad motor driver module
      ROS2handle.getStatesNaiad.motorDriver.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesNaiad.motorDriver._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesNaiad.motorDriver.sendRequest(request, (response) => {
          this.io.emit('state/get/motor_driver',{target:'Naiad',module:'motorDriver',state:response.state,intState:response.int_state})
        });
      });

      //Get state from Naiad position module
      ROS2handle.getStatesNaiad.position.waitForService(1900).then((result) => {
        if (!result) {
          this.io.emit('state/get/error',{errMsg: 'Error: service '+ROS2handle.getStatesNaiad.position._serviceName+' not available'});
          return;
        }
        ROS2handle.getStatesNaiad.position.sendRequest(request, (response) => {
          this.io.emit('state/get/position',{target:'Naiad',module:'position',state:response.state,intState:response.int_state})
        });
      });
    },500);
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
              wpAction.action_type = 0;
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
            if (req.data.target == 'athena')
            {
              ROS2handle.loadMissionPlanAthena.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.loadMissionPlanAthena.sendRequest(loadMission, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
            else
            {
              ROS2handle.loadMissionPlanNaiad.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.loadMissionPlanNaiad.sendRequest(loadMission, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
            break;
          case 'start_mission_plan':
            const client = new ActionClient(ROS2handle.node, req.data.target, this);
            client.sendMission();
            break;
          /*
            Request to toggle manual override
          */
          case 'toggle_manual_override':
            var request = {data:req.data.bool};
            if (req.data.target == 'athena')
            {
              ROS2handle.manualOverrideAthena.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.manualOverrideAthena.sendRequest(request, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
            else
            {
              ROS2handle.manualOverrideNaiad.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.manualOverrideNaiad.sendRequest(request, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
            break;
          /*
            Request to abort
          */
          case 'abort':
            var request = {};
            if (req.data.target == 'athena')
            {
              ROS2handle.abortAthena.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.abortAthena.sendRequest(request, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
            else
            {
              ROS2handle.abortNaiad.waitForService(1000).then((result) => {
                if (!result) {
                  console.log('Error: service not available');
                  return;
                }
                ROS2handle.abortNaiad.sendRequest(request, (response) => {
                  //Send response back to client
                  socket.emit('response',{data:response});
                  //Close connection
                  socket.disconnect();
                });
              });
            }
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
    this.node = null;
    this.heartbeatAthena = {handle:null,active:false};
    this.heartbeatNaiad  = {handle:null,active:false};
    this.manualOverrideAthena = null;
    this.manualOverrideNaiad = null;
    this.loadMissionPlanAthena = null;
    this.startMissionPlanNaiad = null;
    this.abortAthena = null;
    this.abortNaiad = null;
    this.getStatesAthena = {missionControl:null,navigation:null,motorControl:null,motorDriver:null,position:null};
    this.getStatesNaiad = {missionControl:null,navigation:null,motorControl:null,motorDriver:null,position:null};
    this.startMissionAthena = null;
    this.startMissionNaiad = null;
    this.stateAthena = null;
    this.stateNaiad = null;
    this.logging = null;
  }

  init()
  {
    //Initialize rclnodejs
    this.rclnodejs.init();
    this.node = new this.rclnodejs.Node('ground_control');
  }

  startInterfaces(serverHandle)
  {
    //Create and start state listener Athena
    this.stateAthena = this.node.createSubscription('trident_msgs/msg/State', prefixTopics+'athena/position/state', (msg) => {
      var quaternion = new THREE.Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z);
      var rotation = new THREE.Euler().setFromQuaternion( quaternion, 'XYZ' );
      this.heartbeatAthena.active = true;
      serverHandle.io.emit('state/athena', {x:msg.pose.position.x, y:msg.pose.position.y, yaw:rotation._z*(180/Math.PI)});
    });

    //Create and start state listener Naiad
    this.stateNaiad = this.node.createSubscription('trident_msgs/msg/State', prefixTopics+'naiad/position/state', (msg) => {
      var quaternion = new THREE.Quaternion(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z);
      var rotation = new THREE.Euler().setFromQuaternion( quaternion, 'XYZ' );
      this.heartbeatNaiad.active = true;
      serverHandle.io.emit('state/naiad', {x:msg.pose.position.x, y:msg.pose.position.y, yaw:rotation._z*(180/Math.PI)});
    });

    //Create and start logging listener Athena & Naiad
    this.logging = this.node.createSubscription('rcl_interfaces/msg/Log', '/rosout', (msg) => {
      //Check that log message contains the parameters we're interested in
      if (typeof msg.stamp !== 'undefined' && typeof msg.level !== 'undefined' && 
          typeof msg.name !== 'undefined' && typeof msg.msg !== 'undefined' && 
          typeof msg.file !== 'undefined' && typeof msg.function !== 'undefined' && 
          typeof msg.line !== 'undefined')
      {
        var logTarget = msg.name.substr(0, msg.name.indexOf('.')); //Get target device name
        var date = new Date(msg.stamp * 1000);
        var hours = date.getHours();
        var minutes = "0" + date.getMinutes();
        var seconds = "0" + date.getSeconds();
        var formattedTime = hours + ':' + minutes.substr(-2) + ':' + seconds.substr(-2);
        msg.stamp = formattedTime
        fs.appendFile('logs/'+logTarget+'.log', JSON.stringify(msg)+'\n', function (err) {
          if (err) throw err;
        }); 
        serverHandle.io.emit('logger/'+logTarget, msg);
      }
    });

    //Create service: manual_override
    this.manualOverrideAthena = this.node.createClient('std_srvs/srv/SetBool', prefixTopics+'athena/motor_control/manual_override');
    this.manualOverrideNaiad = this.node.createClient('std_srvs/srv/SetBool', prefixTopics+'naiad/motor_control/manual_override');

    //Create service: load_mission_plan
    this.loadMissionPlanAthena = this.node.createClient('trident_msgs/srv/LoadMission', prefixTopics+'athena/mission_control/mission/load');
    this.loadMissionPlanNaiad = this.node.createClient('trident_msgs/srv/LoadMission', prefixTopics+'naiad/mission_control/mission/load');

    //Create services to get states from Athena and Naiad
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
    this.abortAthena = this.node.createClient('std_srvs/srv/Trigger', prefixTopics+'athena/abort');
    this.abortNaiad = this.node.createClient('std_srvs/srv/Trigger', prefixTopics+'naiad/abort');

    this.node.spin();
  }
}

/*
  Action classes
*/
class ActionClient {
  constructor(node,target,serverHandle) {
    //Setup node for sending load_mission action
    this._node = node;
    this.target = target;
    this.serverHandle = serverHandle;
    this._actionClient = new rclnodejs.ActionClient(
      node,
      'trident_msgs/action/StartMission',
      prefixTopics+this.target+'/mission_control/mission/start'
    );
  }

  async sendMission() {
    //Notify gui that we're waiting for the server
    this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'info', message:'Waiting for action server...'});
    const mission = {};
    //Send goal request to server
    this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'info', message:'Sending goal request...'});
    const goalHandle = await this._actionClient.sendGoal(mission, (feedback) =>
      this.feedbackCallback(feedback)
    );
    //Notify gui if goal isn't accepted
    if (!goalHandle.isAccepted()) {
      this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'error', message:'Goal rejected'});
      return;
    }
    //Notify gui if goas is accepted
    this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'success', message:'Goal accepted'});
    const result = await goalHandle.getResult();
    //When action iscomplete, send result to gui
    if (goalHandle.isSucceeded()) {
      this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'success', message:'Successful mission: '+JSON.stringify(result)});
      this.serverHandle.io.emit('response',{data:{success:true}});
    } else {
      this.serverHandle.io.emit('mission/status',{target:this.target, msgType:'error', message:'Goal not succeded'});
      this.serverHandle.io.emit('response',{data:{success:false}});
    }

  }
  //Feedback function that send the feedback from the server to gui
  feedbackCallback(feedback) {
    this.serverHandle.io.emit('mission/status',{target:this.target, msgType: 'info', message:'Feedback: '+JSON.stringify(feedback)});
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

  //Setup ros2
  ros2.init();
  ros2.startInterfaces(server);
  
}

main();