<?php

require_once OOP_PATH . '/src/classes/factories/helpers/HelperFactory.inc';

/**
 * Class HelperDependent
 */
trait HelperDependent {
  /**
   * @access protected
   * @var HelperBase $helper
   *   The main helper.
   */
  protected $helper;

  /**
   * @return HelperBase
   */
  public function getHelper() {
    return $this->helper;
  }

  /**
   * @param HelperBase $helper
   */
  public function setHelper($helper) {
    $this->helper = $helper;
  }

  /**
   * Instanciates a helper.
   *
   * @param string $type
   *   The helper's type.
   * @param array  $args
   *   The args to pass to the factory.
   *
   * @return HelperBase
   */
  protected function helperGetInstance($type, array $args = array()) {
    $factory = new HelperFactory();
    $args += array(
      'parsing_args'  => array(
        'type' => $type
      ),
      'instance_args' => array(
        'data_holder' => $this
      )
    );

    return $factory->getInstance($args);
  }
}