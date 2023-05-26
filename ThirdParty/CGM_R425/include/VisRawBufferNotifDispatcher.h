#ifndef __VisRawBufferNotifDispatcher_h__
#define __VisRawBufferNotifDispatcher_h__

#include "SGInfra.h"

#include <list>
#include <mutex>
#include <shared_mutex>
#include <unordered_set>
#include <functional>

class VisRawBuffer;

class ExportedBySGInfra VisRawBufferNotifDispatcher
{
public:
    class ExportedBySGInfra Subscriber
    {
    public:
        Subscriber();
        ~Subscriber();

        // Suscribe to all events related to all 'VisRawBuffer' instances (creation, moditication, deletion)
        void SubscribeForAllUpdates();

        // Unsubscribe to all events, related to all 'VisRawBuffer' instances.
        void UnsubscribeForAllUpdates();

        // The implementations of the overriden functions *must be thread-safe*. Each of these functions
        // can be called simultaneously by several threads.
        virtual void OnVisRawBufferCreated(VisRawBuffer* iVisRawBuffer) { }
        virtual void OnVisRawBufferUpdated(VisRawBuffer* iVisRawBuffer) { }
        virtual void OnVisRawBufferDeleted(VisRawBuffer* iVisRawBuffer) { }
    };

    static VisRawBufferNotifDispatcher& GetInstance();

    // The following functions transfer the notifications to the receivers.
    void VisRawBufferCreated(VisRawBuffer* iVisRawBuffer);
    void VisRawBufferUpdated(VisRawBuffer* iVisRawBuffer);
    void VisRawBufferDeleted(VisRawBuffer* iVisRawBuffer);

    //
    // The following functions are called by 'VisRawBufferNotifDispatcher::Subscriber'.
    //
    void RegisterSubscriber(Subscriber* iSubscriber);
    void UnregisterSubscriber(const Subscriber* iSubscriber);

    void SubscribeForAllUpdates(const Subscriber* iSubscriber);
    void UnsubscribeForAllUpdates(const Subscriber* iSubscriber);
    //
    // End of the functions called by 'VisRawBufferNotifDispatcher::Subscriber'.
    //

private:
    // This structures associates a 'Subscriber' with the list of the 'CATGraphicMaterial' and
    // 'VisMaterialApplication' instances it has subsribed to.

    struct RegisteredSubscriber
    {
        Subscriber* subscriber;
        bool registeredForAlllUpdates;

        bool IsRegisteredForVisRawBuffer(const VisRawBuffer* iVisRawBuffer) const;

        RegisteredSubscriber() = delete;
        RegisteredSubscriber(Subscriber* receiver);
        RegisteredSubscriber(const RegisteredSubscriber&) = default;
        RegisteredSubscriber(RegisteredSubscriber&&) = default;
        RegisteredSubscriber& operator = (const RegisteredSubscriber&) = default;
    };

    std::list<RegisteredSubscriber>::iterator FindSubscriber(const Subscriber* iSubscriber);
    std::list<RegisteredSubscriber>::iterator FindExistingSubscriber(const Subscriber* iSubscriber);

    VisRawBufferNotifDispatcher();
    VisRawBufferNotifDispatcher(const VisRawBufferNotifDispatcher&) = delete;
    VisRawBufferNotifDispatcher& operator = (const VisRawBufferNotifDispatcher&) = delete;

    void ApplyToSubscribers(std::function<bool(RegisteredSubscriber&)> iFilter,
        std::function<void(RegisteredSubscriber&)> iFunction);

    void ApplyVisRawBufferChangeToSubscribers(VisRawBuffer* iVisRawBuffer,
            std::function<void(RegisteredSubscriber&)> iFunction);

    void ApplyToRegisteredSubscriber(const Subscriber* iSubscriber,
        std::function<void(RegisteredSubscriber&)> iFunction);

private: 
    static VisRawBufferNotifDispatcher* instance_;
    static std::mutex instanceMutex_;

    // The list 'receivers_' is being accessed.
    std::shared_mutex subscribersListMutex_;

    // The list of all the receivers that are registered.
    std::list<RegisteredSubscriber> subscribers_;
};

#endif // __VisRawBufferNotifDispatcher_h__
