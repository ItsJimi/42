Z.id("canvas").style.display = "none";

window.addEventListener("DOMContentLoaded", function() {
	// Grab elements, create settings, etc.
	var canvas = Z.id("canvas"),
		context = canvas.getContext("2d"),
		video = Z.id("video"),
		videoObj = { "video": true },
		errBack = function(error) {
			Z.l("Video capture error: ", error.code);
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
	else if(navigator.mozGetUserMedia) { // Firefox-prefixed
		navigator.mozGetUserMedia(videoObj, function(stream){
			video.src = window.URL.createObjectURL(stream);
			video.play();
		}, errBack);
	}

	// Trigger photo take
	Z.id("snap").addEventListener("click", function() {
		canvas.width = 640;
		canvas.height = 480;
		context.drawImage(video, 0, 0, 640, 480);
		Z.id("video").style.display = "none";
		Z.id("canvas").style.display = "block";
	});

	Z.id("save").addEventListener("click", function() {
		Z.l(canvas.toDataURL("image/png"));
	});

	Z.id("clear").addEventListener("click", function() {
		Z.id("video").style.display = "block";
		Z.id("canvas").style.display = "none";
	});
}, false);

var fullscreen = 0;
Z.id("filter").addEventListener("click", function() {
	if (fullscreen == 0) {
		fullscreen = 1;
		Z.id("video").style.width = "1000px";
		Z.id("video").style.height = "750px";
		Z.id("video").style.margin = "100px 0px 0px -705px";
		Z.id("filter").style.width = "1000px";
		Z.id("filter").style.height = "750px";
		Z.id("filter").style.margin = "-762px 0px 0px -705px";
	}
	else {
		fullscreen = 0;
		Z.id("video").style.width = "";
		Z.id("video").style.height = "";
		Z.id("video").style.margin = "";
		Z.id("filter").style.width = "";
		Z.id("filter").style.height = "";
		Z.id("filter").style.margin = "";
	}
	Z.l(fullscreen);
});

function allowDrop(ev) {
	ev.preventDefault();
}

function drag(ev) {
	ev.dataTransfer.setData("text", ev.target.id);
}

function drop(ev) {
	ev.preventDefault();
	var data = ev.dataTransfer.getData("text");
	ev.target.appendChild(document.getElementById(data));
}
