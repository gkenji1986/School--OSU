var mongoose = require('mongoose');
var bcrypt = require('bcryptjs');

// User Schema
var UserSchema = mongoose.Schema({
	display: {
		type: String,
		index: true,
		unique: true
	},
	email: {
		type: String,
		index: true,
		unique: true
	},
	password: {
		type: String,
		index: false
	},
	joinDate: {
		type: Date,
		default: Date.now
	}
});

var User = module.exports = mongoose.model('User', UserSchema);

module.exports.createUser = function(newUser, callback) {
	bcrypt.genSalt(10, function(err, salt) {
	    bcrypt.hash(newUser.password, salt, function(err, hash) {
	        newUser.password = hash;
	        newUser.save(callback);
	    });
	});
}

module.exports.deleteUser = function(id, callback) {
	User.remove({_id: id}, callback);
}

module.exports.getUserById = function(id, callback) {
	User.findById(id, callback);
}

module.exports.getUserByUsername = function(username, callback) {
	User.findOne({email: username}, callback);
}

module.exports.getUserHash = function(username, callback) {
	User.findOne({email: username}).select('password').exec(callback);
}

module.exports.getAllUsers = function(callback) {
	User.find({}, callback);
}

module.exports.comparePassword = function(candidatePassword, hash, callback) {
	console.log(candidatePassword);
	console.log(hash)
	bcrypt.compare(candidatePassword, hash, function(err, isMatch) {
    	if(err) throw err;
    	callback(null, isMatch);
	});
}