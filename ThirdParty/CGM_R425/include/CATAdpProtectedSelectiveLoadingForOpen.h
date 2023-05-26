// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATAdpProtectedSelectiveLoadingForOpen.h
// Header definition of CATAdpProtectedSelectiveLoadingForOpen class
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//===================================================================
/**
 * @level Protected
 * @usage U1  
 */

#ifndef CATAdpProtectedSelectiveLoadingForOpen_H_
#define CATAdpProtectedSelectiveLoadingForOpen_H_


#include "IUnknown.h"
#include "CATPLMIntegrationAccess.h"

class CATBaseUnknown;
class CATIAdpErrorMonitor;

/**
 * This set of methods activates some specific selective loading features
 * available during the opening of various plm component.
 *
 * The activated selective loading features will impact all data opening
 * methods, CAA (CATAdpOpener or CATAdpOpenerX) and interactive (Open,
 * Open Advanced methods and related).
 *
 * RFL IMPLEMENT LINKS MANAGEMENT :
 *
 * By default, the RFL implement links are loaded with their aggregating reference.
 * This may lead to long open times and heavy sessions, even for users that don't need
 * to navigate on those links. Disabling RFL implement links loading will improve the
 * situation, at the cost of crippling of commands and interactions working on those links.
 *
 * There is ways of disabling RFL ImplementLinks loading :
 *   * set the CATPLMOpenWithoutFLImplementLinks environment variable to 1 in your CATEnv
 *   * call the following CATAdpSelectiveLoadingForOpen::StopLoadingRFLImplementLinks() method
 *
 * In both cases, if needed, RFL ImplementLinks loading can be reactivated through the
 * following CATAdpSelectiveLoadingForOpen::StartLoadingRFLImplementLinks() methods.
 */
class ExportedByCATPLMIntegrationAccess CATAdpProtectedSelectiveLoadingForOpen
{
public:
  /**
   * Disable the retrieval of RFL implement links for the rest of the session or
   * until StartLoadingRFLImplementLinks is called. Note that the already loaded
   * implement links won't be unloaded.
   *
   * @return
   *   S_OK         : if the RFL Implement links won't be loaded anymore.
   *   S_FALSE      : if the RFL Implement links were already not loaded (through a previous
   *                  call to this method or CATPLMOpenWithoutFLImplementLinks variable is set).
   *   E_UNEXPECTED : in case of internal error.
   */
  static HRESULT StopLoadingRFLImplementLinks();

  /**
   * Load the implement links for all references in session and re-enable their retrieval
   * for the rest of the session or StartLoadingRFLImplementLinks is called.
   *
   * @param iopErrorReviewer [in]:
   *   The ErrorReviewer dedicated to store and handle all PLM Errors raised during the
   *   execution of this service.
   *
   * @return
   *   S_OK    : if the RFL Implement links have been loaded and will be loaded during next opens.
   *   S_FALSE : if the RFL Implement links loading was already activated (through a previous
   *             call to this method or absence of CATPLMOpenWithoutFLImplementLinks variable).
   *   E_FAIL  : in case of internal error, most probably during the load of missing RFL implement
   *             links. Refer to CATIAdpPLMErrorReviewer content for details.
   */
  static HRESULT StartLoadingRFLImplementLinks(CATIAdpErrorMonitor * iopErrorMonitor = NULL);
};
#endif /* CATAdpProtectedSelectiveLoadingForOpen_H_ */
