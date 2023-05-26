/* -*-c++-*- */
/**
* @level Protected
* @usage U3
*/
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2008
//-----------------------------------------------------------------------------
//
// class CATIAdpErrorMonitor.h
//
// Handle dedicated to the management of all errors raised by a (series) 
// of AdpServices enabled to collect PLM errors
// 
//-----------------------------------------------------------------------------
// 04/07/2008 Creation - United Colors of Error Management                  VCS
//-----------------------------------------------------------------------------

#ifndef CATIAdpErrorMonitor_H
#define CATIAdpErrorMonitor_H

#include "CATPLMIntegrationAccess.h"
//#include "CATAdpErrorMonitorRestricted.h"
#include "CATBaseUnknown.h"
#include "CATIAdpErrorMonitorAbstract.h"
#include "CATIAdpErrorIterator.h"
#include "CATError.h"
#include "CATLISTV_CATPLMID.h"

class CATIAdpPLMIdentificator;
class CATInternalError;
class CATUuid;
class CATUnicodeString;
class CATIPLMRecordRead;
class CATIPLMCompRecordReadSet;
class CATIPLMError;


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationAccess IID IID_CATIAdpErrorMonitor;
#else
extern "C" const IID IID_CATIAdpErrorMonitor ;
#endif

//-----------------------------------------------------------------------------

/**
 * Possible search targets for PLM data to search/read 
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>SearchInSession</tt> <dd> PLM Data are searched in current session.
 * @param <tt>SearchInDataBase</tt> <dd> PLM Data are searched in DataBase.
 * @param <tt>SearchAnywhere</tt>  <dd> PLM Data are searched first in session then in DataBase.
 * </dl>
 */
enum AdpSearchTarget
{
  SearchInSession=0,
  SearchInDataBase=1,
  SearchAnywhere=2
};

/**
* Interface intended to handle applicative monitoring for all errors raised 
* during its life cycle in any interactive or batch context.
* <br><b>Role</b>: The ErrorMonitor acceded through this interface is the container for all errors happening
* during calls to PLM services/Engines the monitor is passed to.
* The ErrorMonitor creation is invoked by application, using CATAdpErrorMonitorFactory::CreateErrorMonitor.
* The ErrorMonitor destruction is asked by application when releasing the CATIAdpErrorMonitor pointer.
* The ErrorMonitor also offers the capability to Interpret, Filter, Display or Report errors to the end user.
* Several ErrorMonitors may be declared a the same time in the current session for distinct uses.
* They are all identified in current session and a handler on each ErrorMonitor can retrieved
* through its idenfier using CATAdpErrorMonitorFactory::FindErrorMonitor.
* Application using this decides wich services are to be monitored by a given monitor 
* and when errors have to be filtered and/or displayed.
* Displaying/reporting asked by the ErrorMonitor invokes applicative implementation(s) of CATIAdpErrorReporter interface:
* This implementation capability is restricted, to keep a coherent LookAndFeel among applications.
* Interpretation and filtering by the ErrorMonitor invokes applicative implementation(s) of CATIAdpErrorInterpreter interface:
* As a lot of errors may be the consequence of an initial error, the interpretation is about the deprecation 
* of errors not intented to be displayed and/or beeing replaced for display by new factorized ones, more concise.
* 
* <p>
* For use only - This interface cannot be re-implemented by applications using it.
*/

class ExportedByCATPLMIntegrationAccess CATIAdpErrorMonitor: public CATIAdpErrorMonitorAbstract
{
  CATDeclareInterface;

public:

  using CATIAdpErrorMonitorAbstract::CreateErrorCell; // For other method signatures usage.
                                                                 
  /**
  * Creates a new Error cell in the Error monitor
  * @param iErrorKey
  *        the key describing this specific error in a given error messages catalog
  * @param iErrorCatalog
  *        the error messages catalog into wich the error is described
  * @param iSeverity
  *        the severity to be set on this Error 
  * @param iComponentId
  *    the session identifier of the component that raised this error:
  *    When a component valid and opened in session is given as entry, the display identifier of the component is read
  *    and then set as the single parameter of the input error message. 
  *    Warning: The input error message is supposed to support as a single parameter the display identifier of the component.    
  * @param opAdpErrorCell
  *        the Error cell created in the Error Monitor
  * @return
  *		 S_OK : ErrorCell created and Display identification of the component that raised the error is successful 
  *		 S_FALSE : ErrorCell created but Display identification of the component that raised the error failed
  * <br> E_FAIL : ErrorCell creation failed
  *	   E_INVALIDARG : input arg iErrorKey or iErrorCatalog is NULL
  */
  virtual HRESULT CreateErrorCell(const char * iErrorKey, const char * iErrorCatalog, CATErrorType iSeverity, CATComponentId iComponentId, CATIAdpErrorCell* & opAdpErrorCell)= 0;

  /**
  * Completes the external identification of all component that raised errors in the ErrorMonitor
  * <ul>
  * <li>CATIAlias identification is invoked for components opened in session </li>
  * <li>External identification set of attributes is queried in DataBase for components not opened in session</li>
  * </ul>
  * @param iSearchTarget
  *         SearchInSession:  PLM Data are searched in current session.
  *         SearchInProvider: PLM Data are searched in their origin provider.
  *         SearchAnywhere:   PLM Data are searched first in session then in their origin provider
  * @return
  *		 S_OK : identification successfull for all components found to be identified for display in current Search context
  *		 S_FALSE : no component needs to be identified
  * <br> E_FAIL : identification failed for at least one component. In most cases, this error should not be considered by caller 
  *               as stopping the current process : Error processing/display is to be continued even if components identification
  *               is not completed or failed
  */
  virtual HRESULT CompleteComponentsIdentification(const AdpSearchTarget iSearchTarget=SearchInSession)= 0;

  using CATIAdpErrorMonitorAbstract::GetErrorsFromServerMessage; // For CATIPLMCompRecordReadSet signature usage.

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
   virtual HRESULT GetErrorsFromServerMessage(CATIPLMError * ipError, CATBoolean & obImpactingError) = 0;

   virtual HRESULT Concatenate(CATIAdpErrorMonitor *ispErrorMonitor) = 0;
   virtual void Concatenate(CATIAdpErrorCell *ispErrorCell) = 0;

};
//-----------------------------------------------------------------------------
 CATDeclareHandler( CATIAdpErrorMonitor, CATBaseUnknown );

#endif
