<?php

/**
 * @file
 *  Administration callbacks.
 */

function i18n_hreflang_admin($form, &$form_state) {
  $languages = language_list('enabled');
  $options = array();
  // remove all disabled translations
  if (!empty($languages[1])){
    foreach ($languages[1] as $lang) {
      $options[$lang->language] = $lang->name;
    }
  }
  $form['i18n_hreflang_default'] = array(
    '#type' => 'select',
    '#title' => t('Default language'),
    '#options' => $options,
    '#default_value' => variable_get('i18n_hreflang_default', ''),
  );
  return system_settings_form($form);
}
