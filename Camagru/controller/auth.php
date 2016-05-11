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
			return (1);
		return (0);
	}

	// Hash
	function pass_hash($user, $pass) {
		return hash('whirlpool', $user.$pass);
	}
?>
