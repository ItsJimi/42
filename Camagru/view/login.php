<?php
	echo $_POST['user']."<br>";
?>
<form action="index.php" method="post">
	<input type="text" name="user">
	<input type="password" name="pass">
	<input type="submit" name="submit" value="Connexion">
</form>
