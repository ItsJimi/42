var to;

function getReceiver(me, user) {
	to = user;

	$.get('/api/messages/' + to).done(function(res) {
		if (res[0]) {
			$('#message_content').html('');
			$('.message_user').css("background-color", "");
			$(me).css("background-color", "rgba(0, 0, 0, 0.2)");

			res[0].messages.forEach(function(message) {
				if (message.from == to)
					var role = "receiver";
				else
					var role = "sender";
				$('#message_content').append('<div class="message_' + role + '">' + message.message + '</div><div class="clear"></div>');
			});

			$('#message_text').attr('placeholder', 'Press return to send message ! ;)');
			$('#message_text').removeAttr('disabled');
			$("#message_content").animate({ scrollTop: $(document).height() }, 500);
		}
	});
}

function sendMessage() {
	sendData({
		act: 'message',
		to: to,
		message: $('#message_text').val()
	});
	$('#message_text').val("");
	$("#message_content").animate({ scrollTop: $(document).height() }, 500);
}
