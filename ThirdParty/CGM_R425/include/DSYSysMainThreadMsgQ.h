/**
 * @author ik8
 * @fullreview  ik8         13:04:23
 * @quickreview ik8         13:05:31
 */
 
#ifndef DSYSysMainThreadMsgQ_H
#define DSYSysMainThreadMsgQ_H

// COPYRIGHT DASSAULT SYSTEMES 2013

/****************************************************************************/
/* Includes                                                                 */
/****************************************************************************/
#include "CATSysMainThreadMQ.h"
#include "JS0CORBA.h"
#include "CATApplication.h"
#include "DSYSysRefCounter.h"
#include "DSYSysSharedPtr.hpp"
#include "CATSysTSDataType.h"

/****************************************************************************/
/* Defines                                                                  */
/****************************************************************************/
//#define _DSYSysMainThreadMsgQ_DEBUG

/****************************************************************************/
/* Declarations                                                             */
/****************************************************************************/
ExportedByJS0CORBA const char* AddStringInDico(const char *, short = 1);

/**
* DSYSysMainThreadMsgQ is an API that allows worker threads to communicate 
* with the process's main thread. This communication is based on a combination 
* of user-defined callbacks and messages. As a typical use case, the user 
* first registers a callback on a particular message type from the main thread. 
* Once it has been done, each time a worker thread posts a message of this 
* type, the main thread then executes the registered callback(s).
* 
* CAUTION: using this API makes sense only in the context of an interactive 
* application (class CATInteractiveApplication). For this API to work properly,
* one has to ensure that the Instance member function is first called from 
* the main thread.
*/

class ExportedByCATSysMainThreadMQ DSYSysMainThreadMsgQ
{
public:
    
    /**
    * Message is the base class for user defined messages. Each type of 
    * message is identified by its class name as C-style string. This type 
    * can be retrieved from any instance by calling the GetType member 
    * function or by refering to the static member "Type".
    * Derived classes must be declared using the macro 
    * DSYSysMainThreadMsgQMessageDecl and they must be defined using the 
    * macro DSYSysMainThreadMsgQMessageImpl.
    * Message instanciation is managed by the static member function Create.
    *
    * LIFECYCLE:
    * From the time a message is posted, its lifecycle is managed by the API, 
    * meaning that the sender is free to release its pointer (either manually 
    * or automatically through the use of a smart pointer).
    * COROLLARY: once all required callbacks have been called for a message,
    * it is automatically released.
    */
         
    #define DSYSysMainThreadMsgQMessageDecl(ClassName)                      \
    public:                                                                 \
        static const char *Type;                                            \
        static DSYSysSharedPtr<ClassName> Create();                         \
    private:                                                                \
        ClassName();
        
    #define DSYSysMainThreadMsgQMessageImpl(ClassName)                      \
        const char *ClassName::Type = #ClassName;                           \
        DSYSysSharedPtr<ClassName> ClassName::Create()                      \
        {                                                                   \
            ClassName *msg = new ClassName();                               \
            DSYSysSharedPtr<ClassName> spMsg(msg);                          \
            msg->Release();                                                 \
            spMsg->Message::SetType(#ClassName);                            \
            return spMsg;                                                   \
        }                                                                   \

    class Message : public DSYSysRefCounter
    {
        const char *_type;
        friend class MsgQInternalCBDispatcher;
    protected:
        // DO NOT CALL
        inline Message() : DSYSysRefCounter(), _type(NULL) { }
        inline void SetType(const char *iMsgType);
    public:
        inline const char *GetType() { return _type; }
        inline virtual ~Message() { }
#ifdef _DSYSysMainThreadMsgQ_DEBUG
        inline CATINT32 AddRef();
        inline CATINT32 Release();
#endif
    };

    /**
    * Callback is the base class for user defined callback objects.
    * Derived classes must override the operator () to implement a custom 
    * callback behavior.
    *
    * LIFECYCLE:
    * From the time a Callback instance is registered into the API, its 
    * lifecycle is automatically managed. This means that the user is free to 
    * release its pointer to the instance. However, one might want to keep 
    * track of a particular instance to be able to unregister it later on.
    */    
    class Callback : public DSYSysRefCounter
    {
    public:
        inline Callback() : DSYSysRefCounter() { }
        inline virtual ~Callback() { }
        virtual void operator() ( 
            DSYSysSharedPtr<DSYSysMainThreadMsgQ::Message> ) = 0;
#ifdef _DSYSysMainThreadMsgQ_DEBUG
        inline CATINT32 AddRef();
        inline CATINT32 Release();
#endif
    };
    
    /************************************************************************/
    /* WARNING: below member functions are to be called from main thread    */
    /* only. Failure to comply with this requirement may lead to undefined  */
    /* behavior.                                                            */
    /************************************************************************/

    /**
    * RegisterCB allows to register a Callback instance on a particular 
    * message type.
    * NB: a single Callback instance can be registered for several message 
    * types by calling this service once for each of them.
    * 
    * @param [in] iCallbackObj is a pointer to a user defined Callback object.
    * @param [in] iMsgType is the message type for which iCallbackObj is to be
    * registered (formatted as a C-style string).
    *
    * @retval S_OK upon success.
    * @retval S_FALSE if iCallbackObj has already been registered.
    * @retval E_FAIL upon failure (most likely due to invalid input).
    */
    HRESULT RegisterCB (
        DSYSysSharedPtr<Callback> iCallbackObj, const char *iMsgType);
 
    /**
    * UnregisterCB allows to unregister a Callback instance from a particular 
    * message type.
    * 
    * @param [in] iCallbackObj is a pointer to a user defined Callback object.
    * @param [in] iMsgType is the message type for which iCallbackObj is to be 
    * unregistered (formatted as a C-style string).
    *
    * @retval S_OK upon success.
    * @retval E_FAIL upon failure (callback was not registered or input is 
    * invalid).
    */
    HRESULT UnregisterCB(
        DSYSysSharedPtr<Callback> iCallbackObj, const char *iMsgType);
    
    /************************************************************************/
    /* THREAD-SAFE SECTION                                                  */                        
    /************************************************************************/
        
    /**
    * Post provides a way for worker threads to notify the main thread of some
    * event through user defined messages.
    * 
    * @param [in] iMsg is a pointer to a Message instance that is to be 
    * transmitted to all registered callbacks.
    * NB: if multiple callbacks are registered on a same type of message, 
    * the order in which they will be invoked is not specified.
    *
    * @retval S_OK upon success.
    * @retval E_FAIL upon failure. One might consider to plan a retry at a 
    * later point.
    */
    HRESULT Post(DSYSysSharedPtr<Message> iMsg);

    /**
    * Instance member function allows to retrieve a pointer to the 
    * DSYSysMainThreadMsgQ singleton (which has a session lifetime).
    * 
    * IMPORTANT: instead of checking the validity of the return value for each
    * call, one should just ensure that the initialization rules described 
    * above were applied.
    *
    * @retval pointer to the DSYSysMainThreadMsgQ singleton upon success.
    * @retval NULL otherwise (an initialization error occured).
    */
    static DSYSysMainThreadMsgQ *Instance();
 
private:
    DSYSysMainThreadMsgQ ();
    ~DSYSysMainThreadMsgQ();
    DSYSysMainThreadMsgQ(const DSYSysMainThreadMsgQ &);
    DSYSysMainThreadMsgQ& operator= (const DSYSysMainThreadMsgQ &iSrc);
    
    static void OnMessageReceived(void *);
    void DispatchMessage(void *);
    void UnregisterAllCB();
    
    // Initialization routines
    static DSYSysMainThreadMsgQ *CreateDSYSysMainThreadMsgQ();
    HRESULT Init();
    HRESULT DeInit();
    static int DeInitMainThreadMsgQ(int);
    
    // Members
    void                          * _data;
    static DSYSysMainThreadMsgQ   * _singleton;
};


// INLINE DEFINITIONS
inline void DSYSysMainThreadMsgQ::Message::SetType(const char *iMsgType) 
{
    if(iMsgType)
        _type = AddStringInDico(iMsgType); 
}

#ifdef _DSYSysMainThreadMsgQ_DEBUG
inline CATINT32 DSYSysMainThreadMsgQ::Message::AddRef()
{ 
    CATINT32 newRef = DSYSysRefCounter::AddRef();
    return newRef;
}
inline CATINT32 DSYSysMainThreadMsgQ::Message::Release() 
{ 
    CATINT32 newRef = DSYSysRefCounter::Release(); 
    return newRef;
}
inline CATINT32 DSYSysMainThreadMsgQ::Callback::AddRef()
{ 
    CATINT32 newRef = DSYSysRefCounter::AddRef();
    return newRef;
}
inline CATINT32 DSYSysMainThreadMsgQ::Callback::Release() 
{ 
    CATINT32 newRef = DSYSysRefCounter::Release(); 
    return newRef;
}
#endif

#endif  // DSYSysMainThreadMsgQ_H
