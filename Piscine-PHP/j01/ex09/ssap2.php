#!/usr/bin/php
<?php
	function isalpha($str){
		$str = str_split(strtolower($str));
		foreach ($str as $char) {
			if (ord($char) < 97 || ord($char) > 122)
				return (false);
		}
		return (true);
	}
	function cmp($a, $b) {
		if (isalpha($a) && isalpha($b)) {
			if (strcmp($a, $b))
				return (-1);
			else
				return (1);
		}
		elseif (is_numeric($a) && is_numeric($b)) {
			if ($a > $b)
				return (-1);
			else
				return (1);
		}
		else
			return (0);
	}
	function ft_split($str) {
		$tab = explode(" ", $str);
		$tab = array_values(array_filter($tab));
		return ($tab);
	}
	$tab = $argv;
	unset($tab[0]);
	$tab = array_values($tab);
	$tab2 = array();
	foreach ($tab as $key => $value) {
		$tab2 = array_merge($tab2, ft_split($value));
	}
	usort($tab2, "cmp");
	foreach ($tab2 as $value) {
		echo $value."\n";
	}
?>
