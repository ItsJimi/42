<?php
	if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] === "OK") {
		if (file_exists('../private') && file_exists('../private/passwd'))
		{
			$user = unserialize(file_get_contents('../private/passwd'));
			if ($user)
			{
				$error = true;
				foreach ($user as $key => $value) {
					if ($value['login'] === $_POST['login'] && $value['passwd'] === hash('whirlpool', $_POST['login'].$_POST['oldpw']))
					{
						$user[$key]['passwd'] = hash('whirlpool', $_POST['login'].$_POST['newpw']);
						$new_user = serialize($user);
						file_put_contents('../private/passwd', $new_user);
						echo "OK\n";
						$error = false;
					}
				}
				if ($error = true)
					echo "ERROR\n";
			}
			else
				echo "ERROR\n";
		}
		else
			echo "ERROR\n";
	}
	else
		echo "ERROR\n";
?>
