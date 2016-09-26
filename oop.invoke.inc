<?php

/**
 * @file
 *
 * This file provide with hook invoke functions.
 */

/**
 * Returns a class info.
 *
 * @param null|string $class
 *   The class to get info on.
 *
 * @return array
 */
function oop_class_get_info($class = NULL) {
  $hook = 'class_info';
  $cid  = 'class_info';

  static $drupal_static;
  if (!isset($drupal_static)) {
    $drupal_static[$cid] = &drupal_static(__FUNCTION__);
  }

  $class_info = &$drupal_static[$cid];
  if (empty($class_info)) {
    if ($cache = oop_cache_get($cid)) {
      $class_info = $cache->data;
    }
    else {
      $invoke = invoke_and_alter($hook);
      $buffer = array();
      foreach ($invoke as $machine_name_class => $info) {
        $buffer[$machine_name_class] = $info;
      }
      $class_info = $buffer;
      oop_cache_set($cid, $class_info);
    }
  }

  return isset($class) ? $class_info[$class] : $class_info;
}