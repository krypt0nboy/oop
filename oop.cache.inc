<?php

/**
 * @file
 *
 * This file provides with cache related functions.
 */

/**
 * The module's cache table name.
 */
define('OOP_DB__CACHE', 'cache_oop');

/**
 * Sets cache in oop cache table.
 *
 * @param string $cid
 *   The cache ID.
 * @param mixed  $data
 *   The data to cache.
 * @param int    $expire
 *   The expiration in seconds.
 */
function oop_cache_set($cid, $data, $expire = CACHE_PERMANENT) {
  generic_cache_set(OOP_DB__CACHE, $cid, $data, $expire);
}

/**
 * Returns cache from cache_oop.
 * Gets the cache from oop cache table.
 *
 * @param $cid
 *   The cache ID.
 *
 * @return null|object
 */
function oop_cache_get($cid) {
  return generic_cache_get(OOP_DB__CACHE, $cid);
}

/**
 * Returns the cache data from oop cache table.
 *
 * @param $cid
 *   The cache ID.
 *
 * @return array|false
 */
function oop_cache_get_data($cid) {
  return generic_cache_get_data(OOP_DB__CACHE, $cid);
}

/**
 * Implements hook_cache_info().
 */
function oop_cache_info() {
  $info                                  = array();
  $info[OOP_DB__CACHE]['class_info']     = array();
  $info[OOP_DB__CACHE]['class_registry'] = array();
  $info[OOP_DB__CACHE]['trait_info']     = array();
  $info[OOP_DB__CACHE]['interface_info'] = array();
  $info[OOP_DB__CACHE]['factory_info']   = array();

  return $info;
}