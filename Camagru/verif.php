<?php
	require_once("controller/include.php");

	if (isset($_GET['v']) && isset($_GET['l']) && $_GET['l'] === sha1($_GET['v']."quarante")) {
		try {
			$db = new PDO('mysql:host=localhost;dbname=db_instapics;charset=utf8', 'root', 'pass');
		}
		catch(Exception $e) {
			die('Erreur : '.$e->getMessage());
		}
		$sql = "SELECT user, valid FROM users WHERE user='".htmlspecialchars($_GET['v'])."'";
		$result = $db->query($sql);
		if ($result->rowCount() > 0) {
			$user = $result->fetch();
			if ($user['valid'] == 0) {
				$sql = $db->prepare('UPDATE users SET valid = :valid WHERE user = :user');
				$sql->execute(array(
					'user' => $_GET['v'],
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
?>
