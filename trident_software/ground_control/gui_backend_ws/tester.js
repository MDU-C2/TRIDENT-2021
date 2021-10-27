
const rclnodejs = require('rclnodejs');


rclnodejs
  .init()
  .then(() => {
    const node = rclnodejs.createNode('tester_node');
    let count = 0;

    //hearbeat tester
    const heartbeatPublisherAthena = node.createPublisher('trident_msgs/msg/Num','hearbeat/athena');
    let counter1 = 0;
    setInterval(() => {
      heartbeatPublisherAthena.publish({a:counter1++});
    }, 500);
    
    const heartbeatPublisherNaiad = node.createPublisher('trident_msgs/msg/Num','hearbeat/naiad');
    let counter2 = 0;
    setInterval(() => {
      heartbeatPublisherNaiad.publish({a:counter2++});
    }, 500);


    //toggle control mode tester
    node.createService(
      'trident_msgs/srv/ToggleControl',
      'toggle_control_mode',
      (request, response) => {
        console.log(request);
        console.log('Request to toggle on');
        let result = response.template;
        result.success = true;
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //load mission plan tester (athena)
    node.createService(
      'std_srvs/srv/Trigger',
      'load_mission_plan/athena',
      (request, response) => {
        console.log(request);
        console.log('Request to load mission plan on athena');
        let result = response.template;
        result.success = true;
        result.message = "mission plan loaded on athena";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //load mission plan tester (naiad)
    node.createService(
      'std_srvs/srv/Trigger',
      'load_mission_plan/naiad',
      (request, response) => {
        console.log(request);
        console.log('Request to load mission plan on naiad');
        let result = response.template;
        result.success = true;
        result.message = "mission plan loaded on naiad";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //abort tester
    node.createService(
      'trident_msgs/srv/Abort',
      'abort',
      (request, response) => {
        console.log(request);
        console.log('Request to toggle on');
        let result = response.template;
        result.success = true;
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //toggle mode on naiad
    /*
    node.createService(
      'trident_msgs/srv/ToggleControl',
      'toggle_control_mode',
      (request, response) => {
        console.log('Request to toggle automatic on Athena');
        let result = response.template;
        result.success = true;
        result.message = "automatic toggled";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );*/

    rclnodejs.spin(node);
  })
  .catch((e) => {
    console.log(e);
  });

  process.on('SIGINT', function() {
    console.log('Shutting down server.');
    process.exit();
  });