<?PHP
	require_once("./include/include.php");
	if (!is_admin())
		header('Location: ../signin.php');
?>
<html>
	<head>
		<title>Admin</title>
		<link rel="stylesheet" type="text/css" href="style.css">
	<head>
	<body>
	<header>
		<a href="index.php">Articles</a>
		<a href="users.php">Utilisateurs</a>
		<a href="categories.php">Catégories</a>
		<a href="commands.php">Commandes</a>
		<span><a href="../index.php">Revenir au site</a></span>
	</header>
