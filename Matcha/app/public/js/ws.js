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
			info(res);
		}
		else if (res.act === "notif") {
			notif(res.message, res.icon);
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
