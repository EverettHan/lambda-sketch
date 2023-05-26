// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATIPLMReplReportServices.h
// Define the CATIPLMReplReportServices interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Oct 2006  Creation: PA
//===================================================================
#ifndef CATIPLMReplReportServices_H
#define CATIPLMReplReportServices_H

/**
 * @level Private
 * @usage U3
 */

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplReportServices;
#else
extern "C" const IID IID_CATIPLMReplReportServices ;
#endif

#include "CATCollec.h"

class CATLISTV(CATPLMID);
class CATPLMReplicationReport;
class CATDbBinary;
class CATPLMReplReportsComparison;

//------------------------------------------------------------------

/**
  * Interface associated with the Replication Engine.
  * <br><b>Role</b>: it allows to access and compare replication information issued from different repositories
  *   
  * <p><b>1.    Definition of the ReplicationEngine</b>
  * 
  * <br>The ReplicationEngine provides all the services necessary to handle replication.
  * <br> - The Change site ownership : Allowing to transfer the ownership of an object to another site.
  * <br> - The Capture : Allowing to collect all the data that need to be replicated to another site
  * <br> - The Apply : Allowing to insert in the current site replicated data comming from another site
  * <br> - The Acknowledge : Allowing to insert the acklowledgement coming from a replicated site.
  * <br> - The Reclaim Ownership : Allowing to force a local ownership if it has been lost during a transfer.
  * <br><br>
  * Additionally, it provides the capability to copy components from a repository to another:
  * <br> - ExportToBriefcase: Generates a file containing the components extracted from repository A.
  * <br> - ImportBriefcaseAsNew: Imports in repository B the content of the file by creating new objects.
  * 
  * <p><b>2.	Access to the replication information</b>
  * <br> The present interface allows to access and compare replication information issued from 2 repositories.
  * 
  */

class ExportedByCATPLMIntegrationInterfaces CATIPLMReplReportServices: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

/**
  * Creates from a repository a replication report corresponding to a list of PLM entities.
  * @param iListOfEntitiesIDs
  *   List of CATPLMIDs of the PLM entities
  * @param opReplicationReport
  *   Replication report containing the replication information 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  *   <dd>The creation of the replication report succeeded. 
  *   </dd>
  *   <dt>E_FAIL</dt>  
  *   <dd>The creation of the replication report failed.
  *   </dd>
  * <br>
  */
  virtual HRESULT CreateReplicationReport( const CATLISTV(CATPLMID) &iListOfEntitiesIDs,  
                                           CATPLMReplicationReport *&opReplicationReport ) = 0 ;
/**
  * Creates a replication report from a replication report stored as CATDbBinary
  * @param iBinaryReplicationReport
  *   Replication report as a CATDbBinary
  * @param opReplicationReport
  *   Replication report  
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  *   <dd>The creation of the replication report succeeded. 
  *   </dd>
  *   <dt>E_FAIL</dt>  
  *   <dd>The creation of the replication report failed.
  *   </dd>
  * <br>
  */
  virtual HRESULT CreateReplicationReport( const CATDbBinary &iBinaryReplicationReport, 
                                           CATPLMReplicationReport *&opReplicationReport ) = 0;

/**
  * Compares 2 replication reports
  * @param iReplicationReport1
  *   First replication report  
  * @param iReplicationReport2
  *   Second replication report 
  * @param opReplReportsComparison
  *   Results of comparison of the 2 replication reports 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  *   <dd>The comparison of the replication reports succeeded. 
  *   </dd>
  *   <dt>E_FAIL</dt>  
  *   <dd>The comparison of the replication reports failed.
  *   </dd>
  * <br>
  */
  virtual HRESULT CompareReplicationReports( CATPLMReplicationReport &iReplicationReport1, CATPLMReplicationReport &iReplicationReport2,
	                                         CATPLMReplReportsComparison *&opReplReportsComparison ) = 0;

/**
  * Stream a replication report as a CATDbBinary
  * @param iReplicationReport
  *   Replication report  
  * @param oBinaryReplicationReport
  *   Replication report streamed as a CATDbBinary
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt>  
  *   <dd>The streaming of the replication report as a CATDbBinary succeeded. 
  *   </dd>
  *   <dt>E_FAIL</dt>  
  *   <dd>The streaming of the replication report as a CATDbBinary failed.
  *   </dd>
  * <br>
  */
  virtual HRESULT StreamReplicationReport( CATPLMReplicationReport & iReplicationReport, 
                                           CATDbBinary &oBinaryReplicationReport ) = 0;

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMReplReportServices, CATBaseUnknown );

#endif
