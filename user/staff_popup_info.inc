<?php
function portal_staff_popup_info($staff) {
    $nw = entity_metadata_wrapper('node', $staff);
    $staff_name = portal_get_user_name($nw->field_user_link->raw());
    $link_opts = array('query' => array('field_appointed_link' => $nw->getIdentifier()));
    $task_link = '<i class="fi-clock"> </i>' . l('задача', '/node/add/task', $link_opts) . ' ';
    $control_link = '<i class="fi-graph-bar"> </i>' . l('контроль', '/node/add/control', $link_opts);
    $staff_image_uri = $nw->field_image->value()['uri'];
    $staff_image_uri = !empty($staff_image_uri) ? $staff_image_uri : 'public://default_images/default-user.png';
    $staff_image_url = image_style_url('foto_270x350', $staff_image_uri);
    $staff_image = theme_image(array(
        'path' => $staff_image_url,
        'width' => NULL,
        'height' => NULL,
        'alt' => $staff_name,
        'title' => $staff_name,
        'attributes' => NULL
    ));
    $staff_name = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'popup-staff-name'
            ),
            '#value' => $staff_name,
        )
    ));
    $staff_image = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'table-cell'
            ),
            '#value' => $staff_image,
        )
    ));
    $staff_dep = '';
    if ($nw->field_departments_link->raw()) {
        $staff_deps = $nw->field_departments_link;
        $staff_dep_arr = array();
        foreach ($staff_deps as $item){
            $staff_dep_arr[] = $item->value()->title;
        }
        unset($staff_dep_arr[0]);
        $staff_dep = implode(', ', $staff_dep_arr);
        $staff_dep = theme_html_tag(array(
            'element' => array(
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'popup-staff-department'
                ),
                '#value' => $staff_dep,
                '#value_prefix' => '<b>Отдел: </b>'
            )
        ));
    }
    $staff_function = '';
    if ($nw->field_sm_function->value()) {
        $staff_function = theme_html_tag(array(
            'element' => array(
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'popup-staff-function'
                ),
                '#value' => $nw->field_sm_function->label(),
                '#value_prefix' => '<b>Должность: </b>'
            )
        ));
    }
    $staff_mobile = '';
    if ($nw->field_sm_mobile->value()) {
        $staff_mobile = $nw->field_sm_mobile->value()['value'];
        $staff_mobile = theme_html_tag(array(
            'element' => array(
                '#tag' => 'div',
                '#attributes' => array(
                    'class' => 'popup-staff-function'
                ),
                '#value' => $staff_mobile,
                '#value_prefix' => '<b>Телефон: </b>'
            )
        ));
    }
    $links = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'popup-staff-actions'
            ),
            '#value' => $task_link . $control_link,
            '#value_prefix' => '<b>Действия: </b>'
        )
    ));
    $info = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'table-cell'
            ),
            '#value' => $staff_name . $staff_dep . $staff_function . $staff_mobile . $links,
        )
    ));
    $popup = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'reveal-scroll-wrapper',
            ),
            '#value' => $staff_image . $info
        )
    ));
    $popup = theme_html_tag(array(
        'element' => array(
            '#tag' => 'div',
            '#attributes' => array(
                'class' => 'reveal-modal popup-staff',
                'id' => 'modal-' . $nw->getIdentifier(),
                'data-reveal' => '',
                'aria-labelledby' => 'firstModalTitle',
                'aria-hidden' => 'true',
                'role' => 'dialog',
            ),
            '#value' => $popup,
            '#value_suffix' => '<a class="close-reveal-modal" aria-label="Close">&#215;</a>',
        )
    ));
    return $popup;
}
?>
