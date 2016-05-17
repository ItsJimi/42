<?php
	// Pics
	function pics($nbr, $connect) {
		$sql = "SELECT * FROM pics ORDER BY id DESC LIMIT ".intval($nbr).", 2";
		$result = $connect->query($sql);
		$fetch1 = $result->fetchAll(PDO::FETCH_ASSOC);

		foreach ($fetch1 as $key => $value) {
			$sql = "SELECT COUNT(*) AS 'count' FROM likes WHERE pic='".$value['id']."'";
			$result = $connect->query($sql);
			$fetch2 = $result->fetch(PDO::FETCH_ASSOC);
			$fetch1[$key]['likes'] = $fetch2['count'];
		}
		$res = json_encode($fetch1);
		return ($res);
	}
?>
