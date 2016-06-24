var ws = new WebSocket('ws://' + window.location.hostname + ':' + window.location.port + '/');

ws.onerror = function(err) {
	console.log(err);
};
ws.onopen = function () {
	console.log('WS :)');
};
ws.onmessage = function(data) {
	try {
		var res = JSON.parse(data.data);
		console.log(res);
		if (res.act === "info") {
			notif(res);
		}
	} catch (e) {
		console.log(e);
	}
};

function sendData(obj) {
	try {
		ws.send(JSON.stringify(obj));
	}
	catch(e) {
		console.log("Error sendData : " + e);
	}
}

function notif(res) {
	if (res.end === "true")
		$("#info").css("background", "#27ae60");
	else
		$("#info").css("background", "#c0392b");
	$("#info").text(res.message);
	$("#info").fadeIn("fast");
	setTimeout(function() {
		$("#info").fadeOut("fast");
	}, 6000);
}
