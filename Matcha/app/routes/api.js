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

	if (sess.username) {
		var profile = {};

		if (req.body.firstname)
			profile.firstname = util.escapeHtml(req.body.firstname);
		if (req.body.lastname)
			profile.lastname = util.escapeHtml(req.body.lastname);
		if (req.body.location)
			profile.location = util.escapeHtml(req.body.location);
		try {
			profile.birthdate = new Date(req.body.birthdate).toISOString();
		}
		catch (e) {}
		if (req.body.gender === "Man")
			profile.gender = "Man";
		else if (req.body.gender === "Woman")
			profile.gender = "Woman";
		else
			profile.gender = "Unknown";
		if (req.body.preference === "Man")
			profile.preference = "Man";
		else if (req.body.preference === "Woman")
			profile.preference = "Woman";
		else
			profile.preference = "Both";
		if (req.body.bio)
			profile.bio = util.escapeHtml(req.body.bio);

		db.update("profiles", {
			username: sess.username
		}, {
			$set: profile
		}, function() {
			res.json({
				act: "info",
				request: true,
				message: "Your profile has been updated."
			});
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
