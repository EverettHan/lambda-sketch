/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2011
/**
 * @level Protected
 * @usage U1
 */
#ifndef CATPLMTypeProtectedBehaviors_H
#define CATPLMTypeProtectedBehaviors_H

#include "CATPLMIdentificationAccess.h"
#include "CATPLMTypeDescriptor.h"
#include "CATOmxArray.h"
#include "CATPLMStrongRelationshipId.h"

class CATString;
class CATPLMTypeRelationIter;
class CATPLMTypeRelation;
class CATOmxKeyString;
class CATUnicodeString;

// FILTER DEFINITIONS
static const int TYPREL_Aggregation = 0x01;  // 00000001
static const int TYPREL_Instanciation = 0x02;  // 00000010
static const int TYPREL_Pointer = 0x04;  // 00000100
static const int TYPREL_SessionIntegrity = TYPREL_Aggregation | TYPREL_Instanciation;

/**
 * Class enabling to determine semantical description of a PLM type.
 *
 * <br><b>Role</b>: Given a PLM type, this class enables to determine the physical aspect of the PLM type.
 * <ul>
 * <li>Available entry points:</li>
 * <li>public:CanBeAggregated</li>
 * <li>public:CanAggregate</li>
 * <li>public:SupportMonoInstanciation</li>
 * <li>public:SupportVersioning</li>
 * <li>public:SupportExpand</li>
 * <li>public:SupportDeletionFromAuthoringSession</li>
 * <li>public:SupportShortTransactionDeletion</li>
 * <li>public:SupportShortTransactionDeletionIfAvailableInAuthoringSession</li>
 * <li>public:GetGenericAttributeForSelectConditionInOpenQuery</li>
 * <li>public:SupportIdentificationSet</li>
 * <code>
 * CATPLMID myComponent;
 * CATPLMTypeProtectedBehaviors Behavior(myComponent);
 * HRESULT rc_aggregation=Behavior.CanBeAggregated();
 * if ( SUCCEEDED(rc_aggregation) )
 * {
 *   if ( rc_aggregation==S_OK )
 *     printf("My Component has a father");
 *   else
 *     printf("My Component is stand alone");
 * }
 *
 * or
 *
 * CATPLMID myComponent;
 * CATPLMTypeH TypeH(myComponent);
 * CATPLMTypeProtectedBehaviors Behavior(TypeH);
 * HRESULT rc_aggregation=Behavior.CanBeAggregated();
 * if ( SUCCEEDED(rc_aggregation) )
 * {
 *   if ( rc_aggregation==S_OK )
 *     printf("My Component has a father");
 *   else
 *     printf("My Component is stand alone");
 * }
 *
 * </code>
 * </ul>
 */
class CATPLMTypeProtectedBehaviors : public CATPLMTypeDescriptor
{
public:
  inline CATPLMTypeProtectedBehaviors(const CATPLMTypeH & iPLMType) : CATPLMTypeDescriptor(iPLMType) {}
#if defined(TSTCATPLMAppIdOpen_H) || defined(TSTCATPLMODTAdapterBaseForData_H)
  //hack for several sources in CATPLMImplAdapterQL.tst, good correction: add const in constructors of base classes (big build impact)
  inline CATPLMTypeProtectedBehaviors(const CATPLMType* iPLMType) : CATPLMTypeDescriptor(const_cast<CATPLMType*>(iPLMType)) {}
#endif
  /**
   * List the Relations defined for a PLM Type.
   * <br><b>Role:</b>This method enables to extract a subset of Relations defined for a PLM Type.
   *
   * @param iFilter [in]
   * The filter needed to be applied to get the wanted relations.
   * <ul>
   * <li>TYPREL_Aggregation: enables to retrieve the Relations defined as Aggregating relations in the metadata.</li>
   * <li>TYPREL_Instanciation: enables to retrieve the Relations defined as Instanciation relations in the metadata.</li>
   * <li>TYPREL_Pointer: enables to retrieve the Relations defined as Pointing relations in the metadata.</li>
   * <li>TYPREL_SessionIntegrity: enables to retrieve the Relations defined as mandatory for the Integrity of the Model in the Authoring Session.</li>
   * </ul>
   * @param oRelations [out]
   * The relations found. The returned @href CATPLMTypeRelation are not sorted.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Relations corresponding to the given filter were found.</li>
   * <li><tt>S_FALSE</tt> if no Relation have been found.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT ListRelations(const CATPLMTypeH & iPLMType, int iFilter, CATPLMTypeRelationIter & oRelations);
  inline HRESULT ListRelations(int iFilter, CATPLMTypeRelationIter & oRelations) const { return ListRelations(*this, iFilter, oRelations); }

  /**
   * Determine if the Component can be aggregated under a Father.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be aggregated under a Father Component.
   * <ul>
   * <li>This method is an accelerator for simple use of @href CATPLMTypeProtectedBehaviors#ListRelations with TYPREL_Aggregation filter.</li>
   * </ul>
   *
   * @param oKey [out]
   * The name of the attribute modelizing the relation as defined in the metadata.
   * @param iTargetType [in]
   * The PLM type of the Component which might aggregate the given PLM Type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CanBeAggregated(const CATPLMTypeH & iPLMType, CATString & oKey, const CATPLMTypeH & iTargetType);
  inline HRESULT CanBeAggregated(CATString & oKey, const CATPLMTypeH & iTargetType) const { return CanBeAggregated(*this, oKey, iTargetType); }

  /**
   * Determine if the Component can be aggregated under a Father.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be aggregated under a Father Component.
   * <ul>
   * <li>This method is an accelerator for simple use of @href CATPLMTypeProtectedBehaviors#ListRelations with TYPREL_Aggregation filter.</li>
   * </ul>
   *
   * @param oKey [out]
   * The name of the attribute modelizing the relation as defined in the metadata.
   * @param oAlternateKey [out]
   * The name of an alternate attribute modelizing the relation as defined in the metadata.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CanBeAggregated(const CATPLMTypeH & iPLMType, CATString & oKey, CATString & oAlternateKey);
  inline HRESULT CanBeAggregated(CATString & oKey, CATString & oAlternateKey) const { return CanBeAggregated(*this, oKey, oAlternateKey); }

  /**
   * Determine if the Component can intanciate a Reference/Entity.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type represents an Instanciation relation.
   * <ul>
   * <li>This method is an accelerator for simple use of @href CATPLMTypeProtectedBehaviors#ListRelations with TYPREL_Instanciation filter.</li>
   * </ul>
   *
   * @param oKey [out]
   * The name of the attribute modelizing the relation as defined in the metadata.
   * @param iTargetType [out]
   * The PLM type of the Component which might be instanciated by the given PLM Type.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CanInstanciate(const CATPLMTypeH & iPLMType, CATString & oKey, const CATPLMTypeH & iTargetType);
  inline HRESULT CanInstanciate(CATString & oKey, const CATPLMTypeH & iTargetType) const { return CanInstanciate(*this, oKey, iTargetType); }

  /**
   * Determine if the Component can intanciate a Reference/Entity.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type represents an Instanciation relation.
   * <ul>
   * <li>This method is an accelerator for simple use of @href CATPLMTypeProtectedBehaviors#ListRelations with TYPREL_Instanciation filter.</li>
   * <li>CATPLMTypeH_Null and <code>S_OK</code> is returned if more than one PLM Type is targeted by the Instanciation. Use CATPLMTypeProtectedBehaviors#ListRelations for more accuracy in the behavior.</li>
   * </ul>
   *
   * @param oKey [out]
   * The name of the attribute modelizing the relation as defined in the metadata.
   * @param oAlternateKey [out]
   * The name of an alternate attribute modelizing the relation as defined in the metadata.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CanInstanciate(const CATPLMTypeH & iPLMType, CATString & oKey, CATString & oAlternateKey);
  inline HRESULT CanInstanciate(CATString & oKey, CATString & oAlternateKey) const { return CanInstanciate(*this, oKey, oAlternateKey); }

  /**
   * Determine if the Component support the mono-instanciation pattern.
   * <br><b>Role:</b>This method enables to determine if a Component can be mono-instanciated. The Modelization attribute key is returned.
   *
   * @param oKey [out]
   * The name of the attribute modelizing the mono-instanciation behavior.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportMonoInstanciation(const CATPLMTypeH & iPLMType, CATString & oKey);
  inline HRESULT SupportMonoInstanciation(CATString & oKey) const { return SupportMonoInstanciation(*this, oKey); }

  /**
   * Determine if the Component can be versioned.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be versioned through the different Versioing apis.
   *
   * @param oKey [out]
   * The name of the attribute modelizing the versioning pattern.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportVersioning(const CATPLMTypeH & iPLMType, CATString & oKey);
  inline HRESULT SupportVersioning(CATString & oKey) const { return SupportVersioning(*this, oKey); }

  /**
   * Determine if the Component can be expanded to retrieve its aggregated children.
   * <br><b>Role:</b>This method enables to determine if a Component can be expanded in the database to retrieve its aggregated children.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportExpand(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportExpand() const { return SupportExpand(*this); }

  /**
   * Determine if the Component supports Maturity evolutions.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type implements the maturity functionality.
   *
   * @param oKey [out]
   * The name of the attribute modelizing the maturity pattern.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportMaturity(const CATPLMTypeH & iPLMType, CATString & oKey);
  inline HRESULT SupportMaturity(CATString & oKey) const { return SupportMaturity(*this, oKey); }

  /**
   * Determine if the Component can be queried for Genealogy functionality.
   * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be handled by the Genealogy functionality.
   *
   * @param oKey [out]
   * The name of the attribute modelizing the genealogy pattern.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportGenealogy(const CATPLMTypeH & iPLMType, CATString & oKey);
  inline HRESULT SupportGenealogy(CATString & oKey) const { return SupportGenealogy(*this, oKey); }

  /**
   * Determine if the Component can be destroyed in an Authoring Session.
   * <br><b>Role:</b>This method enables to determine if a Component can be asked to be destroyed in the Database from an Authoring Session.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportDeletionFromAuthoringSession(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportDeletionFromAuthoringSession() const { return SupportDeletionFromAuthoringSession(*this); }

  /**
   * Determine if the Component can be destroyed directly in the Database.
   * <br><b>Role:</b>This method enables to determine if a Component can be destroyed in the database through a Short Transaction.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportShortTransactionDeletion(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportShortTransactionDeletion() const { return SupportShortTransactionDeletion(*this); }

  /**
   * Determine if the Component can be destroyed even if it is currently edited in the Authoring Session.
   * <br><b>Role:</b>This method enables to determine if a Component can be deleted from the Database even if it is currently edited in the Authoring Session.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportShortTransactionDeletionIfAvailableInAuthoringSession(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportShortTransactionDeletionIfAvailableInAuthoringSession() const { return SupportShortTransactionDeletionIfAvailableInAuthoringSession(*this); }

  /**
   * Determine if a PLM type is compliant with the Refresh functionality.
   * <br><b>Role:</b>This method enables to determine if the PLM type can be used to perfrom a Refresh operation.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportSessionRefresh(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportSessionRefresh() const { return SupportSessionRefresh(*this); }

  /**
   * @ nodoc
   */
  ExportedByCATPLMIdentificationAccess static HRESULT GetGenericAttributeForSelectConditionInOpenQuery(const CATPLMTypeH & iPLMType, CATString & oKey);
  inline HRESULT GetGenericAttributeForSelectConditionInOpenQuery(CATString & oKey) const { return GetGenericAttributeForSelectConditionInOpenQuery(*this, oKey); }

  /**
   * @ nodoc
   */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportIdentificationSet(const CATPLMTypeH & iPLMType);
  inline HRESULT SupportIdentificationSet() const { return SupportIdentificationSet(*this); }

  /**
   * Determine if the PLM type is usable for an instanciation in a Session.
   * <br><b>Role:</b>This method enables to determine if the PLM type can be used to instanciate a Component in a Session depending on the PLM typing system availability.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the PLM Type is reliable for Component instanciation in the Session.</li>
   * <li><tt>S_FALSE</tt> if the PLM Type cannot be used to instantiate a Component in the Session.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CheckTypingCompatibilityForInstanciation(const CATPLMTypeH & iPLMType);
  inline HRESULT CheckTypingCompatibilityForInstanciation() const { return CheckTypingCompatibilityForInstanciation(*this); }

  /**
   * Order the PLM type compared to other.
   * <br><b>Role:</b>This method enables to determine the ranking of a PLM type with the purpose of ordering Components.
   *
   * @param iOperation [in]
   * The kind of operation for which the Components must be ordered.
   * @param oRanking [out]
   * The rank (rank>=1).
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT GetRankForOperation(const CATPLMTypeH & iPLMType, CATPLMTypeBehaviorDefs::PLMTypeRankingOperation iOperation, short & oRanking);
  inline HRESULT GetRankForOperation(CATPLMTypeBehaviorDefs::PLMTypeRankingOperation iOperation, short & oRanking) const { return GetRankForOperation(*this, iOperation, oRanking); }

  /**
   * Returns the maximum value that can be retrieved through GetRankForOperation
   *
   * @return
   *    The maximum value that can be retrieved through GetRankForOperation
   */
  ExportedByCATPLMIdentificationAccess static int GetMaxRankForOperations();

  /**
   * warning, does not do what it says !
   *
   * return S_OK if the type belongs to an hardcoded list of internal infrastructure types that should not be shown in edit/links
   */
  ExportedByCATPLMIdentificationAccess static HRESULT IsUIDisplayable(const CATPLMTypeH & iPLMType);
  inline HRESULT IsUIDisplayable() const { return IsUIDisplayable(*this); }

  /**
   * Determine if a PLM type is compliant with the DWS behaviors.
   * <br><b>Role:</b>This method enables to determine if the PLM type can be used in a DWS.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
   * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT IsDWSCompliant(const CATPLMTypeH & iPLMType);
  inline HRESULT IsDWSCompliant() const { return IsDWSCompliant(*this); }


  /**
  * Determines if a minor of this type can be interchanged in session.
  * If yes, it means that only one minor of this type may be present in a session at the same time,
  * and links are dynamically resolved on minor
  * If no, it means that multiple minors of this type may be present at the same time in a session,
  * at the price of no dynamic resolution of links.
  * Implemented R217 and +
  * Property on metadata : InterchangeableMinors, default to yes for IRPC and No for ER
  * <br><b>Role</b>: Determine minor interchangeability (ie. dynamic resolution and multiple minor in a session)
  *
  * @return
  * <dl>
  * <dt><code>S_OK</code> Minor type is interchangeable <dd>
  * <dt><code>S_FALSE</code> Minor type is not interchangeable <dd>
  * <dt><code>E_FAIL</code> If error occured dyring the processing <dd>
  * <dt><code>E_UNEXPECTED</code> If the given type is invalid <dd>
  * </dl>
  */
  ExportedByCATPLMIdentificationAccess static HRESULT IsMinorInterchangeable(const CATPLMTypeH &iPLMType);
  inline HRESULT IsMinorInterchangeable() const { return IsMinorInterchangeable(*this); }

  /**
   * Returns the attribute to use for CEStamp query.
   *
   * @param oCEStampAttribute [out]:
   *   The value of the attribute to use to query the CEStamp.
   *
   * @return
   * <ul>
   * <li><tt>S_OK</tt> if the attribute has been found.</li>
   * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
   * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT GetCEStampAttribut(const CATPLMTypeH & iPLMType, CATString & oCEStampAttribute);
  inline HRESULT GetCEStampAttribut(CATString & oCEStampAttribute) const { return GetCEStampAttribut(*this, oCEStampAttribute); }

  /**
  *GetRoleForLifeCycleCoupling
  * <br><b>Role</b>: Get the role of relations that can be held by a component
  * of the given type which symbolize a theoritical aggregating link (aka Dard Vert).
  * The returned role have therefore a life cycle coupling meaning.
  * @param iPLMType
  *   the type of the component
  * @param oRoles
  *   the roles that have a life cycle coupling meaning
  * @return
  * <dl>
  * <dt><code>S_OK</code> if the given type has life cycle coupling relation roles<dd>
  * <dt><code>S_FALSE</code> if no such role is associated to this type<dd>
  * <dt><code>E_FAIL</code> if an error occured during the treatment.<dd>
  * <dt><code>E_UNEXPECTED</code> if the given PLM Type is invalid.<dd>
  * </dl>
  */
  ExportedByCATPLMIdentificationAccess static HRESULT GetRoleForLifeCycleCoupling(const CATPLMTypeH & iPLMType, CATOmxArray<CATString> & oRoles);
  inline HRESULT GetRoleForLifeCycleCoupling(CATOmxArray<CATString> & oRoles) { return GetRoleForLifeCycleCoupling(*this, oRoles); }

  /**
  * Get the name of tree ordering attribute, if any exists with the right kind.
  * @param oAttName
  *    the name of the TreeOrdering attribute
  * @return
  * <dl>
  * <dt><code>S_OK</code> if the given type has a tree ordering attribute<dd>
  * <dt><code>S_FALSE</code> if no such attribute is declared on this type<dd>
  * <dt><code>E_FAIL</code> if an error occured during the treatment.<dd>
  * <dt><code>E_UNEXPECTED</code> if the given PLM Type is invalid.<dd>
  * </dl>
  */
  ExportedByCATPLMIdentificationAccess static HRESULT GetTreeOrderingAttributeName(const CATPLMTypeH& iType, CATOmxKeyString& oAttName);
  ExportedByCATPLMIdentificationAccess HRESULT GetTreeOrderingAttributeName(CATOmxKeyString& oAttName) const;

  /**
  * Determine if components of this type are compliant with "save as" functionality.
  * <br><b>Role:</b>This method enables to determine if a Component from the given PLM Type can be saved in the database as a new component by the authoring session.
  *
  * @return
  * <ul>
  * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
  * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
  * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
  * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
  * </ul>
  */
  ExportedByCATPLMIdentificationAccess static HRESULT SupportSaveAs(const CATPLMTypeH& iType);
  inline HRESULT SupportSaveAs() const { return SupportSaveAs(*this); }

  /**
   * Checks if input from/to types match allowed target types declared in .metadata files (through SubClause statements)
   * @param iType
   *    the type to check.
   *    * on a RelationType both iFromType and iToType must be set
   *    * on a PLMPort/PLMConnection, iFromType must be set but iToType must be null
   *    * on something else, both iFromType and iToType must be null
   * @param iFromType
   *    the type of the from/fromrel/V_Owner target
   * @param iToType
   *    the type of the to/to/rel/V_IsInstanceOf target
   * @return
   * <ul>
   * <li><tt>S_OK</tt>everything is fine.</li>
   * <li><tt>S_FALSE</tt>if iFromType or iToType or not valid target types</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT CheckFromAndTo(const CATPLMTypeH& iType, const CATPLMTypeH& iFromType, const CATPLMTypeH& iToType);

  /**
   * Determine whether objects of this type have position matrixes.
   * Nowadays, it is only true for objects deriving from "LPAbstractInstance".
   *
   * @return
   * <ul>
  * <li><tt>S_OK</tt> if the Component support the Pattern.</li>
  * <li><tt>S_FALSE</tt> if a Component from this PLM Type does not support the Pattern.</li>
  * <li><tt>E_FAIL</tt> if an error occured during the treatment.</li>
  * <li><tt>E_UNEXPECTED</tt> if the given PLM Type is invalid.</li>
   * </ul>
   */
  ExportedByCATPLMIdentificationAccess static HRESULT IsPositionnable(const CATPLMTypeH& iType);
  inline HRESULT IsPositionnable() const { return IsPositionnable(*this); }

  /**
   * return true if extension has ResetOnCloning=Yes (respectively ResetOnNewVersion) property in metadata
   */
  ExportedByCATPLMIdentificationAccess static bool IsResetOnCloning(const CATPLMTypeH& iExtensionType);
  ExportedByCATPLMIdentificationAccess static bool IsResetOnNewVersion(const CATPLMTypeH& iExtensionType);
};
#endif
