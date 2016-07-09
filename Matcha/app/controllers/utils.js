module.exports = {
	validateEmail : function(email) {
    	var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    	return re.test(email);
	},
	escapeHtml: function(text) {
		var map = {
			'&': '&amp;',
			'<': '&lt;',
			'>': '&gt;',
			'"': '&quot;',
			"'": '&#039;'
		};
		return text.replace(/[&<>"']/g, function(m) { return map[m]; });
	},
	unescapeHtml: function(text) {
		return text.replace(/&lt;/g,'<').replace(/&gt;/g,'>').replace(/&amp;/g,'&').replace(/&quot;/g,'"').replace(/&#039;/g,"'");
	}
	// },
	// img: function(picture, callback) {
    //     var encondedImageBuffer = new Buffer(picture, 'base64');
    //     lwip.open(encondedImageBuffer, 'jpg', function(err, image) {
    //         if (err) {
    //             console.log(err);
    //         } else {
    //             image.batch().cover(512, 512).toBuffer('png', function(e, buffer) {
    //                 if (e) {
    //                     console.log(e);
    //                 } else {
    //                     base64Image = buffer.toString('base64');
    //                     callback(base64Image);
    //                 }
    //             });
    //         }
    //     });
    // }
};
