// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMREBriefcaseDataImportReporting.h
// Define the CATIPLMREBriefcaseDataImportReporting interface
//
//===================================================================
//
//  Apr 2008  Creation: LED
//===================================================================
#ifndef CATIPLMREBriefcaseDataImportReporting_H
#define CATIPLMREBriefcaseDataImportReporting_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMREBriefcaseDataImportReporting;
#else
extern "C" const IID IID_CATIPLMREBriefcaseDataImportReporting ;
#endif

#include "CATCollec.h"

class CATListPtrCATPLMREDataImportResultRecord;
class CATUuid;

//------------------------------------------------------------------

/**
* Interface exposing replication engine services dedicated to data import reporting.
* <br><b>Role</b>: This interface allows applications to implement their own data import reports
*/

class ExportedByCATPLMIntegrationInterfaces CATIPLMREBriefcaseDataImportReporting: public CATBaseUnknown
{
  CATDeclareInterface;

public:

/**
  * Start reporting applicative treaments.
  * <br><b>Role:</b>Start reporting applicative treaments.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Starting reporting applicative treaments succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Starting reporting applicative treaments failed.</dd>
  * <br>
  */ 
  virtual HRESULT StartReporting () = 0;  

/**
  * Start reporting applicative treaments.
  * <br><b>Role:</b>Start reporting applicative treaments.
  *
  * @param ipListOfDataImportResultsRecords
  *   List of raw data import results issued from the replication engine
  * @param iErrorMonitorId
  *   Error monitor id 
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Start reporting applicative treaments succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Start reporting applicative treaments failed.</dd>
  * <br>
  */ 
  virtual HRESULT RunReporting ( const CATListPtrCATPLMREDataImportResultRecord *ipListOfDataImportResultsRecords,
	                             const CATUuid & iErrorMonitorId ) = 0; 
 
/**
  * End reporting applicative treaments.
  * <br><b>Role:</b>End reporting applicative treaments.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>Ending reporting applicative treaments succeeded.</dd>
  *   <dt>E_FAIL</dt><dd>Ending reporting applicative treaments failed.</dd>
  * <br>
  */ 
  virtual HRESULT EndReporting () = 0; 

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMREBriefcaseDataImportReporting, CATBaseUnknown );

#endif
