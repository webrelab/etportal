(function ($, Drupal) {
    Drupal.behaviors.custom_views = {
        attach: function (context, settings) {
            var inp = $('#edit-field-delivery-items-quantity-und-0-value');
            var fs = $('fieldset.group-delivery-repair');
            if (inp.val().match(/^\d+$/) && inp.val() == inp.val().match(/^\d+$/)[0]) {
                fs.css('display', 'block');
            } else {
                fs.css('display', 'none');
            }
            inp.keyup(function(){
                if (inp.val().match(/^\d+$/) && inp.val() == inp.val().match(/^\d+$/)[0]) {
                    fs.css('display', 'block');
                } else {
                    fs.css('display', 'none');
                }
            });
        }
    }
})(jQuery, Drupal);

