<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_network_i18n_string_info() {
  $groups['nefo_network'] = array(
    'title' => t('NeFo Research Network'),
    'description' => t('Configurable NeFo Research Network.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_network_i18n_object_info() {
  $info['nefo_network'] = array(
    'title' => t('Research Network Category'),
    'key' => 'rnid',
    'load callback' => 'nefo_network_load',
    'placeholders' => array(
      '%nefo_network' => 'rnid',
    ),
    'edit path' => 'admin/config/nefo/categories/networks/%nefo_network/edit',
    'translate tab' => 'admin/config/nefo/categories/networks/%nefo_network/translate',
    'string translation' => array(
      'textgroup' => 'nefo_network',
      'type' => 'researchnetwork',
      'table' => 'nefo__actors_research_network',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/networks/%nefo_network/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_network_i18n_string_list($group) {
  if ($group == 'nefo_network' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_research_network', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $network) {
      $strings['nefo_network']['researchnetwork'][$network->rnid]['name'] = $network->name;
    }

    return $strings;
  }
}
