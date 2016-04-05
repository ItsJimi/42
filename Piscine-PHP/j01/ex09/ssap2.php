#!/usr/bin/php
<?php
	function ft_split($str) {
		$tab = explode(" ", $str);
		sort($tab);
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
	sort($tab2);
	foreach ($tab2 as $value) {
		echo $value."\n";
	}
?>
