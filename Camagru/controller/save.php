<?php
	// Save Pic
	function save($pic, $filter, $connect) {
		$pic = explode(",", $pic);
		if($pic = base64_decode($pic[1])) {
			$pic = imagecreatefromstring($pic);
			if (file_exists("../public/img/".$filter))
				$filter = imagecreatefrompng("../public/img/".$filter);
			else {
				$res['end'] = false;
				$res['info'] = "Le filtre n'existe pas.";
				$res = json_encode($res);
				return($res);
			}
			imagecopy($pic, $filter, 0, 0, 0, 0, 640, 480);

			ob_start();
			imagepng($pic);
			// read from buffer
			$final_pic = ob_get_contents();
			// delete buffer
			ob_end_clean();
			$sql = $connect->prepare('INSERT INTO pics (user, pic) VALUES (:user, :pic)');
			$sql->execute(array(
				'user' => htmlspecialchars($_SESSION['user']),
				'pic' => "data:image/png;base64,".base64_encode($final_pic)
			));
			$res['end'] = true;
			$res['info'] = "Votre photo a été envoyée ! ;)";
			$res = json_encode($res);
			return($res);
		}
		else {
			$res['end'] = false;
			$res['info'] = "Votre photo n'est pas valide ! :(";
			$res = json_encode($res);
			return($res);
		}
	}
?>
