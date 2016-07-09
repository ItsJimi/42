var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/:username', function (req, res) {
	db.get("profiles", function(data) {
		if (data.length == 1) {
			var img = data[0].img[0].split(",");
			// util.img(img[1], function(img){
			// 	res.send('data:image/png;base64,' + img);
			// });
		}
		else {
			console.log("ko");
		}
	}, {
		username: req.params.username.toLowerCase()
	});
});

module.exports = router;
