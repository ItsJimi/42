<?php
	require_once('controller/include.php');
	require_once('view/header.php');

	if (!is_connected())
		require_once('view/login.php');
	elseif (!isset($_GET['p']) || $_GET['p'] == "")
		require_once('view/home.php');
	elseif (isset($_GET['p']) && $_GET['p'] == "home")
		require_once('view/home.php');
	elseif (isset($_GET['p']) && $_GET['p'] == "pic")
		require_once('view/pic.php');
	else
		echo "<center><h1>Cette page n'existe pas.</h1></center>";

	require_once('view/footer.php');
?>
