function settingsProfiles(username) {
	viewProfile(function() {
		$('#settings').fadeOut('fast');
		$('#profiles').fadeIn('fast');
	}, username);
}

function viewProfile(callback, username) {
	NProgress.start();
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
	NProgress.inc();
	if (!username)
		username = '';
	$.get("/api/profiles/view/" + username, {}).done(function(res) {
		NProgress.inc();
		if (!res[0]) {
			info({
				request: false,
				message: "Error"
			});
			return (false);
		}
		if (res[0].firstname)
			$('#profiles_firstname').html(res[0].firstname);
		if (res[0].lastname)
			$('#profiles_lastname').html(res[0].lastname);
		$('#profiles_img_s').attr("src", '/api/img/view/' + username + '/300/0');
		if (res[0].like)
			$('#profiles_controls_like').html('<svg style="width:24px;height:24px" viewBox="0 0 24 24"><path fill="#fff" d="M12,21.35L10.55,20.03C5.4,15.36 2,12.27 2,8.5C2,5.41 4.42,3 7.5,3C9.24,3 10.91,3.81 12,5.08C13.09,3.81 14.76,3 16.5,3C19.58,3 22,5.41 22,8.5C22,12.27 18.6,15.36 13.45,20.03L12,21.35Z" /></svg>')
		else
			$('#profiles_controls_like').html('<svg style="width:24px;height:24px" viewBox="0 0 24 24"><path fill="#fff" d="M12.1,18.55L12,18.65L11.89,18.55C7.14,14.24 4,11.39 4,8.5C4,6.5 5.5,5 7.5,5C9.04,5 10.54,6 11.07,7.36H12.93C13.46,6 14.96,5 16.5,5C18.5,5 20,6.5 20,8.5C20,11.39 16.86,14.24 12.1,18.55M16.5,3C14.76,3 13.09,3.81 12,5.08C10.91,3.81 9.24,3 7.5,3C4.42,3 2,5.41 2,8.5C2,12.27 5.4,15.36 10.55,20.03L12,21.35L13.45,20.03C18.6,15.36 22,12.27 22,8.5C22,5.41 19.58,3 16.5,3Z" /></svg>')
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
		NProgress.inc();
		callback();
		NProgress.done();
    });
	$.get("/api/profiles/visits/" + username).done();
}

function viewYourProfile(callback) {
	NProgress.start();
	$.get("/api/profiles/view/", {}).done(function(res) {
		NProgress.inc();
		if (!res[0]) {
			info({
				request: false,
				message: "Error"
			});
			return (false);
		}
		if (res[0].firstname)
			$('#edit_firstname').val(res[0].firstname);
		if (res[0].lastname)
			$('#edit_lastname').val(res[0].lastname);
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
				$('#edit_tags').append('<span class="edit_tag" onclick="delTag(this)">#' + tag + '</span> ');
			});
		}
		NProgress.inc();
		getTags();
		NProgress.inc();
		if (res[0].bio)
			$('#edit_bio_s').html(res[0].bio);
		NProgress.inc();
		callback();
		NProgress.done();
    });
}

function editProfile() {
	NProgress.start();
	$.post("/api/profiles/update/", {
		firstname: $('#edit_firstname').val(),
		lastname: $('#edit_lastname').val(),
		location: $('#edit_location_s').val(),
		birthdate: $('#edit_birthdate_s').val(),
		gender: $("#edit_gender_s option:selected").text(),
		preference: $("#edit_preference_s option:selected").text(),
		bio: $('#edit_bio_s').val()
	}).done(function(res) {
		NProgress.inc();
		if (!res.request) {
			info(res);
			return (false);
		}
		else {
			info(res);
		}
		NProgress.done();
    });
}

function getTags(callback) {
	$.get("/api/tags/").done(function(res) {
		res.forEach(function(tag) {
			$('#edit_tags_choose').append('<option value="' + tag.name + '">');
		});
    });
}

function upload(files) {
	NProgress.start();
    var file = files[0] ;

    var reader = new FileReader();

    // When the image is loaded
    reader.onload = function(evt) {
		NProgress.inc();
        $.post("/api/img/upload/", {
            objectData: evt.target.result.split(',')[1],
            type: file.type
        }).done(function(res) {
			NProgress.inc();
			if (res.request) {
				$('#uploadImg').val('');
			}
			info(res);
			NProgress.done();
        });
    };

	NProgress.inc();
    // Read in the image file as a data URL
    reader.readAsDataURL(file);
}

function delYourPicture() {
	$.post("/api/img/del/", {
		image: $('#edit_img_s').attr('src').split('/')[6]
	}).done(function(res) {
		info(res);
	});
}

function addTag() {
	$.post("/api/tags/add/", {
		tag: $('#edit_tags_add').val()
	}).done(function(res) {
		if (res.request) {
			$('#edit_tags').append('<span class="edit_tag" onclick="delTag(this)">#' + $('#edit_tags_add').val() + '</span> ');
			$('#edit_tags_add').val("");
		}
		info(res);
	});
}

function delTag(tag) {
	$.post("/api/tags/del/", {
		tag: $(tag).html().slice(1, tag.length)
	}).done(function(res) {
		$(tag).remove();
		info(res);
	});
}

function location() {
	// Try HTML5 geolocation.
	if (navigator.geolocation) {
		navigator.geolocation.getCurrentPosition(function(position) {
			pos = {
				lat: position.coords.latitude,
				lng: position.coords.longitude
			};
			$.get("https://maps.googleapis.com/maps/api/geocode/json?latlng=" + pos.lat + "," + pos.lng).done(function(res) {
				if (res.results.length > 0)
					$('#edit_location_s').val(res.results[0].formatted_address);
			});
		}, function() {
			//handleLocationError(true, infoWindow, map.getCenter());
			info({
				request: false,
				message: "Location error"
			});
		});
	} else {
		// Browser doesn't support Geolocation
		// handleLocationError(false, infoWindow, map.getCenter());
		info({
			request: false,
			message: "Your browser doesn't support Geolocation"
		});
	}
}

function handleLocationError(browserHasGeolocation, infoWindow, pos) {
  infoWindow.setPosition(pos);
  infoWindow.setContent(browserHasGeolocation ?
                        'Error: The Geolocation service failed.' :
                        'Error: Your browser doesn\'t support geolocation.');
}

function like() {
	var username = $('#profiles_img_s').attr('src').split('/')[4];
	$.get("/api/profiles/like/" + username).done(function(res) {
		if (res.request) {
			if (res.act === "like")
				$('#profiles_controls_like').html('<svg style="width:24px;height:24px" viewBox="0 0 24 24"><path fill="#fff" d="M12,21.35L10.55,20.03C5.4,15.36 2,12.27 2,8.5C2,5.41 4.42,3 7.5,3C9.24,3 10.91,3.81 12,5.08C13.09,3.81 14.76,3 16.5,3C19.58,3 22,5.41 22,8.5C22,12.27 18.6,15.36 13.45,20.03L12,21.35Z" /></svg>')
			else
				$('#profiles_controls_like').html('<svg style="width:24px;height:24px" viewBox="0 0 24 24"><path fill="#fff" d="M12.1,18.55L12,18.65L11.89,18.55C7.14,14.24 4,11.39 4,8.5C4,6.5 5.5,5 7.5,5C9.04,5 10.54,6 11.07,7.36H12.93C13.46,6 14.96,5 16.5,5C18.5,5 20,6.5 20,8.5C20,11.39 16.86,14.24 12.1,18.55M16.5,3C14.76,3 13.09,3.81 12,5.08C10.91,3.81 9.24,3 7.5,3C4.42,3 2,5.41 2,8.5C2,12.27 5.4,15.36 10.55,20.03L12,21.35L13.45,20.03C18.6,15.36 22,12.27 22,8.5C22,5.41 19.58,3 16.5,3Z" /></svg>')
		}
		info(res);
	});
}
function block() {
	var username = $('#profiles_img_s').attr('src').split('/')[4];
	$.get("/api/profiles/block/" + username).done(function(res) {
		if (res.request) {
			$('#profiles').fadeOut('fast');
			marker.forEach(function(mark) {
				if (username === mark.username)
					marker[mark.id].setMap(null);
			});
		}
		info(res);
	});
}
function report() {
	var username = $('#profiles_img_s').attr('src').split('/')[4];
	$.get("/api/profiles/report/" + username).done(function(res) {
		info(res);
	});
}
