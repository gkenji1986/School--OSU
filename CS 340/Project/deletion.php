<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8"> 
        <title>CS 340 Final</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
            <!-- nav bar -->
<nav>
        <ul>
        <li><a href="main.php">Back to Main Page</a></li> 
          <li><a href="insert.php">Insert Pokemon and attributes for Pokemon into Pokedex</a></li>       
		  <li><a href="insert_move.php" class="selected">Insert Moves and attributes into Pokedex</a></li>
		  <li><a href="insert_trainer.php" class="selected">Insert Trainer and trainer's Pokemon into Pokedex</a></li>
		  <li><a href="deletion.php" class="selected">Delete Information from Pokedex</a></li>
        </ul>
 </nav>
        <h1>PokeDex</h1>
			<fieldset>
				<div id="insert_poke">
		   
					<text>Select a Pokemon to delete from the Pokedex</text>
					<!-- setting up post method from form-->
						<form action='pokemon_delete_queries.php' method='POST'>
									<select id = "pokemon" name = "pokemon">
									   <?php
									   //set up the server
											$servername = "oniddb.cws.oregonstate.edu";
											$username = "nakashig-db";
											$password = "xXiNAmO8UFsRQc9d";
											$dbname = "nakashig-db";
											// Create connection
											$mysql = new mysqli($servername, $username, $password, $dbname);
											// Check connection
											if ($mysql->connect_error) 
											{
											  die("Connection failed: " . $mysql->connect_error);
											} 
											//set up the select statement
											$sql = "SELECT name FROM pokemon";
											$result = $mysql->query($sql);
											//display the results
											while ($row = $result->fetch_assoc()) 
											{
											  unset($name);
											  $name = $row['name']; 
											  echo '<option value="'.$name.'">'.$name.'</option>';
											}
											$mysql->close();
										?>
									</select>
								<input name="deletePokemon" type="submit" class="btn-primary" value="Submit"/>
						</form>
				</div>
			</fieldset>
			<br>
			<fieldset>
				<div id="">
					<text>Select a Type to delete from the Pokedex</text>
					<!-- setting up post method from form-->
						<form action='pokemon_delete_queries.php' method='POST'>
								<select id = "type" name = "type">
									<?php
									//set up the server
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$mysql = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($mysql->connect_error) 
										{
										  die("Connection failed: " . $mysql->connect_error);
										} 
										//set up the select statement
										$sql = "SELECT type_name FROM types";
										$result = $mysql->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($type);
										  $type = $row['type_name']; 
										  echo '<option value="'.$type.'">'.$type.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="deleteType" type="submit" class="btn-primary" value="Submit"/>
						</form>
				</div>
			</fieldset>
			<br>
			<fieldset>
				<div id="">
					<text>Select a Move to delete from the Pokedex</text>
					<!-- setting up post method from form-->
						<form action='pokemon_delete_queries.php' method='POST'>
								<select id = "move" name = "move">
									<?php
									//set up the server information
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$mysql = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($mysql->connect_error) 
										{
										  die("Connection failed: " . $mysql->connect_error);
										} 
										//set up the select statement
										$sql = "SELECT move_name FROM moves";
										$result = $mysql->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($move);
										  $move = $row['move_name']; 
										  echo '<option value="'.$move.'">'.$move.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="deleteMove" type="submit" class="btn-primary" value="Submit"/>
						</form>
				</div>
			</fieldset>
			<fieldset>
				<div id="">
					<text>Select a Route to delete from the Pokedex</text>
					<!-- setting up post method from form-->
						<form action='pokemon_delete_queries.php' method='POST'>
								<select id = "route" name = "route">
									<?php
									//set up the server
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$mysql = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($mysql->connect_error) 
										{
										  die("Connection failed: " . $mysql->connect_error);
										} 
										//set up the select statement
										$sql = "SELECT route_name FROM routes";
										$result = $mysql->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($route);
										  $route = $row['route_name']; 
										  echo '<option value="'.$route.'">'.$route.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="deleteRoute" type="submit" class="btn-primary" value="Submit"/>
						</form>
				</div>
			</fieldset>
			<fieldset>
				<div id="">
					<text>Select a Trainer to delete from the Pokedex</text>
					<!-- setting up post method from form-->
						<form action='pokemon_delete_queries.php' method='POST'>
								<select id = "trainer" name = "trainer">
									<?php
										//set up the server
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$mysql = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($mysql->connect_error) 
										{
										  die("Connection failed: " . $mysql->connect_error);
										} 
										//set up the select statement
										$sql = "SELECT trainer_name FROM trainer";
										$result = $mysql->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($name);
										  $name = $row['trainer_name']; 
										  echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="deleteTrainer" type="submit"  class="btn-primary" value="Submit"/>
						</form>
				</div>
			</fieldset>
		
    </body>
</html>
