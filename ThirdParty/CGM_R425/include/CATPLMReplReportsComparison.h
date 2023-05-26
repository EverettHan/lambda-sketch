#ifndef _CATPLMReplReportsComparison_h_
#define _CATPLMReplReportsComparison_h_
/**
* @level Private
* @usage U2
*/
//
/*
===============================================================================
===============================================================================
*/
#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATLISTV(CATPLMID);
class CATPLMID;

// definition de la classe CATPLMReplReportsComparison classe abstraite

class ExportedByCATPLMIntegrationInterfaces CATPLMReplReportsComparison: public CATBaseUnknown
{
 public: 

 /**
   * Existence of the entity in the 2 reports
   * <tt> Possible values:</tt>
   * <dl>
   * @param <tt>EntityExistingInBothReplReports</tt>   <dd> The entity exists in the 2 replication reports.
   * @param <tt>EntityOnlyExistingInFirstReplReport</tt> <dd> The entity only exists in replication report 1.
   * @param <tt>EntityOnlyExistingInSecondReplReport</tt> <dd> The entity only exists in replication report 2.
   * </dl>
   */
  enum CATPLMReportsExistence 
  {
	EntityExistingInBothReplReports=0,       
	EntityOnlyExistingInFirstReplReport=1,   
	EntityOnlyExistingInSecondReplReport=2 	
  };

 /**
   * Comparison of the status of an entity between 2 replication reports
   * <tt> Possible values:</tt>
   * <dl>
   * @param <tt>A_Sup_B</tt> <dd>   The entity is in a more advanced state in the repository corresponding to replication report 1.
   * @param <tt>A_Inf_B</tt> <dd>   The entity is in a more advanced state in the repository corresponding to replication report 2.
   * @param <tt>A_Equal_B</tt> <dd> The entity is in the same state in the 2 repositories corresponding to the 2 replication reports.
   * @param <tt>A_NotComparable_B</tt> <dd> The status of the entity in the 2 repositories cannot be compared : case the entity does not exist
   *                                        in one replication report, case the entity is missing at least in one repository, rogue case , … 
   * </dl>
   */
  enum CATPLMStateComparisonStatus 
  {
	A_Sup_B=0,       
	A_Inf_B=1,   
	A_Equal_B=2,
	A_NotComparableTo_B=3
  };

 /**
   * Capability to transfer the site ownership from repository 1 ( corresponding to replication report 1 ) towards repository 2 
   * ( corresponding to replication report 2 ).
   * <tt> Possible values:</tt>
   * <dl>
   * @param <tt>Undefined</tt> <dd> Unable to determine if the site ownership transfer is possible or not.
   * @param <tt>No</tt> <dd>  The site ownership transfer is not possible for this entity.
   * @param <tt>Yes</tt> <dd> The site ownership transfer is possible for this entity.
   * </dl>
   */
  enum CATPLMSiteOwnershipTransferStatus 
  {
	Undefined=0,       
	No=1,   
	Yes=2
  };

 /**
   * Capability to transfer the site ownership from repository 1 ( corresponding to replication report 1 ) towards repository 2 
   * ( corresponding to replication report 2 ): site ownership transfer diagnosis.
   * <tt> Possible values:</tt>
   * <dl>
   * @param <tt>EntityNotExistingInFirstReplReport</tt> <dd> The entity does not exist in replication report 1.
   * @param <tt>UnknownEntityInFirstRepository</tt> <dd>  The entity is unknown in repository 1.
   * @param <tt>SiteOwnershipOwnedByAnOtherRepository</tt> <dd> The entity is in “Distant” ownership status in repository 1.
   * @param <tt>SiteOwnershipTransferAlreadyRequestedFromFirstRepository </tt> <dd> The entity is in “Pending” ownership status in repository 1.
   * @param <tt>SiteOwnershipTransferAlreadySentFromFirstRepository </tt> <dd> The entity is in “Waiting” ownership status in repository 1.
   * @param <tt>EntityNotExistingInSecondReplReport </tt> <dd> The entity does not exist in replication report 2.
   * @param <tt>UnknownEntityInSecondRepository </tt> <dd> The entity is unknown in repository 2.
   * @param <tt>EntitySeenAsNotExchangedInSecondRepository  </tt> <dd> The entity is seen as not exchanged in repository 2
   * @param <tt>DesynchronizedEntity</tt> <dd> The entity is in a less advanced state in repository 2.
   * @param <tt>InvalidSiteOwnershipStatusInSecondRepository</tt> <dd> The entity is not in “distant status” in repository 2.
   * @param <tt>TransferableSiteOwnership</tt> <dd> Transferable site ownership entity : entity for which the site ownership can be transferred.   
   * </dl>
   */
  enum CATPLMSiteOwnershipTransferDiagnosis 
  {
	EntityNotExistingInFirstReplReport=0,       
	UnknownEntityInFirstRepository=1,   
	SiteOwnershipOwnedByAnOtherRepository=2,
	SiteOwnershipTransferAlreadyRequestedFromFirstRepository=3,
	SiteOwnershipTransferAlreadySentFromFirstRepository=4,
	EntityNotExistingInSecondReplReport=5,
	UnknownEntityInSecondRepository=6,
	EntitySeenAsNotExchangedInSecondRepository=7,
    DesynchronizedEntity=8,
	InvalidSiteOwnershipStatusInSecondRepository=9,
	TransferableSiteOwnership=10
  };
  
 /**
   * Gets the existence of an entity in the 2 replication reports
   * @param iEntityID
   *   The PLM entity (known by its CATPLMID).
   * @param oEntityExistence
   *   The existence of the entity in the 2 replication reports
   *   ( possible values in above CATPLMReportsExistence enum )
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The test of existence of the entity in the 2 replication reports succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The test of existence of the entity in the 2 replication reports failed.
   *   </dd>
   */
  virtual HRESULT GetReportsExistence( const CATPLMID &iEntityID, 
                                       CATPLMReportsExistence  &oEntityExistence ) = 0;

 /**
   * Gets the comparison status of the state of the entity in the 2 replication reports
   * @param iEntityID
   *   The PLM entity (known by its CATPLMID).
   * @param oStateComparisonStatus
   *   The comparison status of the state of the entity in the 2 replication reports
   *   (possible values in above CATPLMStateComparisonStatus enum)
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd>The comparison status of the state of the entity in the 2 replication reports succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd>The comparison status of the state of the entity in the 2 replication reports failed.
   *   </dd>
   */

  virtual HRESULT GetStateComparisonStatus( const CATPLMID &iEntityID,
                                                 CATPLMStateComparisonStatus  &oStateComparisonStatus ) = 0;

  /**
   * Gets the site ownership transfer status for a PLM entity  
   * @param iEntityID
   *   The PLM entity (known by its CATPLMID).
   * @param oSiteOwnershipTransferStatus
   *   The site ownership transfer status for the PLM entity 
   *   (possible values in above CATPLMSiteOwnershipTransferStatus enum)
   * @param oSiteOwnershipTransferDiagnosis
   *   The site ownership transfer diagnosis for the PLM entity 
   *   (possible values in above CATPLMSiteOwnershipTransferDiagnosis enum)
   * @return 
   * <br><b>Legal values</b>
   *   <dt>S_OK</dt>  
   *   <dd> The site ownership transfer status for a PLM entity succeeded. 
   *   </dd>
   *   <dt>E_FAIL</dt>  
   *   <dd> The site ownership transfer status for a PLM entity failed.
   *   </dd>
   */
  virtual HRESULT GetSiteOwnershipTransferStatus( const CATPLMID &iEntityID,
                                                  CATPLMSiteOwnershipTransferStatus &oSiteOwnershipTransferStatus, 
                                                  CATPLMSiteOwnershipTransferDiagnosis &oSiteOwnershipTransferDiagnosis ) = 0;  

  protected:

  // Constructor & Destructor
  CATPLMReplReportsComparison();
  virtual ~CATPLMReplReportsComparison();  
  
};
  
#endif







