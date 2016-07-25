var pos;
var marker = [];
var map;

function initMap() {
	NProgress.start();
	$.get("/api/profiles/view", {}).done(function(res) {
		NProgress.inc();
		if (res[0].pos)
			var myLatLng = {lng: res[0].pos[0], lat: res[0].pos[1]};
		else
			var myLatLng = {lng: 2.3522219, lat: 48.856614};
		NProgress.inc();
		map = new google.maps.Map(document.getElementById('map'), {
			zoom: 15,
			center: myLatLng,
			zoomControl: true,
			mapTypeControl: false,
			scaleControl: true,
			streetViewControl: false,
			rotateControl: false
		});
		NProgress.inc();
		$.get("/api/profiles/?block=true", {}).done(function(res) {
			var i = 0;

			NProgress.inc();
			myPos = new google.maps.Marker({
				position: pos,
				map: map,
				title: 'Me'
			});
			NProgress.inc();
			res.forEach(function(profile) {
				if (profile.pos && profile.img) {
					marker[i] = new google.maps.Marker({
				    	position: {lng: profile.pos[0], lat: profile.pos[1]},
				    	map: map,
				    	title: profile.firstname + " " + profile.lastname,
						icon: "/api/img/view/" + profile.username + "/50/0"
					});
					marker[i].username = profile.username;
					marker[i].id = i;
					marker[i].addListener('click', function() {
						viewProfile(function() {
							$('#profiles').fadeIn('fast');
						}, profile.username);
					});
					i++;
				}
				NProgress.inc();
			});

			NProgress.done();
		});
	});
}
