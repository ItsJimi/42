$(document).ready(function() {
	console.log("Coucou !");
	$("a").on('click', function (e) {
	    pageUrl = $(this).attr('href');
		$.ajax({
	        url: pageUrl + '?type=ajax',
	        success: function (data) {
	            $('#container').html(data);
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
                $('#container').html(data);
            }
        });
    });
});
