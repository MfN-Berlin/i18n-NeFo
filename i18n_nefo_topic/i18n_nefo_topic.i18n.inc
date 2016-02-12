<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_string_info().
 */
function i18n_nefo_topic_i18n_string_info() {
  $groups['nefo_topic'] = array(
    'title' => t('NeFo Topic'),
    'description' => t('Configurable NeFo Topic.'),
    'format' => FALSE,
    'list' => TRUE,
  );

  return $groups;
}

/**
 * Implements hook_i18n_object_info().
 */
function i18n_nefo_topic_i18n_object_info() {
  $info['nefo_topic'] = array(
    'title' => t('Topic Category'),
    'key' => 'tid',
    'load callback' => 'nefo_topic_load',
    'placeholders' => array(
      '%nefo_topic' => 'tid',
    ),
    'edit path' => 'admin/config/nefo/categories/topics/%nefo_topic/edit',
    'translate tab' => 'admin/config/nefo/categories/topics/%nefo_topic/translate',
    'string translation' => array(
      'textgroup' => 'nefo_topic',
      'type' => 'topic',
      'table' => 'nefo__actors_topics',
      'properties' => array(
        'name' => t('Name'),
      ),
      'translate path' => 'admin/config/nefo/categories/topics/%nefo_topic/translate/%i18n_language',
    )
  );

  return $info;
}

/**
 * Implements hook_i18n_string_list().
 */
function i18n_nefo_topic_i18n_string_list($group) {
  if ($group == 'nefo_topic' || $group == 'all') {
    $strings = array();
    $query = db_select('nefo__actors_topics', 't')->fields('t');
    $result = $query->execute()->fetchAll();
    foreach ($result as $topic) {
      $strings['nefo_topic']['topic'][$topic->tid]['name'] = $topic->name;
    }

    return $strings;
  }
}


