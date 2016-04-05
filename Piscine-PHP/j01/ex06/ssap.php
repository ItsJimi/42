#!/usr/bin/php
<?php
	function ft_split($str) {
		$tab = explode(" ", $str);
		sort($tab);
		$tab = array_values(array_filter($tab));
		return ($tab);
	}
	$tab = $argv;
	sort($tab);
	print_r($tab);
?>
