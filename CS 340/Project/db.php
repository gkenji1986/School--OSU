<?php

$servername = 'oniddb.cws.oregonstate.edu';
$username = 'nakashig-db';
$password = 'xXiNAmO8UFsRQc9d';
$dbname = 'nakashig-db';
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check Connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$sql = "SELECT pokemon_id, name, description FROM pokemon";
$result = $conn->query($sql);
//process $result


$conn->close();
?>