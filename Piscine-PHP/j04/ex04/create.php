<?php
	header('Location: index.html');
	if ($_POST['login'] && $_POST['passwd'] && $_POST['submit'] === "OK") {
		if (!file_exists('../private'))
			mkdir('../private');
		$error = 0;
		$i = -1;
		if (file_exists('../private/passwd'))
		{
			$user = unserialize(file_get_contents('../private/passwd'));
			if ($user)
			{
				foreach ($user as $key => $value) {
					if ($value['login'] === $_POST['login'])
						$error = 1;
					$i = $key;
				}
			}
		}
		if ($error == 0)
		{
			$user[$i + 1]['login'] = $_POST['login'];
			$user[$i + 1]['passwd'] = hash('whirlpool', $_POST['login'].$_POST['passwd']);
			$new_user = serialize($user);
			file_put_contents('../private/passwd', $new_user);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
	else
		echo "ERROR\n";
?>
