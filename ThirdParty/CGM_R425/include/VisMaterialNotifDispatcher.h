
#ifndef __VisMaterialNotifDispatcher_h__
#define __VisMaterialNotifDispatcher_h__

#include "SGInfra.h"
#include <list>
#include <unordered_set>
#include <functional>
#include <mutex>
#include <shared_mutex>

class CATGraphicMaterial;
class VisMaterialApplication;
class CATNotification;


class ExportedBySGInfra VisMaterialNotifDispatcher
{
public: 
  class ExportedBySGInfra Subscriber
  {
  public:
    Subscriber();    
    ~Subscriber();

    // Subscribe to the events sent when a 'CATGraphicMaterial' or a 'VisMaterialApplication' is modified.
    
    // Subscribe to all events related to all 'CATGraphicMaterial' instances.
    void SubscribeForAllMaterialUpdates();

    // Subscribe to all events related to all 'VisMaterialApplication' instances.
    void SubscribeForAllMaterialApplicationUpdates();

    // Subscribe to the events related to a given 'CATGraphicMaterial'.
    void SubscribeForMaterialUpdates(const CATGraphicMaterial* iMaterial);
    void UnsubscribeForMaterialUpdates(const CATGraphicMaterial* iMaterial);

    // Subscribe to the events related to a given 'VisMaterialApplication'.
    void SubscribeForMaterialApplicationUpdates(const VisMaterialApplication* iMaterialApplication);
    void UnsubscribeForMaterialApplicationUpdates(const VisMaterialApplication* iMaterialApplication);

    // Unsubscribe to all events, related to all 'CATGraphicMaterial' and 'VisMaterialApplication' instances.
    void UnsubscribeForAllUpdates();

    //
    // Notifications: these are sent by 'MaterialHubs' every time a 'CATGraphicMaterial' or a 'VisMaterialApplication'
    // is updated or deleted. Override the following functions to be notified.
    //
    // The implementations of the overriden functions *must be thread-safe*. Each of these functions
    // can be called simultaneously by several threads.

    virtual void OnMaterialCreated(CATGraphicMaterial* iGraphicMaterial) { }
    virtual void OnMaterialApplicationCreated(VisMaterialApplication* iMaterialApplication) { }

    virtual void OnMaterialUpdated(CATGraphicMaterial* iGraphicMaterial, const CATNotification* iNotification) { }
    virtual void OnMaterialApplicationUpdated(VisMaterialApplication* iMaterialApplication, const CATNotification* iNotification) { }

    // Unregistration is automatic when a material is deleted (do not call 'UnregisterForMaterialUpdates'
    // or 'UnregisterForMaterialApplicationUpdates').
    virtual void OnMaterialDeleted(CATGraphicMaterial* iGraphicMaterial) { }
    virtual void OnMaterialApplicationDeleted(VisMaterialApplication* iMaterialApplication) { }

    // End of the functions to be overriden.
  };

  // TBD: this is a singleton, but it should not be. There should be a 'VisMaterialNotifDispatcher' for each view point
  // (like there is a 'vREMaterialPool' for each view point).
  
  static VisMaterialNotifDispatcher& GetInstance();  
  
  // The following functions transfer the notifications to the receivers.

  void MaterialCreated(CATGraphicMaterial* iMaterial);
  void MaterialApplicationCreated(VisMaterialApplication* iMaterialApplication);
  
  void MaterialUpdated(CATGraphicMaterial* iGraphicMaterial, const CATNotification* iNotification);
  void MaterialApplicationUpdated(VisMaterialApplication* iMaterialApplication, const CATNotification* iNotification);

  // This unregister the material or the material application from all receivers.
  
  void MaterialDeleted(CATGraphicMaterial* iGraphicMaterial);
  void MaterialApplicationDeleted(VisMaterialApplication* iMaterialApplication);

  //
  // The following functions are called by 'VisMaterialNotifDispatcher::Subscriber'.
  //

  void RegisterSubscriber(Subscriber* iSubscriber);
  void UnregisterSubscriber(const Subscriber* iSubscriber);  

  // For the following functions, the 'VisMaterialNotifDispatcher::Subscriber' must have been previously registered 
  // by calling 'RegisterSubscriber'.

  void SubscribeForAllMaterialUpdates(const Subscriber* iSubscriber);
  void SubscribeForAllMaterialApplicationUpdates(const Subscriber* iSubscriber);
  void UnsubscribeForAllUpdates(const Subscriber* iSubscriber);

  void SubscribeForMaterialUpdates(const Subscriber* iSubscriber, const CATGraphicMaterial* iMaterial);
  void UnsubscribeForMaterialUpdates(const Subscriber* iSubscriber, const CATGraphicMaterial* iMaterial);
  void SubscribeForMaterialApplicationUpdates(const Subscriber* iSubscriber, const VisMaterialApplication* iMaterialApplication);
  void UnsubscribeForMaterialApplicationUpdates(const Subscriber* iSubscriber, const VisMaterialApplication* iMaterialApplication);

  //
  // End of the functions called by 'VisMaterialNotifDispatcher::Subscriber'.
  //

private:  
  static VisMaterialNotifDispatcher* instance_;
  static std::mutex instanceMutex_;

  // This structures associates a 'Subscriber' with the list of the 'CATGraphicMaterial' and
  // 'VisMaterialApplication' instances it has subsribed to.

  struct RegisteredSubscriber
  {
    Subscriber* subscriber;
    std::unordered_set<const CATGraphicMaterial*> catGraphicMaterials;
    std::unordered_set<const VisMaterialApplication*> visMaterialApplications;
    bool registeredForAllMaterialUpdates;
    bool registeredForAllMaterialApplicationUpdates;
    
    std::unordered_set<const CATGraphicMaterial*>::iterator FindMaterial(const CATGraphicMaterial* iGraphicMaterial);
    std::unordered_set<const CATGraphicMaterial*>::const_iterator FindMaterial(const CATGraphicMaterial* iGraphicMaterial) const;
    bool IsRegisteredForMaterial(const CATGraphicMaterial* iGraphicMaterial) const;

    std::unordered_set<const VisMaterialApplication*>::iterator FindMaterialApplication(const VisMaterialApplication* iMaterialApplication);
    std::unordered_set<const VisMaterialApplication*>::const_iterator FindMaterialApplication(const VisMaterialApplication* iMaterialApplication) const;
    bool IsRegisteredForMaterialApplication(const VisMaterialApplication* iVisMaterialApplication) const;

    void UnregisterMaterial(const CATGraphicMaterial* iGraphicMaterial);
    void UnregisterMaterialApplication(const VisMaterialApplication* iVisMaterialApplication);

    RegisteredSubscriber() = delete;
    RegisteredSubscriber(Subscriber* receiver);    
    RegisteredSubscriber(const RegisteredSubscriber&) = default;
    RegisteredSubscriber(RegisteredSubscriber&&) = default;
    RegisteredSubscriber& operator = (const RegisteredSubscriber&) = default;
  };

  // The list of all the receivers that are registered.
  
  std::list<RegisteredSubscriber> subscribers_;

  std::list<RegisteredSubscriber>::iterator FindSubscriber(const Subscriber* iSubscriber);
  std::list<RegisteredSubscriber>::iterator FindExistingSubscriber(const Subscriber* iSubscriber);

  // The list 'receivers_' is being accessed.
  std::shared_mutex subscribersListMutex_;

  VisMaterialNotifDispatcher();
  VisMaterialNotifDispatcher(const VisMaterialNotifDispatcher&) = delete;
  VisMaterialNotifDispatcher& operator = (const VisMaterialNotifDispatcher&) = delete;

  // Utility functions for the implementation.

  void ApplyToSubscribers(std::function<bool(RegisteredSubscriber&)> iFilter,
                        std::function<void(RegisteredSubscriber&)> iFunction);
  
  void ApplyMaterialChangeToSubscribers(CATGraphicMaterial* iGraphicMaterial,
                                      std::function<void(RegisteredSubscriber&)> iFunction);

  void ApplyMaterialApplicationChangeToSubscribers(VisMaterialApplication* iMaterialApplication,
                                                   std::function<void(RegisteredSubscriber&)> iFunction);

  void ApplyToRegisteredSubscriber(const Subscriber* iSubscriber,
                                 std::function<void(RegisteredSubscriber&)> iFunction);
};

#endif // __VisMaterialNotifDispatcher_h__
