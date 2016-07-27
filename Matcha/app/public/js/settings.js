function settings(callback) {
	$('#settings_email').val("");
	$('#settings_like').html("");
	$('#settings_blocked').html("");
	$('#settings_visits').html("");
	NProgress.start();
	$.get("/api/profiles/view").done(function(res) {
		
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
