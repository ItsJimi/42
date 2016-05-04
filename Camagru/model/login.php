<?php
	require_once("../config/setup.php");
	require_once("../controller/auth.php");

	if (signin($_POST, $connect)) {
		echo "TRUE";
	}
	else {
		echo "FALSE";
	}
?>
