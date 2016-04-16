<?PHP
	include("./include/include.php");
	if (count($_SESSION['cart']) > 0) {

		$cart = $_SESSION['cart'];
		$uuid = $_SESSION['uuid'];
		if ($uuid == null) {
			header("Location: signin.php");
			return ;
		}
		include 'header.php';
		$price = 0;
		foreach($_SESSION['cart'] as $key => $value) {
			$price = $price + ($value['price'] * $value['quantity']);
			$new_stock = ($value['stock'] - $value['quantity']);
			$sql = 'UPDATE articles SET stock='.$new_stock.' WHERE uuid="'.$value['uuid'].'"';
			if (mysqli_query($connect, $sql)) {
			    echo "";
			}
		}

		$sql = "INSERT INTO commands (uuid, tab, price) VALUES ('" . $uuid . "', '" . base64_encode(serialize($cart)) . "','" . $price . "')";
		if (mysqli_query($connect, $sql)) {
		?>
			<div id="body">
				<div id="title">Commande</div>
				<center>Votre commande a bien été enregistré.</center>
		<?php
			unset($_SESSION['cart']);
		}
		else {
		    echo "Erreur: ".$sql."<br />".mysqli_error($connect);
		}

	}
?>
</div>
<?php
	include 'footer.php';
?>
