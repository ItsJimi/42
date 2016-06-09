$(document).ready(function(){
    $("#search_button").click(function(){
        search($("#search_bar").value);
		$("#search_bar").value = "";
    });
});

function search(str) {
	if (str === "")
		return (false);
	var obj = {
		"act" : "search",
		"message" : str
	};
	ws.send(JSON.stringify(obj));
}
