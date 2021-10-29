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

class Server {
	constructor() {
		this.port = 8080;
		this.xhr = new XMLHttpRequest();
	}

	sendReq(data)
	{
		return new Promise(resolve => {
			var tempMsg = JSON.parse(data);
			this.xhr.open("POST", tempMsg.url, true);
			this.xhr.setRequestHeader('Content-Type', 'application/json');
			this.xhr.send(data);
			this.xhr.onload = function(resp) {
				if (resp.originalTarget.status != 200) { // analyze HTTP status of the response
					resolve(0);
				} else { // show the result
					resolve(resp.originalTarget.response);
				}
			};
		});
		
	}
}

class Athena {
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
	
	setMode(mode)
	{
		this.mode = mode;
		document.getElementById("systemAthenaMode").innerHTML = mode;
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
	
	setMode(mode)
	{
		this.mode = mode;
		document.getElementById("systemNaiadMode").innerHTML = mode;
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
		maxZoom: 18,
		attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, ' +
			'Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
		id: 'mapbox/streets-v11',
		tileSize: 512,
		zoomOffset: -1
	}).addTo(waypointMap.map);

var waypointMarker = new L.marker([waypointMap.relativeNullPoint.latitude,waypointMap.relativeNullPoint.longitude]).addTo(waypointMap.map);

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
	var slider = document.createElement('input');
	slider.type = 'range';
	slider.id = "depthRangeSlider-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType];
	slider.className = "form-range"
	slider.min = 0;
	slider.max = 100;
	slider.value = 0;
	slider.step = 1;
	slider.onchange = function () {
		//console.log(waypointMap.waypointType + " " + waypointMap.waypointCounter[waypointMap.waypointType]);
		var rangeVal = document.getElementById("depthRangeSlider-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]).value;
		waypointMap.depth[waypointMap.waypointType][waypointMap.waypointCounter[waypointMap.waypointType]-1] = rangeVal;
		document.getElementById("depthRangeNum-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]).innerHTML = rangeVal;
	};
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
		document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item-'+target).length;
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
		document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item-'+target).length;
	}
}


/*
	Heartbeat
	- request heartbeat status from server node.
*/
function heartbeat()
{
	var server = new Server();
	var heartbeatStatus = [null,null];
	setInterval(async function(){
		var data = JSON.stringify({url:"http://localhost:"+server.port+"/heartbeat"});
		var resp = await server.sendReq(data);
		resp = JSON.parse(resp);
		if (resp.athena == true && resp.athena != heartbeatStatus[0])
		{
			athena.connected = true;
			heartbeatStatus[0] = true;
			document.getElementById("connStatusAthena").innerHTML = "online";
			document.getElementById("connStatusAthena").style.color = "#4CAF50";
			printLoggerMain("Connection established with Athena", "green");
		}
		else if (resp.athena == false && resp.athena != heartbeatStatus[0])
		{
			athena.connected = false;
			heartbeatStatus[0] = false;
			document.getElementById("connStatusAthena").innerHTML = "offline";
			document.getElementById("connStatusAthena").style.color = "rgb(201, 76, 76)";
			printLoggerMain("Connection lost with Athena", "red");
		}
		if (resp.naiad == true && resp.naiad != heartbeatStatus[1])
		{
			naiad.connected = true;
			heartbeatStatus[1] = true;
			document.getElementById("connStatusNaiad").innerHTML = "online";
			document.getElementById("connStatusNaiad").style.color = "#4CAF50";
			printLoggerMain("Connection established with Naiad", "green");
		}
		else if (resp.naiad == false && resp.naiad != heartbeatStatus[1])
		{
			naiad.connected = false;
			heartbeatStatus[1] = false;
			document.getElementById("connStatusNaiad").innerHTML = "offline";
			document.getElementById("connStatusNaiad").style.color = "rgb(201, 76, 76)";
			printLoggerMain("Connection lost with Naiad", "red");
		}
	},1000);
	
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
	// [athena,naiad]
	var targets = [document.getElementById("checkboxTargetAthena").checked, document.getElementById("checkboxTargetNaiad").checked];
	var tmpTargerArr = [];
	if (!targets[0] && !targets[1])
	{
		printLoggerMain("No target selected.","red");
		return;
	}
	if (targets[0] && !athena.connected)
	{
		printLoggerMain("Can't send payload, not connected to Athena.","red");
		return;
	}
	else
	{
		if (targets[0])
		{
			tmpTargerArr.push('athena');
		}
	}

	if (targets[1] && !naiad.connected)
	{
		printLoggerMain("Can't send payload, not connected to Naiad.","red");
		return;
	}
	else
	{
		if (targets[1])
		{
			tmpTargerArr.push('naiad');
		}
	}

	switch(payload) {
		case 'toggle_manual_control':
			for (tar of tmpTargerArr)
			{
				var server = new Server();
				var data = JSON.stringify({url:"http://localhost:"+server.port+"/toggleControl",target:tar,mode:'manual'});
				printLoggerMain("Sending toggle_manual_control to: " + tar);
				var resp = await server.sendReq(data);
				resp = JSON.parse(resp);
				if (resp.success == true)
				{
					if (resp.target == 'athena')
					{
						athena.setMode('manual');
					}
					if (resp.target == 'naiad')
					{
						naiad.setMode('manual');
					}
					printLoggerMain("Toggling MANUAL control on "+resp.target+" successful", "green");
				}
				else
				{
					printLoggerMain("Toggling MANUAL control on "+resp.target+" unsuccessful", "red");
				}
			}
			break;
		case 'toggle_automatic_control':
			for (tar of tmpTargerArr)
			{
				var server = new Server();
				var data = JSON.stringify({url:"http://localhost:"+server.port+"/toggleControl",target:tar,mode:'automatic'});
				printLoggerMain("Sending toggle_automatic_control to: " + tar);
				var resp = await server.sendReq(data);
				resp = JSON.parse(resp);
				if (resp.success == true)
				{
					if (resp.target == 'athena')
					{
						athena.setMode('automatic');
					}
					if (resp.target == 'naiad')
					{
						naiad.setMode('automatic');
					}
					printLoggerMain("Toggling AUTOMATIC control on "+resp.target+" successful", "green");
				}
				else
				{
					printLoggerMain("Toggling AUTOMATIC control on "+resp.target+" unsuccessful", "red");
				}
			}
			break;
		case 'load_mission_plan':
			for (tar of tmpTargerArr)
			{
				var waypoints = [];
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
				console.log(waypoints);

				var server = new Server();
				var data = JSON.stringify({url:"http://localhost:"+server.port+"/load_mission_plan",target:tar,waypoints:waypoints});
				printLoggerMain("Sending toggle_automatic_control to: " + tar);
				var resp = await server.sendReq(data);
				resp = JSON.parse(resp);
				if (resp.success == true)
				{
					printLoggerMain("Loading mission plan on "+resp.target+" successful", "green");
				}
				else
				{
					printLoggerMain("Loading mission plan on "+resp.target+" unsuccessful", "red");
				}
			}
			break;
		case 'start_mission_plan':
			for (tar of tmpTargerArr)
			{
				var server = new Server();
				var data = JSON.stringify({url:"http://localhost:"+server.port+"/start_mission_plan",target:tar});
				printLoggerMain("Sending toggle_automatic_control to: " + tar);
				var resp = await server.sendReq(data);
				resp = JSON.parse(resp);
				if (resp.success == true)
				{
					printLoggerMain("Starting mission plan on "+resp.target+" successful", "green");
				}
				else
				{
					printLoggerMain("Starting mission plan on "+resp.target+" unsuccessful", "red");
				}
			}
			break;
		case 'abort':
			for (tar of tmpTargerArr)
			{
				var server = new Server();
				var data = JSON.stringify({url:"http://localhost:"+server.port+"/abort",target:tar});
				printLoggerMain("Sending toggle_manual_control to: " + tar);
				var resp = await server.sendReq(data);
				resp = JSON.parse(resp);
				if (resp.success == true)
				{
					printLoggerMain(""+resp.target+" aborted", "green");
				}
				else
				{
					printLoggerMain("Couldn't abort "+resp.target+"", "red");
				}
			}
		break;
	}
}

$(document).ready(function(){
	heartbeat();
});