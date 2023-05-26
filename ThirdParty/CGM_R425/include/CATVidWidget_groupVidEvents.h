/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group that aggregates functions used by the VID
 * propagating events system.
 */

#error this file must never be included; doxygen file only.

/**
 * @defgroup groupVidEvents VID Propagating Events
 *
 * The module <b>VID Propagating Events</b> groups classes and
 * functions that are involved in the creation, dispatch and handling
 * of propagating events in both the @ref CATVidWidget and the @ref
 * CATVidFraWindow trees.
 *
 * VID uses the @ref groupSypEvent infrastructure.
 *
 * @section groupVidEvents_secWinsAndWidgets Window & Widget Events
 * Events on windows (@ref CATVidFraWindow) and events on widgets
 * (@ref CATVidWidget) both use the same event propagation
 * infrastructure (@ref CATSYPEvent) but do not belong to the same
 * object tree. As a consequence events on widgets are never
 * dispatched through windows, and events on windows are never
 * dispatch through widgets.
 *
 * The behavior of disptaching is similar with widgets and windows, as
 * a consequence the following documentation applies to both object
 * trees. The term <em>object</em> is used instead of widget or
 * window.
 *
 * @section groupVidEvents_secDefinitions Definitions
 * The VID Propagating Events infrastructure offers the possibility to
 * make synchronous calls to @em event @em handlers registered
 * dynamically on the objects (either @ref CATVidWidget or windows @ref
 * CATVidFraWindow, see above for details).
 *
 * Handlers are registered for one or more @em event on one or more
 * object.
 *
 * The @em dispatch of an event is the action to call the handlers
 * registered on objects for this event. The handlers registered for
 * that event are called in sequence.
 *
 * The dispatch is made by requesting one object to dispatch the
 * event; this specific object is called the @em origin of the
 * dispatch.
 *
 * The handlers that are called during a dispatch depends on the type
 * of @em propagation of the event. There are three types of
 * propagation for events:
 *   - @em NoPropagation: only the handlers registered for the event on 
 *     the origin object are called.
 *   - @em OriginToRoot: first handlers registered for the event on the
 *     origin object are called, then handlers on its parent object, 
 *     then on the parent of its parent and recursively until the root
 *     object is reached.
 *   - @em RootToOrigin: this is the opposite of OriginToRoot, we start
 *     with the root object and end with the origin.
 *
 * Note that the parenthood of widgets is returned by @ref
 * CATVidWidget#GetFatherWidget and the parenthood of windows is
 * returned by @ref CATVidFraWindow#GetFatherWindow. In both cases it
 * does not use the @c CATCommand father.
 *
 * The handlers registered for the dispatched event on a given object
 * are always called in the same order:
 *   - first @em class @em handlers: those handlers are not registered 
 *     on an instance of object but for a class of object (i.e. 
 *     automatically for every instance of this class of one of its
 *     sub-class). Note that as of today there are no class handlers
 *     for windows.
 *   - then @em instance @em handlers
 * 
 * Class handlers of the most specialized class are called first, then
 * handlers registered for its parent class and recursively until @c
 * CATBaseUnknown is reached.
 *
 * For a given class, handlers are called in their order of
 * registration.
 *
 * Instance handlers are called in their order of registration.
 *
 * Some dispatching data are passed to every handler called during a
 * dispatch, these are the @em arguments of an event. Those arguments
 * are represented by an object that can be specialized by the user of
 * the event infrastructure.
 *
 * The same instance of this object is passed to every handlers.
 *
 * It can be used to prevent next handlers to be called by @em
 * consuming the event. After a handler has consumed one event, only
 * handlers registered to be called for consumed events are still
 * called. Other handlers are not called.
 *
 * A @em snapshot of the path of objects that will be called for an
 * event is made before the first handler is called. This snapshot
 * also contains for each objects the list of handlers to call. As a
 * consequence the modifications of the object tree and the
 * addition/removal of handlers on the objects have no impact on the
 * dispatch after it has started.
 *
 * The dispatch of an event is @em synchronous. The dispatch function
 * will only return when the dispatch is done.
 *
 * The dispatch is @em reentrant. It is safe to start a new dispatch
 * while being called in a handler by an other dispatch. The first
 * dispatch is simply paused until the new dispatch completes.
 *
 *
 * @section groupVidEvents_secEvents Events
 *
 * An event is defined by three things:
 *   - its identity
 *   - its type of propagation
 *   - its type of arguments
 *
 * The identity of an event is the instance of the @ref CATSYPEvent
 * class that represents the event. Note that event have a name
 * returned by @ref CATSYPEvent#GetName but this name should only be
 * used for debugging purposes.
 *
 * The type of propagation of an event (@ref CATSYPEvent#Propagation)
 * specifies how the event will propagate in the objects tree when
 * dispatched on its origin object. There are tree types of
 * propagation:
 *   - @ref CATSYPEvent#NoPropagation : the event only propagates on
 *     its origin object.
 *   - @ref CATSYPEvent#OriginToRoot : the event first propagates on
 *     its origin and then recursively on its father objects until it
 *     reaches the root object (i.e. the one having no father).
 *   - @ref CATSYPEvent#RootToOrigin : the event first propagates on
 *     root object (i.e. the last father in the chains of fathers of
 *     the origin object) then the recursively on each child object
 *     in direction of the origin object.
 *
 * Note that the parenthood of widgets is returned by @ref
 * CATVidWidget#GetFatherWidget and the parenthood of windows is
 * returned by @ref CATVidFraWindow#GetFatherWindow. In both cases it
 * does not use the @c CATCommand father.
 *
 * The type of arguments specifies the sub-class of @ref
 * CATSYPEventArgs that are to be used as arguments for the dispatch
 * of this event.
 *
 * Events should be exposed on their owner class by a static function
 * named after the name of the event itself. For example the @c
 * "Close" event on a class should be available with a @c static @c
 * public function returning a @c CATSYPEvent*. @c AddRef should not
 * have been called on the returned instance and it must return always
 * the same instance.
 *
 * The documentation should explicit:
 *   - the type of propagation of the event
 *   - the name of the event
 *   - the type of argument of the event (i.e. a sub-type of 
 *     @ref CATSYPEventArgs)
 *   - the expected usage of the event, including the expected origin
 *     of the event.
 *
 * The choice of the owner class depends on the event and its
 * usage. Generally an event should be owned by the class that
 * dispatches it but this is not mandatory. An event can be dispatch
 * by any object.<br/>
 * It may be useful to expose an event on an other class that the
 * expected origin of the event to keep it private for example; or if
 * the event is application specific and can't be added on all objects.
 *
 * Example of documentation of event @c "Close" on class @c MyClass
 * that is a widget:
 * @code
 * class MyClass : public CATVidWidget
 * {
 * ...
 * public:
 *   // Get the @c Close event.
 *   //
 *   // The @c Close event is emitted when ... by ...
 *   // 
 *   // @par EventProperties
 *   //   - Name: @c "Close"
 *   //   - Type of propagation: @c OriginToRoot
 *   //   - Type of argument: @ref MyEventArg
 *   //
 *   // @return the event instance. @c AddRef has NOT been called on
 *   // the returned pointer.
 *   static CATSYPEvent * Close();
 * ...
 * };
 * @endcode
 *
 * To simplify the implementation of this kind of method, you may use
 * the @ref CATImplementSYPEvent macro.<br/> With the previous example
 * the C++ file should contain:
 * @code
 * CATImplementSYPEvent(MyClass, Close, OriginToRoot, MyEventArg, GetEventFactory());
 * @endcode
 *
 *
 * @section groupVidEvents_secHandlers Handlers
 *
 * An event handler is a specialization of @ref CATSYPEventHandler
 * class.
 *
 * Instance handlers are registered on widgets using @ref
 * CATVidWidget#AddHandler and on windows using @ref
 * CATVidFraWindow#AddHandler.
 *
 * Class handlers can be registered on widgets using @ref
 * CATVidWidget#AddClassHandler. As of today it is not possible to
 * register class handlers for windows events.
 *
 * In most cases it is not useful for a client that want to listen to
 * an event to have its own class of handlers. Some default
 * implementations of handlers can be used:
 *   - @ref CATSYPStaticEventHandler : this kind of handlers point a 
 *     function (either static member function or non-member function)
 *     that is called when the handler is called.
 *   - @ref CATSYPWRefMethEventHandler : this kind of handlers point
 *     both a member function (using a member function pointer) and an
 *     instance of the class that contain this member function. The
 *     instance of the class is pointed using a weak-reference to
 *     prevent reference loops (as a consequence it can be used to
 *     point the object on which this handler is registered for 
 *     example).
 *   - @ref CATSYPSenderMethEventHandler : this kind of handlers point
 *     a member function that is expected to be a member function of
 *     the object on which the handler is registered. It only make 
 *     sense to be registered as a class handler.
 *
 * Since those handlers are all template classes, they may require to
 * write too much code to instantiate and register. To simplify code
 * writing some template functions exists:
 *   - @ref AddCATSYPStaticEventHandler : to instantiate a @ref CATSYPStaticEventHandler 
 *     and register it as an instance handler
 *   - @ref AddCATSYPWRefMethEventHandler : to instantiate a @ref CATSYPWRefMethEventHandler
 *     and register it as an instance handler
 *   - @ref AddSCATSYPStaticEventHandler : to instantiate a @ref CATSYPStaticEventHandler 
 *     and register it as a class handler
 *   - @ref AddSCATSYPSenderMethEventHandler : to instantiate a @ref CATSYPSenderMethEventHandler
 *     and register it as a class handler
 *
 *
 * @section groupVidEvents_secDispatch Dispatch
 * 
 * The dispatch of is done on widgets by calling @ref
 * CATVidWidget#Dispatch with an instance of event arguments (@ref
 * CATSYPEventArgs). On windows it is done by calling @ref
 * CATVidFraWindow#Dispatch. Note that the instance of arguments must
 * be the expected class for the event (@ref
 * CATSYPEvent#GetArgumentType).
 *
 * @see groupSypEvent
 */
