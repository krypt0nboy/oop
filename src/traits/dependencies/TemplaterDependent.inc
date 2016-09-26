<?php

require_once OOP_PATH . '/src/classes/templaters/TemplaterBase.inc';

/**
 * Class TemplaterDependent
 */
trait TemplaterDependent {
  /**
   * @access protected
   * @var TemplaterBase $templater
   *   The factory templater.
   */
  protected $templater;

  /**
   * @return TemplaterBase
   */
  public function getTemplater() {
    return $this->templater;
  }

  /**
   * @param TemplaterBase $templater
   */
  public function setTemplater(TemplaterBase $templater) {
    $this->templater = $templater;
  }

  /**
   * Initialize templating vars.
   *
   * @param array $vars
   *   The vars to init.
   */
  public function initTplVars(array $vars = array()) {
    $this->templater->setTplVars($vars);
  }

  /**
   * Instanciates a templater object.
   *
   * @param array $args
   *   The construct args to pass to the templater factory.
   *
   * @return TemplaterBase
   */
  public function templaterGetInstance(array $args = array()) {
    $factory = new TemplaterFactory();
    $args += array(
      'source' => $this
    );

    return $factory->getInstance($args);
  }
}