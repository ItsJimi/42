var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/:username', function (req, res) {
	db.get("users", function(data) {
		if (data.length == 1) {
			console.log("ok");
		}
		else {
			console.log("ko");
		}
	}, {
		username: req.params.username.toLowerCase()
	});
});

module.exports = router;
