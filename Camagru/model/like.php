<?php
	require_once("include.php");

	if (is_connected())
		$request = like($connect);
	else
		$request = 0;
	echo $request;
?>
