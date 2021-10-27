
class Server
{
  constructor()
  {
    this.express = require('express');
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
      switch(req.body.target) {
        case 'athena':
          ROS2handle.loadMissionPlanAthena.waitForService(1000).then((result) => {
            if (!result) {
              console.log('Error: service not available');
              return;
            }
            console.log(`Sending: ${typeof request}`, request);
            ROS2handle.loadMissionPlanAthena.sendRequest(request, (response) => {
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
    this.rclnodejs = require('rclnodejs');
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
    this.loadMissionPlanAthena = this.node.createClient('std_srvs/srv/Trigger', 'load_mission_plan/athena');
    this.loadMissionPlanNaiad = this.node.createClient('std_srvs/srv/Trigger', 'load_mission_plan/naiad');

    //Create service: abort
    this.abort = this.node.createClient('trident_msgs/srv/Abort', 'abort');

    this.node.spin();
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