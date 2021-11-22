//const tridentstates = require("../../gui_backend_ws/tridentstates");

/*
	Trident states class
	 - Contains states for each submodule in Athena and Naiad
*/
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

		this.actionState = {
			NO_ACTION: 0,
			HOLD_POSITION: 1
		}
	}
}

/*
	Class for waypoints and map
	 - Contains the functionality needed to setup waypoints and have a
	   graphical view of athena and naiad.
*/
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
		this.metersPerLat = null;
		this.metersPerLon = null;

		L.tileLayer('https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw', {
			maxZoom: 20,
			attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, ' +
				'Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
			id: 'mapbox/streets-v11',
			tileSize: 512,
			zoomOffset: -1
		}).addTo(this.map);

		this.athenaIcon = L.icon({
			iconUrl: 'img/athena-marker.png',
			iconSize: [52,69],
			iconAnchor: [26,35]
		});
	
		this.naiadIcon = L.icon({
			iconUrl: 'img/naiad-marker.png',
			iconSize: [52,69],
			iconAnchor: [26,35]
		});
	
		this.nullpointIcon = L.icon({
			iconUrl: 'img/nullpoint.png',
			iconSize: [52,52],
			iconAnchor: [26,26]
		});

		this.waypointMarker = new L.marker([this.relativeNullPoint.latitude,this.relativeNullPoint.longitude], {icon:this.nullpointIcon}).addTo(this.map);
		this.athenaMarker = new L.marker([this.relativeNullPoint.latitude+0.001,this.relativeNullPoint.longitude+0.001], {icon:this.athenaIcon}).addTo(this.map);
		this.naiadMarker = new L.marker([this.relativeNullPoint.latitude+0.001,this.relativeNullPoint.longitude-0.001], {icon:this.naiadIcon}).addTo(this.map);
		
	}
	asRadians(degrees) //Converts degrees to radians
	{
		return degrees * Math.PI / 180
	}

	hav(theta) // Calculate the haversine of an angle (radians)
	{
		return (1-Math.cos(theta))/2;
	}

	generateXYconversionParams()
	{
		// Calculate the "great circle" length of a degree latitude and longitude
		var earthRadius = 6362257; // approximate radius at origin
		this.metersPerLat = 2*earthRadius*Math.asin(Math.sqrt(
			this.hav(this.asRadians(1.0)) + Math.cos(this.asRadians(this.relativeNullPoint.latitude))*Math.cos(this.asRadians(this.relativeNullPoint.latitude+1))*this.hav(0.0)
			));
		this.metersPerLon = 2*earthRadius*Math.asin(Math.sqrt(
			this.hav(0.0) + Math.cos(this.asRadians(this.relativeNullPoint.latitude))*Math.cos(this.asRadians(this.relativeNullPoint.latitude))*this.hav(this.asRadians(1.0))
			));
	}

	getXYpos(desiredPos) //Get [x,y] coords based of [lat,lng]
	{
		var degreeDifference = [desiredPos.latitude - this.relativeNullPoint.latitude,
							desiredPos.longitude - this.relativeNullPoint.longitude];
		return [degreeDifference[0]*this.metersPerLat,
				degreeDifference[1]*this.metersPerLon];
	}

	getLatLng(relativePos) //Get [lat,lng] coord based of [x,y]
	{
		return [relativePos[0]/this.metersPerLat+this.relativeNullPoint.latitude,
				relativePos[1]/this.metersPerLon+this.relativeNullPoint.longitude];
	}
}

/*
	Server class
	 - Handles the communication between the GUI and server
*/
class Server {
	constructor() {
		this.port = 8080;
		this.socket = io("http://localhost:"+this.port);
		this.heartbeatStatus = [null,null]; //[athena,naiad]
	}

	sendReq(data)
	{
		//Create a promise that sends a request to the server,
		//waits for a response, and sends it back to client.
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
				logger.printLogger('loggerMainWindow',"Connection established with Athena", "green");
			}
			else if (resp.athena == false && resp.athena != this.heartbeatStatus[0])
			{
				athena.connected = false;
				this.heartbeatStatus[0] = false;
				document.getElementById("connStatusAthena").innerHTML = "offline";
				document.getElementById("connStatusAthena").style.color = "rgb(201, 76, 76)";
				logger.printLogger('loggerMainWindow',"Connection lost with Athena", "red");
			}
			if (resp.naiad == true && resp.naiad != this.heartbeatStatus[1])
			{
				naiad.connected = true;
				this.heartbeatStatus[1] = true;
				document.getElementById("connStatusNaiad").innerHTML = "online";
				document.getElementById("connStatusNaiad").style.color = "#4CAF50";
				logger.printLogger('loggerMainWindow',"Connection established with Naiad", "green");
			}
			else if (resp.naiad == false && resp.naiad != this.heartbeatStatus[1])
			{
				naiad.connected = false;
				this.heartbeatStatus[1] = false;
				document.getElementById("connStatusNaiad").innerHTML = "offline";
				document.getElementById("connStatusNaiad").style.color = "rgb(201, 76, 76)";
				logger.printLogger('loggerMainWindow',"Connection lost with Naiad", "red");
			}
		});
	}

	//Listen on updates of the substates in Athena and Naiad
	listenGetStates()
	{
		var state = new TridenStates();
		this.socket.on('state/get/motor_control', resp => {
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
			if (resp.target == 'athena')
			{
				athena.setSubState('motor_ctrl',document.getElementById("system"+resp.target+"SubstateMotorCtrl").innerHTML);
			}
			else if (resp.target == 'naiad')
			{
				naiad.setSubState('motor_ctrl',document.getElementById("system"+resp.target+"SubstateMotorCtrl").innerHTML);
			}
		});
		this.socket.on('state/get/motor_driver', resp => {
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
		});
		this.socket.on('state/get/navigaton', resp => {
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
		});
		this.socket.on('state/get/mission_control', resp => {
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
		});
		this.socket.on('state/get/position', resp => {
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
		});
		//If an error occured during get state service, display in logger.
		this.socket.on('getStates/error', resp => {
			logger.printLogger('loggerMainWindow',resp.errMsg, 'red');
		});
	}

	//Listen om mission status update
	listenMissionStatus()
	{
		this.socket.on('mission/status', resp => {
			if (resp.msgType == 'info')
			{
				logger.printLogger('loggerMainWindow',resp.message);
			}
			else if (resp.msgType == 'error')
			{
				logger.printLogger('loggerMainWindow',resp.message,'red');
			}
			else if (resp.msgType == 'success')
			{
				logger.printLogger('loggerMainWindow',resp.message,'green');
			}
		});
	}

	//Listen on Athena and Naiad current position and heading
	listenPosState()
	{
		this.socket.on('state/athena', resp => {
			var latlng = waypointMap.getLatLng([resp.x,resp.y]);
			waypointMap.athenaMarker.setRotationAngle(resp.yaw);
			waypointMap.athenaMarker.slideTo(latlng, {
				duration: 100
			});
		});
		this.socket.on('state/naiad', resp => {
			var latlng = waypointMap.getLatLng([resp.x,resp.y]);
			waypointMap.naiadMarker.setRotationAngle(resp.yaw);
			waypointMap.naiadMarker.slideTo(latlng, {
				duration: 100
			});
		});
	}

	//Listen on logging data from Athena and Naiad
	listenLogger()
	{
		this.socket.on('logger/athena', resp => {
			logger.printLogger('loggerAthenaWindow', JSON.stringify(resp));
		});
		this.socket.on('logger/naiad', resp => {
			logger.printLogger('loggerNaiadWindow', JSON.stringify(resp));
		});
	}
}

/*
	Class for Athena
*/
class Athena {
	constructor() {
		this.connected = false;
		this.substate = {
			mission_ctrl: 'idle',
			navigation: 'idle',
			motor_ctrl: 'idle',
			position: 'idle',
		};
	}

	//Set substate of specified module
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

/*
	Class for Naiad
*/
class Naiad {
	constructor() {
		this.connected = false;
		this.substate = {
			mission_ctrl: 'idle',
			navigation: 'idle',
			motor_ctrl: 'idle',
			position: 'idle',
		};
	}

	//Set substate of specified module
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

/*
	Class for the logging functionality
*/
class Logger {
	constructor()
	{
		this.freezeLogger = false;
	}

	//Print logging message to specified board (main, athena, naiad)
	printLogger(board,msg,color)
	{
		var today = new Date();
		var hours = today.getHours();
		var minutes = today.getMinutes();
		var seconds = today.getSeconds();
		if (hours < 10){hours = '0'+hours;}
		if (minutes < 10){minutes = '0'+minutes;}
		if (seconds < 10){seconds = '0'+seconds;}
		var time = hours + ":" + minutes + ":" + seconds;
		document.getElementById(board).innerHTML += "<p class='font-monospace my-0' style='color:"+color+";'>"+time+" - "+msg+"</p>";
		//Limit outputs to logging screen to avoid overload
		if (document.getElementById(board).childNodes.length >= 50)
		{
			document.getElementById(board).removeChild(document.getElementById(board).childNodes[0]);
		}
		var objDiv = document.getElementById(board);
		if (!this.freezeLogger)
		{
			objDiv.scrollTop = objDiv.scrollHeight;
		}
	}

	//Disable the logging windows from automatically scrolling
	//to the bottom when new logging data is printed
	toggleFreezeLogger()
	{
		this.freezeLogger = !this.freezeLogger;
		if (this.freezeLogger)
		{
			document.getElementById('toggleFreezeLogger').className = 'bi bi-lock-fill';
		}
		else
		{
			document.getElementById('toggleFreezeLogger').className = 'bi bi-unlock-fill';
		}
	}

	//Clear logging screens
	clearLoggerWindow()
	{
		document.getElementById('loggerMainWindow').innerHTML = "";
		document.getElementById('loggerAthenaWindow').innerHTML = "";
		document.getElementById('loggerNaiadWindow').innerHTML = "";
	}

	//Opens a new tab with an enlarged logger window for main, athena, and naiad
	openFullscreenLogger()
	{
		window.open('loggerWindow.html', '_blank');
	}

}

//Setup class handlers
var waypointMap = new WaypointMap();
waypointMap.generateXYconversionParams();
var athena = new Athena();
var naiad = new Naiad();
var logger = new Logger();

/*
	Map
	- Listen on click event on map, which will add marker to selected target
*/
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
	slider.id = "depthRangeSlider-" + waypointMap.waypointType + "-"  + waypointMap.depth[waypointMap.waypointType].length;
	slider.className = "form-range"
	slider.min = 0;
	slider.max = 100;
	slider.value = 0;
	slider.step = 1;
	slider.onchange = slider => {
		waypointMap.depth[waypointMap.waypointType][slider.target.id.substr(19,19)-1] = slider.target.value;
		document.getElementById("depthRangeNum-"+slider.target.name).innerHTML = slider.target.value;
	};

	var actionType = document.createElement('div');
	actionType.className = "actionTypeDiv-"+waypointMap.waypointType;
	actionType.innerHTML = "<hr><span>Action type:</span> \
							<br><input type='radio' class='btn-check' name='actionTypes"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"' id='actionType"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"-1' autocomplete='off'> \
							<label class='btn btn-outline-primary' for='actionType"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"-1'>Hold</label> \
							<input type='radio' class='btn-check' name='actionTypes"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"' id='actionType"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"-2' autocomplete='off' checked> \
							<label class='btn btn-outline-primary ' for='actionType"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"-2'>No action</label> \
							<label class='pt-2'>Action param:</label> \
							<input class='form-control' id='actionParam"+waypointMap.waypointType+"-"+waypointMap.waypointCounter[waypointMap.waypointType]+"' style='width: 3rem;' value='0'>";

	//Create waypoint list element
	var list = document.createElement('li');
	list.id = "waypointListItem-" + waypointMap.waypointType + "-" + waypointMap.waypointCounter[waypointMap.waypointType];
	list.className = "list-group-item waypoint-item-"+waypointMap.waypointType;
	list.innerHTML = "Waypoint "+ waypointMap.waypointCounter[waypointMap.waypointType] +":<br> \
		<span>Lat: </span><span id='waypointLat-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lat.toFixed(7)+"</span> \
		<br><span>Lng: </span><span id='waypointLng-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lng.toFixed(7)+"</span> \
		<hr><span>Depth: </span><span id='depthRangeNum-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>0</span><span> meters</span> \
		<button onclick='removeWaypoint(\""+waypointMap.waypointType+"\",\""+waypointMap.waypointCounter[waypointMap.waypointType]+"\")' style='position:absolute;top:0.5rem;right:0.5rem;background:transparent;border:none;'><i class='bi bi-x-circle' style='color: red; font-size: 2rem;'></i></button>";
		
	
	//Add slider to list
	list.appendChild(slider);
	//Add action type to list
	list.appendChild(actionType);
	document.getElementById("waypointList-"+waypointMap.waypointType).appendChild(list); 
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
			waypointMap.depth[waypointMap.waypointType].splice(index,1);
		}

	});
	remapPolyLines();
}

//Remap lines between markers
function remapPolyLines()
{
	//Remove all polylines and add them back to get correct polylines
	waypointMap.polyLines[waypointMap.waypointType].forEach(function(item){
		waypointMap.map.removeLayer(item);
	});
	waypointMap.latlng[waypointMap.waypointType] = [];

	//Go through each marker on the map of a specified type (athena, naiad)
	//and insert it to the latlng array buffer
	waypointMap.waypointObjects[waypointMap.waypointType].forEach(function(waypoint)
	{
		waypointMap.latlng[waypointMap.waypointType].push([waypoint._latlng.lat,waypoint._latlng.lng]);
	});

	//If there are more than one marker of the same type => set a polyline
	//between those markers
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

/*
	Send payload functionality
*/
async function sendPayload()
{
	var tridentStates = new TridenStates();
	var payload = document.getElementById("payloadSelectBox").value;
	var targets = [document.getElementById("checkboxTargetAthena").checked, document.getElementById("checkboxTargetNaiad").checked]; // [athena,naiad]
	var tmpTargerArr = [];
	//Check if any target has been selected
	if ($('input[name=target]:checked').length == 0)
	{
		logger.printLogger('loggerMainWindow',"No target selected.","red");
		return;
	}
	//Check if a payload has been selected
	if (!payload)
	{
		logger.printLogger('loggerMainWindow',"No payload selected.","red");
		return;
	}

	//Check if athena is connected, if selected
	if (targets[0] && !athena.connected)
	{
		logger.printLogger('loggerMainWindow',"Can't send payload, not connected to"+targets[0], "red");
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
		logger.printLogger('loggerMainWindow',"Can't send payload, not connected to"+targets[0], "red");
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
				if ((tar == 'athena' && waypointMap.latlng[0].length == 0) || (tar == 'naiad' && waypointMap.latlng[1].length == 0))
				{
					logger.printLogger('loggerMainWindow',"No waypoints added for: " + tar, "red");
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

				var actionTypeList = document.getElementsByClassName("actionTypeDiv-"+tarIndex);
				var counter = 0;
				//Setup waypoints array
				waypointMap.latlng[tarIndex].forEach(item => {
					//Create temporary waypoint array
					var tmpWP = [];
					//Insert converted [x,y] pos to temporary array
					tmpWP.push(waypointMap.getXYpos({latitude:item[0],longitude:item[1]}));
					//Get corresponding z pos (depth)
					var depth = parseInt(waypointMap.depth[tarIndex][waypointMap.latlng[tarIndex].indexOf(item)]);
					//Get action type and param values
					if(document.getElementById("actionType"+actionTypeList[counter].lastChild.id.substr(11,13)+"-1").checked)
					{
						var actionType = tridentStates.actionState.HOLD_POSITION;
						var actionParam = parseInt(document.getElementById("actionParam"+actionTypeList[counter].lastChild.id.substr(11,13)).value);
					}
					else
					{
						var actionType = tridentStates.actionState.NO_ACTION;
						var actionParam = parseInt(document.getElementById("actionParam"+actionTypeList[counter].lastChild.id.substr(11,13)).value);
					}
					//Add [x,y,z] pos and action type to waypoints array
					waypoints.push([tmpWP[0][0], tmpWP[0][1], depth, actionType, actionParam]);
					counter += 1;
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
					//Get the inverted value of the current manual_override value
					if (athena.substate.motor_ctrl = 'MANUAL_OVERRIDE'){tmpBool=false;}
					else {tmpBool=true}
					
				}
				else if (tar == 'naiad')
				{
					//Get the inverted value of the current manual_override value
					if (naiad.substate.motor_ctrl = 'MANUAL_OVERRIDE'){tmpBool=false;}
					else {tmpBool=true}
				}
				data = {function:payload, target:tar, bool:tmpBool};
				break;
			case 'abort':
				data = {function:payload, target:tar};
				break;
		}

		var server = new Server();
		logger.printLogger('loggerMainWindow',"Sending "+payload+" to: " + tar);
		//Send payload to server as request and wait for response
		var resp = await server.sendReq(data);
		if (resp.data.success == true)
		{
			logger.printLogger('loggerMainWindow',"Payload "+payload+" on "+tar+" successful", "green");
		}
		else
		{
			logger.printLogger('loggerMainWindow',"Payload "+payload+" on "+tar+" unsuccessful", "red");
		}
	}
}

/*
	Send abort command to both Athena and Naiad
*/
async function abort()
{
	//Send abort payload to both Athena and Naiad
	var target = ['athena','naiad'];
	for (tar of target)
	{
		data = {function:'abort',target:tar};
		var server = new Server();
		logger.printLogger('loggerMainWindow',"Sending abort to: " + tar);
		var resp = await server.sendReq(data);
		if (resp.data.success == true)
		{
			logger.printLogger('loggerMainWindow',"Payload abort on "+tar+" successful", "green");
		}
		else
		{
			logger.printLogger('loggerMainWindow',"Payload abort on "+tar+" unsuccessful", "red");
		}
	}
}

$(document).ready(function(){
	var server = new Server();
	server.listenHeartbeat();		//Listen for heartbeat
	server.listenGetStates();		//Listen on substate updates on Athena and Naiad
	server.listenMissionStatus();	//Listen on mission status (feedback/result) from mission
	server.listenPosState();		//Listen on the position state (i.e. where Naiad/Athena are on the map)
	server.listenLogger();			//Listen on the logging topics (main + Athena + Naiad)
	
	//Add eventlistener for logging buttons: toggle freeze mode, clear logging window, open logger full screen
	document.getElementById("toggleFreezeLogger").addEventListener('click',function(){logger.toggleFreezeLogger();});
	document.getElementById("clearLoggerWindow").addEventListener('click',function(){logger.clearLoggerWindow();});
	document.getElementById("openFullscreenLogger").addEventListener('click',function(){logger.openFullscreenLogger();});
});