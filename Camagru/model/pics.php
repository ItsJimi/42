<?php
	require_once("include.php");

	$request = pics($_POST, $connect);
	echo $request;
?>
