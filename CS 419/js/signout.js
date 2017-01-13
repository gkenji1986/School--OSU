var signout = {
	get: function(req, res, next) {
		req.session.id = null;
		res.redirect('/');
	}
}

module.exports = signout;