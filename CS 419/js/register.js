var mysql = require('mysql');
var db = require('./rtsdb.js');

var register = {
	get: function(req, res, next) {
		res.type('text/html');
		res.status(200);
		var context = {};
		context.confirm = {check: false};

		res.render('register', context);
	},
	post: function(req, res, next) {
		var display = function(err, data) {
			res.type('text/html');
			res.status(200);
			var context = {};
			try {
				if(err) {
					throw err;
				} else {
					context.confirm = { check: true, message: "User registered successfully"};
				}
				res.render('register', context);
			} catch(e) {
				context.confirm = { check: false, error: true, message: "An error occured registering the user."}
				res.render('register', context);
			}
		};
		var data = req.body;
		db.query("INSERT INTO users (users_email, users_password, users_displayName) VALUES(?, ?, ?)", [data.email, data.password, data.display], display);
	}
};

module.exports = register;