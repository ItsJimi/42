$(document).ready(function() {
	var edit = false;
	var edit_nbr = 0;
	var profiles_nbr = 0;
	var text_history;

	// Nav Buttons
	$('#nav_message').click(function() {
		getUsersMsg(function() {
			$('#message').fadeToggle('fast');
			$('#edit').fadeOut('fast');
			$('#profiles').fadeOut('fast');
			$('#filters').fadeOut('fast');
			$('#settings').fadeOut('fast');
		});
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
				$('#settings').fadeOut('fast');

				edit = true;
			});
		}
	});
	$('#nav_filters').click(function() {
		$('#filters').slideToggle('fast');
		$('#edit').fadeOut('fast');
		$('#message').fadeOut('fast');
		$('#profiles').fadeOut('fast');
		$('#settings').fadeOut('fast');
	});
	$('#nav_settings').click(function() {
		settings(function() {
			$('#settings').fadeToggle('fast');
			$('#filters').fadeOut('fast');
			$('#edit').fadeOut('fast');
			$('#message').fadeOut('fast');
			$('#profiles').fadeOut('fast');
		});
	});

	// Close panes
	$('#edit_close').click(function() {
		$('#edit').fadeOut('fast');
		$('#edit_tags').html("");
		$('#edit_tags_choose').html("");

		edit = false;
	});
	$('#profiles_close').click(function() {
		$('#profiles').fadeOut('fast');
	});
	$('#message_close').click(function() {
		$('#message').fadeOut('fast');
	});
	$('#settings_close').click(function() {
		$('#settings').fadeOut('fast');
	});

	// Edit pane
	$('#edit_location_add').click(function() {
		location();
	});
	$('#edit_add_tag').click(function() {
		addTag();
	});
	$('#edit_validate').click(function() {
		editProfile();
	});

	$('#edit_del').click(function() {
		delYourPicture();
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

	// Profile pane
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
	$('#profiles_controls_like').click(function() {
		like();
	});
	$('#profiles_controls_block').click(function() {
		block();
	});
	$('#profiles_controls_report').click(function() {
		report();
	});

	// Keydown
	$(document).keydown(function(e) {
		if (e.keyCode == 27) {
			$('#edit').fadeOut('fast');
			$('#profiles').fadeOut('fast');
			$('#message').fadeOut('fast');
			$('#settings').fadeOut('fast');
		}
	});
});
