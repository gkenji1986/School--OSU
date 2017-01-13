var mysql = require('mysql');
var pool = require('./rtsdb.js');
var sessionCheck = require('./sessionCheck.js');

var home = {
	get: function(req, res, next) {
		var loggedIn = function(results) {	
			var context = {};
			console.log(results);
			context.loggedIn = true;
			context.user = results[0].users_email;
			res.render('home', context);
		};

		var loggedOut = function() {
			var context = {};
			context.loggedIn = false;
			res.render('home', context);
		};

		res.type('text/html');
		res.status(200);

		sessionCheck.sessionVerify(req.session.id, loggedIn, loggedOut);
	}
};

module.exports = home;