var express = require('express');
var router = express.Router();

router.get('/', ensureAuthenticated, function(req, res) {

	if(req.user) {
		res.render('home', {user: req.user, game: true});
	} else {
		res.render('home', {game: true});
	}
});

function ensureAuthenticated(req, res, next) {
	if(req.isAuthenticated()) {
		next();
	} else {
		next();
	}
}

module.exports = router;