(function ($, Drupal) {
    Drupal.behaviors.custom_views = {
        attach: function (context, settings) {
            if (Drupal.settings.viewid) {
                var inputbox = $('#' + Drupal.settings.viewid + ' input.form-text');
                inputbox.attr('autocomplete','off');
                inputbox.keyup(function() {
                    var input = $(this).val();
                    var fields = $('#' + Drupal.settings.viewid).parent().next().find('.views-row');
                    fields.each(function() {
                        var name = $(this).find('a, span').text();
                        if (name.toLowerCase().indexOf(input.toLowerCase()) < 0) {
                            $(this).css('display','none');
                        }
                        else
                        {
                            $(this).css('display','block');
                        }
                    });
                });
            }
        }
    }
})(jQuery, Drupal);
