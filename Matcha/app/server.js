// Config
var c = require('../config.json');

// Modules
var server = require('http').createServer();
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({
	server: server
});
var favicon = require('serve-favicon');
var express = require('express');
var app = express();

// Controllers
var db = require('./controllers/database.js');

// Global var

db.connect(function(database) {
	// ???
});

// Set
app.set('view engine', 'pug');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));

// Routes
app.get('/', function (req, res) {
	res.render('./layouts/home', {
		name: c.site.name,
		author: c.site.author,
		page: 'Home'
	});
});
app.get('/home', function (req, res) {
	res.render('./layouts/home', {
		name: c.site.name,
		author: c.site.author,
		page: 'Home'
	});
});
app.get('/profiles', function (req, res) {
	db.get("users", function(json) {
		var users = json;
		res.render('./layouts/profiles', {
			name: c.site.name,
			author: c.site.author,
			page: 'Profiles',
			users: users
		});
    }, {});
});
app.get('/about', function (req, res) {
	res.render('./layouts/about', {
		name: c.site.name,
		author: c.site.author,
		page: 'About'
	});
});
app.get('/contact', function (req, res) {
	res.render('./layouts/contact', {
		info: {
			name: c.site.name,
			author: c.site.author,
		},
		page: 'Contact'
	});
});

// Server
server.on('request', app);
app.listen(3001, function() {
	console.log('Start at 3001');
});
