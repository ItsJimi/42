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

// Routes
var index = require('./routes/index.js');
var profiles = require('./routes/profiles.js');
var cdn = require('./routes/cdn.js');
var login = require('./routes/login.js');

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
app.set('view engine', 'ejs');
app.set('views', './app/views');

// Use
app.use(express.static('./app/public'));
app.use(favicon('./app/public/img/img1.jpg'));
app.use(bodyParser.json());

// Index
app.use('/', index);
// Profiles
app.use('/profiles', profiles);
// Cdn
app.use('/cdn', cdn);
// Auth
app.use('/login', login);
// 404
app.use(function(req, res, next) {
	res.status(404).render('./404');
});

// Server
server.on('request', app);
server.listen(port, function () {
	console.log('Start at ' + server.address().port);
});
