<?php
	session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Chat 42</title>
	</head>
	<body>
	<?php
		include 'auth.php';

		if(auth($_POST['login'], $_POST['passwd'])) {
			$_SESSION['loggued_on_user'] = $_POST['login'];
	?>
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe><br />
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	<?php
		}
		else {
			$_SESSION['loggued_on_user'] = "";
			echo "ERROR\n";
		}
	?>
	</body>
</html>
