<?php

/**
 * Class FactoryControls
 */
trait FactoryControls {
  /**
   * Add parsing args.
   *
   * @param array $args
   *   The args to add.
   *
   * @return $this
   */
  function parsing_args(array $args = array()) {
    /** @var FactoryBase $this */
    foreach ($args as $argName => $arg) {
      $this->parsing_arg($argName, $arg);
    }

    return $this;
  }

  /**
   * Add a parsing arg.
   *
   * @param string $argName
   *   The arg name.
   * @param mixed  $arg
   *   The arg value.
   *
   * @return $this
   */
  function parsing_arg($argName, $arg) {
    /** @var FactoryBase $this */
    $this->parsingArgs[$argName] = $arg;

    return $this;
  }

  /**
   * Add instance args.
   *
   * @param array $args
   *   The args to add.
   *
   * @return $this
   */
  function instance_args(array $args = array()) {
    /** @var FactoryBase $this */
    foreach ($args as $argName => $arg) {
      $this->instance_arg($argName, $arg);
    }

    return $this;
  }

  /**
   * Adds an instance arg.
   *
   * @param string $argName
   *   The arg name.
   * @param mixed  $arg
   *   The arg value.
   *
   * @return $this
   */
  function instance_arg($argName, $arg) {
    /** @var FactoryBase $this */
    $this->instanceArgs[$argName] = $arg;

    return $this;
  }
}