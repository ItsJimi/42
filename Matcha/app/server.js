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
	var ajax = (req.query.ajax === '') ? true : false;
	res.render('./layouts/home', {
		name: c.site.name,
		author: c.site.author,
		ajax: ajax,
		page: 'Home'
	});
});
app.get('/home', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	res.render('./layouts/home', {
		name: c.site.name,
		author: c.site.author,
		ajax: ajax,
		page: 'Home'
	});
});
app.get('/profiles', function (req, res) {
	var ajax = (req.query.ajax === '') ? true : false;
	db.get("users", function(json) {
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
	res.status(404).render('./layouts/404', {
		name: c.site.name,
		author: c.site.author,
		ajax: false,
		page: '404'
	});
});

// Server
server.on('request', app);
app.listen(3001, function() {
	console.log('Start at 3001');
});
