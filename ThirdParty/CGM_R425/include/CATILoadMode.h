// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATILoadMode.h
// Interface used to specify how to load containers
//
//===================================================================
//
// Usage notes:
//   Appli : set and get loading mode
//   Document implementation : define list of containers to be loaded
//
//===================================================================
//
//  May 2002  Creation: Code generated by the CAA wizard
//===================================================================
#ifndef CATILoadMode_H
#define CATILoadMode_H

/**
* @level Private
* @usage U3
*/

#include "AD0XXBAS.h"
#include "CATBaseUnknown.h"
#include "CATBooleanDef.h"
#include "CATCollec.h"
//

class CATUnicodeString;
class CATILoadModeListener;
class CATIContainer;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByAD0XXBAS IID IID_CATILoadMode;
#else
extern "C" const IID IID_CATILoadMode ;
#endif

//------------------------------------------------------------------

/**
* Interface to define which containers may be loaded in a document
* <p> Allows to load only a subset of the containers if 
*     they are sufficient for a particular task
* 
*/
class ExportedByAD0XXBAS CATILoadMode: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Get list of load modes for this document
  * @param oList
  *        list of available modes
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT GetModeList(CATListOfCATUnicodeString& oList) = 0;

  /**
  * Get current mode
  * @param oMode
  *        current mode
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT GetCurrentMode(CATUnicodeString& oMode) = 0;

  /**
  * Set current mode
  * @param ioMode
  *        desired mode (selected mode is returned)
  * @param iForce
  *        FALSE : loaded containers remain
  *        TRUE : containers may be unloaded (future use)
  * @return
  *        S_OK if mode was changed
  *        <b>S_FALSE if mode already current
  *        <b>E_FAIL if not allowed
  */
  virtual HRESULT SetCurrentMode(CATUnicodeString& ioMode, boolean iForce = FALSE) = 0;

  /**
  * Get status for a particular container
  * @param iCont
  *        container name
  * @return
  *        S_OK = should be loaded
  *        S_FALSE = not allowed to load
  *        E_FAIL = not specified
  */
  virtual HRESULT GetContainerStatus(const char* iCont) = 0;

  /**
  * Add a listener
  * @param iListener
  *        listener interface
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT  AddLoadModeListener(CATILoadModeListener* iListener)=0;

  /**
  * Remove a listener
  * @param iListener
  *        listener interface
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT  RemoveLoadModeListener(CATILoadModeListener* iListener)=0;

  /**
  * Advise : call ContainerLoaded on all listeners
  * @param iContainer
  *        container which is loaded
  * @return
  *        S_OK, E_FAIL if not available
  */
  virtual HRESULT  AdviseContainerLoaded(CATIContainer* iCont)=0;
};

//------------------------------------------------------------------

#endif