<?php
	// Reset password
	function reset_pass($post, $connect) {
		if (preg_match('/@.+\./', $post['reset_mail'])) {
			$sql = "SELECT user, mail FROM users WHERE mail='".htmlspecialchars($post['reset_mail'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();
				$code = substr(sha1($post['reset_mail']."controle"), rand(0, 14), 5);

				$sql = $connect->prepare('INSERT INTO codes (mail, code) VALUES (:mail, :code)');
				$sql->execute(array(
					'mail' => htmlspecialchars($user['mail']),
					'code' => $code
				));

				$to = $user['mail'];
				$subject = 'Réinitialisation du mot de passe InstaPics';
				$message = "Bonjour ".$user['user'].",\nPour réinitialiser votre mot de passe, il vous suffit de cliquer sur le lien ci-dessous.\n\nhttp://localhost:8080/Camagru/reset.php?m=".$user['mail']."&c=".$code."\n\nSi vous n'avez pas fait de demande de réinitialisation de mot de passe, veuillez cliquer sur le lien ci-dessous\n\nhttp://localhost:8080/Camagru/reset.php?m=".$post['reset_mail']."&c=no";
				$headers = 'From: reset@instapics.fr';

				mail($to, $subject, $message, $headers);

				$res['end'] = true;
				$res['info'] = "Un mail de réinitialisation a été envoyé.";

				return(json_encode($res));
			}
			else {
				$res['end'] = false;
				$res['info'] = "Le mail n'est pas valide";

				return(json_encode($res));
			}
		}
		else {
			$res['end'] = false;
			$res['info'] = "Le mail n'est pas valide";

			return(json_encode($res));
		}
	}
?>
