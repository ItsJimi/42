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
		db.sort("profiles", {
			username: 1
		}, function(json) {
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
// Update your profile
router.post('/profiles/update/', function (req, res) {
	var sess = req.session;

	var firstname = util.htmlEscape(req.body.firstname);
	var lastname = util.htmlEscape(req.body.firstname);
	var localisation = util.htmlEscape(req.body.localisation);
	try {
		var birthdate = new Date(req.body.birthdate).toISOString();
	}
	catch (e) {
		res.json({
			act: "error",
			message: "Date format not valid."
		});
	}
	if (req.body.gender === "man")
		var gender = "Man";
	else if (req.body.gender === "woman")
		var gender = "Woman";
	else
		var gender = "Unknown";
	
	var preference = util.htmlEscape(req.body.firstname);
	var firstname = util.htmlEscape(req.body.firstname);
	var firstname = util.htmlEscape(req.body.firstname);
	var firstname = util.htmlEscape(req.body.firstname);
	var firstname = util.htmlEscape(req.body.firstname);

	if (sess.username) {
		db.update("profiles", {
			username: sess.username
		}, {
			$set: {
		        "firstname": req.body.firstname,
		        "lastname": req.body.flastname,

			}
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
