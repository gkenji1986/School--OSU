<?php
//if it is to add a move to the list
	if(isset($_POST['addMoveList']))
	{
		//set up server information
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
		//set all post information
		$move_name = $_POST['name'];
		$basedmg = $_POST['baseDamage'];
		$power_p = $_POST['pp'];

		$desc = $_POST['moveDesc'];
		$type = $_POST['moveType'];
		//set up sql connection
		$mysql = new mysqli($servername, $username, $password, $dbname);
		//sql SELECT statement												
		$stmt = $mysql->prepare('SELECT type_id FROM types WHERE type_name = (?)');
		//bind it, then execute it
		$stmt->bind_param('s', $type);
		$stmt->execute();
		$stmt->bind_result($move_Type);
		$results = $stmt->fetch();
		
		$mysql2 = new mysqli($servername, $username, $password, $dbname);	
		$stmt = $mysql2->prepare('INSERT INTO moves (move_name, move_type, move_base_damage, move_pp, description) VALUES (?, ?, ?, ?, ?)');
		$stmt->bind_param('sssss', $move_name, $move_Type, $basedmg, $power_p, $desc);
		
		$stmt->execute();

		$stmt->close();
		//close the connection
		$mysql->close();
	}
//if the post is to add a pokemon move	
	if(isset($_POST['addPokeMove']))
	{
		//set up server information
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
		// Create connection 
		//set up post information
		$name = $_POST['pokeName'];
		$move = $_POST['pokeMove'];
		
		$mysql = new mysqli($servername, $username, $password, $dbname);												
		$stmt = $mysql->prepare('SELECT pokemon_id FROM pokemon WHERE name = (?)');
		$stmt->bind_param('s', $name);
		$stmt->execute();
		$stmt->bind_result($p_name);
		$results = $stmt->fetch();
		//set up sql with server information
		$mysql2 = new mysqli($servername, $username, $password, $dbname);	
		//get ready to send out the SELECT statement, based on values provided by the php page													
		$stmt = $mysql2->prepare('SELECT move_id FROM moves WHERE move_name = (?)');
		$stmt->bind_param('s', $move);
		$stmt->execute();
		$stmt->bind_result($p_move);
		$results = $stmt->fetch();
		//set up sql with server information
		$mysql3 = new mysqli($servername, $username, $password, $dbname);	
		//get ready to send out the INSERT statement, based on values provided by the php page		
		$stmt = $mysql3->prepare('INSERT INTO pokemon_moves (pid, mid) VALUES (?, ?)');
		$stmt->bind_param('ss', $p_name, $p_move);
		$stmt->execute();
		$stmt->close();
		
		$mysql->close();
	}
//if the post is to update a move information		
	if(isset($_POST['updateMove']))
	{
		//set up server information
		$servername = "oniddb.cws.oregonstate.edu";
		$username = "nakashig-db";
		$password = "xXiNAmO8UFsRQc9d";
		$dbname = "nakashig-db";
			// Create connection
		//set up all post information
		$move = $_POST['moveName'];
		$damage = $_POST['updateDmg'];
		$pp = $_POST['updatePp'];
			//set up sql with server information
		$mysql = new mysqli($servername,$username, $password, $dbname);	
		//get ready to send out the UPDATE statement, based on values provided by the php page											
		$stmt = $mysql->prepare('UPDATE moves SET move_base_damage = (?), move_pp = (?) WHERE move_name = (?)');
		$stmt->bind_param('sss', $damage, $pp, $move);
		$stmt->execute();	
		//close			
		$mysql->close();
	}
	

	header("Location:insert_move.php");
    exit();
?>
