$(document).ready(function() {
    $("#search_button").click(function() {
        search($("#search_bar").html());
		$("#search_bar").html("");
    });
	$("#search_bar").keypress(function(event) {
		if (event.which == 13) {
			search($("#search_bar").html());
			$("#search_bar").html("");
			$("#search_bar").blur();
		}
	});
});

function search(str) {
	if (str === "")
		return (false);
	sendData({
		act: "search",
		name: str
	});
}
