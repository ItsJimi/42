var express = require('express');
var router = express.Router();
var bcrypt = require('bcryptjs');
var salt = bcrypt.genSaltSync(10);
var validator = require('validator');

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
									end: "true",
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
							end: "false",
							message: "Your mail address is not verified."
						});
						return (false);
					}
				}
				else {
					res.json({
						end: "false",
						message: "Wrong informations"
					});
					return (false);
				}
			}
			else {
				res.json({
					end: "false",
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
				end: "false",
				message: "Fields empty."
			});
			return (false);
		}
		if (req.body.pass1 !== req.body.pass2) {
			res.json({
				end: "false",
				message: "Passwords don't match."
			});
			return (false);
		}
		db.get("users", function(data) {
			if (data.length == 1) {
				res.json({
					end: "false",
					message: "Already used."
				});
				return (false);
			}
			else {
				if (validator.isEmail(req.body.mail)) {
					db.insert("profiles", {
						username: validator.escape(eq.body.username.toLowerCase()),
						firstname: validator.escape(req.body.firstname),
						lastname: validator.escape(req.body.lastname)
					});
					db.insert("users", {
						username: validator.escape(req.body.username.toLowerCase()),
						mail: validator.escape(req.body.mail),
						pass: bcrypt.hashSync(req.body.username.toLowerCase() + req.body.pass1, salt)
					});
					res.json({
						end: "true",
						message: "Yeah ! Welcome to Choose !"
					});
					return (true);
				}
				else {
					res.json({
						end: "false",
						message: "Email not valid."
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
	res.redirect('/login');
});

module.exports = router;
