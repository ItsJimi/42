<?php
	require_once("./header.php");
	$_SESSION['current'] = "users.php";
?>
<?php
		if ($_GET['action'] === "finish" && !empty($_GET['uuid'])) {
			$sql = "DELETE FROM commands WHERE uuid=".$_GET['uuid'];
			if (mysqli_query($connect, $sql)) {
			    echo "La commande est validé";
			} else {
			    echo "Erreur: " . mysqli_error($connect);
			}
		}
		else {
?>
		<div class="title">
			<span>Toutes les commandes</span>
		</div>
		<div class="articles">
			<table>
				<tr>
					<td>Uuid Utilisateur</td>
					<td>Prix</td>
					<td>Achats</td>
					<td></td>
				</tr>
		<?php
			$sql = "SELECT * FROM commands";
			$result = mysqli_query($connect, $sql);
			if (mysqli_num_rows($result) > 0) {
				$user = mysqli_fetch_all($result, MYSQLI_ASSOC);
				foreach ($user as $value) {
					$tab = base64_decode($value['tab']);
					$tab = unserialize($tab);
					$name = "";
					foreach ($tab as $key => $value) {
						if ($tab[$key + 1])
							$name .= $value['name']." x ".$value['quantity'].", ";
						else
							$name .= $value['name']." x ".$value['quantity'];
					}
					echo "<tr>
						<td>".$value['uuid']."</td>
						<td>".$value['price']."</td>
						<td>".$name."</td>
						<td><a href=\"commands.php?action=finish&uuid='".$value['uuid']."'\"><div class=\"modif\">Valider</div></a></td>
					</tr>";
				}
			}
		}
	?>
	</table>
	</div>
</body>
</html>
