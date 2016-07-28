var express = require('express');
var router = express.Router();
var validator = require('validator');

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

// Valid mail
router.get('/valid/:username/:link', function(req, res) {
	db.get("users", function(data) {
		if (data.length == 1) {
			if (data[0].valid != true && data[0]._id == req.params.link) {
				db.update("users", {
					_id: data[0]._id
				}, {
					$set: {
						valid: true
					}
				}, function() {
					res.send("Your account has been verified");
				});
			}
			else
				res.send("Wrong link");
		}
		else
			res.send("Wrong link");
	}, {
		username: validator.escape(req.params.username)
	});
});

module.exports = router;
