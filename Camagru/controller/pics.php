<?php
	// Pics
	function pics($post, $connect) {
		$sql = "SELECT * FROM pics ORDER BY id DESC LIMIT ".intval($post['nbr']).", 2";
		$result = $connect->query($sql);
		$fetch1 = $result->fetchAll(PDO::FETCH_ASSOC);
		foreach ($fetch1 as $key => $value) {
			$sql = "SELECT COUNT(*) AS 'count' FROM likes WHERE pic='".$value['id']."'";
			$result = $connect->query($sql);
			$fetch2 = $result->fetch(PDO::FETCH_ASSOC);
			$fetch1[$key]['likes'] = $fetch2['count'];

			if (is_connected()) {
				$sql = "SELECT * FROM likes WHERE pic='".intval($value['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
				$result = $connect->query($sql);
				if ($result->fetch())
					$fetch1[$key]['islike'] = 1;
				else
					$fetch1[$key]['islike'] = 0;
			}

			$sql = "SELECT user, comment FROM comments WHERE pic='".$value['id']."' ORDER BY id ASC";
			$result = $connect->query($sql);
			$fetch3 = $result->fetchAll(PDO::FETCH_ASSOC);
			$fetch1[$key]['comments'] = $fetch3;
		}
		$res = json_encode($fetch1);
		return ($res);
	}
?>
