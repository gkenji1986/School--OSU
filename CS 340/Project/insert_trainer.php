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
       
            <text>Enter name and description for the new Trainer</text>
 <!-- setting up the post method-->
            <form action='pokemon_insert_trainer_queries.php' method='POST'>
                 <p>
                    <label for="trainer">Name:</label>
                    <input type="text" name="trainer_name"/>
                </p>
                  <p>
                    <label for="trainer">Description:</label>
                    <input type="text" name="trainer_desc"/>
                </p>
                <input name="addTrainer" type="submit" class="btn-primary" value="Submit"/>
            </form>
        </div>
        </fieldset>
		<br>
		<fieldset>
			<text>Select a Trainer and element type to add the Pokemon type to the Trainer.</text>
				<text>Trainer</text>
					<form action='pokemon_insert_trainer_queries.php' method='POST'>
								<select id = "trainerName" name = "trainerName">
									<?php
									//set up the server
										$servername = "oniddb.cws.oregonstate.edu";
										$username = "nakashig-db";
										$password = "xXiNAmO8UFsRQc9d";
										$dbname = "nakashig-db";
										
										$mysql= new mysqli($servername, $username, $password, $dbname);
										//check the connection	
										if ($mysql->connect_error) 
										{
											 die("Connection failed: " . $mysql->connect_error);
										} 
										//create the select statement
										$sql = "SELECT trainer_name FROM trainer";
										$result = $mysql->query($sql);
										//output the result
										while ($row = $result->fetch_assoc()) 
										{
											 unset($name);
											$name = $row['trainer_name']; 
											 echo '<option value="'.$name.'">'.$name.'</option>';
										}
										$mysql->close();	
									?>
								</select>
				<text>Type</text>
								<select id = "trainerType" name = "trainerType">
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
									//output the result
									while ($row = $result->fetch_assoc()) 
									{
										 unset($type);
										$type = $row['type_name']; 
										 echo '<option value="'.$type.'">'.$type.'</option>';
									}
									$mysql->close();	
								?>
								</select>
							<input name="addTrainerType" type="submit" class="btn-primary" value="Submit"/>	
					</form>
		</fieldset>
		
    </body>
</html>