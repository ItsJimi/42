$(document).ready(function() {
	console.log("Coucou !");
	$(".link1").on('click', function (e) {
	    pageUrl = $(this).attr('href');
		console.log(pageUrl);
		$.ajax({
	        url: pageUrl + '?type=ajax',
	        success: function (data) {
	            $('.container').html(data);
				console.log("success");
	        }
	    });
	    if (pageUrl != window.location) {
	        window.history.pushState({ path: pageUrl }, '', pageUrl);
	    }
	    e.preventDefault();
	});
	$(".link2").on('click', function (e) {
	    pageUrl = $(this).attr('href');
		console.log(pageUrl);
		$.ajax({
	        url: pageUrl + '?type=ajax',
	        success: function (data) {
	            $('.container').html(data);
				console.log("success");
	        }
	    });
	    if (pageUrl != window.location) {
	        window.history.pushState({ path: pageUrl }, '', pageUrl);
	    }
	    e.preventDefault();
	});
	$(window).on('popstate', function () {
        $.ajax({
            url: location.pathname + '?type=ajax',
            success: function (data) {
                $('.container').html(data);
            }
        });
    });
});
