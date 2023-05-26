#ifndef CATITosIterator_H
#define CATITosIterator_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2008
/**
 * @level Private
 * @usage U3
 */
#include "ExportedByCATPLMTos.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMTos IID IID_CATITosIterator;
#else
extern "C" const IID IID_CATITosIterator ;
#endif

/**
* Interface to browse on a set of objects.
*/
class ExportedByCATPLMTos CATITosIterator : public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Retrieves an interface smart pointer on the next element of the set of objects.
  *
  * @param oNext
  *     The interface smart pointer on the next element.
  * @return
  *     An HRESULT value.
  *     <br><b>Legal values</b>:
  *     <ul>
  *         <li><tt>S_OK</tt> if the next element was successfully retrieved.</li>
  *         <li><tt>E_FAIL</tt> if there is no more element to browse.</li>
  *     </ul>
  */
  virtual HRESULT Next(CATBaseUnknown_var & oNext) = 0;
};

CATDeclareHandler(CATITosIterator, CATBaseUnknown);

#endif
