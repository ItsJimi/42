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

	Z.l(signin_user + " : " + signin_pass + " : " + signin_submit, "blue");
	Z.post("model/login.php", {
		signin_user: signin_user,
		signin_pass: signin_pass,
		signin_submit: signin_submit
	}, function(response) {
		Z.id("info").innerHTML = response;
	});
}
