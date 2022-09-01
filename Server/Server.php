<?php

$server = "localhost";
$username = "user";
$password = "password";
$name = "db";

$conn = mysqli_connect($server, $username, $password, $name);

if (!$conn) {
	die("Connection failed: " . mysqli_connect_error());
}

echo "Connected successfully" . PHP_EOL;

$sql = "SELECT * FROM Player";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
    echo "id: " . $row["id"]. " - Name: " . $row["name"]. PHP_EOL;
  }
} else {
  echo "0 results";
}
$conn->close();