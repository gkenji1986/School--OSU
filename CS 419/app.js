var express = require('express');
var body = require('body-parser');
var path = require('path');
var cors = require('cors');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var handlebars = require('express-handlebars');
var validator = require('express-validator');
var flash = require('connect-flash');
var session = require('express-session');
var MongoStore = require('connect-mongo')(session);


var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

var server = function (err) {
    if (err) throw err;

    var app = express();
    app.use(cors());
    
    var store = new MongoStore({
        url: "mongodb://santa:claus1234567890@ds011314.mlab.com:11314/santadefender"
    });
    // view engine
    app.set('views', path.join(__dirname, 'views'));
    app.engine('handlebars', handlebars({ defaultLayout: 'main' }));
    app.set('view engine', 'handlebars');

    var login = require('./routes/login');
    var register = require('./routes/registration');
    var signout = require('./routes/signout');
    var highscore = require('./routes/highscore');
    var home = require('./routes/home');
    var about = require('./routes/about');
    var profile = require('./routes/profile');

    // parse the encoded text
    app.use(body.json());
    app.use(body.urlencoded({ extended: false }));
    app.use(cookieParser());

    // static folder
    app.use(express.static(path.join(__dirname, 'public')));

    // express session
    app.use(session({
        secret: 'Santas Secret Keeper',
        store: store,
        saveUninitialized: true,
        resave: true
    }));

    // passport functionality
    app.use(passport.initialize());
    app.use(passport.session());

    // validator
    app.use(validator({
        errorFormatter: function (param, msg, value) {
            var namespace = param.split('.')
            , root = namespace.shift()
            , formParam = root;

            while (namespace.length) {
                formParam += '[' + namespace.shift() + ']';
            }
            return {
                param: formParam,
                msg: msg,
                value: value
            };
        }
    }));

    // flash messages
    app.use(flash());

    // global vars
    app.use(function (req, res, next) {
        res.locals.success_msg = req.flash('success_msg');
        res.locals.error_msg = req.flash('error_msg');
        res.locals.error = req.flash('error');
        res.locals.user = req.user || null;
        next();
    });

    // all item functions handle in the item route
    app.use('/', home);
    app.use('/highscore', highscore);
    app.use('/login', login);
    app.use('/register', register);
    app.use('/signout', signout);
    app.use('/about', about);
    app.use('/profile', profile);

    // start server
    app.set('port', (process.env.PORT || 8080));

    app.listen(app.get('port'), function () {
        console.log('Server started on port ' + app.get('port'));
    });
}

module.exports = server;