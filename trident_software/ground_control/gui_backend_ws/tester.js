
const rclnodejs = require('rclnodejs');


rclnodejs
  .init()
  .then(() => {
    const node = rclnodejs.createNode('subscription_message_example_node');
    let count = 0;

    node.createSubscription(
      'trident_msgs/msg/Num',
      'topic2',
      (state) => {
        console.log(`Received message No. ${++count}: `, state);
      }
    );

    const publisher = node.createPublisher('trident_msgs/msg/Num','hearbeat/athena');

    let counter = 0;
    setInterval(() => {
      publisher.publish({a:counter++});
    }, 500);

    rclnodejs.spin(node);
  })
  .catch((e) => {
    console.log(e);
  });