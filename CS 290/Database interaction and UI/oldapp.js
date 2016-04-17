var express = require('express');
var mysql = require('./database.js');

var app = express();
var handlebars = require('express-handlebars').create({defaultLayout:'oldmain'});
var bodyParser = require('body-parser');

app.use(bodyParser.json());  
app.engine('handlebars', handlebars.engine);
app.set('view engine', 'handlebars');
app.set('port', 3333);


app.get('/',function(req,res,next){
  
  var context = {};
	mysql.pool.query('SELECT * FROM workouts',function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
    var temp = [];
	
	for(var i = 0; i < rows.length; i++)
	{
		val correctLBS = checkBool(rows[i].lbs});
		temp.push({"id":rows[i].id, "name": rows[i].name, "reps": rows[i].reps,"weight": rows[i].weight,"date": rows[i].date,"lbs": correctLBS});
	}
	
    context.results = temp;
    res.render('oldhome', context);
  });
});

function Refresh(req,res,next)
{
  var context = {};
  mysql.pool.query('SELECT * FROM workouts', function(err, rows, fields){
    if(err){
      next(err);
      return;
    }
	var temp = [];
	
	for(var i = 0; i < rows.length; i++)
	{
		val correctLBS = checkBool(rows[i].lbs});
		temp.push({"id":rows[i].id, "name": rows[i].name, "reps": rows[i].reps,"weight": rows[i].weight,"date": rows[i].date,"lbs": rows[i].lbs});
	}
	
    context.results = temp;
    res.render('oldhome', context);
  });
}

app.get('/insert',function(req,res,next){
  var context = {};
  
	  if(req.query.name != '')
	  {
			  mysql.pool.query("INSERT INTO workouts (`name`,`reps`,`weight`,`date`,`lbs`) VALUES (?,?,?,?,?)",  
							[req.query.name, req.query.reps, req.query.weight, req.query.date, checkBool(req.query.lbs)], function(err, result){
						Refresh(req,res,next);
					});
	  }
	  else
	  {
  
		Refresh(req,res,next);
		
	  }
 });

function checkBool(weight)
{
	if(weight > 1)
	{
		weight = '0';
		return weight;
	}
	else if(weight < 0)
	{
		weight = '0';
		return weight;
	}
	else
	{
			return weight;
	}
}

app.get('/update',function(req,res,next){
  var context = {};
	
	  if(req.query.name != '')
	  {
		  mysql.pool.query("SELECT * FROM workouts WHERE id=?", [req.query.id], function(err, result){
				if(err){
				  next(err);
				  return;
				}
				
				if(result.length == 1){
				  var curVals = result[0];
				  var newLBS = checkBool(req.query.lbs);
				  
				  mysql.pool.query("UPDATE workouts SET name=?, reps=?, weight=?, date=?, lbs=? WHERE id=?",
					[req.query.name || curVals.name, req.query.reps || curVals.reps, req.query.weight || curVals.weight, req.query.date || curVals.date, newLBS || curVals.lbs, req.query.id],
					function(err, result){
					if(err){
					  next(err);
					  return;
					}
					Refresh(req,res,next);
				  });
				}
			  });
	  }
	  else
	  {
		   Refresh(req,res,next);
	  }
});

 app.get('/delete',function(req,res,next){
  var context = {};
  var num = req.query.id;
  mysql.pool.query("DELETE FROM workouts WHERE id=?", [num], function(err, result){
    if(err){
      next(err);
      return;
    }
		Refresh(req,res,next);
	});	
});

app.get('/reset-table',function(req,res,next){
  var context = {};
  mysql.pool.query("DROP TABLE IF EXISTS workouts", function(err){ 
    var createString = "CREATE TABLE workouts("+
    "id INT PRIMARY KEY AUTO_INCREMENT,"+
    "name VARCHAR(255) NOT NULL,"+
    "reps INT,"+
    "weight INT,"+
    "date DATE,"+
    "lbs BOOLEAN)";
      mysql.pool.query(createString, function(err){
      context.results = "Table reset";
      res.render('home',context);
    })
  });
});

app.use(function(req,res){
  res.status(404);
  res.render('404');
});

app.use(function(err, req, res, next){
  console.error(err.stack);
  res.status(500);
  res.render('500');
});

app.listen(app.get('port'), function(){
  console.log('Express started on http://localhost:' + app.get('port') + '; press Ctrl-C to terminate.');
});