<?php
	session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<?php
		if ($_SESSION['loggued_on_user']) {
			if ($_POST['msg'] && $_POST['submit'] === "Envoyer")
			{
				$error = false;
				$i = -1;
				if (!file_exists('../private'))
					$error = true;
				if (file_exists('../private/chat') && $error == false)
				{
					$msg = unserialize(file_get_contents('../private/chat'));
					if ($msg)
					{
						foreach ($msg as $key => $value)
							$i = $key;
					}
				}
				if ($error == false)
				{
					$fp = fopen("../private/chat", "r+");
					if (flock($fp, LOCK_EX | LOCK_NB)) {
						$msg[$i + 1]['login'] = $_SESSION['loggued_on_user'];
						$msg[$i + 1]['time'] = time();
						$msg[$i + 1]['msg'] = $_POST['msg'];
						$new_msg = serialize($msg);
						file_put_contents('../private/chat', $new_msg);
						flock($fp, LOCK_UN);
					}
					fclose($fp);
				}
			}
	?>
	<body>
		<form action="speak.php" method="post">
			<input type="text" name="msg" />
			<input type="submit" name="submit" value="Envoyer" />
		</form>
	<?php
		}
	?>
	</body>
</html>
