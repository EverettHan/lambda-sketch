// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMLockEngine.h
// Define the CATIPLMLockEngine interface
//
//===================================================================
//
// Usage notes:
//   Interface dedicated to the Lock/Unlock Engine
//
//===================================================================
//
//  Mar 2008  Creation: Code generated by the CAA wizard  BAG
//===================================================================
#ifndef CATIPLMLockEngine_H
#define CATIPLMLockEngine_H

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
class CATPLMID;


/**
 * @level Protected
 * @usage U3
 */


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMLockEngine;
#else
extern "C" const IID IID_CATIPLMLockEngine ;
#endif

//------------------------------------------------------------------

/**
 * Interface representing the communication protocol of the Lock/Unlock Engine
 * Use CATPLMEnginesToolbox#GetLockEngine to get a pointer on the Lock/Unlock Engine
 *
 *
 *  CATIPLMLockEngine* piLockEngine=NULL;
 *  rc = CATPLMEnginesToolbox::GetLockEngine(piLockEngine, pListener);
 * ...
 * piLockEngine->AddComponentForLock(plmid1);
 * piLockEngine->AddComponentForUnlock(plmid2);
 * piLockEngine->AddComponentForUnlock(plmid3);
 * RC = piLockEngine->ExecuteLockUnlockRequest(); // Executes the 3 requests
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMLockEngine: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

  /**
   * Tells the Lock/Unlock Engine to lock the component that corresponds to the PLMID given in input
   * This method can be called several times, but you must call #ExecuteLockUnlockRequest once at the end of the process
   * @param iId [in] the plmid of the component to lock
   * @return S_OK if the Lock/UnlockEngine performed the operation successfully
   *         E_FAIL if a problem occured
   */

  virtual HRESULT AddComponentForLock(const CATPLMID & iId) = 0;


  /**
   * Tells the Lock/Unlock Engine to unlock the component that corresponds to the PLMID given in input
   * This method can be called several times, but you must call #ExecuteLockUnlockRequest once at the end of the process
   * @param iId [in] the plmid of the component to unlock
   * @return S_OK if the Lock/UnlockEngine performed the operation successfully
   *         E_FAIL if a problem occured
   */

  virtual HRESULT AddComponentForUnlock(const CATPLMID & iId) = 0;

  /**
   * Executes the lock/unlock transaction of the components you previously declared with #AddComponentForLock 
   * or #AddComponentForUnlock on the server.
   * @return S_OK if the Lock/Unlock Engine performed all the lock/unlock operations successfully
   *         S_FALSE if neither #AddComponentForLock nor #AddComponentForUnlock was called
   *                 or if an error occured and the listener was correctly informed of the error
   *         E_FAIL if an error (internal for example)
   */
  virtual HRESULT ExecuteLockUnlockRequest() = 0 ;

};
CATDeclareHandler(CATIPLMLockEngine,CATBaseUnknown);
//------------------------------------------------------------------

#endif
