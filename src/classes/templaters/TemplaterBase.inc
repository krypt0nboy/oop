<?php

trait_require_once('oop_common');
trait_require_once('templating');

/**
 * Class TemplaterBase
 */
class TemplaterBase {
  use OopCommon,
    Templating {
    OopCommon::setUp as oopSetUp;
  }

  /**
   * TemplaterBase constructor.
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
}