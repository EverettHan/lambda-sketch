/**
 * @level Private
 * @usage U3
 */
#ifndef CATIUndoVisitor_H
#define CATIUndoVisitor_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATBaseUnknown.h"

#include "CATObjectModelerItf.h"
extern ExportedByCATObjectModelerItf IID IID_CATIUndoVisitor;
 

/**   
 * This interface provides a Visitor which provides a global treatment at the 
 * end of the visit.
 */
class ExportedByCATObjectModelerItf CATIUndoVisitor: public CATBaseUnknown
{
  CATDeclareInterface;
  
public:
  
  
 /**
  * Operates on the submitted object and returns a continuation code.
  *
  * @param iInstance Object to be performed on.
  * @return S_OK to continue the scan, E_FAIL to stop.
  */ 
  virtual HRESULT   Visit      (CATBaseUnknown* iInstance)=0;
  
  
 /**
  * Operates a global operation after all the visits.
  * @return S_OK if Treatment is OK, E_FAIL if not.
  */ 
  virtual HRESULT   EndVisit      ()=0;
  
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler(CATIUndoVisitor, CATBaseUnknown) ;

#endif
