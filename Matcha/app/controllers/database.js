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
	update: function(name, obj1, obj2, cb) {
        // Get the documents collection
        var collection = db.collection(name);
        collection.updateOne(obj1, obj2, function(err, docs) {
            if (err)
                throw err;
            if (cb)
                cb(docs);
        });
    },
	get : function(name, cb, obj) {
	    // Get the documents collection
	    var collection = database.collection(name);
	    // Find some documents
	    collection.find(obj).toArray(function(err, docs) {
			if (err)
				throw err;
	        cb(docs);
	    });
	},
	limit : function(name, nbr, cb, obj) {
	    // Get the documents collection
	    var collection = database.collection(name);
	    // Find some documents
	    collection.find(obj).limit(nbr).toArray(function(err, docs) {
			if (err)
				throw err;
	        cb(docs);
	    });
	},
	sort : function(name, obj1, cb, obj2) {
	    // Get the documents collection
	    var collection = database.collection(name);
	    // Find some documents
	    collection.find(obj2).sort(obj1).toArray(function(err, docs) {
			if (err)
				throw err;
	        cb(docs);
	    });
	},
	sortl : function(name, nbr, obj1, cb, obj2) {
	    // Get the documents collection
	    var collection = database.collection(name);
	    // Find some documents
	    collection.find(obj2).sort(obj1).limit(nbr).toArray(function(err, docs) {
			if (err)
				throw err;
	        cb(docs);
	    });
	}
};
