function initMap() {
	$.get("/api/profiles/view", {}, function(res) {
		if (res[0].pos)
			var myLatLng = {lat: res[0].pos[0], lng: res[0].pos[1]};
		else
			var myLatLng = {lat: 48.856614, lng: 2.3522219};

		var map = new google.maps.Map(document.getElementById('map'), {
			zoom: 15,
			center: myLatLng,
			zoomControl: true,
			mapTypeControl: false,
			scaleControl: true,
			streetViewControl: false,
			rotateControl: false
		});
		$.get("/api/profiles/", {}, function(res) {
			var i = 0;
			var marker = [];

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
			});
		});
	});
}
