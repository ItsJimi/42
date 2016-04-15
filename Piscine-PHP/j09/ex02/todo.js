var i = 0;
var cookies = {};

if (document.cookie && document.cookie != '') {
    var split = document.cookie.split(';');
    for (var i = 0; i < split.length; i++) {
        var name_value = split[i].split("=");

		var parentElement = document.getElementById("ft_list");
		var firstChild = parentElement.firstChild;

		var added = document.createElement("div");
		added.setAttribute("id", name_value[0]);
		added.setAttribute("onclick", "del('" + name_value[0] + "');");
		var text = document.createTextNode(name_value[1]);
		added.appendChild(text);

		parentElement.insertBefore(added, firstChild);
    }
}

function add() {
	console.log("New todo !");
	var todo = prompt("Inscrivez votre nouvelle tâche ci-dessous :");

	var parentElement = document.getElementById("ft_list");
	var firstChild = parentElement.firstChild;

	var added = document.createElement("div");
	added.setAttribute("id", "todo" + i);
	added.setAttribute("onclick", "del('todo" + i + "');");
	var text = document.createTextNode(todo);
	added.appendChild(text);

	parentElement.insertBefore(added, firstChild);

	document.cookie = "todo" + i + "=" + todo + ";";

	i++;
}

function del(id) {
	if (confirm("Voulez vous supprimer cette tâche ?")) {
		var list = document.getElementById("ft_list");
		var div = document.getElementById(id);
		list.removeChild(div);
		document.cookie = id + "=; expires=Thu, 01 Jan 1970 00:00:00 UTC";
	}
}
