var express = require('express');
var router = express.Router();
var User = require('../models/users.js');
var Highscore = require('../models/highscores.js');

router.get('/', ensureAuthenticated, function (req, res) {
    Highscore.getAllScores(function(err, results) {
        if(err) {
            throw err;
        } else {
            if(!results) {
                res.render('highscores');
            } else {
                var high_low = results.reverse();
                res.render('highscores', { scores: high_low });
            }
        }
    })
});

router.post('/', ensureAuthenticated, function (req, res) {
    console.log(req.body);
    var score = req.body.score;
    var user = req.body.by;

    if (user != req.user.email)
    {
        res.send({ error: 'Invalid user' });
    } 
    else if (score < 0)
    {
        res.send({ error: 'Invalid score' });
    }
    else
    {
       var newHighscore = new Highscore({
            score: score,
            by: req.user._id
        });
       console.log("adding high score");

        Highscore.addHighscore(newHighscore, function (err, details) {
            if (err) throw err;
            console.log(details);
            res.send({ error: false });
        });
    }
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