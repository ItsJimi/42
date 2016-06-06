var MongoClient = require('mongodb').MongoClient;
var c = require('../../config.json');
var database, callback;

MongoClient.connect('mongodb://' + c.db.user + ':' + c.db.password + '@' + c.db.host + ':' + c.db.port + '/' + c.db.database, function(err, db) {
	if (err)
		throw err;
	database = db;
	if (callback)
		callback(database);
});

module.export = {
	connect : function(cb) {
		if (database)
			cb(database);
		else
			callback = cb;
	}
};
