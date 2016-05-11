Z.id("info").style.display = "none";
Z.id("login_bar").style.display = "none";
Z.id("member_bar").style.display = "none";

if (Z.id("info_cross"))
	Z.id("info_cross").addEventListener("click", hide_info);

is_connected();

function hide_info() {
	Z.id("info").style.display = "none";
}

function is_connected() {
	Z.post("model/auth.php", {
		request: "OK"
	}, function(res) {
		res = JSON.parse(res);
		if (res.logged == true) {
			Z.id("login_bar").style.display = "none";
			Z.id("member_bar").style.display = "block";
			Z.id("member_user").innerHTML = res.user;
			Z.id("member_mail").innerHTML = res.mail;
		}
		else {
			Z.id("login_bar").style.display = "block";
			Z.id("member_bar").style.display = "none";
			Z.id("member_user").innerHTML = "";
			Z.id("member_mail").innerHTML = "";
		}
	});
}
