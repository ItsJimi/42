<?php
	// DB
	$server = "";
	$user = "";
	$pass = "";
	$dbname = "shop";

	$connect = mysqli_connect($server, $user, $pass, $dbname);

	if (!$connect) {
		die("Connection failed: ".mysqli_connect_error()."<br /><h1><a href=\"install.php\">Si c'est votre première connextion, cliquez ici.</a></h1>");
	}
?>
