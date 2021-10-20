var map = new L.map('map1', {zoomControl: false}).setView([51.505, -0.09], 13);
var waypointCounter = 0;

L.tileLayer('https://api.mapbox.com/styles/v1/{id}/tiles/{z}/{x}/{y}?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw', {
		maxZoom: 18,
		attribution: 'Map data &copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors, ' +
			'Imagery © <a href="https://www.mapbox.com/">Mapbox</a>',
		id: 'mapbox/streets-v11',
		tileSize: 512,
		zoomOffset: -1
	}).addTo(map);


map.on('click', function(e) {
    var newMarker = new L.marker(e.latlng).addTo(map);
    waypointCounter += 1;
    console.log(e.latlng.lat);
    document.getElementById("waypointList").innerHTML += "<li class='list-group-item'>Waypoint "+ waypointCounter +":<br>Lat: "+e.latlng.lat+"<br>Lng: "+e.latlng.lng+"</li>";
});

var latlngs = [[37, -109.05],[41, -109.03],[41, -102.05],[37, -102.04]];

var polygon = L.polygon(latlngs, {color: 'red'}).addTo(map);

// zoom the map to the polygon
map.fitBounds(polygon.getBounds());