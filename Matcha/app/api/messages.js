var express = require('express');
var router = express.Router();
var validator = require('validator');

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// Get Conversation
router.get('/:username', function(req, res) {
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
					act: "info",
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
});

module.exports = router;
