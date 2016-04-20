<?php
	$server = "localhost";
	$user = "root";
	$pass = "pass";
	$db = "db_instapics";

	try {
		$connect = new PDO("mysql:host=$server;dbname=$db", $user, $pass);
		$connect->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}
	catch(PDOException $e) {
		echo "Connection failed: " . $e->getMessage();
	}
?>
