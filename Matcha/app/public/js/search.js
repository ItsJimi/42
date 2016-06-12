$(document).ready(function(){
    $("#search_button").click(function(){
        search($("#search_bar").val());
		$("#search_bar").val("");
    });
});

function search(str) {
	if (str === "")
		return (false);
	socket.emit('search', str);
}
