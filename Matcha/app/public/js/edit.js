function editProfile(callback) {
	$.ajax({
        url: "/edit/",
        type: "POST",
        dataType: "json",
        data: JSON.stringify({
            request: "edit"
        }),
        contentType: "application/json",
        cache: false,
        timeout: 5000,
        statusCode: {
			400: function() {
                notif({
					end: false,
					message: "Error"
				});
            },
            200: function(res) {
				notif(res);
				$('#edit_firstname').html(res.edit_firstname);
				$('#edit_lastname').html(res.edit_lastname);
				$('#edit_img').html(res.edit_img);
				$('#edit_localisation_s').val(res.edit_localisation);
				$('#edit_birthdate_s').val(res.edit_birthdate);
				$('#edit_localisation_s').val(res.edit_localisation);
				$('#edit_localisation_s').val(res.edit_localisation);
				$('#edit_localisation_s').val(res.edit_localisation);
				$('#edit_localisation_s').val(res.edit_localisation);
				$('#edit_localisation_s').val(res.edit_localisation);
				callback();
            }
        }
    });
}
