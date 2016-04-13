<?php
	class Jaime extends Lannister {
		public function sleepWith($name) {
			if (get_class($name) === 'Tyrion')
				print ('Not even if I\'m drunk !'.PHP_EOL);
			elseif (get_class($name) === 'Sansa')
				print ('Let\'s do this.'.PHP_EOL);
			elseif (get_class($name) === 'Cersei')
				print ('With pleasure, but only in a tower in Winterfell, then.'.PHP_EOL);
		}
	}
?>
