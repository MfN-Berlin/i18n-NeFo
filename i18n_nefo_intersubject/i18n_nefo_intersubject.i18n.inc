<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_intersubject_i18n_string_info() {
  $groups['nefo_intersubject'] = array(
    'title' => t('NeFo Interdisciplinary Subject'),
    'description' => t('Configurable NeFo Interdisciplinary Subject.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_intersubject_i18n_object_info() {
  $info['nefo_intersubject'] = array(
    'title' => t('Interdisciplinary Subject Category'),
    'key' => 'isid',
    'load callback' => 'nefo_intersubject_load',
    'placeholders' => array(
      '%nefo_intersubject' => 'isid',
    ),
    'edit path' => 'admin/config/nefo/categories/intersubjects/%nefo_intersubject/edit',
    'translate tab' => 'admin/config/nefo/categories/intersubjects/%nefo_intersubject/translate',
    'string translation' => array(
      'textgroup' => 'nefo_intersubject',
      'type' => 'interdisciplinarysubject',
      'table' => 'nefo__actors_interdisciplinary_subject',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/intersubjects/%nefo_intersubject/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_intersubject_i18n_string_list($group) {
  if ($group == 'nefo_intersubject' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_interdisciplinary_subject', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $intersubject) {
      $strings['nefo_intersubject']['interdisciplinarysubject'][$intersubject->isid]['name'] = $intersubject->name;
    }

    return $strings;
  }
}
