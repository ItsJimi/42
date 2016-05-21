<?php
	function like($post, $connect) {
		if(isset($post['id'])) {
			$sql = "SELECT pic, user FROM likes WHERE pic='".intval($post['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
			$result = $connect->query($sql);
			if ($result->fetch()) {
				$sql = "DELETE FROM likes WHERE pic='".intval($post['id'])."' AND user='".htmlspecialchars($_SESSION['user'])."'";
				$result = $connect->query($sql);

				$res['end'] = true;
				$res['info'] = "Vous venez de unlike une photo !";
				$res['islike'] = 0;

				return (json_encode($res));
			}
			else {
				$sql = "SELECT user FROM pics WHERE id='".intval($post['id'])."'";
				$result = $connect->query($sql);
				$fetch = $result->fetch(PDO::FETCH_ASSOC);

				$sql = $connect->prepare('INSERT INTO likes (pic, user, pic_user) VALUES (:pic, :user, :pic_user)');
				$sql->execute(array(
					'pic' => intval($post['id']),
					'user' => htmlspecialchars($_SESSION['user']),
					'pic_user' => htmlspecialchars($fetch['user'])
				));
				$res['end'] = true;
				$res['info'] = "Vous venez de like une photo !";
				$res['islike'] = 1;

				return (json_encode($res));
			}
		}
	}
?>
