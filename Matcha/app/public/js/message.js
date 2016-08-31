$(document).ready(function() {
	$("#message_text").keypress(function(e) {
		if (e.which == 13) {
			text_history = $('#message_text').val();
			sendMessage();
		}
		else if (e.which == 38) {
			$('#message_text').val(text_history);
		}
	});
});

var to;

function getUsersMsg(callback) {
	NProgress.start();
	$.get("/api/messages/users/").done(function(res) {
		NProgress.inc();
		if (res.request != false) {
			NProgress.inc();
			$('#message_users').html('');
			res.forEach(function(profile) {
				$('#message_users').append('<div class="message_user" onclick="getReceiver(this, \'' + profile.username + '\');">'
					+ '<div class="img">'
						+ '<img src="/api/img/view/' + profile.username + '/60/0" alt="" />'
					+ '</div>'
					+ '<div class="name">'
						+ profile.firstname + ' ' + profile.lastname
					+ '</div>'
					+ '<div class="username">'
						+ profile.username
					+ '</div>'
				+ '</div>');
				NProgress.inc();
			});
			NProgress.done();
			callback();
		}
		else {
			info({
				act: "info",
				request: false,
				message: "You haven't any match"
			});
		}
	});
}

function getReceiver(me, user) {
	to = user;

	NProgress.start();
	$.get('/api/messages/view/' + to).done(function(res) {
		NProgress.inc();
		if (res[0]) {
			NProgress.inc();
			$('#message_content').html('');
			$('.message_user').css("background-color", "");
			$(me).css("background-color", "rgba(0, 0, 0, 0.2)");

			res[0].messages.forEach(function(message) {
				if (message.from == to)
					var role = "receiver";
				else
					var role = "sender";
				$('#message_content').append('<div class="message_' + role + '">' + message.message + '</div><div class="clear"></div>');
				NProgress.inc();
			});

			NProgress.done();
			$('#message_text').attr('placeholder', 'Press return to send message ! ;)');
			$('#message_text').removeAttr('disabled');
			$('#message_content').stop().animate({ scrollTop: $('#message_content').prop('scrollHeight') }, 0);
		}
		else if (res.request == false && res.act === "msg") {
			$('#message_content').html('');
			$('.message_user').css("background-color", "");
			$(me).css("background-color", "rgba(0, 0, 0, 0.2)");

			$('#message_text').attr('placeholder', 'Press return to send message ! ;)');
			$('#message_text').removeAttr('disabled');
			$('#message_content').stop().animate({ scrollTop: $('#message_content').prop('scrollHeight') }, 0);
		}
	});
}

function sendMessage() {
	NProgress.start();
	sendData({
		act: 'message',
		to: to,
		message: $('#message_text').val()
	});
	NProgress.inc();
	$('#message_text').val("");
	NProgress.inc();
	$("#message_content").animate({ scrollTop: $(document).height() }, 500);
	NProgress.done();
}
