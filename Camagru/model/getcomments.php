<?php
	require_once("include.php");

	$request = getComments($_POST, $connect);
	echo $request;
?>
