<?php
	require_once('controller/include.php');
	require_once('view/header.html');

	if (!isset($_GET['p']) || $_GET['p'] == "")
		require_once('view/home.html');
	elseif (isset($_GET['p']) && $_GET['p'] == "home")
		require_once('view/home.html');
	elseif (isset($_GET['p']) && $_GET['p'] == "pic" && is_connected())
		require_once('view/pic.html');
	else
		echo "<center><h1>Cette page n'existe pas.</h1></center>";

	require_once('view/footer.html');
?>
