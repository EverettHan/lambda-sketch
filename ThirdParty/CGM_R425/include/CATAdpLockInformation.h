/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATAdpLockInformation_H
#define CATAdpLockInformation_H

/**
 * @CAA2Level L1
 * @CAA2Usage U1  
 */

#include "CATPLMIntegrationAccess.h"
#include "CATErrorDef.h"
class CATIAdpPLMIdentificator;
class CATUnicodeString;
class CATError;

/**
 * Class giving access to a set of informations resulting from a lock analysis.
 *
 * <br><b>Role</b>: provide a set of informations about a component resulting from a lock analysis in a database.
 */
class ExportedByCATPLMIntegrationAccess CATAdpLockInformation
{
public:

/** 
 * Gets the component identificator.
 *
 * <br><b>Role</b>: Gets the @href CATIAdpPLMIdentificator enabling to identify a component.
 *
 * @param oIdentifier [out, CATBaseUnknown#Release]
 *   The retrieved component identificator.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the related identifier could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetIdentifier( CATIAdpPLMIdentificator *& oIdentifier ) = 0;

/**
 * Description of the available lock states for a component.
 * <dt> <code><b>NotLocked</b></code>     <dd> The component is not locked.
 * <dt> <code><b>LockedByConnectedUser</b></code>      <dd> The component is locked by the user performing the query.
 * <dt> <code><b>LockedByAnotherUser</b></code>     <dd> The component is locked by another user than the one performing the query.
 * <dt> <code><b>LockAnalyzeFailure</b></code>     <dd> The lock analysis failed on the component. The error can be obtained through @href CATAdpLockInformation#GetLockError .
 */
  enum LockState { NotLocked=0, LockedByConnectedUser=1, LockedByAnotherUser=2, LockAnalyzeFailure=3 };

/**
 * Gets a lock state.
 *
 * <br><b>Role</b>: Gets a lock state corresponding to the state of the component in the database.
 *
 * @param oLockState[out]
 * 	The lock state of the component. In case of <b>LockAnalyzeFailure</b>, an error can be obtained through @href CATAdpLockInformation#GetLockError .
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the lock state could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetLockState( LockState & oLockState ) = 0;

/**
 * Gets a lock user.
 *
 * <br><b>Role</b>: Gets the user who is locking the component if the component is locked.
 *
 * @param oLockUser[out]
 * 	The lock user.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if the lock user could be retrieved.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetLockUser( CATUnicodeString & oLockUser ) = 0;

/**
 * Gets the error which prevents from analyzing the component.
 *
 * <br><b>Role</b>: Gets an error if the component could not be analyzed through the @href CATAdpLockServices#IsLocked entry point.
 * If an error is available, @href CATAdpLockInformation#GetLockState should return <b>LockAnalyzeFailure</b> value.
 *
 * @param oLockAnalysisError[out, CATBaseUnknown#Release]
 * 	The lock error if the analysis could not be done on the component.
 *
 * @return
 *   <ul>
 *   <li><code>S_OK</code> if a lock error is available.</li>
 *   <li><code>E_FAIL</code> otherwise.</li>
 *   </ul>
 *
 */
  virtual HRESULT GetLockError( CATError *& oLockAnalysisError ) = 0;
 /**
  * Destructor.
  */
  virtual ~CATAdpLockInformation(void) {}
};
#endif
