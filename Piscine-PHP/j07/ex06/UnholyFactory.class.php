<?php
class UnholyFactory {
	private $_crew;

	function absorb($obj) {
		if (!$obj instanceof Fighter) {
			print("(Factory can't absorb this, it's not a fighter)" . PHP_EOL);
			return ;
		}
		$string = $obj->str();
		if ($string && !$this->_crew || !array_key_exists($string, $this->_crew)) {
				print("(Factory absorbed a fighter of type ".$string.")" . PHP_EOL);
				$this->_crew[$string] = $obj;
		}
		else if ($obj instanceof Fighter) {
			foreach($this->_crew as $string => $obj) {
				if ($this->_crew[$string] = $obj)
					print("(Factory already absorbed a fighter of type ".$string.")" . PHP_EOL);
			}
		}
	}
	function fabricate($rf) {
		if (!array_key_exists($rf, $this->_crew)) {
			print("(Factory hasn't absorbed any fighter of type ".$rf.")" . PHP_EOL);
			return (NULL);
		}
		else {
			print("(Factory fabricates a fighter of type ".$rf.")" . PHP_EOL);
			return ($this->_crew[$rf]);
		}
	}
}
?>
