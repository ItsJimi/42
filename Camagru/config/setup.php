<?php
	// CONNECT DB
	try {
		$connect = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$connect->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	}
	catch(PDOException $e) {
		echo "Connection failed: " . $e->getMessage();
	}
	// CREATE DB
	try {
    	$sql = "CREATE DATABASE IF NOT EXISTS db_instapics";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// USE DB INSTAPICS
	$connect->query("USE db_instapics;");
	// CREATE TABLE USERS
	try {
		$sql = "CREATE TABLE IF NOT EXISTS users (
			id INT PRIMARY KEY AUTO_INCREMENT,
			user VARCHAR(255) NOT NULL,
			password VARCHAR(128) NOT NULL,
			mail VARCHAR(255) NOT NULL,
			valid INT(1) DEFAULT 0,
			create_at TIMESTAMP
		)";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE CODES
	try {
		$sql = "CREATE TABLE IF NOT EXISTS codes (
			id INT PRIMARY KEY AUTO_INCREMENT,
			mail VARCHAR(255) NOT NULL,
			code VARCHAR(255) NOT NULL
		)";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE PICS
	try {
		$sql = "CREATE TABLE IF NOT EXISTS pics (
			id INT PRIMARY KEY AUTO_INCREMENT,
			pic MEDIUMTEXT NOT NULL,
			user VARCHAR(255) NOT NULL,
			hearts INT DEFAULT 0,
			create_at TIMESTAMP
		)";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE LIKES
	try {
		$sql = "CREATE TABLE IF NOT EXISTS likes (
			id INT PRIMARY KEY AUTO_INCREMENT,
			pic INT NOT NULL,
			user VARCHAR(255) NOT NULL,
			pic_user VARCHAR(255) NOT NULL
		)";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
	// CREATE TABLE COMMENTS
	try {
		$sql = "CREATE TABLE IF NOT EXISTS comments (
			id INT PRIMARY KEY AUTO_INCREMENT,
			pic INT NOT NULL,
			comment TEXT NOT NULL,
			user VARCHAR(255) NOT NULL,
			create_at TIMESTAMP
		)";
    	$connect->query($sql);
    }
	catch(PDOException $e) {
    	echo $sql . "<br>" . $e->getMessage();
    }
?>
