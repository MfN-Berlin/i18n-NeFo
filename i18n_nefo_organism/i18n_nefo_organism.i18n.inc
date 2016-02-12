<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_organism_i18n_string_info() {
  $groups['nefo_organism'] = array(
    'title' => t('NeFo Organism'),
    'description' => t('Configurable NeFo Organism.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_organism_i18n_object_info() {
  $info['nefo_organism'] = array(
    'title' => t('Organism Category'),
    'key' => 'oid',
    'load callback' => 'nefo_organism_load',
    'placeholders' => array(
      '%nefo_organism' => 'oid',
    ),
    'edit path' => 'admin/config/nefo/categories/organisms/%nefo_organism/edit',
    'translate tab' => 'admin/config/nefo/categories/organisms/%nefo_organism/translate',
    'string translation' => array(
      'textgroup' => 'nefo_organism',
      'type' => 'organism',
      'table' => 'nefo__actors_organisms',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/organisms/%nefo_organism/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_organism_i18n_string_list($group) {
  if ($group == 'nefo_organism' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_organisms', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $organism) {
      $strings['nefo_organism']['organism'][$organism->oid]['name'] = $organism->name;
    }

    return $strings;
  }
}


