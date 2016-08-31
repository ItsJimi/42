var express = require('express');
var router = express.Router();
var validator = require('validator');
var http = require('http');
var sendmail = require('sendmail')();
var ObjectId = require('mongodb').ObjectID;

var server = require('../controllers/server.js');
var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// View all profiles
router.get('/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (req.query.filters) {
			var filters = {
				age_min: 18,
				age_max: 120,
				score_min: 0,
				score_max: 100,
				dist: 10,
				tags: []
			}
			if (req.query.age_min)
				filters.age_min = parseInt(req.query.age_min);
			if (req.query.age_max)
				filters.age_max = parseInt(req.query.age_max);
			if (req.query.score_min)
				filters.score_min = parseInt(req.query.score_min);
			if (req.query.score_max)
				filters.score_max = parseInt(req.query.score_max);
			if (req.query.tags) {
				var tags = req.query.tags.split(",");
				tags.forEach(function(tag) {
					if (tag.trim() !== '')
						filters.tags.push(tag.trim());
				});
			}

			if (parseInt(req.query.dist) !== NaN) {
				util.getPeoplesNearFilters(sess.username, parseInt(req.query.dist), filters, function(data) {
					data.sort(function(a, b) {
						return (b.filter - a.filter);
					});

					data = data.slice(Math.max(data.length - 20, 0));

					res.json(data);
				});
			}
			else {
				res.json({
					act: "info",
					request: false,
					message: "error"
				});
			}
		}
		else {
			var users = [];

			util.getPeoplesNear(sess.username, 10, function(data) {
				data.sort(function(a, b) {
					return (b.filter - a.filter);
				});

				data = data.slice(Math.max(data.length - 20, 0));

				res.json(data);
			});
		}

	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
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
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
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
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
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
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Liked profiles
router.get('/like', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("like", function(data) {
			res.json(data);
		}, {
			'users.1': validator.escape(sess.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
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
		db.get("block", function(data) {
			if (data.length == 0) {
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
							db.get("like", function(data) {
								if (data.length == 1) {
									db.insert("like", {
										users: [
											validator.escape(sess.username),
											validator.escape(req.params.username)
										],
										match: true
									}, function() {
										db.update("like", {
											'users.0': validator.escape(req.params.username),
											'users.1': validator.escape(sess.username)
										}, {
											$set: {
												match: true
											}
										});
										db.get("block", function(data) {
											if (data.length == 0) {
												server.getUser(req.params.username).forEach(function(user) {
													server.sendData(user, {
														act: "notif",
														from: validator.escape(sess.username),
														message: validator.escape(sess.username) + " and you match ! <3"
													});
												});
												db.insert("notifs", {
													username: validator.escape(req.params.username),
													from: validator.escape(sess.username),
													message: validator.escape(sess.username) + " and you match ! <3"
												});
											}
										}, {
											'users.0': validator.escape(req.params.username),
											'users.1': validator.escape(sess.username)
										});
										res.json({
											act: "like",
											request: true,
											message: "Great, " + validator.escape(req.params.username) + " and you match ! <3"
										});
									});
								}
								else {
									db.insert("like", {
										users: [
											validator.escape(sess.username),
											validator.escape(req.params.username)
										]
									}, function() {
										db.get("block", function(data) {
											if (data.length == 0) {
												server.getUser(req.params.username).forEach(function(user) {
													server.sendData(user, {
														act: "notif",
														from: validator.escape(sess.username),
														message: validator.escape(sess.username) + " like you ! <3"
													});
												});
												db.insert("notifs", {
													username: validator.escape(req.params.username),
													from: validator.escape(sess.username),
													message: validator.escape(sess.username) + " like you ! <3"
												});
											}
										}, {
											'users.0': validator.escape(req.params.username),
											'users.1': validator.escape(sess.username)
										});
										res.json({
											act: "like",
											request: true,
											message: "Great, you like " + validator.escape(req.params.username) + " now !"
										});
									});
								}
							}, {
								'users.0': validator.escape(req.params.username),
								'users.1': validator.escape(sess.username)
							});
						}
						else {
							db.remove("like", {
								users: [
									validator.escape(sess.username),
									validator.escape(req.params.username)
								]
							}, function() {
								db.get("like", function(data) {
									if (data.length == 1) {
										db.update("like", {
											'users.0': validator.escape(req.params.username),
											'users.1': validator.escape(sess.username)
										}, {
											$set: {
												match: false
											}
										});
									}
								}, {
									'users.0': validator.escape(req.params.username),
									'users.1': validator.escape(sess.username)
								});
								db.get("block", function(data) {
									if (data.length == 0) {
										server.getUser(req.params.username).forEach(function(user) {
											server.sendData(user, {
												act: "notif",
												from: validator.escape(sess.username),
												message: validator.escape(sess.username) + " don't like you ! </3"
											});
										});
										db.insert("notifs", {
											username: validator.escape(req.params.username),
											from: validator.escape(sess.username),
											message: validator.escape(sess.username) + " don't like you ! </3"
										});
									}
								}, {
									'users.0': validator.escape(req.params.username),
									'users.1': validator.escape(sess.username)
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
					username: validator.escape(req.params.username)
				});
			}
			else {
				res.json({
					act: "info",
					request: false,
					message: "Error"
				});
			}
		}, {
			"users.0": validator.escape(sess.username),
			"users.1": validator.escape(req.params.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Blocked profiles
router.get('/block', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("block", function(data) {
			res.json(data);
		}, {
			'users.0': validator.escape(sess.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
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
						db.remove("like", {
							users: [
								validator.escape(sess.username),
								validator.escape(req.params.username)
							]
						}, function() {
							db.update("like", {
								'users.0': validator.escape(req.params.username),
								'users.1': validator.escape(sess.username)
							}, {
								$set: {
									match: false
								}
							});
							res.json({
								act: "block",
								request: true,
								message: "You block " + validator.escape(req.params.username) + " now !"
							});
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
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
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
			res.json({
				act: "report",
				request: true,
				message: "An email was sent to administrator !"
			});
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Notifs
router.get('/notifs', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("notifs", function(data) {
			res.json(data);
		}, {
			username: validator.escape(sess.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Remove Notifs
router.post('/notifs/del', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.remove("notifs", {
			_id: ObjectId(req.body.id),
			username: validator.escape(sess.username)
		}, function() {
			res.json({
				request: true
			});
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Visited profiles
router.get('/visits', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var visits = [];

		db.get("visits", function(data) {
			data.forEach(function(profile) {
				if (visits.indexOf(profile.users[0]) == -1)
					visits.push(profile.users[0]);
			});
			res.json(visits);
		}, {
			'users.1': validator.escape(sess.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});
// Visits <username> profile
router.get('/visits/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (sess.username === req.params.username) {
			res.json({
				act: "visits",
				request: false,
				message: "It's you"
			});
			return (false);
		}
		db.get("profiles", function(data) {
			if (data.length == 0) {
				res.json({
					act: "visits",
					request: false,
					message: "User not found"
				});
				return (false);
			}

			db.get("visits", function(data) {
				if (data.length == 0) {
					db.update("profiles", {
						username: validator.escape(req.params.username)
					}, {
						$inc: {
							score: 1
						}
					});
				}
				db.insert("visits", {
					users: [
						validator.escape(sess.username),
						validator.escape(req.params.username)
					]
				}, function() {
					db.get("block", function(data) {
						if (data.length == 0) {
							server.getUser(req.params.username).forEach(function(user) {
								server.sendData(user, {
									act: "notif",
									from: validator.escape(sess.username),
									message: validator.escape(sess.username) + " visit you your profile ;)"
								});
							});
							db.insert("notifs", {
								username: validator.escape(req.params.username),
								from: validator.escape(sess.username),
								message: validator.escape(sess.username) + " visit you your profile ;)"
							});
						}
					}, {
						'users.0': validator.escape(req.params.username),
						'users.1': validator.escape(sess.username)
					});
					res.json({
						act: "visits",
						request: true
					});
				});
			}, {
				'users.0': validator.escape(sess.username),
				'users.1': validator.escape(req.params.username)
			});
		}, {
			username: validator.escape(req.params.username)
		});
	}
	else {
		res.json({
			act: "unauthorized",
			request: false,
			message: "Unauthorized"
		});
	}
});

module.exports = router;
