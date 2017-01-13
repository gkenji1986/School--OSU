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
				<text>Enter id, name, and description to add a pokemon</text>
	 	<!-- setting up post method from form-->
				<form action='pokemon_insert_queries.php' method='POST'>
					<p>
						 <!-- lables for inputs-->
						<label for="poke_id">Id:</label>
						<input type="number" name="value1" min="1" max= "151"/>
					</p>
					<p>
						 <!-- lables for inputs-->
						<label for="poke_id">Name:</label>
						<input type="text" name="value2"/>
					</p>
					<p>
						 <!-- lables for inputs-->
						<label for="poke_id">Description:</label>
						<input type="text" name="value3"/>
					</p>
					<input name="addPokemon" type="submit" class="btn-primary" value="Submit"/>
				</form>
			</div>
        </fieldset>
		<br>
		<fieldset>
			<div id="insert_poke">		   
				<text>Select a name and type for the Pokemon</text>
					<!-- setting up post method from form-->
					<form action='pokemon_insert_queries.php' method='POST'>
						<select id = "namePoke" name = "namePoke">
							<label for="namePoke">Name:</label>
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
						<select id = "typePoke" name = "typePoke">
							<label for="typePoke">Type:</label>
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
						<input name="addPokemonType" type="submit" class="btn-primary" value="Submit"/>
					</form>
			</div>
        </fieldset>
		<br>
		<fieldset>
			<div id="insert_poke">		   
				<text>Input a Pokemon's predecessor and evolution. </text><br>
					<br>
						<!-- setting up post method from form-->
						<form action='pokemon_insert_queries.php' method='POST'>
							<text>Predecessor</text>
								<select id = "predPoke" name = "predPoke">
									<?php
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
										//set up SELECt statement
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
							<text>Evolution</text>
								<select id = "evoPoke" name = "evoPoke">
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
										while ($row = $result->fetch_assoc()) 
										{
											unset($name);
											$name = $row['name']; 
											echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="evolutionPokemon" type="submit" class="btn-primary" value="Submit"/>
						</form>
			</div>
		</fieldset>
		<br>
		<fieldset>
			<div id="addType">
				<text>Type in a new type</text>
				<form action='pokemon_insert_queries.php' method='POST'>
					<p>
						 <!-- lables for inputs-->
						<label for="poke_id">Type:</label>
						<input type="text" name="type"/>
					</p>
					<input name="addType" type="submit" class="btn-primary" value="Submit"/>
				</form>
			</div>
		</fieldset>
		<br>
		<fieldset>
			<div id="insert_poke">		   
				<text>Select a route where a Pokemon was spotted. </text><br>
					<br>
						<!-- setting up post method from form-->
						<form action='pokemon_insert_queries.php' method='POST'>
							<text>Pokemon</text>
								<select id = "pokeRoute" name = "pokeRoute">
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
							<text>Route/Location</text>
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
										//set up the select statement
										if ($mysql->connect_error) 
										{
										  die("Connection failed: " . $mysql->connect_error);
										} 
										$sql = "SELECT route_name FROM routes";
										$result = $mysql->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
											unset($name);
											$name = $row['route_name']; 
											echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$mysql->close();
									?>
								</select>
							<input name="routePoke" type="submit" class="btn-primary" value="Submit"/>
						</form>
			</div>
		</fieldset>
		<fieldset>
			<div id="addRoute">
				<text>Add a newly discovered route</text>
				<form action='pokemon_insert_queries.php' method='POST'>
					<p>
						 <!-- lables for inputs-->
						<label for="route">Route Name:</label>
						<input type="text" name="route_name"/>
					</p>
					<p>
						 <!-- lables for inputs-->
						<label for="route">Description:</label>
						<input type="text" name="route_description"/>
					</p>
					<input name="addRoute" type="submit" class="btn-primary" value="Submit"/>
				</form>
			</div>
		</fieldset>
	
    </body>
</html>
