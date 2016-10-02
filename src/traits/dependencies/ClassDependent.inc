<?php

/**
 * Class ClassDependent
 */
trait ClassDependent {
  /**
   * @access protected
   * @var string $class_
   *   The class name.
   */
  protected $class_;
  /**
   * @access protected
   * @var string $classFileName
   *   The class file name, without the extension.
   */
  protected $classFileName;
  /**
   * @access protected
   * @var string $classFilePath
   *   The path leading to the class file.
   */
  protected $classFilePath;
  /**
   * @access protected
   * @var string $classFile
   *   The complete and valid class file path.
   */
  protected $classFile;

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
   * @return string
   */
  public function getClassFileName() {
    return $this->classFileName;
  }

  /**
   * @param string $classFileName
   */
  public function setClassFileName($classFileName) {
    $this->classFileName = $classFileName;
  }

  /**
   * @return string
   */
  public function getClassFilePath() {
    return $this->classFilePath;
  }

  /**
   * @param string $classFilePath
   */
  public function setClassFilePath($classFilePath) {
    $this->classFilePath = $classFilePath;
  }

  /**
   * @return string
   */
  public function getClassFile() {
    return $this->classFile;
  }

  /**
   * @param string $classFile
   */
  public function setClassFile($classFile) {
    $this->classFile = $classFile;
  }
}