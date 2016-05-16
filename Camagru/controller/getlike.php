<?php
	function getLike($connect) {
		$sql = "SELECT hearts FROM pics WHERE id='".htmlspecialchars($post['id'])."'";
		$result = $connect->query($sql);
		if ($result->rowCount() > 0) {
			$pic = $result->fetch();
			$res['end'] = true;
			$res['hearts'] = $pic['hearts'];

			return (json_encode($res));
		}
	}
?>
