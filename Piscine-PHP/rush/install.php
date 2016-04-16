<?php
	require_once("./include/auth.php");

	if (!empty($_POST['mail']) && !empty($_POST['password1']) && !empty($_POST['password2'])) {
		if (preg_match('/@.+\./', $_POST['mail']) && $_POST['password1'] === $_POST['password2']) {
			// CONNECT
			$server = "";
			$user = "";
			$pass = "";
			$dbname = "shop";

			$connect = mysqli_connect($server, $user, $pass);

			if (!$connect) {
				die("Connection failed: ".mysqli_connect_error());
			}

			// CREATE
			$sql = "CREATE DATABASE ".$dbname;
			if (mysqli_query($connect, $sql)) {
				echo "Database created successfully<br />";
				mysqli_close($connect);

				$connect = mysqli_connect($server, $user, $pass, $dbname);

				if (!$connect) {
				    die("Connection failed: ".mysqli_connect_error());
				}

				// USER
				$sql = "CREATE TABLE users (
					uuid VARCHAR(255) NOT NULL,
					mail VARCHAR(255) NOT NULL,
					password VARCHAR(128) NOT NULL,
					rank INT(1),
					create_at TIMESTAMP,
					accesstoken VARCHAR(255)
				)";

				if (mysqli_query($connect, $sql)) {
				    echo "Users table created successfully<br />";
					$sql = "INSERT INTO users (uuid, mail, password, rank, create_at)
					VALUES ('".uuid()."', '".$_POST['mail']."', '".pass_hash($_POST['mail'], $_POST['password1'])."', 1, NOW())";

					if (mysqli_query($connect, $sql)) {
					    echo "New record created successfully<br />";
					}
					else {
					    echo "Error: ".$sql."<br />".mysqli_error($connect);
					}
				}
				else {
				    echo "Error creating table: ".mysqli_error($connect);
				}

				// ARTICLE
				$sql = "CREATE TABLE articles (
					uuid VARCHAR(255) NOT NULL,
					name VARCHAR(255) NOT NULL,
					description TEXT,
					img VARCHAR(255),
					price FLOAT(4),
					stock INT(11),
					star INT(1)
				)";

				if (mysqli_query($connect, $sql)) {
				    echo "Article table created successfully<br />";
				}
				else {
				    echo "Error creating table: ".mysqli_error($connect);
				}

				// CATEGORY
				$sql = "CREATE TABLE categories (
					uuid VARCHAR(255) NOT NULL,
					name VARCHAR(255) NOT NULL,
					article TEXT
				)";

				if (mysqli_query($connect, $sql)) {
				    echo "Category table created successfully<br />";
				}
				else {
				    echo "Error creating table: ".mysqli_error($connect);
				}

				// COMMANDS
				$sql = "CREATE TABLE commands (
					uuid VARCHAR(255) NOT NULL,
					price INT(11) NOT NULL,
					tab TEXT
				)";

				if (mysqli_query($connect, $sql)) {
				    echo "Commands table created successfully<br />";
				}
				else {
				    echo "Error creating table: ".mysqli_error($connect);
				}
			}
			else {
				echo "Error creating database: " . mysqli_error($connect);
			}
			mysqli_close($connect);
		}
	}
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Install</title>
	</head>
	<body>
		<form action="install.php" method="post">
			<h3>Administrateur</h3>
			<hr />
			<label for="mail">Email :</label>
			<input type="email" name="mail" value="" />
			<label for="password1">Mot de passe :</label>
			<input type="password" name="password1" value="" />
			<label for="password2">Mot de passe :</label>
			<input type="password" name="password2" value="" />
			<hr />
			<input type="submit" name="submit" value="Installer">
		</form>
	</body>
</html>
