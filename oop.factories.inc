<?php

/**
 * @file
 *
 * This file provides with factories related functions.
 */

/**
 * Returns a Factory.
 *
 * @param string $sys_id
 *   The target base $sys_id.
 *
 * @return FactoryBase
 */
function factory($sys_id) {
  $info          = oop_class_get_info($sys_id);
  $factory_info  = oop_factory_get_info($info['factory']);
  $factory_class = $factory_info['class'];
  if (class_exists($factory_class)) {
    return new $factory_class();
  }
  else {
    require_once $factory_info['file']['file'];
    return new $factory_class();
  }
}