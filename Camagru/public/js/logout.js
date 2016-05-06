Z.id("signout_submit").addEventListener("click", signout);

function signout() {
	var signout_submit = Z.id("signout_submit").innerHTML;

	Z.post("model/logout.php", {
		signout_submit: signout_submit
	}, function(response) {
		Z.l(response, "red");
	});
}
