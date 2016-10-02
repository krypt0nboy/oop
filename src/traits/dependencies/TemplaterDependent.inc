<?php

require_once OOP_PATH . '/src/classes/templaters/TemplaterBase.inc';
require_once OOP_PATH . '/src/classes/factories/templaters/TemplaterFactory.inc';

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
  protected function initTplVars(array $vars = array()) {
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
    return factory('templater')
      ->instance_arg('source', $this)
      ->getInstance($args, FALSE);
  }
}