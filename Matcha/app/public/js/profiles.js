function viewProfile(callback, username) {
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
			$('#profile_firstname').html(res[0].firstname);
		if (res[0].lastname)
			$('#profile_lastname').html(res[0].lastname);
		if (res[0].img)
			$('#profile_img_s').attr("src", res[0].img[0]);
		if (res[0].location)
			$('#profile_location_s').html(res[0].location);
		if (res[0].birthdate)
			$('#profile_birthdate_s').html(res[0].birthdate.substr(0, 10));
		if (res[0].gender)
			$("#profile_gender_s option[value='" + res[0].gender + "']").html("selected", "selected");
		if (res[0].preference)
			$("#profile_preference_s option[value='" + res[0].preference + "']").html("selected", "selected");
		if (res[0].tags) {
			res[0].tags.forEach(function(tag) {
				$('#profile_tags').append('<span class="profile_tag">#' + tag + '</span> ');
			});
		}
		getTags();
		if (res[0].bio)
			$('#profile_bio_s').html(res[0].bio);
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
			$('#edit_firstname').html(res[0].firstname);
		if (res[0].lastname)
			$('#edit_lastname').html(res[0].lastname);
		if (res[0].img)
			$('#edit_img_s').attr("src", res[0].img[0]);
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
		firstname: $('#edit_firstname').html(),
		lastname: $('#edit_lastname').html(),
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
