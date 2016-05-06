Z.id("signout_submit").addEventListener("click", signout);

function signout() {
	var signout_submit = Z.id("signout_submit").innerHTML;

	Z.post("model/logout.php", {
		signout_submit: signout_submit
	}, function(response) {
		if (response != 0)
			Z.id("info").innerHTML = response;
	});
}
