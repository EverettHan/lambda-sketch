// COPYRIGHT Dassault Systemes 2007


#ifndef CATOmbRelationalBrowseServices_H
#define CATOmbRelationalBrowseServices_H

/**
* @level Protected
* @usage U1
*/
#ifndef NULL
#define NULL 0
#endif

#include "CATOmbLinkNavigationAccess.h"
#include "IUnknown.h"
#include "CATBoolean.h"


class CATOmbRelationSnapshotIterator;
class CATOmbRelationSnapshotSpecificationIterator;
class CATIPLMComponent;
class CATOmbRelationSnapshot;
class CATOmbRelationSnapshotSpecification;
class CATOmbRelationsFilter;
class CATISpecAttrAccess_var;
class CATISpecAttrKey_var;
class CATUnicodeString;


/**
* Static class providing services to navigate over the relational model.
* <br><b>Role</b>: Provide in-session relation snapshots.
* Return iterators to browse efficiently set of relation snapshots.
* <p> The retrived views are representing the model only when they are created.
* <b>They will not be impacted by future changes of the model.</b>
* @see CATOmbRelationSnapshotIterator, CATOmbRelationSnapshot, CATOmbRelationsFilter
*/
class ExportedByCATOmbLinkNavigationAccess CATOmbRelationalBrowseServices
{
public:

    /**
    * Get an iterator on snapshots of relations from a given PLM component.
    * <br><b>Role</b>: Get an iterator on all in-session direct relations.
    * @param ipiComponent [in]
    *   A PLM pointing component to browse relations.
    * @param ipRelationsFilter [in]
    *   A filter on relation snapshots.
    * @return delete
    *   A iterator on relation snapshot.
    *   If no relation to browse, void iterator is return (NOT a null pointer)
    */
  static CATOmbRelationSnapshotIterator * GetRelationsSnapshot(CATIPLMComponent & ipiComponent, CATOmbRelationsFilter * ipRelationsFilter = NULL);

  /**
  * Get an iterator on snapshots of relations pointing a given PLM component.
  * <br><b>Role</b>: Get an iterator on all in-session indirect relations (Inverse relations).
  * @param ipiComponent [in]
  *   A PLM pointed component to browse relations.
  * @param ipRelationsFilter [in]
  *   A filter on relation snapshots.
  * @return delete
  *   A iterator on inverse relation snapshots.
  *   If no relation to browse, void iterator is return (NOT a null pointer)
  */
  static CATOmbRelationSnapshotIterator * GetInverseRelationsSnapshot(CATIPLMComponent & ipiComponent, CATOmbRelationsFilter * ipRelationsFilter = NULL);

  /**
  * Get an iterator on snapshots of relations from a given PLM component and a given SubRelationship name.
  * <br><b>Role</b>: Get an iterator on all in-session direct relations sharing the same SubRelationship name.
  * @param ipiComponent [in]
  *   A PLM pointing component to browse relations.
  * @param iRelationName [in]
  *   The SubRelationship name.
  * @return delete
  *   A iterator on relation snapshot.
  *   If no relation to browse, void iterator is return (NOT a null pointer)
  *   If any error (including invalid SubRelationship name), return NULL pointer
  */
  static CATOmbRelationSnapshotIterator * GetRelationsSnapshot(CATIPLMComponent & iComponent, const CATUnicodeString & iRelationName);

  /**
  * @deprecated V6R2011 GetRelationsSnaphot
  *
  * ===========================================================================================================================
  * Deprecated method :
  * OMBLink do not support anymore ordered relational browse by RelationName (_index_ parameter).
  * Please use CATOmbRelationSnapshotIterator * GetRelationsSnapshot (CATIPLMComponent &, const CATUnicodeString &).
  * Important, DO NOT WORK with :
  *   *   "Bolino Light Read-Only" loading mode enhancement for V6R2011.
  *   *   Structured Connection models.
  * ===========================================================================================================================
  *
  * Get a snapshot of the relation corresponding to a given SubRelationship.
  * <br><b>Role</b>: From a SubRelationship name, return the associated relation snapshot.
  * @param iComponent [in]
  *   The pointing component.
  * @param iRelationName [in]
  *   The name of the SubRelationship.
  * @param iModelerKey [in]
  *   The Modeler Key, to be allowed to access the relation snapshot.
  * @param opRelationSnapshot [out, IUnknown#Release]
  *   The retrived relation snapshot.
  * @param iIndex [in]
  *    Use for multi-set SubRelationship. If 0, set at the end.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_ACCESSDENIED</code> if modeler key is invalid
  *   <code>E_FAIL</code> if no relation is corresponding to the given name and the given index.
  *   <code>E_NOINTERFACE</code> if current packaging do not include CATPLMClientCore or SpecModeler.
  *   Otherwise, associated failure code.
  */
  static HRESULT GetRelationSnapshot(CATIPLMComponent & iComponent, const CATUnicodeString & iRelationName, const CATUnicodeString & iModelerKey, CATOmbRelationSnapshot * & opRelationSnapshot, int iIndex = 0);

  /**
  * Get a snapshot of the relation set on a given feature attribute.
  * <br><b>Role</b>: From a feature attribute which must be a tk_external or tk_list of tk_external,
  * return the relation corresponding to the link set on this attribute.
  * @param ispAttrAccess [in]
  *   The pointing feature.
  * @param ispAttrKey [in]
  *   The key of the tk_external or tk_list of tk_external attribute owned by the feature.
  * @param opRelationSnapshot [out, IUnknown#Release]
  *   The retrived relation snapshot.
  * @param iIndex [in]
  *    Use for tk_list. If 0, set at the end.
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *   <code>E_INVALIDARG</code> if ispAttrAccess or ispAttrAccess are not valuated.
  *   <code>E_NOTIMPL</code> if asking for retriving the context of a contextual relation.
  *   <code>E_ACCESSDENIED</code> if link valuated on attribute do not have a PLM relational view.
  *   <code>E_FAIL</code> if no link is valuated on the given attribute.
  *   <code>E_NOINTERFACE</code> if current packaging do not include SpecModeler.
  *   Otherwise, associated failure code.
  */
  static HRESULT GetRelationSnapshot(CATISpecAttrAccess_var & ispAttrAccess, CATISpecAttrKey_var & ispAttrKey, CATOmbRelationSnapshot * & opRelationSnapshot, int iIndex = 0);

 /**
  * Get an iterator on specifiable relation snapshots from a given PLM component.
  * <br><b>Role</b>: Get an iterator over all in-session direct relations, with the ability to specificate targets for check processing.
  * @param ipiComponent [in]
  *   A PLM pointing component to browse relations.
  * @param ipRelationsFilter [in]
  *   A filter on relation.
  * @return delete
  *   A iterator on specifiable relation snapshots.
  *   If no relation to browse, void iterator is return (NOT a null pointer)
  */

  static CATOmbRelationSnapshotSpecificationIterator * GetRelationSnapshotSpecifications(CATIPLMComponent & ipiComponent, CATOmbRelationsFilter * ipRelationsFilter = NULL);

  static CATOmbRelationSnapshotIterator * CreateSnapshotIterator(CATOmbRelationSnapshot & iRelationSnapshot);
};


#endif
