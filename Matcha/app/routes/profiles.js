var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');


router.get('/', function (req, res) {
	var sess = req.session;

	if (sess.username)
		res.redirect('/profiles/' + sess.username);
	else
		res.redirect('/login');
});
router.get('/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			if (users[0])
				var user = users[0];
			else
				var user = null;
			res.render('./profiles', {
				ajax: ajax,
				user: user,
				me: {
					firstname: sess.firstname,
					lastname: sess.lastname
				}
			});
	    }, {
			username: req.params.username
		});
	}
	else
		res.redirect('/login');
});
router.get('/:username/edit', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var user = json;
			res.render('./edit', {
				ajax: ajax,
				users: user,
				me: {
					firstname: sess.firstname,
					lastname: sess.lastname
				}
			});
	    }, {});
	}
	else
		res.redirect('/login');
});

module.exports = router;
