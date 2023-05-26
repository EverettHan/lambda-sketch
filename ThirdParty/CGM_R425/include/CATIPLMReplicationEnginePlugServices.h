// COPYRIGHT Dassault Systemes 2005
//===================================================================
//
// CATIPLMReplicationEnginePlugServices.h
// Define the CATIPLMReplicationEnginePlugServices interface
//
//===================================================================
//
//  Apr 2008  Creation: LED
//===================================================================
#ifndef CATIPLMReplicationEnginePlugServices_H
#define CATIPLMReplicationEnginePlugServices_H

/**
* @level Protected
* @usage U3
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATPLMREBusinessCard.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMIntegrationInterfaces IID IID_CATIPLMReplicationEnginePlugServices;
#else
extern "C" const IID IID_CATIPLMReplicationEnginePlugServices ;
#endif

#include "CATCollec.h"

class CATUnicodeString;
class CATString;
class CATPLMREPlugCreateOptions; 
class CATPLMREPlugSynchronizeOptions; 
class CATPLMREPlugPublishOptions;
class CATPLMREPlugTransferOptions;
class CATLISTV(CATPLMID);
class CATPLMREExchangeForm;

//------------------------------------------------------------------

/**
* Interface exposing services dedicated to PLM channel management.
* <br><b>Role</b>: This interface allows to create/remove a PLM channel.
* <br><b>Channel</b>: Exchange context created between two specific repositories, to allow for optimized back and forth data exchange and ownership transfers.
* <br><b>Plug</b>: Persistent infrastructure object that materializes the channel in each of the two connected repositories. The plug holds all persisted context data associated to the channel. A channel is the combination of two connected plugs.
* <br><b>Revision</b>: Briefcase file sent over a channel. The revision is the physical support for the exchange of data and ownership between plugs. Each plug publishes sequential revisions that are sent to the peer plug. 
* <br><b>Edition Token Transfer</b>: Capability to transfer the edition authorization on a given replicated PLM entity from one PLM repository to another. 
*
* <br>This interface can be obtained via @href CATPLMEnginesToolbox#GetPlugServices
* 
* @see CATPLMEnginesToolbox
*/

class ExportedByCATPLMIntegrationInterfaces CATIPLMReplicationEnginePlugServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Creates an initial plug.
  * <br><b>Role:</b>Creates an initial plug for exchanges with a target repository. This is the first step of PLM channel set-up.
  * @param iTargetSiteBusinessCard
  *   the business card of the target repository
  * @param iOptions
  *   optional creation parameters
  * @param oChannelID
  *   if successful, the channel identifier of the created plug.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The initial plug was succesfully created.</dd>
  *   <dt>E_FAIL</dt><dd>The initial plug could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT CreateInitialPlug ( 
    const CATPLMREBusinessCard &iTargetSiteBusinessCard,
    const CATPLMREPlugCreateOptions &iOptions,
    CATString &oChannelID) = 0;

  /**
  * Creates an connected plug.
  * <br><b>Role:</b>Creates a connected plug as an answer to a revision sent by initial plug. This is the second step of PLM channel set-up.
  * <br>An option allows refusing the connected plug creation. This will create a “refused” plug that can be published to notify the initial plug of the refusal.
  * <br>The connected plug can only be created by the repository defined as the target of the revision. 
  * <br>The connected plug creation will fail if a plug for this channel already exists in this repository, or if the channel has been previously refused.
  * 
  * @param iRevisionPath
  *   The path of a revision published by the initial plug (see @href CATIPLMReplicationEnginePlugServices#PublishPlug)
  * @param iOptions
  *   optional creation parameters
  * @param iCreateAsRefused
  *   If TRUE, the plug creation is refused. In such case, data exchange on this channel will be forbidden.
  * @param oChannelID
  *   if successful, the channel identifier of the created plug.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The connected plug was succesfully created.</dd>
  *   <dt>E_FAIL</dt><dd>The connected plug could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT CreateConnectedPlug ( 
    const CATUnicodeString &iRevisionPath,
    const CATPLMREPlugCreateOptions &iOptions,
    CATBoolean iCreateAsRefused,
    CATString &oChannelID) = 0;                   

  /**
  * Removes a plug.
  * <br><b>Role:</b>Removes a plug from the local repository, given a channel identifier. 
  * <br>Note that the corresponding plug in the target repository will not be automatically removed. 
  * <br>A plug can not be removed if there are pending edition token transfers.
  * <br>Once removed, a plug can never be re-created.
  *
  * @param iChannelID
  *   the channelID for which the plug must be removed.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The plug was successfully removed.</dd>
  *   <dt>E_FAIL</dt><dd>The plug could not be removed. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT RemovePlug ( 
    const CATString &iChannelId) = 0;  

  /**
  * Lists all active plugs maintained in the local PLM repository.
  * <br><b>Role:</b>This method searches in the current connected PLM repository for "active" plugs (plugs that were not refused, not destroyed).
  *
  * @param ioChannelIds
  *   list where all channel IDs are appended
  * @param ioPlugNames
  *   list where plug names are appended
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The list of active plugs was succesfully retrieved.</dd>
  *   <dt>E_FAIL</dt><dd>The list of active plugs could not be retrieved. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT ListActivePlugs ( 
    CATLISTV(CATString) &ioChannelIds,      
    CATLISTV(CATUnicodeString) &ioPlugNames) = 0;  

  /**
  * Status of a plug (might be local or remote).
  * <tt> Possible values:</tt>
  * <dl>
  * @param <tt>Unknown</tt><dd>The plug does not exist.
  * @param <tt>Active</tt<dd>The plug is active.
  * @param <tt>Deleted</tt><dd>The plug was removed with @href CATIPLMReplicationEnginePlugServices#RemovePlug
  * @param <tt>Refused</tt><dd>The plug was refused.
  * </dl>
  */
  enum CATPLMPlugLifecycleStatus 
  {
    Unknown=0,           
    Active=1,         
    Deleted=2,         
    Refused=3,         
  }; 

  /**
  * Retrieves the current status of a channel, given its identifier.
  * <br><b>Role:</b>This method returns the lifecycle status of both plugs of a channel.
  * <br>The lifecycle status of the local plug is a persisted information that evolves when the plug is created/removed/refused.
  * <br>The status of the remote plug is a synhronized copy of this information on the local repository. It is updated automatically through publish/synchronize. 
  *
  * @param iChannelID
  *   the identifier of the channel
  * @param oLocalPlugStatus
  *   the status of the local plug
  * @param oRemotePlugStatus
  *   the status of the remote plug
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The status of the channel was succesfully retrieved.</dd>
  *   <dt>E_FAIL</dt><dd>The status of the channel could not be retrieved. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 

  virtual HRESULT GetChannelStatus ( 
    const CATString &iChannelID,
    CATPLMPlugLifecycleStatus &oLocalPlugStatus,
    CATPLMPlugLifecycleStatus &oRemotePlugStatus) = 0;                   

  /**
  * Publishes information from a plug. 
  * <br><b>Role:</b>This service creates a revision file to be sent to the target repository.
  *
  * @param iChannelID
  *   the identifier of the channel
  * @param iRevisionPath
  *   the path where the revision will be generated
  * @param iPublishOptions
  *   optionnal publish parameters
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The revision was succesfully created.</dd>
  *   <dt>E_FAIL</dt><dd>The revision could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT PublishPlug( 
    const CATString &iChannelId,
    const CATUnicodeString &iRevisionPath,
    const CATPLMREPlugPublishOptions &iPublishOptions,
    CATPLMREExchangeForm * iExchangeForm = NULL,
	const int & iRevisionNumber=-1) = 0;                    

  /**
  * Synchronizes a plug with a revision file. 
  * <br><b>Role:</b>.
  *
  * @param iChannelID
  *   the identifier of the channel
  * @param iRevisionPath
  *   the path of the revision 
  * @param iSynchronizeOptions
  *   optionnal parameters of the synchronize operation
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The revision was succesfully created.</dd>
  *   <dt>E_FAIL</dt><dd>The revision could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT SynchronizePlug( 
    const CATString &iChannelId,
    const CATUnicodeString &iRevisionPath,
    const CATPLMREPlugSynchronizeOptions &iSynchronizeOptions,
    CATPLMREExchangeForm  *iExchangeForm = NULL ) = 0;

  /**
	* @deprecated R207 
  * Request the transfer of a set of edition tokens. 
  * <br><b>Role:</b>This service allows to request transferring edition tokens for a set of components to the peer plug.
  * <br>If successful, the corresponding entities are immediately set to read-only. 
  * <br>The transfer will be executed through publish/synchronize operations.
  *
  * @param iChannelID
  *   the identifier of the channel
  * @param iComponents
  *   the set of components whose edition tokens need to be transferred. 
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The request was succesfully processed.</dd>
  *   <dt>E_FAIL</dt><dd>The request could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT RequestEditionTokenTransfer( 
    const CATString &iChannelID,
    const CATLISTV(CATPLMID) &iComponents) = 0;

	/**
	* Request the transfer of a set of edition tokens. 
	* <br><b>Role:</b>This service allows to request transferring edition tokens for a set of components to the peer plug.
	* <br>If successful, the corresponding entities are immediately set to read-only. 
  * <br>The transfer will be executed through publish/synchronize operations.
  *
  * @param iChannelID
  *   the identifier of the channel
  * @param iComponents
  *   the set of components whose edition tokens need to be transferred. 
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The request was succesfully processed.</dd>
  *   <dt>E_FAIL</dt><dd>The request could not be created. An error message is available through @href CATError#CATGetLastError()
  *   </dd>
  * <br>
  */ 
  virtual HRESULT RequestEditionTokenTransfer( 
    const CATString &iChannelID,
    const CATLISTV(CATPLMID) &iComponents,
		CATPLMREPlugTransferOptions& iTransferOptions) = 0;

  /**
  * Reserve a slot of iteration on a plug.
  * @param iChannelID
  *   the identifier of the channel
  * @param iNbIteration
  *   the number of iteration to reserve
  */
  virtual HRESULT ReservePlugRevisionIterations( 
     const CATString             & iChannelID,
	 const int                   & iNbIteration,
	 const int                   & ibTransferOwnership,
	 int                         & oInitialRevisionNumber ) = 0;

};
//------------------------------------------------------------------
CATDeclareHandler( CATIPLMReplicationEnginePlugServices, CATBaseUnknown );



#endif
