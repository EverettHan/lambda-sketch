// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATIPLMProcedureCall.h
// Interface to run Procedures. Implementation by providers.
//
//===================================================================
//
// Usage notes:
//    MQV:
//    Use this interface to execute a Procedure thanks to the method LaunchProcedure.
//    EPB(R208): 
//    -procedure support 0,...,n input  parameters which type can be (<list of>)String,(<list of>)Double,(<list of>)PLMId... (simple type)
//    -procedure support 0,...,n output parameters which type can be (<list of>)String,(<list of>)Double,(<list of>)PLMId... (simple type)
//    Today IDL mecanism that you can find using ORBIX or RMI or web services with generation of a stub and a skeleton
//    doesn't exist. That is why you can only send an receive simple types.
//
//    list of parameters supported:
//    String      |   omx_string    |   omx_string
//    Integer     |   omx_int       |   omx_int
//    Date        |   omx_time      |   omx_time
//    Double      |   omx_double    |   omx_double
//    Binary      |   omx_boolean   |   omx_boolean
//    PLMId ...   |   omx_IUnknown  |   omx_IUnknown
//
//===================================================================
//
//  Dec 2008  Creation:  MQV
//===================================================================
/**
 * @level Protected
 * @usage U3
 */
#ifndef CATIPLMProcedureCall_H
#define CATIPLMProcedureCall_H

#include "CATPLMServicesProc.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "CATListOfCATBoolean.h"

class CATString;
class CATLISTV(CATPLMID);
class CATIPLMRecordReadSet;
class CATPLMProcedureParams;
class CATIPLMError;

//enum ParamMode {IN_MODE,OUT_MODE,INOUT_MODE,IN_AND_INOUT_MODE,OUT_AND_INOUT_MODE,ALL};

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMServicesProc IID IID_CATIPLMProcedureCall;
#else
extern "C" const IID IID_CATIPLMProcedureCall ;
#endif

/**
 *   Use this interface to execute a Procedure thanks to the method LaunchProcedure.
 */
class ExportedByCATPLMServicesProc CATIPLMProcedureCall: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /** 
   * Execute a Procedure.
   *
   * <br><b>Role</b>:
   * Here are the kind of procedures that are supported by this method:
   * procedures that have:
   * 1- - one input parameter which type is a list of PLMId (procedure implemented on R207 level)
   *    - one output parameter which type is a list of PLMId
   * 2- - 0...n input parameter(s) which type is "String" or "Integer" or "Date" or "Double" or "Boolean" or "PLMId"
   *                               which can be a list
   *    - 0...n output parameter(s) which type is "String" or "Integer" or "Date" or "Double" or "Boolean" or "PLMId"
   *                               which can be a list
   *
   * @param iProcName [in]
   *   The Name of the Procedure to call.
   * @param iObject [in]
   *   iObject contains the list of input parameters that will be send to the server with their values
   * @param oObject [out]
   *   oObject contains the list of output parameters that will be retrieved from the server with their values
   *   after the execution of the procedure iProcName
   * @param opError [out]
   *   retrieve error sent by the server:
   *   1- Suppose in the xml, we find <GLOBALREPORT STATUS="Success" SEVERITY="Warning"/>.
   *   In such a case, STATUS=="Success", no report is created opError == NULL.
   *   2- Suppose in the xml, we find <GLOBALREPORT STATUS="FAILED" SEVERITY="FATAL" ERRORCODE="PLM_SystemPb" ERRORCATALOG="PLMServerGlobalErrors" >.
   *   In such a case, STATUS!="SUCCEEDED", a report is created opError != NULL
   *
   * @return
   *   <code>S_OK</code> the xml returned is well formed opError==NULL.
   *   <code>S_FALSE</code> the xml returned is well formed. 
   *                        there is a warning or an error described in opError==NULL.
   *   <code>E_FAIL</code> xml returned is badly formed.
   *
  */
  virtual HRESULT LaunchProcedure(const CATString & iProcName,
                                  CATPLMProcedureParams & iObject,
                                  CATPLMProcedureParams & oObject,
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
   *    A CATIPLMRecordReadSet interface provides access to the result of the Procedure.
   *  @return
   *      Error code of function:
   *   <dl>
   *     <dt>S_OK</dt>
   *     <dd>Procedure executed successfully</dd>
   *     <dt>S_FALSE</dt>
   *     <dd>A global error occured. Check the global report.</dd>
   *     <dt>E_FAIL</dt>
   *     <dd>An unexpected problem occured.</dd>
   *   </dl>
  */
  //virtual HRESULT LaunchProcedure(  const CATString & iProcedureName,
  //                                  const CATLISTV(CATPLMID) & iInputIDs,
  //                                  CATIPLMRecordReadSet *& oRecordSet) = 0;

  /** 
  * method implemented to keep downward compatibility 
  * (R207 level and next levels) for procedure.
  *
  * <br><b>Role</b>: Conversion of a CATOmxKeyValueBlock into a CATIPLMRecordReadSet.
  *
  * @param iObject [in]
  *   This method supposes that the procedure contains only one OUT parameter whose type is PLMId
  *   <Parameter Name="OutputIds" Lower="0" Upper="-1" MultiValuated="Yes" Direction="out" DataType="PLMId"/>
  *   the type of this parameter should be "PLMId"
  *   Taking into accound the signature of the procedure described above, we know that parameter iObject has been filled doing:
  *   CATOmxAny Value;
  *   ...
  *   CATOmxKeyString keyString("OutputIds");
  *   oObject.SetValue(keyString,Value);
  *   Value contains a list CATOmxAny and each CATOmxAny contains a plmid
  * @param iProcedureName
  *   name of the procedure
  * @param oRecordSet [out]
  *   The parameter role...
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *
  */
  //virtual HRESULT Convert(  const CATString & iProcedureName,
  //                          CATPLMProcedureParams & iObject     ,
  //                          CATIPLMRecordReadSet *& oRecordSet) = 0;

