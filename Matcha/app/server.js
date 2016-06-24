// Config
var c = require('../config.json');
var port = 3001;

// Modules
var favicon = require('serve-favicon');
var server = require('http').createServer();
var url = require('url');
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ server: server });
var express = require('express');
var session = require('express-session');
var bodyParser = require('body-parser');
var app = express();

// Session
app.use(session({ secret : 'MpCF12y', resave: false, saveUninitialized: true }));

// Controllers
var db = require('./controllers/database.js');
var util = require('./controllers/utils.js');

db.connect(function(database) {
	// ???
});

// Web Socket
wss.on('connection', function connection(ws) {
	var location = url.parse(ws.upgradeReq.url, true);
	// you might use location.query.access_token to authenticate or share sessions
	// or ws.upgradeReq.headers.cookie (see http://stackoverflow.com/a/16395220/151312)
	ws.on('message', function incoming(message) {
		try {
    		var res = JSON.parse(message);
			if (res.act === "search") {
				db.sort("users", {
					score: -1,
					name: 1
				}, function(data) {
					console.log(data);
			    }, {
					firstname: res.name
				});
			}
		} catch (e) {
			console.log('Error try ws : ' + e);
		}
		console.log('received: %s', res.act);
	});
});

// Set
app.set('view engine', 'pug');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));
app.use(bodyParser.json());

// Routes
app.get('/', function(req, res) {
	var sess = req.session;

	if (sess.username) {
		db.sort("profiles", {
			score: -1,
			name: 1
		}, function(json) {
			var users = json;
			res.render('./layouts/map', {
				name: c.site.name,
				author: c.site.author,
				users: users
			});
		}, {});
	}
	else
		res.redirect('/login');
});
app.get('/profiles/:username', function (req, res) {
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
app.get('/edit', function (req, res) {
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
app.get('/cdn/:username', function (req, res) {
	db.get("users", function(data) {
		if (data.length == 1) {
			console.log("ok");
		}
		else {
			console.log("ko");
		}
	}, {
		username: req.params.username.toLowerCase()
	});
});

// Login
app.get('/login', function (req, res) {
	var sess = req.session;

	if (!sess.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		res.render('./layouts/login', {
			name: c.site.name,
			author: c.site.author,
			ajax: ajax,
			page: 'Login'
		});
	}
	else
		res.redirect('/');
});
app.post('/signin', function (req, res) {
	var sess = req.session;

	if (!sess.username) {
		if (!req.body.username || !req.body.pass)
			return (false);
		db.get("users", function(data) {
			console.log(req.body.username);
			if (data.length == 1) {
				if (data[0].username === req.body.username.toLowerCase() && data[0].pass === util.passHash(req.body.username.toLowerCase(), req.body.pass)) {
					console.log("test");
					if (data[0].valid == 1) {
						sess.username = data[0].username;
						sess.mail = data[0].mail;
						db.get("profiles", function(data) {
							if (data.length == 1) {
								sess.firstname = data[0].firstname;
								sess.lastname = data[0].lastname;
							}
						},
						{
							username: data[0].username
						});
						res.status(200).send(JSON.stringify({
							end: "true",
							message: "Connected"
						}));
						res.redirect('/');
						return (true);
					}
					else {
						res.status(200).send(JSON.stringify({
							end: "false",
							message: "Your mail address is not verified."
						}));
						return (false);
					}
				}
			}
			res.status(200).send(JSON.stringify({
				end: "false",
				message: "Wrong informations"
			}));
			return (false);
		}, {
			username: req.body.username.toLowerCase()
		});
	}
	else
		res.redirect('/');
});
app.post('/signup', function (req, res) {
	var sess = req.session;

	if (!sess.username) {
		if (!req.body.username || !req.body.firstname || !req.body.lastname || !req.body.mail || !req.body.pass1 || !req.body.pass2) {
			res.status(200).send(JSON.stringify({
				end: "false",
				message: "Fields empty."
			}));
			return (false);
		}
		if (req.body.pass1 !== req.body.pass2) {
			res.status(200).send(JSON.stringify({
				end: "false",
				message: "Passwords don't match."
			}));
			return (false);
		}
		db.get("users", function(data) {
			if (data.length == 1) {
				res.status(200).send(JSON.stringify({
					end: "false",
					message: "Already used."
				}));
				return (false);
			}
			else {
				if (util.validateEmail(req.body.mail)) {
					db.insert("profiles", {
						username: req.body.username.toLowerCase(),
						firstname: req.body.firstname,
						lastname: req.body.lastname
					});
					db.insert("users", {
						username: req.body.username.toLowerCase(),
						mail: req.body.mail,
						pass: util.passHash(req.body.username.toLowerCase(), req.body.pass1)
					});
					res.status(200).send(JSON.stringify({
						end: "true",
						message: "Yeah ! Welcome to Choose !"
					}));
					return (true);
				}
				else {
					res.status(200).send(JSON.stringify({
						end: "false",
						message: "Email not valid."
					}));
					return (false);
				}
			}
		}, {
			$or: [
				{ username: req.body.username.toLowerCase() },
				{ mail: req.body.mail }
			]
		});
	}
	else
		res.redirect('/');
});
app.get('/logout', function (req, res) {
	req.session.destroy(function(err) {
		if (err)
			console.log(err);
	});
	res.redirect('/login');
});

app.use(function(req, res, next) {
	var ajax = (req.query.ajax === '') ? true : false;
	db.sortl("profiles", 3, {
		score: -1,
		firstname: 1
	}, function(json) {
		var users = json;
		res.status(404).render('./layouts/404', {
			name: c.site.name,
			author: c.site.author,
			ajax: ajax,
			page: '404',
			users: users,
			me: {
				firstname: session.firstname,
				lastname: session.lastname
			}
		});
    });
});

// Server
server.on('request', app);
server.listen(port, function () {
	console.log('Start at ' + server.address().port);
});
