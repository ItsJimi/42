var express = require('express');
var router = express.Router();

var profiles = require('./profiles.js');
var img = require('./img.js');
var tags = require('./tags.js');
var mail = require('./mail.js');
var messages = require('./messages.js');
var users = require('./users.js');

router.get('/', function (req, res) {
	res.send("Choose API v0.1 !");
});

// Profiles
router.use('/profiles', profiles);

// Img
router.use('/img', img);

// Tags
router.use('/tags', tags);

// Mail
router.use('/mail', mail);

// Messages
router.use('/messages', messages);

// Users
router.use('/users', users);

module.exports = router;
