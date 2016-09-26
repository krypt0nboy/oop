<?php

require_once OOP_PATH . '/src/classes/factories/FactoryBase.inc';
require_once OOP_PATH . '/src/classes/variables/VariableBase.inc';
require_once OOP_PATH . '/src/classes/variables/php/BooleanVariable.inc';


/**
 * Class VariableFactory
 */
class VariableFactory extends FactoryBase {

  /**
   * TemplaterFactory constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $args = $this->mergeArgs(array(
      'name' => 'variable'
    ), $args);
    parent::__construct($args);
  }

  /**
   * @param       $varType
   * @param array $args
   * @param bool  $flush
   * @return object
   */
  public function propertyGetInstance($varType, $args = array(), $flush = FALSE) {
    $args = $this->mergeArgs(array(
      'parsing_args' => array(
        'var_type' => $varType
      )
    ), $args);

    return $this->getInstance($args, $flush);
  }
}