<?php
	require_once("include.php");

	if (is_connected()) {
		reload_member($connect);
		$res['logged'] = true;
		$res['user'] = $_SESSION['user'];
		$res['mail'] = $_SESSION['mail'];
		$res['hearts'] = $_SESSION['hearts'];
		$res['create_at'] = $_SESSION['create_at'];

		$request = json_encode($res);
	}
	else {
		$res['logged'] = false;

		$request = json_encode($res);
	}
	echo $request;
?>
