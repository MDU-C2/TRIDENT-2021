
const rclnodejs = require('./node_modules/rclnodejs/index.js')
const Mission = rclnodejs.require('trident_msgs/msg/Mission');
const LoadMission = rclnodejs.require('trident_msgs/srv/LoadMission');
const Waypoint = rclnodejs.require('trident_msgs/msg/Waypoint');
const WaypointAction = rclnodejs.require('trident_msgs/msg/WaypointAction');
const Pose = rclnodejs.require('geometry_msgs/msg/Pose');

let prefixTopics = "gc/";
class StartMissionActionServer {
  constructor(node) {
    this._node = node;

    this._actionServer = new rclnodejs.ActionServer(
      node,
      'trident_msgs/msg/Mission',
      'startMission',
      this.executeCallback.bind(this),
      this.goalCallback.bind(this),
      null,
      this.cancelCallback.bind(this)
    );
  }

  async executeCallback(missionHandle) {
    this._node.getLogger().info('Executing goal...');

    const feedbackMessage = new Fibonacci.Feedback();
    const sequence = [0, 1];

    // Start executing the action
    for (let i = 1; i < missionHandle.request.order; i++) {
      // Check if the goal has been canceled
      if (missionHandle.isCancelRequested) {
        missionHandle.canceled();
        this._node.getLogger().info('Goal canceled');
        return new Fibonacci.Result();
      }

      // Update Fibonacci sequence
      sequence.push(sequence[i] + sequence[i - 1]);

      feedbackMessage.sequence = sequence;
      this._node
        .getLogger()
        .info(`Publishing feedback: ${feedbackMessage.sequence}`);

      // Publish the feedback
      missionHandle.publishFeedback(feedbackMessage);

      // Wait for 1 second
      await new Promise((resolve) => setTimeout(resolve, 1000));
    }

    missionHandle.succeed();

    // Populate result message
    const result = new Fibonacci.Result();
    result.sequence = sequence;

    this._node.getLogger().info(`Returning result: ${result.sequence}`);

    return result;
  }

  goalCallback(missionHandle) {
    this._node.getLogger().info('Received goal request');
    return rclnodejs.GoalResponse.ACCEPT;
  }

  cancelCallback(missionHandle) {
    this._node.getLogger().info('Received cancel request');
    return rclnodejs.CancelResponse.ACCEPT;
  }
}

rclnodejs
  .init()
  .then(() => {
    const node = rclnodejs.createNode('tester_node');
    let count = 0;

    //hearbeat tester
    const heartbeatPublisherAthena = node.createPublisher('trident_msgs/msg/Num',prefixTopics+'athena/heartbeat');
    let counter1 = 0;
    setInterval(() => {
      heartbeatPublisherAthena.publish({a:counter1++});
    }, 100);
    
    const heartbeatPublisherNaiad = node.createPublisher('trident_msgs/msg/Num',prefixTopics+'naiad/heartbeat');
    let counter2 = 0;
    setInterval(() => {
      heartbeatPublisherNaiad.publish({a:counter2++});
    }, 100);


    //Manual override athena
    node.createService(
      'trident_msgs/srv/ToggleControl',
      prefixTopics+'athena/motor_control/manual_override',
      (request, response) => {
        console.log(request);
        let result = response.template;
        result.success = true;
        result.message = "done";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //Manual override naiad
    node.createService(
      'trident_msgs/srv/ToggleControl',
      prefixTopics+'naiad/motor_control/manual_override',
      (request, response) => {
        console.log(request);
        let result = response.template;
        result.success = true;
        result.message = "done";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //load mission plan tester (athena)
    node.createService(
      'trident_msgs/srv/LoadMission',
      prefixTopics+'athena/mission_control/mission/load',
      (request, response) => {
        console.log(JSON.stringify(request));
        let result = response.template;
        result.success = true;
        result.message = "mission plan loaded on athena";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //load mission plan tester (naiad)
    node.createService(
      'trident_msgs/srv/LoadMission',
      prefixTopics+'naiad/mission_control/mission/load',
      (request, response) => {
        console.log(request.mission.waypoints);
        let result = response.template;
        result.success = true;
        result.message = "mission plan loaded on naiad";
        console.log(`Sending response: ${typeof result}`, result, '\n--');
        response.send(result);
      }
    );

    //start mission plan tester
    //new StartMissionActionServer(node);

    //abort tester
    node.createService(
      'trident_msgs/srv/Abort',
      prefixTopics+'abort',
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