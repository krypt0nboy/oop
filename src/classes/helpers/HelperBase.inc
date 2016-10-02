<?php

trait_require_once('oop_common');
trait_require_once('templating');

/**
 * Class HelperBase
 */
class HelperBase {

  use OopCommon,
    Templating {
    OopCommon::setUp as oopSetUp;
  }
  /**
   * @const ALIAS
   *   The default data holder property the helper is attached to.
   */
  const ALIAS = '';
  /**
   * @access protected
   * @var object $dataHolder
   *   The object containing the data to help with.
   */
  protected $dataHolder;
  /**
   * @access protected
   * @var string $currentAlias
   *   The current alias.
   */
  protected $currentAlias;
  /**
   * @access protected
   * @var string[] $swaps
   *   An array of strings referring to the data holder properties, available when swapping alias.
   */
  protected $swaps = array();

  /**
   * ToolboxPropertiesHelper constructor.
   *
   * @param array $args
   */
  public function __construct(array $args = array()) {
    $this->setUp($args);
  }

  /**
   * @return object
   */
  public function getDataHolder() {
    return $this->dataHolder;
  }

  /**
   * @param object $dataHolder
   */
  public function setDataHolder($dataHolder) {
    $this->dataHolder = $dataHolder;
  }

  /**
   * @return string
   */
  public function getCurrentAlias() {
    return $this->currentAlias;
  }

  /**
   * @param string $currentAlias
   */
  public function setCurrentAlias($currentAlias) {
    $this->currentAlias = $currentAlias;
  }

  /**
   * @return string[]
   */
  public function getSwaps() {
    return $this->swaps;
  }

  /**
   * @param string[] $swaps
   */
  public function setSwaps($swaps) {
    $this->swaps = $swaps;
  }

  /**
   * Swaps to another alias and sets it as current alias.
   *
   * @param string $swap
   *   The alias to swap to.
   *
   * @return string
   */
  protected function swapAlias($swap) {
    $this->setCurrentAlias($swap);

    return $swap;
  }

  /**
   * Reset the currentAlias to default (constant ALIAS).
   */
  protected function resetAlias() {
    $this->currentAlias = NULL;

    return $this::ALIAS;
  }

  /**
   * Returns the current alias.
   *
   * @return string
   */
  public function currentAlias() {
    return $this->__isset('current_alias') ? $this->getCurrentAlias() : $this::ALIAS;
  }

  /**
   * Indicates if the data holder has a property.
   *
   * @param string $name
   *   The property name.
   * @param bool   $strict
   *   Returns FALSE if property exists but is not set.
   *
   * @return bool
   */
  protected function dataHolderHasProperty($name, $strict = FALSE) {
    $exists = property_exists($this->getDataHolder(), $name);
    if ($strict) {
      return !$exists ? $exists : $this->getDataHolder()->__isset($name);
    }
    else {
      return $exists;
    }
  }

  /**
   * Returns the helper data content.
   *
   * @param null|string $alias
   *   The data holder property to use.
   * @param bool        $swap
   *   Whether to swapAlias.
   *
   * @return mixed
   */
  public function alias($alias = NULL, $swap = FALSE) {
    if (isset($alias)) {
      if ($swap) {
        $alias = $this->swapAlias($alias);
      }
    }
    else {
      $alias = $this->currentAlias();
    }
    if (!empty($alias)) {
      if ($this->dataHolderHasProperty($alias)) {
        return $this->dataHolder->__get($alias);
      }
    }
  }

  /**
   * Returns the number of values for the helper data.
   *
   * @return int
   */
  public function count() {
    return count($this->alias());
  }
}