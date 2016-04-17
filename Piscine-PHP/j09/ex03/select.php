<?php
	if (file_exists("list.csv")) {
		$all = array();
		$content = file_get_contents("list.csv");
		$content = explode(PHP_EOL, $content);
		$content = array_filter($content);
		foreach ($content as $key => $value) {
			$value = explode(";", $value);
			array_push($all, $value);
		}
		echo json_encode($all);
	}
?>
