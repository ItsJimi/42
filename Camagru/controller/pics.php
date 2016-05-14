<?php
	// Pics
	function pics($nbr, $connect) {
		$sql = "SELECT * FROM pics ORDER BY id DESC LIMIT 5 OFFSET ".$nbr;
		$result = $connect->query($sql);
		$fetch = $result->fetchAll(PDO::FETCH_ASSOC);
		$res = json_encode($fetch);
		return ($res);
	}
?>
