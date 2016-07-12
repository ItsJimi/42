function viewProfile(callback, username) {
	$('#profiles_firstname').html("");
	$('#profiles_lastname').html("");
	$('#profiles_img_s').attr("src", "/img/pp.png");
	$('#profiles_location_s').html("Unknown");
	$('#profiles_age_s').html("?");
	$("#profiles_gender_s").html("Unknown");
	$("#profiles_preference_s").html("Both");
	$('#profiles_tags').html('');
	$('#profiles_bio').html('');
	$('#profiles_img_prev').attr('onclick', '');
	$('#profiles_img_next').attr('onclick', '');
	if (!username)
		username = '';
	$.get("/api/profiles/view/" + username, {}, function(res) {
		if (!res[0]) {
			info({
				end: false,
				message: "Error"
			});
			return (false);
		}
		if (res[0].firstname)
			$('#profiles_firstname').html(res[0].firstname);
		if (res[0].lastname)
			$('#profiles_lastname').html(res[0].lastname);
		if (res[0].img)
			$('#profiles_img_s').attr("src", '/api/img/view/' + username + '/300/0');
		if (res[0].location)
			$('#profiles_location_s').html(res[0].location);
		if (res[0].birthdate) {
			var ageDifMs = Date.now() - (new Date(res[0].birthdate));
	        var ageDate = new Date(ageDifMs);
			$('#profiles_age_s').html(Math.abs(ageDate.getUTCFullYear() - 1970));
		}
		if (res[0].gender)
			$("#profiles_gender_s").html(res[0].gender);
		if (res[0].preference)
			$("#profiles_preference_s").html(res[0].preference);
		if (res[0].tags) {
			res[0].tags.forEach(function(tag) {
				$('#profiles_tags').append('<span class="profiles_tag">#' + tag + '</span> ');
			});
		}
		if (res[0].bio)
			$('#profiles_bio').html(res[0].bio);
		callback();
    });
}

function viewYourProfile(callback) {
	$.get("/api/profiles/view/", {}, function(res) {
		if (!res[0]) {
			info({
				end: false,
				message: "Error"
			});
			return (false);
		}
		if (res[0].firstname)
			$('#edit_firstname').val(res[0].firstname);
		if (res[0].lastname)
			$('#edit_lastname').val(res[0].lastname);
		if (res[0].img)
			$('#edit_img_s').attr("src", '/api/img/view/' + res[0].username + '/300/0');
		if (res[0].location)
			$('#edit_location_s').val(res[0].location);
		if (res[0].birthdate)
			$('#edit_birthdate_s').val(res[0].birthdate.substr(0, 10));
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
    });
}

function editProfile() {
	$.post("/api/profiles/update/", {
		firstname: $('#edit_firstname').val(),
		lastname: $('#edit_lastname').val(),
		location: $('#edit_location_s').val(),
		birthdate: $('#edit_birthdate_s').val(),
		gender: $("#edit_gender_s option:selected").text(),
		preference: $("#edit_preference_s option:selected").text(),
		bio: $('#edit_bio_s').val()
	}).done(function(res) {
		if (!res.request) {
			info({
				end: false,
				message: res.message
			});
			return (false);
		}
		else {
			info({
				end: true,
				message: res.message
			});
		}
    });
}

function getTags(callback) {
	$.get("/api/tags/", {}, function(res) {
		res.forEach(function(tag) {
			$('#edit_tags_choose').append('<option value="' + tag.name + '">');
		});
    });
}

function upload(files) {
    var file = files[0] ;

    var reader = new FileReader();

    // When the image is loaded
    reader.onload = function(evt) {
        $.post("/api/img/upload/", {
            objectData: evt.target.result.split(',')[1],
            type: file.type
        }, function(res) {
			if (res.request) {
				$('#uploadImg').val('');
			}
			info({
				end: res.request,
				message: res.message
			});
        });
    };

    // Read in the image file as a data URL
    reader.readAsDataURL(file);
}
