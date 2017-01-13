var mongodb = require('mongodb');
var mongoose = require('mongoose');
var appserver = require('./app.js');

mongoose.Promise = global.Promise;

mongoose.connect('mongodb://santa:claus1234567890@ds011314.mlab.com:11314/santadefender', appserver);