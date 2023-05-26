/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// 

/**
 * @level Protected 
 * @usage U1
 */

#ifndef CATOmiSwitchOperation_H
#define CATOmiSwitchOperation_H


#include "CATOmiSwitchEngineItf.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATOmxList.h"
#include "CATOmxSR.h"

class CATOmbErrorContext;
class CATOmbSwitchEngineImpl;
class CATError;

enum CATOmiSwitchOperationStatus 
{
  CATOmiSwitchRefused =0, 
  CATOmiSwitchValidated=1,
  CATOmiSwitchExecuted=2, 
  CATOmiSwitchFailed=3
}; 


/**
* This class describes a switch operation. A switch operation consists in changing the loading mode of a RepRef. 
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Switch Operations are created by the SwitchEngine. @href CATIOmiSwitchEngine
* They are designed to give information about the switch operation. 
* On can retrieve the initial loading mode of the RepRef and its target loading mode, 
* one can follow the progress of the operation, and gain some information in case of error. 
*/
class ExportedByCATOmiSwitchEngineItf CATOmiSwitchOperation
{
  friend class CATOmbSwitchWizard;               

public:
  CATOmiSwitchOperation(CATBaseUnknown& iComponent, CATUnicodeString iInitialLoadingMode, CATUnicodeString iTargetLoadingMode);
  CATOmiSwitchOperation( const CATOmiSwitchOperation& );  
  virtual ~CATOmiSwitchOperation();
  
  /**
  * Returns the component for which the Switch operation is required.
  * <b>Role</b>
  * @param opComponent [out, CATBaseUnknown#Release]
  *    a component to be switched by the engine
  * @return <ul>
  *            <li> S_OK : 
  *            <li> E_FAIL  :
  *         </ul>
  */         
  HRESULT GetComponent(CATBaseUnknown*& opComponent);
  inline CATBaseUnknown* GetComponent() {return _pObjetToSwitch;}

  /**
  * Returns the initial loading mode of the component to be switched.
  * <b>Role</b>
  * @param oInitialLoadingMode
  *    The initial loading mode. 
  * @return <ul>
  *            <li> S_OK : 
  *            <li> E_FAIL  :
  *         </ul>
  */         
  HRESULT GetInitialLoadingMode(CATUnicodeString &oInitialLoadingMode);
  inline CATUnicodeString GetInitialLoadingMode() const {return _InitialLoadingMode;}
  
  /**
  * Returns the target loading mode of the component to be switched.
  * <b>Role</b>
  * @param oTargetLoadingModes
  *    the target loading mode. 
  * @return <ul>
  *            <li> S_OK : 
  *            <li> E_FAIL  :
  *         </ul>
  */         
  HRESULT GetTargetLoadingMode(CATUnicodeString &oTargetLoadingMode);
  inline CATUnicodeString GetTargetLoadingMode() const {return _TargetLoadingMode;}
  /**
  * Returns the error that affects the switch if any. 
  * <b>Role</b>
  * @param oErrors
  *    The detected error. Error is Adreffed. 
  * @return <ul>
  *            <li> S_OK    : Error returned
  *            <li> E_FAIL  : No error returned 
  *         </ul>
  */         
  HRESULT GetAssociatedError(CATError*& oError);
  
  /**
  * Returns the status of the switch operation
  * <b>Role</b>
  * @param SwitchOperationsStatus
  *    The status of the switch operation.
  * @return <ul>
  *            <li> S_OK : 
  *            <li> E_FAIL  :
  *         </ul>
  */         
  HRESULT GetStatus(CATOmiSwitchOperationStatus& oSwitchOperationsStatus);
  inline CATOmiSwitchOperationStatus GetStatus() const {return _OpStatus;}

 /**
* Returns the list of low severity errors, that do not affect the switch operation.
* @return 
*       The list of Warning/Information errors carried by the switch operation normally executed.
*/
  inline CATOmxList<CATError> GetInfoWarnings() { return _InfoWarnings; };

private:

  friend class CATOmbErrorContext;  // private access to SetAssociatedError
  friend class CATOmbSwitchEngineImpl;  // private access to SetStatus

  /**
  * Sets the error that affects the switch if any. 
  * <b>Role</b>
  * @param iError
  *    The detected error. Error is Addreffed. 
  * @return 
  *        S_OK : 
  *        E_FAIL :
  */         
  HRESULT SetAssociatedError(CATError& iError);

   /**
  * Returns the status of the switch operation
  * <b>Role</b>
  * @param SwitchOperationsStatus
  *    The status of the switch operation.
  * @return <ul>
  *            <li> S_OK : 
  *            <li> E_FAIL  :
  *         </ul>
  */         
  HRESULT SetStatus(CATOmiSwitchOperationStatus iSwitchOperationsStatus);

  inline void AddInfoWarning(CATError& iError) { _InfoWarnings.Append(&iError);};
  inline void RemoveInfoWarnings() { _InfoWarnings.RemoveAll(); };

  CATOmiSwitchOperation& operator=(CATOmiSwitchOperation&);
  
  CATOmxSR<CATBaseUnknown>  _pObjetToSwitch;
  CATUnicodeString _InitialLoadingMode;
  CATUnicodeString _TargetLoadingMode;
  CATError*        _pError;
  CATOmiSwitchOperationStatus _OpStatus;
  CATOmxList<CATError> _InfoWarnings;
  
};
#endif
