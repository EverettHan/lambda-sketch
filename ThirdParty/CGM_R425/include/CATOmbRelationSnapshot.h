#ifndef CATOmbRelationSnapshot_H
#define CATOmbRelationSnapshot_H

// COPYRIGHT Dassault Systemes 2007

/**
* @level Protected
* @usage U1
*/

// BSFBuildtimeData
#include "CATIAV5Level.h"
// SystemTS
#include "CATBoolean.h"
// ObjectModelerCollection
#include "CATOmxOSet.h"
#include "CATOmxSet.h"
#include "CATOmxSR.h"
// CATPLMIdentificationAccess
#include "CATListPtrCATIAdpPLMIdentificator.h"
#include "CATListPtrCATIPLMComponent.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"
#include "CATOmbRelationInformation.h"

class CATUnicodeString;
class CATOmbRelationContextSnapshot;
class CATIPLMComponent;
class CATSemanticRelationMetaData;


/**
* Snapshot of a relation state.
* <br><b>Role</b>: Allow read-only browse of the relational model.
* <p> This interface is accessible with relational browse services provided by
* @href CATOmbRelationalBrowseServices.
* Object life cycle using AddRef () / Release () mechanism (especially, each retrived
* pointer with associated services, from or not a @href CATOmbRelationSnapshotIterator,
* should be release).
* <p> <b>The provided view is representing the model only when the snapshot is done.</b>
* This is an object not impacted by the future changes of the model.
* @see CATOmbRelationalBrowseServices, CATOmbRelationSnapshotIterator, CATOmbRelationContextSnapshot
*/
#if defined(CATIAR425)
#include "CATOmxSharable.h"
class ExportedByCATObjectModelerBase CATOmbRelationSnapshot : public CATOmxSharable
#else
#include "CATOmbUnknown.h"
class ExportedByCATObjectModelerBase CATOmbRelationSnapshot : public CATOmbUnknown
#endif
{
public:
  /**
  * Get the pointing component.
  * @param opiPointingComponent [out, CATBaseUnknown#Release]
  *   The PLM pointing component retrived as a pointer (AddRef is done).
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetPointingComponent(CATIPLMComponent *& opiPointingComponent) const = 0;

  /**
  * Get in session pointed components.
  * <br><b>Role</b>: The pointed entity is heard as a list of components, according to
  * the specific case when the relation is pointing a path of instances.
  * For a single pointed component, the list is reduced to a single element.
  * @param opiPointingComponent [out]
  *   The list of PLM pointed components retrived as a list of pointers (AddRef is done on each
  *   element). WARNING : only loaded components are listed.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>S_FALSE</code> if everything ran ok, but some pointed components are not loaded in session.
  *      Retrived list gives components in session (it could be a empty list).
  */
  virtual HRESULT GetPointedComponent(CATLISTP(CATIPLMComponent) & oPointedComponent) const = 0;

  /**
   * Get the Adp PLM Identificators of the pointed components.
   * @param opiADpPLMIdentificator [out]
   *   The list of pointed Adp PLM Identificators retrived as a list of pointers (AddRef is done on each
   *   element).
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>E_FAIL</code> if failed.
   */
  virtual HRESULT GetPointedAdpPLMId(CATLISTP(CATIAdpPLMIdentificator) & opiADpPLMIdentificator) const = 0;

  /** @see CATOmbRelationSnapshot#GetPointedAlias */
  enum AliasType { TargetAliasOnly = 0, FullAlias = 1 };

  /**
   * Get the alias of the pointed components.
   * @param oAlias [out]
   *   The returned alias.
   * @param iAliasType [in]
   *   Determine the returned alias :
   *   TargetAliasOnly : Just the target alias (last element of a Virtual Object, if applicable).
   *   FullAlias : The concatenation of each pointed elements alias, separated by slash characters
   *      (equivalent to the target alias if the pointed object is not a Virtual Object).
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>S_FALSE</code> if everything ran ok, but some pointed components are not loaded in session, and the
   *      corresponding alias are retrived from the cache of the last known alias.
   *   <code>E_FAIL</code> if failed.
   */
  virtual HRESULT GetPointedAlias(CATUnicodeString & oAlias, const AliasType & iAliasType = TargetAliasOnly) const = 0;

  /**
  * Get the relation context.
  * <br><b>Role</b>: Contextual relations could be broken down into two relations : Input and Context.
  * This method allow to retrive a specific snapshot of the relation context.
  * @param oContext [out, IUnknown#Release]
  *   The relation context as a pointer on @href CATOmbRelationContextSnapshot.
  *   SHOULD BE RELEASE BY USER.
  *   If relation is not a contextual relation, return <code>NULL</code>.
  * @return
  *   <code>S_OK</code> if the relation is a contextual relation and everything ran ok.
  *   <code>S_FALSE</code> if the relation is not a contextual relation.
  *   <code>E_FAIL</code> if failed.
  */
  virtual HRESULT GetContext(CATOmbRelationContextSnapshot *& oContext) const = 0;

  /**
  * Get the Role MetaData attribute value.
  * @param oRole [out]
  *   The retrived Role string value.
  * @param iNLSFormat [in]
  *   Is the value must be return in National Language Support format ?
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetRole(CATUnicodeString & oRole, CATBoolean iNLSFormat = FALSE) const = 0;

  /**
  * Get the Category MetaData attribute value.
  * @param oCategory [out]
  *   The retrived Category string value.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetCategory(CATUnicodeString & oCategory) const = 0;

  /**
   * Get the PathType MetaData attribute value.
   * @param oPathType [out]
   *   The retrived PathType string value.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
   */
  virtual HRESULT GetType(CATUnicodeString & oPathType) const = 0;

  /**
  * Get the Orientation attribute value.
  * @param oOrientation [out]
  *   Enumerate value about orientation, see CATOmbRelationInformation.h.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetOrientation(CATOmbRelationOrientation & oOrientation) const = 0;

  /**
  * Get information on resolution and synchronization about the relation.
  * <br><b>Role</b>: In the case of a contextual relation, the relation context information
  * are also available. According to a CATBoolean parameter, the user could ask for
  * seing retrived relation status recomputed with relation context status.
  * @param oStatus [out]
  *   Enumerate value about resolution status, see CATOmbRelationInformation.h.
  * @param oSynchroStatus [out]
  *   Enumerate value about synchronization status, see CATOmbRelationInformation.h.
  * @param iMergeWithContextStatus [in]
  *   Merge status with an eventual relation context ?
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetRelationStatus(CATOmbRelationStatus & oStatus, CATOmbRelationSynchroStatus & oSynchroStatus, CATBoolean iMergeWithContextStatus = TRUE) const = 0;

  /**
  * Is relation was flagued as inconsistent by server (Designer WS creation) ?
  */
  virtual CATBoolean IsInconsistentOccurrence() = 0;

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
   * Gets the pointing objects (in session) of the relation. I.e. all the sources of the
   *   links that share this relation. Object  PC2 Safe.
   *   This API only works for loaded objects.
 * @param ioPointingObjects
 *	The set of pointing objects.
 *	<br>The objects are inserted to the set given as argument.
   * @return
   *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
   */
  virtual HRESULT GetPointingObjects(CATOmxSet <CATBaseUnknown> & ioPointingObjects) = 0;

  /**
  * Get the NLS Role MetaData attribute value.
  * @return
  *   The retrived the NLS Role string value.
  */
  virtual const CATUnicodeString & GetNLSRole() const = 0;

  /**
  * Get the Role and the Category MetaData attribute value.
  * @param oRole [out]
  *   The retrived Role string value.
  * @param oCategory [out]
  *   The retrived Category string value.
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise associated failure code.
  */
  virtual HRESULT GetRoleAndCategory(CATUnicodeString & oRole, CATUnicodeString & oCategory) const = 0;

  virtual const CATSemanticRelationMetaData & GetSemanticRelationMetaData() const = 0;
};

#endif
