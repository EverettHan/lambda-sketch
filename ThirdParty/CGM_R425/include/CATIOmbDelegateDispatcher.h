// COPYRIGHT Dassault Systemes 2006
/**
* @level Protected 
* @usage U3
*/ 
//===================================================================
//
// CATIOmbDelegateDispatcher.h
//   Dispatcher associated to CATIOmbDelegateListener.
//
//===================================================================
//
// Usage notes:
//   Notifies the Product Linkable Object on delete or modification of the 
//   Delegate (CATIOmbDelegateObject).
//
//===================================================================
#ifndef CATIOmbDelegateDispatcher_H
#define CATIOmbDelegateDispatcher_H

#include "AC0XXLNK.h"
#include "CATBaseUnknown.h"
class CATIOmbDelegateListener;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAC0XXLNK IID IID_CATIOmbDelegateDispatcher;
#else
extern "C" const IID IID_CATIOmbDelegateDispatcher ;
#endif

//------------------------------------------------------------------

/**
* CATIOmbDelegateDispatcher.
*
* <br><b>Role</b>: The Delegate, @see CATIOmbDelegateObject , implements CATIOmbDelegateDispatcher.
*/
class ExportedByAC0XXLNK CATIOmbDelegateDispatcher: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
  * Add a listener
  * @param iListener
  *        listener interface
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT  AddDelegateListener(CATIOmbDelegateListener* iListener)=0;
  /**
  * Remove a listener
  * @param iListener
  *        listener interface
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT  RemoveDelegateListener(CATIOmbDelegateListener* iListener)=0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(CATIOmbDelegateDispatcher,CATBaseUnknown);

#endif
