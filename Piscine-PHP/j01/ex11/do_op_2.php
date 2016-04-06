#!/usr/bin/php
<?php
	function ft_split($str, $operator) {
		$tab = explode($operator, $str);
		$tab = array_values(array_filter($tab));
		if (is_numeric(trim($tab[0])) && is_numeric(trim($tab[1])))
			return ($tab);
		echo "Syntax Error\n";
		exit (-1);
	}
	if ($argc == 2)
	{
		if (strpos($argv[1], "+") !== false) {
			$str = ft_split($argv[1], "+");
			$result = $str[0] + $str[1];
		}
		elseif (strpos($argv[1], "-") !== false) {
			$str = ft_split($argv[1], "-");
			$result = $str[0] - $str[1];
		}
		elseif (strpos($argv[1], "*") !== false) {
			$str = ft_split($argv[1], "*");
			$result = $str[0] * $str[1];
		}
		elseif (strpos($argv[1], "/") !== false) {
			$str = ft_split($argv[1], "/");
			$result = $str[0] / $str[1];
		}
		elseif (strpos($argv[1], "%") !== false) {
			$str = ft_split($argv[1], "%");
			$result = $str[0] % $str[1];
		}
		else {
			$error = true;
		}
		if ($error != true)
			echo $result."\n";
		else
			echo "Syntax Error\n";
	}
	else
		echo "Incorrect Parameters\n";
?>
