// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMCompProcedureCallService.h
// Interface to run Procedures.
//
//===================================================================
//
// Usage notes:
//   Use this interface to execute a Procedure thanks to the method LaunchProcedure.
//   To get a pointer on this interface, use the static method
//                  CATPLMComponentServices::GetProcedureCallService
//
//===================================================================
//
//  Dec 2008  Creation:  MQV
//===================================================================
/**
 * @level Protected
 * @usage U3
 */
#ifndef CATIPLMCompProcedureCallService_H
#define CATIPLMCompProcedureCallService_H

#include "CATPLMServicesProc.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATListOfCATString.h"
#include "CATListOfInt.h"
#include "CATListOfCATBoolean.h"
#include "CATPLMRepositoryName.h"

class CATString;
class CATLISTV(CATPLMID);
class CATIPLMCompRecordReadSet;
class CATPLMProcedureParams;
class CATIPLMError;

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesProc IID IID_CATIPLMCompProcedureCallService;
#else
extern "C" const IID IID_CATIPLMCompProcedureCallService ;
#endif

/**
 * Use this interface to execute a Procedure thanks to the method LaunchProcedure.
 * To retrieve a valid pointer on this interface, use the static method 
 * @href CATPLMComponentServices#GetProcedureCallService .<br>
 */
class ExportedByCATPLMServicesProc CATIPLMCompProcedureCallService: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** 
  * Check that provider is able to launch procedure on the server side.
  *
  * <br><b>Role</b>: Check that provider  is able to launch procedure on the server side.
  *                  <=>Check that the provider implements CATIPLMProcedureCall.
  *
  * @param iType [in]
  *   The name of the provider that will execute procedures.
  *   if number of provider connected is > 1 and if iType == CATPLMRepositoryName_Null, E_FAIL.
  *   if number of provider connected is 1 and if iType == CATPLMRepositoryName_Null,
  *   procedure is launched on the provider connected.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *   <code>E_NOTIMPL</code> if the provider doesn't support the launch of procedure on the server side.
  *   <code>E_FAIL</code>
  *
  */
  virtual HRESULT PrepareLaunchProcedure(const CATPLMRepositoryName iType = CATPLMRepositoryName_Null) = 0;

  /** 
   * Execute a Procedure.
   *
   * <br><b>Role</b>:
   * Here are the kind of procedures that are supported by this method:
   * procedures that have:
   * 1- - one input parameter which type is a list of PLMId (procedure implemented on R207 level).
   *    - one output parameter which type is a list of PLMId.
   * 2- - 0...n input parameter(s) which type is "String" or "Integer" or "Date" or "Double" or "Boolean" or "PLMId".
   *                               which can be a list.
   *    - 0...n output parameter(s) which type is "String" or "Integer" or "Date" or "Double" or "Boolean" or "PLMId".
   *                                which can be a list.
   *
   * @param iProcName [in]
   *   The Name of the Procedure to call.
   * @param iObject [in]
   *   iObject contains the list of input parameters that will be send to the server with their values.
   * @param oObject [out]
   *   oObject contains the list of output parameters that will be retrieved from the server with their values.
   *   after the execution of the procedure iProcName.
   * @param opError [out]
   *   retrieve error sent by the server:
   *   1- Suppose in the xml, we find <GLOBALREPORT STATUS="SUCCEEDED" SEVERITY="Warning"/>.
   *   In such a case, STATUS=="Succeeded", no report is created opError == NULL.
   *   2- Suppose in the xml, we find <GLOBALREPORT STATUS="FAILED" SEVERITY="FATAL" ERRORCODE="PLM_SystemPb" ERRORCATALOG="PLMServerGlobalErrors" >.
   *   In such a case, STATUS!="Succeeded", a report is created opError != NULL
   *
   * @return
   *   <code>S_OK</code> the xml returned is well formed opError==NULL.
   *   <code>S_FALSE</code> the xml returned is well formed. 
   *                        there is a warning or an error described in opError==NULL.
   *   <code>E_FAIL</code> xml returned is badly formed.
   *
  */
  virtual HRESULT LaunchProcedure(  const CATString & iProcedureName    ,
                                    CATPLMProcedureParams & iObject     ,
                                    CATPLMProcedureParams & opObject   ,
                                    CATIPLMError* & opError) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

#endif


  /**
   * Execute a Procedure.
   *
   * we let this method to keep downward compatibility (between R207 and new levels)
   * this method only support procedures that have one input parameter which type is a list of PLMId
   * this method only support procedures that have one output parameter which type is a list of PLMId
   *
   * @param iProcedureName [in]
   *    The Name of the Procedure to call.
   * @param iInputIDs [in]
   *    The list of PLMIDs to be given as inputs of the Procedure.
   * @param oRecordSet [out, CATBaseUnknown#Release]
   *    A CATIPLMCompRecordReadSet interface provides access to the result of the Procedure.
   *	@return
   *			Error code of function:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>Procedure executed successfully</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>A global error occured. Check the global report.</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>An unexpected problem occured.</dd>
   *   </dl>
   */
  //virtual HRESULT LaunchProcedure(const CATString & iProcedureName,
  //                                const CATLISTV(CATPLMID) & iInputIDs,
  //                                      CATIPLMCompRecordReadSet *& oRecordSet) = 0;

