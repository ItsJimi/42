<?php
	require_once("./header.php");
	$_SESSION['current'] = "shop.php?c=" . $_GET['c'];
?>
<div id="body">
	<div id="title">Boutique</div>
	<?php
		if (!empty($_GET['c'])) {
			$sql = "SELECT article FROM categories WHERE name='" . $_GET['c'] . "'";
			$result = mysqli_query($connect, $sql);
			if ($result !== false && mysqli_num_rows($result) > 0) {
				$articles = mysqli_fetch_assoc($result);
				$articles = explode(',', $articles['article']);
				foreach ($articles as $key => $value) {
					$sql = "SELECT name, img, description, price, stock, star FROM articles WHERE uuid='" . $value. "'";
					$result = mysqli_query($connect, $sql);
					if ($result != false && mysqli_num_rows($result) > 0) {
						$tmp = mysqli_fetch_all($result, MYSQLI_ASSOC);
						foreach($tmp as $article) {
							if ($article['stock'] <= 0)
								continue ;
						?>
							<div class="box">
								<div class="left">
									<img class="img" src="<?php echo htmlspecialchars($article['img']); ?>" />
								</div>
								<div class="right">
									<div class="name"><?php echo htmlspecialchars($article['name']); ?></div>
									<div class="price">
										Prix : <span><?php echo htmlspecialchars($article['price']); ?> &euro;</span>
									</div>
									<div class="stock">
										Stock : <span><?php echo htmlspecialchars($article['stock']); ?></span>
									</div>
									<a href="cart.php?action=add&uuid=<?php echo $value; ?>">
										<div class="buy">
											Ajouter au panier
										</div>
									</a>
								</div>
							</div>
							<div class="clear"></div>
							<p>
								<?php echo htmlspecialchars($article['description']); ?>
							</p>
						<?php
						}
					}
				}

				return ;
			}
		}
		$sql = "SELECT uuid, description, name, img, price, stock FROM articles";
		$result = mysqli_query($connect, $sql);
		if ($result !== false && mysqli_num_rows($result) > 0) {
			$article = mysqli_fetch_all($result, MYSQLI_ASSOC);
			foreach ($article as $value) {
				if ($value['stock'] <= 0)
					continue ;
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
				<p>
					<?php echo htmlspecialchars($value['description']); ?>
				</p>
			<?php
			}
		}

	?>
</div>
<?php
	include 'footer.php';
?>
