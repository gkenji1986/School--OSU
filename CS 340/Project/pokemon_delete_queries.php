<?php
//if the post is to delete a pokemon
	if(isset($_POST['deletePokemon']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$p_name = $_POST['pokemon'];
		//get ready to send out the DELETE statement, based on values provided by the php page			
		$mysql = new mysqli($servername,$username, $password, $dbname);												
		$stmt = $mysql->prepare('DELETE FROM pokemon WHERE name=?');
		$stmt->bind_param('s', $p_name);
		$stmt->execute();
		$stmt->close();
		$mysql->close();
	}
	//if the post is to delete a type
	if(isset($_POST['deleteType']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$p_type = $_POST['type'];
		//get ready to send out the DELETE statement, based on values provided by the php page		
		$mysql = new mysqli($servername,$username, $password, $dbname);												
		$stmt = $mysql->prepare('DELETE FROM types WHERE type_name=?');
		$stmt->bind_param('s', $p_type);
		$stmt->execute();
		$stmt->close();
		$mysql->close();
	}
	//if the post is to delete a move
	if(isset($_POST['deleteMove']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$p_move = $_POST['move'];
			//get ready to send out the DELETE statement, based on values provided by the php page		
		$mysql = new mysqli($servername,$username, $password, $dbname);												
		$stmt = $mysql->prepare('DELETE FROM moves WHERE move_name=?');
		$stmt->bind_param('s', $p_move);
		$stmt->execute();
		$stmt->close();
		$mysql->close();
	}
	//if the post is to delete a route
	if(isset($_POST['deleteRoute']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$p_route = $_POST['route'];
			//get ready to send out the DELETE statement, based on values provided by the php page		
		$mysql = new mysqli($servername,$username, $password, $dbname);												
		$stmt = $mysql->prepare('DELETE FROM routes WHERE route_name=?');
		$stmt->bind_param('s', $p_route);
		$stmt->execute();
		$stmt->close();
		$mysql->close();
	}
	//if the post is to delete a trainer
	if(isset($_POST['deleteTrainer']))
	{
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all the POST information
		$p_trainer = $_POST['trainer'];
			//get ready to send out the DELETE statement, based on values provided by the php page		
		$mysql = new mysqli($servername,$username, $password, $dbname);												
		$stmt = $mysql->prepare('DELETE FROM trainer WHERE trainer_name=?');
		$stmt->bind_param('s', $p_trainer);
		$stmt->execute();
		$stmt->close();
		$mysql->close();
	}
	
	header("Location:deletion.php");
    exit();
?>