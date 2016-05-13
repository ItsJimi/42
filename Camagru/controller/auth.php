<?php
	/***************************/
	/*       AuthFunctions     */
	/***************************/

	// Is Admin
	function is_admin() {
		if (isset($_SESSION['id']) && isset($_SESSION['rank']) && $_SESSION['id'] !== "" && $_SESSION['rank'] == 1)
			return (1);
		return (0);
	}

	// Is Connected
	function is_connected() {
		if (isset($_SESSION['id']) && $_SESSION['id'] !== "")
			return (1);
		return (0);
	}

	// Reload member
	function reload_member($connect) {
		if (isset($_SESSION['id']) && $_SESSION['id'] !== "") {
			$sql = "SELECT * FROM users WHERE id=".$_SESSION['id'];
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();

				$_SESSION['user'] = $user['user'];
				$_SESSION['mail'] = $user['mail'];
				$_SESSION['followers'] = $user['followers'];
				$_SESSION['hearts'] = $user['hearts'];
				$_SESSION['create_at'] = $user['create_at'];
				return (1);
			}
		}
		return (0);
	}

	// Hash
	function pass_hash($user, $pass) {
		return hash('whirlpool', $user.$pass);
	}
?>
