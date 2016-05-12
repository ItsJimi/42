window.onkeydown = function(event) {
	if (event.keyCode === 13 && (Z.id("signup_user").selected || Z.id("signup_pass1").selected))
		signup();
}

if (Z.id("signup_submit"))
	Z.id("signup_submit").addEventListener("click", signup);

function signup() {
	var signup_user = Z.id("signup_user").value;
	var signup_mail = Z.id("signup_mail").value;
	var signup_pass1 = Z.id("signup_pass1").value;
	var signup_pass2 = Z.id("signup_pass2").value;
	var signup_submit = Z.id("signup_submit").innerHTML;
	Z.id("signup_pass1").value = "";
	Z.id("signup_pass2").value = "";

	Z.post("model/signup.php", {
		signup_user: signup_user,
		signup_mail: signup_mail,
		signup_pass1: signup_pass1,
		signup_pass2: signup_pass2,
		signup_submit: signup_submit
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			if (res.end == true) {
				Z.id("signup_user").value = "";
				Z.id("signup_mail").value = "";
			}
		}
	});
}
