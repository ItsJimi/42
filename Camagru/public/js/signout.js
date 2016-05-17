Z.id("signout_submit").addEventListener("click", signout);

function signout() {
	var signout_submit = Z.id("signout_submit").innerHTML;

	Z.post("model/signout.php", {
		signout_submit: signout_submit
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			//Z.id("login_bar").style.display = "none";
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			if (res.end == true) {
				Z.id("login_bar").style.display = "block";
				Z.id("member_bar").style.display = "none";
				Z.id("signin_user").value = "";
				Z.id("member_user").innerHTML = "";
				Z.id("member_mail").innerHTML = "";
				Z.id("member_hearts").innerHTML = "?";
				Z.id("member_followers").innerHTML = "?";
			}
		}
		else {
			Z.id("login_bar").style.display = "block";
			Z.id("member_bar").style.display = "none";
			Z.id("signin_user").value = "";
			Z.id("member_user").innerHTML = "";
			Z.id("member_mail").innerHTML = "";
			Z.id("member_hearts").innerHTML = "?";
			Z.id("member_followers").innerHTML = "?";
		}
	});
}
