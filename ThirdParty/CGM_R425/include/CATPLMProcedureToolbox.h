//===================================================================
// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMProcedureParams.h
// Define the CATPLMProcedureParams class
//
//===================================================================
//
// Usage notes:
//   New adapter: parameters of procedures
//
//===================================================================
//
// July 2009
// Creation: EPB
//
//===================================================================

/**
* @level Protected
* @usage U1
*/

#ifndef CATPLMProcedureToolbox_H
#define CATPLMProcedureToolbox_H

#include "CATPLMServicesProc.h"

#include "CATSysErrorDef.h"             // SpecialAPI PublicInterfaces

#include "CATListOfInt.h"               // System PublicInterfaces
#include "CATListOfDouble.h"            // System PublicInterfaces
#include "CATListOfCATString.h"         // System PublicInterfaces
#include "CATListOfCATUnicodeString.h"  // System PublicInterfaces
#include "CATListOfCATBoolean.h"        // System PublicInterfaces
#include "CATString.h"                  // System PublicInterfaces
#include "CATUnicodeString.h"           // System PublicInterfaces

#include "CATLISTV_CATPLMID.h"          // CATPLMIdentificationAccess ProtectedInterfaces

class CATPLMProcedureParams;

class ExportedByCATPLMServicesProc CATPLMProcedureToolbox
{
public:
  enum ParamMode {IN_MODE,OUT_MODE};

  /** 
  * Parse a procedure.
  *
  * <br><b>Role</b>: Parse a procedure
  *
  * eg of a procedure saved in <CATIA code>\intel_a\code\dictionary\metadata\procedures:
  * <xml version="1.0"?>
  * <!-- edited with XMLSpy v2007 (http://www.altova.com) by DASSAULT SYSTEMES (DASSAULT SYSTEMES) -->
  * <ProcedurePackage xmlns="PLMDictionaryProcedure" Name="CATSbi_Procedures">
  *   <Procedure Name="SystemsBehavior_ExportChannel">
  *     <Implementation Name="SystemsBehavior_ExportChannel" FileLocation="SystemsBehavior_ExportChannel.KProc" Language="EKL"/>
  *     <Signature href="CATSbi_ProcedureSignatureExport"/>
  *   </Procedure>
  *  <Procedure Name="SystemsBehavior_ExportDesign">
  *     <Implementation Name="SystemsBehavior_ExportDesign" FileLocation="SystemsBehavior_ExportDesign.KProc" Language="EKL"/>
  *     <Signature href="CATSbi_ProcedureSignatureExport"/>
  *   </Procedure>
  *   <Signature id="CATSbi_ProcedureSignatureExport">
  *     <Parameter Name="InputIds" Lower="0" Upper="-1" MultiValuated="Yes" Direction="in" DataType="PLMId"/>
  *     <Parameter Name="OutputIds" Lower="0" Upper="-1" MultiValuated="Yes" Direction="out" DataType="PLMId"/>
  *   </Signature>
  * </ProcedurePackage>
  *
  * @param iProcName [in]
  *   name of the procedure that will be parsed.
  *   Have a look in:
  *   <CATIA code>\intel_a\code\dictionary\metadata\procedures
  *   to see the list of procedures that can be executed on the server.
  * @param iParamMode [in]
  *   Specify which kind of parameters we retrieve: IN, OUT, INOUT parameters...
  * @param oListOfParamName [out]
  *   with eg above: if iParamMode == IN_MODE, oListOfParamName contains "InputIds"
  * @param oListOfIsMulti [out]
  *   with eg above: if iParamMode == IN_MODE, oListOfIsMulti contains "Yes"
  * @param oListLowerBound [out]
  *   with eg above: if iParamMode == IN_MODE, oListLowerBound contains "0"
  * @param oListUpperBound [out]
  *   with eg above: if iParamMode == IN_MODE, oListUpperBound contains "-1"
  * @param oListOfDataType [out]
  *   with eg above: if iParamMode == IN_MODE, oListOfDataType contains "PLMId"
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise...
  *   <code>E_INVALIDARG</code> if one of the list is not empty
  *   <code>E_FAIL</code> impossible to find the procedure iProcName in the dictionary
  *
  */
  static HRESULT ParseProcParams( const CATString & iProcName                               ,
                                  ParamMode   iParamMode                                   ,
                                  CATListOfCATString & oListOfParamName /*Parameter Name*/  ,
                                  CATListOfCATBoolean & oListOfIsMulti  /*MultiValuated*/   ,
                                  CATListOfInt & oListLowerBound        /*Lower*/           ,
                                  CATListOfInt & oListUpperBound        /*Upper*/           ,
                                  CATListOfCATString & oListOfDataType  /*DataType*/
                                );

  /** 
   * method implemented to keep downward compatibility 
   * (R207 and next levels) for procedure.
   *
   * <br><b>Role</b>: method implemented to keep downward compatibility 
   *                  (R207 level and next levels) for procedure.
   *
   * @param iProcedureName [in]
   *   name of the procedure that will be executed on the server
   *   this procedure must contain only one IN parameter:
   *   <Parameter Name="InputIds" Lower="0" Upper="-1" MultiValuated="Yes" Direction="in" DataType="PLMId"/>
   *   the type of this parameter should be "PLMId"
   * @param iInputIDs [in]
   *   list of plmids given that are used as arguments of procedure
   * @param ioObject [out]
   *   new object that contains the list of plmids
   *
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise...
   *   <code>E_FAIL</code> impossible to find the procedure iProcName in the dictionary or to retrieve the list of PLMID
   *
  */
  static HRESULT Convert( const CATString & iProcedureName,
                          const CATLISTV(CATPLMID) & iInputIDs,
                          CATPLMProcedureParams & oObject);

  /** 
   * method implemented to keep downward compatibility 
   * (R207 and next levels) for procedure.
   *
   * <br><b>Role</b>: method implemented to keep downward compatibility 
   *                  (R207 level and next levels) for procedure.
   *
   * @param iProcedureName [in]
   *   name of the procedure that will be executed on the server
   *   this procedure must contain only one IN parameter:
   *   <Parameter Name="InputIds" Lower="0" Upper="-1" MultiValuated="Yes" Direction="in" DataType="PLMId"/>
   *   the type of this parameter should be "PLMId"
   * @param ipObject [out]
   *   object retrieved after the execution of the procedure
   * @param oInputIDs [in]
   *   list of plmids retrieved after the execution of the procedure
   *
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise...
   *   <code>E_FAIL</code> impossible to find the procedure iProcName in the dictionary or to retrieve the list of PLMID
   *
  */
  static HRESULT Convert( const CATString & iProcedureName,
                          CATPLMProcedureParams & iObject,
                          CATLISTV(CATPLMID) & oInputIDs);

  /** 
   * method to check the existence of the procedure.
   *
   * <br><b>Role</b>: method to check the existence of the procedure.
   *
   * @param iProcName [in]
   *   name of the procedure that will be checked.
   *
   * @return
   *   <code>S_OK</code> the procedure exists (<=> declared in the dictionary (see metadatas))
   *   <code>E_FAIL</code> the procedure doens't exist (<=> not declared in the dictionary (see metadatas))
   *
  */
  static HRESULT IsProcedureDeclared(const CATString & iProcName);
};

#endif
