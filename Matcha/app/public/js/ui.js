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
	$('#edit_close').click(function() {
		$('#edit').fadeOut('fast');
		$('#edit_tags').html("");
		$('#edit_tags_choose').html("");

		edit = false;
	});
	$('#profiles_close').click(function() {
		$('#profiles').fadeOut('fast');
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

	$('#edit_del').click(function() {
		delYourPicture();
	});
	$('#profiles_img_prev').click(function() {
		if (profiles_nbr == 0)
			profiles_nbr = 4;
		else
			profiles_nbr--;
		var username = $('#profiles_img_s').attr('src').split('/')[4];
		$('#profiles_img_s').attr("src", '/api/img/view/' + username + '/300/' + profiles_nbr);
	});
	$('#profiles_img_next').click(function() {
		if (profiles_nbr == 4)
			profiles_nbr = 0;
		else
			profiles_nbr++;
		var username = $('#profiles_img_s').attr('src').split('/')[4];
		$('#profiles_img_s').attr("src", '/api/img/view/' + username + '/300/' + profiles_nbr);
	});
	$('#edit_img_prev').click(function() {
		if (edit_nbr == 0)
			edit_nbr = 4;
		else
			edit_nbr--;
		var username = $('#edit_img_s').attr('src').split('/')[4];
		$('#edit_img_s').attr("src", '/api/img/view/' + username + '/300/' + edit_nbr);
	});
	$('#edit_img_next').click(function() {
		if (edit_nbr == 4)
			edit_nbr = 0;
		else
			edit_nbr++;
		var username = $('#edit_img_s').attr('src').split('/')[4];
		$('#edit_img_s').attr("src", '/api/img/view/' + username + '/300/' + edit_nbr);
	});
});
