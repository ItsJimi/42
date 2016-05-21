Z.id("info").style.display = "none";
Z.id("login_bar").style.display = "none";
Z.id("member_bar").style.display = "none";

var logged = false;

if (Z.id("info_cross"))
	Z.id("info_cross").addEventListener("click", hide_info);

window.addEventListener("DOMContentLoaded", function() {
	Z.post("model/auth.php", {
		request: "OK"
	}, function(res) {
		res = JSON.parse(res);
		if (res.logged == true) {
			logged = true;
			Z.id("login_bar").style.display = "none";
			Z.id("member_bar").style.display = "block";
			Z.id("member_user").innerHTML = res.user;
			Z.id("member_mail").innerHTML = res.mail;
			Z.id("member_hearts").innerHTML = res.hearts;
		}
		else {
			logged = false;
			Z.id("login_bar").style.display = "block";
			Z.id("member_bar").style.display = "none";
			Z.id("member_user").innerHTML = "";
			Z.id("member_mail").innerHTML = "";
			Z.id("member_hearts").innerHTML = "?";
		}
	});
});

function hide_info() {
	Z.id("info").style.display = "none";
}
