class WaypointMap {
	constructor(){
		this.map = new L.map('map1').setView([51.505, -0.09], 13);
		this.waypointCounter = [0,0]; 	// [athena,naiad]
		this.waypointObjects = [[],[]];	// [[athena],[naiad]]
		this.latlng = [[],[]];			// [[athena],[naiad]]
		this.polyLines = [[],[]];		// [[athena],[naiad]]
		this.waypointType = 0;			// 0 = Athena, 1 = Naiad
	}
}

class InterfaceHandler {
	constructor() {
		this.xhr = new XMLHttpRequest();
	}

	sendReq(data, callback)
	{
		var tempMsg = JSON.parse(data);
		this.xhr.open("POST", tempMsg.url, true);
		this.xhr.setRequestHeader('Content-Type', 'application/json');
		this.xhr.send(data);
		this.xhr.onload = function(resp) {
			if (resp.originalTarget.status != 200) { // analyze HTTP status of the response
				callback(0);
			} else { // show the result
				callback(resp.originalTarget.response);
			}
		};
	}
}

//Setup class handlers
var waypointMap = new WaypointMap();
var interfaceHandler = new InterfaceHandler();


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

waypointMap.map.on('click', function(e) {
	waypointMap.waypointCounter[waypointMap.waypointType] += 1;
    var waypointMarker = new L.marker(e.latlng, {draggable:'true', waypointType: waypointMap.waypointType, waypointNum: waypointMap.waypointCounter[waypointMap.waypointType]})
	.on('drag', function(){
		document.getElementById("waypointLat-"+waypointMap.waypointType+"-"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lat.toFixed(4);
		document.getElementById("waypointLng-"+waypointMap.waypointType+"-"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lng.toFixed(4);
	})
	.on('dragend', function(){
		remapPolyLines();
	});
	//Add waypoint object to array
	waypointMap.waypointObjects[waypointMap.waypointType].push(waypointMarker);
	//Add waypoint lat and lng to array for polylines
	waypointMap.latlng[waypointMap.waypointType].push([e.latlng.lat, e.latlng.lng]);
	waypointMap.map.addLayer(waypointMarker);
    document.getElementById("waypointList-"+waypointMap.waypointType).innerHTML += "<li id='waypointListItem-" + waypointMap.waypointType + "-" + waypointMap.waypointCounter[waypointMap.waypointType] +"' class='list-group-item waypoint-item-"+waypointMap.waypointType+"'>Waypoint "+ waypointMap.waypointCounter[waypointMap.waypointType] +":<br> \
		<span>Lat: </span><span id='waypointLat-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lat.toFixed(4)+"</span> \
		<br><span>Lng: </span><span id='waypointLng-" + waypointMap.waypointType + "-"  + waypointMap.waypointCounter[waypointMap.waypointType]+"'>"+e.latlng.lng.toFixed(4)+"</span> \
		<button onclick='removeWaypoint(\""+waypointMap.waypointType+"\",\""+waypointMap.waypointCounter[waypointMap.waypointType]+"\")' style='position:absolute;top:0.5rem;right:0.5rem;background:transparent;border:none;'><i class='bi bi-x-circle' style='color: red; font-size: 2rem;'></i></button></li>";

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
var heartbeatStatus = [null,null];
function heartbeat()
{
	var data = JSON.stringify({url: "http://localhost:8081/heartbeat"});
	interfaceHandler.sendReq(data, function(resp){
		resp = JSON.parse(resp);
		if (resp.athena == true && resp.athena != heartbeatStatus[0])
		{
			heartbeatStatus[0] = true;
			document.getElementById("connStatusAthena").innerHTML = "online";
			document.getElementById("connStatusAthena").style.color = "#4CAF50";
			printLoggerMain("Connection established with Athena");
		}
		else if (resp.athena == false && resp.athena != heartbeatStatus[0])
		{
			heartbeatStatus[0] = false;
			document.getElementById("connStatusAthena").innerHTML = "offline";
			document.getElementById("connStatusAthena").style.color = "rgb(201, 76, 76)";
			printLoggerMain("Connection lost with Athena");
		}
		if (resp.naiad == true && resp.naiad != heartbeatStatus[1])
		{
			heartbeatStatus[1] = true;
			document.getElementById("connStatusNaiad").innerHTML = "online";
			document.getElementById("connStatusNaiad").style.color = "#4CAF50";
			printLoggerMain("Connection established with Naiad");
		}
		else if (resp.naiad == false && resp.naiad != heartbeatStatus[1])
		{
			heartbeatStatus[1] = false;
			document.getElementById("connStatusNaiad").innerHTML = "offline";
			document.getElementById("connStatusNaiad").style.color = "rgb(201, 76, 76)";
			printLoggerMain("Connection lost with Naiad");
		}
	});
}
setInterval(function(){
	heartbeat();
},1000);

function printLoggerMain(msg)
{
	var today = new Date();
	var time = today.getHours() + ":" + today.getMinutes() + ":" + today.getSeconds();
	document.getElementById("loggerMainWindow").innerHTML += "<p class='font-monospace my-0'>"+time+" - "+msg+"</p>";
}