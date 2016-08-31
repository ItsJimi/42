$(document).ready(function() {
	var edit = false;
	var message = false;
	var setting = false;
	var edit_nbr = 0;
	var profiles_nbr = 0;
	var text_history;

	$.get("/api/profiles/notifs/").done(function(res) {
		var i = 0;

		res.forEach(function(data) {
			i++;
		});

		$('#nbr_notifs').html(i);
	});

	// Nav Buttons
	$('#nav_message').click(function() {
		if (message) {
			$('#message').fadeOut('fast');

			message = false;
		}
		else {
			getUsersMsg(function() {
				$('#message_content').html("");

				$('#message').fadeIn('fast');
				$('#edit').fadeOut('fast');
				$('#profiles').fadeOut('fast');
				$('#filters').fadeOut('fast');
				$('#settings').fadeOut('fast');

				message = true;
				edit = false;
				setting = false;
			});
		}

	});
	$('#nav_edit').click(function() {
		if (edit) {
			$('#edit').fadeOut('fast');

			edit = false;
		}
		else {
			viewYourProfile(function() {
				$('#edit_tags').html("");
				$('#edit_tags_choose').html("");

				$('#edit').fadeIn('fast');
				$('#profiles').fadeOut('fast');
				$('#message').fadeOut('fast');
				$('#filters').fadeOut('fast');
				$('#settings').fadeOut('fast');

				message = false;
				edit = true;
				setting = false;
			});
		}
	});
	$('#nav_filters').click(function() {
		message = false;
		edit = false;
		setting = false;
		$('#filters').slideToggle('fast');
		$('#edit').fadeOut('fast');
		$('#message').fadeOut('fast');
		$('#profiles').fadeOut('fast');
		$('#settings').fadeOut('fast');
	});
	$('#nav_settings').click(function() {
		if (setting) {
			$('#settings').fadeOut('fast');

			setting = false;
		}
		else {
			settings(function() {
				$('#settings').fadeIn('fast');
				$('#filters').fadeOut('fast');
				$('#edit').fadeOut('fast');
				$('#message').fadeOut('fast');
				$('#profiles').fadeOut('fast');

				message = false;
				edit = false;
				setting = true;
			});
		}
	});
	$('#nbr_notifs').click(function() {
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
		$('#message_content').html("");
	});
	$('#settings_close').click(function() {
		$('#settings').fadeOut('fast');
	});

	// Edit pane
	$('#edit_location_add').click(function() {
		getLocation();
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
