#!/usr/bin/php
<?php
	function ft_split($str) {
		$tab = explode(" ", $str);
		$tab = array_values(array_filter($tab));
		return ($tab);
	}
	$str = ft_split($argv[1]);
	foreach ($str as $key => $value) {
		if ($key != 0)
			echo $value." ";
	}
	echo $str[0]."\n";
?>
