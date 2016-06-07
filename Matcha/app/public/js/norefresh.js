$(document).ready(function() {
    setAct();
    $(window).on('popstate', function () {
		NProgress.start();
        $.ajax({
            url: location.pathname + '?ajax',
            success: function (data) {
				NProgress.inc();
                $('.content').html(data);
				NProgress.done();
            }
        });
    });
});

function setAct() {
    $(".no-refresh").on('click', function (e) {
		NProgress.start();
        pageUrl = $(this).attr('href');
		NProgress.inc();
        $.ajax({
            url: pageUrl + '?ajax',
            success: function (data) {
				NProgress.inc();
                $('.content').html(data);
				NProgress.done();
            }
        });
        if (pageUrl != window.location) {
            window.history.pushState({ path: pageUrl }, '', pageUrl);
        }
        e.preventDefault();
    });
}
