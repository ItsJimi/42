<?php
	require_once("controller/include.php");

	if (isset($_GET['v']) && isset($_GET['l']) && $_GET['l'] === sha1($_GET['v']."quarante")) {
		$sql = "SELECT user, valid FROM users WHERE user='".htmlspecialchars($_GET['v'])."'";
		$result = $connect->query($sql);
		if ($result->rowCount() > 0) {
			$user = $result->fetch();
			if ($user['valid'] == 0) {
				$sql = $connect->prepare('UPDATE users SET valid = :valid WHERE user = :user');
				$sql->execute(array(
					'user' => htmlspecialchars($_GET['v']),
					'valid' => 1
				));
				echo "Votre compte a été vérifié.";
			}
			else {
				echo "Le lien n'est pas valide.";
			}
		}
		else {
			echo "Le lien n'est pas valide.";
		}
	}
	else {
		echo "Le lien n'est pas valide.";
	}
?>
