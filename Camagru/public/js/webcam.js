Z.id("canvas").style.display = "none";
var fullscreen = 0;
var filters = ["chap1.png", "chap2.png", "chap3.png", "chap4.png", "chap5.png", "chap6.png", "chap7.png", "chap8.png", "chap9.png", "chap10.png"];
var key_filter = 0;
var snap = 0;

window.addEventListener("DOMContentLoaded", function() {
	// Grab elements, create settings, etc.
	var canvas = Z.id("canvas"),
		context = canvas.getContext("2d"),
		video = Z.id("video"),
		videoObj = { "video": true },
		errBack = function(error) {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Video capture error: ", error.code;
		};

	// Put video listeners into place
	if(navigator.getUserMedia) { // Standard
		navigator.getUserMedia(videoObj, function(stream) {
			video.src = stream;
			video.play();
		}, errBack);
	} else if(navigator.webkitGetUserMedia) { // WebKit-prefixed
		navigator.webkitGetUserMedia(videoObj, function(stream){
			video.src = window.URL.createObjectURL(stream);
			video.play();
		}, errBack);
	}
	else if(navigator.mediaDevices.getUserMedia) { // Firefox-prefixed
		navigator.mediaDevices.getUserMedia({
			audio: false,
  			video: { width: 640, height: 480 }
		}).then(function(stream){
			cam_stream = stream;
			video.src = window.URL.createObjectURL(stream);
			video.play();
		});
	}

	// Trigger photo take
	Z.id("snap").addEventListener("click", function() {
		if (logged == true) {
			if (snap == 0) {
				canvas.width = 640;
				canvas.height = 480;
				context.drawImage(video, 0, 0, 640, 480);
				Z.id("video").style.display = "none";
				Z.id("canvas").style.display = "block";
				snap = 1;
			}
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez être connecté pour prendre des photos.";
		}
	});

	Z.id("save").addEventListener("click", function() {
		if (snap == 1) {
			snap = 0;
			Z.post("model/save.php", {
				pic: encodeURIComponent(canvas.toDataURL("image/png")),
				filter: filters[key_filter]
			}, function(res) {
				if (res != 0) {
					res = JSON.parse(res);
					Z.id("info").style.display = "block";
					Z.id("info_text").innerHTML = res.info;
					pics(0);
				}
			});
			if (logged == true) {
				Z.id("info").style.display = "block";
				Z.id("info_text").innerHTML = "Envoi de la photo en cours ...";
			}
			else {
				Z.id("info").style.display = "block";
				Z.id("info_text").innerHTML = "Vous devez être connecté pour prendre des photos.";
			}
			Z.id("video").style.display = "block";
			Z.id("canvas").style.display = "none";
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez prendre la photo avant de la sauvegarder.";
		}
	});

	Z.id("clear").addEventListener("click", function() {
		snap = 0;
		Z.id("upload_file").value = "";
		Z.id("video").style.display = "block";
		Z.id("canvas").style.display = "none";
	});

	Z.id('upload_file').addEventListener('change', function() {

		if (logged == true) {
			var reader = new FileReader();
			reader.addEventListener('load', function() {
				var ext = Z.id('upload_file').files[0].name.substr(Z.id('upload_file').files[0].name.length - 3);;
				if (ext != 'png' && ext != 'jpg') {
					Z.id("info").style.display = "block";
					Z.id("info_text").innerHTML = "Votre photo doit être au format png !";
				}
				else {
					canvas.width = 640;
					canvas.height = 480;
					var b64 = reader.result;
					var img = new Image();
					img.onload = function() {
						context.drawImage(img, 0, 0, 640, 480);
						Z.id("video").style.display = "none";
						Z.id("canvas").style.display = "block";
						snap = 1;
					};
					img.src = b64;
				}
			});
			if (Z.id('upload_file').files)
				reader.readAsDataURL(Z.id('upload_file').files[0]);
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez être connecté pour choisir des photos.";
		}
	});

}, false);

Z.id("filter").addEventListener("click", function() {
	if (fullscreen == 0) {
		fullscreen = 1;
		Z.id("section").style.margin = "785px 0px 0px 0px";
		Z.id("video").style.width = "1000px";
		Z.id("video").style.height = "750px";
		Z.id("video").style.margin = "100px 0px 0px -705px";
		Z.id("canvas").style.width = "1000px";
		Z.id("canvas").style.height = "750px";
		Z.id("canvas").style.margin = "100px 0px 0px -705px";
		Z.id("filter").style.width = "1000px";
		Z.id("filter").style.height = "750px";
		Z.id("filter").style.margin = "-758px 0px 0px -705px";
		Z.id("filter_img").style.width = "1000px";
		Z.id("filter_img").style.height = "750px";
	}
	else {
		fullscreen = 0;
		Z.id("section").style.margin = "";
		Z.id("video").style.width = "";
		Z.id("video").style.height = "";
		Z.id("video").style.margin = "";
		Z.id("canvas").style.width = "";
		Z.id("canvas").style.height = "";
		Z.id("canvas").style.margin = "";
		Z.id("filter").style.width = "";
		Z.id("filter").style.height = "";
		Z.id("filter").style.margin = "";
		Z.id("filter_img").style.width = "";
		Z.id("filter_img").style.height = "";
	}
});

Z.id("filters_left").addEventListener("click", function() {
	if (key_filter == 0)
		key_filter = 9;
	else if (key_filter > 0)
		key_filter--;
	Z.id("filter_img").src = "public/img/" + filters[key_filter];
	Z.id("filters_name").innerHTML = "Chapeau " + key_filter;
});

Z.id("filters_right").addEventListener("click", function() {
	if (key_filter == 9)
		key_filter = 0;
	else if (key_filter < 9)
		key_filter++;
	Z.id("filter_img").src = "public/img/" + filters[key_filter];
	Z.id("filters_name").innerHTML = "Chapeau " + key_filter;
});
