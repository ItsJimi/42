#!/usr/bin/php
<?php
	$month = array("Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre");

	$tab = explode(" ", $argv[1]);
	$tab1 = explode(":", $tab[4]);

	$final["day"] = $tab[1];
	$final["month"] = $tab[1];
	$final["year"] = $tab[3];
	$final["hour"] = $tab1[0];
	$final["minute"] = $tab1[1];
	$final["second"] = $tab1[2];

	$tab = date_parse($argv[1]);
	print_r($tab);
	print_r($final);
	print_r($month);
?>
