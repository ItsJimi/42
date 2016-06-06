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

module.exports = {
	connect : function(cb) {
		if (database)
			cb(database);
		else
			callback = cb;
	},
	insert : function(name, obj) {
		var collection = database.collection(name);
		collection.insert(obj);
	},
	get : function(name, cb, obj) {
	    // Get the documents collection
	    var collection = database.collection(name);
	    // Find some documents
	    collection.find(obj).toArray(function(err, docs) {
			if (err)
				throw err;
			console.log(docs);
	        cb(docs);
	    });
	}
};
