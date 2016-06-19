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
var app = express();

// Session
app.use(session({ secret : 'MpCF12y', resave: false, saveUninitialized: true }));

// Controllers
var db = require('./controllers/database.js');
var util = require('./controllers/utils.js');

// Global var
var session;

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
			else if (res.act === "signin") {
				if (!res.mail || !res.pass)
					return (false);
				db.get("users", function(data) {
					if (data.length == 1) {
						if (data[0].mail === res.mail && data[0].pass === util.passHash(res.mail, res.pass)) {
							ws.send(JSON.stringify({
								act: "info",
								end: "true",
								message: "Connected !!"
							}));
							session.username = data[0].username;
							session.mail = data[0].mail;
							console.log(session);
							return (true);
						}
					}
					ws.send(JSON.stringify({
						act: "info",
						end: "false",
						message: "Wrong informations !"
					}));
					return (false);
				}, {
					mail: res.mail
				});
			}
			else if (res.act === "signup") {
				if (!res.username || !res.firstname || !res.lastname || !res.mail || !res.pass1 || !res.pass2) {
					ws.send(JSON.stringify({
						act: "info",
						end: "false",
						message: "Field empty."
					}));
					return (false);
				}
				if (res.pass1 !== res.pass2) {
					ws.send(JSON.stringify({
						act: "info",
						end: "false",
						message: "Passwords don't match."
					}));
					return (false);
				}
				db.get("users", function(data) {
					if (data.length == 1) {
						ws.send(JSON.stringify({
							act: "info",
							end: "false",
							message: "Already used."
						}));
						return (false);
					}
					else {
						if (util.validateEmail(res.mail)) {
							db.insert("profiles", {
								username: res.username.toLowerCase(),
								firstname: res.firstname,
								lastname: res.lastname
							});
							db.insert("users", {
								username: res.username.toLowerCase(),
								mail: res.mail,
								pass: util.passHash(res.mail, res.pass1)
							});
							ws.send(JSON.stringify({
								act: "info",
								end: "true",
								message: "Yeah ! Welcome to Choose !"
							}));
							return (true);
						}
						else {
							ws.send(JSON.stringify({
								act: "info",
								end: "false",
								message: "Email not valid."
							}));
							return (false);
						}
					}
				}, {
					$or: [
						{ username: res.username.toLowerCase() },
						{ mail: res.mail }
					]
				});
			}
		} catch (e) {
			console.log('Error try ws : ' + e);
		}
		console.log('received: %s', res.act);
	});

	ws.send('something');
});

// Set
app.set('view engine', 'pug');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));

// Routes
app.get('/home', function (req, res) {
	if (session.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		db.sortl("profiles", 3, {
			score: -1,
			firstname: 1
		}, function(json) {
			var users = json;
			res.render('./layouts/home', {
				name: c.site.name,
				author: c.site.author,
				ajax: ajax,
				nav: true,
				page: 'Home',
				users: users
			});
	    });
	}
	else
		res.redirect('/login');
});
app.get('/profiles', function (req, res) {
	if (session.username) {
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
				users: users
			});
	    }, {});
	}
	else
		res.redirect('/login');
});

// Login
app.get('/login', function (req, res) {
	if (!session.username) {
		var ajax = (req.query.ajax === '') ? true : false;
		res.render('./layouts/login', {
			name: c.site.name,
			author: c.site.author,
			ajax: ajax,
			page: 'Login'
		});
	}
	else
		res.redirect('/home');
});
app.get('/logout', function (req, res) {
	session.username = false;
	session.mail = false;
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
			users: users
		});
    });
});

// Server
server.on('request', app);
server.listen(port, function () {
	console.log('Start at ' + server.address().port);
});
