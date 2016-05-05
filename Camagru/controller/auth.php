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
						return (true);
					}
				}
			}
			else
				$_SESSION['error'] = "L'adresse email doit être correctement formatée.";
		}
		return (false);
	}

	// SignUp
	function signup($post, $connect) {
		if (!empty($post['mail']) && !empty($post['password1']) && !empty($post['password1'])) {
			if (preg_match('/@.+\./', $post['mail'])) {
				$sql = "SELECT id, mail, password, create_at, rank, accesstoken FROM users WHERE mail='".htmlspecialchars($post['mail'])."'";
				$result = mysqli_query($connect, $sql);
				if (mysqli_num_rows($result) == 0) {
					if ($post['password1'] === $post['password2']) {
						$sql = "INSERT INTO users (id, mail, password, rank, create_at)
						VALUES ('".id()."', '".$post['mail']."', '".pass_hash($post['mail'], $post['password1'])."', 0, NOW())";
						if (mysqli_query($connect, $sql)) {
							$_SESSION['error'] = "";
						    return (true);
						}
						else {
						    $_SESSION['error'] = "Une erreur est survenue.";
						}
					}
					else
						$_SESSION['error'] = "Les mots de passes de correspondent pas.";
				}
				else
					$_SESSION['error'] = "L'adresse email est déjà prise.";
			}
			else
				$_SESSION['error'] = "L'adresse email doit être correctement formatée.";
		}
		return (false);
	}

	// SignIn
	function signin($post, $connect) {
		if (!empty($post['signin_user']) && !empty($post['signin_pass']))
		{
			$sql = "SELECT id, pic, user, password, mail, followers FROM users WHERE user='".htmlspecialchars($post['signin_user'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();
				if ($user['signin_user'] === $post['signin_user'] && $user['signin_pass'] === pass_hash($post['signin_user'], $post['signin_pass'])) {
					$_SESSION['id'] = $user['id'];
					$_SESSION['pic'] = $user['pic'];
					$_SESSION['user'] = $user['user'];
					$_SESSION['password'] = $user['password'];
					$_SESSION['mail'] = $user['mail'];
					$_SESSION['followers'] = $user['followers'];
					$_SESSION['hearts'] = $user['hearts'];
					$_SESSION['create_at'] = $user['create_at'];
					return (true);
				}
				else
					$_SESSION['error'] = "Informations incorrectes.";
			}
		}
		return (false);
	}

	// Logout
	function logout() {
		if ($_SESSION['id'] && $_SESSION['id'] !== "") {
			$current = $_SESSION['current'];
			session_destroy();
			header('Location: '.$current);
		}
		header('Location: '.$_SESSION['current']);
	}
?>
