#!/usr/bin/php
<?php
	function ft_split($str) {
		$tab = explode(":", $str);
		$tab = array_values(array_filter($tab));
		return ($tab);
	}
	$tab = $argv;
	$key = $tab[1];
	unset($tab[0]);
	unset($tab[1]);
	$tab = array_values($tab);
	foreach ($tab as $i => $value) {
		$tab1[$i] = ft_split($value);
		if ($tab1[$i][0] === $key)
			$str = $tab1[$i][1];
	}
	echo $str."\n";
?>
