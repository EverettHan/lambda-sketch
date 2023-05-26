// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATEditabilityManager_h_
#define CATEditabilityManager_h_

// Editability Management

/**
* @level Protected
* @usage U1
*/

#include "CATObjectModelerBase.h"
#include "IUnknown.h"
#include "CATBoolean.h"
#include "CATSession.h"
#include "CATProxySpace.h"
#include "CATComponentIdSet.h"

struct CATEditabilityParameters;

class ExportedByCATObjectModelerBase CATEditabilityManager
{
public:

  /**
  * Describes whether SwitchToEdition/SwitchToReadOnly commands may bypass edition rules.
  *   Forbid : if an object is not lockable in DB, the status switch in session is forbidden (object remains ReadOnly in session).
  *   Warning : the modification is authorized (object switches into ReadWrite status) even if the object is not lockable in DB, but the save is not guaranteed and it may fail.
  */
  enum CATPLMEditabilityMode { Forbid, Warning };

  /**
  * Describes the editability strategy in the session.
  *   Pessimistic : components are locked when they are switched into Read/Write to ensure the save.
  *   Opportunistic : components are locked when the first modification is attempted to ensure the save (if they are read/write in session)
  *   Optimistic : no lock is attempted, the save is not ensured.
  */
  enum CATPLMEditabilityStrategy { Pessimistic, Opportunistic, Optimistic };

  /**
  * Describe the default edit status of all components when they are opened in session.
  *   ReadOnly : (almost) no modification is authorized on components
  *   ReadWrite : modifications are authorized on (almost all) components
  *   Hybrid : reserved for experiments.
  *   Computed : modification authorization matches CheckEdit answer
  */
  enum CATPLMDefaultEditStatus { ReadOnly, ReadWrite, Hybrid, Computed };

  /**
  * Describe the editability configuration of the session chosen by settings.
  * This is a list of restricted combinations of the tree other enum values.
  * <ul>
  *   FullEdit : (Warning, Optimistic, ReadWrite)
  *   Optimist : (Warning, Optimistic, ReadOnly)
  *   Pessimist : (Forbid, Pessimistic, ReadOnly)
  *   Pessimist_Relaxed : (Warning, Pessimistic, ReadOnly)
  *   Opportunist : (Forbid, Opportunistic, ReadOnly)
  *   Opportunist_Relaxed : (Warning, Opportunistic, Computed)
  * </ul>
  */
  enum CATPLMEditabilityConfiguration { FullEdit = 1, Optimist = 2, Pessimist = 3, Pessimist_Relaxed = 4, Opportunist = 5, Opportunist_Relaxed = 6 };

  /**
  * Retrieve the editability manager of the current session
  */
  static CATEditabilityManager& Get();

  /** obsolete, use CATEditabilityManager::Get or CATEditabilityManager::GetParameters()*/
  static inline CATEditabilityManager* GetEditabilityManager() { return &Get(); }

  /** obsolete, use GetParameters*/
  HRESULT GetEditabilityParameters(CATPLMEditabilityMode& oMode, CATPLMEditabilityStrategy& oStrategy, CATPLMDefaultEditStatus& oEditStatus);

  /**
   * retrieve current session editability parameters (the real ones that are actually used, not something from settings that might be used in next session)
   * @see CATEditabilityParameters
   */
  static CATEditabilityParameters GetParameters();

  /** do not use,
   * return configuration stored in some setting
   * does not reflect actual session configuration
   * this setting value can be unsynchronized with the setting that is really used
   */
  HRESULT GetEditabilityConfiguration(CATPLMEditabilityConfiguration& oEditConfiguration);

  //==============================================================================
  // all methods after this line are reserved to 
  //   * infrastructure 
  //   * settings UI
  //   * ODTs
  //===============================================================================
#if !defined(_WINDOWS_SOURCE) || defined (__CATOmbEditability) || defined (__CATImmVPMWintop) || defined (__CATVPMNavWintop) || defined (__OmbEditabilityTst)|| defined (__CATPLMTestAddIn) || defined(__CATPCTSwitchEditStatus)  || defined(__CATPLMTestAPI)

  /**
  * Get the editability configuration stored in settings (not necessarily the one currently used in session)
  */
  HRESULT GetEditabilityConfigurationFromSettings(CATPLMEditabilityConfiguration& oEditConfiguration);

  /**
  * change settings, does NOT change session configuration
  */
  HRESULT SetEditabilityConfigurationInSettings(CATPLMEditabilityConfiguration iEditConfiguration);
  /** broken, same behavior as SetEditabilityConfigurationInSettings*/
  HRESULT SetEditabilityConfiguration(CATPLMEditabilityConfiguration iEditConfiguration);

  /**
  * broken: does not do what was previsouly documented
  */
  HRESULT SwitchEditabilityConfiguration(CATPLMEditabilityConfiguration iEditConfiguration);

  HRESULT GetLock(char& oLock);
  HRESULT Lock();
  HRESULT Unlock();

#endif


#if !defined(_WINDOWS_SOURCE) || defined (__CATOmbEditability)|| defined (__OmbEditabilityTst) || defined (__CATPLMWorkspaceCmd) || defined (__CATLive3DInsightCmd) || defined(__CATPCTEditabilityTests)

  /**
  * Tries to Activate a new Editability Configuration at a DWS connection
  * @param iEditConfiguration
  *   The editability configuration to switch into
  * @return
  *      <ul>
  *         <li><tt>S_OK</tt> The switch succeeded, the new editability configuration will be taken into consideration</li>
  *         <li><tt>S_FALSE</tt> The editability configuration is already in that mode</li>
  *         <li><tt>E_FAIL</tt> The switch failed, the editablity configuration doesn't change</li>
  *      </ul>
  */
  HRESULT ActivateEditabilityMode(CATPLMEditabilityConfiguration iEditConfiguration);

  /**
  * Recovers the previous editability mode, the one before executing ActivateEditabilityMode()
  * @return
  *      <ul>
  *         <li><tt>S_OK</tt> The recovery succeeded</li>
  *         <li><tt>E_FAIL</tt> The recovery failed, an error occured or ActivateEditabilityMode() hasn't been executed before</li>
  *      </ul>
  *
  * NB: broken, editability status of components in session is not updated as it should
  */
  HRESULT DeactivateEditabilityMode();

#endif

  //Editability behavior when creating components in database
  //meaningful only in "Pessimistic" mode
  enum BehaviorForNewComponents
  {
    DoNothingAfterSave = 0,       //legacy behavior, components remain editable although not locked on server
    RecomputeStatusAfterSave = 1, //editability is recomputed after save (as a consequence saved component become "by default" ReadOnly)
    ReserveAfterSave = 2          //new components are reserved in database after being saved
  };
  CATEditabilityManager::BehaviorForNewComponents GetBehaviorForNewComponents() const;
  void SetBehaviorForNewComponents(CATEditabilityManager::BehaviorForNewComponents iBehavior);

private:
  friend class CATPCTSwitchEditStatus;
  friend class CATSession;

  CATEditabilityManager();
  ~CATEditabilityManager();

  /**
  * Delete the editability manager
  */
  static void DeleteEditabilityManager();

  CATEditabilityManager(const CATEditabilityManager&);  // not implemented
  CATEditabilityManager& operator=(const CATEditabilityManager&);   // not implemented

  /**
  * Says whether switch editability will have immediate effect or the user will be obliged to relaunch its session
  * @param iEditConfiguration
  *    The Editability Configuration to switch to
  * @return
  *   S_OK    : Switch Editability has immediate effect without relaunching the session
  *   E_FAIL  : The user must restart its session so the new editability configuration is taken into consideration.
  */
  HRESULT SwitchEditabilityIsImmediate();

  CATPLMEditabilityConfiguration m_configuration, m_settingsConfiguration, m_configurationBackup;
  CATBoolean m_SwitchByDWS;
};

typedef CATEditabilityManager::CATPLMEditabilityMode CATPLMEditabilityMode;
typedef CATEditabilityManager::CATPLMEditabilityStrategy CATPLMEditabilityStrategy;
typedef CATEditabilityManager::CATPLMDefaultEditStatus CATPLMDefaultEditStatus;
typedef CATEditabilityManager::CATPLMEditabilityConfiguration CATPLMEditabilityConfiguration;

/** struct containing all informations on editability "configuration"*/
struct CATEditabilityParameters
{
#ifdef _WINDOWS_SOURCE
#pragma pack(push,1) 
#endif
  // editability configuration: FullEdit, Pessimist etc...
  CATPLMEditabilityConfiguration Configuration : 8;
  // the three following fields are deduced from configuration
  CATPLMEditabilityMode Mode : 8; // Forbid/Warning
  CATPLMEditabilityStrategy Strategy : 8; //  Pessimistic, Opportunistic, Optimistic
  CATPLMDefaultEditStatus DefaultEditStatus : 8; // ReadOnly/ReadWrite
#ifdef _WINDOWS_SOURCE
#pragma pack(pop) 
#endif
};

#endif
