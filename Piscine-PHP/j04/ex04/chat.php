<?php
	session_start();
	date_default_timezone_set('Europe/Paris');
	if ($_SESSION['loggued_on_user']) {
		$error = false;
		$i = -1;
		if (!file_exists('../private'))
			$error = true;
		if (file_exists('../private/chat') && $error == false)
		{
			$msg = unserialize(file_get_contents('../private/chat'));
			if ($msg)
			{
				foreach ($msg as $key => $value) {
					echo "[".date("G", $value['time']).":".date("i", $value['time'])."] <b>".$value['login']."</b>: ".$value['msg']."<br />";
				}
			}
		}
	}
?>
