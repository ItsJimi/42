<?php
	// SignIn
	function signin($post, $connect) {
		if (!empty($post['signin_user']) && !empty($post['signin_pass']))
		{
			$sql = "SELECT * FROM users WHERE user='".htmlspecialchars($post['signin_user'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();
				if ($user['user'] === $post['signin_user'] && $user['password'] === pass_hash($post['signin_user'], $post['signin_pass'])) {
					if ($user['valid'] == 1) {
						$_SESSION['id'] = $user['id'];
						$_SESSION['pic'] = $user['pic'];
						$_SESSION['user'] = $user['user'];
						$_SESSION['mail'] = $user['mail'];
						$_SESSION['followers'] = $user['followers'];
						$_SESSION['hearts'] = $user['hearts'];
						$_SESSION['create_at'] = $user['create_at'];

						$res['end'] = true;
						$res['info'] = "Vous êtes connecté ! ;)";

						return (json_encode($res));
					}
					else {
						$res['end'] = false;
						$res['info'] = "Vous devez d'abord vérifier votre compte.";

						return (json_encode($res));
					}
				}
				else {
					$res['end'] = false;
					$res['info'] = "Les informations entrées sont incorrectes.";

					return (json_encode($res));
				}
			}
			else {
				$res['end'] = false;
				$res['info'] = "Les informations entrées sont incorrectes.";

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
