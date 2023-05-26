#ifndef CATOmbRerouteAssistant_H
#define CATOmbRerouteAssistant_H

// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U3
 */

 // System
#include "CATCollec.h"
// SystemTS
#include "CATBoolean.h"
#include "CATSysTSDataType.h"
#include "IUnknown.h"
// ObjectModelerBase
#include "CATObjectModelerBase.h"

class CATOmbOutputRelation;
class CATOmbLinkProperties;
class CATComponentId;
class CATLISTP(CATOmbOutputRelation);
class CATLISTP(CATOmbRerouteElementaryRequest);
class CATOmbRelationContext;
class CATOmbProposedRerouteTargetIterator;
class CATOmbCompoIdToCompoIdHashTable;

/**
 * Class that defines a reroute assistant, an object used to guide a user during the process.
 */
class ExportedByCATObjectModelerBase CATOmbRerouteAssistant
{
public:
  /**
   * Manipulated object type.
   * <br><b>Role:</b> Enumerates the object types.
   * @param RELATION
   *		The assistant will reroute a single relation. @see #GetManipulatedRelation()
   * @param BUNDLE
   *		The assistant will reroute a bundle. @see #GetManipulatedBundle()
   * @param CONTEXT
   *		The assistant will reroute the common context of a set of links.
   *		@see #GetManipulatedContext().
   */
  enum CATOmbManipulatedObjectType { RELATION, BUNDLE, CONTEXT };

  /**
   * Returns the manipulated object type.
   * @return
   *	The manipulated object type.
   */
  virtual CATOmbManipulatedObjectType GetManipulatedObjectType() const = 0;

  /**
   * Reroute proposition type.
   * <br><b>Role:</b> Enumerates the available proposition types.
   * @param PROPOSITIONS_AVAILABLE
   *	The system has found targets. @see GetProposedRerouteTargets()
   * @param PROPOSITION_AVAILABLE_UNDER_CONDITION
   *	The system has found targets, but the current assistant is inside an integrity unit (@see CATOmbRerouteAssistantIntegrityUnit), and
   *	has to be solved in conjunction with others assistants.
   * @param NO_SOLUTION
   *	 There is no eligible component(s) on which the relation(s) can be rerouted.
   * @param NO_NEW_ALTERNATIVE
   *	 There is no other eligible targets than the components already pointed.
   * @param EXPLICIT_BUNDLE_REROUTE_NOT_ALLOWED
   *	 By specs, explicit reroute is forbidden on bundle relations.
   */
  enum CATOmbReroutePropositionType { PROPOSITIONS_AVAILABLE, PROPOSITION_AVAILABLE_UNDER_CONDITION, NO_SOLUTION, NO_NEW_ALTERNATIVES, EXPLICIT_BUNDLE_REROUTE_NOT_ALLOWED };

  /**
   * Returns the reroute proposition type.
   * @return
   *	The reroute proposition type.
   */
  virtual CATOmbReroutePropositionType GetReroutePropositionType() const = 0;

  /**
   * Reroute diagnostics.
   * <br><b>Role:</b> Enumerates the diagnostics, i.e the captured user intentions.
   * This diagnostic influences the pertinence of the solutions.
   * @param REPAIR
   *		The model is in an invalid state: the system looks for a valid solution
   *		while trying to stay close to the current model.
   * @param FIND_ALTERNATIVE
   *		The model is already in a valid status: the system assumes that the user
   *		wants to find a different, valid solution.
   * @param USE_TARGET
   *		The user has explicitly specified a target, which is the most pertinent.
   */
  enum CATOmbRerouteDiagnostic { REPAIR, FIND_ALTERNATIVE, USE_TARGET };

  /**
   * Returns the diagnostic of the assistant
   * @return
   *	A diagnostic.
   */
  virtual CATOmbRerouteDiagnostic GetDiagnostic() const = 0;

  /**
   * Returns the requests that resulted in the creation of this assistant.
   * @param oRequests
   *   The requests. Must not be deleted manually.
   */
  virtual void GetInitiatingRequests(CATLISTP(CATOmbRerouteElementaryRequest) & oRequests) const = 0;

  /**
   * Returns a string describing the diagnostic
   * @return
   *	Nls string
   */
  virtual CATUnicodeString GetDiagnosticNls() const = 0;

  /**
   * Returns the relation that will be rerouted by the assistant.
   * @param oRelation
   *	The relation
   * @return
   *	S_OK: opRelation is valuated
   *	E_FAIL: the manipulated object is not a relation.
   */
  virtual HRESULT GetManipulatedRelation(CATOmbOutputRelation *& oRelation) const = 0;

  /**
   * Returns the bundle that will be rerouted by the assistant.
   * @param oBundles
   *	 The bundle
   * @return
   *  An HRESULT value
   * <dl>
   *	 <dt>S_OK</dt><dd>oBundle a non-empty list.</dd>
   *	 <dt>E_FAIL</dt><dd>the manipulated object is not a bundle.</dd>
   * </dl>
   */
  virtual HRESULT GetManipulatedBundle(CATLISTP(CATOmbOutputRelation) & oBundles) const = 0;

  /**
   * Returns the context that will be rerouted by the assistant.
   * @param oContext
   *	 The contextual relation
   * @return
   *  An HRESULT value
   * <dl>
   *	 <dt>S_OK</dt><dd>opContext is valuated.</dd>
   *	 <dt>E_FAIL</dt><dd>the manipulated object is not a context.</dd>
   * </dl>
   */
  virtual HRESULT GetManipulatedContext(CATOmbRelationContext *& oContext) const = 0;

  /**
   * Returns an iterator on the proposed targets for this assistant.
   * <br><b>Note:</b>A target can be selected using @href CATOmbProposedRerouteTarget#SelectAsTarget.
   * Selecting a target will change the status of the assistant.
   * @param oRerouteTargetIterator
   *  An iterator on the possible target components.
   *  <br><b>Note:</b>Must be deleted after use.
   * @return
   *  An HRESULT value
   * <dl>
   *  <dt>E_FAIL</dt><dd>There are no target propositions.</dd>
   *  <dt>S_OK</dt><dd>Else.</dd>
   * </dl>
   */
  virtual HRESULT GetProposedRerouteTargets(CATOmbProposedRerouteTargetIterator *& oRerouteTargetIterator) = 0;

  /**
   * Cancel the reroute: don't do any modifications to the objects referenced by this assitant
   * <br>The relation(s) causing the error will not be rerouted.
   * @return
   *  S_OK
   */
  virtual HRESULT Cancel() = 0;

  /**
   * Checks whether the assistant is solved or not. An assistant is solved if its behaviour presents no ambiguity:
   * <dl>
   *	<dt>a pertinent target was preselected by the system
   *	<dt>a target was explicitly selected using CATOmbRerouteAssistant#SelectAsTarget
   *	<dt>the assistant was cancelled with Cancel.
   * </dl>
   *
   * @return
   *	A boolean
   */
  virtual bool IsAssistantSolved() const = 0;

  virtual ~CATOmbRerouteAssistant() = default;
};

#endif

