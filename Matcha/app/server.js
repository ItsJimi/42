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
var app = express();

// Controllers
var db = require('./controllers/database.js');

// Global var

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
				}, function(json) {
					console.log(json);
			    }, {
					firstname: res.name
				});
			}
		} catch (e) {

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
app.get('/', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	res.render('./layouts/login', {
		name: c.site.name,
		author: c.site.author,
		ajax: ajax,
		page: 'Login'
	});
});
app.get('/home', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	db.sortl("users", 3, {
		score: -1,
		firstname: 1
	}, function(json) {
		var users = json;
		res.render('./layouts/home', {
			name: c.site.name,
			author: c.site.author,
			ajax: ajax,
			page: 'Home',
			users: users
		});
    });
});
app.get('/profiles', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	db.sort("users", {
		score: -1,
		name: 1
	}, function(json) {
		var users = json;
		res.render('./layouts/profiles', {
			name: c.site.name,
			author: c.site.author,
			ajax: ajax,
			page: 'Profiles',
			users: users
		});
    }, {});
});
app.get('/about', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	res.render('./layouts/about', {
		name: c.site.name,
		author: c.site.author,
		ajax: ajax,
		page: 'About'
	});
});
app.get('/contact', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	res.render('./layouts/contact', {
		name: c.site.name,
		author: c.site.author,
		ajax: ajax,
		page: 'Contact'
	});
});

app.use(function(req, res, next) {
	var ajax = (req.query.ajax === '') ? true : false;
	db.sortl("users", 3, {
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
