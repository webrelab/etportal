(function ($, Drupal) {
    Drupal.behaviors.custom_views = {
        attach: function (context, settings) {
            if ($('#edit-field-task-date-und-0-show-repeat-settings').prop('checked') === true) {
                $('.field-name-field-task-repeate-schedule').css("display", "block");
            } else {
                $('.field-name-field-task-repeate-schedule').css("display", "none");
            }
            $('#edit-field-task-date-und-0-show-repeat-settings').click(function() {
                if ($('#edit-field-task-date-und-0-show-repeat-settings').prop('checked') === true) {
                $('.field-name-field-task-repeate-schedule').css("display", "block");
                } else {
                    $('.field-name-field-task-repeate-schedule').css("display", "none");
                }
            });
        }
    }
})(jQuery, Drupal);
