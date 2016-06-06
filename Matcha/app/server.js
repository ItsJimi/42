// Config
var c = require('../config.json');

// Modules
var favicon = require('serve-favicon');
var express = require('express');
var app = express();

// Controllers
var db = require('./config/database.js');

console.log(db);

// Set
app.set('view engine', 'pug');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));

// Routes
app.get('/', function (req, res) {
	res.render('home', { name: c.site.name, author: c.site.author, title: 'Home' });
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
app.listen(3001, function() {
	console.log('Start at 3001');
});
