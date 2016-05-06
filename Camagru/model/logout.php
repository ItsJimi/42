<?php
	require_once("include.php");

	if (is_connected())
		$request = signout();
	else
		$request = 0;
	echo $request;
?>
