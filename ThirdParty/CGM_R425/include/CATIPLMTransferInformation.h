/* -*-c++-*- */
// COPYRIGHT Dassault Systemes 2006
#ifndef CATIPLMTransferInformation_H
#define CATIPLMTransferInformation_H

/**
 * @level Protected
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATIPLMTransferEngine.h"  // for scenario enum

class CATUnicodeString;
class CATString;
class CATBinary;
class CATIPLMTransferOptions;
class CATIPLMTransferBehaviors;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMTransferInformation;
#else
extern "C" const IID IID_CATIPLMTransferInformation ;
#endif

/**
 * This interface enables to set information related to the data transfer.
 * <br>
 * <ul>
 *   <li>These information are used by  @href  CATIPLMTransferToProvider</li>
 * </ul>
 */
class ExportedByCATPLMIntegrationInterfaces CATIPLMTransferInformation: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/** 
 * DEPRECATED R206
 *
 */
 virtual void SetDestinationProvider(CATUnicodeString& iProviderName)= 0;

/** 
 * Enables to define a connection parameter for the transfer destination provider.
 *
 * @param iParameterName [in]
 *   The name of the connection parameter.
 *
 * @param iParameterValue [in]
 *   The corresponding value of the parameter.
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetDestinationConnectionInfo(CATString& iParameterName, CATUnicodeString& iParameterValue)= 0;

/** 
 * Enables to define a connection parameter for the transfer destination provider.
 *
 * @param iBinaryParameter[in]
 *   The binary containing all the connection parameters.
 *
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetDestinationConnectionInfo(CATBinary & iBinaryParameter)= 0;

/** 
 * Enables to define a connection parameter for the transfer source provider.
 *
 * @param iParameterName [in]
 *   The name of the connection parameter.
 *
 * @param iParameterValue [in]
 *   The corresponding value of the parameter.
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetSourceConnectionInfo(CATString& iParameterName, CATUnicodeString& iParameterValue)= 0;

  /** 
 * Enables to define a connection parameter for the transfer source provider.
 *
 * @param iBinaryParameter[in]
 *   The binary containing all the connection parameters.
 *
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT SetSourceConnectionInfo(CATBinary & iBinaryParameter)= 0;

  /** 
  * Enables to set the transfer report complete path.
  *
  * <li>The report logs the information related to the data transfer.</li>
  * <li>The generated report will be called 'ProcessReport.xml'</li>
  * <li>In case no path is given the report will be generated in CATTemp\TransitionEngine </li>
  *
  * @param iGenerateReport [in]
  *   Set this parameter to CATFalse if you don't want the report directory path to be modified.
  * <b>Legal values</b>
  * <br><i>CATTrue,CATFalse</i> 
  *
  * @param ioReportPath [in/out]
  *   input : It is either empty or a directory path.
  *	output : The complete path to the report.
  *   if ioReportPath is empty we create a default path for the report.
  *   if ioReportPath is a directory path and iGenerateReport = CATTrue, we create a directory Report_"date" in the directory path ioReportPath
  *	if iGenerateReport = CATFalse then we take ioReportPath and write the report directly in this directory
  *
  *
  * @return
  *   <code>S_OK</code> 
  *   <code>S_FALSE</code> 
  *   <code>E_FAIL</code> 
  *
  */
  virtual HRESULT SetTransferReportInfo(CATBoolean& iGenerateReport, CATUnicodeString& ioReportPath)= 0;

/** 
 * Gets a handle on the CATIPLMTransferOptions interface.
 *
 * @param oTransferOptions [out]
 *   the CATIPLMTransferOptions interface pointer.
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT GetTransferOptionsAccess(CATIPLMTransferOptions*& oTransferOptions)= 0;

 /** 
 * DEPRECATED R207
 */
  virtual HRESULT GetTransferBehaviorsAccess(CATIPLMTransferBehaviors*& oTransferBehaviors)= 0;

  /** 
 * Gets a handle on the CATIPLMTransferBehaviors interface.
 *
 * @param iScenario [in]
 *   the transfer scenario type
 *
 * @param oTransferBehaviors [out]
 *   the CATIPLMTransferBehaviors interface pointer.
 *
 * @return
 *   <code>S_OK</code> 
 *   <code>S_FALSE</code> 
 *   <code>E_FAIL</code> 
 *
 */
  virtual HRESULT GetTransferBehaviorsAccess(CATIPLMTransferEngine::CATPLMTEScenario iScenario, CATIPLMTransferBehaviors*& oTransferBehaviors)= 0;
											 
 /** 
 * Sets the input XML parameter file. Usefull in case of reverse migration.
 *
 * @param iXMLFile [in]
 *   The path of the XML parameter file.
 *
 */
  virtual void SetXMLParameterFile(CATUnicodeString& iXMLFile)= 0;

 /** 
 * Sets the context of the transfer. Usefull in case of migration scenario.
 *
 * @param iContext [in]
 *   The context of the transfer.
 *
 */
  virtual void SetContext(CATUnicodeString& iContext)= 0;
  
};
CATDeclareHandler( CATIPLMTransferInformation, CATBaseUnknown );
#endif
