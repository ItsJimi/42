var ws = new WebSocket('ws://' + window.location.hostname + ':' + window.location.port + '/');

ws.onerror = function(err) {
	console.log(err);
};
ws.onopen = function () {
	console.log('WS :)');
};
ws.onmessage = function(data) {
	console.log(data.data);
};

function sendData(obj) {
	try {
		ws.send(JSON.stringify(obj));
	}
	catch(e) {
		console.log("Error sendData : " + e);
	}
}
