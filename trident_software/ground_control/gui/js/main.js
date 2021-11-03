class TridenStates {
	constructor()
	{
		this.missionControlState = {
			NO_MISSION: 0,
			MISSION_LOADED: 1,
			EXECUTING_MISSION: 2,
			MISSION_FINISHED: 3
		};
		
		this.guidanceState = {
			IDLE: 1,
			PREPARING_GUIDANCE: 2,
			GUIDING: 3 //Pinging
		};
		
		this.navigationState = {
			IDLE: 0,
			EXECUTING: 1
		};
		
		this.motorControlState = {
			IDLE: 0,
			EXECUTING: 1,
			MANUAL_OVERRIDE: 2
		};
		
		this.motorDriverState = {
			IDLE: 0,
			KILLED: 1,
			MOTOR_OUTPUT_SILENCE: 2,
			ACTIVE: 3
		};
	}
}

class WaypointMap {
	constructor(){
		this.relativeNullPoint = {latitude:59.6175191,longitude:16.5609992}; //Null point from where to measure [x,y] distance, set at MDH C2
		this.map = new L.map('map1').setView([this.relativeNullPoint.latitude,this.relativeNullPoint.longitude], 17);
		this.waypointCounter = [0,0]; 	// [athena,naiad]
		this.waypointObjects = [[],[]];	// [[athena],[naiad]]
		this.latlng = [[],[]];			// [[athena],[naiad]]
		this.depth = [[],[]];			// [[athena],[naiad]]
		this.polyLines = [[],[]];		// [[athena],[naiad]]
		this.waypointType = 0;			// 0 = Athena, 1 = Naiad
		
	}
	asRadians(degrees)
	{
		return degrees * Math.PI / 180
	}

	getXYpos(desiredPos)
	{
		// Calculates X and Y distances in meters.
		var deltaLatitude = desiredPos.latitude - this.relativeNullPoint.latitude
		var deltaLongitude = desiredPos.longitude - this.relativeNullPoint.longitude
		//The circumference at the equator (latitude 0) is 40075160 meters
		var latitudeCircumference = 40075160 * Math.cos(this.asRadians(this.relativeNullPoint.latitude))
		var resultX = deltaLongitude * latitudeCircumference / 360
		var resultY = deltaLatitude * 40008000 / 360
		return [resultX, resultY]
	}
}
/*
const socket = io("http://localhost:8080");

socket.on('heartbeat', data => {
	console.log(data);
});
*/
class Server {
	constructor() {
		this.port = 8080;
		this.xhr = new XMLHttpRequest();
		this.socket = io("http://localhost:8080");
		this.heartbeatStatus = [null,null]; //[athena,naiad]
	}

	sendReq(data)
	{
		return new Promise(resolve => {
			this.socket.emit("request",{data});
			this.socket.on("response", resp => {
				resolve(resp);
			});
		});
		
	}

	//Listen to heartbeat messages from server
	listenHeartbeat()
	{
		this.socket.on('heartbeat', resp => {
			if (resp.athena == true && resp.athena != this.heartbeatStatus[0])
			{
				athena.connected = true;
				this.heartbeatStatus[0] = true;
				document.getElementById("connStatusAthena").innerHTML = "online";
				document.getElementById("connStatusAthena").style.color = "#4CAF50";
				printLoggerMain("Connection established with Athena", "green");
			}
			else if (resp.athena == false && resp.athena != this.heartbeatStatus[0])
			{
				athena.connected = false;
				this.heartbeatStatus[0] = false;
				document.getElementById("connStatusAthena").innerHTML = "offline";
				document.getElementById("connStatusAthena").style.color = "rgb(201, 76, 76)";
				printLoggerMain("Connection lost with Athena", "red");
			}
			if (resp.naiad == true && resp.naiad != this.heartbeatStatus[1])
			{
				naiad.connected = true;
				this.heartbeatStatus[1] = true;
				document.getElementById("connStatusNaiad").innerHTML = "online";
				document.getElementById("connStatusNaiad").style.color = "#4CAF50";
				printLoggerMain("Connection established with Naiad", "green");
			}
			else if (resp.naiad == false && resp.naiad != this.heartbeatStatus[1])
			{
				naiad.connected = false;
				this.heartbeatStatus[1] = false;
				document.getElementById("connStatusNaiad").innerHTML = "offline";
				document.getElementById("connStatusNaiad").style.color = "rgb(201, 76, 76)";
				printLoggerMain("Connection lost with Naiad", "red");
			}
		});
	}

	listenGetStates()
	{
		var state = new TridenStates();
		this.socket.on('getStates', resp => {
			//Switch statement for modules in athena
			switch(resp.module)
			{
				//Switch statement for mission control
				case 'missionControl':
					switch(resp.intState)
					{
						case state.missionControlState.NO_MISSION:
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").className = 'badge bg-secondary';
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").innerHTML = "NO_MISSION";
							break;
						case state.missionControlState.MISSION_LOADED:
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").className = 'badge bg-info';
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").innerHTML = "MISSION_LOADED";
							break;
						case state.missionControlState.EXECUTING_MISSION:
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").innerHTML = "EXECUTING_MISSION";
							break;
						case state.missionControlState.MISSION_FINISHED:
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").className = 'badge bg-success';
							document.getElementById("system"+resp.target+"SubstateMissionCtrl").innerHTML = "MISSION_FINISHED";
							break;
					}
				//Switch statement for navigation
				case 'navigation':
					switch(resp.intState)
					{
						case state.navigationState.IDLE:
							document.getElementById("system"+resp.target+"SubstateNavigation").className = 'badge bg-secondary';
							document.getElementById("system"+resp.target+"SubstateNavigation").innerHTML = "IDLE";
							break;
						case state.navigationState.EXECUTING:
							document.getElementById("system"+resp.target+"SubstateNavigation").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstateNavigation").innerHTML = "EXECUTING";
							break;
					}
				//Switch statement for motor control
				case 'motorControl':
					switch(resp.intState)
					{
						case state.motorControlState.IDLE:
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").className = 'badge bg-secondary';
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").innerHTML = "IDLE";
							break;
						case state.motorControlState.EXECUTING:
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").innerHTML = "EXECUTING";
							break;
						case state.motorControlState.MANUAL_OVERRIDE:
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").className = 'badge bg-info';
							document.getElementById("system"+resp.target+"SubstateMotorCtrl").innerHTML = "MANUAL_OVERRIDE";
							break;
					}
				//Switch statement for navigation
				case 'motorDriver':
					switch(resp.intState)
					{
						case state.motorDriverState.IDLE:
							document.getElementById("system"+resp.target+"SubstateMotorDriver").className = 'badge bg-secondary';
							document.getElementById("system"+resp.target+"SubstateMotorDriver").innerHTML = "IDLE";
							break;
						case state.motorDriverState.KILLED:
							document.getElementById("system"+resp.target+"SubstateMotorDriver").className = 'badge bg-danger';
							document.getElementById("system"+resp.target+"SubstateMotorDriver").innerHTML = "KILLED";
							break;
						case state.motorDriverState.MOTOR_OUTPUT_SILENCE:
							document.getElementById("system"+resp.target+"SubstateMotorDriver").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstateMotorDriver").innerHTML = "MOTOR_OUTPUT_SILENCE";
							break;
						case state.motorDriverState.ACTIVE:
							document.getElementById("system"+resp.target+"SubstateMotorDriver").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstateMotorDriver").innerHTML = "ACTIVE";
							break;
					}
				//Switch statement for navigation
				case 'position':
					switch(resp.intState)
					{
						case state.guidanceState.IDLE:
							document.getElementById("system"+resp.target+"SubstatePosition").className = 'badge bg-secondary';
							document.getElementById("system"+resp.target+"SubstatePosition").innerHTML = "IDLE";
							break;
						case state.guidanceState.PREPARING_GUIDANCE:
							document.getElementById("system"+resp.target+"SubstatePosition").className = 'badge bg-info';
							document.getElementById("system"+resp.target+"SubstatePosition").innerHTML = "PREPARING_GUIDANCE";
							break;
						case state.guidanceState.GUIDING:
							document.getElementById("system"+resp.target+"SubstatePosition").className = 'badge bg-primary';
							document.getElementById("system"+resp.target+"SubstatePosition").innerHTML = "GUIDING";
							break;
					}
			}
		});
	}
}

class Athena {
	constructor() {
		this.connected = false;
		this.manualOverride = false;
		this.mode = 'manual';
		this.state = 'idle';
		this.substate = {
			mission_ctrl: 'idle',
			navigation: 'idle',
			motor_ctrl: 'idle',
			position: 'idle',
		};
	}
	
	setManualOverride(bool)
	{
		this.manualOverride = bool;
		document.getElementById("systemAthenaMO").classList.toggle("bg-info");
		if (this.manualOverride)
		{
			document.getElementById("systemAthenaMO").innerHTML = "on";
		}
		else
		{
			document.getElementById("systemAthenaMO").innerHTML = "off";
		}
	}

	setState(state)
	{
		if (state != this.state)
		{
			this.state = state;
			document.getElementById("systemAthenaState").innerHTML = state;
			document.getElementById("systemAthenaState").classList.remove('bg-secondary');
			document.getElementById("systemAthenaState").classList.add('bg-primary');
		}
	}

	setSubState(module,state)
	{
		switch(module)
		{
			case 'mission_ctrl':
				this.substate.mission_ctrl = state;
				document.getElementById("systemAthenaSubstateMissionCtrl").innerHTML = state;
				break;
			case 'navigation':
				this.substate.navigation = state;
				document.getElementById("systemAthenaSubstateNavigation").innerHTML = state;
				break;
			case 'motor_ctrl':
				this.substate.motor_ctrl = state;
				document.getElementById("systemAthenaSubstateMotorCtrl").innerHTML = state;
				break;
			case 'position':
				this.substate.position = state;
				document.getElementById("systemAthenaSubstatePosition").innerHTML = state;
				break;
		}
	}
}

class Naiad {
	constructor() {
		this.connected = false;
		this.mode = 'manual';
		this.state = 'idle';
		this.substate = {
			mission_ctrl: 'idle',
			navigation: 'idle',
			motor_ctrl: 'idle',
			position: 'idle',
		};
	}
	
	setManualOverride(bool)
	{
		this.manualOverride = bool;
		document.getElementById("systemNaiadMO").classList.toggle("bg-info");
		if (this.manualOverride)
		{
			document.getElementById("systemNaiadMO").innerHTML = "on";
		}
		else
		{
			document.getElementById("systemNaiadMO").innerHTML = "off";
		}
	}

	setState(state)
	{
		if (state != this.state)
		{
			this.state = state;
			document.getElementById("systemNaiadState").innerHTML = state;
			document.getElementById("systemNaiadState").classList.remove('bg-secondary');
			document.getElementById("systemNaiadState").classList.add('bg-primary');
		}
	}

	setSubState(module,state)
	{
		switch(module)
		{
			case 'mission_ctrl':
				this.substate.mission_ctrl = state;
				document.getElementById("systemNaiadSubstateMissionCtrl").innerHTML = state;
				break;
			case 'navigation':
				this.substate.navigation = state;
				document.getElementById("systemNaiadSubstateNavigation").innerHTML = state;
				break;
			case 'motor_ctrl':
				this.substate.motor_ctrl = state;
				document.getElementById("systemNaiadSubstateMotorCtrl").innerHTML = state;
				break;
			case 'position':
				this.substate.position = state;
				document.getElementById("systemNaiadSubstatePosition").innerHTML = state;
				break;
		}
	}
}

//Setup class handlers
var waypointMap = new WaypointMap();
var athena = new Athena();
var naiad = new Naiad();

/*
	Map
	- setup map layer
	- setup marker functionality
*/
L.tileLayer('https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw', {
		maxZoom: 20,
		attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, ' +
			'Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
		id: 'mapbox/streets-v11',
		tileSize: 512,
		zoomOffset: -1
	}).addTo(waypointMap.map);

var athenaIcon = L.icon({
	iconUrl: 'img/athena-marker.png',
	iconSize: [52,69],
	iconAnchor: [26,35]
});

var naiadIcon = L.icon({
	iconUrl: 'img/naiad-marker.png',
	iconSize: [52,69],
	iconAnchor: [26,35]
});

var nullpointIcon = L.icon({
	iconUrl: 'img/nullpoint.png',
	iconSize: [52,52],
	iconAnchor: [26,26]
});

var waypointMarker = new L.marker([waypointMap.relativeNullPoint.latitude,waypointMap.relativeNullPoint.longitude], {icon:nullpointIcon}).addTo(waypointMap.map);

var athenaMarker = new L.marker([waypointMap.relativeNullPoint.latitude+0.001,waypointMap.relativeNullPoint.longitude+0.001], {icon:athenaIcon,rotationAngle:45}).addTo(waypointMap.map);
var naiadMarker = new L.marker([waypointMap.relativeNullPoint.latitude+0.001,waypointMap.relativeNullPoint.longitude-0.001], {icon:naiadIcon}).addTo(waypointMap.map);
console.log(athenaMarker);
setTimeout(() => {
	athenaMarker.setLatLng([waypointMap.relativeNullPoint.latitude-0.001,waypointMap.relativeNullPoint.longitude+0.001]);
	athenaMarker.setRotationAngle(90);
}, 1000);

waypointMap.map.on('click', function(e) {
	waypointMap.waypointCounter[waypointMap.waypointType] += 1;
    var waypointMarker = new L.marker(e.latlng, {draggable:'true', waypointType: waypointMap.waypointType, waypointNum: waypointMap.waypointCounter[waypointMap.waypointType]})
	.on('drag', function(){
		document.getElementById("waypointLat-"+waypointMap.waypointType+"-"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lat.toFixed(7);
		document.getElementById("waypointLng-"+waypointMap.waypointType+"-"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lng.toFixed(7);
	})
	.on('dragend', function(){
		remapPolyLines();
	});
	//Add waypoint object to array
	waypointMap.waypointObjects[waypointMap.waypointType].push(waypointMarker);
	waypointMap.depth[waypointMap.waypointType].push(0);

	//Add waypoint lat and lng to array for polylines
	waypointMap.latlng[waypointMap.waypointType].push([e.latlng.lat, e.latlng.lng]);
	waypointMap.map.addLayer(waypointMarker);

	//Create waypoint depth slider element
	var slider = document.createElement('input');
	slider.type = 'range';
	slider.name = waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType];
	slider.id = "depthRangeSlider-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType];
	slider.className = "form-range"
	slider.min = 0;
	slider.max = 100;
	slider.value = 0;
	slider.step = 1;
	var tmpType = waypointMap.waypointType;
	slider.onchange = slider => {
		waypointMap.depth[waypointMap.waypointType][waypointMap.waypointCounter[waypointMap.waypointType]-1] = slider.target.value;
		document.getElementById("depthRangeNum-"+slider.target.name).innerHTML = slider.target.value;
	};

	//Create waypoint list element
	var list = document.createElement('li');
	list.id = "waypointListItem-" + waypointMap.waypointType + "-" + waypointMap.waypointCounter[waypointMap.waypointType];
	list.className = "list-group-item waypoint-item-"+waypointMap.waypointType;
	list.innerHTML = "Waypoint "+ waypointMap.waypointCounter[waypointMap.waypointType] +":<br> \
		<span>Lat: </span><span id='waypointLat-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lat.toFixed(7)+"</span> \
		<br><span>Lng: </span><span id='waypointLng-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lng.toFixed(7)+"</span> \
		<br><span>Depth: </span><span id='depthRangeNum-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>0</span><span> meters</span> \
		<button onclick='removeWaypoint(\""+waypointMap.waypointType+"\",\""+waypointMap.waypointCounter[waypointMap.waypointType]+"\")' style='position:absolute;top:0.5rem;right:0.5rem;background:transparent;border:none;'><i class='bi bi-x-circle' style='color: red; font-size: 2rem;'></i></button>";
	list.appendChild(slider);
	document.getElementById("waypointList-"+waypointMap.waypointType).appendChild(list); 
	if (waypointMap.waypointCounter[waypointMap.waypointType] > 1)
	{
		var tmpArr = [];
		tmpArr.push(waypointMap.latlng[waypointMap.waypointType][waypointMap.latlng[waypointMap.waypointType].length-1]);
		tmpArr.push(waypointMap.latlng[waypointMap.waypointType][waypointMap.latlng[waypointMap.waypointType].length-2]);
		if (waypointMap.waypointType == 0) //Athena
		{
			var polyline = new L.polyline(waypointMap.latlng[waypointMap.waypointType], {color: 'blue'}).addTo(waypointMap.map);
			waypointMap.polyLines[waypointMap.waypointType].push(polyline);
		}
		else if (waypointMap.waypointType == 1) //Naiad
		{
			var polyline = new L.polyline(waypointMap.latlng[waypointMap.waypointType], {color: 'red'}).addTo(waypointMap.map);
			waypointMap.polyLines[waypointMap.waypointType].push(polyline);
		}
	}
	//Set number of waypoint items in list
	document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item-'+waypointMap.waypointType).length;
});

//Remove waypoints on the map
function removeWaypoint(type, counter)
{
	//Update waypoint type
	selectWaypointType(type);
	//Remove waypoint list item
	document.getElementById("waypointListItem-"+type+"-"+counter).remove();
	//Reset waypoint counter if no waypoints exist
	if (document.getElementById("waypointList-"+type).innerHTML == "")
	{
		waypointMap.waypointCounter[waypointMap.waypointType] = 0;
	}
	//Remove waypoint marker from map
	waypointMap.waypointObjects[type].forEach(function(waypoint, index)
	{
		if (waypoint.options.waypointNum == counter)
		{
			waypointMap.map.removeLayer(waypoint);
			waypointMap.waypointObjects[waypointMap.waypointType].splice(index,1);
		}

	});
	remapPolyLines();
}

//Remap lines between markers
function remapPolyLines()
{
	//Remove all polylines and add them back to get correct polylines
	waypointMap.polyLines[waypointMap.waypointType].forEach(function(item){
		//console.log(item);
		waypointMap.map.removeLayer(item);
	});
	waypointMap.latlng[waypointMap.waypointType] = [];

	//Remap polylines
	waypointMap.waypointObjects[waypointMap.waypointType].forEach(function(waypoint)
	{
		waypointMap.latlng[waypointMap.waypointType].push([waypoint._latlng.lat,waypoint._latlng.lng]);
	});

	if (waypointMap.waypointCounter[waypointMap.waypointType] > 1)
	{
		if (waypointMap.waypointType == 0) //Athena
		{
			var polyline = new L.polyline(waypointMap.latlng[waypointMap.waypointType], {color: 'blue'}).addTo(waypointMap.map);
			waypointMap.polyLines[waypointMap.waypointType].push(polyline);
		}
		else if (waypointMap.waypointType == 1) //Naiad
		{
			var polyline = new L.polyline(waypointMap.latlng[waypointMap.waypointType], {color: 'red'}).addTo(waypointMap.map);
			waypointMap.polyLines[waypointMap.waypointType].push(polyline);
		}
	}
	//Set number of waypoint items in list
	document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item-'+waypointMap.waypointType).length;
}

/*
	Waypoint selector
	- Select waypoint type (Athena or Naiad)
*/
function selectWaypointType(target)
{
	if (target == 0) //set athena active
	{
		//Set Naiad as inactive
		document.getElementById('waypointSelectorNaiad').classList.remove('btn-primary');
		document.getElementById('waypointSelectorNaiad').classList.add('btn-outline-primary');
		//Set Athena as active
		document.getElementById('waypointSelectorAthena').classList.remove('btn-outline-primary');
		document.getElementById('waypointSelectorAthena').classList.add('btn-primary');
		waypointMap.waypointType = 0;
		document.getElementById("waypointTypeTarget").innerHTML = "Athena";
		document.getElementById("waypointList-1").style.display = "none";
		document.getElementById("waypointList-0").style.display = "block";
	}
	else if (target == 1) //set naiad active
	{
		//Set Athena as inactive
		document.getElementById('waypointSelectorAthena').classList.remove('btn-primary');
		document.getElementById('waypointSelectorAthena').classList.add('btn-outline-primary');
		//Set Naiad as active
		document.getElementById('waypointSelectorNaiad').classList.remove('btn-outline-primary');
		document.getElementById('waypointSelectorNaiad').classList.add('btn-primary');
		waypointMap.waypointType = 1;
		document.getElementById("waypointTypeTarget").innerHTML = "Naiad";
		document.getElementById("waypointList-0").style.display = "none";
		document.getElementById("waypointList-1").style.display = "block";
	}
}

function printLoggerMain(msg,color)
{
	var today = new Date();
	var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();
	document.getElementById("loggerMainWindow").innerHTML += "<p class='font-monospace my-0' style='color:"+color+";'>"+time+" - "+msg+"</p>";
	var objDiv = document.getElementById("loggerMainWindow");
	objDiv.scrollTop = objDiv.scrollHeight;
}

/*
	Send payload functionality
*/
async function sendPayload()
{
	var payload = document.getElementById("payloadSelectBox").value;
	var targets = [document.getElementById("checkboxTargetAthena").checked, document.getElementById("checkboxTargetNaiad").checked]; // [athena,naiad]
	var tmpTargerArr = [];
	//Check if any target has been selected
	if ($('input[name=target]:checked').length == 0)
	{
		printLoggerMain("No target selected.","red");
		return;
	}
	//Check if athena is connected, if selected
	if (targets[0] && !athena.connected)
	{
		printLoggerMain("Can't send payload, not connected to"+targets[0], "red");
		return;
	}
	else
	{
		if (targets[0])
		{
			tmpTargerArr.push('athena');
		}
	}
	//CHeck if naiad is connected, if selected
	if (targets[1] && !naiad.connected)
	{
		printLoggerMain("Can't send payload, not connected to"+targets[0], "red");
		return;
	}
	else
	{
		if (targets[1])
		{
			tmpTargerArr.push('naiad');
		}
	}

	//Loop through each target
	for (tar of tmpTargerArr)
	{
		var data = {};
		//Input correct parameters depending on payload
		switch(payload) {
			case 'load_mission_plan':
				var waypoints = [];
				//If we don't have any waypoints added for target
				if ((tar == 'athena' && waypointMap.latlng[0].length == 0) || (tar == 'naiad' && waypointMap.latlng[0].length == 0))
				{
					printLoggerMain("No waypoints added for: " + tar, "red");
					continue;
				}
				if (tar == 'athena')
				{
					var tarIndex = 0;
				}
				else if (tar == 'naiad')
				{
					var tarIndex = 1;
				}
				//Setup waypoints array
				waypointMap.latlng[tarIndex].forEach(item => {
					//Create temporary waypoint array
					var tmpWP = [];
					//Insert converted [x,y] pos to temporary array
					tmpWP.push(waypointMap.getXYpos({latitude:item[0],longitude:item[1]}));
					//Get corresponding z pos (depth)
					var depth = parseInt(waypointMap.depth[tarIndex][waypointMap.latlng[tarIndex].indexOf(item)]);
					//Add [x,y,z] pos to waypoints array
					waypoints.push([tmpWP[0][0], tmpWP[0][1], depth]);
				});
				data = {function:payload, waypoints:waypoints, target:tar};
				break;
			case 'start_mission_plan':
				data = {function:payload,target:tar};
				break;
			case 'toggle_manual_override':
				var tmpBool = null;
				if (tar == 'athena')
				{
					tmpBool = !athena.manualOverride;
					
				}
				else if (tar == 'naiad')
				{
					tmpBool = !naiad.manualOverride;
				}
				data = {function:payload, target:tar, bool:tmpBool};
				break;
			case 'abort':
				data = {function:payload, target:tar};
				break;
		}

		var server = new Server();
		printLoggerMain("Sending "+payload+" to: " + tar);
		var resp = await server.sendReq(data);
		if (resp.data.success == true)
		{
			printLoggerMain("Sending payload "+payload+" to "+tar+" successful", "green");
		}
		else
		{
			printLoggerMain("Sending payload "+payload+" to "+tar+" unsuccessful", "red");
		}
	}
}

$(document).ready(function(){
	var server = new Server();
	server.listenHeartbeat();
	server.listenGetStates();
	//heartbeat();
});

