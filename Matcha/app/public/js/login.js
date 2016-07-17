$(document).ready(function() {
    $("#signin_submit").click(function() {
        signin($("#signin_username").val(), $("#signin_pass").val());
    });
	$("#signup_submit").click(function() {
        signup($("#signup_username").val(),
			$("#signup_firstname").val(),
			$("#signup_lastname").val(),
			$("#signup_mail").val(),
			$("#signup_pass1").val(),
			$("#signup_pass2").val());
    });
});

function signin(username, pass) {
	if (username === "" || pass === "") {
		info({
			request: false,
			message: "Fields empty."
		});
		return (false);
	}
	$.post("/login/signin", {
		username: username,
        pass: pass
    }, function(res) {
		info(res);
		if (res.request)
			window.location = "/";
    });
}
function signup(username, firstname, lastname, mail, pass1, pass2) {
	if (username === "" || firstname === "" || lastname === "" || mail === "" || pass1 === "" || pass2 === "") {
		info({
			request: false,
			message: "Fields empty."
		});
		return (false);
	}
	$.post("/login/signup", {
		username: username,
		firstname: firstname,
		lastname: lastname,
		mail: mail,
		pass1: pass1,
		pass2: pass2
    }, function(res) {
		info(res);
    });
}
