var express = require('express');
var router = express.Router();
var User = require('../models/users.js');

router.get('/', ensureAuthenticated, function (req, res) {

    var user = req.body.user;

    User.getUserById(user, function (err, results) {
        if(err) {
            throw err;
        } else {
            if(!results) {
                res.render('profile');
            } else {

                res.render('profile', results);
            }
        }
    })
});

function ensureAuthenticated(req, res, next) {
    if (req.isAuthenticated())
    {
        return next();
    }
    else
    {
        res.send({ error: 'Not Authenticated.' });
    }
}

module.exports = router;