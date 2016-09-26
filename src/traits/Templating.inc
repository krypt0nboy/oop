<?php

/**
 * Class Templating
 */
trait Templating {
  /**
   * @access protected
   * @var array $tplVars
   *   The object template vars.
   */
  protected $tplVars = array();
  /**
   * @access protected
   * @var string $selfExtractMrkr
   *   The self extract marker.
   */
  protected $selfExtractMrkr;
  /**
   * @access protected
   * @var string $selfReplaceMrkr
   *   The self replace marker.
   */
  protected $selfReplaceMrkr;
  /**
   * @access protected
   * @var object $source
   *   The object for which the templater exists.
   */
  protected $source;

  /**
   * @return array
   */
  public function getTplVars() {
    return $this->tplVars;
  }

  /**
   * @param array $tplVars
   */
  public function setTplVars($tplVars) {
    $this->tplVars = $tplVars;
  }

  /**
   * @return string
   */
  public function getSelfExtractMrkr() {
    return $this->selfExtractMrkr;
  }

  /**
   * @param string $selfExtractMrkr
   */
  public function setSelfExtractMrkr($selfExtractMrkr) {
    $this->selfExtractMrkr = $selfExtractMrkr;
  }

  /**
   * @return string
   */
  public function getSelfReplaceMrkr() {
    return $this->selfReplaceMrkr;
  }

  /**
   * @param string $selfReplaceMrkr
   */
  public function setSelfReplaceMrkr($selfReplaceMrkr) {
    $this->selfReplaceMrkr = $selfReplaceMrkr;
  }

  /**
   * @return object
   */
  public function getSource() {
    return $this->source;
  }

  /**
   * @param object $source
   */
  public function setSource($source) {
    $this->source = $source;
  }

  /**
   * Updates the templating variables.
   *
   * @param array $vars
   *   The variables to update.
   */
  public function updateTplVars(array $vars = array()) {
    $this->tplVars += $vars;
  }

  /**
   * Updates a templating var.
   *
   * @param string $name
   *   The var name.
   * @param mixed  $var
   *   The var value.
   */
  public function updateTplVar($name, $var) {
    $this->tplVars[$name] = $var;
  }

  /**
   * Self extract method.
   *
   * @return array
   */
  public function extractSelf() {
    return $this->extractTplVars($this->getSource(), $this->selfExtractMrkr, $this->selfReplaceMrkr);
  }

  /**
   * Extracts and flattens variables from a given source.
   *
   * @param mixed  $source
   *   The source to extract from.
   * @param string $extractMrkr
   *   The extract marker.
   * @param string $replaceMrkr
   *   The replace marker.
   *
   * @return array
   */
  public function extractTplVars($source, $extractMrkr, $replaceMrkr) {
    switch (gettype($source)) {
      case 'object':
        break;
      case 'array':
        break;
    }
  }

  /**
   * Process a template.
   *
   * @param string $string
   *   The template to process.
   * @param array  $vars
   *   The vars to process with.
   * @param bool   $strict
   *   If TRUE, the unmatched wildcard will be removed.
   *
   * @return string
   */
  public function process($string, $vars = array(), $strict = FALSE) {
    $processed = tpl_process($string, !empty($vars) ? $vars : $this->tplVars);
    if ($strict && preg_match(RGX__WILDCARD, $processed)) {
      return preg_replace(RGX__WILDCARD, '', $processed);
    }
    else {
      return $processed;
    }
  }

}