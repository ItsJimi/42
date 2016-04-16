<?php
	require_once('./include/include.php');
	if (!is_connected()) {
		if(signin($_POST, $connect)) {
			header('Location: '.$_SESSION['current']);
		}
	}
	else
		header('Location: '.$_SESSION['current']);
	require_once("./header.php");
?>
<div id="body">
	<div id="title">Connexion</div>
	<div class="error">
		<center><?php echo $_SESSION['error']; ?></center>
	</div>
	<form action="signin.php" method="post">
		<div class="text">Adresse email :</div>
		<input type="email" name="mail" />
		<div class="text">Mot de passe :</div>
		<input type="password" name="password" />
		<br /><br />
		<input class="button" type="submit" name="submit" value="Connexion">
	</form>
</div>
<?php
	include 'footer.php';
?>
