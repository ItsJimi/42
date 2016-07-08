var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/', function (req, res) {
	res.send("Choose API v0.1 !");
});

// View all profiles
router.get('/profiles/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			var user = json;

			res.json(user);
		}, {});
	}
});
// View your profile
router.get('/profiles/view/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			var user = json;

			res.json(user);
		}, {
			username: sess.username
		});
	}
});
// View <username> profile
router.get('/profiles/view/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			var user = json;

			res.json(user);
		}, {
			username: req.params.username
		});
	}
});

// View all tags
router.get('/tags/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("tags", {
			name: 1
		}, function(json) {
			var tags = json;

			res.json(tags);
		}, {});
	}
});
// View profiles with <tag>
router.get('/tags/view/:tag', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("tags", {
			name: 1
		}, function(json) {
			var tags = json;

			res.json(tags);
		}, {});
	}
});

module.exports = router;
