<?php

trait_require_once('oop_common');
trait_require_once('factory_controls');
trait_require_once('class_dependent');
trait_require_once('class_factoring_dependent');
trait_require_once('module_dependent');
require_once OOP_PATH . '/src/classes/templaters/TemplaterBase.inc';


/**
 * Class FactoryBase
 */
class FactoryBase {
  use OopCommon,
    ClassDependent,
    ClassFactoringDependent,
    ModuleDependent,
    FactoryControls {
    OopCommon::setUp as oopSetUp;
  }

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
    $this->templater = new TemplaterBase(array('source' => $this));
    if (isset($this->classSysId)) {
      // Retrieving class info.
      $this->classInfo     = oop_class_get_info($this->classSysId);
      $this->class_        = $this->classInfo['class_'];
      $this->baseClass     = $this->classInfo['base'];
      $this->moduleName    = $this->classInfo['module'];
      $this->safeClass     = empty($this->classInfo['safe']) ? $this->baseClass : $this->classInfo['safe'];
      $this->dependencyDir = $this->classInfo['dependency dir'];
      // Retrieving module info.
      $this->moduleInfo = module_get_info($this->moduleName);
      $this->modulePath = $this->moduleInfo['path'];
      if (!empty($this->classInfo['model'])) {
        $this->modelClass = $this->classInfo['model']['class'];
        if (!empty($this->classInfo['model']['args'])) {
          $this->modelArgs = $this->classInfo['model']['args'];
        }
      }
      $this->prepare();
    }
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
   * Prepare method.
   */
  public function prepare() {
    $this->patchModelClass();
  }

  /**
   * Guesses and auto sets the safe class.
   */
  protected function autoSetSafeClass() {
    $this->safeClass = $this->baseClass;
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
   * Indicates if a model class has been patched.
   *
   * @return bool
   */
  protected function isModelClassPatched() {
    return isset($this->sourceModelClass);
  }

  /**
   * Process the arguments passed when requesting an instance.
   *
   * @param array $args
   *   The args to process.
   *
   * @return array
   */
  protected function processInstanceRequestArgs(array $args = array()) {
    if (!empty($args['parsing_args'])) {
      $this->setParsingArgs($args['parsing_args']);
    }
    if (!empty($args['instance_args'])) {
      $this->setInstanceArgs($args['instance_args']);
    }
  }

  /**
   * Retrieves the models real args and returns a useable model class.
   */
  protected function patchModelClass() {
    if ($this->hasModelClass()) {
      if (preg_match('/%args%/', $this->modelClass)) {
        $strArgs = array();
        foreach ($this->modelArgs as $strArg) {
          $strArgs[] = "%$strArg%";
        }
        $patch                  = concat('', $strArgs, '');
        $patched                = preg_replace('/%args%/', $patch, $this->modelClass);
        $this->sourceModelClass = $this->modelClass;
        $this->modelClass       = $patched;
      }
    }
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
    $ved    = $this->validateClass($parsed);
    if ($ved) {
      $this->parsedClass = $parsed;
    }

    return $ved ? $parsed : NULL;
  }

  /**
   * Validates a class name.
   *
   * @param string $parsed
   *   The class to validate.
   *
   * @return bool
   */
  protected function validateClass($parsed) {
    $exists = class_exists($parsed);
    if (!$exists) {
      $tryClassFile = $this->buildClassFile($parsed);
      if (file_exists($tryClassFile)) {
        require_once $tryClassFile;
        if (class_exists($parsed)) {
          $exists = TRUE;
          $this->setIncludeRequired(TRUE);
        }
        else {
          $this->instanceClass = $this->safeClass;
        }
      }
    }
    else {
      $this->instanceClass = $this->safeClass;
    }

    return $exists;
  }

  /**
   * Builds the class file.
   *
   * @return string
   */
  protected function buildClassFile($class) {
    $tails = array('src', 'classes', $this->dependencyDir);

    return file_path($class, $this->modulePath, $tails, 'inc');
  }

  /**
   * Requires once a class file.
   */
  protected function requireOnceClassFile() {
    $file = $this->buildClassFile($this->instanceClass);
    $this->setClassFile($file);

    require_once $this->classFile;
  }

  /**
   * Ensures the factory has a valid class to instanciate.
   *
   * @return bool
   */
  protected function ensureClass() {
    if (!isset($this->instanceClass)) {
      if ($this->hasModelClass()) {
        $class = $this->parseModelClass();
        if (isset($class)) {
          $this->setInstanceClass($class);
        }
        else {
          $ved = $this->validateClass($this->class_);
          if ($ved) {
            $this->setInstanceClass($this->class_);
          }
        }
      }
      else {
        $ved = $this->validateClass($this->class_);
        if ($ved) {
          $this->setInstanceClass($this->class_);
        }
      }
    }

    return TRUE;
  }

  /**
   * Flushes the given parameters.
   */
  protected function flush($flush = TRUE) {
    if ($flush) {
      $this->flushExec();
      $this->setFlushed(TRUE);
    }
  }

  /**
   * Flushed the given parameters.
   */
  protected function flushExec() {
    $this->parsingArgs  = array();
    $this->instanceArgs = array();
  }

  /**
   * Instanciates the target class.
   *
   * @param array $args
   *   The args to pass to the instance.
   *
   * @return object
   */
  public function getInstance($args = array(), $flush = TRUE) {
    $this->flush($flush);
    $this->processInstanceRequestArgs($args);
    $this->setFlushed(FALSE);
    $this->ensureClass();
    $class = $this->getInstanceClass();
    if ($this->isIncludeRequired()) {
      $this->requireOnceClassFile();
    }

    return new $class($this->instanceArgs);
  }
}