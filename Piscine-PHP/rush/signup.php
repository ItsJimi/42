<?php
	require_once('./include/include.php');
	if (!is_connected()) {
		if(signup($_POST, $connect)) {
			header('Location: '.$_SESSION['current']);
		}
	}
	else
		header('Location: '.$_SESSION['current']);
	require_once("./header.php");
?>
<div id="body">
	<div id="title">Inscription</div>
	<div class="error">
		<center><?php echo $_SESSION['error']; ?></center>
	</div>
	<form action="signup.php" method="post">
		<div class="text">Adresse email :</div>
		<input type="email" name="mail" />
		<div class="text">Mot de passe :</div>
		<input type="password" name="password1" />
		<div class="text">Confirmer  :</div>
		<input type="password" name="password2" />
		<br /><br />
		<input id="button" type="submit" name="submit" value="Inscription">
	</form>
</div>
<?php
	include 'footer.php';
?>
