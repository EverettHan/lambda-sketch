#ifndef __CATOmxEvent_h__
#define __CATOmxEvent_h__
#include <CATOmxPortability.h>
#include <CATOmxKernel.h>
#include <CATOmxAny.h>
#include <CATOmxOMap.h>
#include <CATOmxMapIter.h>
#include <CATOmxIter.h>
#include <CATOmxVector.h>
#include <CATOmxKeyString.h>
#include "CATOmxKeyValueBlock.h"
#include "CATOmxSharable.h"

typedef unsigned long long CATOmxEventId  ;
/** meta event signaling add of a new source. */
#define OMX_ADDSOURCE 1
/** meta event signaling add of a new event. */
#define OMX_ADDEVENT  2 
/** meta event when a logerr message is send. */
#define OMX_LOGERR   3 
/** compute 2**n of an unsigned long long .*/
#define OMX_POW2ULL(n) (1ULL<<(n))
/** @deprecated use OMX_TWEET instead.*/
#define OMX_EMIT(evtsource,evtid,args) \
 { const CATOmxEventSource &omx_emit_source(evtsource); \
    if(( omx_emit_source.emit_mask & (OMX_POW2ULL(evtid))))  \
     { \
      omx_emit_source.Emit(evtid) args .Commit() ; \
   } \
}

/**
 * Use this macro to emit an event.
 * @param evtsource reference to the event_source
 * @param evtid the event ordinal
 * @param ... list of parameter to add in info
 */
#define OMX_TWEET(evtsource,evtid, ... ) \
 { const CATOmxEventSource &omx_emit_source(evtsource); \
    if(( omx_emit_source.emit_mask & (OMX_POW2ULL(evtid))))  \
     { \
      CATOmxEventContext &ctx__  =omx_emit_source.Emit(evtid); \
      ctx__ , __VA_ARGS__; \
      ctx__.Commit() ; \
   } \
}
/** 
 * Use this macro to emit an event without any context.
 * @param evtsource reference to the event_source
 * @param evtid the event ordinal
 */
#define OMX_TWEET0(evtsource,evtid) \
 { const CATOmxEventSource &omx_emit_source(evtsource); \
    if(( omx_emit_source.emit_mask & (OMX_POW2ULL(evtid))))  \
     { \
      omx_emit_source.Emit0(evtid); \
     } \
}

class CATOmxEventMask {
  CATOmxEventId mask;
public:
  CATOmxEventMask() : mask(0) {}
  CATOmxEventMask & all() { mask = ~0;  return *this; }
  CATOmxEventMask & add( CATOmxEventId i) { mask |= OMX_POW2ULL(i);  return *this; }
  CATOmxEventMask & sub( CATOmxEventId i) { mask &= ~OMX_POW2ULL(i);  return *this; }
  CATOmxEventId get() const { return mask; }
};

class CATOmxEventSource;
class CATOmxEventContext;
class CATOmxEventController;
class CATOmxEventListener;
/**
 * Base class for the CATOmxEvent hierarchy .
 * MUST not be used outside ObjectModelerCollection.
 * @private
 */
class ExportedByCATOmxKernel CATOmxEventSharable : public CATOmxSharable {
  CATOmxEventSharable(const CATOmxEventSharable &); // prevent copy
public:
  CATOmxEventSharable();
  ~CATOmxEventSharable();
};
/**
 * Describe an event.
 * ALL DATA SHOULD NOT BE MODIFIED.
 * DATA ARE EXPOSED FOR PERFORMANCE PURPOSE.
 */
class ExportedByCATOmxKernel  CATOmxEvent : public CATOmxEventSharable {
public:
   CATOmxEventSource *source ; // the event source
   CATOmxKeyString name; // the event name
   CATOmxKeyString full_name; // the event full name event@source (format)
   CATOmxEventId id; // the event id
   CATULONG64    v_count;  // captor event count
   CATULONG64    v_weight; // captor weight
   /** 
    * Activate the source. 
    * @see CATOmxEventSource::Enable
    */
   HRESULT Enable(CATBoolean iState);
   CATBoolean is_forward() const;
};
/**
 * The EventContext.
 */
class ExportedByCATOmxKernel  CATOmxEventContext : public CATOmxEventSharable
{
public:
   const CATOmxEvent &event ;
   CATOmxAny info ;

   CATOmxEventContext(const CATOmxEvent &iEvent) ;
   /** add a data in the CATOmxEvent. see OMX_EMIT */
   CATOmxEventContext &add(const CATOmxAny &i)  ;
   inline CATOmxEventContext &operator, (const CATOmxAny& i) { return add(i); }
   /** Add weight */
   CATOmxEventContext &weight(CATULONG64 iWeight)  ;
   /** Internal use */
   void Commit()  ;
};

/**
 * An Event source gather several event.
 * Events can be Enabled or Disabled.
 */
class ExportedByCATOmxKernel CATOmxEventSource : public CATOmxEventSharable
{
   friend class CATOmxEvent;
   friend class CATOmxEventContext;
public:
   // do not modify this mask used by OMX_EMIT
   CATOmxEventId emit_mask ;
private:
   void sync_emit_mask();
   CATOmxEventId listener_mask;
   CATOmxEventId event_mask;
   CATOmxEventId def_mask ;
   CATOmxKeyString source_name ;
   unsigned int m_mask;
   CATOmxKeyValueBlock description;
   CATOmxVector<CATOmxEvent> event_by_id;
   CATOmxOMap<CATOmxKeyString,CATOmxEvent*,naive_manager,naive_manager> event_by_name;
   CATOmxVector<class CATOmxEventMediator> listener; 
public:
   /** Access to source description */
   inline const CATOmxKeyValueBlock &GetDescription() ;
   CATOmxEventSource(const CATOmxKeyString &iName) ;
   inline const CATOmxKeyString& GetSourceName() const { return source_name; }
   /** Add an event. 
    * The event is created disabled
    */
   CATOmxEventSource&AddEvent(const CATOmxKeyString &iKey, CATOmxEventId iEvent) ;
   /** Activate or Deactivate the specific event. 
    */
   HRESULT Enable(const CATOmxKeyString &iName,CATBoolean iState=TRUE) ;
   /** 
    * Deactivate the specific event.
    * NOT RECOMMANDED.
    */
   HRESULT Disable(const CATOmxKeyString &iName) ;
   /** Internal use. */
   CATOmxEventContext &Emit(CATOmxEventId iEventId) const;
   void Emit0(CATOmxEventId iEventId) const;
   /** Return all events. */
   CATOmxIter<CATOmxEvent> EventIterator();
   /** Return event matching name. */
   CATOmxEvent *LocateByName(const CATOmxKeyString &iName) const;
   /** Return event matching id. */
   CATOmxEvent *LocateById(CATOmxEventId iEventId) const;
   /**
    * Add a source listener.
    * source listener are not yet implemented !
    */
   void AddListener(CATOmxEventListener &iListen, const CATOmxEventMask &iId) ;
   void RemoveListener(CATOmxEventListener &iListen, const CATOmxEventMask &iId) ;
   void Spray(const CATOmxEventContext &iContext) ;
};
/**
 * A singleton class used to gather EventSource and Listener.
 */
class ExportedByCATOmxKernel CATOmxEventController
{
   CATOmxOMap<CATOmxKeyString,CATOmxEventSource*,naive_manager,com_manager> m_source;
   CATOmxOMap<CATOmxKeyString,CATOmxEvent*,naive_manager,com_manager> m_event;
   CATOmxVector<CATOmxEventListener> listener; 
   
   CATOmxEventController(const CATOmxEventController &);
public:
   CATOmxEventSource &omx_event;
   CATOmxEventController();
   ~CATOmxEventController();
   /** Add a new source. */
   CATOmxEventSource &AddSource(const CATOmxKeyString &iSourceName) ;
   /** Return a source if it exist.  */
   CATOmxEventSource *GetSource(const CATOmxKeyString &iSourceName) ;
   static CATOmxEventController &get()  ;
   /**
    * Add a global listener.
    * source listener are not yet implemented !
    */
   void AddListener(CATOmxEventListener &iListen) ;
   /** Return all sources. */
   CATOmxMapIter<CATOmxKeyString,CATOmxEventSource*> SourceIterator();
   /** Return all events (by full_name). */
   CATOmxMapIter<CATOmxKeyString,CATOmxEvent*> EventIterator();
   /**
    * INTERNAL USE ONLY.
    * use OMX_EMIT instead.
    */
   void Spray(const CATOmxEventContext &iContext) ;
   /**
    * INTERNAL USE ONLY. 
    * This API is used to create a new event breakpoint before the event creation.
    * use OMD :set_event_state plugin instead
    */
   CATOmxEvent &RegisterByFullName(const CATOmxKeyString &iName);
   CATOmxEvent *GetEvent(const CATOmxKeyString &iName);
};
/**
 * Implements this class to subscribe to event source.
 */
class ExportedByCATOmxKernel CATOmxEventListener : public CATOmxEventSharable
{
public:
   virtual void Receive(CATOmxEventContext &iContext) =0;
};

#endif
