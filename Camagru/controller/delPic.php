<?php
	// Del Pic
	function delPic($post, $connect) {
		if (isset($post['id'])) {
			$sql = "SELECT id, user FROM pics WHERE id='".intval($post['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();

				$sql = "DELETE FROM pics WHERE id='".intval($post['id'])."'";
				$result = $connect->query($sql);

				$res['end'] = true;
				$res['info'] = "La photo a été supprimée !";

				return (json_encode($res));
			}
			else {
				$res['end'] = false;
				$res['info'] = "Une erreur est survenue.";

				return (json_encode($res));
			}
		}
	}
?>
