function initMap() {
  var myLatLng = {lat: 48.8966838, lng: 2.3161868};

  var map = new google.maps.Map(document.getElementById('map'), {
    zoom: 13,
    center: myLatLng,
	zoomControl: true,
    zoomControlOptions: {
        position: google.maps.ControlPosition.TOP_RIGHT
    },
	mapTypeControl: false,
	scaleControl: true,
	streetViewControl: false,
	rotateControl: false
  });

  var marker = new google.maps.Marker({
    position: {lat: 48.896, lng: 2.3161868},
    map: map,
    title: '42 School !',
	icon: 'http://icons.iconarchive.com/icons/hopstarter/face-avatars/256/Male-Face-F5-icon.png'
  });
}
