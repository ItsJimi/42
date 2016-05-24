<?php
	// Pics
	function pics($post, $connect) {
		if ($post['bool'] === "false") {
			$sql = "SELECT * FROM pics ORDER BY id DESC LIMIT ".intval($post['nbr']).", 2";
			$result = $connect->query($sql);
			$fetch1['data'] = $result->fetchAll(PDO::FETCH_ASSOC);
			foreach ($fetch1['data'] as $key => $value) {
				$sql = "SELECT COUNT(*) AS 'count' FROM likes WHERE pic='".$value['id']."'";
				$result = $connect->query($sql);
				$fetch2 = $result->fetch(PDO::FETCH_ASSOC);
				$fetch1['data'][$key]['likes'] = $fetch2['count'];

				if (is_connected()) {
					$sql = "SELECT * FROM likes WHERE pic='".intval($value['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
					$result = $connect->query($sql);
					if ($result->fetch())
						$fetch1['data'][$key]['islike'] = 1;
					else
						$fetch1['data'][$key]['islike'] = 0;
				}

				$sql = "SELECT user, comment FROM comments WHERE pic='".$value['id']."' ORDER BY id ASC";
				$result = $connect->query($sql);
				$fetch3 = $result->fetchAll(PDO::FETCH_ASSOC);
				$fetch1['data'][$key]['comments'] = $fetch3;
			}
			$fetch1['end'] = true;
			$res = json_encode($fetch1);
			return ($res);
		}
		else {
			$sql = "SELECT * FROM pics WHERE id='".intval($post['nbr'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$fetch1 = $result->fetch(PDO::FETCH_ASSOC);

				$sql = "SELECT COUNT(*) AS 'count' FROM likes WHERE pic='".intval($fetch1['id'])."'";
				$result = $connect->query($sql);
				$fetch2 = $result->fetch(PDO::FETCH_ASSOC);
				$fetch1['likes'] = $fetch2['count'];

				if (is_connected()) {
					$sql = "SELECT * FROM likes WHERE pic='".intval($fetch1['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
					$result = $connect->query($sql);
					if ($result->fetch())
						$fetch1['islike'] = 1;
					else
						$fetch1['islike'] = 0;
				}

				$sql = "SELECT user, comment FROM comments WHERE pic='".intval($fetch1['id'])."' ORDER BY id ASC";
				$result = $connect->query($sql);
				$fetch3 = $result->fetchAll(PDO::FETCH_ASSOC);
				$fetch1['comments'] = $fetch3;
				$fetch1['end'] = true;

				$res = json_encode($fetch1);
				return ($res);
			}
			else {
				$res['end'] = false;
				$res['info'] = "Cette photo n'existe pas.";

				return (json_encode($res));
			}
		}
	}
?>
