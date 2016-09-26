<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once OOP_PATH . '/src/classes/templaters/TemplaterBase.inc';

/**
 * Class TemplaterFactory
 */
class TemplaterFactory extends FactoryBase {
  /**
   * TemplaterFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'name' => 'templater'
    ), $args);
    parent::__construct($args);
  }
}