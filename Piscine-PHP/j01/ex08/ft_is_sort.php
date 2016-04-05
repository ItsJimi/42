#!/usr/bin/php
<?php
	function ft_is_sort($tab) {
		$str = $tab;
		sort($tab);
		return ($tab === $str);
	}
?>
