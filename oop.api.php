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
 *   An associative array where the keys are the class name and the values are :
 *    -
 */
function hook_class_info() {
  $info                   = array();
  $info['templater']      = array(
    'class'   => 'TemplaterBase',
    'info'    => array(
      'base' => 'TemplaterBase',
    ),
    'factory' => 'templater_factory'
  );
  $info['builder_helper'] = array(
    'class'   => 'BuilderHelper',
    'info'    => array(
      'base'  => 'BuilderHelper',
      'model' => '%args%BuilderHelper',
      'args'  => array()
    ),
    'factory' => 'helper_factory'
  );

  return $info;
}

function hook_factory_info() {
  $info = array();

  return $info;
}