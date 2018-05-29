<?php

class custom_views_handler_filter_authorfilter extends views_handler_filter_in_operator {
    function get_value_options() {
        $users_list = entity_load('user');
        global $user;
        $user = user_load($user->uid);
        foreach ($users_list as $user_item) {
            
            if ($user_item->uid > 1) { //удаляю учётку админа из списка авторов
                if ($user->field_company_link['und'][0]['target_id'] == $user_item->field_company_link['und'][0]['target_id']) {
                $dep = portal_get_depname($user_item->uid);
        $users[$dep][$user_item->uid] = portal_get_user_name($user_item->uid);
            }
            }
        }

        $this->value_options = $users;

        return $users;
    }
    function query() {
        $this->ensure_my_table();
        $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field", $this->value, $this->operator);
    }
}
