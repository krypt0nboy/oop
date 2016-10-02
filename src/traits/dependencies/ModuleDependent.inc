<?php

/**
 * Class ModuleDependent
 */
trait ModuleDependent {
  /**
   * @access protected
   * @var string $moduleName
   *   The module's name.
   */
  protected $moduleName;
  /**
   * @access protected
   * @var int $moduleStatus
   *   The module's status.
   */
  protected $moduleStatus;
  /**
   * @access protected
   * @var array $moduleInfo
   *   The module info.
   */
  protected $moduleInfo = array();
  /**
   * @access protected
   * @var string $modulePath
   *   The module's path.
   */
  protected $modulePath;

  /**
   * @return string
   */
  public function getModuleName() {
    return $this->moduleName;
  }

  /**
   * @param string $moduleName
   */
  public function setModuleName($moduleName) {
    $this->moduleName = $moduleName;
  }

  /**
   * @return int
   */
  public function getModuleStatus() {
    return $this->moduleStatus;
  }

  /**
   * @param int $moduleStatus
   */
  public function setModuleStatus($moduleStatus) {
    $this->moduleStatus = $moduleStatus;
  }

  /**
   * @return array
   */
  public function getModuleInfo() {
    return $this->moduleInfo;
  }

  /**
   * @param array $moduleInfo
   */
  public function setModuleInfo($moduleInfo) {
    $this->moduleInfo = $moduleInfo;
  }

  /**
   * @return string
   */
  public function getModulePath() {
    return $this->modulePath;
  }

  /**
   * @param string $modulePath
   */
  public function setModulePath($modulePath) {
    $this->modulePath = $modulePath;
  }
}