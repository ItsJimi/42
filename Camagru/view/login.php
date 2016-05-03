<?php
	echo $_POST['user']."<br>";
	echo pass_hash($_POST['user'], $_POST['pass']);
?>
<form action="index.php?p=login" method="post">
	<input type="text" name="user">
	<input type="password" name="pass">
	<input type="submit" name="submit" value="Connexion">
</form>
