<?php
//if the post is to add a trainer
	if(isset($_POST['addTrainer']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$name = $_POST['trainer_name'];
		$desc = $_POST['trainer_desc'];
		//set up sql with server information	
		$mysql = new mysqli($servername,$username, $password, $dbname);	
		//get ready to send out the INSERT statement, based on values provided by the php page									
		$stmt = $mysql->prepare('INSERT INTO trainer (trainer_name, description) VALUES (?, ?)');
		$stmt->bind_param('ss', $name, $desc);
		$stmt->execute();				
		$mysql->close();
	}
	//if the post is to add a trainer type	
	if(isset($_POST['addTrainerType']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
		// Create connection
		//set up all the POST information
		$name = $_POST['trainerName'];
		$type = $_POST['trainerType'];
		
		$mysql = new mysqli($servername, $username, $password, $dbname);	
		//get ready to send out the SELECT statement, based on values provided by the php page													
		$stmt = $mysql->prepare('SELECT trainer_id FROM trainer WHERE trainer_name = (?)');
		$stmt->bind_param('s', $name);
		$stmt->execute();
		$stmt->bind_result($t_name);
		$results = $stmt->fetch();
		//set up sql with server information
		$mysql2 = new mysqli($servername, $username, $password, $dbname);	
		//get ready to send out the SELECT statement, based on values provided by the php page												
		$stmt = $mysql2->prepare('SELECT type_id FROM types WHERE type_name = (?)');
		$stmt->bind_param('s', $type);
		$stmt->execute();
		$stmt->bind_result($t_type);
		$results = $stmt->fetch();
		//set up sql with server information
		$mysql3 = new mysqli($servername, $username, $password, $dbname);
		//get ready to send out the INSERT statement, based on values provided by the php page			
		$stmt = $mysql3->prepare('INSERT INTO trainer_pokemon (trainer_pokemon_id, trainer_pokemon_type_id) VALUES (?, ?)');
		$stmt->bind_param('ss', $t_name, $t_type);
		$stmt->execute();
		$stmt->close();
		
		$mysql->close();
	}
	
	header("Location:insert_trainer.php");
    exit();
?>