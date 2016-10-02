<?php

/**
 * Class ArgsCollectorBase
 */
class ArgsCollectorBase {
  use
    OopCommon {
    OopCommon::setUp as oopSetUp;
  }

  /**
   * @access protected
   * @var array $collection
   *   The arguments collected.
   */
  protected $collection = array();

  /**
   * ArgsCollectorBase constructor.
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * Set up method.
   *
   * @param array $args
   *   The args to use for setup.
   */
  public function setUp(array $args = array()) {
    $this->oopSetUp($args);
  }

  /**
   * @return array
   */
  public function getCollection() {
    return $this->collection;
  }

  /**
   * @param array $collection
   */
  public function setCollection($collection) {
    $this->collection = $collection;
  }
}