<?php
	function getLike($post, $connect) {
		$sql = "SELECT COUNT(*) AS 'count' FROM likes WHERE pic='".intval($post['id'])."'";
		$result = $connect->query($sql);
		if ($result->rowCount() > 0) {
			$pic = $result->fetch();
			$res['end'] = true;
			$res['hearts'] = $pic['count'];

			return (json_encode($res));
		}
		else {
			$res['end'] = false;
			$res['hearts'] = "Une erreur est survenue.";
		}
	}
?>
