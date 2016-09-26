<?php

require_once OOP_PATH . '/src/traits/OopCommon.inc';

/***
 * Class BooleanVariable
 */
class BooleanVariable extends VariableBase {
  /** {{@inheritdoc}} */
  protected $phpType = 'boolean';
}