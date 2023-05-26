#ifndef CATOmbOutputRelation_H
#define CATOmbOutputRelation_H


// COPYRIGHT DASSAULT SYSTEMES 2005


/**
* @level Protected
* @usage U1
*/

// BSFBuildtimeData
#include "CATIAV5Level.h"
// SystemTS
#include "CATBoolean.h"
#include "IUnknown.h" // for HRESULT
// ObjectModelerBase
#include "CATListOfCATOmbLinkProperties.h"
#include "CATListOfCATOmbOutputRelation.h"
#include "CATListOfCATOmbRelationContext.h"
#include "CATObjectModelerBase.h"
#include "CATOmbCuteUniversalLink.h"
#include "CATOmbRelationInformation.h"
#include "CATOmxList.h"
#include "CATBaseUnknown.h"

class CATOmbRelationContext;
class CATComponentId;
class CATUnicodeString;
class CATIOmbLinkAccessListener;


/**
* Class that enables to access a relation.
**/
class ExportedByCATObjectModelerBase CATOmbOutputRelation
{
public:

  /**
  * Synchronization status of a relation.
  * @param Synchronized
  *   The relation is synchronized (session status)
  * @param Unsynchronized
  *   The relation is not synchronized (session status)
  * @param Undefined
  *   The pointed object is not in session
  * @param Neutral
  *   Synchronization status unrelevant for the relation
  */
  enum RelationSynchroStatus
  {
    Synchronized,
    Unsynchronized,
    Undefined,
    Neutral
  };

  /**
  * orientation a relation.
  * @param O_IN
  *  The relation is in.
  *  <br>The synchronization status depends of the pointed component.
  * @param O_OUT
  *  The relation is out.
  *  <br>The synchronization status depends of the pointing component.
  * @param O_NEUTRAL
  *  The relation is neutral.
  *  The relation has no synchronization status.
  */
  enum Orientation
  {
    O_IN,
    O_OUT,
    O_NEUTRAL,
    O_INOUT
  };

  /**
  * Retrieves the pointing component of the relation.
  * @param oPointingComponent
  *   The pointing component of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetPointingComponentId(CATComponentId& oPointingComponent) const = 0;

  /**
  * Retrieves the name of the pointing component.
  * @param oName
  *  The name of the pointing component.
  * @return
  *  S_OK.
  */
  virtual HRESULT GetPointingComponentName(CATUnicodeString& oName) const = 0;

  /**
  * Retrieves the pointed component of the relation.
  * @param oPointedComponent
  *   The pointed component of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetPointedComponentId(CATComponentId& oPointedComponent) const = 0;

  /**
  * Retrieves the name of the pointed component.
  * @param oName
  *  The name of the pointed component.
  * @return
  *  S_OK.
  */
  virtual HRESULT GetPointedComponentName(CATUnicodeString& oName) const = 0;

#ifdef CATIAR418
  /**
  * Retrieves the type of the relation.
  * @param oType
  *   The type of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetType(CATUnicodeString &oType) const = 0;
#endif

  /**
   * Retrieves the role of the relation.
   * @param oRole
   *   The role of the relation.
   * @param iNLSFormat
   *   To retrieve the role in NLS format.
   * @return
   *   S_OK.
   */
  virtual HRESULT GetRole(CATUnicodeString &oRole, CATBoolean iNLSFormat = FALSE) const = 0;

  /**
   * Retrieves the category of the relation.
   * @param oRole
   *   The category of the relation.
   * @return
   *   S_OK.
   */
  virtual HRESULT GetCategory(CATUnicodeString &oCategory) const = 0;

  /**
  * Retrieves the orientation of the relation.
  * @param oOrientation
  *  The orienation of the relation.
  * <br><b>Note:</b>The orientation is computed from the meta data of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetOrientation(CATOmbOutputRelation::Orientation& oOrientation) const = 0;

  /**
  * Retrieves all links owned by the relation.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @param ioList
  *  The list of links.
  *  <br><b>Note:</b> The returned objets will be removed during the deletion of the current objet.
  * @return
  *  S_OK.
  */
  virtual HRESULT GetLinks(CATLISTP(CATOmbLinkProperties)& ioList) = 0;

  /**
  * Retrieves the context of the current relation.
  * @param oContext
  *  The context.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>S_FALSE</dt>
  *    <dd>The relation does not have a context.</dd>
  *   <dt>S_OK</dt>
  *    <dd>The relation has a context.</dd>
  *  </dl>
  */
  virtual HRESULT GetContext(CATOmbRelationContext* & oContext) const = 0;

  /**
  * Tests if the relation is synchronizable.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @return
  *  <dl>
  *   <dt>TRUE</dt>
  *    <dd>The relation is synchronizable.</dd>
  *   <dt>FALSE</dt>
  *    <dd>The relation is not synchronizable.</dd>
  *  </dl>
  */
  virtual CATBoolean IsSynchronisable() = 0;

  /**
  * Tests if the relation is synchronizable through the user interface.
  * <br><b>Note:</b>It is more restrictive than IsSynchronisable(),
  * because it forbides synchronization on some certain type of components.
  * @return
  *  <dl>
  *   <dt>TRUE</dt>
  *    <dd>The relation is synchronizable by UI.</dd>
  *   <dt>FALSE</dt>
  *    <dd>The relation is not synchronizable by UI.</dd>
  *  </dl>
  */
  virtual CATBoolean IsSynchronizableByUI() = 0;

  /**
  * Returns the number of owning links that are not synchronized.
  * @return
  *  The number of links that are not synchronized, or -1 if all links have not been computed.
  */
  virtual int GetNumberOfNotSynchronizedLinks() = 0;

  /**
  * Synchronizes the relation.
  * <br><b>Note:</b>It may trigger a load event to load the pointing component.
  * @param iSynchronizeAllLinks
  *  Synchronizes the related links if necessary.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The relation was synchronized successfully .</dd>
  *   <dt>S_FALSE</dt>
  *    <dd>The relation is already synchronized or the pointed object is not in session.</dd>
  *   <dt>E_FAIL</dt>
  *		<dd>The relation is not synchronizable or it failed to be synchronized.</dd>
    *   <dt>E_INVALIDARG </dt>
  *    <dd>If synchronizing a synchro disabled relation.</dd>
  *	</dl>
  */
  virtual HRESULT Synchronize(CATBoolean iSynchronizeAllLinks = FALSE) = 0;

  /**
  * Synchronizes a list of relations.
  * <br><b>Note:</b>It may trigger a load event to load the pointing components.
  * @param iRelations
  *  The list of relations to synchronize.
  * @param iSynchronizeAllLinks
  *  Synchronizes the related links if necessary.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>E_FAIL</dt>
  *    <dd>At least one relation or one link failed to synchronize.</dd>
  *   <dt>E_INVALIDARG </dt>
  *    <dd>At least one relation has a synchro disabled status.</dd>
  *   <dt>S_OK</dt>
  *    <dd>All relations were synchronized successfully.</dd>
  *  </dl>
  */
  static HRESULT Synchronize(const CATLISTP(CATOmbOutputRelation)& iRelations, CATBoolean iSynchronizeAllLinks = FALSE);

  /**
  * Returns the binding status of the relation.
  * @param oStatus
  *  The status of the relation.
  * @param iMergeWithContextStatus
  *  If the current relation has a context, returns a global status computed from the current relation and its context.
  * @param oAdditionalRelationStatus
  *   Additional relation status.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The status was computed successfully.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The status of the relation can't be computed.</dd>
  *   <dt>E_INVALIDARG </dt>
  *    <dd>If synchronizing a synchro disabled relation.</dd>
  *  </dl>
  */
  virtual HRESULT GetRelationStatus(CATOmbRelationStatus & oStatus, CATBoolean iMergeWithContextStatus = TRUE, CATOmbAdditionalRelationStatus * oAdditionalRelationStatus = NULL) const = 0;

  /**
  * Returns the complete status of the relation
  * This status is based on session and remote persistency status.
  * @param oStatus
  *   The binding status.
  * @param oSynchroStatus
  *   The synchronization status.
  * @param iMergeWithContextStatus
  *  If the current relation has a context, returns a global status computed from the current relation and its context.
  * @param oAdditionalRelationStatus
  *   Additional relation status.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The status were computed successfully</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The status can't be computed.</dd>
  *  </dl>
  */
  virtual HRESULT GetRelationSynchroStatus(
    CATOmbRelationStatus & oStatus,
    CATOmbRelationSynchroStatus & oSynchroStatus,
    CATBoolean iMergeWithContextStatus = TRUE, CATOmbAdditionalRelationStatus * oAdditionalRelationStatus = NULL) const = 0;

  /**
  * Returns the remote status of the relation
  *
  * The remote status is evaluated only at import time (Open, Refresh, ...).
  * This information is never updated by PLM Session.
  *
  * @param oRemoteStatus
  *   The remote status.
  * @param iMergeWithContextStatus
  *  If the current relation has a context, returns a global status computed from the current relation and its context.
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The status were computed successfully</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>The status can't be computed.</dd>
  *  </dl>
  */
  virtual HRESULT GetRelationRemoteStatus(CATOmbRelationRemoteStatus & oRemoteStatus, CATBoolean iMergeWithContextStatus = TRUE) const = 0;

  /**
  * Isolates a list of relations.
  * <br><b>Note:</b>It may trigger a load event to load the pointing components.
  * @param iRelations
  *  The list of relations to isolate.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>E_ACCESSDENIED</dt>
  *    <dd>At least one relation is not valid anymore. Nothing in done.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>At least one relation failed to be isolated.</dd>
  *   <dt>S_OK</dt>
  *    <dd>All relations were isolated successfully.</dd>
  *  </dl>
  * @see CATOmbOutputRelation
  */
  static HRESULT Break(const CATLISTP(CATOmbOutputRelation)& iRelations);

  /**
  * Loads the pointing and pointed components of a list of relations.
  * <br><b>Note:</b>If the pointed component of a relation is a rep,
  * then the containers that are referenced by the links of the relation will be loaded.
  * If the pointing component of a relation is a rep, then it will be loaded with the minimal mode to access links.
  * @param iRelations
  *  The list of relations.
  * @param ipiListener
  *  A listener on load events.
  * @param iLoadTargetOfPub
  *  If TRUE, and if a publication is the pointed component of a relation, then the target of the pub will be loaded.
  * @return
  *  An HRESULT value:
  *  <dl>
  *   <dt>E_FAIL</dt>
  *    <dd>A component failed to be loaded.</dd>
  *   <dt>S_OK</dt>
  *    <dd>All components were loaded succesfully.</dd>
  *  </dl>
  */
  static HRESULT LoadPointingAndPointedComponents(
    const CATLISTP(CATOmbOutputRelation)& iRelations,
    CATIOmbLinkAccessListener* ipiListener,
    CATBoolean iLoadTargetOfPub = TRUE);

  /**
  * Equality operator.
  * <br><b>Role:</b>Used to compare with a relation from another descriptor.
  * @param iRelation
  *  The relation to compare with the current one.
  * @return
  *  <dl>
  *   <dt>0</dt>
  *    <dd>The relations are different.</dd>
  *   <dt>1</dt>
  *    <dd>The relations are identical.</dd>
  *  </dl>
  */
  virtual int operator==(const CATOmbOutputRelation& iRelation) const = 0;

  /**
  * Unequality operator.
  * @param iRelation
  *  The relation to compare with the current one.
  *  <br><b>Role:</b>Used to compare with a relation from another descriptor.
  * @return
  *  <dl>
  *   <dt>0</dt>
  *    <dd>The relations are identical.</dd>
  *   <dt>1</dt>
  *    <dd>The relations are different.</dd>
  *  </dl>
  */
  virtual int operator!=(const CATOmbOutputRelation& iRelation) const = 0;

  /** @deprecated */
  virtual HRESULT GetSynchronizationStatus(RelationSynchroStatus& oStatus) const = 0;

  /**
   * If the relation belong to a bundle, retrieve the bundle name.
   * @param oBundleName
   *  The Name of the associated bundle.
   * @return
   *  <dl>
   *   <dt>S_OK</dt>
   *    <dd>The Relation belongs to a bundle and oBundleName is correctly valuated.</dd>
   *    <dt>S_FALSE</dt>
   *     <dd>The relation is not in a bundle.</dd>
   *    <dt>E_FAIL</dt>
   *     <dd>Error while retrieving the bundle name.</dd>
   *    <dt>E_NOTIMPL</dt>
   *     <dd>GetBundleName () not yet available.</dd>
   *   </dl>
   */
  virtual HRESULT GetBundleName(CATUnicodeString & oBundleName) const = 0;

  /**
   * If the relation belong to a bundle, retrieve the unique and strictly positive identifier of the bundle in the context of the pointing component.
   * @param oBundleId
   *  The identifier of the associated bundle, unique in the context of the pointing component.
   * @return
   *  <dl>
   *   <dt>S_OK</dt>
   *    <dd>The Relation belongs to a bundle and oBundleId is not null.</dd>
   *    <dt>S_FALSE</dt>
   *     <dd>The relation is not in a bundle (oBundleId is null).</dd>
   *    <dt>E_FAIL</dt>
   *     <dd>Error while retrieving the bundle identifier.</dd>
   *    <dt>E_NOTIMPL</dt>
   *     <dd>GetBundleId () not yet available.</dd>
   *   </dl>
   */
  virtual HRESULT GetBundleId(int & oBundleId) const = 0;

  /**
   * Check if all links owned by the relation are solved on valid (synchronized
   * with the pointed object) proxies. If yes, the unloading of pointed private
   * streams will be possible by keeping links binding or relation synchronize abilities.
   * @return
   *  <dl>
   *   <dt>S_OK</dt>
   *    <dd>All links are solved on valid proxies.</dd>
   *    <dt>S_FALSE</dt>
   *     <dd>A least one link is not solved on a valid proxy.</dd>
   *    <dt>E_FAIL</dt>
   *     <dd>The relation is not opened or broken.</dd>
   *    <dt>E_ACCESSDENIED</dt>
   *     <dd>A least one link is not visible (pointing component loading).</dd>
   *    <dt>Otherwise, associated error code.</dt>
   *   </dl>
   */
  virtual HRESULT AreAllLinksSolvedOnValidProxies() = 0;

  /**
   * Check if there is at least one link owned by the relation which is in a
   *  "Not loaded" state.
   * @return
   *  <dl>
   *   <dt>S_OK</dt>
   *    <dd>At least one link is in a "Not loaded" state.</dd>
   *    <dt>S_FALSE</dt>
   *     <dd>All links are solved or broken.</dd>
   *    <dt>E_FAIL</dt>
   *     <dd>The relation is not opened or broken.</dd>
   *    <dt>E_ACCESSDENIED</dt>
   *     <dd>A least one link is not visible (pointing component loading).</dd>
   *    <dt>Otherwise, associated error code.</dt>
   *   </dl>
   */
  virtual HRESULT NeedToLoad() = 0;

  /**
  * Tests if the build spec of the relation is synchronizable.
  * @return
  *  <dl>
  *   <dt>TRUE</dt>
  *    <dd>The relation is minor unsensitive and dynamically solved in session.</dd>
  *   <dt>FALSE</dt>
  *    <dd>The relation is minor sensitive.</dd>
  *    <dd>The relation is minor unsensitive and unsolved or statically solved.</dd>
  *  </dl>
  */
  virtual CATBoolean IsBuildSpecSynchronizable() const = 0;

  /**
  * Synchronizes the build spec of the relation with the dynamic target.
  * Is not depending of selective loading mode, can be launched if component loaded in PLM mode.
  *
  * @return
  *  <dl>
  *   <dt>S_OK</dt>
  *    <dd>The build spec is synchronized.</dd>
  *   <dt>S_FALSE</dt>
  *    <dd>The build spec cannot be synchronized because relation is minor sensitive.</dd>
  *    <dd>The build spec cannot be synchronized because relation is not solved.</dd>
  *    <dd>The build spec cannot be synchronized because relation is still synchronized.</dd>
  *   <dt>E_FAIL</dt>
  *    <dd>unexpected failure.</dd>
  *  </dl>
  */
  virtual HRESULT SynchronizeBuildSpec() = 0;


  /**
  * Set the disabling synchro capabilitie
  * @param iSynchroEnabled
  *    <code>TRUE</code> to enable the synchronization
  *    <code>FALSE</code> to disable the synchronization
  * @return
  *   <code>S_OK</code> if the the disable synchro capabilitie is allowed,
  *   <code>E_FAIL</code> otherwise.
  */
  virtual HRESULT SetSynchroActivationStatus(CATBoolean& iSynchroEnabled) = 0;

  /**
  * Get the information if relation infrastructure will allow the disable synchro and
  * enable synchro capabilities for the relation.
  * @return
  *   <code>TRUE</code> if the the disable synchro capabilitie is allowed,
  *   <code>FALSE</code> otherwise.
  */
  virtual CATBoolean IsSynchroDisablingAllowed() = 0;

  /**
  * Get the information if the relation synchronization is allowed.
  * @return
  *   <code>TRUE</code> if the relation synchronization is allowed,
  *   <code>FALSE</code> otherwise.
  */
  virtual CATBoolean IsSynchroEnabled() = 0;

  /**
   * Retrieves the attributes that were used to create the link
   * @param oAttributeList [out]
   *   the attributes used for the synchro status of the link
   * @return
   *   S_OK: If the attributes are retrieved correctly.
   *   S_FALSE : If the synchro status of the link is not based on attributes (oAttributeList is returned empty)
   *   E_FAIL: Otherwise.
   */
  virtual HRESULT GetAttributesUsedForSynchro(CATOmxArray<CATOmbCuteUniversalLink_Attribute> & oAttributeList) = 0;

#ifndef CATIAR418
  /**
  * Retrieves the type of the relation.
  * @param oType
  *   The type of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetType(CATUnicodeString &oType) const = 0;
#endif

  /**
   * Returns the nls role of the relation.
   * @return
   *	The nls role.
   */
  virtual const CATUnicodeString& GetNLSRole() const = 0;

  /**
  * Retrieves the role and the category of the relation.
  * @param oRole
  *   The role of the relation.
  * @param oCategory
  *   The category of the relation.
  * @return
  *   S_OK.
  */
  virtual HRESULT GetRoleAndCategory(CATUnicodeString & oRole, CATUnicodeString & oCategory) const = 0;

  /**
   * Retrieves the target of the relation (as with GetPointedComponentId).
   * It will return an empty list if any of the elements of the target path is destroyed/not loaded.
   */
  virtual CATOmxList<CATBaseUnknown> GetTargetPath() const = 0;
};
#endif

