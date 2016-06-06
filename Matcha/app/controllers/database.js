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
	insert : function() {

	},
	getUsers: function(cb) {
	    // Get the documents collection
	    var collection = database.collection('users');
	    // Find some documents
	    collection.find({}).toArray(function(err, docs) {
			if (err)
				throw err;
			console.log(docs);
	        cb(docs);
	    });
	}
};
