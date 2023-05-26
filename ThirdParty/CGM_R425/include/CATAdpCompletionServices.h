// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATAdpCompletionServices.h
//
//===================================================================
//
// Usage notes:
// Tutorial to retrieve errors from a CATIAdpErrorMonitor:
// AdpIterationFilter iIterationFilter=DisplayableErrors;
// CATIAdpErrorIterator* pErrorIterator = NULL;
// ioErrorMonitor->GetErrorIterator(pErrorIterator,iIterationFilter);
// CATIAdpErrorCell* opErrorCell = NULL;
 // you must do that while opErrorCell!=NULL
// pErrorIterator->Next(opErrorCell);
// // for each opErrorCell, you can try to know if it is a fatal error:
// CATError *opError = NULL
// opErrorCell->GetError(&opError);
// CATErrorType type;
// type = opError->GetInformationOnErrorType ();
//===================================================================
/**
 * @level Protected
 * @usage U1  
 */
#ifndef CATAdpCompletionServices_H
#define CATAdpCompletionServices_H

#include "CATPLMIntegrationAccess.h"

#include "IUnknown.h"
#include "CATErrorDefs.h"
#include "CATCollec.h"

class CATUnicodeString ;
class CATLISTV(CATPLMID);
class CATIAdpErrorMonitor;
class CATPLMRepositoryName;

/**
* Class to access Completion services
*
* <br><b>Role</b>: This class provides all high level functions for Completion.
*/
class ExportedByCATPLMIntegrationAccess CATAdpCompletionServices
{
public:
   
   /** 
    * Call Completion service for Export scenarios.
    * <br><b>Role:</b>This method allows you to complete a set of PLM Components for Export purpose,
    * according to the specified Completion Procedure.
    * @param iProcedureName
    *   The name of the Completion Procedure to apply.
    * @param iInputIDs
    *   The identifiers of the PLM Components to complete. Must be simple PLMIDs.
    * @param oOutputIDs
    *   The identifiers of the PLM Components after Completion. Simple unique PLMIDs. No order.
    * @param ioErrorMonitor
    *   The error monitor. it shouldn't be NULL if you want to treat errors.
    *   Here is what you have to do to instantiate a CATIAdpErrorMonitor:
    *   CATIAdpErrorMonitor * ioErrorMonitor = NULL
    *   CATUuid oErrorMonitorId;
    *   rc = CATAdpErrorMonitorFactory::CreateErrorMonitor(oErrorMonitorId,ioErrorMonitor);
    * @return
    *   <ul>
    *   <li><tt>S_OK</tt> Completion successfull. </li> 
    *   <li><tt>S_FALSE</tt> the server has returned an xml well formed and the report ioErrorMonitor contains errors.</li> 
    *   <li><tt>E_FAIL</tt> the server has returned an xml badly formed, we are not able to parse it and to describe errors that have occured.</li>
                            or
                            we are not able to retrieve the list of plmids
    *   <li><tt>E_INVALIDARG</tt> Input parameter are not correct.</li>
    *  </ul>
    */
    static HRESULT CompletionForExport ( const CATUnicodeString &    iProcedureName,
                                        const CATLISTV(CATPLMID) &  iInputIDs,
                                        CATLISTV(CATPLMID) &  oOutputIDs,
                                        CATIAdpErrorMonitor * ioErrorMonitor = NULL);

private:
  /**
  * Checks that all plmids provided are associated to a single repository
  *     and returns the repository name.
  *
  * @param iInputIDs
  *             The list of input plmids to be checked
  *
  * @param oRepoName
  *             The name of the repository contained in the input list
  *
  * @return
  *   <ul>
  *   <li><tt>S_OK</tt>   We found only one provider.               </li> 
  *   <li><tt>E_FAIL</tt> We found at least two different providers.</li>
  *   <li><tt>E_INVALIDARG</tt> Input parameter are not correct.</li>
  *  </ul>
  * 
  **/
  static HRESULT  CheckAndGetRepositoryName( const CATLISTV(CATPLMID) &  iInputIDs, CATPLMRepositoryName &oRepoName );
};

#endif
