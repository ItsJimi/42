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
+					'<div class="tools_help">'
+						'Posté par <a href="#">' + pic.user + '</a>'
+					'</div>'
+					'<a href="#">'
+						'<div class="tools_like">'
+							'<svg style="height: 100%" viewBox="0 0 24 24">'
+								'<path fill="#ecf0f1" d="M12,21.35L10.55,20.03C5.4,15.36 2,12.27 2,8.5C2,5.41 4.42,3 7.5,3C9.24,3 10.91,3.81 12,5.08C13.09,3.81 14.76,3 16.5,3C19.58,3 22,5.41 22,8.5C22,12.27 18.6,15.36 13.45,20.03L12,21.35Z" />'
+							'</svg>'
+							pic.hearts
+						'</div>'
+					'</a>'
+				'</div>'
+			'</article>';
		});
	});
}

Z.id("more_pics").addEventListener("click", function() {
	nbr_pics += 5;
	pics(nbr_pics);
});
