var nbr_pics = 0;

pics(nbr_pics);

function pics(nbr, callback) {
	Z.post("model/pics.php", {
		nbr: nbr
	}, function(res) {
		res = JSON.parse(res);
		if (nbr == 0)
			Z.id("all_pics").innerHTML = "";
		res.forEach(function(pic) {
			Z.id("all_pics").innerHTML += '<article>'
				+ '<img src="' + pic.pic + '">'
				+ '<div class="tools">'
					+ '<div class="tools_help left">'
						+ 'Posté par <a href="#">' + pic.user + '</a>'
					+ '</div>'
					+ '<div class="tools_like right">'
						+ '<svg style="width: 40px; height: 40px" viewBox="0 0 24 24">'
							+ '<path fill="#FF6550" d="M20,2A2,2 0 0,1 22,4V20A2,2 0 0,1 20,22H4A2,2 0 0,1 2,20V4C2,2.89 2.9,2 4,2H20M20,12H18V10H17V12H15V13H17V15H18V13H20V12M9,11.29V13H11.86C11.71,13.71 11,15.14 9,15.14C7.29,15.14 5.93,13.71 5.93,12C5.93,10.29 7.29,8.86 9,8.86C10,8.86 10.64,9.29 11,9.64L12.36,8.36C11.5,7.5 10.36,7 9,7C6.21,7 4,9.21 4,12C4,14.79 6.21,17 9,17C11.86,17 13.79,15 13.79,12.14C13.79,11.79 13.79,11.57 13.71,11.29H9Z" />'
						+ '</svg>'
						+ '<svg style="width: 40px; height: 40px" viewBox="0 0 24 24">'
							+ '<path fill="#3B5998" d="M19,4V7H17A1,1 0 0,0 16,8V10H19V13H16V20H13V13H11V10H13V7.5C13,5.56 14.57,4 16.5,4M20,2H4A2,2 0 0,0 2,4V20A2,2 0 0,0 4,22H20A2,2 0 0,0 22,20V4C22,2.89 21.1,2 20,2Z" />'
						+ '</svg>'
						+ '<svg style="width: 40px; height: 40px" viewBox="0 0 24 24">'
							+ '<path fill="#1DA1F2" d="M17.71,9.33C17.64,13.95 14.69,17.11 10.28,17.31C8.46,17.39 7.15,16.81 6,16.08C7.34,16.29 9,15.76 9.9,15C8.58,14.86 7.81,14.19 7.44,13.12C7.82,13.18 8.22,13.16 8.58,13.09C7.39,12.69 6.54,11.95 6.5,10.41C6.83,10.57 7.18,10.71 7.64,10.74C6.75,10.23 6.1,8.38 6.85,7.16C8.17,8.61 9.76,9.79 12.37,9.95C11.71,7.15 15.42,5.63 16.97,7.5C17.63,7.38 18.16,7.14 18.68,6.86C18.47,7.5 18.06,7.97 17.56,8.33C18.1,8.26 18.59,8.13 19,7.92C18.75,8.45 18.19,8.93 17.71,9.33M20,2H4A2,2 0 0,0 2,4V20A2,2 0 0,0 4,22H20A2,2 0 0,0 22,20V4C22,2.89 21.1,2 20,2Z" />'
						+ '</svg>'
						+ '<svg id="like_' + pic.id + '" style="width: 40px; height: 40px" viewBox="0 0 24 24" onclick="like(' + pic.id + ')">'
						+ '</svg>'
						+ '<div id="nbr_like">'
							+ '<span id="nbr_like_' + pic.id + '">'
								+ pic.likes
							+ '</span>'
						+ '</div>'
					+ '</div>'
					+ '<div class="clear"></div>'
				+ '</div>'
				+ '<div id="comments_' + pic.id + '">'
				+ '</div>'
				+ '<div class="comments_tool"><input id="comments_input_' + pic.id + '" type="text" placeholder="Poster un commentaire ..." ><button id="comments_button" onclick="postComments(' + pic.id + ')">Envoyer</button></div>'
			+ '</article>';
			if (pic.islike)
				Z.id("like_" + pic.id).innerHTML = '<path fill="#c0392b" d="M12,21.35L10.55,20.03C5.4,15.36 2,12.27 2,8.5C2,5.41 4.42,3 7.5,3C9.24,3 10.91,3.81 12,5.08C13.09,3.81 14.76,3 16.5,3C19.58,3 22,5.41 22,8.5C22,12.27 18.6,15.36 13.45,20.03L12,21.35Z" />';
			else
				Z.id("like_" + pic.id).innerHTML = '<path fill="#c0392b" d="M12.1,18.55L12,18.65L11.89,18.55C7.14,14.24 4,11.39 4,8.5C4,6.5 5.5,5 7.5,5C9.04,5 10.54,6 11.07,7.36H12.93C13.46,6 14.96,5 16.5,5C18.5,5 20,6.5 20,8.5C20,11.39 16.86,14.24 12.1,18.55M16.5,3C14.76,3 13.09,3.81 12,5.08C10.91,3.81 9.24,3 7.5,3C4.42,3 2,5.41 2,8.5C2,12.27 5.4,15.36 10.55,20.03L12,21.35L13.45,20.03C18.6,15.36 22,12.27 22,8.5C22,5.41 19.58,3 16.5,3Z" />';
			pic.comments.forEach(function(comment) {
				Z.id("comments_" + pic.id).innerHTML += '<span class="comments_user">' + comment.user + '</span> : ' + comment.comment + '<br />';
			});
		});
		myPics();
	});
}

function myPics() {
	Z.post("model/mypics.php", {
		request: "OK"
	}, function(res) {
		res = JSON.parse(res);
		Z.id("my_pics").innerHTML = "";
		res.forEach(function(pic) {
			Z.id("my_pics").innerHTML += '<img src="' + pic.pic + '"><br /><button onclick="delPic(' + pic.id + ')">Supprimer</button><br />';
		});
	});
}

function delPic(id) {
	Z.post("model/delpic.php", {
		id: id
	}, function(res) {
		if (res != 0) {
			res = JSON.parse(res);
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = res.info;
			pics(0);
			myPics();
		}
		else {
			Z.id("info").style.display = "block";
			Z.id("info_text").innerHTML = "Vous devez être connecté pour supprimé une photo.";
		}
	});
}

Z.id("more_pics").addEventListener("click", function() {
	nbr_pics += 2;
	pics(nbr_pics);
});
