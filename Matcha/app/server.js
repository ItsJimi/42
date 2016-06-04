// Modules
var favicon = require('serve-favicon');
var express = require('express');
var app = express();

// Use
app.use(express.static(__dirname + '/public'));
app.use(favicon(__dirname + '/public/img/img1.jpg'));

// Routes
app.get('/', function(req, res) {
	res.send('Search !');
});

// Server
app.listen(3001, function() {
	console.log('Start at 3001');
});
