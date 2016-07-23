var express = require('express');
var router = express.Router();
var validator = require('validator');

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// View all tags
router.get('/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("tags", {
			name: 1
		}, function(json) {
			var tags = json;

			res.json(tags);
		}, {});
	}
});
// View profiles with <tag>
router.get('/view/:tag', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("tags", {
			name: 1
		}, function(json) {
			var tags = json;

			res.json(tags);
		}, {});
	}
});
// Add tag
router.post('/add', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		if (!req.body.tag)
			return (false);
		if (!validator.isAlphanumeric(req.body.tag)) {
			res.json({
				act: "info",
				request: false,
				message: "Tags must contain only alphanumeric chars"
			});
			return (false);
		}

		db.update("profiles", {
			username: sess.username
		}, {
			 $addToSet: { tags: { $each: [ validator.escape(req.body.tag) ] } }
		}, function() {
			res.json({
				act: "info",
				request: true,
				message: validator.escape(req.body.tag) + " has been added to your tags"
			});
		});
		db.get("tags", function(data) {

			if (data.length == 0) {
				db.insert("tags", {
					name: validator.escape(req.body.tag)
				});
			}
		}, {
			name: validator.escape(req.body.tag)
		});
	}
});
// Del tag
router.post('/del', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.update("profiles", {
			username: sess.username
		}, {
			$pull: {
				tags: validator.escape(req.body.tag)
			}
		}, function(json) {
			res.json({
				act: "info",
				request: true,
				message: validator.escape(req.body.tag) + " has been deleted"
			});
		});
	}
});

module.exports = router;
