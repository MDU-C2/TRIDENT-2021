
const rclnodejs = require('rclnodejs');


rclnodejs
  .init()
  .then(() => {
    const node = rclnodejs.createNode('subscription_message_example_node');
    let count = 0;

    node.createSubscription(
      'trident_msgs/msg/Num',
      'topic',
      (state) => {
        console.log(`Received message No. ${++count}: `, state);
      }
    );

    rclnodejs.spin(node);
  })
  .catch((e) => {
    console.log(e);
  });