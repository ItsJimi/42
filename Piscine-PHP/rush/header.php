<?php
	require_once("./include/include.php");
?>
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" href="fonts.css" charset="utf-8">
		<link rel="stylesheet" href="master.css" charset="utf-8">
		<title>AirPURe</title>
	</head>
	<body>
		<nav>
			<div class="container">
				<div class="left">
					AirPURe
				</div>
				<div class="right">
					<a href="index.php">Nouveautés</a>
					<?php
						$sql = "SELECT name FROM categories";
						$result = mysqli_query($connect, $sql);
						if ($result != false && mysqli_num_rows($result) > 0) {
							$categories = mysqli_fetch_all($result, MYSQLI_ASSOC);
							foreach ($categories as $value) {
								echo "<a href=\"shop.php?c=".$value['name']."\">".$value['name']."</a>";
							}
						}
					?>
				</div>
				<div class="clear"></div>
			</div>
		</nav>
		<div id="user">
			<div class="container">
				<div class="left">
					<?php if (is_connected()) { echo '<span>Bonjour, '.$_SESSION['mail'].'</span>'; } ?></span>
				</div>
				<div class="right">
				<?php
					if (!is_connected()) {
						echo '<a href="signin.php">Connexion</a>';
						echo '<a href="signup.php">Inscription</a>';
					} else {
						echo '<a href="cart.php">Panier ('.count($_SESSION['cart']).')</a>';
						echo '<a href="user.php">Mon compte</a>';
						echo '<a href="signout.php">Déconnexion</a>';
						if (is_admin()) {
							echo '<a href="admin/">Administration</a>';
						}
					}
				?>
				</div>
				<div class="clear"></div>
			</div>
		</div>
