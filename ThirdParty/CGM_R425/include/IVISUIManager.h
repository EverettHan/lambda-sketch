// COPYRIGHT DASSAULT SYSTEMES 2011

#ifndef IVISUIManager_H
#define IVISUIManager_H

#include "IVInterfaces.h"
#include "CATSysErrorDef.h"

#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"

#include "IVISUIScenario.h"
class IVISUIScenario;
class IVISUIScenario_var;
class CATSYPEventFactory;


/**
* Interface to manage SUI Elements.
* <strong>Role</strong>: The SUI Manager allows to instantiate, retrieve and release a @href IVISUIScenario 
*
* The SUI Manager is a singleton and its instance can be retrieved through the static method @href IVISUIManager#GetManager.
* The client does not have to take care of the lifecycle of the SUI Manager, since it is automatically handled by the iV component.
*
* Once retrieved, the SUI Manager can be used to set up any iV Scenarios desired by the user, by calling #RegisterScenario.
* You should keep the returned Scenario for later use, to call IVISUIScenario#Activate for example
*
* Once a scenario is retrieved, its Interaction Context and all the Elements it contains can be accessed in a straightforward way.
* Here is a code snippet demonstrating SUI element navigation and data retrieval.
* For simplicity's sake, we use signatures returning handlers. Pointer checks have been omitted.
*
* @example
* <pre>
* // In this example, the position of a marker relative to the camera is retrieved.
*
* // Get SUI Manager
* IVISUIManager* pSUIManager = IVISUIManager::GetManager();
*
* HRESULT rc = S_OK;
*
* // Register a Magic Window Scenario
* IVISUIScenarioMagicWindow_var hScenario = pSUIManager->RegisterScenario(IID_IVISUIScenarioMagicWindow);
*
* // Create a Marker and add it to the Scenario (see IVISUIScenarioMagicWindow)
*
* // ...
* // Later, when you are ready to launch your command
* //
*
* // Activate the Scenario on the desired viewer
* hr = hScenario->Activate(pViewer);
*
* //
* // Retrieve the position of the SUI Marker
* //
*
* // Retrieve first Interaction Context...
* IVISUIInteractionContext_var hContext = hScenario->GetInteractionContext();
*
* // ... then the description of the real world ...
* IVISUIPhysicalEnvironment_var hPhysEnv = hContext->GetPhysicalEnvironment();
*
* // ... and now the marker ...
* IVISUIMarker_var hMarker = hPhysEnv->GetMarker();
*
* // ... and its global pose in the virtual world
* CATMathTransformation virtualPose = hMarker->GetVirtualGlobalMatrix();
*
* // NOTE: You can ask to be called back on any SUI Entity using AddIVEventHandler
*
*
*
*  //
*  // Another basic example: parse Users and retrieve the position of the different parts of their body
*  //
*  
*  unsigned int nbUsers = 0;
*  nbUsers = hContext->GetUserCount();
*  IVISUIUser_var hUser = NULL_var;
*  for(unsigned int i=0; i<nbUsers; i++)
*  {
*     hUser = pContext->GetUser(i);
*
*     if(!!hUser)
*     {
*       // Get Dominant Hand Position
*       IVISUIHand_var hHand = pUser->GetDominantHand();
*       if(!!hHand)
*       {
*         CATMathTransformation handPose = hHand->GetPhysicalLocalMatrix();
*       }
*
*       // Get Head Position
*       IVISUIHead_var hHead = pUser->GetHead();
*       if(!!hHead)
*       {
*         CATMathTransformation headPose = hHead->GetPhysicalLocalMatrix();
*       }
*    } 
*  } // end of User loop
*
*
* </pre>
*
* @see IVISUIScenario, IVISUIInteractionContext, IVISUIPhysicalEnvironment, IVISUIUser, IVSUIEvents, AddIVEventHandler
*/
class ExportedByIVInterfaces IVISUIManager : public CATBaseUnknown
{

   CATDeclareClass;

public:

 /** 
  * Retrieves the unique @href IVISUIManager instance.
  *
  * @return
  *     The @href IVISUIManager instance.
  *
  * <br><strong>Lifecycle rules deviation</strong>:
  * The @href IVISUIManager is a Singleton. Its lifecycle is automatically handled by the iV framework. 
  * The returned pointer should never be <tt>NULL</tt>, and the caller should <strong>never</strong> try and delete it.
  */
  static IVISUIManager* GetManager();
  
 /** 
  * Creates an instance of a @href IVISUIScenario using a specific configuration file.
  * Once you have finished using the Scenario, call #UnregisterScenario
  *
  * @param iIVISUIScenario [in]
  *     The IID corresponding to the interface of the requested scenario
  *
  * @param iIVSUIScenarioConfigurationFile [in]
  *     The path to the xml file describing the configuration.
  *      If left empty, the scenario will be initialized using the default configuration.
  *
  * @return
  *      A handler to the @href IVISUIScenario instance.
  */
  virtual IVISUIScenario_var RegisterScenario(const IID& iIVISUIScenario, const CATUnicodeString& iIVSUIScenarioConfigurationFile = CATUnicodeString("")) = 0;

  /**
   * Register the given  @href IVISUIScenario
   * Once you have finished using the Scenario, call #UnregisterScenario
   *
   * @param iScenario
   *     The scenario to register
   * 
   * @return 
   *     S_OK if succeeded. E_FAIL otherwise.
   */
  virtual HRESULT RegisterScenario(IVISUIScenario_var iScenario) = 0;


  /** 
   *  Unregisters an instance of a @href IVISUIScenario
   *  Call this method when you do no longer need to use a scenario.
   *
   * @param iIVISUIScenario [in]
   *     A handler to the scenario to unregister
   */
   virtual HRESULT UnregisterScenario(IVISUIScenario_var& iIVISUIScenario) = 0;

  /**
   *  Listens to a scenario of a certain type being activated or deactivated.
   *  This doesn't require the user having a handle on a precise scenario.
   *  Use RemoveScenarioListener (see below) afterward.
   *
   * @param iIVISUIScenario [in]
   *     The type of scenario to listen, such as IID_IVISUIScenarioMultipipe.
   * @param iHandler [in]
   *     A handler linked to a callback : when a scenario of the correct type is activate or deactivated,
   *     this callback will be called, with a IVScenarioEvtArgs that will contain the state of the scenario (IV_ACTIVATED or IV_DEACTIVATED).
   */
  virtual void AddScenarioListener(const IID& iIVISUIScenario, CATSYPEventHandler* iHandler) = 0;

  /**
   *  Stops listening to a scenario of a certain type being activated or deactivated.
   *
   * @param iIVISUIScenario [in]
   *     The type of scenario to listen, such as IID_IVISUIScenarioMultipipe.
   * @param iHandler [in]
   *     The handler that was used in the call to AddScenarioListener.
   */
  virtual void RemoveScenarioListener(const IID& iIVISUIScenario, CATSYPEventHandler* iHandler) = 0;

  //
  // END OF PUBLIC API
  //

 /**
  * @nodoc
  * Internal use only.
  */
 virtual bool IsScenarioRegistered(const IID& iIVISUIScenario) = 0;

 /** 
  * @nodoc
  * Internal use only.
  */
  virtual unsigned int GetScenarioCount() const = 0;
  virtual HRESULT GetScenarioCount(unsigned int& oNbScenarii) const = 0;
  virtual HRESULT GetScenario(const unsigned int iScenarioIndex, IVISUIScenario*& oScenario) const = 0;
  virtual IVISUIScenario_var FindScenarioByIID(IID const& iScenarioIID) = 0;

 /**
  * @nodoc 
  * Retrieves the unique @href CATSYPEventFactory instance.
  */
  static CATSYPEventFactory* GetEventFactory();

 /**
  * @nodoc
  * Internal use only.
  * @param oSUIScenario [out, IUnknown#Release] 
  * Should only be called by IVScheduler.
  */
  virtual HRESULT RunTask() = 0;


protected:
  // Instantiation not allowed
  /** @nodoc */
  IVISUIManager();
  /** @nodoc */
  virtual ~IVISUIManager();

  virtual CATSYPEventFactory* GetSUIEventFactory() = 0;

private:
  // Copy not allowed
  /** @nodoc */
  IVISUIManager(const IVISUIManager&);
  /** @nodoc */
  IVISUIManager& operator=(const IVISUIManager&);
};

#endif
