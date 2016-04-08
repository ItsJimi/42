<?php
	function auth($login, $passwd) {
		if (file_exists('../private') && file_exists('../private/passwd'))
		{
			$user = unserialize(file_get_contents('../private/passwd'));
			if ($user)
			{
				foreach ($user as $value) {
					if ($value['login'] === $login && $value['passwd'] === hash('whirlpool', $login.$passwd))
						return (true);
				}
			}
		}
		return (false);
	}
?>
