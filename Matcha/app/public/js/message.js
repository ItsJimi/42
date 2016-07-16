var to;

function getReceiver(me, user) {
	to = user;

	$('#message_content').html('');

	$('.message_user').css("background-color", "");
	$(me).css("background-color", "rgba(0, 0, 0, 0.2)");

	$('#message_text').attr('placeholder', 'Press return to send message ! ;)');
	$('#message_text').removeAttr('disabled');
	console.log(to);
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
