window.onkeydown = function(event) {
	if (event.keyCode === 13 && (Z.id("signin_user").selected || Z.id("signin_pass").selected))
		signin();
}

if (Z.id("signin_submit"))
	Z.id("signin_submit").addEventListener("click", signin);

function signin() {
	var signin_user = Z.id("signin_user").value;
	var signin_pass = Z.id("signin_pass").value;
	var signin_submit = Z.id("signin_submit").innerHTML;
	Z.id("signin_pass").value = "";

	Z.post("model/signin.php", {
		signin_user: signin_user,
		signin_pass: signin_pass,
		signin_submit: signin_submit
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			if (res.end == true) {
				Z.id("login_bar").style.display = "none";
				Z.id("member_bar").style.display = "block";
			}
		}
	});
}
