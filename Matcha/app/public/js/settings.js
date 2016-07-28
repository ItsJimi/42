$(document).ready(function() {
	$('#settings_save').click(function() {
		if ($('#settings_email').val() !== '') {
			$.post('/api/users/update', {
				mail: $('#settings_email').val()
			}).done(function(res) {
				info(res);
			});
		}
	});
	$('#settings_pass').click(function() {
		if ($('#settings_pass1').val() !== '' && $('#settings_pass2').val() !== '') {
			$.post('/api/users/pass', {
				pass1: $('#settings_pass1').val(),
				pass2: $('#settings_pass2').val()
			}).done(function(res) {
				info(res);
			});
		}
	});
});

function settings(callback) {
	$('#settings_email').val("");
	$('#settings_like').html("");
	$('#settings_blocked').html("");
	$('#settings_visits').html("");
	NProgress.start();
	$.get("/api/users/view").done(function(res) {
		if (res.request != false) {
			if (res[0].mail)
				$('#settings_email').val(res[0].mail);
		}
		$.get("/api/profiles/like").done(function(res) {
			NProgress.inc();
			res.forEach(function(data) {
				$('#settings_like').append('<img src="/api/img/view/' + data.users[0] + '/100/0" onclick="settingsProfiles(\'' + data.users[0] + '\')" />');
				NProgress.inc();
			});
			NProgress.inc();
			$.get("/api/profiles/block").done(function(res) {
				NProgress.inc();
				res.forEach(function(data) {
					$('#settings_blocked').append('<img src="/api/img/view/' + data.users[1] + '/100/0" onclick="settingsProfiles(\'' + data.users[1] + '\')" />');
					NProgress.inc();
				});
				$.get("/api/profiles/visits").done(function(res) {
					NProgress.inc();
					res.forEach(function(data) {
						$('#settings_visits').append('<img src="/api/img/view/' + data + '/100/0" onclick="settingsProfiles(\'' + data + '\')" />');
						NProgress.inc();
					});
					NProgress.done();
					callback();
				});
			});
		});
	});
}
