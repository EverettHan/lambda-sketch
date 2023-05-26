#ifndef CATOmbProposedRerouteTarget_H
#define CATOmbProposedRerouteTarget_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

#include "CATObjectModelerBase.h"
#include "sequence_octet.h"
#include "CATCollec.h"
#include "CATBoolean.h"

class CATComponentId;
class CATOmbOutputRelation;
class CATOmbLinkProperties;
class CATOmbRelationContext;
class CATLISTP(CATOmbLinkProperties);
class CATLISTP(CATOmbOutputRelation);
class CATLISTP(CATOmbRelationRerouteTransaction);
class CATOmbCompoIdToCompoIdHashTable;


/**
 * Class to store a CATComponentId and a status during a logical reroute.
 */
class ExportedByCATObjectModelerBase CATOmbProposedRerouteTarget
{
public:

  /**
   * This status describes the state of the relation after the reroute if
   * this CATComponentId is selected as the new target.
   *	@param VALID
   *		The relation is in a valid state
     *  @param VALID_UNDER_CONDITION
     *      @see CATOmbRerouteIntegrityUnitAssistant, the relation belongs to an integrity unit, and its inter-relation validity depends
     *          on others relations state.
   *  @param TARGET_SELECTION_BREAKS_LINKS
   *		At least one link cannot be rerouted and will break if this CATComponentId is chosen.
   *  @param PLM_INTEGRITY_VIOLATION
   *		PLMIntegrity rules violation (not about inter-relation dependency).
   *  @param PLM_INTEGRITY_VIOLATION_WITH_PREVIOUS_REROUTE_REQUEST
   *		@see CATOmbRerouteIntegrityUnitAssistant, PLMIntegrity rules violation (inter-relation dependency) with a previously solved RerouteAssistant,
     *		inside the same integrity unit.
   *  @param INVALID_TYPE_CONVERSION
   *		PLM Type mismatching on pointed component.
   *	@param FATAL_ERROR
   *		An unexpected error occured during the reroute simulation.
   */
  enum ComponentStatus
  {
    VALID,
    VALID_UNDER_CONDITION,
    TARGET_SELECTION_BREAKS_LINKS,
    PLM_INTEGRITY_VIOLATION,
    PLM_INTEGRITY_VIOLATION_WITH_PREVIOUS_REROUTE_REQUEST,
    INVALID_TYPE_CONVERSION,
    FATAL_ERROR
  };

  /**
   * This enum describes the general strategy used to find a proposed target in session.
   *	@param USE_ALTERNATIVE_VERSION
   *		An alternative version of the component was found.
   *	@param USE_ALTERNATIVE_CONTEXT
   *		An alternative contextual path was found.
   *	@param CHANGE_BUNDLE_OWNER
   *		An alternative version of the bundle owner was found.
   *	@param PRESERVE_FUNCTION
   *		A component with the same function was found.
   */
  enum RerouteStrategy
  {
    CHANGE_BUNDLE_OWNER,
    USE_ALTERNATIVE_VERSION,
    PRESERVE_FUNCTION,
    USE_ALTERNATIVE_PATH,
    USE_SPECIFIED_TARGET,
    USE_ALTERNATIVE_CONTEXT,
    EXTEND_CONTEXT_SCOPE
  };

  /**
   * This enum represents the various possible natures of the context of the proposed target.
   * @param UNDEFINED
   *   The context does not have any particular properties.
   * @param MAXIMUM
   *   The context is the maximum possible context in session.
   * @param RIGID_MINIMUM
   *   The context is minimal and ignores PMR (product flexibility).
   * @param FLEXIBLE_MINIUM
   *   The context is minimal and respects PMR rules.
   */
  enum ContextType
  {
    UNDEFINED,
    RIGID_MINIMUM,
    FLEXIBLE_MINIMUM
  };

  /**
   * Returns the associated CATComponentId target
   *  @param component
   *		the target component
   *  @return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>The object was not correctly initialized.</dd>
   *   <dt>S_OK</dt>
   *    <dd>Operation successful.</dd>
   *  </dl>
   */
  virtual HRESULT GetProposedTarget(CATComponentId & oCompId) const = 0;

  /**
   * Returns the status associated with the target.
   * @return
   *  The status.
   */
  virtual ComponentStatus GetStatus() const = 0;

  /**
   * Returns a string describing a status
   *  @return
   *		A CATUnicodeString
   */
  virtual const CATUnicodeString GetStatusNls() const = 0;

  /**
   * Returns the strategy used to find this target.
   *	@return
   *		The strategy
   */
  virtual RerouteStrategy GetStrategy() const = 0;

  /**
   * Returns a string describing the strategy
   *  @return
   *		A CATUnicodeString
   */
  virtual const CATUnicodeString GetStrategyNls() const = 0;

  /**
   * During the reroute, attempt to correct the ambiguity by
   * specifying this component as the new target.
   *	@returns
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>this component is not a valid target (@see #IsValidTarget()).</dd>
   *   <dt>S_OK</dt>
   *    <dd>The component was successfully selected and the error is resolved.</dd>
   *  </dl>
   */
  virtual HRESULT SelectAsTarget() = 0;

  /**
   * Checks whether the relation can be rerouted on this component.
   * Components that put the relation in an invalid state cannot be chosen
   * as targets.
   */
  virtual CATBoolean IsTargetSelectionAllowed() const = 0;

  /**
   * Returns the list of links that will be broken if this
   * target is chosen as the new target for the reroute entity.
   *	@return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>Object not initialized properly.</dd>
   *   <dt>S_OK</dt>
   *    <dd>Operation successful: oLinks is valuated</dd>
   *  </dl>
   */
  virtual HRESULT GetLinksBrokenByTargetSelection(CATLISTP(CATOmbLinkProperties) & oLinks) const = 0;

  /**
   * Returns the list of relations that will be broken if this
   * target is chosen as the new target for the reroute entity.
   *	@return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>Object not initialized properly.</dd>
   *   <dt>S_OK</dt>
   *    <dd>Operation successful: oRelations is valuated</dd>
   *  </dl>
   */
  virtual HRESULT GetRelationsBrokenByTargetSelection(CATLISTP(CATOmbOutputRelation) & oRelations) const = 0;

  /**
   * Returns a pertinence score for this target
   * @return
   *		The pertinence score
   */
  virtual CATUINT32 GetPertinence() const = 0;

  /**
   * Returns a list of transactions.
   * @param oRelationTransactions
   *		The transactions
   * @return
   *  An HRESULT value:
   *  <dl>
   *   <dt>E_FAIL</dt>
   *    <dd>The object was not initialized correctly.</dd>
   *   <dt>S_OK</dt>
   *    <dd>Operation successful.</dd>
   *  </dl>
   */
  virtual HRESULT GetRelationTransactions(CATLISTP(CATOmbRelationRerouteTransaction) & oRelationTransactions) const = 0;

  /**
   * Returns the nature of the context of the proposed reroute target.
   * @return
   *   the context type. see the CATOmbProposedRerouteTarget::ContextType enum for more information.
   */
  virtual ContextType GetContextType() const = 0;

  /** @nodoc */
  virtual ~CATOmbProposedRerouteTarget() {};
};

#endif


