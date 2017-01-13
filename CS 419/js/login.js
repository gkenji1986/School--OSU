var mysql = require('mysql');
var pool = require('./rtsdb.js');

var login = {
	get: function(req, res, next) {
		res.type('text/html');
		res.status(200);
		var context = {};
		res.render('login', context);
	},
	post: function(req, res, next) {
		var verify = function(err, results) {	
			res.type('text/html');
			res.status(200);
			var context = {};
			if(err) {
				console.log(err.message);
			}
			if(results.length == 0) {
				context.loginValid = false;
				context.isError = true;
				context.message = "Unable to verify credentials.";
			} else {
				context.loginValid = true;
				context.isError = false;
				req.session.id = results[0].users_id;
				context.message = "Successfully logged in.";
			}
			res.render('login', context);
		};
		var data = req.body;
		pool.query("SELECT users_id, users_email, users_displayName FROM users WHERE users_email = ? AND users_password = ?", [data.email, data.password], verify);
	}
};

module.exports = login;