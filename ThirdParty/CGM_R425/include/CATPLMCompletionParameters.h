// COPYRIGHT DASSAULT SYSTEMES 2009

/**
 * @level Protected
 * @usage U1
 */

#ifndef CATPLMCompletionParameters_h
#define CATPLMCompletionParameters_h

#include "CATPLMIntegrationInterfaces.h"
#include "CATBoolean.h"
#include "CATPLMCompletionContext.h"
#include "CATUnicodeString.h"

 /**
 * This class represents the various options available for the completions actions that
 * can be used in the CATPLMCompleteGraphWithFilter api. The Action enum defines the
 * various steps that can be followed.
 */
class ExportedByCATPLMIntegrationInterfaces CATPLMCompletionParameters
{
public:
  /**
  * Defines the various completion actions that can be done on a given set of components
  *   * Expand :
  *        Expand the given components (see ExpandLevel).
  *   * Decorate :
  *        Add the ports, connections, reps, rep instances and material data.
  *   * DecorateWithIntegrity :
  *        Same as Decorate but an integrity check is done on the components (including
  *        the subcomponents in the case of complex plmids) in order to add the aggregating
  *        and aggregated refs/reps for instances, repinstances, ports and connections
  *   * ExpandWithIntegrity :
  *        Same as Expand but an integrity check is done on the components (see up)
  * Note the integrity actions are less performant than their basi counter part due to the
  * integrity call. If you known that your set of data is ok (because it comes from a server
  * expand on a reference for example), use the basic versions.
  *
  * Expand actions can be configured through SetExpandWithReps and SetExpandWithCnxAndPorts.
  * Note the results of the expand actions will automatically be added to a generic decoration
  * action.
  *
  * Decorate steps can be configured through SetRepMode, SetRetrieveCnxAndPorts and SetRetrieveMaterials.
  */
  enum Action { Expand = 0, Decorate = 1, DecorateWithIntegrity = 2, ExpandWithIntegrity = 3 };

  /**
  * Defines the various filters that can applied to the reps retrived in the Decoration actions
  *   * NoRep: Deprecated, do not use. Use IntegrityReps instead.
  *   * IntegrityReps : only mandatory reps are kept.
  *   * Shape3DReps : mandatory + 3DShapes.
  *   * CustomReps : mandatory + design reps. For Functionnal or Logical data, all reps are retrieved
  *   * AllReps : all reps.
  */
  enum RepMode { NoRep, IntegrityReps, Shape3DReps, CustomReps, AllReps };

  /**
  * Defines the level of expand
  *   * OneLevel: Only expand the first level
  *   * AllLevels : Expand all the structure
  * Default : AllLevels
  */
  enum ExpandLevel { AllLevels = 0, OneLevel };

  enum class LinkFilteringMode {
    AllLinks = 0,
    OnlyRelevantLinks = 1,
    NoLinks = 2
  };

  /**
  * Constuctor
  *   * iRepMode               : see SetRepMode
  *   * iRetrieveMaterials     : see SetRetrieveMaterials
  *   * iRetrieveCnxAndPorts   : see SetRetrieveMaterials
  *   * iRetrieveCnxAndPorts   : see SetRetrieveCnxAndPorts
  *   * iExpandWithReps        : see SetExpandWithReps
  *   * iExpandWithCnxAndPorts : see SetExpandWithCnxAndPorts
  */
  CATPLMCompletionParameters(const RepMode iRepMode = RepMode::CustomReps,
    const CATBoolean iRetrieveMaterials = FALSE,
    const CATBoolean iRetrieveCnxAndPorts = TRUE,
    const CATBoolean iExpandWithReps = FALSE,
    const CATBoolean iExpandWithCnxAndPorts = FALSE,
    const CATBoolean iCheckFinalIntegrity = FALSE,
    const CATPLMCompletionContext::Objectif = CATPLMCompletionContext::Objectif::NoObjectif,
    const CATUnicodeString = "",
    const CATBoolean iRetrieveDIFs = TRUE,
    const CATBoolean iRetrievePLMParameters = FALSE,
    const CATBoolean iOldTyping = FALSE);

  CATPLMCompletionParameters(const CATPLMCompletionParameters&) = default;
  CATPLMCompletionParameters& operator = (const CATPLMCompletionParameters&) = default;
  virtual ~CATPLMCompletionParameters() = default;

  /**
  * Manages the expand details : shall the reps be retreived in the expand actions ?
  * If set to TRUE, all the reps/repinsts types given by the CATIPLMCompletionTypeRetriever
  * (see the CATPLMCompleteGraphWithFilter api) will be retrieved in the various expand actions.
  */
  inline void SetExpandWithReps(const CATBoolean iExpandWithReps) { _expandWithReps = iExpandWithReps; }
  inline CATBoolean ExpandWithReps() const { return _expandWithReps; }

  /**
  * Manages the expand details : shall the cnxs and ports be retreived in the expand actions ?
  * If set to TRUE, all the connections/ports types given by the CATIPLMCompletionTypeRetriever
  * (see the CATPLMCompleteGraphWithFilter api) will be retrieved in the various expand actions.
  */
  inline void SetExpandWithCnxAndPorts(const CATBoolean iExpandWithCnxAndPorts) { _expandWithCnxAndPorts = iExpandWithCnxAndPorts; }
  inline CATBoolean ExpandWithCnxAndPorts() const { return _expandWithCnxAndPorts; }

  /**
  * Manages the decoration details : which reps do you need in your decoration ?
  */
  void SetRepMode(const RepMode iRepMode);
  inline RepMode GetRepMode() const { return _repMode; }

  /**
   * Specifies if 'RepCentric' filtering should be done : if some rep instances are given in input,
   * only those repinstances will be opened under their respective owner references. Note that
   * integrity representations will still be opened, as soon as the RepMode is not 'NoRep'.
   *
   * By default, this is set to TRUE. If you set it to FALSE the reps retrieved under the reference
   * will only take into account the RepMode, and the given rep instances won't trigger any specific
   * filtering.
   */
  inline void SetFilterOnInputReps(const CATBoolean iFilterOnInputReps) { _filterOnInputReps = iFilterOnInputReps; }
  inline CATBoolean FilterOnInputReps() const { return _filterOnInputReps; }

  /**
   * Specifies if reps should be retrieved on the components to decorate.
   * Note that if the global repMode is not NoRep, the integrity reps will be
   * retrieved on those components to decorate anyway.
   *
   * By default, it is set to TRUE, meaning that reps will be retrieves on
   * components to decorate, with respect to the global repMode.
   */
  inline void SetRetrieveRepsInDecorate(const CATBoolean iRetrieveRepsInDecorate) { _retrieveRepsInDecorate = iRetrieveRepsInDecorate; }
  inline CATBoolean RetrieveRepsInDecorate() const { return _retrieveRepsInDecorate; }

  /**
  * Manages the decoration details : do you want the amterials attached to your components ?
  */
  inline void SetRetrieveMaterials(const CATBoolean iRetrieveMaterials) { _retrieveMaterials = iRetrieveMaterials; }
  inline CATBoolean RetrieveMaterials() const { return _retrieveMaterials; }

  /**
  * Manages the decoration details : do you want the DIFs attached to your components ?
  */
  inline void SetRetrieveDIFs(const CATBoolean iRetrieveDIFs) { _retrieveDIFs = iRetrieveDIFs; }
  inline CATBoolean RetrieveDIFs() const { return _retrieveDIFs; }

  /**
  * Manages the decoration details : do you want the PLMParameters attached to your components ?
  */
  inline void SetRetrievePLMParameters(const CATBoolean iRetrievePLMParameters) { _retrievePLMParameters = iRetrievePLMParameters; }
  inline CATBoolean RetrievePLMParameters() const { return _retrievePLMParameters; }

  /**
  * Manages the decoration details : do you want the connections and ports attached to your components ?
  */
  inline void SetRetrieveCnxAndPorts(const CATBoolean iRetrieveCnxAndPorts) { _retrieveCnxAndPorts = iRetrieveCnxAndPorts; }
  inline CATBoolean RetrieveCnxAndPorts() const { return _retrieveCnxAndPorts; }

  /**
  * Retrievs the effectivities and associated elements
  */
  inline void SetRetrieveConfiguration(const CATBoolean iRetrieveConfiguration) { _retrieveConfiguration = iRetrieveConfiguration; }
  inline CATBoolean RetrieveConfiguration() const { return _retrieveConfiguration; }

  inline void SetRetrieveConfigConnections(const CATBoolean iRetrieveConfigConnections) { _retrieveConfigConnections = iRetrieveConfigConnections; }
  inline CATBoolean RetrieveConfigConnections() const { return _retrieveConfigConnections; }

  /**
  * Manage context ie. what want the client.
  * Implemented for Simulation : open with or without model
  **/
  inline void SetContext(const CATPLMCompletionContext::Objectif iContext) { _context = iContext; }
  inline CATPLMCompletionContext::Objectif GetContext() const { return _context; }

  /**
  * Activates a final integrity check on the input inst, repinst, port and cnx components to ensure
  * that their aggregated and aggregating components in the final scope. The added components won't
  * be decorated. This check need to run a fetch query on inst, repinst, port and cnx  of the input
  * set, even if the set satifies the integrity rules, so don't turn it on if you know that your
  * input set is OK.
  */
  inline void SetCheckFinalIntegrity(const CATBoolean iCheckFinalIntegrity) { _checkFinalIntegrity = iCheckFinalIntegrity; }
  inline CATBoolean CheckFinalIntegrity() const { return _checkFinalIntegrity; }

  inline void SetExpandLevel(const ExpandLevel iExpandLevel) { _expandLevel = iExpandLevel; }
  inline ExpandLevel GetExpandLevel() const { return _expandLevel; }

  inline void SetProfile(const CATUnicodeString& iProfileName) { _profileName = iProfileName; }
  inline CATUnicodeString GetProfile() const { return _profileName; }

  /**
  * Activates old typing mode. That means that if the open profile support old typing, a filter on discipline will be done.
  */
  inline void SetOldTyping(const CATBoolean iOldTyping)
  {
    _oldTyping = iOldTyping;
    _oldTypingOverwritten = TRUE;
  }
  inline CATBoolean OldTyping() const { return _oldTyping; }
  inline CATBoolean OldTypingOverwritten() const { return _oldTypingOverwritten; }

  HRESULT SetMfgProductionPlanningFilteringMode(LinkFilteringMode iFilteringMode);
  inline LinkFilteringMode GetMfgProductionPlanningFilteringMode() const { return _mfgProductionPlanningFilteringMode; }

  HRESULT SetAllocatedResourceLinkFilteringMode(LinkFilteringMode iFilteringMode);
  inline LinkFilteringMode GetAllocatedResourceFilteringMode() const { return _allocatedResourceFilteringMode; }

  HRESULT SetTimeConstraintLinkFilteringMode(LinkFilteringMode iFilteringMode);
  inline LinkFilteringMode GetTimeConstraintFilteringMode() const { return _timeConstraintsFilteringMode; }

  HRESULT SetProcessPrerequisiteLinkFilteringMode(LinkFilteringMode iFilteringMode);
  inline LinkFilteringMode GetProcessPrerequisiteFilteringMode() const { return _processPrerequisiteFilteringMode; }

  CATBoolean ForcePPRConnectionsFiltering() const;

private:
  // INTERNAL USE ONLY
  // Specific NoRep mode default constructor for internal completion algorithms.
  friend class CATPLMCompleteGraphForRelevantCnxAndPorts;
  friend class CATPLMItgOtherSpaceOpener;
  CATPLMCompletionParameters(const CATBoolean iRetrieveMaterials,
    const CATBoolean iRetrieveCnxAndPorts,
    const CATBoolean iExpandWithReps,
    const CATBoolean iExpandWithCnxAndPorts,
    const CATBoolean iCheckFinalIntegrity,
    const CATPLMCompletionContext::Objectif,
    const CATUnicodeString,
    const CATBoolean iRetrieveDIFs,
    const CATBoolean iRetrievePLMParameters,
    const CATBoolean iOldTyping);

  // INTERNAL USE ONLY
  friend class CATPLMCompleteGraphWithFilterImpl;
  friend class CATPLMCompletionExpandAction;
  friend class CATPLMCompletionPortsAndCnxDecorationAction;
  friend class CATPLMCompletionExpandDindeAction;
  friend class CATPLMCompletionDecorateDindeAction;
  friend class CATPLMCompletionDecorateComposedRepDindeAction;

  // Tests
  friend class CATPLMCompletionParametersForTests;
  inline void ForceNoRepMode() { _repMode = RepMode::NoRep; }
  void InitPPRConnectionsFilteringMode();

private:
  RepMode _repMode{ RepMode::CustomReps };
  CATBoolean _retrieveMaterials{ FALSE },
    _retrieveDIFs{ TRUE },
    _retrieveCnxAndPorts{ TRUE },
    _retrieveConfiguration{ FALSE },
    _retrieveRepsInDecorate{ TRUE },
    _expandWithReps{ FALSE },
    _expandWithCnxAndPorts{ FALSE },
    _checkFinalIntegrity{ FALSE },
    _retrieveConfigConnections{ FALSE },
    _filterOnInputReps{ TRUE },
    _retrievePLMParameters{ FALSE },
    _oldTyping{ FALSE },
    _oldTypingOverwritten{ FALSE };
  CATPLMCompletionContext::Objectif _context{ CATPLMCompletionContext::Objectif::NoObjectif };
  ExpandLevel _expandLevel{ ExpandLevel::AllLevels };
  CATUnicodeString  _profileName{};
  LinkFilteringMode _mfgProductionPlanningFilteringMode{};
  LinkFilteringMode _allocatedResourceFilteringMode{};
  LinkFilteringMode _timeConstraintsFilteringMode{};
  LinkFilteringMode _processPrerequisiteFilteringMode{};
};
#endif
