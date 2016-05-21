<?php
	// Del Pic
	function delPic($post, $connect) {
		$sql = "SELECT pic, user FROM pics WHERE pic='".intval($post['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
		$result = $connect->query($sql);
		if ($result->fetch()) {
		}
		$sql = "DELETE FROM pics WHERE pic='".intval($post['id'])."'";
		$result = $connect->query($sql);

		$res = json_encode($fetch1);
		return ($res);
	}
?>
