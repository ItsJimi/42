var to;

function getReceiver(user) {
	to = user;
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
