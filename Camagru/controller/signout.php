<?php
	// SignOut
	function signout() {
		if (isset($_SESSION['id']) && $_SESSION['id'] !== "") {
			session_destroy();
			$res['end'] = true;
			$res['info'] = "Vous êtes déconnecté ! ;)";

			return (json_encode($res));
		}
		$res['end'] = false;
		$res['info'] = "Erreur.";

		return (json_encode($res));
	}
?>
