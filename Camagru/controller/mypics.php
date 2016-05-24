<?php
	// MyPics
	function myPics($post, $connect) {
		$sql = "SELECT * FROM pics WHERE user='".htmlspecialchars($_SESSION['user'])."' ORDER BY id DESC";
		$result = $connect->query($sql);
		if ($result->rowCount() > 0) {
			$fetch1['data'] = $result->fetchAll(PDO::FETCH_ASSOC);
			$fetch1['end'] = true;
			$res = json_encode($fetch1);
			return ($res);
		}
		else {
			$res['end'] = false;
			$res['info'] = "Il n'y a aucune photo à afficher.";

			return (json_encode($res));
		}
	}
?>
