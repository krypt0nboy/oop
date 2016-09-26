<?php

require_once OOP_PATH . '/src/traits/OopCommon.inc';
require_once OOP_PATH . '/src/classes/templaters/TemplaterBase.inc';

/**
 * Class FactoryBase
 */
class FactoryBase {
  use OopCommon{
    OopCommon::setUp as oopSetUp;
  }

  /**
   * @access protected
   * @var string $name
   *   The class machine name.
   */
  protected $name;
  /**
   * @access protected
   * @var string $class_
   *   The class to instanciate.
   */
  protected $class_;
  /**
   * @access protected
   * @var string $baseClass
   *   The target object base class.
   */
  protected $baseClass;
  /**
   * @access protected
   * @var array $classInfo
   *   The class info.
   */
  protected $classInfo = array();
  /**
   * @access protected
   * @var bool $requiresParsing
   *   Indicates if the factory needs to parse the model class before instanciating.
   */
  protected $requiresParsing;
  /**
   * @access protected
   * @var string $modelClass
   *   The model to be parsed to obtain the final class.
   */
  protected $modelClass;
  /**
   * @access protected
   * @var array $modelClassArgs
   *   The model args.
   */
  protected $modelClassArgs = array();
  /**
   * @access protected
   * @var array $parsingArgs
   *   The class parsing args.
   */
  protected $parsingArgs = array();
  /**
   * @access protected
   * @var string $parsedClass
   *   The parsed model class.
   */
  protected $parsedClass;
  /**
   * @access protected
   * @var string $instanceClass
   *   The class to use when instanciating.
   */
  protected $instanceClass;
  /**
   * @access protected
   * @var array $instanceArgs
   *   The arguments to pass when instanciating the target object.
   */
  protected $instanceArgs = array();
  /**
   * @access protected
   * @var TemplaterBase $templater
   *   The factory templater.
   */
  protected $templater;

  /**
   * FactoryBase constructor.
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
    $this->classInfo = oop_class_get_info($this->name);
    $this->class_    = $this->classInfo['class'];
    $this->baseClass = $this->classInfo['info']['base'];
    if (!empty($this->classInfo['info']['model'])) {
      $this->modelClass = $this->classInfo['info']['model'];
    }
    $this->requiresParsing = isset($this->modelClass);
    if ($this->requiresParsing) {
      $this->templater = new TemplaterBase(array('source' => $this));
    }
    $this->prepare();
  }

  /**
   * Prepare method.
   */
  public function prepare() {
    if ($this->hasModelClass()) {
      $this->patchModelClass();
    }
  }

  /**
   * @return string
   */
  public function getName() {
    return $this->name;
  }

  /**
   * @param string $name
   */
  public function setName($name) {
    $this->name = $name;
  }

  /**
   * @return string
   */
  public function getBaseClass() {
    return $this->baseClass;
  }

  /**
   * @param string $baseClass
   */
  public function setBaseClass($baseClass) {
    $this->baseClass = $baseClass;
  }

  /**
   * @return array
   */
  public function getClassInfo() {
    return $this->classInfo;
  }

  /**
   * @param array $classInfo
   */
  public function setClassInfo($classInfo) {
    $this->classInfo = $classInfo;
  }

  /**
   * @return string
   */
  public function getModelClass() {
    return $this->modelClass;
  }

  /**
   * @param string $modelClass
   */
  public function setModelClass($modelClass) {
    $this->modelClass = $modelClass;
  }

  /**
   * @return string
   */
  public function getParsedClass() {
    return $this->parsedClass;
  }

  /**
   * @param string $parsedClass
   */
  public function setParsedClass($parsedClass) {
    $this->parsedClass = $parsedClass;
  }

  /**
   * @return array
   */
  public function getInstanceArgs() {
    return $this->instanceArgs;
  }

  /**
   * @param array $instanceArgs
   */
  public function setInstanceArgs($instanceArgs) {
    $this->instanceArgs = $instanceArgs;
  }

  /**
   * @return boolean
   */
  public function getRequiresParsing() {
    return $this->requiresParsing;
  }

  /**
   * @param boolean $requiresParsing
   */
  public function setRequiresParsing($requiresParsing) {
    $this->requiresParsing = $requiresParsing;
  }

  /**
   * @return string
   */
  public function getInstanceClass() {
    return $this->instanceClass;
  }

  /**
   * @param string $instanceClass
   */
  public function setInstanceClass($instanceClass) {
    $this->instanceClass = $instanceClass;
  }

  /**
   * @return string
   */
  public function getClass() {
    return $this->class_;
  }

  /**
   * @param string $class_
   */
  public function setClass($class_) {
    $this->class_ = $class_;
  }

  /**
   * @return array
   */
  public function getModelClassArgs() {
    return $this->modelClassArgs;
  }

  /**
   * @param array $modelClassArgs
   */
  public function setModelClassArgs($modelClassArgs) {
    $this->modelClassArgs = $modelClassArgs;
  }

  /**
   * @return array
   */
  public function getParsingArgs() {
    return $this->parsingArgs;
  }

  /**
   * @param array $parsingArgs
   */
  public function setParsingArgs($parsingArgs) {
    $this->parsingArgs = $parsingArgs;
  }

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
   * Indicates if a model class is set.
   *
   * @return bool
   */
  protected function hasModelClass() {
    return isset($this->modelClass);
  }

  /**
   * Parse the model class to obtain a valid class name.
   *
   * @param bool $autoSet
   *   Whether to autoset modelClass or not.
   *
   * @return string
   */
  protected function parseModelClass($autoSet = TRUE) {
    $parsed = $this->getTemplater()
                   ->process($this->modelClass, $this->parsingArgs, TRUE);
    $ved    = $this->validateParsedClass($parsed);
    if ($autoSet && $ved) {
      $this->parsedClass = $parsed;
    }

    return $parsed;
  }

  /**
   * Retrieves the models real args and returns a useable model class.
   */
  protected function patchModelClass() {
    if (preg_match('/%args%/', $this->modelClass)) {
      $strArgs = array();
      foreach ($this->classInfo['info']['args'] as $strArg) {
        $strArgs[] = "%$strArg%";
      }
      $patch            = concat('', $strArgs, '');
      $patched          = preg_replace('/%args%/', $patch, $this->modelClass);
      $this->modelClass = $patched;
    }
  }

  /**
   * Validates a class name.
   *
   * @param string $parsed
   *   The class to validate.
   *
   * @return bool
   */
  protected function validateParsedClass($parsed) {
    $exists = class_exists($parsed);

    return $exists;
  }

  /**
   * Ensures the factory has a valid class to instanciate.
   *
   * @return bool
   */
  protected function ensureClass() {
    if (!isset($this->instanceClass)) {
      if ($this->hasModelClass()) {
        $this->parseModelClass();
        $class = $this->getParsedClass();
        $this->setInstanceClass($class);
      }
      else {
        $class = class_exists($this->class_) ? $this->class_ : $this->baseClass;
        $this->setInstanceClass($class);
      }
    }

    return TRUE;
  }

  /**
   * Instanciates the target class.
   *
   * @param array $args
   *   The args to pass to the instance.
   *
   * @return object
   */
  public function getInstance($args = array(), $flush = FALSE) {
    $this->bulkSet($args);
    $this->ensureClass();
    $class = $this->getInstanceClass();

    return new $class($this->instanceArgs);
  }
}