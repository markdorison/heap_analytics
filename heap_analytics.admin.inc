<?php

/**
 * @file
 * Administrative page callbacks for the heap_analytics module.
 */

/**
 * Implements hook_admin_settings() for module settings configuration.
 */
function heap_analytics_admin_settings_form($form_state) {
  $form['account'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  $form['account']['heap_analytics_account_id'] = array(
    '#title' => t('Property ID'),
    '#type' => 'textfield',
    '#default_value' => variable_get('heap_analytics_account_id', 'XXXXXXXXX'),
    '#size' => 15,
    '#maxlength' => 20,
    '#required' => TRUE,
    '#description' => t('This unique Heap project ID.'),
  );
  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 */
function heap_analytics_admin_settings_form_validate($form, &$form_state) {
  // Trim text value.
  $form_state['values']['heap_analytics_account_id'] = trim($form_state['values']['heap_analytics_account_id']);
  if (!is_numeric($form_state['values']['heap_analytics_account_id'])) {
    form_set_error('heap_analytics_account_id', t('Invalid Heap Analytics Project ID.'));
  }
}
