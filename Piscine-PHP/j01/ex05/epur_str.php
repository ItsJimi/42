#!/usr/bin/php
<?php
	function ft_split($str) {
		$tab = explode(" ", $str);
		sort($tab);
		$tab = array_values(array_filter($tab));
		return ($tab);
	}
	$str = trim($argv[1]);
	$str = ft_split($str);
	$nbr = count($str);
	foreach ($str as $key => $value) {
		echo $value;
		if ($key != $nbr - 1)
			echo " ";
	}
?>
