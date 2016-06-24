function initMap() {
	var myLatLng = {lat: 48.8966838, lng: 2.3161868};

	var map = new google.maps.Map(document.getElementById('map'), {
		zoom: 16,
		center: myLatLng,
		zoomControl: true,
		mapTypeControl: false,
		scaleControl: true,
		streetViewControl: false,
		rotateControl: false
	});

	var marker = new google.maps.Marker({
    	position: {lat: 48.896, lng: 2.3161868},
    	map: map,
    	title: '42 School !',
		icon: 'https://www.gravatar.com/avatar/fe65f553c23437048d75161e836dd724?s=50'
	});
	var infowindow = new google.maps.InfoWindow({
		content: '<div class="desc">Jimi Maiquez</div>'
	});
	marker.addListener('click', function() {
		infowindow.open(map, marker);
	});

	var marker2 = new google.maps.Marker({
    	position: {lat: 48.9, lng: 2.3161868},
    	map: map,
    	title: '42 School !',
		icon: 'https://www.gravatar.com/avatar/?s=50'
	});
	var infowindow2 = new google.maps.InfoWindow({
		content: '<div class="desc">Marie Coutellier</div>'
	});
	marker2.addListener('click', function() {
		infowindow2.open(map, marker2);
	});
}
