<?php
	require_once("include.php");

	if (!is_connected())
		$request = signup($_POST, $connect);
	else
		$request = 0;
	echo $request;
?>
