var nbr_pics = 0;

pics(nbr_pics);

function pics(nbr) {
	Z.post("model/pics.php", {
		nbr: nbr
	}, function(res) {
		res = JSON.parse(res);
		res.forEach(function(pic) {
 			Z.id("all_pics").innerHTML += '<article>'
+				'<img src="' + pic.pic + '">'
+				'<div class="tools">'
+					'<div class="tools_help left">'
+						'Posté par <a href="#">' + pic.user + '</a>'
+					'</div>'
+					'<div class="tools_like right">'
+						'<svg id="like" style="width: 40px; height: 40px" viewBox="0 0 24 24" onclick="like(' + pic.id + ')">'
+							'<path fill="#c0392b" d="M12.1,18.55L12,18.65L11.89,18.55C7.14,14.24 4,11.39 4,8.5C4,6.5 5.5,5 7.5,5C9.04,5 10.54,6 11.07,7.36H12.93C13.46,6 14.96,5 16.5,5C18.5,5 20,6.5 20,8.5C20,11.39 16.86,14.24 12.1,18.55M16.5,3C14.76,3 13.09,3.81 12,5.08C10.91,3.81 9.24,3 7.5,3C4.42,3 2,5.41 2,8.5C2,12.27 5.4,15.36 10.55,20.03L12,21.35L13.45,20.03C18.6,15.36 22,12.27 22,8.5C22,5.41 19.58,3 16.5,3Z" />'
+						'</svg>'
+						'<div id="like">'
+							pic.hearts
+						'</div>'
+					'</div>'
+					'<div class="clear"></div>'
+				'</div>'
+			'</article>';
		});
	});
}

Z.id("more_pics").addEventListener("click", function() {
	nbr_pics += 5;
	pics(nbr_pics);
});
