//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2014x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT Dassault Systemes 2013
//===================================================================
#ifndef PLMExchangeSecurityServices_H
#define PLMExchangeSecurityServices_H
/**  
*  @level  Protected    
*  @usage  U1    
*/

// PLMExchangeServices
#include "PLMExchangeGlobalServices.h"    //PLMExchangeGlobalServices.m
// SpecialAPI
#include "CATSysBoolean.h"
#include "CATSysErrorDef.h"
#include "CATIPLMCompConnectionInstance.h" 
#include "CATListOfCATUnicodeString.h"
#include "CATListOfCATListOfCATUnicodeStrings.h"

#include "CATIAV5Level.h"
//SKN14++ FUN110016 BL CheckAccess //J76 MAC OS Check
//#ifdef CATIAR423
//#include "PLMIBLImportExportPnOValuations.h"
//#endif
//SKN14--
// System
class CATString;
class CATUnicodeString;

//-----------------------------------------------------------------------
class ExportedByPLMExchangeGlobalServices PLMExchangeSecurityServices
{
public:
   /** 
   * Check if an operation is allowed or not.
   * A same operation can correspond to different commands.
   *
   * @param iOperationId
   *        The identifier of the operation.
   * @param oOperationAllowed
   *        The status of the operation (Allowed or not)
   *  <ul>
   *	   <li><code>TRUE</code> : the operation is allowed</li>
   *	   <li><code>FALSE</code> : the operation is not allowed</li>
   *  </ul>
   * @param iMessage
   *        Enables to retrive the default message in case the operation is not allowed.
   * @return
   *  <ul>
   *     <li><code>S_OK</code> Security is implemented on current connection for the operation.</li>
   *     <li><code>E_FAIL</code> Security is not implemented on current connection for the operation. In that case, oOperationAllowed = TRUE </li>
   *  </ul>
   */
   static HRESULT CheckAccess(const CATString& iOperationId, CATBoolean& oOperationAllowed, CATUnicodeString* iMessage=0);
   static HRESULT GetCurrentSecurityContext (CATUnicodeString & oSecurityContext);
   static HRESULT GetServerUrl(CATUnicodeString & oURL); 
   static HRESULT GetConnectedInstance (CATIPLMCompConnectionInstance ** oCnxInst); 
#ifdef CATIAR421
   static HRESULT GetOnlineInstance (CATUnicodeString & osOnlineInstance); 
#endif
#ifdef CATIAR423
   static HRESULT CheckAccessThroughBusinessLogic(const CATUnicodeString& iImportExportFormat, const CATListOfCATUnicodeString& iListOfFilesToProcess, const CATListOfCATListOfCATUnicodeString& iListOfListOfFilesToProcess, CATBoolean& oOperationAllowed );//SKN14 BL Check Access
#endif

   /** List of Security privileges for exchanges. */
   static const CATString s_Export_Operation                       ;
   static const CATString s_Import_Operation                       ;
   static const CATString s_DatabaseDetach_Operation               ;
   static const CATString s_RepairSiteOwnership_Operation          ;
   static const CATString s_NewVersionUsingDistantData_Operation   ;
   static const CATString s_DuplicateUsingDistantData_Operation    ; 
   static const CATString s_ENOVIA_ImportExport_Delegate_Operation ;
   static const CATString s_ENOVIA_ImportExport_Revoke_Operation   ;
   static const CATString s_ENOVIA_CreateAsNew_Operation           ;

} ;
//-----------------------------------------------------------------------
#endif
