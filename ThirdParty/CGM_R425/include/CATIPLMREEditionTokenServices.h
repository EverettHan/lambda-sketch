// COPYRIGHT Dassault Systemes 2005-2017
//===================================================================
//
// CATIPLMREEditionTokenServices.h
// Define the CATIPLMREEditionTokenServices interface
//
//===================================================================
//
//  Apr 2008  Creation: LED
//===================================================================
#ifndef CATIPLMREEditionTokenServices_H
#define CATIPLMREEditionTokenServices_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATListOfShort.h"
#include "CATUnicodeString.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMREEditionTokenServices;
#else
extern "C" const IID IID_CATIPLMREEditionTokenServices ;
#endif

#include "CATCollec.h"

class CATLISTV(CATPLMID);
class CATPLMRepositoryName;

//------------------------------------------------------------------

/**
* Interface exposing services dedicated to PLM channel management.
* <br><b>Role</b>: This interface allows to create/remove a PLM channel.
* <br><b>Channel</b>: Exchange context created between two specific repositories, to allow for optimized back and forth data exchange and ownership transfers.
* <br><b>Plug</b>: Persistent infrastructure object that materializes the channel in each of the two connected repositories. The plug holds all persisted context data associated to the channel. A channel is the combination of two connected plugs.
* <br><b>Revision</b>: Briefcase file sent over a channel. The revision is the physical support for the exchange of data and ownership between plugs. Each plug publishes sequential revisions that are sent to the peer plug. 
* <br><b>Edition Token Transfer</b>: Capability to transfer the edition authorization on a given replicated PLM entity from one PLM repository to another. 
*
* <br>This interface can be obtained via @href CATPLMEnginesToolbox#GetEditionTokenServices
* 
* @see CATPLMEnginesToolbox
*/

class ExportedByCATPLMIntegrationInterfaces CATIPLMREEditionTokenServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Edition token repair status for a set of PLM entities
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>Local</tt><dd>The repository has the edition token on the PLM entities
  * @param <tt>Distant</tt><dd>The edition token on the PLM entities is owned by a distant site
  * </dl>
  */
  enum CATPLMREEditionTokenRepairStatus 
  {
    Local=0,           
    Distant=1        
  }; 

  /**
  * Repair the edition tokens of a set of PLM entities forcing them to “Local” or “Distant”.
  * <br><b>Role:</b>Repair the edition tokens of a set of PLM entities forcing them to “Local” or “Distant”.
  *
  * @param iComponents
  *   PLM components to be repaired
  * @param iStatus
  *   Edition token to be forced 
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The edition tokens were successfully forced.</dd>
  *   <dt>E_FAIL</dt><dd>Repairing the edition tokens failed.</dd>
  * <br>
  */ 

  virtual HRESULT RepairOwnership  ( const CATLISTV(CATPLMID) &iComponents,
                                     CATPLMREEditionTokenRepairStatus iStatus ) = 0;  

  /**
  * Fetch next edition token state desired by customer after executing export or site information command.
  * <br><b>Role:</b>Fetch next edition token state desired by customer from the business rule after executing export or site information command.
  *
  * @param ilistOfPLMIDs
  *   PLM Ids of objects on which next edition token state is to be fetched using the business rule.
  * @param isOperationId
  *   Current operation (ExportWithDelegationAndWaive or SiteInformationRevoke) for which we want to know the next edition token state using business rule
  * @param ioplistOfCurrentEditionTokenStatuses
  *   List of edition token states currently set on a object
  * @param oplistOfExpectedEditionTokenStatuses
  *   List of edition token states to be set on an object as asked by the Business Rule
  * @param iExchangeChannelName
  *   Name of exchange channel used during 3dxml authoring export with batch.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The next edition token state is successfully retrieved.</dd>
  *   <dt>E_FAIL</dt><dd>Failed to retrieve next edition token state.</dd>
  * <br>
  */ 

  virtual HRESULT FetchEditionTokenStatusesUsingBL( const CATLISTV(CATPLMID)  & ilistOfPLMIDs
                                                  , const CATString           & isOperationId
                                                  , CATListOfInt             *& ioplistOfCurrentEditionTokenStatuses
                                                  , CATListOfShort           *& oplistOfExpectedEditionTokenStatuses
                                                  , const CATUnicodeString    & iExchangeChannelName = "") = 0;

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMREEditionTokenServices, CATBaseUnknown );

#endif
