<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_habitat_i18n_string_info() {
  $groups['nefo_habitat'] = array(
    'title' => t('NeFo Habitat'),
    'description' => t('Configurable NeFo Habitat.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_habitat_i18n_object_info() {
  $info['nefo_habitat'] = array(
    'title' => t('Habitat Category'),
    'key' => 'hid',
    'load callback' => 'nefo_habitat_load',
    'placeholders' => array(
      '%nefo_habitat' => 'hid',
    ),
    'edit path' => 'admin/config/nefo/categories/habitats/%nefo_habitat/edit',
    'translate tab' => 'admin/config/nefo/categories/habitats/%nefo_habitat/translate',
    'string translation' => array(
      'textgroup' => 'nefo_habitat',
      'type' => 'habitat',
      'table' => 'nefo__actors_habitats',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/habitats/%nefo_habitat/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_habitat_i18n_string_list($group) {
  if ($group == 'nefo_habitat' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_habitats', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $habitat) {
      $strings['nefo_habitat']['habitat'][$habitat->hid]['name'] = $habitat->name;
    }

    return $strings;
  }
}
