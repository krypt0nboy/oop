<?php

/**
 * Class ClassFactoringDependent
 */
trait ClassFactoringDependent {
  /**
   * @access protected
   * @var string $classSysId
   *   The class system unique identifier.
   */
  protected $classSysId;
  /**
   * @access protected
   * @var array $classInfo
   *   The class info.
   * @see hook_class_info().
   */
  protected $classInfo = array();
  /**
   * @access protected
   * @var string $safeClass
   *   The safe class.
   */
  protected $safeClass;
  /**
   * @access protected
   * @var string $baseClass
   *   The base class.
   */
  protected $baseClass;
  /**
   * @access protected
   * @var string $modelClass
   *   The model class to be parsed.
   */
  protected $modelClass;
  /**
   * @access protected
   * @var string $sourceModelClass
   *   The unpatched model class.
   *   Set only when the model class has been patched.
   */
  protected $sourceModelClass;
  /**
   * @access protected
   * @var array $modelArgs
   *   The model arguments to be used when patching the model.
   */
  protected $modelArgs = array();
  /**
   * @access protected
   * @var array $parsingArgs
   *   The args to use when parsing the model class.
   */
  protected $parsingArgs = array();
  /**
   * @access protected
   * @var string $parsedClass
   *   The parsed class.
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
   * @var string $dependencyDir
   *   The dependency dir where to find the class file.
   */
  protected $dependencyDir;
  /**
   * @access protected
   * @var bool $includeRequired
   *   Whether the class should be included before instanciating.
   */
  protected $includeRequired;
  /**
   * @access protected
   * @var array $instanceArgs
   *   The arguments to pass to the instanciated class.
   */
  protected $instanceArgs = array();
  /**
   * @access protected
   * @var bool $flushed
   *   If the factory has been flushed.
   */
  protected $flushed;

  /**
   * @return string
   */
  public function getClassSysId() {
    return $this->classSysId;
  }

  /**
   * @param string $classSysId
   */
  public function setClassSysId($classSysId) {
    $this->classSysId = $classSysId;
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
  public function getSafeClass() {
    return $this->safeClass;
  }

  /**
   * @param string $safeClass
   */
  public function setSafeClass($safeClass) {
    $this->safeClass = $safeClass;
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
  public function getSourceModelClass() {
    return $this->sourceModelClass;
  }

  /**
   * @param string $sourceModelClass
   */
  public function setSourceModelClass($sourceModelClass) {
    $this->sourceModelClass = $sourceModelClass;
  }

  /**
   * @return array
   */
  public function getModelArgs() {
    return $this->modelArgs;
  }

  /**
   * @param array $modelArgs
   */
  public function setModelArgs($modelArgs) {
    $this->modelArgs = $modelArgs;
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
  public function getDependencyDir() {
    return $this->dependencyDir;
  }

  /**
   * @param string $dependencyDir
   */
  public function setDependencyDir($dependencyDir) {
    $this->dependencyDir = $dependencyDir;
  }

  /**
   * @return boolean
   */
  public function isIncludeRequired() {
    return $this->includeRequired;
  }

  /**
   * @param boolean $includeRequired
   */
  public function setIncludeRequired($includeRequired) {
    $this->includeRequired = $includeRequired;
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
  public function isFlushed() {
    return $this->flushed;
  }

  /**
   * @param boolean $flushed
   */
  public function setFlushed($flushed) {
    $this->flushed = $flushed;
  }
}