var lwip = require('lwip');

module.exports = {
	img: function(picture, size, type, callback) {
        var encondedImageBuffer = new Buffer(picture, 'base64');
        lwip.open(encondedImageBuffer, type, function(err, image) {
            if (err) {
                console.log(err);
            } else {
                image.batch().cover(size, size).toBuffer('png', function(e, buffer) {
                    if (e)
                        console.log(e);
					else
                        callback(buffer);
                });
            }
        });
    },
	getUser: function(wss, user) {
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
	},
	removeSlash: function(text) {
	    return text.replace(/[/]/g, '');
	}
};
