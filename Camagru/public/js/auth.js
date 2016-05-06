is_connected();

function is_connected() {
	Z.post("model/auth.php", {
		request: "OK"
	}, function(logged) {
		// if (logged == 1) {
		// 	Z.id("signout_submit").style.display = "inline";
		// 	Z.id("signin_user").style.display = "none";
		// 	Z.id("signin_pass").style.display = "none";
		// 	Z.id("signin_submit").style.display = "none";
		// }
		// else {
		// 	Z.id("signout_submit").style.display = "none";
		// 	Z.id("signin_user").style.display = "inline";
		// 	Z.id("signin_pass").style.display = "inline";
		// 	Z.id("signin_submit").style.display = "inline";
		// }
	});
}
