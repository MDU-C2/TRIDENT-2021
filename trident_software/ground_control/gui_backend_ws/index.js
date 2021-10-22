const express = require('express');
const rclnodejs = require('rclnodejs');

const app = express();
const port = process.env.PORT || 8082;

// routes will go here
app.use(express.static('../gui'))

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.post('/api/users', function(req, res) {
  const user_id = req.body.id;
  console.log("test");
  res.send({
    'user_id': user_id
  });
});

rclnodejs.init().then(() => {
  const node = new rclnodejs.Node('publisher_example_node');
  const publisher = node.createPublisher('trident_msgs/msg/Num', 'topic');
  let counter = 0;
  setInterval(() => {
    console.log(`Publishing message: Hello ROS ${counter++}`);
    publisher.publish({a:counter});
  }, 1000);
  node.spin();
});

app.listen(port);
console.log('Server started at http://localhost:' + port);

