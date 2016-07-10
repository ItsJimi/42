var express = require('express');
var router = express.Router();
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
			profile.firstname = util.escapeHtml(req.body.firstname);
		if (req.body.lastname)
			profile.lastname = util.escapeHtml(req.body.lastname);
		if (req.body.location) {
		http.request({
		    host: "maps.googleapis.com",
		    path: "/maps/api/geocode/json?address=" + util.escapeHtml(req.body.location) + "&key=AIzaSyCcrz8h8SAOcv2S92upJPFUreYHV6DATS8",
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
			profile.bio = util.escapeHtml(req.body.bio);

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

		util.img(img, size, function(buffer) {
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
