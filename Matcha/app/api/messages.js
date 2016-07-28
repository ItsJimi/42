var express = require('express');
var router = express.Router();
var validator = require('validator');

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// Get Users
router.get('/users', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		var like = [];
		var users = [];

		db.get("like", function(data) {
			if (data.length > 0) {
				data.forEach(function(user) {
					if (user.match == true) {
						like.push(user.users[1]);
					}
				});
				db.get("profiles", function(data1) {
					data1.forEach(function(profile) {
						if (like.indexOf(profile.username) != -1)
							users.push(profile);
					});
					res.json(users);
				}, {});
			}
			else {
				res.json({
					act: "info",
					request: false,
					message: "No match"
				});
			}
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

// Get Conversation
router.get('/view/:username', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("messages", {
			'messages.date': 1
		}, function(data) {
			if (data.length == 1) {
				res.json(data);
			}
			else {
				res.json({
					act: "msg",
					request: false,
					message: "This conversation doesn't exist"
				});
			}
		}, {
			$and: [{
				users: {
					$in: [
						validator.escape(sess.username)
					]
				}
			}, {
				users: {
					$in: [
						validator.escape(req.params.username)
					]
				}
			}]
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
