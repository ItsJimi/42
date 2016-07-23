var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.render('./index', {
				ajax: ajax,
				users: users,
				me: {
					firstname: sess.firstname,
					lastname: sess.lastname
				}
			});
		}, {});
	}
	else
		res.redirect('/auth');
});

module.exports = router;
