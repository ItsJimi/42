$(document).ready(function() {
	var edit = false;

	// Nav Buttons
	$('#nav_message').click(function() {
		$('#message').fadeToggle('fast');
		$('#edit').fadeOut('fast');
		$('#profiles').fadeOut('fast');
		$('#filters').fadeOut('fast');
	});
	$('#nav_edit').click(function() {
		if (edit) {
			$('#edit').fadeOut('fast');
			$('#edit_tags').html("");
			$('#edit_tags_choose').html("");

			edit = false;
		}
		else {
			viewYourProfile(function() {
				$('#edit').fadeIn('fast');
				$('#profiles').fadeOut('fast');
				$('#message').fadeOut('fast');
				$('#filters').fadeOut('fast');

				edit = true;
			});
		}
	});
	$('#nav_filters').click(function() {
		$('#filters').slideToggle('fast');
		$('#edit').fadeOut('fast');
		$('#message').fadeOut('fast');
		$('#profiles').fadeOut('fast');
	});
	$(document).keydown(function(e) {
		if (e.keyCode == 27) {
			$('#edit').fadeOut('fast');
			$('#profiles').fadeOut('fast');
			$('#message').fadeOut('fast');
		}
	});

	$('#edit_validate').click(function() {
		editProfile();
	});
});
