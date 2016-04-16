<?php
	require_once('./include/include.php');
	if (is_connected()) {
		if(modif($_POST, $connect)) {
			header('Location: '.$_SESSION['current']);
		}
	}
	else
		header('Location: signin.php');
	require_once("./header.php");
?>
<div id="body">
	<div id="title">Modification du compte</div>
	<div class="error">
		<center><?php echo $_SESSION['error']; ?></center>
	</div>
	<form action="user.php" method="post">
		<div class="text">Adresse email :</div>
		<input type="email" name="mail" value="<?php echo htmlspecialchars($_SESSION['mail']); ?>" />
		<div class="text">Mot de passe :</div>
		<input type="password" name="password1" value="" />
		<div class="text">Confirmer  :</div>
		<input type="password" name="password2" value="" />
		<br /><br />
		<input id="button" type="submit" name="submit" value="Inscription">
	</form>
</div>
<?php
	include 'footer.php';
?>
