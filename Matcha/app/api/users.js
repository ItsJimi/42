var express = require('express');
var router = express.Router();
var validator = require('validator');
var sendmail = require('sendmail')();
var bcrypt = require('bcryptjs');
var salt = bcrypt.genSaltSync(10);

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// Get User
router.get('/view', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("users", function(data) {
			if (data.length == 1) {
				res.json(data);
			}
			else {
				res.json({
					act: "user",
					request: false,
					message: "User not found"
				});
			}
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

// Update User
router.post('/update', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		if (validator.isEmail(req.body.mail)) {
			db.update("users", {
				username: validator.escape(sess.username)
			}, {
				$set: {
					mail: validator.escape(req.body.mail)
				}
			}, function() {
				res.json({
					act: "info",
					request: true,
					message: "Your mail address has been updated"
				});
			});
		}
		else {
			res.json({
				act: "info",
				request: false,
				message: "Wrong mail address (Ex: name@example.com)"
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

// Update pass
router.post('/pass', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		if (req.body.pass1 === req.body.pass2) {
			if (req.body.pass1.length >= 6) {
				db.update("users", {
					username: validator.escape(sess.username)
				}, {
					$set: {
						pass: bcrypt.hashSync(sess.username.toLowerCase() + req.body.pass1, salt)
					}
				}, function() {
					res.json({
						act: "info",
						request: true,
						message: "Your password has been updated"
					});
				});
			}
			else {
				res.json({
					act: "info",
					request: false,
					message: "Password must contain 6 caracters min"
				});
			}
		}
		else {
			res.json({
				act: "info",
				request: false,
				message: "Passwords not equals"
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

// Reset password
router.post('/reset', function(req, res) {
	if (req.body.username !== '') {
		db.get("users", function(data) {
			if (data.length == 1) {
				var randomPass = Math.random().toString(36).slice(-8);
				db.update("users", {
					username: validator.escape(req.body.username.toLowerCase())
				}, {
					$set: {
						pass: bcrypt.hashSync(req.body.username.toLowerCase() + randomPass, salt)
					}
				}, function() {
					sendmail({
						from: 'no-reply@choose.fr',
						to: validator.escape(data[0].mail),
						subject: 'Reset password',
						content: 'Your new password : ' + randomPass + ', please change your password in your settings.'
					}, function(err, reply) {
						// console.log(err && err.stack);
						res.json({
							act: "info",
							request: true,
							message: "Mail sent !"
						});
					});
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
			username: validator.escape(req.body.username.toLowerCase())
		});
	}
	else {
		res.json({
			act: "info",
			request: false,
			message: "Field empty"
		});
	}
});

module.exports = router;
