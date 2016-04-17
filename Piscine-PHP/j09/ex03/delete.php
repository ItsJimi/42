<?php
	$id = htmlspecialchars($_POST['id']);

	if (file_exists("list.csv")) {
		$content = file_get_contents("list.csv");
		$content = explode(PHP_EOL, $content);
		foreach ($content as $key => $value) {
			$value = explode(";", $value);
			if ($value[0] == $id) {
				unset($content[$key]);
			}
		}
		$content = implode(PHP_EOL, $content);
		file_put_contents("list.csv", $content);
	}
?>
