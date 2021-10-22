
class Server
{
  constructor()
  {
    this.express = require('express');
    //Setup express node and port
    this.app = this.express();
    this.port = process.env.PORT || 8082;
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
  }

  handleReq()
  {
    this.app.post('/api/users1', function(req,res) {
      const uid = req.body.id;
      res.send({
        'user_id':1
      });
    });

    this.app.post('/api/users2', function(req,res) {
      const uid = req.body.id;
      res.send({
        'user_id':2
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
    this.publisher1 = null;
    this.publisher2 = null;
  }

  init()
  {
    //Initialize rclnodejs
    this.rclnodejs.init();
    this.node = new this.rclnodejs.Node('publisher_example_node');
  }

  setupInterface()
  {
    //Setup publisher1
    this.publisher1 = this.node.createPublisher('trident_msgs/msg/Num', 'topic1');
    //Setup publisher2
    this.publisher2 = this.node.createPublisher('trident_msgs/msg/Num', 'topic2');
    
  }

  startInterfaces()
  {
    //Start publisher1
    setInterval(() => {
      this.publisher1.publish({a:1});
    }, 1000);

    //Start publisher2
    setInterval(() => {
      this.publisher2.publish({a:2});
    }, 1000);

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
  server.handleReq();

  //Setup ros2 and serve messages/services/actions
  ros2.init();
  ros2.setupInterface();
  ros2.startInterfaces();
  
}

main();