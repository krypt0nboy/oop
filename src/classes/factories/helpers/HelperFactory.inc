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
      'name' => 'helper'
    ), $args);
    parent::__construct($args);
  }
}