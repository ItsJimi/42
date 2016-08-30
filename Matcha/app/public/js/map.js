$(document).ready(function() {
	$('#filters_save').click(function() {
		if ($('#filters_age_min').val())
			var age_min = $('#filters_age_min').val();
		else
			var age_min = '';
		if ($('#filters_age_max').val())
			var age_max = $('#filters_age_max').val();
		else
			var age_max = '';
		if ($('#filters_score_min').val())
			var score_min = $('#filters_score_min').val();
		else
			var score_min = '';
		if ($('#filters_score_max').val())
			var score_max = $('#filters_score_max').val();
		else
			var score_max = '';
		if ($('#filters_dist').val())
			var dist = $('#filters_dist').val();
		else
			var dist = '';
		if ($('#filters_tags').val())
			var tags = $('#filters_tags').val();
		else
			var tags = '';

		$.get("/api/profiles/?filters=true&dist=" + dist + "&age_min=" + age_min + "&age_max=" + age_max + "&score_min=" + score_min + "&score_max=" + score_max + "&tags=" + tags).done(function(res) {
			if (res.request != false) {
				getMap(res);
			}
			NProgress.done();
		});
	});
});

var pos;
var marker = [];
var map;

function enterFullscreen() {
  var element = document.documentElement;

  if (element.requestFullscreen) {
    element.requestFullscreen();
  } else if (element.msRequestFullscreen) {
    element.msRequestFullscreen();
  } else if (element.mozRequestFullScreen) {
    element.mozRequestFullScreen();
  } else if (element.webkitRequestFullscreen) {
    element.webkitRequestFullscreen();
  }
}

function initMap() {
	NProgress.start();
	$.get("/api/profiles/view").done(function(res) {
		NProgress.inc();
		if (res[0].pos)
			var myLatLng = {lng: res[0].pos[0], lat: res[0].pos[1]};
		else
			var myLatLng = {lng: 2.3522219, lat: 48.856614};
		NProgress.inc();
		map = new google.maps.Map(document.getElementById('map'), {
			zoom: 13,
			center: myLatLng,
			zoomControl: true,
			mapTypeControl: false,
			scaleControl: true,
			streetViewControl: false,
			rotateControl: false
		});
		NProgress.inc();
		myPos = new google.maps.Marker({
			position: myLatLng,
			map: map,
			title: 'Me',
			icon: "/api/img/view/" + res[0].username + "/50/0"
		});
		NProgress.inc();
		$.get("/api/profiles/").done(function(res) {
			NProgress.inc();
			getMap(res);
			NProgress.done();
		});
	});
}

function getMap(res) {
	marker.forEach(function(mark) {
		marker[mark.id].setMap(null);
	});
	var i = 0;

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
			NProgress.inc();
		}
	});
}
