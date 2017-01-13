var mongoose = require('mongoose');
var ObjectId = mongoose.Schema.ObjectId;

// High Score Schema
var HighscoreSchema = mongoose.Schema({
	score: {
		type: Number,
		index: false,
		unique: false
	},
	by: {
		unique: false,
		index: false,
		type: ObjectId,
		ref: 'User'
	}
});

var Highscore = module.exports = mongoose.model('Highscore', HighscoreSchema);

module.exports.addHighscore = function(newHighscore, callback) {
	 newHighscore.save(callback);
}

module.exports.getAllScores = function(callback) {
	Highscore.find().sort('score').populate('by').exec(callback);
}