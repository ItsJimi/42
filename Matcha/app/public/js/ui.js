$(document).ready(function() {
	var edit = false;
	var edit_nbr = 0;
	var profiles_nbr = 0;

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

	$('#profiles_img_prev').click(function() {
		if (nbr == 0)
			nbr = 4;
		else
			nbr--;
		//$('#profiles_img_s').attr("src", '/api/img/view/' + username + '/300/' + nbr);
	});
	$('#profiles_img_next').click(function() {
		if (nbr == 4)
			nbr = 0;
		else
			nbr++;
	});
	$('#edit_img_prev').click(function() {
		if (nbr == 0)
			nbr = 4;
		else
			nbr--;
	});
	$('#edit_img_next').click(function() {
		if (nbr == 4)
			nbr = 0;
		else
			nbr++;
	});
});
