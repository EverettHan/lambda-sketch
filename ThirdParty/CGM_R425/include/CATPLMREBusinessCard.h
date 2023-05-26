// COPYRIGHT Dassault Systemes 2008
//===================================================================
//
// CATPLMREBusinessCard.h
// Business card object used by the Replication Engine
//
//===================================================================
//
//
//===================================================================
//
//  Jan 2008  Creation: LED
//===================================================================

#ifndef _CATPLMREBusinessCard_H
#define _CATPLMREBusinessCard_H

/**
* @level Protected
* @usage U1
*/

#include "CATPLMIntegrationInterfaces.h"
#include "CATUnicodeString.h"
#include "CATPLMPhysicalRepositoryID.h"

/**
* Repository business-card object.
* <br><b>Role</b>: a business-card is an object that describes the identification of a PLM repository.
* Each PLM repository is identified by a universally unique identifier. The business-card includes this identifier, plus additional information.
* Business-cards can be serialized to a file and exchanged between PLM repositories to set-up data exchanges.
* <br> The business-card for a repository can be obtained through @href CATIPLMReplicationEngine#GetConnectedRepoBusinessCard
* <br> A business-card can be serialized to a file through @href CATIPLMBriefcaseServices#WriteBusinessCardToFile
* <br> A business-card can be deserialized from a file through @href CATIPLMBriefcaseServices#ReadBusinessCardFromFile
*/
class ExportedByCATPLMIntegrationInterfaces CATPLMREBusinessCard
{

public:
  CATPLMREBusinessCard();
  virtual ~CATPLMREBusinessCard();

  /**
  * Returns the display name of the PLM repository.
  * <br><b>Role:</b>This method returns a human-readable name corresponding to the repository described by this business card.
  * By default, the repository name is the name allocated to this repository at install.
  * @param oDisplayName
  *   The display name of the repository. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The display name was returned.</dd>
  *   <dt>E_FAIL</dt><dd>The business-card is not valuated</dd>
  * <br>
  */ 
  HRESULT GetDisplayName( CATUnicodeString &oDisplayName);

  /**
  * Returns the universally unique identifier of the repository.
  * <br><b>Role:</b>This method returns the identifier automatically allocated to this repository at install.
  * @param oRepoID
  *   The repository identifier. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>S_OK</dt><dd>The repository identifier was returned.</dd>
  *   <dt>E_FAIL</dt><dd>The business-card is not valuated</dd>
  * <br>
  */ 
  HRESULT GetRepositoryID( CATPLMPhysicalRepositoryID &oRepoID );

  /**
  * Checks if the business-card is valuated.
  *
  * @return 
  * <br><b>Legal values</b>
  *   <dt>TRUE</dt><dd>The business-card has never been valuated.</dd>
  *   <dt>FALSE</dt><dd>The business-card has been valuated.</dd>
  * <br>
  */ 
  CATBoolean IsNull() const;

  /**
  * Compares two business-cards.
  * <br><b>Role:</b>This method allows to check if two business-cards describe the same physical repository.
  * <br>Note: the display-name is ignored.
  * @param iCopy
  *   The business-card to be compared with. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>TRUE</dt><dd>The business-cards describe the same physical repository.</dd>
  *   <dt>FALSE</dt><dd>The business-cards describe different physical repository.</dd>
  * <br>
  * </dl>
  */
  virtual int operator==(const CATPLMREBusinessCard & iCopy) const;
  
  /**
  * Compares two business-cards.
  * <br><b>Role:</b>This method allows to check if two business-cards describe the same physical repository.
  * <br>Note: the display-name is ignored.
  * @param iCopy
  *   The business-card to be compared with. 
  * @return 
  * <br><b>Legal values</b>
  *   <dt>FALSE</dt><dd>The business-cards describe the same physical repository.</dd>
  *   <dt>TRUE</dt><dd>The business-cards describe different physical repository.</dd>
  * <br>

  */
  virtual int operator!=(const CATPLMREBusinessCard & iCopy) const;

private:

  // Valuation of business card is restricted to replication-engine component.
  friend class CATPLMREBriefcaseFileHeader;
  friend class CATPLMREBusinessCardSerializer;
  friend class CATPLMREReplicationEngineImpl;
  friend class CATPLMRECommonServices;
  friend class RETestUtils;

  CATPLMPhysicalRepositoryID _repoID;
  CATUnicodeString           _repoName;

 
};

#endif
