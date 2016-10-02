<?php

/**
 * Class HelperFactory
 */
class HelperFactory extends FactoryBase {
  /**
   * HelperFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'class_sys_id' => 'helper'
    ), $args);
    parent::__construct($args);
  }
}