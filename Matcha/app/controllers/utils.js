var hash = require('mhash');
var lwip = require('lwip');

module.exports = {
	passHash : function(username, pass) {
		return (hash("whirlpool", username + pass));
	},
	validateEmail : function(email) {
    	var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    	return re.test(email);
	},
	img: function(picture, callback) {
        var encondedImageBuffer = new Buffer(picture, 'base64');
        lwip.open(encondedImageBuffer, 'jpg', function(err, image) {
            if (err) {
                console.log(err);
            } else {
                image.batch().cover(512, 512).toBuffer('png', function(e, buffer) {
                    if (e) {
                        console.log(e);
                    } else {
                        base64Image = buffer.toString('base64');
                        callback(base64Image);
                    }
                });
            }
        });
    }
};
