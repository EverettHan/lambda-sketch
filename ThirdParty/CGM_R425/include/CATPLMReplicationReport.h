#ifndef _CATPLMReplicationReport_h_
#define _CATPLMReplicationReport_h_
// COPYRIGHT DASSAULT SYSTEMES 2004-2012
/**
  * @level Private
  * @usage U2
  */

#include "CATPLMIntegrationInterfaces.h"

#include "CATBaseUnknown.h"
#include "CATCollec.h"

class CATLISTV(CATPLMID)     ;
class CATPLMID               ;
class CATPLMRepositoryStatus ;

// definition de la classe CATPLMReplicationReport classe abstraite

class ExportedByCATPLMIntegrationInterfaces CATPLMReplicationReport : public CATBaseUnknown
{
   public: 

    /**
      * Ownership status of a PLM entity.
      * <tt> Possible values:</tt>
      * <dl>
      * <Dt>Local</dt>     <dd>The repository has the site ownership on the entity.</dd>
      * <dt>Pending</dt>   <dd>Someone has requested the site ownership on the entity to be transferred to a distant site. It will be transmitted next time the entity will be exchanged..</dd>
      * <dt>Waiting</dt>   <dd>The site ownership on the entity is currently being transmitted to a distant site (and successful reception has not been confirmed).</dd>
      * <dt>Distant</dt>   <dd>The site ownership on the entity is owned by a distant site.</dd>
      * <dt>Delegator</dt> <dd>The repository has the site ownership on the entity, but it has been delegated.</dd>
      * <dt>Delegated</dt> <dd>This is a distant entity on this repository, but modification authorization has been provided.</dd>
      * <dt>Forward</dt>   <dd>This is a distant entity on this repository that has received a modification authorization (delegation) delegated to another locations.</dd>
      * <dt>Shared</dt>    <dd>The repository has the site ownership on the entity that has been exported or published.</dd>
      * </dl>
      */
      enum CATPLMSiteOwnerShipStatus 
      {
        Local     = 0
      , Pending   = 1
      , Waiting   = 2
      , Distant   = 3
      , Delegator = 4
      , Delegated = 5
      , Forward   = 6
      , Shared    = 7
      } ;

    /**
      * Repository status of a PLM entity
      * <tt> Possible values:</tt>
      * <dl>
      * <dt>NotExistingInReport</dt>   <dd>The entity does not exist in the replication report.</dd>
      * <dt>UnknownFromRepository</dt> <dd>The entity is unknown from the repository.</dd>
      * <dt>Present_NotExchanged</dt>  <dd>The entity is present in the repository, but has never being exchanged with an other repository.</dd>
      * <dt>Present_Exchanged</dt>     <dd>The entity is present in the repository and has already being exchanged with an other repository.</dd>
      * <dt>Deleted_Exchanged</dt>     <dd>The entity has already being exchanged with an other repository and is now deleted.</dd>
      * </dl>
      */
      enum CATPLMRepositoryStatus 
      {
        NotExistingInReport   = 0
      , UnknownFromRepository = 1
      , Present_NotExchanged  = 2
      , Present_Exchanged     = 3
      , Deleted_Exchanged     = 4
      } ;

    /**
      * Get the list of PLM entities of a replication report
      * @param oListOfEntitiesIDs
      *   The list of PLM entities of a replication report
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>The access to the list of PLM entities of a replication report succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>The access to the list of PLM entities of a replication report failed.</dd>
      * </dl>
      */
      virtual HRESULT GetListOfPLMEntities( CATLISTV(CATPLMID) &oListOfEntitiesIDs ) = 0 ;

    /**
      * Get the site ownership status of a PLM entity
      * @param iEntityID
      *   The PLM entity (known by its CATPLMID)
      * @param oSiteOwnershipStatus
      *   The site ownership status of the PLM entity
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>The access to the site ownership status of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt> <dd>The access to the site ownership status of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetSiteOwnerShipStatus( const CATPLMID &iEntityID , CATPLMSiteOwnerShipStatus & oSiteOwnershipStatus ) = 0 ;

    /**
      * Get the repository status of a PLM entity
      * @param iEntityID
      *   The PLM entity (known by its CATPLMID)
      * @param oRepositoryStatus
      *   The repository status of the PLM entity
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>    <dd>The access to the repository status of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt>  <dd>The access to the repository status of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetRepositoryStatus( const CATPLMID         & iEntityID
                                         , CATPLMRepositoryStatus & oRepositoryStatus ) = 0 ;

    /**
      * Get the weakened status of a PLM entity
      * @param iEntityID
      *   The PLM entity (known by its CATPLMID)
      * @param oWeakened
      *   Yes : The PLM entity is weakened
      *   No  : The PLM entity is not weakened
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>The access to the weakened status of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt> <dd>The access to the weakened status of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetWeakenedStatus( const CATPLMID & iEntityID , CATBoolean & oWeakened ) = 0 ;  

    /**
      * /!\ do not mistake for the previous method! Here weakened means degraded by downward compatibility
      * Get the degraded status of a PLM entity
      * @param iEntityID
      *   The PLM entity (known by its CATPLMID)
      * @param oDCWeakened
      *   Yes : The PLM entity has been created in downward compatibility mode
      *   No  : The PLM entity has not been created in downwward compatibility mode
      * @return 
      * <br><b>Legal values</b>
      * <dl>
      *   <dt>S_OK</dt>   <dd>The access to the degraded status of the PLM entity succeeded.</dd>
      *   <dt>E_FAIL</dt> <dd>The access to the degraded status of the PLM entity failed.</dd>
      * </dl>
      */
      virtual HRESULT GetDownwardCompatibilityWeakenedStatus( const CATPLMID & iEntityID , CATBoolean & oDCWeakened ) = 0 ;  

	  /**
	* Get "Waive" information for the PLM entity
	* @param iEntityID [in]
	*   PLMId of the PLM entity
	* @param ooWaiveMask [out]
	*   int indicating if the PLM entity is waived
	* @return
	* <br><b>Legal values</b>
	*   <dt>S_OK</dt>
	*   <dd>indicating if the PLM entity is deleted succeeded.
	*   </dd>
	*   <dt>E_XXXX</dt>
	*   <dd>Internal error when trying to indicate if the PLM entity is waived.
	*   </dd>
	* <br>
	*/
	virtual  HRESULT GetWaiveMaskStatus(const CATPLMID &iEntityID, int &oWaiveMask) = 0;

   protected:

      // Constructor & Destructor
      CATPLMReplicationReport() ;
      virtual ~CATPLMReplicationReport() ;  
} ;
#endif
