<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8"> 
        <title>CS 340 Final</title>
        <link rel="stylesheet" type="text/css" href="style.css">
    </head>
    <body>
        <!-- James' Changes -->
<nav>
        <ul>
          <li><a href="insert.php">Insert Pokemon and attributes for Pokemon into Pokedex</a></li>       
		  <li><a href="insert_move.php" class="selected">Insert Moves and attributes into Pokedex</a></li>
		  <li><a href="insert_trainer.php" class="selected">Insert Trainer and trainer's Pokemon into Pokedex</a></li>
		  <li><a href="deletion.php" class="selected">Delete Information from Pokedex</a></li>
        </ul>
 </nav>
   <!-- James' Changes -->
		<div>
        <h1>PokeDex</h1>
		</div>
			<div>
				<div class="mainpage">	   
					<text>Select a Pokemon name for information about the Pokemon.</text>
						<form action='main.php' method='POST'>
								<select id = "generalInfo" name = "generalInfo">
								   <?php
								   //set up server information
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$conn = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($conn->connect_error) 
										{
										  die("Connection failed: " . $conn->connect_error);
										} 
										$sql = "SELECT name FROM pokemon";
										$result = $conn->query($sql);
										//generate the table to show the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($name);
										  $name = $row['name']; 
										  echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$conn->close();
									?>
								</select>
							<input name="getPokeInfo" type="submit" class="btn-primary" value="Check PokeDex"/>
						</form>
				</div>
			</div>
			<div id="generalTable">
			   <!-- Set up the table -->
				<table class="table">
					<tr>
						<th>Pokemon ID</th>
						<th>Pokemon Name</th>
						<th>Pokemon Type</th>
						<th>Pokemon Description</th>
						<th>Moves</th>
						<th>Wild Pokemon Location</th>
						<th>Predecessor</th>
					</tr>
					<tr>
						<td>
							<?php
								if(isset($_POST['getPokeInfo']))
								{	
								//set up the server info						
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
										
									$name = $_POST['generalInfo'];
										
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the SELECT statement	
									$stmt = $mysql->prepare('SELECT pokemon_id FROM pokemon WHERE name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									$stmt->bind_result($pokemonID);
									$results = $stmt->fetch();
									echo $pokemonID;
									$stmt->close();
									
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
							//display the results
								echo $_POST['generalInfo'];
							?>
						</td>
						<td>
							<?php
							//if post for poke info, get ready to set the table up
								if(isset($_POST['getPokeInfo']))
								{							
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									
									$name = $_POST['generalInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the SELECT statement to show the table
									$stmt = $mysql->prepare('SELECT type_name FROM types 
											INNER JOIN pokemon_types ON types.type_id = pokemon_types.ptid
											INNER JOIN pokemon ON pokemon_types.pid = pokemon.pokemon_id
											WHERE pokemon.name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$type = "";
									$stmt->bind_result($type);
									//generate the entire table
									while($stmt->fetch())
									{
										echo $type."<br>";
									}
									$stmt->close();
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
							//if looking for pokemon information
								if(isset($_POST['getPokeInfo']))
								{	
								//set up the server						
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set name equal to the post of general info	
									$name = $_POST['generalInfo'];
										
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the SELECt statement	
									$stmt = $mysql->prepare('SELECT description FROM pokemon WHERE name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$stmt->bind_result($pokemonDesc);
									$results = $stmt->fetch();
									//return the pokemon description
									echo $pokemonDesc;
									$stmt->close();
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
							//if looking for pokemon information
								if(isset($_POST['getPokeInfo']))
								{							
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									
									$name = $_POST['generalInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									
									$stmt = $mysql->prepare('SELECT move_name FROM moves 
											INNER JOIN pokemon_moves ON moves.move_id = pokemon_moves.mid
											INNER JOIN pokemon ON pokemon_moves.pid = pokemon.pokemon_id
											WHERE pokemon.name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$moves = "";
									$stmt->bind_result($moves);
									while($stmt->fetch())
									{
										echo $moves. "<br>";
									}
									$stmt->close();
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
							//if looking for pokemon information
								if(isset($_POST['getPokeInfo']))
								{							
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									
									$name = $_POST['generalInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									
									$stmt = $mysql->prepare('SELECT route_name FROM routes
											INNER JOIN pokemon_routes ON routes.route_id = pokemon_routes.rid
											INNER JOIN pokemon ON pokemon_routes.pid = pokemon.pokemon_id
											WHERE pokemon.name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$routes = "";
									$stmt->bind_result($routes);
									while($stmt->fetch())
									{
										echo $routes. "<br>";
									}
									$stmt->close();
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
							//if looking for pokemon information
								if(isset($_POST['getPokeInfo']))
								{		
									//set up the server					
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set up the post information to send
									$name = $_POST['generalInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
									$stmt = $mysql->prepare('SELECT poke1.name FROM pokemon poke1 
											INNER JOIN pokemon_evolutions pe ON pe.pokemon_predecessor_id = poke1.pokemon_id
											INNER JOIN pokemon poke2 ON poke2.pokemon_id = pe.pokemon_evolution_id
											WHERE poke2.name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$evolution = "";
									$stmt->bind_result($evolution);
									//display the results
									while($stmt->fetch())
									{
										echo $evolution."<br>";
									}
									$stmt->close();
									$mysql->close();
								}
							?>
						</td>
					</tr>
				</table>
			</div>
			<hr>
			<div>
				<div class="mainpage">
					<form action="main.php" method="POST">
						<text>Select a move for information about the move.</text><br>
								<select id = "moveInfo" name = "moveInfo">
								   <?php
								   		//set up the server	
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										// Create connection
										$conn = new mysqli($servername, $username, $password, $dbname);
										// Check connection
										if ($conn->connect_error) 
										{
										  die("Connection failed: " . $conn->connect_error);
										} 
										$sql = "SELECT move_name FROM moves";
										$result = $conn->query($sql);
										//display the results
										while ($row = $result->fetch_assoc()) 
										{
										  unset($name);
										  $name = $row['move_name']; 
										  echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$conn->close();
									?>
								</select>
							<input name="getMoveInfo" type="submit" class="btn-primary" value="Check PokeDex"/>
					</form>
				</div>
			</div>
			<div id="moveTable">
				<table class="table">
					<tr>
						<th>Move Name</th>
						<th>Type</th>
						<th>Base Damage</th>
						<th>Power Points</th>
						<th>Description</th>
					</tr>
					<tr>
						<td>
							<?php
								if(isset($_POST['getMoveInfo']))
								{
									echo $_POST['moveInfo'];
								}
							?>
						</td>
						<td>
							<?php
								if(isset($_POST['getMoveInfo']))
								{	
									//set up the server							
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set name equal to post from move info
									$name = $_POST['moveInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
									$stmt = $mysql->prepare('SELECT type_name FROM types 
											INNER JOIN moves ON moves.move_type = types.type_id
											WHERE moves.move_name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									$stmt->bind_result($type);
									$result = $stmt->fetch();
									echo $type;
									$stmt->close();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
								if(isset($_POST['getMoveInfo']))
								{							
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set name equal to move info post information
									$name = $_POST['moveInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
									$stmt = $mysql->prepare('SELECT move_base_damage FROM moves WHERE move_name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									$stmt->bind_result($dmg);
									$result = $stmt->fetch();
									echo $dmg;
									$stmt->close();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
								if(isset($_POST['getMoveInfo']))
								{	
									//set up the server information						
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set name equal to the post information from move info
									$name = $_POST['moveInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
									$stmt = $mysql->prepare('SELECT move_pp FROM moves WHERE move_name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									$stmt->bind_result($pp);
									$result = $stmt->fetch();
									//display the result
									echo $pp;
									$stmt->close();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$mysql->close();
								}
							?>
						</td>
						<td>
							<?php
								if(isset($_POST['getMoveInfo']))
								{	
									//set up the server information						
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									//set name equal to the post information from move info
									$name = $_POST['moveInfo'];
									
									$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
									$stmt = $mysql->prepare('SELECT description FROM moves WHERE move_name=?');
									$stmt->bind_param('s',$name);
									$stmt->execute();
									$stmt->bind_result($desc);
									$result = $stmt->fetch();
									//display the result
									echo $desc;
									$stmt->close();
									if($mysql->connect_error)
									{
										die("Connection error: ". $mysql->connect_error);
									}
									$mysql->close();
								}
							?>
						</td>
					</tr>
				</table>
			</div>
			<hr>
		<div>
			<div class="mainpage">
				<form action="main.php" method="POST">
					<text>Select a trainer for information about the trainer.</text><br>
							<select id = "trainerInfo" name = "trainerInfo">
								<?php
								//set up the server name
									$servername = "oniddb.cws.oregonstate.edu";
									$username = "nakashig-db";
									$password = "xXiNAmO8UFsRQc9d";
									$dbname = "nakashig-db";
									// Create connection
									$conn = new mysqli($servername, $username, $password, $dbname);
									// Check connection
									if ($conn->connect_error) 
									{
									  die("Connection failed: " . $conn->connect_error);
									} 
									//set up the select statement
									$sql = "SELECT trainer_name FROM trainer";
									$result = $conn->query($sql);
									//display the results
									while ($row = $result->fetch_assoc()) 
									{
									  unset($name);
									  $name = $row['trainer_name']; 
									  echo '<option value="'.$name.'">'.$name.'</option>';
									}
									$conn->close();	
								?>
							</select>
						<input name="getTrainerInfo" type="submit" class="btn-primary" value="Check PokeDex"/>
				</form>
			</div>
		</div>
		<div id="trainerTable">
			<table class="table">
				<tr>
					<th>Trainer Name</th>
					<th>Description</th>
					<th>Pokemon Types</th>
				</tr>
				<tr>
					<td>
						<?php
							echo $_POST['trainerInfo'];
						?>
					</td>
					<td>
						<?php
							if(isset($_POST['getTrainerInfo']))
							{							
								$servername = "oniddb.cws.oregonstate.edu";
								$username = "nakashig-db";
								$password = "xXiNAmO8UFsRQc9d";
								$dbname = "nakashig-db";
								
								$name = $_POST['trainerInfo'];
								
								$mysql= new mysqli($servername, $username, $password, $dbname);
									
								$stmt = $mysql->prepare('SELECT description FROM trainer WHERE trainer_name=?');
								$stmt->bind_param('s',$name);
								$stmt->execute();
								if($mysql->connect_error)
								{
									die("Connection error: ". $mysql->connect_error);
								}
								$stmt->bind_result($desc);
								//display the result
								while($stmt->fetch())
								{
									echo $desc."<br>";
								}
								$stmt->close();
								$mysql->close();
							}
						?>
					</td>
					<td>
						<?php
						//if user is trying to get trainer information
							if(isset($_POST['getTrainerInfo']))
							{		
							//set up the server information					
								$servername = "oniddb.cws.oregonstate.edu";
								$username = "nakashig-db";
								$password = "xXiNAmO8UFsRQc9d";
								$dbname = "nakashig-db";
								
								$name = $_POST['trainerInfo'];
								
								$mysql= new mysqli($servername, $username, $password, $dbname);
									//set up the select statement
								$stmt = $mysql->prepare('SELECT type_name FROM types 
									INNER JOIN trainer_pokemon ON types.type_id = trainer_pokemon.trainer_pokemon_type_id
									INNER JOIN trainer ON trainer_pokemon.trainer_pokemon_id = trainer.trainer_id
									WHERE trainer_name=?');
								$stmt->bind_param('s',$name);
								$stmt->execute();
								$types = "";
								if($mysql->connect_error)
								{
									die("Connection error: ". $mysql->connect_error);
								}
								$stmt->bind_result($types);
								//display the results
								while($stmt->fetch())
								{
									echo $types."<br>";
								}
								$stmt->close();
								$mysql->close();
							}
						?>
					</td>
				</tr>
			</table>
		</div>
    </body>
</html>