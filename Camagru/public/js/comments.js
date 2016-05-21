function postComments(id) {
	var comment = Z.id("comments_input_" + id).value;
	Z.id("comments_input_" + id).value = "";
	Z.post("model/postcomments.php", {
		id: id,
		comment: comment
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			getComments(id);
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez être conecté pour posté un commentaire.";
		}
	});
}

function getComments(id) {
	Z.post("model/getcomments.php", {
		id: id
	}, function(res) {
		res = JSON.parse(res);
		Z.id("comments_" + id).innerHTML = "";
		res.comments.forEach(function(comment) {
			Z.id("comments_" + id).innerHTML += '<span class="comments_user">' + comment.user + '</span> : ' + comment.comment + '<br />';
		});
	});
}
