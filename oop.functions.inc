<?php

/**
 * @file
 *
 * This file provides with basic functions required by this module.
 */

/**
 * Requires once a class.
 *
 * @param string $class_sys_id
 *   The class system unique identifier.
 *
 * @return bool
 *   Returns TRUE if the class was successfully required.
 */
function require_class_once($class_sys_id) {

}

/**
 * Requires once a trait.
 *
 * @param string $trait_sys_id
 *   The trait system unique identifier.
 *
 * @return bool
 *   Returns TRUE if the trait was successfully required.
 */
function trait_require_once($trait_sys_id) {
  $info = oop_trait_get_info($trait_sys_id);
  if (($file = $info['file']['file']) !== NULL) {
    require_once $file;
  }
}

/**
 * Returns a helper instance.
 *
 * @param       $sys_id
 * @param array $args
 *
 * @return HelperBase
 */
function helper($sys_id, array $args = array()) {
  /** @var HelperFactory $factory */
  $factory = factory('helper');

  return $factory
    ->parsing_arg('type', $sys_id)
    ->getInstance($args, FALSE);
}