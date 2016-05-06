<?php
	require_once("./header.php");
	$_SESSION['current'] = "index.php";
?>
<div id="slogan">
	<div class="container">
		CHANGEZ D'AIR !
		<a href="shop.php">
			<div class="button">
				Parcourir la boutique
			</div>
		</a>
	</div>
</div>
<div id="body">
	<div id="title">Nouveautés</div>
	<?php
		$sql = "SELECT uuid, name, img, price, stock FROM articles LIMIT 3";
		$result = mysqli_query($connect, $sql);
		if ($result != false && mysqli_num_rows($result) > 0) {
			$article = mysqli_fetch_all($result, MYSQLI_ASSOC);
			foreach ($article as $value) {
			?>
				<div class="box">
					<div class="left">
						<img class="img" src="<?php echo $value['img']; ?>" />
					</div>
					<div class="right">
						<div class="name"><?php echo htmlspecialchars($value['name']); ?></div>
						<div class="price">
							Prix : <span><?php echo htmlspecialchars($value['price']); ?> &euro;</span>
						</div>
						<div class="stock">
							Stock : <span><?php echo htmlspecialchars($value['stock']); ?></span>
						</div>
						<a href="cart.php?action=add&uuid=<?php echo $value['uuid']; ?>">
							<div class="buy">
								Ajouter au panier
							</div>
						</a>
					</div>
				</div>
				<div class="clear"></div>
			<?php
			}
		}
	?>
</div>
<?php
	include 'footer.php';
?>
