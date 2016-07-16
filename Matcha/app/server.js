// Config
var c = require('../config.json');
var port = 3001;
var store;

// Modules
var validator = require('validator');
var emo = require('emojione');
var favicon = require('serve-favicon');
var server = require('http').createServer();
var url = require('url');
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ server: server });
var express = require('express');
var session = require('express-session');
var MongoStore = require('connect-mongo')(session);
var app = express();

// Controllers
var db = require('./controllers/database.js');
var util = require('./controllers/utils.js');

// Routes
var index = require('./routes/index.js');
var profiles = require('./routes/profiles.js');
var cdn = require('./routes/cdn.js');
var login = require('./routes/login.js');
var api = require('./routes/api.js');

db.connect(function(database) {
	store = new MongoStore({ db: database });

	// Session
	app.use(session({ secret : 'MpCF12y', resave: false, saveUninitialized: true, store: store }));

	// Set
	app.set('view engine', 'ejs');
	app.set('views', './app/views');

	// Use
	app.use(express.static('./app/public'));
	app.use(favicon('./app/public/img/img1.jpg'));
	app.use(require('body-parser').urlencoded({ extended: true, limit: '50mb' }));

	// Index
	app.use('/', index);
	// Cdn
	app.use('/cdn', cdn);
	// Auth
	app.use('/login', login);
	// Api
	app.use('/api', api);
	// 404
	app.use(function(req, res, next) {
		res.status(404).render('./404');
	});
});

// Web Socket
wss.on('connection', function connection(ws) {
	if (ws.upgradeReq.headers.cookie) {
		var sessId = ws.upgradeReq.headers.cookie.split("s%3A")[1].split(".")[0];
		store.get(sessId, function(err, sess) {

			ws.username = sess.username;
			ws.setSession = function(session) {
				store.set(ws.upgradeReq.headers.cookie.split("s%3A")[1].split(".")[0], session);
			}
		});
	}

	ws.on('message', function incoming(message) {
		try {
    		var res = JSON.parse(message);
			if (res.act === "message") {
				if (res.message && res.to && res.to != ws.username) {
					util.getUser(wss, res.to).forEach(function(user) {
						console.log(user.username);
						util.sendData(user, {
							act: "message",
							role: "receiver",
							message: emo.toImage(validator.escape(res.message))
						});
					});
					util.getUser(wss, ws.username).forEach(function(user) {
						console.log(user.username);
						util.sendData(user, {
							act: "message",
							role: "sender",
							message: emo.toImage(validator.escape(res.message))
						});
					});
				}
			}
		} catch (e) {
			console.log('Error try ws : ' + e);
		}
		console.log('received: %s', message);
	});
});

// Server
server.on('request', app);
server.listen(port, function () {
	console.log('Start at ' + server.address().port);
});
