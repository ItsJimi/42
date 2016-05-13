<?php
	require_once("include.php");

	if (is_connected())
		$request = save($_POST['pic'], $_POST['filter'], $connect);
	else
		$request = 0;
	echo $request;
?>
