#ifndef __CATOmbErrorContext_H
#define __CATOmbErrorContext_H

// System
#include "CATError.h"
// ObjectModelerCollection
#include "CATOmxArray.h"
#include "CATOmxSR.h"
// ObjectModelerSystem
#include "CATOmyIncidentGroup.h"
// ObjectModelerBase
#include "AD0XXBAS.h"
#include "CATOmbLoadableDataUniqueKey.h"
#include "CATOmiSwitchOperation.h"
// CATPLMIdentification
#include "CATComponentId.h"

class CATILockBytes2;
class CATIDocId;
class CATListValCATUnicodeString;

namespace ErrorIn
{
  enum Function {undef, OLE, Projection};
}

/**
* Creates, Stacks and traces OMB errors into @href CATIOmyIncidentCollector with specific context inputs
* CATOmbErrorContext EC(CompId,...);
* EC.Log*Error(...);
*/
class ExportedByAD0XXBAS CATOmbErrorContext
{
public:

  //FIXME: compact args of CTORs (see CATOsmMessage)

  /**
  * Declares a context from contextual inputs
  */
  // error is always logged, whithout any specific context 
  CATOmbErrorContext();

  // error is logged only if component exists, in V6 context 
  //  (no log in case of V5 data opened in V6 through OMB by link resolution: eventual errors are by-passed and not to be logged)
  CATOmbErrorContext(const CATComponentId& iCompId);

  /*Error is logged only if component exists, in V6 context. use it to log data streaming/unstreaming errors
   (no log in case of V5 data opened in V6 through OMB by link resolution: eventual errors are by-passed and not to be logged)
  iCompid : The component in operation, if V6 operation, else CATComponentId_Null
  iLB2 / iUrlAsString  : Identifies source Data location, for stream/unstream operations
  iDocId / iDocType: Identifies the document streamed/unstreamed. As of now, Type field only is used as error parameter
  */
  CATOmbErrorContext(const CATComponentId& iCompId, CATILockBytes2* iILB2, CATIDocId* iDocId);
  // OR
  CATOmbErrorContext(const CATComponentId& iCompId, const CATUnicodeString& iUrlAsString, const CATUnicodeString& iDocType);

  /*Error to be logged by LogIOError : use it to dump in logs a local file path as complementary information to 
  // file OS i/o errors, typically in V6 local disk projection/OLE context
  iFunc: the functionality where error occurs : may be required to translate a given generic OS error into the OMB error dedicated to this functionality
  iFilePath: typically a file projection path on local disk*/
  CATOmbErrorContext(const ErrorIn::Function iFunc, const CATUnicodeString& iFilePath);

  virtual ~CATOmbErrorContext();

  /**
  * Stacks a new @href CATIOmyIncidentCell CATError into @href CATIOmyIncidentCollector stack with context informations
  */
  /**
  * Stacks a new OMB error from specific Windows/System HRESULT
  */
  CATOmxSR<CATError> LogIOError(HRESULT hr);
  /**
  * Stacks a new OMB error from error Key/Catalog/sev without parameters
  */
  CATOmxSR<CATError> LogOmbError(const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity);
  /**
  * Stacks a new OMB error from error Key/Catalog/sev with parameters
	* @param iErrorKey
	*        the key describing this specific error in a given error messages catalog
	* @param iErrorCatalog
	*        the error messages catalog the error is described into
	* @param iSeverity
	*        the severity to be set on this Error
  * @param iParms
	*        The table of parameters to be added to error message, in numbering order : /p1, /p2..etc
	*        The Request parameter tables if composite (Request-Diagnostic-Advice) message, the single parameter table otherwise.
  * @param iDiagParms
	*        The Diagnostic parameter table if composite (Request-Diagnostic-Advice) message, empty table otherwise.
  * @param iAdvParms
	*        The Advice parameter table if composite (Request-Diagnostic-Advice) message, empty table otherwise.
  */
  CATOmxSR<CATError> LogOmbError(const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity, const CATOmxArray<CATUnicodeString>& iParms, const CATOmxArray<CATUnicodeString>& iDiagParms, const CATOmxArray<CATUnicodeString>& iAdvParms);
  /**
  * Stacks/Associates a new OMB Switch error to an aborted SwitchOperation, from the pack of errors raised by operation validation/execution.
  * To be used only for severe errors, that interrupt validation/execution normal process.
  * @param iSwitchOperation
	*        The switch operation aborted.
  * @param iGroup
	*        The Group of errors raised by Validate/Execute on operation.
	* @param iErrorKey
	*        the key describing this specific error in a given error messages catalog.
	* @param iErrorCatalog
	*        the error messages catalog the error is described into.
	* @param iSeverity
	*        the severity to be set on this Error. NO error generated/log if iSeverity = CATErrorTypeWarning or CATErrorTypeInformation.
  */
  CATOmxSR<CATError> LogSwitchError(HRESULT hr, CATOmiSwitchOperation& iSwitchOperation, CATOmyIncidentGroup* iGroup, const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity, CATBoolean RevertRunning=FALSE);

  /**
  * Dumps a new OMB StreamDescriptor error 
  * Catalog is CATOmbSessionErrors.CATNls, dedicated to all StreamDescriptor problems
  * Error is dumped into logs only, as the internal error it is, but not reported into IncidentCollector
	* @param hr 
	*        the HRESULT to be returned by this method and its caller
	* @param iSDKey
	*        the key identifying the StreamDescriptor in error
	* @param iSDLateType
	*        the eventual SD late type
	* @param iAction 
	*        the current action beeing performed on SD (creation, deletion, ..etc..to be completed into CATOmbSessionErrors.CATNls if needed)
	* @param iErrorKey
	*        the key describing this specific error into CATOmbSessionErrors.CATNls
	* @param iSeverity
	*        the severity to be set on this Error
  */
  HRESULT DumpSDError(HRESULT hr, const CATOmbLoadableDataUniqueKey& iSDKey, const CATUnicodeString& iSDLateType, const CATUnicodeString& iAction, const char *iErrorKey, CATErrorType iSeverity, const CATUnicodeString& iContext="");

  /**
  * Logs a new OMB StreamDescriptor error
  * Proceeds as DumpSDError but Error is dumped into logs AND reported into IncidentCollector
  */
  HRESULT LogSDError(HRESULT hr, const CATOmbLoadableDataUniqueKey& iSDKey, const CATUnicodeString& iSDLateType, const CATUnicodeString& iAction, const char *iErrorKey, CATErrorType iSeverity, const CATUnicodeString& iContext="");

  /**
  * Updates the diagnostic content of an OMB Switch error already associated to an aborted SwitchOperation
 * @param iSwitchOperation
	*        The switch operation aborted 
	* @param iErrorKey
	*        the key describing a specific error which NLS content is to add to the error diagnostic
  * @param iErrorCatalog
	*        the error messages catalog the error is described into
  */
  HRESULT UpdateSwitchError(CATOmiSwitchOperation& iSwitchOperation, const char *iErrorKey, const char* iErrorCatalog);

  CATOmxSR<CATError> LogLoadRuleError(const char *iErrorKey, const char* iErrorCatalog, CATErrorType iSeverity, CATUnicodeString& iRuleContext);

  /* SML1 : ****ing redirection to CATOmySessionRecordServices::AddLogInfos and avoid to include this header that is in conflict with CosPropertyServices.h : declaration of 2 enums with same values*/
  static void AddLogInfosToCATOmySessionRecordServices(const char * iThem, const char * iOperation, CATListValCATUnicodeString & iInfos);

  /**
  * Stacks a new OMB error from another OMB or external error with eventual parameters
  * @param iError
  *        the Error to be copied and dumped to traces
  * @param iContext
  *        the eventual context to be added to current one initialized by CTOR
  */
  CATOmxSR<CATError> LogExternalError(CATError& iError, const CATUnicodeString& iContext);

  /**
  * Gets the PhysicalId of the current component for trace
  * @return
  *        The Physical id of the component in the same Uuid format for all logging systems (OMB_XML_TRACE, DSYSystrace, Eror statistics, ..)
  */
  CATUnicodeString GetComponentUuid();

private:
  
  ErrorIn::Function _ErrIn;
  CATComponentId _CompId;
  CATOmxSR<CATILockBytes2> _ILB2;
  CATOmxSR<CATIDocId> _DocId;
  CATBoolean _LogIt;
  CATUnicodeString _DataType;
  CATUnicodeString _Prefix;
  CATUnicodeString _InitContext;
  CATUnicodeString _Context;
  CATUnicodeString _FilePath;
};
#endif
