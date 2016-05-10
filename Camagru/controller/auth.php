<?php
	/***************************/
	/*       AuthFunctions     */
	/***************************/

	// Is Admin
	function is_admin() {
		if (isset($_SESSION['id']) && isset($_SESSION['rank']) && $_SESSION['id'] !== "" && $_SESSION['rank'] == 1)
			return (true);
		return (false);
	}

	// Is Connected
	function is_connected() {
		if (isset($_SESSION['id']) && $_SESSION['id'] !== "")
			return (true);
		return (false);
	}

	// Hash
	function pass_hash($user, $pass) {
		return hash('whirlpool', $user.$pass);
	}

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

	// SignUp
	function signup($post, $connect) {
		if (!empty($post['signup_user']) && !empty($post['signup_mail']) && !empty($post['signup_pass1']) && !empty($post['signup_pass2'])) {
			if (preg_match('/@.+\./', $post['signup_mail'])) {
				$sql = "SELECT id, user, mail FROM users WHERE user='".htmlspecialchars($post['signup_user'])."'";
				$result = $connect->query($sql);
				if ($result->rowCount() > 0) {
					return ("Le nom d'utilisateur est déjà pris.");
				}
				else {
					$sql = "SELECT id, user, mail FROM users WHERE mail='".htmlspecialchars($post['signup_mail'])."'";
					$result = $connect->query($sql);
					if ($result->rowCount() > 0) {
						return ("L'adresse mail est déjà prise.");
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
						    $message = "Bonjour ".$post['signup_user'].",\n
							Pour vérifier votre compte, il vous suffit de cliquer sur le lien ci dessous.\n
							http://localhost/Camagru/verif.php?v=".$post['signup_user']."&l=".sha1($post['signup_user']."quarante");
						    $headers = 'From: verif@instapics.fr' . "\r\n";

						    mail($to, $subject, $message, $headers);
							return ("Un mail de vérification a été envoyé.");
						}
						else
							return ("Les mots de passe ne correspondent pas.");
					}
				}
			}
			else
				return ("L'adresse mail doit être sous la forme test@test.test");
		}
		else
			return ("Veuillez remplir tous les champs.");
		return ("Erreur");
	}

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
						return ("Vous êtes connecté ! ;)");
					}
					else
						return ("Vous devez d'abord vérifier votre compte.");
				}
				else
					return ("Les informations entrées sont incorrectes.");
			}
			else
				return ("Les informations entrées sont incorrectes.");
		}
		else
			return ("Veuillez remplir tous les champs.");
		return ("Erreur");
	}

	// SignOut
	function signout() {
		if (isset($_SESSION['id']) && $_SESSION['id'] !== "") {
			session_destroy();
			return ("Vous êtes déconnecté ! ;)");
		}
		return ("Erreur");
	}
?>
