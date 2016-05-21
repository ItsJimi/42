<?php
	// MyPics
	function myPics($post, $connect) {
		$sql = "SELECT * FROM pics WHERE user='".htmlspecialchars($_SESSION['user'])."' ORDER BY id DESC";
		$result = $connect->query($sql);
		$fetch1 = $result->fetchAll(PDO::FETCH_ASSOC);

		$res = json_encode($fetch1);
		return ($res);
	}
?>
