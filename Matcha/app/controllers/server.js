var server = require('http').createServer();
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ server: server });

module.exports = {
	getServer: function() {
		return (server);
	},
	getWss: function() {
		return (wss);
	},
	getUser: function(user) {
		var users = [];
        wss.clients.forEach(function (value) {
            if (value.username == user) {
                users.push(value);
            }
        });
        return users;
	},
	sendData: function(ws, obj) {
		try {
			ws.send(JSON.stringify(obj));
		}
		catch(e) {
			console.log("Error sendData : " + e);
		}
	}
};
