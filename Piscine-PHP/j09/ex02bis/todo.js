$(document).ready(function() {
	var i = 0;
	var cookies = {};

	if (document.cookie && document.cookie != '') {
	    var split = document.cookie.split(';');
	    for (var i = 0; i < split.length; i++) {
	        var name_value = split[i].split("=");
			$("#ft_list").prepend("<div id=\"" + name_value[0].trim() + "\">" + name_value[1] + "</div>");
			var nbr = parseInt(name_value[0]);
		}
	}

	if (nbr > 0)
		i = parseInt(nbr) + 1;

	$("#new").click(function() {
		if (todo = prompt("Inscrivez votre nouvelle tâche ci-dessous :")) {
			$("#ft_list").prepend("<div id=\"" + i + "\">" + todo + "</div>");

			document.cookie = i + "=" + todo + ";";
			i++;
		}
	});

	$(this).click(function() {
		var target = event.target.id;
		if ($.isNumeric(target)) {
			if (confirm("Voulez vous supprimer cette tâche ?")) {
				$("#" + target).remove();
				document.cookie = target + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC";
			}
		}
	});
});
