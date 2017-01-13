var express = require('express');
var router = express.Router();
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

var User = require('../models/users.js');

router.get('/', function(req, res) {
	res.type('text/html');
	res.status(200);
	var context = {};
	res.render('register', context);
});

router.post('/', function(req, res) {
	var email = req.body.email;
	var password = req.body.password;
	var confirm = req.body.passwordConfirm;
	var display = req.body.display;

	// validation
	req.checkBody('email', 'Email is required').notEmpty();
	req.checkBody('email', 'Email is required').isEmail();
	req.checkBody('display', 'Display Name is required').notEmpty();
	req.checkBody('password', 'Password is required').notEmpty();
	req.checkBody('passwordConfirm', 'Confirmation password is required').notEmpty();
	req.checkBody('passwordConfirm', 'Passwords do no match').equals(req.body.password);

	var errors = req.validationErrors();

	if(errors) {
		res.render('register', {errors: errors});
	} else {
		var newUser = new User({
			display: display,
			email: email,
			password: password
		});

		User.createUser(newUser, function(err, user) {
			console.log(err);
			if(err) {
				req.flash('error_msg', 'There was an error with the database.');
				res.redirect('/register');
			} else {
				req.flash('success_msg', 'You have been registered successfully, you may now log in!');
				res.redirect('/login');
			}
		});
	}
});

module.exports = router;