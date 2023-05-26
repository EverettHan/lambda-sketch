/* -*-c++-*- */
/**
* @level Protected
* @usage U6
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------

#ifndef PLMErrorSeverity_H
#define PLMErrorSeverity_H

/**
 * Definition of the possible kinds of severity for an error.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>PLM_NOTDEFINED</tt>  <dd> Undefined severity.
 * @param <tt>PLM_WARNING</tt>    <dd> Something happens that doesn't stop the method. It completes and returns a warning.
 * @param <tt>PLM_SEVERE</tt>    <dd> Something happens that doesn't stop the method. It completes partially and returns an error.
 * @param <tt>PLM_FATAL</tt>    <dd> Something happens that stop the method. It does not complete and rollbacks if necessary.
 * @param <tt>PLM_INFORMATION</tt>    <dd> The method successively completes. It returns information that can be useful.
 * </dl>
 */
enum PLMErrorSeverity 
{
  PLM_NOTDEFINED=0, 
  PLM_WARNING=1,    /* Something happens that doesn't stop the method. It completes and returns a warning. */
  PLM_SEVERE=2,     /* Something happens that doesn't stop the method. It completes partially and returns an error. */
  PLM_FATAL=3,       /* Something happens that stop the method. It does not complete and rollbacks if necessary. */
  PLM_INFORMATION=4 /* The method successively completes. It returns information that can be useful. */
};
#endif

// class CATIAdpErrorMonitorAbstract.h
//
// Abstraction of CATIAdpErrorMonitor:
// Handle dedicated to the management of all errors raised by a (series) 
// of PLM action(s) enabled to collect errors (Engines, AdpServices, ..)
// 
// This abstraction has been created for architecture reason:
// to access CATPLMIntegrationInterfaces Engine Services from
// CATPLMIntegrationAccess FW (CATPLMEnginesToolbox for example)
//
//-----------------------------------------------------------------------------
// 04/07/2008 Creation - United Colors of Error Management                  VCS
//-----------------------------------------------------------------------------
#ifndef CATIAdpErrorMonitorAbstract_H
#define CATIAdpErrorMonitorAbstract_H

#include "CATError.h"

#include "CATPLMIntegrationAccess.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATLISTV_CATPLMID.h"
#include "CATOmxDeprecated.h"

class CATIAdpErrorCell;
class CATUuid;
class CATIPLMComponent;
class CATIAdpPLMIdentificator;
class CATIAdpErrorIterator;
class CATIPLMRecordRead;
class CATIPLMCompRecordReadSet;
class CATIPLMError;
class CATAdpResultIterator;
class CATOmyIncidentGroup;
class CATPLMErrorParameters;
class CATError;

/**
 * [[deprecated("useless, not implemented. Use GetErrorIterator() instead")]]
 * @deprecated
 * Do not use
 */
enum AdpIterationFilter
{
  NoFilterOnErrors=1,
  DeprecatedParameter=99
};


class ExportedByCATPLMIntegrationAccess CATIAdpErrorMonitorAbstract: public CATBaseUnknown
{
  public:

  /**
  * Gets the Unique identifier associated to each created instance of this class in CATUuid format
  * @param oMonitorUuid
  *    this CATIAdpErrorMonitor Identifier
  * @return
  *		 S_OK : Error Monitor Uuid successfully get
  * <br> E_FAIL : Error Monitor Uuid not available
  */
  virtual HRESULT GetMonitorUuid(CATUuid & oMonitorUuid)= 0;

  /**
  * @deprecated V6R422
  * @use GetErrorIterator
  */
  virtual HRESULT GetErrorIterator(CATIAdpErrorIterator* & opErrorIterator, AdpIterationFilter iIterationFilter=DeprecatedParameter)= 0;

  /**
  * Creates a new Error cell in the Error monitor
  * @param iErrorKey
  *        the key describing this specific error in a given error messages catalog
  * @param iErrorCatalog
  *        the error messages catalog into wich the error is described
  * @param iSeverity
  *        the severity to be set on this Error as defined by PLMErrorSeverity
  * @param iComponent
  *        the eventual component upon wich this error has been raised
  * @param iParameters
  *        the eventual parameters to be set on this error.
  *        Do not fill this object if no parameters to be set in the error message
  * @param opAdpErrorCell
  *        the Error cell created in the Error Monitor
  * @see CATPLMIntegrationAccess.CATIAdpErrorMonitor#CreateErrorCell
  */
  virtual HRESULT CreateErrorCell(const char * iErrorKey , const char * iErrorCatalog, enum PLMErrorSeverity iSeverity,
                  CATIPLMComponent * ipComponent, const CATPLMErrorParameters & iParameters, CATIAdpErrorCell* & opAdpErrorCell)= 0;

  /**
  * Creates a new Error cell in the Error monitor
  * @param iErrorKey
  *        the key describing this specific error in a given error messages catalog
  * @param iErrorCatalog
  *        the error messages catalog into wich the error is described
  * @param iSeverity
  *        the severity to be set on this Error 
  * @param ipAdpIdentificator
  *        the identifier of the eventual component that raised this error
  * @param iParameters
  *        the eventual parameters to be set on this error.
  *        Do not fill this object if no parameters to be set in the error message
  * @param opAdpErrorCell
  *        the Error cell created in the Error Monitor
  * @see CATPLMIntegrationAccess.CATIAdpErrorMonitor#CreateErrorCell
  */
  virtual HRESULT CreateErrorCell(const char * iErrorKey , const char * iErrorCatalog, enum PLMErrorSeverity iSeverity, CATIAdpPLMIdentificator* ipAdpIdentifier,
                  const CATPLMErrorParameters & iParameters, CATIAdpErrorCell* & opAdpErrorCell)= 0;

  /**
  * Creates a new Error cell in the Error monitor
  * @param iErrorKey
  *        the key describing this specific error in a given error messages catalog
  * @param iErrorCatalog
  *        the error messages catalog into wich the error is described
  * @param iSeverity
  *        the severity to be set on this Error 
  * @param ipAdpIdentificator
  *        the identifier of the eventual component that raised this error
  * @param opAdpErrorCell
  *        the Error cell created in the Error Monitor
  * @return
  *		 S_OK : ErrorCell successfully created
  * <br> E_FAIL : ErrorCell creation failed
  *	   E_INVALIDARG : input arg iErrorKey or iErrorCatalog is NULL
  */
  virtual HRESULT CreateErrorCell(const char * iErrorKey , const char * iErrorCatalog, CATErrorType iSeverity, CATIAdpPLMIdentificator* ipAdpIdentifier,
                  CATIAdpErrorCell* & opAdpErrorCell)= 0;

  /**
  * Creates a new Error cell in the Error monitor, with NLS parameter that is valued at run time
  * @param iErrorKey
  *        the key describing a generic error in a given error messages catalog, with a parameter
  * @param iErrorCatalog
  *        the error messages catalog into wich the error is described
  * @param iNLSMessage
  *        the NLS error message, previously resolved, valued at run time
  * @param iSeverity
  *        the severity to be set on this Error 
  * @param ipAdpIdentificator
  *        the identifier of the eventual component that raised this error
  * @see CATPLMIntegrationAccess.CATIAdpErrorMonitor#CreateErrorCell
  */
  virtual HRESULT CreateErrorCell(const char * iErrorKey , const char * iErrorCatalog, const CATUnicodeString & iNLSMessage, CATErrorType iSeverity, CATIAdpPLMIdentificator* ipAdpIdentifier)= 0;
  
	/**
	* Creates a new Error cell in the Error monitor, with NLS parameter that is valued at run time and associated PLMID parameters.
	* @param iErrorKey
	*        the key describing a generic error in a given error messages catalog, with a parameter
	* @param iErrorCatalog
	*        the error messages catalog into wich the error is described
	* @param iNLSMessage
	*        the NLS error message, previously resolved, valued at run time
	* @param iSeverity
	*        the severity to be set on this Error 
	* @param ipAdpIdentificator
	*        the identifier of the eventual component that raised this error
	* @param iAssociatedComponents
	*        the PLMIDs of the components associated to this error
	* @return
	*		 S_OK : ErrorCell successfully created
	* <br> E_FAIL : ErrorCell creation failed
	*	   E_INVALIDARG : input arg iErrorKey or iErrorCatalog is NULL
	*/
	virtual HRESULT CreateErrorCell(const char * iErrorKey , const char * iErrorCatalog, const CATUnicodeString & iNLSMessage, CATErrorType iSeverity, CATIAdpPLMIdentificator* ipAdpIdentifier, const CATPLMIDs & iAssociatedComponents) = 0;

  /**
  * Invokes Error interpretation asked to a specified implementation of CATIAdpErrorInterpreter 
  * this method invokes CATIAdpErrorInterpreter::InterpretErrors behaviour
  * @param iInterpreterType
  *        The late type for the specified implementation of CATIAdpErrorInterpreter to be invoked
  * @return
  *		 S_OK : Error interpretation successfull
  * <br> E_FAIL : Error interpretation failed
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	   E_INVALIDARG : input late type iInterpreterType doesn't match any implementation for CATIAdpErrorInterpreter
  */
  virtual HRESULT InterpretErrors(const CATUnicodeString & iInterpreterType)= 0;

  /**
  * Displays an interactive panel showing all error messages usefull to user
  * this method invokes the specific CATIAdpErrorReporter::DisplayErrors behaviour asked for
  * @param iDisplayerType
  *        The late type for the specified implementation of CATIAdpErrorReporter to be invoked
  * @return
  *		 S_OK : Error display successfull
  * <br> E_FAIL : Error display failed
  *	   E_INVALIDARG : input late type iDisplayerType doesn't match any implementation for CATIAdpErrorReporter
  */
  virtual HRESULT DisplayErrors(const CATUnicodeString & iDisplayerType)= 0;

  /**
  * Composes an error final reporting form in the format specified by a specified implementation of CATIAdpErrorReporter
  * this method invokes the specific CATIAdpErrorReporter::ComposeErrorReport behaviour asked for
  * @param iReporterType
  *        The late type for the specified implementation of CATIAdpErrorReporter to be invoked
  * @return
  *		 S_OK : Error reporting successfully composed
  * <br> E_FAIL : Error reporting failed
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	   E_INVALIDARG : input late type iReporterType doesn't match any implementation for CATIAdpErrorReporter
  */
  virtual HRESULT ComposeErrorReport(const CATUnicodeString & iReporterType)= 0;

  /**
  * treat errors received from the server.
  *
  * <br><b>Role</b>:
  * Completes the Error Monitor with the eventual global error returned by a QEOPS operation in DataBase.
  * An ErrorCell is created and stacked in ErrorMonitor when a pertinent error is described in the server message
  * returned by the QEOPS operation.
  * some generic error are filtered and hushed up as only indicating that errors on components should also be described in
  * the Server return message. 
  * Use then GetComponentErrorsFromServerRecord in a loop on the message records to get all errors on components.
  *
  * @param ipError [in]
  *   The handle on the error sent by the server
  * @param obImpactingError [out]
  *   TRUE if at least one Severe or Fatal error described in the server message.
  *   FALSE if No error or only Warning(s) described in the server message. 
  *
  * @return
  *   <code>S_OK</code>No error found in IncidentCollector
  *	  <code>S_FALSE</code>At least one incident/error found in IncidentCollector and successfully stacked into the Error Monitor
  *
  */
  virtual HRESULT GetErrorsFromServerMessage(CATIPLMCompRecordReadSet * ipRecordReadSet, CATBoolean & obImpactingError)= 0;

  /**
  * Completes the Error Monitor with all eventual operating errors raised by Server/Client during a Client/Server transaction
  * As many ErrorCells are created and stacked in ErrorMonitor as pertinent transaction errors are described in 
  * the PLMErrorStack managed by the PLMAdapter.
  * @param obImpactingError
  *        TRUE if at least one Severe or Fatal error described in the PLMErrorStack.
  *        FALSE if No error or only Warning(s) described in the PLMErrorStack. 
  * @return
  *		 S_OK : No error found
  *		 S_FALSE : At leat one Error found and successfully stacked into the Error Monitor
  * <br> E_FAIL : Error search in PLMErrorStack or error stacking in Monitor failed:
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  */
  virtual HRESULT GetErrorsFromServerTransaction(CATBoolean & oImpactingError) = 0;

  /**
  * Completes the Error Monitor with the eventual global error returned by a QEOPS operation in DataBase.
  * An ErrorCell is created and stacked in ErrorMonitor when a pertinent error is described in the server message
  * returned by the QEOPS operation.
  * some generic error are filtered and hushed up as only indicating that errors on components should also be described in
  * the Server return message. 
  * Use then GetComponentErrorsFromServerRecord in a loop on the message records to get all errors on components.
  * @param ipRecordReadSet
  *        The handle on the server return message
  * @param obImpactingError
  *        TRUE if at least one Severe or Fatal error described in the server message.
  *        FALSE if No error or only Warning(s) described in the server message. 
  * @param obHushedUp
  *        TRUE if the global error has been found and hushed up
  * @return
  *		 S_OK : No error found 
  *		 S_FALSE : At least one Error found and successfully stacked into the Error Monitor
  * <br> E_FAIL : Error search in the server message or error stacking in Monitor failed:
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	   E_INVALIDARG : input ipRecordReadSet is NULL
  */
  virtual HRESULT GetGlobalErrorFromServerMessage(CATIPLMCompRecordReadSet * ipRecordReadSet, CATBoolean & obImpactingError, CATBoolean & obHushedUp) = 0;

  /**
  * Completes the Error Monitor with the eventual error returned by a QEOPS operation on a given component in DataBase.
  * An ErrorCell is created and stacked in ErrorMonitor when a pertinent error is described in the server record 
  * currently read from the server message returned by the QEOPS operation.
  * @param ipRecordRead
  *        The handle on the server record currently scanned from the server return message
  * @param obImpactingError
  *        TRUE if at least one Severe or Fatal error described in the server message.
  *        FALSE if No error or only Warning(s) described in the server message. 
  * @return
  *		 S_OK : No error found 
  *		 S_FALSE : At least one Error found and successfully stacked into the Error Monitor
  * <br> E_FAIL : Error search in the server message or error stacking in Monitor failed:
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	   E_INVALIDARG : input ipRecordRead is NULL
  */
  virtual HRESULT GetComponentErrorFromServerRecord(CATIPLMRecordRead * ipRecordRead, CATBoolean & obImpactingError) = 0;

  /**
  * Completes the Error Monitor with the eventual error returned by a QEOPS operation on a given component in DataBase.
  * An ErrorCell is created and stacked in ErrorMonitor from the input CATIPLMError currently read by the PLMAdapter 
  * in the server message returned by the QEOPS operation.
  * WARNING: 
  * - When using GetGlobalErrorFromServerMessage service, some generic errors are detected, filtered and hushed up 
  *   as only indicating that errors on components should also be described in the Server return message.
  * - But when using this service, user should whether know if the input PLMError is global and comes from a CATIPLMCompRecordReadSet
  *   or from a CATIPLMRecordRead, to let the service filter if necessary the useless generic input errors.
  *   Otherwise, the Error Monitor may not be filled in a homogeneous way, compared to @see CATPLMIntegrationAccess.CATIAdpErrorMonitor#GetErrorsFromServerMessage or
  *   @see CATPLMIntegrationAccess.CATIAdpErrorMonitor#GetGlobalErrorFromServerMessage and CATPLMIntegrationAccess.CATIAdpErrorMonitor#GetComponentErrorFromServerRecord .
  *   So, please use those latest services instead of this one, when possible.
  * @param iPLMError [in]
  *        The input CATIPLMError
  * @param ipAdpIdentificator [in]
  *        the eventual identifier of the component raising this error, NULL for a global error. 
  * @param ibGlobalError [in]
  *        to be set to TRUE if the input PLMError is global and so comes from a CATIPLMCompRecordReadSet error decoding.
  *        to be set to FALSE if the input PLMError is local and so comes from a CATIPLMRecordRead error decoding.
  * @param oErrorType
  *        The input Error severity
  * @param obImpactingError [out]
  *   TRUE if this PLMError is a Severe or Fatal error.
  *   FALSE if this PLMError is only a Warning. 
  * @return
  *	<code>S_OK</code>When an ErrorCell successfully created and stacked in ErrorMonitor from input PLMError
  *	<code>S_FALSE</code>When Error hushed up, it is then a Global Error and no ErrorCell created in ErrorMonitor
  *   <code>E_FAIL</code>When Error decoding fails.
  *                      If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	<code>E_INVALIDARG<code> input iPLMError is NULL
  */
  virtual HRESULT GetComponentErrorFromPLMError(CATIPLMError * iPLMError, CATIAdpPLMIdentificator* ipAdpIdentificator, const CATBoolean ibGlobalError, CATErrorType & oErrorType, CATBoolean & obImpactingError) = 0;

  /**
  * Removes all ErrorCells from the Error Monitor 
  * to be used in CATPLMIntegration only -not implemented by CATIAdpErrorMonitor-
  */
  virtual HRESULT Empty() = 0;

  /**
  * Completes the Error Monitor with the eventual errors/incidents returned by a sub-QEOPS operation on a given component in DataBase.
  * An ErrorCell is created and stacked in ErrorMonitor from each error/incident stacked in the incident collector previously passed
  * to the sub-QEOPS operation to collect them
  * @param ihIncidentCollector
  *        The incident collector passed to a QEOPS sub-operation and eventually filled with errors/incidents 
  * @return
  *		 S_OK : No error found in IncidentCollector
  *		 S_FALSE : At least one incident/error found in IncidentCollector and successfully stacked into the Error Monitor
  * <br> E_FAIL : Error/incident search in IncidentCollector or error stacking in Monitor failed:
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	   E_INVALIDARG : input ihIncidentCollector is NULL
  */
  virtual HRESULT GetIncidentCollection() = 0;
  
  /**
  * Completes the Error Monitor with the eventual errors returned from a QEOPS operation by a CATAdpResultIterator reporting object.
  * An ErrorCell is created and stacked in ErrorMonitor from each error/incident stacked into the CATAdpResultIterator previously passed
  * to the QEOPS operation to collect them.
  * @param ipResultIterator
  *       the CATAdpResultIterator reporting object output by a QEOPS service. 
  * @see CATPLMIntegrationAccess.CATAdpResultIterator
  * @return
  *		 S_OK : All errors on components found into the CATAdpResultIterator have been transfered into the ErrorMonitor
  * <br> E_FAIL : Error/incident search into CATAdpResultIterator or error stacking in Monitor failed:
  *               If needed, please use CreateErrorCell to Add a new Error describing this failure
  *	    E_INVALIDARG : input ipResultIterator is NULL	
  */  
  virtual HRESULT GetErrorsFromResultIterator(CATAdpResultIterator* ipResultIterator) = 0;

  /**
  * Completes the Error Monitor with the eventual errors/incidents contained in the given incident group.
  * @param iIncidentGroup
  *        The incident group passed with errors/incidents. Note that related errors will be flushed (iIncidentGroup.Empty() is called).
  * @return
  *    S_OK    : No error found in iIncidentGroup
  *    S_FALSE : At least one incident/error found in iIncidentGroup and successfully stacked into the Error Monitor
  *    E_FAIL  : Error/incident search into IncidentCollector or error stacking in Monitor failed:
  *              If needed, please use CreateErrorCell to Add a new Error describing this failure
  */
  virtual HRESULT GetIncidentsFromGroup(CATOmyIncidentGroup & iIncidentGroup) = 0;

  /**
  * Gets an Iterator to scan the list of Error cells.
  * Hidden errors (@see CATIAdpErrorCell#HideError) won't be given by the returned iterator.
  * @param opErrorIterator
  *    The iteration handler returned.
  */
  virtual CATOmxSR<CATIAdpErrorIterator> GetErrorIterator()= 0;

  /**
  * Gets an iterator enabling the user to access to a set of client task messages.
  * <ul>
  * <li>Severity of returned messages can be CATErrorTypeWarning or CATErrorTypeInformation</li>
  * <li>Hide parameter of the message (@see CATIAdpErrorCell#HideError) is not taken into account. Every client task message is returned.>/li>
  * </ul>
  *
  * @return
  *    <li>an iterator on a set of client task messages</li>
  */
  virtual CATOmxIter<CATIAdpErrorCell> GetClientTaskMessagesIterator()=0;

  /**
  * @nodoc
  */
  virtual HRESULT CreateErrorCellForClientTask(const char * iErrorKey, const char * iErrorCatalog, enum PLMErrorSeverity iSeverity, CATIAdpPLMIdentificator* ipAdpIdentifier,
                                               const CATPLMErrorParameters & iParameters, CATIAdpErrorCell* & opAdpErrorCell) = 0;

};
#endif
