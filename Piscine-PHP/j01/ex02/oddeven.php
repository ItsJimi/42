#!/usr/bin/php
<?php
	while (1)
	{
		echo "Entrez un nombre: ";
		$nbr = fgets(STDIN);
		$nbr = substr($nbr, 0, -1);
		if (feof(STDIN))
		{
			echo "\n";
			exit (0);
		}
		if (is_numeric($nbr) && $nbr % 2 == 0)
			echo "Le chiffre ".$nbr." est Pair\n";
		elseif (is_numeric($nbr) && $nbr % 2 != 0)
			echo "Le chiffre ".$nbr." est Impair\n";
		else
			echo "'".$nbr."' n'est pas un chiffre\n";
	}
?>
