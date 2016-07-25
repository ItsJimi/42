var express = require('express');
var router = express.Router();
var validator = require('validator');
var http = require('http');
var sendmail = require('sendmail')();

var server = require('../controllers/server.js');
var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// View all profiles
router.get('/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var users = [];
		var block = [];
		if (req.query.block === "true") {
			db.get("block", function(data) {
				if (data.length > 0) {
					data.forEach(function(user) {
						block.push(user.users[1]);
					});
					db.get("profiles", function(data1) {
						data1.forEach(function(profile) {
							if (block.indexOf(profile.username) == -1)
								users.push(profile);
						});
						res.json(users);
					}, {});
				}
				else {
					db.get("profiles", function(data1) {
						res.json(data1);
					}, {});
				}
			}, {
				'users.0': validator.escape(sess.username)
			});
		}
		else {
			db.sort("profiles", {
				username: 1
			}, function(data) {
				res.json(data);
			}, {});
		}
	}
});
// View your profile
router.get('/view/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(data) {
			res.json(data);
		}, {
			username: sess.username
		});
	}
});
// View <username> profile
router.get('/view/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(data) {

			db.get("like", function(data1) {
				if (data1.length == 1)
					data[0].like = true;

				res.json(data);
			}, {
				'users.0': validator.escape(sess.username),
				'users.1': validator.escape(req.params.username)
			});
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
// Like <username> profile
router.get('/like/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (sess.username === req.params.username) {
			res.json({
				act: "like",
				request: false,
				message: "Really ?! It's you ..."
			});
			return (false);
		}
		db.get("profiles", function(data) {
			if (data.length == 0) {
				res.json({
					act: "like",
					request: false,
					message: "User not found"
				});
				return (false);
			}
			if (!data[0].img) {
				res.json({
					act: "like",
					request: false,
					message: "You must have one picture to match or unmatch people"
				});
				return (false);
			}

			db.get("like", function(data) {
				if (data.length == 0) {
					db.insert("like", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					}, function() {
						server.getUser(req.params.username).forEach(function(user) {
							server.sendData(user, {
								act: "notif",
								from: validator.escape(sess.username),
								message: validator.escape(sess.username) + " like you ! <3"
							});
						});
						res.json({
							act: "like",
							request: true,
							message: "Great, you like " + validator.escape(req.params.username) + " now !"
						});
					});
				}
				else {
					db.remove("like", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					}, function() {
						server.getUser(req.params.username).forEach(function(user) {
							console.log(user.username);
							server.sendData(user, {
								act: "notif",
								from: validator.escape(sess.username),
								message: validator.escape(sess.username) + " don't like you ! </3"
							});
						});
						res.json({
							act: "unlike",
							request: true,
							message: "You don't like " + validator.escape(req.params.username) + " now !"
						});
					});
				}
			}, {
				'users.0': validator.escape(sess.username),
				'users.1': validator.escape(req.params.username)
			});
		}, {
			username: validator.escape(sess.username)
		});
	}
});
// Block <username> profile
router.get('/block/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (sess.username === req.params.username) {
			res.json({
				act: "block",
				request: false,
				message: "Really ?! It's you ..."
			});
			return (false);
		}
		db.get("profiles", function(data) {
			if (data.length == 0) {
				res.json({
					act: "block",
					request: false,
					message: "User not found"
				});
				return (false);
			}
			if (!data[0].img) {
				res.json({
					act: "block",
					request: false,
					message: "You must have one picture to match or unmatch people"
				});
				return (false);
			}

			db.get("block", function(data) {
				if (data.length == 0) {
					db.insert("block", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					}, function() {
						res.json({
							act: "block",
							request: true,
							message: "You block " + validator.escape(req.params.username) + " now !"
						});
					});
				}
				else {
					db.remove("block", {
						users: [
							validator.escape(sess.username),
							validator.escape(req.params.username)
						]
					}, function() {
						res.json({
							act: "unblock",
							request: true,
							message: "You don't block " + validator.escape(req.params.username) + " now !"
						});
					});
				}
			}, {
				'users.0': validator.escape(sess.username),
				'users.1': validator.escape(req.params.username)
			});
		}, {
			username: validator.escape(sess.username)
		});
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
			res.json({
				act: "report",
				request: true,
				message: "An email was sent to administrator !"
			});
		});
	}
});

module.exports = router;
