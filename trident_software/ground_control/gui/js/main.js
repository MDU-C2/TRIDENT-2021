class WaypointMap {
	constructor(){
		this.map = new L.map('map1', {zoomControl: false}).setView([51.505, -0.09], 13);
		this.waypointCounter = 0;
		this.waypointObjects = [];
		this.latlng = [];
		this.polyLines = [];
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
		this.xhr.send(JSON.stringify({id:0}));
		this.xhr.onload = function(resp) {
			if (resp.originalTarget.status != 200) { // analyze HTTP status of the response
				//console.log(`Error ${this.xhr.status}: ${this.xhr.statusText}`); // e.g. 404: Not Found
				callback(JSON.stringify(0));
			} else { // show the result
				//console.log(`Done, got ${resp.originalTarget.response}`); // response is the server response
				callback(JSON.stringify(resp.originalTarget.response));
			}
		};
	}
}

waypointMap = new WaypointMap();
interfaceHandler = new InterfaceHandler();
console.log(waypointMap);

L.tileLayer('https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw', {
		maxZoom: 18,
		attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, ' +
			'Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
		id: 'mapbox/streets-v11',
		tileSize: 512,
		zoomOffset: -1
	}).addTo(waypointMap.map);


waypointMap.map.on('click', function(e) {
	waypointMap.waypointCounter += 1;
    var waypointMarker = new L.marker(e.latlng, {draggable:'true', waypointNum: waypointMap.waypointCounter})
	.on('drag', function(){
		document.getElementById("waypointLat"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lat.toFixed(4);
		document.getElementById("waypointLng"+waypointMarker.options.waypointNum).innerHTML = waypointMarker.getLatLng().lng.toFixed(4);
	})
	.on('dragend', function(){
		remapPolyLines();
	});
	//Add waypoint object to array
	waypointMap.waypointObjects.push(waypointMarker);
	//Add waypoint lat and lng to array for polylines
	waypointMap.latlng.push([e.latlng.lat, e.latlng.lng]);
	waypointMap.map.addLayer(waypointMarker);
    document.getElementById("waypointList").innerHTML += "<li id='waypointListItem"+ waypointMap.waypointCounter +"' class='list-group-item waypoint-item'>Waypoint "+ waypointMap.waypointCounter +":<br> \
		<span>Lat: </span><span id='waypointLat"+waypointMap.waypointCounter+"'>"+e.latlng.lat.toFixed(4)+"</span> \
		<br><span>Lng: </span><span id='waypointLng"+waypointMap.waypointCounter+"'>"+e.latlng.lng.toFixed(4)+"</span> \
		<button onclick='removeWaypoint(\""+waypointMap.waypointCounter+"\")' style='position:absolute;top:0.5rem;right:0.5rem;background:transparent;border:none;'><i class='bi bi-x-circle' style='color: red;'></i></button></li>";

	if (waypointMap.waypointCounter > 1)
	{
		var tmpArr = [];
		tmpArr.push(waypointMap.latlng[waypointMap.latlng.length-1]);
		tmpArr.push(waypointMap.latlng[waypointMap.latlng.length-2]);
		var polyline = new L.polyline(tmpArr, {color: 'blue'}).addTo(waypointMap.map);
		waypointMap.polyLines.push(polyline);
	}
	//Set number of waypoint items in list
	document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item').length;
	});
function removeWaypoint(counter)
{
	//Update waypoint counter
	document.getElementById("waypointListItem"+counter).remove();
	//Remove waypoint marker from map list
	document.getElementById("waypointNumCounter").innerHTML = document.querySelectorAll('.waypoint-item').length;
	//Reset waypoint counter if no waypoints exist
	if (document.getElementById("waypointList").innerHTML == "")
	{
		console.log("set counter to 0");
		waypointCounter = 0;
	}
	//Remove waypoint marker from map
	waypointMap.waypointObjects.forEach(function(waypoint, index)
	{
		if (waypoint.options.waypointNum == counter)
		{
			waypointMap.map.removeLayer(waypoint);
			waypointMap.waypointObjects.splice(index,1);
		}

	});
	remapPolyLines();
}

function remapPolyLines()
{
	//Remove all polylines and add them back to get correct polylines
	waypointMap.polyLines.forEach(function(item){
		waypointMap.map.removeLayer(item);
	});
	waypointMap.latlng = [];
	//Remap polylines
	waypointMap.waypointObjects.forEach(function(waypoint)
	{
		waypointMap.latlng.push([waypoint._latlng.lat,waypoint._latlng.lng]);
	});

	if (waypointMap.waypointCounter > 1)
	{
		var polyline = new L.polyline(waypointMap.latlng, {color: 'blue'}).addTo(waypointMap.map);
		waypointMap.polyLines.push(polyline);
	}
}

function heartbeat()
{
	var data = JSON.stringify({url: "http://localhost:8082/api/users1",id: 0})
	//var timeout = setTimeout(function(){},)
	interfaceHandler.sendReq(data, function(resp){
		console.log(JSON.parse(resp));
	});
}
setInterval(function(){
	heartbeat();
},1000);
