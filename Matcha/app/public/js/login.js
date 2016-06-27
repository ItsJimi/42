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
		notif({
			end: "false",
			message: "Fields empty."
		});
		return (false);
	}
	$.ajax({
        url: "/login/signin",
        type: "POST",
        dataType: "json",
        data: JSON.stringify({
            username: username,
            pass: pass
        }),
        contentType: "application/json",
        cache: false,
        timeout: 5000,
        statusCode: {
            400: function() {
                console.log("error");
            },
            200: function(res) {
				notif(res);
				if (res.end === "true")
					window.location = "/";
            }
        }
    });
}
function signup(username, firstname, lastname, mail, pass1, pass2) {
	if (username === "" || firstname === "" || lastname === "" || mail === "" || pass1 === "" || pass2 === "") {
		notif({
			end: "false",
			message: "Fields empty."
		});
		return (false);
	}
	$.ajax({
        url: "/login/signup",
        type: "POST",
        dataType: "json",
        data: JSON.stringify({
			username: username,
			firstname: firstname,
			lastname: lastname,
			mail: mail,
			pass1: pass1,
			pass2: pass2
        }),
        contentType: "application/json",
        cache: false,
        timeout: 5000,
        statusCode: {
            400: function() {
                console.log("error");
            },
            200: function(res) {
				notif(res);
            }
        }
    });
}
