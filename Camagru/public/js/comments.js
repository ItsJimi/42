function post_comment(id) {
	var comment = Z.id("comments_input_" + id).value;
	Z.id("comments_input_" + id).value = "";
	Z.post("model/comments.php", {
		id: id,
		comment: comment
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez être conecté pour posté un commentaire.";
		}
	});
}
