function notif(res) {
	if (res.end === "true")
		$("#info").css("background", "#27ae60");
	else
		$("#info").css("background", "#c0392b");
	$("#info").text(res.message);
	$("#info").fadeIn("fast");
	setTimeout(function() {
		$("#info").fadeOut("fast");
	}, 6000);
}
