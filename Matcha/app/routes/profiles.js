var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.render('./layouts/profiles', {
				name: c.site.name,
				author: c.site.author,
				ajax: ajax,
				nav: true,
				page: 'Profiles',
				users: users,
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
router.get('/:username/edit', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.render('./layouts/edit', {
				name: c.site.name,
				author: c.site.author,
				ajax: ajax,
				nav: true,
				page: 'Edit profile',
				users: users,
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
