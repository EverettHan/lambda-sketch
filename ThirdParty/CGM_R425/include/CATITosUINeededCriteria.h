#ifndef CATITosUINeededCriteria_H
#define CATITosUINeededCriteria_H

/**
 * @level Private
 * @usage U3
 */

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATITosUINeededCriteria;
#else
extern "C" const IID IID_CATITosUINeededCriteria;
#endif

class CATITosUIDispatcher;

/**
* Interface needed to acquire Infrastructure Criteria
*   for genuine TOS service in context of interactive Session
*/

class ExportedByCATPLMTos CATITosUINeededCriteria : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Start redraw controller
  * This controller allows to dispatch redraw asynchronous events
  */
  virtual  void StartRedrawController(CATITosUIDispatcher & iDispatcher) = 0;

  /**
  * End Interactive Session
  */
  virtual  void EndInteractiveSession() = 0;
};


#endif
