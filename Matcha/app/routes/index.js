var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.render('./index', {
				users: users,
				test: "coucou"
			});
		}, {});
	}
	else
		res.redirect('/login');
});

module.exports = router;
