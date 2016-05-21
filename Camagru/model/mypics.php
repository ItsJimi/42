<?php
	require_once("include.php");

	$request = myPics($_POST, $connect);
	echo $request;
?>
