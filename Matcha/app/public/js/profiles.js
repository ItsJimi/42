function viewProfile(callback, username) {
	if (!username)
		username = '';
	$.ajax({
        url: "/api/profiles/view/" + username,
        type: "GET",
        dataType: "json",
        data: JSON.stringify({
            request: "edit"
        }),
        contentType: "application/json",
        cache: false,
        timeout: 5000,
        statusCode: {
			400: function() {
                info({
					end: false,
					message: "Error"
				});
            },
            200: function(res) {
				if (!res[0]) {
					info({
						end: false,
						message: "Error"
					});
					return (false);
				}
				if (res[0].firstname)
					$('#edit_firstname').html(res[0].firstname);
				if (res[0].lastname)
					$('#edit_lastname').html(res[0].lastname);
				if (res[0].img)
					$('#edit_img_s').attr("src", res[0].img[0]);
				if (res[0].location)
					$('#edit_localisation_s').val(res[0].location);
				if (res[0].birthdate)
					$('#edit_birthdate_s').val(res[0].birthdate);
				if (res[0].gender)
					$("#edit_gender_s option[value='" + res[0].gender + "']").attr("selected", "selected");
				if (res[0].preference)
					$("#edit_preference_s option[value='" + res[0].preference + "']").attr("selected", "selected");
				if (res[0].tags) {
					res[0].tags.forEach(function(tag) {
						$('#edit_tags').append('<span class="edit_tag">#' + tag + '</span> ');
					});
				}
				getTags();
				if (res[0].bio)
					$('#edit_bio_s').html(res[0].bio);
				callback();
            }
        }
    });
}

function editProfile() {

}

function getTags(callback) {
	$.ajax({
        url: "/api/tags/",
        type: "GET",
        dataType: "json",
        data: JSON.stringify({
            request: "edit"
        }),
        contentType: "application/json",
        cache: false,
        timeout: 5000,
        statusCode: {
			400: function() {
                info({
					end: false,
					message: "Error"
				});
            },
            200: function(res) {
				res.forEach(function(tag) {
					$('#edit_tags_choose').append('<option value="' + tag.name + '">');
				});
            }
        }
    });
}
