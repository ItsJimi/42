var pos;

function initMap() {
	NProgress.start();
	console.log("1");
	// Try HTML5 geolocation.
	if (navigator.geolocation) {
		navigator.geolocation.getCurrentPosition(function(position) {
			console.log("2");
			pos = {
				lat: position.coords.latitude,
				lng: position.coords.longitude
			};
			console.log(pos);
			map();
		}, function() {
			//handleLocationError(true, infoWindow, map.getCenter());
			map();
		});
	} else {
		// Browser doesn't support Geolocation
		// handleLocationError(false, infoWindow, map.getCenter());
		map();
	}
	console.log("3");
}

function map() {
	$.get("/api/profiles/view", {}).done(function(res) {
		console.log("4");
		NProgress.inc();
		if (res[0].pos)
			var myLatLng = {lat: res[0].pos[0], lng: res[0].pos[1]};
		else if (pos)
			var myLatLng = pos;
		else
			var myLatLng = {lat: 48.856614, lng: 2.3522219};
		NProgress.inc();
		var map = new google.maps.Map(document.getElementById('map'), {
			zoom: 15,
			center: myLatLng,
			zoomControl: true,
			mapTypeControl: false,
			scaleControl: true,
			streetViewControl: false,
			rotateControl: false
		});
		NProgress.inc();
		$.get("/api/profiles/", {}).done(function(res) {
			var i = 0;
			var marker = [];

			NProgress.inc();
			myPos = new google.maps.Marker({
				position: pos,
				map: map,
				title: 'Me'
			});
			NProgress.inc();
			res.forEach(function(profile) {
				if (profile.pos) {
					marker[i] = new google.maps.Marker({
				    	position: {lat: profile.pos[0], lng: profile.pos[1]},
				    	map: map,
				    	title: profile.firstname + " " + profile.lastname,
						icon: "/api/img/view/" + profile.username + "/50/0"
					});
					marker[i].addListener('click', function() {
						viewProfile(function() {
							$('#profiles').fadeIn('fast');
						}, profile.username);
					});
				}
				i++;
				NProgress.inc();
			});

			NProgress.done();
		});
	});
}

function handleLocationError(browserHasGeolocation, infoWindow, pos) {
  infoWindow.setPosition(pos);
  infoWindow.setContent(browserHasGeolocation ?
                        'Error: The Geolocation service failed.' :
                        'Error: Your browser doesn\'t support geolocation.');
}
