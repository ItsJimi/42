var express = require('express');
var router = express.Router();
var validator = require('validator');
var http = require('http');

var db = require('../controllers/database.js');
var util = require('../controllers/utils.js');

router.get('/', function (req, res) {
	res.send("Choose API v0.1 !");
});

// View all profiles
router.get('/profiles/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("profiles", {
			username: 1
		}, function(json) {
			var user = json;

			res.json(user);
		}, {});
	}
});
// View your profile
router.get('/profiles/view/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			var user = json;

			res.json(user);
		}, {
			username: sess.username
		});
	}
});
// View <username> profile
router.get('/profiles/view/:username', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			var user = json;

			res.json(user);
		}, {
			username: req.params.username
		});
	}
});
// Update your profile
router.post('/profiles/update/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		var profile = {};

		if (req.body.firstname)
			profile.firstname = validator.escape(req.body.firstname);
		if (req.body.lastname)
			profile.lastname = validator.escape(req.body.lastname);
		if (req.body.location) {
		http.request({
		    host: "maps.googleapis.com",
		    path: "/maps/api/geocode/json?address=" + validator.escape(req.body.location) + "&key=AIzaSyCcrz8h8SAOcv2S92upJPFUreYHV6DATS8",
		    method: 'GET'
		}, function(res) {
		    res.setEncoding('utf8');
		    var body = '';
		    res.on('data', function(chunk) {
		        body += chunk;
		    });
		    res.on('end', function() {
				try {
					console.log(body);
				} catch (e) {
				}
		    });
		}).end();

		}
		try {
			profile.birthdate = new Date(req.body.birthdate).toISOString();
		}
		catch (e) {}
		if (req.body.gender === "Man")
			profile.gender = "Man";
		else if (req.body.gender === "Woman")
			profile.gender = "Woman";
		else
			profile.gender = "Unknown";
		if (req.body.preference === "Man")
			profile.preference = "Man";
		else if (req.body.preference === "Woman")
			profile.preference = "Woman";
		else
			profile.preference = "Both";
		if (req.body.bio)
			profile.bio = validator.escape(req.body.bio);

		db.update("profiles", {
			username: sess.username
		}, {
			$set: profile
		}, function() {
			res.json({
				act: "info",
				request: true,
				message: "Your profile has been updated."
			});
		});
	}
});

// View all img
router.get('/img/view/:username/:size', function (req, res) {
	db.get("profiles", function(json) {
		if (!json[0]) {
			res.sendStatus(404);
			return (false);
		}
		if (json[0].img)
			var img = json[0].img[0].split(",")[1];
		else
			var img = "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";

		var size = parseInt(req.params.size);
		if (!size || size < 1 || size > 1000)
			size = 200;

		util.img(img, size, 'png', function(buffer) {
			res.writeHead(200, {
				'Content-Type': 'image/png',
				'Content-Length': buffer.length
		   });
		   res.end(buffer);
		});
	}, {
		username: req.params.username
	});
});
// Upload your img
router.post('/img/upload/', function (req, res) {
	var sess = req.session;

	if (sess.username) {
		db.get("profiles", function(json) {
			if (json[0].img) {
				if (json[0].img.length == 5) {
					res.json({
						act: "info",
						request: false,
						message: "You already have 5 pictures."
					});
					return (false);
				}
			}

			switch (req.body.type) {
	            case "image/jpeg": {
	                format = 'jpg'
	                break;
	            }
	            case "image/png": {
	                format = 'png'
	                break;
	            }
	            case "image/gif": {
	                format = 'gif'
	                break;
	            }
				default: {
					res.json({
						act: "info",
						request: false,
						message: "Format not supported. Ex : JPG, PNG, GIF"
					});
					return (false);
				}
	        }

			util.img(req.body.objectData, 300, format, function(buffer) {
				var image = buffer.toString('base64');

				db.update("profiles", {
					username: sess.username
				}, {
					$push: {
						img: image
					}
				}, function() {
					res.json({
						act: "info",
						request: true,
						message: "Your profile has been updated."
					});
				});
			});
		}, {
			username: sess.username
		});
	}
});

// View all tags
router.get('/tags/', function (req, res) {
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
router.get('/tags/view/:tag', function (req, res) {
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

module.exports = router;
