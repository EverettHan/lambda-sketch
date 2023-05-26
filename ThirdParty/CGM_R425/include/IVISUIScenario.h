#ifndef IVISUIScenario_H
#define IVISUIScenario_H

// COPYRIGHT DASSAULT SYSTEMES 2011

/**
* @CAA2Level L0
* @CAA2Usage U1
*/

#include "IVInterfaces.h"
#include "CATBaseUnknown.h"
#include "CATCollec.h"
#include "IVISUICollection.h"

class CATUnicodeString;
class CATVizViewer;
class IVISUIInteractionContext;
class IVISUIInteractionContext_var;
class IVISUIBehaviour;
class IVISUIBehaviour_var;
class IVIDeviceHandle;
class IVIDeviceHandle_var;
class IVISUIInteraction;
class IVISUIDeviceMappings_var;
class CATSYPEvent;
class CATSYPEventHandler;
class CATSYPEventArgs;

extern ExportedByIVInterfaces IID IID_IVISUIScenario;

/**
* Interface representing an Immersive Virtuality Scenario.
*
* <strong>Role</strong>: A Scenario is a high-level all-in-one interface abstracting an iV Experience.
* Each Scenario instantiates a predefined SUI Model, which is updated by iV Devices, to make the User live an iV Experience.
* A Scenario captures an interaction use-case. Therefore, after activating a Scenario,
* the User must follow the Script of the Scenario, i.e. the interaction guidelines underlying each Scenario,
* to maximize the effects of the Experience.
*
* To provide access to a Scenario all you need to do is register the Scenario you wish to expose by calling IVISUIManager#Register as early in your code as possible.
* Keep the returned Scenario at hand for later use.
* Then, in order to run the Scenario, simply call #Activate.
* If you need to retrieve information on the SUI Model being updated by the Scenario, you can access it by calling #GetInteractionContext to retrieve the root of the SUI Model.
*
* @see IVISUIManager, IVISUIUser, IVISUIInteractionContext
*/
class ExportedByIVInterfaces IVISUIScenario : public CATBaseUnknown
{

  CATDeclareInterface;

public: 

  /**
  * Get the Scenario name.
  *
  * @return
  *   The Scenario name.
  */
  virtual CATUnicodeString GetName() = 0;

  /**
  * @nodoc
  * Activate the Scenario.
  *
  * The Scenario must have been reigstered using IVISUIManager#Register before calling this method.
  *
  * @param iViewer [in]
  *   The Viewer on which to Run the Scenario.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The activation succeeded</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The activation failed</dd>
  *   </dl>
  */
  virtual HRESULT Activate(CATVizViewer* iViewer) = 0;

  /**
  * @nodoc
  * Deactivate the Scenario.
  *
  * The Scenario must have been reigstered using IVISUIManager#Register before calling this method.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The deactivation succeeded</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The deactivation failed</dd>
  *   </dl>
  */
  virtual HRESULT Deactivate() = 0;

  /**
  * Get the Scenario status.
  *
  * @return
  *   1 if the Scenario is activated.
  */
  virtual unsigned int IsActive() = 0;

  /**
  * @nodoc
  * Internal use only.
  */
  virtual HRESULT Validate() = 0;

  /**
  * @nodoc
  * Get the Viewer.
  *
  * @return
  *   The Viewer on which the Scenario is running.
  */
  virtual CATVizViewer* GetVizViewer() = 0;

  /**
  * Get the Interaction Context containing the SUI elements.
  * 
  * @param oContext [out, IUnknown#Release] 
  *   The Interaction Context used for the Scenario.
  *
  * @return
  *   An HRESULT value.
  *   <br><strong>Legal values</strong>:
  *   <dl>
  *     <dt>S_OK</dt>
  *     <dd>The requested <tt>oContext</tt> is successfully retrieved</dd>
  *     <dt>E_FAIL</dt>
  *     <dd>The requested <tt>oContext</tt> could not be retrieved</dd>
  *   </dl>
  */
  virtual HRESULT GetInteractionContext(IVISUIInteractionContext*& oContext) const = 0;

  /**
  * Get the Interaction Context containing the SUI elements.
  *
  * @return
  *   The Interaction Context used for the Scenario.
  */
  virtual IVISUIInteractionContext_var GetInteractionContext() const = 0;

  /**
  * @nodoc
  * Internal use only.
  * Get the count of Devices used for the Scenario.
  *
  * @return
  *   The Devices count.
  */
  virtual unsigned GetDeviceCount() const = 0;

  /**
  * @nodoc
  * Internal use only.
  * Get one of the Devices used for the Scenario.
  *
  * @return
  *   The Device.
  */
  virtual IVIDeviceHandle_var GetDevice(unsigned iIndex) const = 0;

  /**
  * @nodoc
  * Internal use only.
  * Get the list of Devices as a CATLISTP(IVIDeviceHandle).
  *
  * @param oDevicesList [out]
  *   The Devices list used for the Scenario.
  */
  virtual void GetListDevices(CATLISTP(IVIDeviceHandle)& oDevicesList) const = 0;

  /**
  * @nodoc
  * Internal use only.
  * Get the mapping of Devices on interactions.
  *
  * @param oDeviceMappings [out]
  *   The Devices mapping used for the Scenario.
  */
  virtual void GetDeviceMappings(IVISUIDeviceMappings_var& oDeviceMappings) const = 0;

  /**
  * @nodoc
  * Internal use only.
  * Get the the list of applicative commands Behaviours as a CATLISTP(IVISUIBehaviour).
  *
  * @param oBehavioursList [out]
  *   The applicative commands Behaviours used during the Scenario.
  */
  virtual void GetApplicativeCommandsBehaviours(CATLISTP(IVISUIBehaviour)& oBehavioursList) const = 0;

  /** 
  * @nodoc
  * Internal use only.
  * Get the applicative commands Behaviours.
  *
  * @param oBehaviour [out]
  *   The applicative commands Behaviour retrieved by its name.
  *
  * @param iCommandName [in]
  *   The applicative commands Behaviour name.
  */
  virtual void GetApplicativeCommandsBehaviour(IVISUIBehaviour_var& oBehaviour, const CATUnicodeString& iCommandName) const = 0;

  /** 
  * @nodoc
  * Internal use only.
  * Get the Interactions definition
  *
  * @param oInteractionsList [out]
  *   The Interactions used during the scenario.
  */
  virtual void GetListInteractions(CATLISTP(IVISUIInteraction)& oInteractionsList) const = 0;

  /** 
  * Add callbacks on events sent by the Scenario on activation/deactivation.
  * @see IVSUIScenarioEvents
  *
  * @param iEvent [in]
  *   The Event to listen to, such as IVScenarioEvents::IVScenarioChanged()
  * @param iHandler [in]
  *   The Event Handler to use.
  * @param i
  *   The parameter i is ignored. The events are never consumed.
  *   This parameter is available so that you can use AddCATSYPWRefMethEventHandler
  * @return
  *   1 if succeeded
  */
  virtual int AddScenarioEventHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler, int i = 1) = 0;

  /** 
  * Remove callbacks on events sent by the Scenario on activation/deactivation.
  * @see IVSUIScenarioEvents
  *
  * @param iEvent [in]
  *   The Event to listen to, such as IVScenarioEvents::IVScenarioChanged()
  * @param iHandler [in]
  *   The Event Handler to remove.
  * @return
  *   1 if succeeded
  */
  virtual int RemoveScenarioEventHandler(CATSYPEvent* iEvent, CATSYPEventHandler* iHandler) = 0;
};

CATDeclareHandler(IVISUIScenario, CATBaseUnknown);

#endif
