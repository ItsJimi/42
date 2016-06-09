// Config
var c = require('../config.json');

// Modules
var server = require('http').createServer();
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ server: server });

var favicon = require('serve-favicon');
var express = require('express');
var app = express();

// Controllers
var db = require('./controllers/database.js');

// Global var

db.connect(function(database) {
	// ???
});

// WS
wss.on('connection', function(ws) {
	console.log(ws);
	ws.on('message', function(data) {
		try {
			var res = JSON.parse(data);

			if (res.act === "search") {
				db.sort("users", {
					name: 1,
					score: -1
				}, function(json) {
					console.log(json);
				}, {
					name: res.message
				});
			}
		}
		catch (e) {
			console.log("Error : " + e);
		}
	});
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
app.listen(3001, function() {
	console.log('Start at 3001');
});
