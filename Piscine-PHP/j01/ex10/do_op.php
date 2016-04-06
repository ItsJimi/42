#!/usr/bin/php
<?php
	if ($argc == 4)
	{
		if (strpos($argv[2], "+") !== false) {
			$result = $argv[1] + $argv[3];
		}
		elseif (strpos($argv[2], "-") !== false) {
			$result = $argv[1] - $argv[3];
		}
		elseif (strpos($argv[2], "/") !== false) {
			$result = $argv[1] / $argv[3];
		}
		elseif (strpos($argv[2], "%") !== false) {
			$result = $argv[1] % $argv[3];
		}
		else {
			$result = $argv[1] * $argv[3];
		}
		echo $result."\n";
	}
	else
		echo "Incorrect Parameters\n";
?>
