
const rclnodejs = require('./node_modules/rclnodejs/index.js')
const Mission = rclnodejs.require('trident_msgs/msg/Mission');
const LoadMission = rclnodejs.require('trident_msgs/srv/LoadMission');
const StartMission = rclnodejs.require('trident_msgs/action/StartMission');
const Waypoint = rclnodejs.require('trident_msgs/msg/Waypoint');
const WaypointAction = rclnodejs.require('trident_msgs/msg/WaypointAction');
const Pose = rclnodejs.require('geometry_msgs/msg/Pose');
const tridenStates = require('./tridentstates');
const State = rclnodejs.require('trident_msgs/msg/State');

let prefixTopics = "gc/";

class ActionServer {
  constructor(node,target) {
    this._node = node;
    this.target = target;
    this._actionServer = new rclnodejs.ActionServer(
      node,
      'trident_msgs/action/StartMission',
      prefixTopics+this.target+'/mission_control/mission/start',
      this.executeCallback.bind(this),
      this.goalCallback.bind(this),
      null,
      this.cancelCallback.bind(this)
    );
  }

  async executeCallback(missionHandle) {
    this._node.getLogger().info('Executing goal...');

    const feedbackMessage = new StartMission.Feedback();
    // Start executing the action
    if (missionHandle.isCancelRequested) {
      missionHandle.canceled();
      this._node.getLogger().info('Goal canceled');
      return new StartMission.Result();
    }
    feedbackMessage.status = 0;
    feedbackMessage.message = "executing";
    feedbackMessage.waypoints_completed = 0;
    
    for (var i=0; i < 5 ; i++)
    {
      feedbackMessage.waypoints_completed += 1;
      this._node
        .getLogger()
        .info(`Publishing feedback: ${feedbackMessage}`);

      // Publish the feedback
      missionHandle.publishFeedback(feedbackMessage);

      // Wait for 1 second
      await new Promise((resolve) => setTimeout(resolve, 2000));
    }

    missionHandle.succeed();

    // Populate result message
    const result = new StartMission.Result();
    result.success = true;
    result.message = "done";

    this._node.getLogger().info(`Returning result: ${result}`);

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

class States {
  constructor()
  {
    this.athena = {
      missionControl:tridenStates.missionControlState.NO_MISSION,
      navigation:tridenStates.navigationState.IDLE,
      motorControl:tridenStates.motorControlState.IDLE,
      motorDriver:tridenStates.motorDriverState.IDLE,
      position:tridenStates.guidanceState.IDLE
    };
    this.naiad = {
      missionControl:tridenStates.missionControlState.NO_MISSION,
      navigation:tridenStates.navigationState.IDLE,
      motorControl:tridenStates.motorControlState.IDLE,
      motorDriver:tridenStates.motorDriverState.IDLE,
      position:tridenStates.guidanceState.IDLE
    };
  }
}

rclnodejs
  .init()
  .then(() => {
    const node = rclnodejs.createNode('tester_node');
    let count = 0;
    const states = new States();

    const statePublisherAthena = node.createPublisher('trident_msgs/msg/State',prefixTopics+'athena/position/state');
    const statePublisherNaiad = node.createPublisher('trident_msgs/msg/State',prefixTopics+'naiad/position/state');

    let twist = rclnodejs.createMessageObject('geometry_msgs/msg/Twist');
    let pose = rclnodejs.createMessageObject('geometry_msgs/msg/Pose');
    let point = rclnodejs.createMessageObject('geometry_msgs/msg/Point');
    let quaternion = rclnodejs.createMessageObject('geometry_msgs/msg/Quaternion');
    let state = new State();

    twist.linear.x = 0.0;
    twist.linear.y = 0.0;
    twist.linear.z = 0.0;
    twist.angular.x = 0.0;
    twist.angular.y = 0.0;
    twist.angular.z = 0.0;

    point.x = 0.0;
    point.y = 0.0;
    point.z = 0.0;
    //Temporarily set orientation to zero
    quaternion.x = 0.0;
    quaternion.y = 0.0;
    quaternion.z = 0.0;
    quaternion.w = 0.0;
    pose.position = point;
    pose.orientation = quaternion;

    state.twist = twist;
    state.pose = pose;

     //Publish state
    setInterval(function(){
      statePublisherAthena.publish(state);
      statePublisherNaiad.publish(state);
    },1000);
    

    //Manual override athena
    node.createService(
      'std_srvs/srv/SetBool',
      prefixTopics+'athena/motor_control/manual_override',
      (request, response) => {
        if (states.athena.motorControl != tridenStates.motorControlState.MANUAL_OVERRIDE)
        {
          states.athena.motorControl = tridenStates.motorControlState.MANUAL_OVERRIDE;
        }
        else
        {
          states.athena.motorControl = tridenStates.motorControlState.IDLE;
        }
        let result = response.template;
        result.success = true;
        result.message = "done";
        response.send(result);
      }
    );

    //Manual override naiad
    node.createService(
      'std_srvs/srv/SetBool',
      prefixTopics+'naiad/motor_control/manual_override',
      (request, response) => {
        if (states.naiad.motorControl != tridenStates.motorControlState.MANUAL_OVERRIDE)
        {
          states.naiad.motorControl = tridenStates.motorControlState.MANUAL_OVERRIDE;
        }
        else
        {
          states.naiad.motorControl = tridenStates.motorControlState.IDLE;
        }
        let result = response.template;
        result.success = true;
        result.message = "done";
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
        result.message = "mission plan loaded on athena";;
        response.send(result);
      }
    );

    //load mission plan tester (naiad)
    node.createService(
      'trident_msgs/srv/LoadMission',
      prefixTopics+'naiad/mission_control/mission/load',
      (request, response) => {
        console.log(JSON.stringify(request));
        let result = response.template;
        result.success = true;
        result.message = "mission plan loaded on naiad";
        response.send(result);
      }
    );

    //abort tester (Athena)
    node.createService(
      'std_srvs/srv/Trigger',
      prefixTopics+'athena/abort',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.message = "Done";
        response.send(result);
      }
    );

    //abort tester (Athena)
    node.createService(
      'std_srvs/srv/Trigger',
      prefixTopics+'naiad/abort',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.message = "Done";
        response.send(result);
      }
    );

    /*
      Setup get state handlers for each module (Athena)
    */
    node.createService('trident_msgs/srv/GetState',prefixTopics+'athena/mission_control/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.athena.missionControl;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'athena/navigation/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.athena.navigation;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'athena/motor_control/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.athena.motorControl;
        //console.log('athena:'+JSON.stringify(result));
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'athena/motor_driver/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.athena.motorDriver;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'athena/position/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.athena.position;
        response.send(result);
      }
    );

    /*
      Setup get state handlers for each module (Athena)
    */
      node.createService('trident_msgs/srv/GetState',prefixTopics+'naiad/mission_control/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.naiad.missionControl;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'naiad/navigation/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.naiad.navigation;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'naiad/motor_control/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.naiad.motorControl;
        //console.log('naiad:'+JSON.stringify(result));
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'naiad/motor_driver/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.naiad.motorDriver;
        response.send(result);
      }
    );
    node.createService('trident_msgs/srv/GetState',prefixTopics+'naiad/position/state/get',
      (request, response) => {
        let result = response.template;
        result.success = true;
        result.state = "None";
        result.int_state = states.naiad.position;
        response.send(result);
      }
    );

    //Setup start mission actions
    new ActionServer(node,'athena');
    new ActionServer(node,'naiad');

    console.log("Tester node started");
    rclnodejs.spin(node);
  })
  .catch((e) => {
    console.log(e);
  });

  process.on('SIGINT', function() {
    console.log('Shutting down server.');
    process.exit();
  });