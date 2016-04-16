$(document).ready(function() {
	var i;
	var tab = {};

	$.get("select.php", function(data, status) {
		if (data)
			tab = JSON.parse(data);
		else
			tab = [];
		tab.forEach(function(element) {
			$("#ft_list").prepend("<div id=\"" + element[0] + "\">" + element[1] + "</div>");
		});
		i = get_id();
	});

	$("#new").click(function() {
		if (todo = prompt("Inscrivez votre nouvelle tâche ci-dessous :")) {
			$("#ft_list").prepend("<div id=\"" + i + "\">" + todo + "</div>");
			$.post("insert.php", {
				id: i,
				content: todo
			});
			i++;
		}
	});

	$(this).click(function() {
		var target = event.target.id;
		if ($.isNumeric(target)) {
			if (confirm("Voulez vous supprimer cette tâche ?")) {
				$("#" + target).remove();
				$.post("delete.php", {
					id: tab[target][0]
				});
			}
		}
	});

	function get_id() {
		var id = -1;
		tab.forEach(function(element) {
			if (id < parseInt(element[0]))
				id = parseInt(element[0]);
		});
		return (id + 1);
	}
});
