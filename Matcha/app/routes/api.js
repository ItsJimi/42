var express = require('express');
var router = express.Router();

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/', function (req, res) {
	var sess = req.session;

	if (sess.username)
		res.send("Choose API v0.1 : ' /api/username ' to get Json profile.");
	else
		res.redirect('/login');
});
router.get('/profiles', function (req, res) {
	var sess = req.session;

	// if (sess.username) {
		db.sortl("profiles", 5, {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.json(users);
	    }, {});
	// }
	// else
	// 	res.redirect('/login');
});
router.get('/profiles/:nbr', function (req, res) {
	var sess = req.session;

	// if (sess.username) {
		db.sortl("profiles", parseInt(req.params.nbr), {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.json(users);
	    }, {});
	// }
	// else
	// 	res.redirect('/login');
});
// router.get('/profiles/:username', function (req, res) {
// 	var sess = req.session;
//
// 	if (sess.username) {
// 		db.sort("profiles", {
// 			score: -1,
// 			name: 1
// 		}, function(json) {
// 			var users = json;
// 			if (users[0]) {
// 				res.json(users[0]);
// 			}
// 	    }, {
// 			username: req.params.username
// 		});
// 	}
// 	else
// 		res.redirect('/login');
// });

module.exports = router;
