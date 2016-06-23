$(document).ready(function() {

});
var show = 0;

function userDisplay(user) {
	if (show == 0) {
		$(user).show("fast");
		show = 1;
	}
	else {
		$(user).hide("fast");
		show = 0;
	}
}
