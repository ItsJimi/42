<?php
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	if ($_SERVER['PHP_AUTH_USER'] === "zaz" && $_SERVER['PHP_AUTH_PW'] === "jaimelespetitsponeys")
	{
		echo "<html><body>\nBonjourZaz<br />\n";
		echo "<img src='data:image/png;base64,".base64_encode(file_get_contents("../img/42.png"))."'>\n";
		echo "</body></html>\n";
	}
	else
		echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
?>
