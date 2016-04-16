<?php
	$id = htmlspecialchars($_POST['id']);
	$content = htmlspecialchars($_POST['content']);
	file_put_contents("list.csv", $id.";".$content.PHP_EOL, FILE_APPEND);
?>
