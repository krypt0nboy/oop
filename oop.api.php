<?php

/**
 * @file
 *
 * This file provides with an API documentation.
 */

/**
 * Declares a class name and the parameters to instanciante it.
 *
 * @return array
 *   An associative array where the keys are the class system ID and the values are :
 *    -
 */
function hook_class_info() {
  $info            = array();
  $info['builder'] = array(
    'safe'           => 'BuilderBase',
    'class_'         => 'BuilderBase',
    'base'           => 'BuilderBase',
    'model'          => array(
      'class' => '%args%Builder',
      'args'  => array(
        'builder_sys_id'
      )
    ),
    'file'           => array(
      'name' => '',
      'path' => '',
      'file' => '',
    ),
    'module'         => 'oop',
    'dependency dir' => 'builders',
    'factory'        => 'builder_factory',
  );

  return $info;
}

/**
 * Declares a factory.
 *
 * @return array
 *   An associative array where the keys are the factory system ID and the values are :
 *    -
 */
function hook_factory_info() {
  $info          = array();
  $info['model'] = array(
    'module' => 'oop',
    'class'  => 'ModelFactory',
    'file'   => array(
      'name' => 'ModelFactory',
      'dir'  => 'models',
      'path' => '',
      'file' => '',
    ),
  );

  return $info;
}

/**
 * Declares a trait.
 *
 * @return array
 *   An associative array where the keys are the trait system ID and the values are :
 *    -
 */
function hook_trait_info() {
  $info               = array();
  $info['oop_common'] = array(
    'module' => 'oop',
    'file'   => array(
      'name' => 'OopCommon',
      'path' => '',
      'file' => '',
    ),
  );

  return $info;
}