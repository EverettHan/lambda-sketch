#ifndef CATITosUIDispatcher_H
#define CATITosUIDispatcher_H

#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"
#include "CATLISTV_CATBaseUnknown.h"

extern ExportedByCATPLMTos IID IID_CATITosUIDispatcher;

/**
* Interface needed to dispatch asynchronous events based on GUI state
*/
class ExportedByCATPLMTos CATITosUIDispatcher : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Dispatch asynchronous events
  *
  * @return
  *   <br><b>Legal values</b>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>Everyhting is OK .</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>An error occured  .</dd>
  *   </dl>
  */
  virtual  HRESULT Dispatch() = 0;
};


#endif
