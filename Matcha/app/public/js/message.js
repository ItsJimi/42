var to = null;

function getReceiver(user) {
	to = user;
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
