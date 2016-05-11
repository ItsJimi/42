<?php
	// SignUp
	function signup($post, $connect) {
		if (!empty($post['signup_user']) && !empty($post['signup_mail']) && !empty($post['signup_pass1']) && !empty($post['signup_pass2'])) {
			if (preg_match('/@.+\./', $post['signup_mail'])) {
				$sql = "SELECT id, user, mail FROM users WHERE user='".htmlspecialchars($post['signup_user'])."'";
				$result = $connect->query($sql);
				if ($result->rowCount() > 0) {
					$res['end'] = false;
					$res['info'] = "Le nom d'utilisateur est déjà pris.";

					return (json_encode($res));
				}
				else {
					$sql = "SELECT id, user, mail FROM users WHERE mail='".htmlspecialchars($post['signup_mail'])."'";
					$result = $connect->query($sql);
					if ($result->rowCount() > 0) {
						$res['end'] = false;
						$res['info'] = "L'adresse mail est déjà prise.";

						return (json_encode($res));
					}
					else {
						if ($post['signup_pass1'] === $post['signup_pass2']) {
							$sql = $connect->prepare('INSERT INTO users (user, password, mail) VALUES (:user, :password, :mail)');
							$sql->execute(array(
								'user' => htmlspecialchars($post['signup_user']),
								'password' => pass_hash($post['signup_user'], $post['signup_pass1']),
								'mail' => htmlspecialchars($post['signup_mail'])
							));
							$to = $post['signup_mail'];
							$subject = 'Vérification InstaPics';
							$message = "Bonjour ".$post['signup_user'].",\nPour vérifier votre compte, il vous suffit de cliquer sur le lien ci dessous.\nhttp://localhost:8080/Camagru/verif.php?v=".$post['signup_user']."&l=".sha1($post['signup_user']."quarante");
							$headers = 'From: verif@instapics.fr';

							mail($to, $subject, $message, $headers);

							$res['end'] = true;
							$res['info'] = "Un mail de vérification a été envoyé.";

							return (json_encode($res));
						}
						else {
							$res['end'] = false;
							$res['info'] = "Les mots de passe ne correspondent pas.";

							return (json_encode($res));
						}
					}
				}
			}
			else {
				$res['end'] = false;
				$res['info'] = "L'adresse mail doit être sous la forme test@test.test";

				return (json_encode($res));
			}
		}
		else {
			$res['end'] = false;
			$res['info'] = "Veuillez remplir tous les champs.";

			return (json_encode($res));
		}
		$res['end'] = false;
		$res['info'] = "Erreur.";

		return (json_encode($res));
	}
?>
