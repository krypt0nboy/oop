<?php

/**
 * Class OopCommon
 */
trait OopCommon {
  /**
   * @access protected
   * @var array $constructArgs
   *   The construct arguments.
   */
  protected $constructArgs = array();

  /**
   * __get magic method.
   *
   * @param string $name
   *   The property name.
   *
   * @return mixed
   */
  public function __get($name) {
    $cKey   = str2camelcase($name);
    $method = 'get' . $cKey;
    if (method_exists($this, $method)) {
      return $this->$method();
    }
  }

  /**
   * __set magic method.
   *
   * @param string $name
   *   The property name.
   *
   * @param mixed  $value
   *   The value to set.
   */
  public function __set($name, $value) {
    $cKey   = str2camelcase($name);
    $method = 'set' . $cKey;
    if (method_exists($this, $method)) {
      $this->preSet($name);
      $this->$method($value);
      $this->postSet($cKey, $value);
    }
  }

  /**
   * __isset magic method.
   *
   * @param string $name
   *   The property name.
   *
   * @return bool
   */
  public function __isset($name) {
    $cKey = str2camelcase($name, FALSE);

    return isset($this->{$cKey}) && !empty($this->{$cKey});
  }

  /**
   * __unset magic method.
   *
   * @param string $name
   *   The object property's name.
   */
  public function __unset($name) {
  }

  /**
   * __call magic method.
   *
   * @param string $name
   * @param array  $arguments
   */
  public function __call($name, $arguments) {
  }

  /**
   * @return array
   */
  public function getConstructArgs() {
    return $this->constructArgs;
  }

  /**
   * @param array $constructArgs
   */
  public function setConstructArgs($constructArgs) {
    $this->constructArgs = $constructArgs;
  }

  /**
   * Set up method.
   *
   * @param array $args
   *   The args to use for setup.
   */
  public function setUp(array $args = array()) {
    $this->vedConstructArg($args);
    $this->constructSet($args);
  }

  /**
   * Init phase where construct args are set.
   *
   * @param array $args
   */
  protected function constructSet($args) {
    $this->setConstructArgs($args);
    $this->bulkSet($args);
  }

  /**
   * Sets properties in bulk.
   *
   * @param array $args
   *   The args to set.
   */
  public function bulkSet(array $args = array()) {
    foreach ($args as $argName => $arg) {
      $this->__set($argName, $arg);
    }
  }

  /**
   * Called before __set() method is called.
   *
   * @param string $name
   *   The property's name.
   */
  protected function preSet($name) {
    $cKey   = str2camelcase($name);
    $method = "preSet$cKey";
    if (method_exists($this, $method)) {
      $this->$method();
    }
  }

  /**
   * Called after __set() method has been called.
   *
   * @param string $name
   *   The property's name.
   * @param mixed  $value
   *   The value set.
   */
  protected function postSet($name, $value) {
    $method = "postSet$name";
    if (method_exists($this, $method)) {
      $this->$method($value);
    }
  }

  /**
   * Merge arguments recursively.
   *
   * @param array $args1
   *   The array to add to the initial array.
   * @param array $args2
   *   The initial array.
   *
   * @return array
   */
  protected function mergeArgs(array $args1 = array(), array $args2 = array()) {
    $merged = array_replace_recursive($args1, $args2);

    return $merged;
  }

  /**
   * Checks that every required arg is provided.
   *
   * @param array $args
   *   The construct args to check.
   */
  protected function vedConstructArg(array $args = array()) {

  }
}