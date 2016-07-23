// Config
var c = require('../config.json');
var port = 3001;
var store;

// Modules
var validator = require('validator');
var emo = require('emojione');
var favicon = require('serve-favicon');
var url = require('url');
var express = require('express');
var session = require('express-session');
var MongoStore = require('connect-mongo')(session);
var app = express();

// Controllers
var db = require('./controllers/database.js');
var server = require('./controllers/server.js');
var util = require('./controllers/utils.js');
var ws = require('./controllers/ws.js');

// API
var index = require('./routes/index.js');
var auth = require('./routes/auth.js');
var api = require('./api/api.js');

db.connect(function(database) {
	store = new MongoStore({ db: database });

	// Websockets
	ws.start(store);
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
	// Auth
	app.use('/auth', auth);
	// Api
	app.use('/api', api);
	// 404
	app.use(function(req, res, next) {
		res.status(404).render('./404');
	});
});

// Server
server.getServer().on('request', app);
server.getServer().listen(port, function () {
	console.log('Start at ' + server.getServer().address().port);
});
