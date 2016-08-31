var ws = new WebSocket('ws://' + window.location.hostname + ':' + window.location.port + '/');

ws.onerror = function(err) {
};
ws.onopen = function () {
	sendData({
		act: "open"
	});
};
ws.onmessage = function(data) {
	try {
		var res = JSON.parse(data.data);
		if (res.act === "info") {
			info(res);
		}
		else if (res.act === "notif") {
			notif(res.message, "/api/img/view/" + res.from + "/300/0");
			var nbr = parseInt($('#nbr_notifs').html()) + 1;
			$('#nbr_notifs').html(nbr);
		}
		else if (res.act === "connect") {
			var name = $('#profiles_img_s').attr('src').split("/")[4];
			if (name === res.name)
				$('#profiles_time_s').html("ONLINE");
		}
		else if (res.act === "disconnect") {
			var name = $('#profiles_img_s').attr('src').split("/")[4];
			if (name === res.name)
				$('#profiles_time_s').html("a few seconds ago");
		}
		else if (res.act === "message") {
			if (res.from === to && res.role === "receiver")
				$('#message_content').append('<div class="message_' + res.role + '">' + res.message + '</div><div class="clear"></div>');
			if (res.role === "sender")
				$('#message_content').append('<div class="message_' + res.role + '">' + res.message + '</div><div class="clear"></div>');
			if (res.from && res.message) {
				notif(res.message, "/api/img/view/" + res.from + "/300/0");
				var nbr = parseInt($('#nbr_notifs').html()) + 1;
				$('#nbr_notifs').html(nbr);
			}
			$('#message_content').stop().animate({ scrollTop: $('#message_content').prop('scrollHeight') }, 0);
		}
	} catch (e) {}
};

function sendData(obj) {
	try {
		ws.send(JSON.stringify(obj));
	}
	catch(e) {}
}
