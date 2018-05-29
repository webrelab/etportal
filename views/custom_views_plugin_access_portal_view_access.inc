<?php

class custom_views_plugin_access_portal_view_access extends views_plugin_access {
    function access($account) {
        return portal_check_module_access(array_filter($this->options['module']), array_filter($this->options['role']));
    }
    
    function get_access_callback() {
        return array('portal_check_module_access', array(array_filter($this->options['module']) ,array_filter($this->options['role'])));
    }
    
    function option_definition() {
        $options = parent::option_definition();
        $options['module'] = array('default' => array());
        $options['role'] = array('default' => array());

        return $options;
    }
    
    function summary_title() {
        $count = count($this->options['module']);
        if ($count < 1) {
            return t('No module(s) selected');
        }
        elseif ($count > 1) {
            return t('Multiple modules');
        }
        else {
            $key = key($this->options['module']);
            $module = $this->options['module'][$key];
            return $module;
        }
    }
    
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
        $form['module'] = array(
            '#type' => 'checkboxes',
            '#title' => t('Module'),
            '#default_value' => $this->options['module'],
            '#options' => array(
                'task' => t('Tasks module'),
                'control' => t('Control module'),
                'wish' => t('Wish list module'),
                'sc' => t('Service center'),
                'instruction' => t('Instruction module'),
                'contragent' => t('Contragent module'),
                'websystem' => t('Websystem module'),
            ),
            '#description' => t('Only the checked modules will be able to access this display. Note that users with "access all views" can see any view, regardless of used modules.'),
        );
        $form['role'] = array(
            '#type' => 'checkboxes',
            '#title' => t('Role'),
            '#default_value' => $this->options['role'],
            '#options' => array_map('check_plain', views_ui_get_roles()),
            '#description' => t('Only the checked roles will be able to access this display. Note that users with "access all views" can see any view, regardless of role.'),
        );
    }
    
    function options_validate(&$form, &$form_state) {
        if (!array_filter($form_state['values']['access_options']['module'])) {
            form_error($form['module'], t('You must select at least one role if type is "by role"'));
        }
        if (!array_filter($form_state['values']['access_options']['role'])) {
            form_error($form['role'], t('You must select at least one role if type is "by role"'));
        }
    }
    
    function options_submit(&$form, &$form_state) {
    // I hate checkboxes.
        $form_state['values']['access_options']['module'] = array_filter($form_state['values']['access_options']['module']);
        $form_state['values']['access_options']['role'] = array_filter($form_state['values']['access_options']['role']);
    }
    
    
}
