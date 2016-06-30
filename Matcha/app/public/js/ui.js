$(document).ready(function() {
	// Nav Buttons
	$('#nav_message').click(function() {
		$('#message').fadeToggle('fast');
		$('#edit').fadeOut('fast');
		$('#profiles').fadeOut('fast');
		$('#filters').fadeOut('fast');
	});
	$('#nav_edit').click(function() {
		$('#edit').fadeToggle('fast');
		$('#profiles').fadeOut('fast');
		$('#message').fadeOut('fast');
		$('#filters').fadeOut('fast');
	});
	$('#nav_filters').click(function() {
		$('#filters').slideToggle('fast');
		$('#edit').fadeOut('fast');
		$('#message').fadeOut('fast');
		$('#profiles').fadeOut('fast');
	});
});