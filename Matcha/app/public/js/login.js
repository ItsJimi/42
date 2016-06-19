$(document).ready(function() {
    $("#signin_submit").click(function() {
        signin($("#signin_mail").val(), $("#signin_pass").val());
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

function signin(mail, pass) {
	if (mail === "" || pass === "")
		return (false);
	sendData({
		act: "signin",
		mail: mail,
		pass: pass
	});
}
function signup(username, firstname, lastname, mail, pass1, pass2) {
	console.log(username + " : " + firstname + " : " + lastname + " : " + mail + " : " + pass1 + " : " + pass2);
	sendData({
		act: "signup",
		username: username,
		firstname: firstname,
		lastname: lastname,
		mail: mail,
		pass1: pass1,
		pass2: pass2
	});
}
