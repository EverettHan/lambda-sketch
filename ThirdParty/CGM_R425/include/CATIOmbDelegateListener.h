// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected 
* @usage U5
*/ 
//===================================================================
//
// CATIOmbDelegateListener.h
//   listener associated to CATIOmbDelegateDispatcher
//
//===================================================================
//
// Usage notes:
//   implemented by the Product Linkable Object to handle delete or modification 
//   of the Delegate, CATIOmbDelegateObject.
//
//===================================================================
#ifndef CATIOmbDelegateListener_H
#define CATIOmbDelegateListener_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbDelegateListener;
#else
extern "C" const IID IID_CATIOmbDelegateListener ;
#endif

//------------------------------------------------------------------

/**
* CATIOmbDelegateListener.
*
* <br><b>Role</b>: The Product Linkable Object implements CATIOmbDelegateListener.
*/
class ExportedByAC0XXLNK CATIOmbDelegateListener: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * informs the PLO that a delegate has been deleted
  * @return
  *        S_OK, E_FAIL
  */
  virtual HRESULT  NotifiedOnDelete()=0;
	
  /**
  * informs the PLO that a delegate has been modified
  * @return
  *        S_OK, E_FAIL
  */	
  virtual HRESULT  NotifiedOnModify()=0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIOmbDelegateListener,CATBaseUnknown);

#endif
