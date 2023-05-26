/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2005
//-----------------------------------------------------------------------------
// 
#ifndef CATOmbLoadingModeRuleSet_H
#define CATOmbLoadingModeRuleSet_H

/**
* @level Protected
* @usage U6
*/

#include "CATOmbSwitchEngine.h"
#include "IUnknown.h"
#include "CATOmxVector.h"

class CATOmiLoadingModeRule;
class CATOmbInternalLoadingModeRule;

/**
* Defines a set of Rules to determine the target loading mode of a RepRef
* This set is then given to the switchEngine
*/
class ExportedByCATOmbSwitchEngine CATOmbLoadingModeRuleSet
{
public:
  //friend class CATOmbSwitchEngineImpl;
  friend class CATOmbSwitchWizard;
  friend class CATOmbLoadingModeComputation;

  //The enumerate for the product rules
  enum PredifinedLoadMode
  {
    PLMMode,
    VisuMode,
    VisuMode2,
    DMUMode,
    LinkableMode,
    EditMode,
    VisuModeV5,
    PLMModeExceptionFor3D
  };

  enum LoadingModeRule
  {
    Index_Mode,
    PLM_Mode,
    AuthoringVisu_Mode,
    AuthoringVisu2_Mode,
    VisuRep_Mode,
    Authoring_Mode,
    PartBRep_Mode,
    PartEdit_Mode,
    AuthoringFullEdit_Mode,
    FullLoadingOfAll_Mode,
    AuthoringVisuExtended_Mode,
    AuthoringVisuAlternative_Mode,
    AuthoringFullExtended_Mode,
    Migration_Mode,
    V5INV6_Mode,
    V5Visu_Mode,
    Thumbnail_Mode,
    Archive_Mode,
    CollaborativeEdit_Mode,
    AuthoringXCAD_Mode
  };

  CATOmbLoadingModeRuleSet();
  virtual ~CATOmbLoadingModeRuleSet();

  /**
  * Adds a Loading Mode rule to the set of rules.
  * @param <tt>CATOmiLoadingModeRule</tt> iLoadingModeRule
  *       the rule to append to the set
  * @return
  * <ul>
  *   <li> S_OK : iLoadingModeRule has been inserted with success </li>
  *   <li> E_FAIL : unexpected error  </li>
  * </ul>
  *
  */
  HRESULT AddALoadingModeRule(const CATOmiLoadingModeRule& iLoadingModeRule);

  /**
  * Retrieves the Product rules from a load mode.
  *
  * @param iLoadMode [in]
  *   The Load Mode
  *
  * @return
  *   <code>S_OK</code> if everything ran ok, otherwise E_FAIL
  *
  */
  HRESULT ApplyPredefinedRules(PredifinedLoadMode iLoadMode);

  /**
  * @deprecated : do not use.
  */
  HRESULT ApplyPredefinedRules(PredifinedLoadMode iLoadMode, CATOmbLoadingModeRuleSet& oLoadingModeRules);

  /**
  * Gets the Visualization stream Type to be used for a given SelectiveLoading mode.
  * @return
  *        S_OK    : Use specific behavior (@R209 : Use UVR stream in Prd:Visu_Mode)
  *        S_FALSE : Use standard behavior (@R209 : Use CGR stream in Prd:Visu_Mode)
  * <br>   E_* : unexpected error
  *
  */
  HRESULT GetVisuStreamType();

  /**
  * Init InitLoadingModeRules static List from installation Path (Executed only first time)
  */
  static void InitLoadingModeRulesFromInstallationPath();

  /**
  * Copy ctor & assignation
  **/
  CATOmbLoadingModeRuleSet(const CATOmbLoadingModeRuleSet&);
  CATOmbLoadingModeRuleSet& operator=(const CATOmbLoadingModeRuleSet&);

private:

  CATOmxVector<CATOmbInternalLoadingModeRule> _LoadingModeRules;
};

#endif
