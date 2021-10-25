
class Server
{
  constructor()
  {
    this.express = require('express');
    //Setup express node and port
    this.app = this.express();
    this.port = process.env.PORT || 8081;
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
    this.app.post('/heartbeat', function(req,res) {
      res.send({'athena':ROS2handle.heartbeatAthena.active, 'naiad':ROS2handle.heartbeatNaiad.active});
        //Reset Athena and Naiad active status
        ROS2handle.heartbeatAthena.active = false;
        ROS2handle.heartbeatNaiad.active = false;
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
  }

  init()
  {
    //Initialize rclnodejs
    this.rclnodejs.init();
    this.node = new this.rclnodejs.Node('publisher_example_node');
  }

  startInterfaces()
  {
    //Start heartbeat Athena
    this.heartbeatAthena.handle = this.node.createSubscription('trident_msgs/msg/Num','hearbeat/athena', (msg) => {
      this.heartbeatAthena.active = true;
    });

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