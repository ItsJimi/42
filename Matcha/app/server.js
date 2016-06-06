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

});

// Set
app.set('view engine', 'pug');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));

// Routes
app.get('/', function (req, res) {
	db.getUsers(function(json) {
		var users = json;
		res.render('home', {
			name: c.site.name,
			author: c.site.author,
			title: 'Home',
			users: users
		});
    });
});
app.get('/home', function (req, res) {
	var ajax = (req.query.type === "ajax");
	console.log(ajax);
	res.render('home', { title: 'Home', ajax: ajax });
});
app.get('/test', function (req, res) {
	var ajax = (req.query.type === "ajax");
	console.log(ajax);
	res.render('test', { title: 'Home', ajax: ajax });
});

// Server
server.on('request', app);
app.listen(3001, function() {
	console.log('Start at 3001');
});
