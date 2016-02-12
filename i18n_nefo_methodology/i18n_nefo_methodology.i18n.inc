<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_methodology_i18n_string_info() {
  $groups['nefo_methodology'] = array(
    'title' => t('NeFo Methodology'),
    'description' => t('Configurable NeFo Methodology.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_methodology_i18n_object_info() {
  $info['nefo_methodology'] = array(
    'title' => t('Methodology Category'),
    'key' => 'mid',
    'load callback' => 'nefo_methodology_load',
    'placeholders' => array(
      '%nefo_methodology' => 'mid',
    ),
    'edit path' => 'admin/config/nefo/categories/methodologies/%nefo_methodology/edit',
    'translate tab' => 'admin/config/nefo/categories/methodologies/%nefo_methodology/translate',
    'string translation' => array(
      'textgroup' => 'nefo_methodology',
      'type' => 'methodology',
      'table' => 'nefo__actors_methodology',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/methodologies/%nefo_methodology/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_methodology_i18n_string_list($group) {
  if ($group == 'nefo_methodology' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_methodology', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $methodology) {
      $strings['nefo_methodology']['methodology'][$methodology->mid]['name'] = $methodology->name;
    }

    return $strings;
  }
}


