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
    }
};
