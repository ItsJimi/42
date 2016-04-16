<?php
	require_once("./header.php");
	$_SESSION['current'] = "users.php";
?>
<?php
	if ($_GET['action'] === "add") {
		if (empty($_POST['mail']) || empty($_POST['password'])) {
		?>
			<form action="users.php?action=add" method="POST">
				<label for="mail">Email :</label><br />
				<input type="email" name="mail" /><br />
				<label for="password">Mot de passe :</label><br />
				<input type="password" name="password" /><br />
				<label for="rank">Rang :</label><br />
				<input type="text" name="rank" /><br />
				<hr />
				<input type="submit" name="submit" value="Créer" />
			</form>
		<?php
		}
		else {
			$sql = "INSERT INTO users (uuid, mail, password, rank, create_at, accesstoken)
			VALUES ('".uuid()."', '".htmlspecialchars($_POST['mail'])."', '".pass_hash($_POST['mail'], $_POST['password'])."', ".htmlspecialchars($_POST['rank']).", NOW(), NULL)";

			if (mysqli_query($connect, $sql)) {
			    echo "L'utilisateur a été ajouté";
			}
			else {
			    echo "Erreur: ".$sql."<br />".mysqli_error($connect);
			}
		}
	}
	elseif ($_GET['action'] === "del" && $_GET['uuid']) {
		$sql = "DELETE FROM users WHERE uuid=".$_GET['uuid'];
		if (mysqli_query($connect, $sql)) {
		    echo "L'utilisateur a été suprimmé";
		} else {
		    echo "Erreur: " . mysqli_error($connect);
		}
	}
	elseif ($_GET['action'] === "modif" && $_GET['uuid']) {
		if ($_POST['submit'] === "Modifier" && !empty($_POST['password'])) {
			$sql = "UPDATE users SET mail='".htmlspecialchars($_POST['mail'])."',password='".htmlspecialchars($_POST[''])."',rank='".htmlspecialchars($_POST['rank'])."' WHERE uuid='".$_GET['uuid']."'";

			if (mysqli_query($connect, $sql)) {
			    echo "L'article a été modifié";
			} else {
			    echo "Erreur: " . mysqli_error($connect);
			}
		}
		elseif ($_POST['submit'] === "Modifier" && empty($_POST['password'])) {
			$sql = "UPDATE users SET mail='".htmlspecialchars($_POST['mail'])."',rank='".htmlspecialchars($_POST['rank'])."' WHERE uuid='".$_GET['uuid']."'";

			if (mysqli_query($connect, $sql)) {
			    echo "L'article a été modifié";
			} else {
			    echo "Erreur: " . mysqli_error($connect);
			}
		}
		else {
			$sql = "SELECT uuid, mail, password, rank FROM users WHERE uuid=".$_GET['uuid'];
			$result = mysqli_query($connect, $sql);
			// ici result vaut false j'arrive pas a savoir pk
			if ($result !== FALSE && mysqli_num_rows($result) > 0) {
				$result = mysqli_fetch_assoc($result);
				echo "<br />";
				?>
					<form action="users.php?action=modif&uuid=<?php echo $result['uuid']; ?>" method="POST">
						<label for="mail">Email :</label><br />
						<input type="email" name="mail" value="<?php echo $result['mail']; ?>" /><br />
						<label for="password">Mot de passe :</label><br />
						<input type="password" name="password" /><br />
						<label for="rank">Rang :</label><br />
						<input type="text" name="rank" value="<?php echo $result['rank']; ?>" /><br />
						<hr />
						<input type="submit" name="submit" value="Modifier" />
					</form>
				<?php
			}
			else {
				echo mysql_error();
			}
		}
	}
	else {
	?>
		<div class="title">
			<span>Tous les utilisateurs</span>
			<a href="users.php?action=add"><div class="add">Ajouter un utlisateur</div></a>
		</div>
		<div class="articles">
			<table>
				<tr>
					<td>Uuid</td>
					<td>Email</td>
					<td>Rang</td>
					<td>Création</td>
					<td>Token</td>
					<td></td>
					<td></td>
				</tr>
		<?php
			$sql = "SELECT uuid, mail, rank, create_at, accesstoken FROM users";
			$result = mysqli_query($connect, $sql);
			if (mysqli_num_rows($result) > 0) {
				$user = mysqli_fetch_all($result, MYSQLI_ASSOC);
				foreach ($user as $value) {
					echo "<tr>
						<td>".$value['uuid']."</td>
						<td>".$value['mail']."</td>
						<td>".$value['rank']."</td>
						<td>".$value['create_at']."</td>
						<td>".$value['accesstoken']."</td>
						<td><a href=\"users.php?action=modif&uuid='".$value['uuid']."'\"><div class=\"modif\">Modifier</div></a></td>
						<td><a href=\"users.php?action=del&uuid='".$value['uuid']."'\"><div class=\"del\">Supprimer</div></a></td>
					</tr>";
				}
			}
	}
	?>
	</table>
	</div>
</body>
</html>
