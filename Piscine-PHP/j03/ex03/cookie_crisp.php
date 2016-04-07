<?php
	if ($_GET['action'] == "set")
		setcookie($_GET['name'], $_GET['value']);
	elseif ($_GET['action'] == "get")
	{
		if ($_COOKIE[$_GET['name']])
			echo $_COOKIE[$_GET['name']]."\n";
	}
	elseif ($_GET['action'] == "del")
		setcookie($_GET['name'], "", time() - 3600);
?>
