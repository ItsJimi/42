<?php
	require_once("include.php");

	if (is_connected())
		$request = comments($_POST, $connect);
	else
		$request = 0;
	echo $request;
?>
