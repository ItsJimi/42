<?php
	require_once("controller/include.php");
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Réinitialisation du mot de passe</title>
	</head>
	<body>
	<?php
		if (isset($_GET['m']) && isset($_GET['c']) && !empty($_GET['m']) && !empty($_GET['c'])) {
			if ($_GET['c'] === "no") {
				$sql = "DELETE FROM codes WHERE mail='".htmlspecialchars($_GET['m'])."'";
				$result = $connect->query($sql);
				echo "La demande de réinitialisation a été annulée.";
			}
			else {
				$sql = "SELECT mail, code FROM codes WHERE mail='".htmlspecialchars($_GET['m'])."' AND code='".htmlspecialchars($_GET['c'])."'";
				$result = $connect->query($sql);
				if ($result->rowCount() > 0) {
					if (isset($_POST['password1']) && isset($_POST['password2']) && !empty($_POST['password1']) && !empty($_POST['password2']) && $_POST['submit'] === "Valider") {
						if (strlen($_POST['password1']) >= 6) {
							if ($_POST['password1'] === $_POST['password2']) {
								$sql = "SELECT user, mail FROM users WHERE mail='".htmlspecialchars($_GET['m'])."'";
								$result = $connect->query($sql);
								if ($result->rowCount() > 0) {
									$user = $result->fetch();
									$sql = $connect->prepare('UPDATE users SET password = :password WHERE mail = :mail');
									$sql->execute(array(
										'password' => pass_hash($user['user'], $_POST['password1']),
										'mail' => $_GET['m']
									));

									$sql = "DELETE FROM codes WHERE mail='".htmlspecialchars($_GET['m'])."'";
									$result = $connect->query($sql);
									echo "Votre mot de passe a été réinitialisé.";
								}
							}
							else {
							?>
								Les mots de passe ne correspondent pas.<br />
								Veuillez entrer votre nouveau mot de passe :
								<form action="reset.php?m=<?php echo htmlspecialchars($_GET['m']); ?>&c=<?php echo htmlspecialchars($_GET['c']); ?>" method="post">
									<input type="password" name="password1" placeholder="Mot de passe">
									<input type="password" name="password2" placeholder="Confirmation">
									<input type="submit" name="submit" value="Valider">
								</form>
							<?php
							}
						}
						else {
						?>
							Le mot de passe doit contenir au moins 6 caractères.<br />
							Veuillez entrer votre nouveau mot de passe :
							<form action="reset.php?m=<?php echo htmlspecialchars($_GET['m']); ?>&c=<?php echo htmlspecialchars($_GET['c']); ?>" method="post">
								<input type="password" name="password1" placeholder="Mot de passe">
								<input type="password" name="password2" placeholder="Confirmation">
								<input type="submit" name="submit" value="Valider">
							</form>
						<?php
						}
					}
					else {
					?>
						Veuillez entrer votre nouveau mot de passe :
						<form action="reset.php?m=<?php echo htmlspecialchars($_GET['m']); ?>&c=<?php echo htmlspecialchars($_GET['c']); ?>" method="post">
							<input type="password" name="password1" placeholder="Mot de passe">
							<input type="password" name="password2" placeholder="Confirmation">
							<input type="submit" name="submit" value="Valider">
						</form>
					<?php
					}
				}
				else {
					echo "Le lien n'est pas valide.";
				}
			}
		}
		else {
			echo "Le lien n'est pas valide.";
		}
	?>
	</body>
</html>
