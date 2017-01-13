var express = require('express');
var Handlebars = require('handlebars');
var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'main'});
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());

app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3000);

app.get('/',function(req,res){
  var queryParameters = [];
  
  var len = Object.keys(req.query).length;  // get length of object
  
  for (var i = 0; i < len; i++)		//loop through object
  {
	var queryName = Object.keys(req.query)[i];// get first key in key in first element http://stackoverflow.com/questions/26292267/how-do-i-check-if-query-string-has-values-in-express-js-node-js
	
	queryParameters.push({'val1':queryName,'val2':req.query[queryName]}); //add to query paramater object
  }
  var context = {reqType: "GET"};		//mark request type as get
  context.dataList = queryParameters;		
  req.isGET = true;							//mark isGet as true
  res.render('data', context);
});

app.post('/', function(req,res){
  var queryParameters = [];
  var len = Object.keys(req.body).length;
  
  for (var i = 0; i < len; i++)
  {
	var queryName = Object.keys(req.body)[i];
	
	queryParameters.push({'val1':queryName,'val2':req.body[queryName]}); 
  }
  
  for (var p in req.query)		//loop through object
  {
	queryParameters.push({'val1':p,'val2':req.query[p]}); 
  }
  var context = {reqType: "POST"};
  context.dataList = queryParameters;
  req.isGET = false;
  res.render('data', context);
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.type('plain/text');
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});

//http://handlebarsjs.com/block_helpers.html 
Handlebars.registerHelper("isGET", function(v1,options) {
  if(v1 === 'true') {
    return options.fn(this);
  }
  return options.inverse(this);
});
