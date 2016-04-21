<?php
	$server = "localhost";
	$user = "root";
	$pass = "pass";
	$db = "db_instapics";

	// CONNECT DB
	try {
		$connect = new PDO("mysql:host=$server;dbname=$db", $user, $pass);
		$connect->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}
	catch(PDOException $e) {
		echo "Connection failed: " . $e->getMessage();
	}
	// CREATE DB
	try {
    	$sql = "CREATE DATABASE ".$db;
    	$connect->exec($sql);
    	echo "Database created successfully<br>";
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE USERS
	try {
		$sql = "CREATE TABLE users (
			id INT PRIMARY KEY AUTO_INCREMENT,
			user VARCHAR(255) NOT NULL,
			password VARCHAR(128) NOT NULL,
			mail VARCHAR(255) NOT NULL,
			rank INT(1),
			valid INT(1),
			create_at TIMESTAMP
		)";
    	$connect->exec($sql);
		echo "Table MyGuests created successfully";
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE PICS
	try {
		$sql = "CREATE TABLE users (
			id INT PRIMARY KEY AUTO_INCREMENT,
			pics LONGTEXT NOT NULL,
			user VARCHAR(255) NOT NULL,
			heart INT,
			create_at TIMESTAMP
		)";
    	$connect->exec($sql);
		echo "Table MyGuests created successfully";
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// INSERT IN USERS
	try {
    	$sql = "INSERT INTO users (user, password, mail, rank, valid)
    	VALUES ('Jimi',
		'ad1612a8bb17de45bcb4892031cd53f774a0e44632f1cf7c88ad9fb55196d785d896d69b75091ddc33025249cd88062e6dfa02aab959e6366ae710eb9d8a7bad',
		'jimi@fruitice.fr',
		1, 1)";
    	$connect->exec($sql);
    	echo "New record created successfully";
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }

	$connect = NULL;
?>
