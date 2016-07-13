$('#logo').click(function() {
	initMap();
});

function info(res) {
	if (res.end == true)
		$("#info").css("background", "#27ae60");
	else
		$("#info").css("background", "#c0392b");
	$("#info").text(res.message);
	$("#info").fadeIn("fast");
	setTimeout(function() {
		$("#info").fadeOut("fast");
	}, 6000);
}

function notif(message, icon) {
	// Voyons si le navigateur supporte les notifications
	if (!("Notification" in window)) {
		return (false);
	}
	// Voyons si l'utilisateur est OK pour recevoir des notifications
	else if (Notification.permission === "granted") {
		// Si c'est ok, créons une notification
		var notification = new Notification(message, {
			icon: icon
		});
	}
	// Sinon, nous avons besoin de la permission de l'utilisateur
	// Note : Chrome n'implémente pas la propriété statique permission
	// Donc, nous devons vérifier s'il n'y a pas 'denied' à la place de 'default'
	else if (Notification.permission !== 'denied') {
		Notification.requestPermission(function (permission) {
			// Quelque soit la réponse de l'utilisateur, nous nous assurons de stocker cette information
			if(!('permission' in Notification)) {
				Notification.permission = permission;
			}
			// Si l'utilisateur est OK, on crée une notification
			if (permission === "granted") {
				var notification = new Notification(message, {
					icon: icon
				});
			}
		});
	}
}
