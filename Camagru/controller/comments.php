<?php
	function comments($post, $connect) {
		if (isset($post['comment']) && $post['comment'] !== "") {
			$sql = $connect->prepare('INSERT INTO comments (pic, comment, user) VALUES (:pic, :comment, :user)');
			$sql->execute(array(
				'pic' => intval($post['id']),
				'comment' => htmlspecialchars($post['comment']),
				'user' => htmlspecialchars($_SESSION['user'])
			));

			$sql = "SELECT user FROM pics WHERE id='".intval($post['id'])."'";
			$result = $connect->query($sql);
			if ($result->rowCount() > 0) {
				$user = $result->fetch();
				$sql = "SELECT user, mail FROM users WHERE user='".htmlspecialchars($user['user'])."'";
				$result = $connect->query($sql);
				if ($result->rowCount() > 0) {
					$user = $result->fetch();
					if ($user['user'] !== $_SESSION['user']) {
						$to = $user['mail'];
						$subject = '[InstaPics] Nouveau commentaire';
						$message = "Bonjour ".htmlspecialchars($user['user']).",\n".htmlspecialchars($_SESSION['user'])." a posté \"".$post['comment']."\" sur votre photo.";
						$headers = 'From: comments@instapics.fr';

						mail($to, $subject, $message, $headers);
					}
				}
			}

			$res['end'] = true;
			$res['info'] = "Un commentaire été posté.";

			return (json_encode($res));
		}
		else {
			$res['end'] = false;
			$res['info'] = "Un commentaire ne peut pas être vide.";
			return (json_encode($res));
		}
	}
?>
