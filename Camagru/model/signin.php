<?php
	require_once("include.php");

	if (!is_connected())
		$request = signin($_POST, $connect);
	else
		$request = 0;
	echo $request;
?>
