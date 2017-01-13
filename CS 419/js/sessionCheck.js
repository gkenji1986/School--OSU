var mysql = require('mysql');
var pool = require('./rtsdb.js');

var check = {
	sessionVerify: function(id, callbackSuccess, callbackFailure) {
		if(typeof id == "undefined") {
			return callbackFailure();
		} else {
			pool.query("SELECT users_id, users_email, users_displayName FROM users WHERE users_id = ?", [id], function(err, results) {
				if(err || results.length == 0) {
					return callbackFailure();
				} else {
					return callbackSuccess(results);
				}
			});
		}
	}
};

module.exports = check;