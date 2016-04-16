<?php
	require_once("./header.php");
	$_SESSION['current'] = "index.php";
?>
<?php
	if ($_GET['action'] === "add") {
		if (empty($_POST['name']) || empty($_POST['description']) || empty($_POST['img']) || empty($_POST['price']) || empty($_POST['stock'])) {
		?>
			<form action="index.php?action=add" method="POST">
				<label for="name">Nom :</label><br />
				<input type="text" name="name" /><br />
				<label for="name">Description :</label><br />
				<textarea name="description">
				</textarea><br />
				<label for="name">Image :</label><br />
				<input type="text" name="img" /><br />
				<label for="price">Prix :</label><br />
				<input type="text" name="price" /><br />
				<label for="name">Quantité :</label><br />
				<input type="number" name="stock" min="1" max="100000" /><br />
				<hr />
				<input type="submit" name="submit" value="Créer" />
			</form>
		<?php
		}
		else {
			$name = str_replace("'", "''", $_POST['name']);
			$description = str_replace("'", "''", $_POST['description']);
			$sql = "INSERT INTO articles (uuid, name, description, img, price, stock, star)
			VALUES ('".uuid()."', '".htmlspecialchars($name)."', '".htmlspecialchars($description)."', '".htmlspecialchars($_POST['img'])."', ".htmlspecialchars($_POST['price']).", ".htmlspecialchars($_POST['stock']).",0)";

			if (mysqli_query($connect, $sql)) {
			    echo "L'article a été ajouté";
			}
			else {
			    echo "Erreur: ".$sql."<br />".mysqli_error($connect);
			}
		}
	}
	elseif ($_GET['action'] === "del" && $_GET['uuid']) {
		$sql = "DELETE FROM articles WHERE uuid=".$_GET['uuid'];
		if (mysqli_query($connect, $sql)) {
		    echo "L'article a été suprimmé";
		} else {
		    echo "Erreur: " . mysqli_error($connect);
		}
	}
	elseif ($_GET['action'] === "modif" && $_GET['uuid']) {
		if ($_POST['submit'] === "Créer") {
			$name = str_replace("'", "''", $_POST['name']);
			$description = str_replace("'", "''", $_POST['description']);
			$sql = "UPDATE articles SET name='". htmlspecialchars($name)."',description='".htmlspecialchars($description)."',img='".htmlspecialchars($_POST['img'])."',price='".htmlspecialchars($_POST['price'])."',stock='".htmlspecialchars($_POST['stock']). "' WHERE uuid='". htmlspecialchars($_GET['uuid']) . "';";

			if (mysqli_query($connect, $sql)) {
			    echo "L'article a été modifié";
			} else {
			    echo "Erreur: " . mysqli_error($connect);
			}
		}
		else {
			$sql = "SELECT uuid, name, description, img, price, stock, star FROM articles WHERE uuid=".$_GET['uuid'];
			$result = mysqli_query($connect, $sql);
			// ici result vaut false j'arrive pas a savoir pk
			if ($result !== FALSE && mysqli_num_rows($result) > 0) {
				$result = mysqli_fetch_assoc($result);
				echo "<br />";
				?>
					<form action="index.php?action=modif&uuid=<?php echo $result['uuid']; ?>" method="POST">
						<label for="name">Nom :</label><br />
						<input type="text" name="name" value="<?php echo $result['name']; ?>" /><br />
						<label for="name">Description :</label><br />
						<textarea name="description"><?php echo $result['description']; ?></textarea><br />
						<label for="name">Image :</label><br />
						<input type="text" name="img" value="<?php echo $result['img']; ?>" /><br />
						<label for="name">Prix :</label><br />
						<input type="text" name="price" value="<?php echo $result['price']; ?>" /><br />
						<label for="name">Quantité :</label><br />
						<input type="text" name="stock" value="<?php echo $result['stock']; ?>" /><br />
						<hr />
						<input type="submit" name="submit" value="Créer" />
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
			<span>Tous les articles</span>
			<a href="index.php?action=add"><div class="add">Ajouter un article</div></a>
		</div>
		<div class="articles">
			<table>
				<tr>
					<td>Image</td>
					<td>Nom</td>
					<td>Description</td>
					<td>Prix</td>
					<td>Quantité</td>
					<td>Note</td>
					<td></td>
					<td></td>
				</tr>
		<?php
			$sql = "SELECT uuid, name, description, img, price, stock, star FROM articles";
			$result = mysqli_query($connect, $sql);
			if (mysqli_num_rows($result) > 0) {
				$article = mysqli_fetch_all($result, MYSQLI_ASSOC);
				foreach ($article as $value) {
					echo "<tr>
						<td><img src=\"".$value['img']."\" /></td>
						<td>".$value['name']."</td>
						<td>".$value['description']."</td>
						<td>".$value['price']."</td>
						<td>".$value['stock']."</td>
						<td>".$value['star']."</td>
						<td><a href=\"index.php?action=modif&uuid='".$value['uuid']."'\"><div class=\"modif\">Modifier</div></a></td>
						<td><a href=\"index.php?action=del&uuid='".$value['uuid']."'\"><div class=\"del\">Supprimer</div></a></td>
					</tr>";
				}
			}
	}
	?>
	</table>
	</div>
</body>
</html>
