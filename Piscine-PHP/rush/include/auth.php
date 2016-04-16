<?php
	/***************************/
	/*       AuthFunctions     */
	/***************************/

	// Is Admin
	function is_admin() {
		if ($_SESSION['uuid'] && $_SESSION['uuid'] !== "" && $_SESSION['rank'] == 1)
			return (true);
		return (false);
	}

	// Is Connected
	function is_connected() {
		if ($_SESSION['uuid'] && $_SESSION['uuid'] !== "")
			return (true);
		return (false);
	}

	// Hash
	function pass_hash($mail, $pass) {
		return hash('whirlpool', $mail.$pass);
	}

	// Uuid
	function uuid() {
		return sprintf('%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
		     mt_rand(0, 0xffff), mt_rand(0, 0xffff),
		     mt_rand(0, 0xffff),
		     mt_rand(0, 0x0fff) | 0x4000,
		     mt_rand(0, 0x3fff) | 0x8000,
		     mt_rand(0, 0xffff), mt_rand(0, 0xffff), mt_rand(0, 0xffff)
	 	);
	}

	// Modif
	function modif($post, $connect) {
		if (!empty($post['mail']) && !empty($post['password1']) && !empty($post['password1'])) {
			if (preg_match('/@.+\./', $post['mail'])) {
				if ($post['password1'] === $post['password2']) {
					$sql = "UPDATE users SET mail, password FROM users WHERE uuid='".htmlspecialchars($_SESSION['uuid'])."'";
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
				$sql = "SELECT uuid, mail, password, create_at, rank, accesstoken FROM users WHERE mail='".htmlspecialchars($post['mail'])."'";
				$result = mysqli_query($connect, $sql);
				if (mysqli_num_rows($result) == 0) {
					if ($post['password1'] === $post['password2']) {
						$sql = "INSERT INTO users (uuid, mail, password, rank, create_at)
						VALUES ('".uuid()."', '".$post['mail']."', '".pass_hash($post['mail'], $post['password1'])."', 0, NOW())";
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
		if (!empty($post['password']) && !empty($post['password']))
		{
			$sql = "SELECT uuid, mail, password, create_at, rank, accesstoken FROM users WHERE mail='".htmlspecialchars($post['mail'])."'";
			$result = mysqli_query($connect, $sql);
			if (mysqli_num_rows($result) > 0) {
				$user = mysqli_fetch_assoc($result);
				if ($user['mail'] === $post['mail'] && $user['password'] === pass_hash($post['mail'], $post['password'])) {
					$_SESSION['uuid'] = $user['uuid'];
					$_SESSION['mail'] = $user['mail'];
					$_SESSION['rank'] = $user['rank'];
					$_SESSION['create_at'] = $user['create_at'];
					$_SESSION['accesstoken'] = $user['accesstoken'];
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
		if ($_SESSION['uuid'] && $_SESSION['uuid'] !== "") {
			$current = $_SESSION['current'];
			session_destroy();
			header('Location: '.$current);
		}
		header('Location: '.$_SESSION['current']);
	}
?>
