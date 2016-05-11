<?php
	// Modif
	function modif($post, $connect) {
		if (!empty($post['mail']) && !empty($post['password1']) && !empty($post['password1'])) {
			if (preg_match('/@.+\./', $post['mail'])) {
				if ($post['password1'] === $post['password2']) {
					$sql = "UPDATE users SET mail, password FROM users WHERE id='".htmlspecialchars($_SESSION['id'])."'";
					if (mysqli_query($connect, $sql)) {
						return ("Vos informations ont été modifiées.");
					}
				}
				else
					return ("Les mots de passe ne correspondent pas.");
			}
			else
				return ("L'adresse mail doit être sous la forme test@test.test");
		}
		else
			return ("Veuillez remplir tous les champs.");
		return (false);
	}
?>
