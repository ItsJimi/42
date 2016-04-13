<?php
	class NightsWatch {
		protected $_members = array();

		function recruit($name) {
			if ($name instanceof IFighter)
				array_push($this->_members, $name);
		}
		function fight() {
			foreach ($this->_members as $name) {
				$name->fight();
			}
		}
	}
?>
