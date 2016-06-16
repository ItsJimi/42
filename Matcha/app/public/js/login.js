$(document).ready(function() {
    $("#signin_submit").click(function() {
        signin($("#signin_mail").val(), $("#signin_pass").val());
    });
});

function signin(mail, pass) {
	console.log(mail + " : " + pass);
	if (mail === "" || pass === "")
		return (false);
	sendData({
		act: "signin",
		mail: mail,
		pass: pass
	});
}
