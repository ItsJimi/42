var express = require('express');
var router = express.Router();
var bcrypt = require('bcryptjs');
var salt = bcrypt.genSaltSync(10);
var validator = require('validator');
var geoip = require('geoip-lite');
var sendmail = require('sendmail')();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// SignIn and SignUp view
router.get('/', function (req, res) {
	var sess = req.session;

	if (!sess.username)
		res.render('./login', {});
	else
		res.redirect('/');
});

// SignIn POST
router.post('/signin', function (req, res) {
	var sess = req.session;

	if (!sess.username) {
		if (!req.body.username || !req.body.pass)
			return (false);
		db.get("users", function(data) {
			if (data.length == 1) {
				if (data[0].username === req.body.username.toLowerCase() && bcrypt.compareSync(req.body.username.toLowerCase() + req.body.pass, data[0].pass)) {
					if (data[0].valid == 1) {
						sess.username = validator.escape(data[0].username);
						db.get("profiles", function(data) {
							if (data.length == 1) {
								res.json({
									request: true,
									message: "Connected !"
								});
								return (true);
							}
						},
						{
							username: validator.escape(data[0].username)
						});
					}
					else {
						res.json({
							request: false,
							message: "Your mail address is not verified."
						});
						return (false);
					}
				}
				else {
					res.json({
						request: false,
						message: "Wrong informations"
					});
					return (false);
				}
			}
			else {
				res.json({
					request: false,
					message: "Wrong informations"
				});
				return (false);
			}
		}, {
			username: validator.escape(req.body.username.toLowerCase())
		});
	}
	else
		res.redirect('/');
});

// SignUp POST
router.post('/signup', function (req, res) {
	var sess = req.session;

	if (!sess.username) {
		if (!req.body.username || !req.body.firstname || !req.body.lastname || !req.body.mail || !req.body.pass1 || !req.body.pass2) {
			res.json({
				request: false,
				message: "Fields empty."
			});
			return (false);
		}
		if (req.body.pass1 !== req.body.pass2) {
			res.json({
				request: false,
				message: "Passwords don't match."
			});
			return (false);
		}
		if (!validator.isAlphanumeric(req.body.username)) {
			res.json({
				act: "info",
				request: false,
				message: "Usernames must contain only alphanumeric chars"
			});
			return (false);
		}
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
		db.get("users", function(data) {
			if (data.length == 1) {
				res.json({
					act: "info",
					request: false,
					message: "Already used."
				});
				return (false);
			}
			else {
				if (validator.isEmail(req.body.mail)) {
					var geo = geoip.lookup(ip);
					var ip = req.headers['x-forwarded-for'] || req.connection.remoteAddress;

					if (geo)
						var pos = [geo.ll[1], geo.ll[0]];
					else
						var pos = [2.3522219, 48.856614];
					db.insert("profiles", {
						username: validator.escape(req.body.username.toLowerCase()),
						firstname: validator.escape(req.body.firstname),
						lastname: validator.escape(req.body.lastname),
						pos: pos
					});
					db.insert("users", {
						username: validator.escape(req.body.username.toLowerCase()),
						mail: validator.escape(req.body.mail),
						pass: bcrypt.hashSync(req.body.username.toLowerCase() + req.body.pass1, salt)
					}, function(err, data) {
						console.log(data);
						sendmail({
							from: 'no-reply@choose.fr',
							to: validator.escape(req.body.mail),
							subject: 'Welcome to Choose !',
							content: 'Please valid your mail address with this link : http://localhost:3001/api/mail/valid/' + validator.escape(req.body.username.toLowerCase()) + '/' + data.ops[0]._id
						}, function(err, reply) {
							console.log(err && err.stack);
						});
						res.json({
							act: "info",
							request: true,
							message: "Yeah, welcome to Choose ! Please check your emails ;)"
						});
						return (true);
					});
				}
				else {
					res.json({
						act: "info",
						request: false,
						message: "Email not valid"
					});
					return (false);
				}
			}
		}, {
			$or: [
				{ username: validator.escape(req.body.username.toLowerCase()) },
				{ mail: validator.escape(req.body.mail) }
			]
		});
	}
	else
		res.redirect('/');
});

// SignOut
router.get('/logout', function (req, res) {
	req.session.destroy(function(err) {
		if (err)
			console.log(err);
	});
	res.redirect('/auth');
});

module.exports = router;
