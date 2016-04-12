<?php
	class Color {
		static $verbose = false;
		public $red = 0;
		public $green = 0;
		public $blue = 0;

		public function __contruct(array $kwargs) {

			if (array_key_exists('rgb', $kwargs)) {
				$this->$red = intval($kwargs['rgb'][0]);
				$this->$green = intval($kwargs['rgb'][1]);
				$this->$blue = intval($kwargs['rgb'][2]);
			}
			elseif(array_key_exists('red', $kwargs) && array_key_exists('green', $kwargs) && array_key_exists('blue', $kwargs)) {
				$this->$red = intval($kwargs['red']);
				$this->$green = intval($kwargs['green']);
				$this->$blue = intval($kwargs['blue']);
			}
			return;
		}
	}
?>
