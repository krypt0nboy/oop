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
 *   The class to get info about.
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
      $implement = module_implements($hook);
      $buffer    = array();
      foreach ($implement as $module) {
        $function = concat($module, $hook);
        $invoke   = $function();
        foreach ($invoke as $machine_name_class => $info) {
          $info['module']              = !empty($info['module']) ? $info['module'] : $module;
          $buffer[$machine_name_class] = $info;
        }
      }
      $class_info = $buffer;
      oop_cache_set($cid, $class_info);
    }
  }

  return isset($class) ? $class_info[$class] : $class_info;
}

/**
 * Returns a factory info.
 *
 * @param null|string $factory
 *   The factory to get info about.
 *
 * @return array
 */
function oop_factory_get_info($factory = NULL) {
  $hook = 'factory_info';
  $cid  = 'factory_info';

  static $drupal_static;
  if (!isset($drupal_static)) {
    $drupal_static[$cid] = &drupal_static(__FUNCTION__);
  }

  $factory_info = &$drupal_static[$cid];
  if (empty($factory_info)) {
    if ($cache = oop_cache_get($cid)) {
      $factory_info = $cache->data;
    }
    else {
      $implement = module_implements($hook);
      $buffer    = array();
      foreach ($implement as $module) {
        $function = concat($module, $hook);
        $invoke   = $function();
        foreach ($invoke as $machine_name_factory => $info) {
          $info['module']                = !empty($info['module']) ? $info['module'] : $module;
          $info['file']['name']          = !empty($info['file']['name']) ? $info['file']['name'] : str2camelcase($machine_name_factory);
          $info['file']['path']          = !empty($info['file']['path']) ? $info['file']['path'] : paths_join(module_get_path($module), array(
            'src/classes/factories',
            !empty($info['file']['dir']) ? $info['file']['dir'] : ''
          ));
          $info['file']['file']          = !empty($info['file']['file']) ? $info['file']['file'] : file_path($info['file']['name'], $info['file']['path'], array(), 'inc');
          $buffer[$machine_name_factory] = $info;
        }
      }
      $factory_info = $buffer;
      oop_cache_set($cid, $factory_info);
    }
  }

  return isset($factory) ? $factory_info[$factory] : $factory_info;
}

/**
 * Returns a factory info.
 *
 * @param null|string $trait
 *   The trait to get info about.
 *
 * @return array
 */
function oop_trait_get_info($trait = NULL) {
  $hook = 'trait_info';
  $cid  = 'trait_info';

  static $drupal_static;
  if (!isset($drupal_static)) {
    $drupal_static[$cid] = &drupal_static(__FUNCTION__);
  }

  $trait_info = &$drupal_static[$cid];
  if (empty($trait_info)) {
    if ($cache = oop_cache_get($cid)) {
      $trait_info = $cache->data;
    }
    else {
      $implement = module_implements($hook);
      $buffer    = array();
      foreach ($implement as $module) {
        $function = concat($module, $hook);
        $invoke   = $function();
        foreach ($invoke as $machine_name_trait => $info) {
          $info['module']              = !empty($info['module']) ? $info['module'] : $module;
          $info['file']['name']        = !empty($info['file']['name']) ? $info['file']['name'] : str2camelcase($machine_name_trait);
          $info['file']['path']        = !empty($info['file']['path']) ? $info['file']['path'] : paths_join(module_get_path($module), array('src/traits'));
          $info['file']['file']        = !empty($info['file']['file']) ? $info['file']['file'] : file_path($info['file']['name'], $info['file']['path'], array(), 'inc');
          $buffer[$machine_name_trait] = $info;
        }
      }
      $trait_info = $buffer;
      oop_cache_set($cid, $trait_info);
    }
  }

  return isset($trait) ? $trait_info[$trait] : $trait_info;
}