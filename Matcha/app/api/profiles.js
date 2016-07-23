var express = require('express');
var router = express.Router();
var validator = require('validator');
var http = require('http');
var sendmail = require('sendmail')();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// View all profiles
router.get('/', function (req, res) {
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
router.get('/view/', function (req, res) {
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
router.get('/view/:username', function (req, res) {
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
router.post('/update/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var profile = {};

		if (!validator.isAlpha(req.body.firstname)) {
			res.json({
				act: "info",
				request: false,
				message: "Firstnames must contain only alphabetic chars"
			});
			return (false);
		}
		if (!validator.isAlpha(req.body.lastname)) {
			res.json({
				act: "info",
				request: false,
				message: "Lastnames must contain only alphabetic chars"
			});
			return (false);
		}

		if (req.body.firstname)
			profile.firstname = validator.escape(req.body.firstname);
		if (req.body.lastname)
			profile.lastname = validator.escape(req.body.lastname);
		if (req.body.location) {
			http.request({
                hostname: 'maps.googleapis.com',
                path: '/maps/api/geocode/json?address=' + encodeURIComponent(req.body.location.trim())
            }, function(response) {
				response.setEncoding('utf8');
			    var body = '';
			    response.on('data', function(chunk) {
			        body += chunk;
			    });
			    response.on('end', function() {
					try {
						var data = JSON.parse(body);
						if (data) {
							console.log(data.results[0].formatted_address);
							console.log(data.results[0].geometry.location.lng);
							console.log(data.results[0].geometry.location.lat);
		                    db.update("profiles", {
		                        username: sess.username
		                    }, {
		                        $set: {
		                            pos: [
		                                data.results[0].geometry.location.lng,
		                                data.results[0].geometry.location.lat
									],
		                            location: data.results[0].formatted_address
		                        }
		                    });
		                }
					} catch (e) {}
			    });
            }).end();
		}
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
			profile.bio = validator.escape(req.body.bio);

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
// Match <username> profile
router.get('/match/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (sess.username === req.params.username) {
			res.json({
				act: "info",
				request: false,
				message: "Really ?! It's you ..."
			});
			return (false);
		}
		db.get("profiles", function(data) {
			if (data.length == 0) {
				res.json({
					act: "info",
					request: false,
					message: "User not found"
				});
				return (false);
			}
			if (!data.img[0]) {
				res.json({
					act: "info",
					request: false,
					message: "You must have one picture to match people"
				});
				return (false);
			}

			db.get("match", function(data) {
				if (data.length == 0) {
					db.insert("match", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					}, function() {
						res.json({
							act: "info",
							request: true,
							message: "Great, you like " + validator.escape(req.params.username) + " now !"
						});
					});
				}
				else {
					db.remove("match", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					});
				}
			}, {
				'users.0': validator.escape(sess.username)
			});
		}, {
			username: validator.escape(sess.username)
		});
	}
});
// Unmatch <username> profile
router.get('/block/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {

	}
});
// Report <username> profile
router.get('/report/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		sendmail({
			from: 'report@choose.fr',
			to: 'jimi+admin@fruitice.fr',
			subject: 'Report member',
			content: sess.username + ' has reported ' + req.params.username
		}, function(err, reply) {
			console.log(err && err.stack);
		});
	}
});

module.exports = router;
