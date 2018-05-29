(function ($, Drupal) {
    Drupal.behaviors.custom_views = {
        attach: function (context, settings) {
            var c = $.cookie('comment_state', {path: '*'});
            if (c === null) {
                $.cookie('comment_state', 'hide', {path: '*', expires: 10});
            }
            if (c == 'display') {
                $('.views-field-last-comment-uid').css('display', $('td').css('display'));
                $('#commentvisible').prop('checked', true);
            } else {
                $('.views-field-last-comment-uid').css('display', 'none');
                $('#commentvisible').prop('checked', false);
            }
            $('#commentvisible').click(function(){
                console.log('click!');
                if ($('#commentvisible').prop('checked') === true) {
                    console.log('true: ' + $('#commentvisible').prop('checked'));
                    $('.views-field-last-comment-uid').css('display', $('td').css('display'));
                    $.cookie('comment_state', 'display', {path: '*', expires: 10});
                } else {
                    console.log('false: ' + $('#commentvisible').prop('checked'));
                    $('.views-field-last-comment-uid').css('display', 'none');
                    $.cookie('comment_state', 'hide', {path: '*', expires: 10});
                }
            });
            $(window).resize(function(){
                if ($('#commentvisible').prop('checked') === true) {
                    $('.views-field-last-comment-uid').css('display', $('td').css('display'));
                }
            });
        }
    }
})(jQuery, Drupal);
