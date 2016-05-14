<?php
	require_once("include.php");

	$request = pics($_POST['nbr'], $connect);
	echo $request;
?>
