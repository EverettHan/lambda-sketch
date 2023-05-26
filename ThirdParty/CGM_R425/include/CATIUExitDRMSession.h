/* COPYRIGHT DASSAULT SYSTEMES 2006 */
/**
 * @CAA2Level L0
 * @CAA2Usage U5
 */

#ifndef CATIUExitDRMSession_H
#define CATIUExitDRMSession_H

#include "CATWTypes.h"
#include "CATErrorDef.h"
#include "CATSysDRMHR.h"
#include "CATUnicodeString.h"

#if defined __JS0DRMDOC
#define ExportedByJS0DRMDOC DSYExport
#else
#define ExportedByJS0DRMDOC DSYImport
#endif
#include "DSYExport.h"



/**
 * Policy to allow the save of unencrypted document 
*/
#define CATSysDRM_ALLOW_UNENCRYPTED_SAVE	0x00000001 


extern "C" const IID IID_CATIUExitDRMSession;

/**
 * Interface to enable user specific DRM (digital rights management) mechanism in
 * a session 
 * <b>Role</b>: This interface is a user exit, that allows an user to create its 
 * security environment session.
 * Implementing this user exit is not mandatory. It is provided as a
 * facility to be called at the beggining and at the end of the security session to
 * do initialisation and cleanup treatments.
 *
 **/


class ExportedByJS0DRMDOC  CATIUExitDRMSession : public IUnknown
{
public:
/**
 * Initialize the DRM environment session.
 * <br><b>Role</b>:Initializes the DRM environment globally.
 * This must be called before the first document is opened.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL:</tt> environment not correctly  initialised
 *   <br><tt> DRM_E_UNKNOWN :</tt> unexpected error.
*/
  virtual HRESULT DRMInitSession()=0;


/**
 * Returns the DRM policy.
 * <br><b>Role</b>:Returns information about the rules and policy implemented by
 * the user exit.
 * @param iPolicy
 *     The queried policy.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt> if the policy is active.
 *   <br><tt> DRM_E_FAIL:</tt> if the policy is not set.
*/
  virtual HRESULT DRMGetPolicy(DWORD iPolicy)=0;




/**
 * Closes the DRM environment.
 * <br><b>Role</b>:Closes the DRM environment session created in 
 * @href #DRMInitSession
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> error
*/
  virtual HRESULT DRMCloseSession( )=0;


/**
 * Returns the display name of the DRM provider.
 * <br><b>Role</b>:Returns the display name of the DRM provider currently used. This
 * method is only intended for user interface purpose. The relevant information 
 * concerning the implementation identification is the 
 * @href CATIUExitDRMDocument::DRMGetLibUID .
 * @param oName [out]
 *	The name of the current implementation
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> error
*/
  virtual HRESULT DRMGetProviderName(CATUnicodeString &oName)=0 ;
};

/**
 * Factory to create the the DRMSession interface.
 * @return
 *   <b>Legal values</b>:
 *   <br><tt> S_OK :</tt>on Success.
 *   <br><tt> DRM_E_FAIL :</tt> error
*/
HRESULT ExportedByJS0DRMDOC CATSysDRMCreateSession(CATIUExitDRMSession *&oSession);

#endif



