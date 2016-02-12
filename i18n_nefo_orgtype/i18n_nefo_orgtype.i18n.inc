<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_orgtype_i18n_string_info() {
  $groups['nefo_orgtype'] = array(
    'title' => t('NeFo Organization Type'),
    'description' => t('Configurable NeFo Organization Type.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_orgtype_i18n_object_info() {
  $info['nefo_orgtype'] = array(
    'title' => t('Organization Type Category'),
    'key' => 'otid',
    'load callback' => 'nefo_orgtype_load',
    'placeholders' => array(
      '%nefo_orgtype' => 'otid',
    ),
    'edit path' => 'admin/config/nefo/institutions/organizationtypes/%nefo_orgtype/edit',
    'translate tab' => 'admin/config/nefo/institutions/organizationtypes/%nefo_orgtype/translate',
    'string translation' => array(
      'textgroup' => 'nefo_orgtype',
      'type' => 'orgtype',
      'table' => 'nefo__actors_organization_type',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/institutions/organizationtypes/%nefo_orgtype/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_orgtype_i18n_string_list($group) {
  if ($group == 'nefo_orgtype' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_organization_type', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $orgtype) {
      $strings['nefo_orgtype']['orgtype'][$orgtype->otid]['name'] = $orgtype->name;
    }

    return $strings;
  }
}


