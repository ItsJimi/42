if (Z.id("reset_submit"))
	Z.id("reset_submit").addEventListener("click", reset);

function reset() {
	var reset_mail = Z.id("reset_mail").value;

	Z.l(reset_mail);

	Z.post("model/reset.php", {
		reset_mail: reset_mail,
		reset_submit: reset_submit
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			Z.id("reset_mail").value = "";
		}
	});
}
