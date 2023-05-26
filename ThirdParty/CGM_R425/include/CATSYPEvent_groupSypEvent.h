/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation groups groupSypEvent, groupSypEventEvent
 */

#error this file must never be included; doxygen file only.


/** 
 * @defgroup groupSypEvent Introspection Propagating Events
 *
 * The <b>Introspection Propagating Events</b> module groups the classes used to
 * instantiate and dispatch events that can be propagated in a tree of
 * objects.
 *
 * This infrastructure was initially designed to be used by VID but
 * can be used on any tree of @ref CATBaseUnknown objects.
 *
 * It has been splitted in four sub-modules:
 *   - @ref groupSypEventEvent to define events
 *   - @ref groupSypEventHandlers the interface for handlers of events registered 
 *     on nodes of the tree
 *   - @ref groupSypEventRegistration to implement the registration of handlers
 *     on the node of the tree
 *   - @ref groupSypEventDispatching to implement the dispatching of events along 
 *     the nodes of the tree
 *
 *
 *
 *
 * @par Dependencies
 * The classes in @ref groupSypEventEvent can be used alone. You don't
 * have to use them with classes of other sub-modules.
 *
 * @par
 * The classes in @ref groupSypEventHandlers depends only on classes
 * in @ref groupSypEventEvent. They can be used with an other
 * registration and dispatching infrastructure as the one proposed
 * here.
 *
 * @par
 * The classes in @ref groupSypEventRegistration depends on classes in
 * @ref groupSypEventHandlers and @ref groupSypEventEvent. They can be
 * used with an other dispatching infrastructure that the one proposed
 * in @ref groupSypEventDispatching.
 *
 * @par
 * The classes in @ref groupSypEventDispatching depends on classes in
 * @ref groupSypEventHandlers and @ref groupSypEventEvent. They can be
 * used with an other registration infrastructure as the one
 * implemented in @ref groupSypEventRegistration.
 *
 *
 *
 * @par Capabilities
 * Using all classes of those modules provide an infrastructure to
 * dispatch events on a tree of objects.
 *
 * @par
 * The events can be propagated from their origin (i.e. the node that
 * dispatched it) up to the root, from the root down to their origin,
 * or only to their origin.
 *
 * @par
 * Handlers can be registered on nodes so that their are called when a
 * specific event reaches the node.
 *
 * @par
 * The path of nodes and their respective handlers are frozen at the
 * beginning of the dispatch so that changes in the object tree or in
 * the registered handlers have no impact on the current dispatch.
 *
 * @par
 * Some handlers can be registered on node classes instead of node
 * instances, enabling the handler to be called for any instance of
 * this class (or instance of sub-class).
 *
 * @par
 * Events can be consumed; that prevents handlers from being
 * called. Note that the registration infrastructure enable to
 * register a handler to be called for consumed events.
 *
 * @par
 * The dispatch is synchronous; until the dispatch is done, the
 * dispatch function does not return.
 *
 * @par
 * The dispatch is reentrant. It is possible to start a new dispatch
 * from a handler called by a first dispatch. The new dispatch will be
 * completed and then the first dispatch will continue.
 *
 * 
 *
 * @section groupSypEvent_UsageSample Usage Sample
 * Here is a sample of usage of the whole infrastructure to add events to a hierarchy.
 *
 * @subsection groupSypEvent_UsageSample_Objects Objects
 * Our sample is based on the following nodes:
 * @code
 * // The base class of nodes in the node tree.
 * class CATSYPTstEventSampleNode : public CATBaseUnknown
 * {
 *   CATDeclareClass;
 * public:
 *   CATSYPTstEventSampleNode(const char *i_id);
 *   
 *   ~CATSYPTstEventSampleNode();
 * 
 *   // Build a string identifying the node and its type.
 *   //
 *   // @return the @ref #id of the node and its class name separated by
 *   // @c ':'.
 *   std::string BuildNodeTypedId();
 * 
 *   // Change the parent of this node.
 *   //
 *   // @param i_pParent the new parent node. Can be @c NULL.
 *   void SetParent(CATSYPTstEventSampleNode *i_pParent);
 * 
 *   // pointer on the parent node of this node. For the purpose of this
 *   // test @c AddRef has been called on this pointer; this is not an
 *   // because a node does not reference its children (for event
 *   // disptaching we don't need to know our children, only our
 *   // parent).
 *   CATSYPTstEventSampleNode *_pParent;
 * 
 *   // the identificator of the node
 *   const char * const id;
 * };
 * CATImplementClass(CATSYPTstEventSampleNode, Implementation, CATBaseUnknown, CATNull);
 * @endcode
 * @code
 * // A node representing a button.
 * class CATSYPTstEventSampleButton : public CATSYPTstEventSampleNode
 * {
 *   CATDeclareClass;
 * public:
 *   CATSYPTstEventSampleButton(const char *i_id);
 *   ~CATSYPTstEventSampleButton();
 * };
 * CATImplementClass(CATSYPTstEventSampleButton, Implementation, CATSYPTstEventSampleNode, CATNull);
 * @endcode
 * @code
 * // A node representing a dialog.
 * class CATSYPTstEventSampleDialog : public CATSYPTstEventSampleNode
 * {
 *   CATDeclareClass;
 * public:
 *   CATSYPTstEventSampleDialog(const char *i_id);
 *   ~CATSYPTstEventSampleDialog();
 * };
 * CATImplementClass(CATSYPTstEventSampleDialog, Implementation, CATSYPTstEventSampleNode, CATNull);
 * @endcode
 * 
 * We will instantiate this node in the following hierarchy for tests:
 * @verbatim
  root:Dialog
    node1:Node
      button1:Button
      node2:Node
        button2:Button
@endverbatim
 *
 * With the code:
 * @code
 * CATSYPTstEventSampleDialog * const pRoot = new CATSYPTstEventSampleDialog("root");
 * CATSYPTstEventSampleNode * const pNode1 = new CATSYPTstEventSampleNode("node1");
 * CATSYPTstEventSampleNode * const pButton1 = new CATSYPTstEventSampleButton("button1");
 * CATSYPTstEventSampleNode * const pNode2 = new CATSYPTstEventSampleNode("node2");
 * CATSYPTstEventSampleNode * const pButton2 = new CATSYPTstEventSampleButton("button2");
 *
 * pNode1->SetParent(pRoot);
 * pNode2->SetParent(pNode1);
 * pButton1->SetParent(pNode1);
 * pButton2->SetParent(pNode2);
 * @endcode
 *
 * @subsection groupSypEvent_UsageSample_Supports Adding Supports
 * The first step to support events is to add event handlers
 * registration infrastructure.
 *
 * This is done by adding a @ref CATSYPEventHandlersSupport to each
 * node.
 *
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown
 * {
 * ...
 * private:
 *   CATSYPEventHandlersSupport * _pSupport;
 * };
 * @endcode
 * 
 * To be able to register handlers, function @c AddHandler and @c
 * RemoveHandler should also be added:
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown
 * {
 * ...
 *   // Add a handler for a given event.
 *   //
 *   // The handlers will be called in the order of their registration.
 *   //
 *   // If this function is called during the dispatch of an event, the
 *   // registered event handler won't be called for this dispatch but
 *   // will only be called for next dispatches.
 *   //
 *   // It is possible to call multiple times this function with the same
 *   // event and the same handler instance. In that case there will be
 *   // multiple registrations; no checks are made for duplication (the
 *   // caller will have to call @ref #RemoveHandler multiple times).
 *   //
 *   // @param i_pEvent the event that we are interested in. Note that @c
 *   // AddRef will be called on the event. Can't be @c NULL.
 *   //
 *   // @param i_pHandler the handler to call. Can't be @c NULL. 
 *   // @c AddRef will be called on this pointer. Note that the type of 
 *   // @c CATSYPEventArgs supported by this handler will be compared to
 *   // the type of arguments of the event. It must be a super-type of
 *   // the one of the event.
 *   //
 *   // @param i_handleConsumedEvents @c !=0 if the handler should be
 *   // called for consumed events.
 *   //
 *   // @return @c !=0 if succeeded, @c 0 if failed to add handler due to
 *   // invalid input or internal error (in that case a @ref FAILURE has
 *   // been raised).
 *   //
 *   // @see #AddHandlerFunction
 *   // @see @AddHandlerWRefMeth
 *   // @see #RemoveHandler 
 *   int AddHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents = 0);
 *
 *   // Remove an handler for an event.
 *   //
 *   // If this function is called during the dispatch of an event, the
 *   // unregistered event handler will be called for this dispatch but
 *   // will not be called for next dispatches.
 *   //
 *   // If the same handler has been added multiple times, this function
 *   // removes the first found registration (starting the look up from
 *   // the most ancient registration).
 *   //
 *   // @param i_pEvent the event. Can't be @c NULL.
 *   //
 *   // @param i_pHandler the handler. Can't be @c NULL.
 *   //
 *   // @return @c !=0 if succeeded, @c 0 if failed to remove handler due
 *   // to invalid input or internal error (in that case a @ref FAILURE has
 *   // been raised) or if the handler was never registered for the given
 *   // event (in that case NO @ref FAILURE is raised, it is valid to do
 *   // so; this is important for auto-remove handlers).
 *   //
 *   // @see #AddHandler
 *   int RemoveHandler(CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler);
 * ...
 * };
 * @endcode
 * These two functions simply delegates action to @c _pSupport.
 * 
 * @subsection groupSypEvent_UsageSample_Dispatch Adding Dispatch
 * The second step to support events is to add event dispatch
 * infrastructure.
 *
 * This is done by specializing a @ref
 * CATSYPEventPathBuilder. Actually, since we are using a @ref
 * CATSYPEventHandlersSupport to register handlers we can specialize
 * @ref CATSYPSupportsEventPathBuilder instead:
 * @code
 * // Path builder for event dispatching in the tree of @ref
 * // CATSYPTstEventSampleNode.
 * class CATSYPTstEventSamplePathBuilder : public CATSYPSupportsEventPathBuilder
 * {
 * public:
 *   CATSYPTstEventSamplePathBuilder();
 *   ~CATSYPTstEventSamplePathBuilder();
 * 
 *   // @copydoc CATSYPEventPathBuilder#GetParent
 *   virtual CATBaseUnknown *GetParent(CATSYPEventArgs *i_pArgs, CATBaseUnknown *i_pNode)
 *   {
 *     CATSYPTstEventSampleNode * const pNode = 
 *       CAT_DYNAMIC_CAST(CATSYPTstEventSampleNode, i_pNode);
 *     CHECK_POINTER_RETV(pNode, NULL);
 *     return pNode->_pParent;
 *   }
 * 
 *   // @copydoc CATSYPSupportsEventPathBuilder#GetSupportForNode
 *   virtual CATSYPEventHandlersSupport *GetSupportForNode(CATBaseUnknown *i_pNode) {
 *     CATSYPTstEventSampleNode * const pNode = 
 *       CAT_DYNAMIC_CAST(CATSYPTstEventSampleNode, i_pNode);
 *     CHECK_POINTER_RETV(pNode, NULL);
 *     return pNode->_pSupport;
 *   }
 * 
 *   // @copydoc CATSYPSupportsEventPathBuilder#GetClassSupportForNode
 *   virtual CATSYPClassEventHandlersSupport *GetClassSupportForNode(CATBaseUnknown *i_pNode) {
 *     return NO_CLASS_SUPPORT();
 *   }
 * };
 * @endcode
 * 
 * As you may have noticed we access to @c _pSupport on @c
 * CATSYPTstEventSampleNode class. To be able to do that, the @c
 * CATSYPTstEventSamplePathBuilder must be friend of @c
 * CATSYPTstEventSampleNode.
 *
 * The dispatch method of @c CATSYPTstEventSampleNode:
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown {
 * ...
 *   // Dispatch the event.
 *   //
 *   // The event will be dispatched in the tree hierarchy depending on
 *   // the propagation mode of the event (@ref
 *   // CATSYPEvent#GetPropagation).
 *   //
 *   // The list of handlers that will be called will be frozen before
 *   // the first handler is called; as a consequence, changes in the
 *   // tree hierarchy or in the handlers for the event at each node
 *   // won't have any effect on the dispatch of this event (but will
 *   // have effect on next dispatches, even on dispatches that may be
 *   // triggered by handlers of this event).
 *   //
 *   // This call is synchronous; it is blocking until the dispatch is
 *   // ended.
 *   //
 *   // The origin on the event argument (@ref CATSYPEventArgs#GetOrigin)
 *   // must be either @c NULL or equal to this object. If @c NULL, it
 *   // will be positioned by this function to this object.
 *   //
 *   // The instance of arguments used on this function will be passed to
 *   // all handlers called during the dispatch.
 *   // 
 *   // @param i_pArgs the arguments of the event to dispatch (the
 *   // dispatched event is retreived though @ref
 *   // CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
 *   // either this object of @c NULL.
 *   //
 *   // @return @c !=0 if the dispatch succeeded, @c 0 if failed.
 *   int Dispatch(CATSYPEventArgs *i_pArgs);
 * ...
 * };
 * @endcode
 * will be implemented this way:
 * @code
 * int CATSYPTstEventSampleNode::Dispatch(CATSYPEventArgs *i_pArgs)
 * {
 *   CHECK_POINTER_RETV(i_pArgs, 0);
 * 
 *   // set the origin  
 *   if (i_pArgs->GetOrigin() == NULL)
 *     i_pArgs->SetOrigin(this);
 *   // check the origin
 *   CHECK_TRUE_RETV_MSG(i_pArgs->GetOrigin() == this,
 *                       0,
 *                       "The origin of the event is incorrect");
 * 
 *   // build the dispatch path
 *   CATSYPTstEventSamplePathBuilder pathBuilder;
 *   CATSYPEventPath * const pPath = pathBuilder.BuildPath(i_pArgs);
 *   CHECK_POINTER_RETV(pPath, 0);
 * 
 *   // dispatch the event
 *   pPath->Dispatch(i_pArgs);
 * 
 *   // destroy the path
 *   delete pPath;
 * 
 *   return 1;
 * }
 * @endcode
 * Note that we may also use the shortcut function @ref
 * CATSYPEventPathBuilder#Dispatch that implements this function for
 * us:
 * @code
 * int CATSYPTstEventSampleNode::Dispatch(CATSYPEventArgs *i_pArgs)
 * {
 *   CATSYPTstEventSamplePathBuilder pathBuilder;
 *   return pathBuilder.Dispatch(this, i_pArgs);
 * }
 * @endcode
 * 
 * @subsection groupSypEvent_UsageSample_Events Adding Events
 * The third step to support events is to add actual events.
 *
 * To be able to add event, we must have a single @ref
 * CATSYPEventFactory instance for our tree:
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown {
 * ...
 * protected:
 *   // Get the factory of events for this tree hierarchy.
 *   //
 *   // @return the event factory. Can't be @c NULL.
 *   static CATSYPEventFactory *GetEventFactory() {
 *     static CATSYPEventFactory factory;
 *     return &factory;
 *   }
 * ...
 * };
 * @endcode
 *
 * For example mouse press event:
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown
 * {
 * ...
 * public:
 *   // Get the @c MousePress event.
 *   //
 *   // @par EventProperties
 *   // Name: @c "MousePress"
 *   // Type of propagation: @c OriginToRoot
 *   // Type of argument: @ref CATSYPTstEventSampleMousePressArgs
 *   //
 *   // @return the event instance. @c AddRef has NOT been called on
 *   // the returned pointer.
 *   static CATSYPEvent * MousePress();
 * ...
 * };
 *
 * ...
 *
 * // Arguments for @ref CATSYPTstEventSampleNode#MousePress event.
 * class CATSYPTstEventSampleMousePressArgs : public CATSYPEventArgs
 * {
 *   CATDeclareClass;
 * public:
 *   CATSYPTstEventSampleMousePressArgs(CATSYPEvent *i_pEvent, int x, int y)
 *     : CATSYPEventArgs(i_pEvent), x(x), y(y) {
 *     INC_INSTANCE_COUNTER(CATSYPTstEventSampleMousePressArgs);
 *   } 
 *   ~CATSYPTstEventSampleMousePressArgs() {
 *     DEC_INSTANCE_COUNTER(CATSYPTstEventSampleMousePressArgs);
 *   }
 *   const int x;
 *   const int y;
 * private:
 *   NON_VALUE_CLASS(CATSYPTstEventSampleMousePressArgs);
 * };
 * 
 * CATImplementClass(CATSYPTstEventSampleMousePressArgs,
 *                   Implementation,
 *                   CATSYPEventArgs,
 *                   CATNull);
 * 
 * CATImplementSYPEvent(CATSYPTstEventSampleNode, MousePress, OriginToRoot, 
 *                      CATSYPTstEventSampleMousePressArgs, GetEventFactory());
 * @endcode
 *
 * And button click event:
 * @code
 * class CATSYPTstEventSampleButton : public CATSYPTstEventSampleNode
 * {
 * ...
 * public:
 *   // Get the @c Click event.
 *   //
 *   // The @c Click event is emmited when the button is clicked. Its
 *   // origin will be the clicked button.
 *   //
 *   // @par EventProperties
 *   // Name: @c "Click"
 *   // Type of propagation: @c OriginToRoot
 *   // Type of argument: @ref CATSYPEventArgs
 *   //
 *   // @return the event instance. @c AddRef has NOT been called on
 *   // the returned pointer.
 *   static CATSYPEvent * Click();
 * ...
 * };
 * ...
 * CATImplementSYPEvent(CATSYPTstEventSampleButton, Click,
 *                      OriginToRoot, CATSYPEventArgs, GetEventFactory());
 * @endcode
 *
 * @subsection groupSypEvent_UsageSample_Handlers Handling Events
 * Now the infrastructure has been put in place, we have to test it.
 *
 * The first thing to do is to add handlers. First we will add a
 * static function that will have to be called by an handler on
 * buttons to transform mouse event into click events and consume
 * them:
 * @code
 * class CATSYPTstEventSampleButton : public CATSYPTstEventSampleNode
 * {
 * ...
 *   // Handler for @ref CATSYPTstEventSampleNode#MousePress event that
 *   // consumes it and transform it into a @ref
 *   // CATSYPTstEventSampleButton#Click event.
 *   //
 *   // This handler must only be registered on a button.
 *   static void HandleMousePress(CATBaseUnknown *i_pSender, CATSYPTstEventSampleMousePressArgs *i_pArgs) {
 *     CHECK_POINTER_RET(i_pArgs);
 *     CATSYPTstEventSampleButton * const pButton =
 *       CAT_DYNAMIC_CAST(CATSYPTstEventSampleButton, i_pSender);
 *     CHECK_POINTER_RET(pButton);
 * 
 *     // consume the mouse press event
 *     i_pArgs->Consume();
 * 
 *     // dispatch a click event
 *     CATSYPEventArgs * const pClickArgs = new CATSYPEventArgs(Click());
 *     CHECK_TRUE(pButton->Dispatch(pClickArgs));
 *     pClickArgs->Release();
 *   }
 * ...
 * };
 * @endcode
 * As you notice, we use @c i_pSender argument of the callback
 * function to identify the button on which this handler calling this
 * function will be registered.
 *
 * We will also add a member function on a simple class that inherit
 * from @ref CATBaseUnknown that will be used to be called by handlers
 * and that will dump a generic message:
 * @code
 * // Object modeler component used as a listener.
 * //
 * // It has a @ref #HandleEvent function that can be used with @ref
 * // CATSYPWRefMethEventHandler handler.
 * class CATSYPTstEventSampleListener : public CATBaseUnknown
 * {
 *   CATDeclareClass;
 * public:
 *   CATSYPTstEventSampleListener();
 *   ~CATSYPTstEventSampleListener();
 * 
 *   // Generic event handling function
 *   void HandleEvent(CATBaseUnknown *i_pSender,
 *                    CATSYPEventArgs *i_pArgs);
 * };
 * 
 * CATImplementClass(CATSYPTstEventSampleListener, Implementation, CATBaseUnknown, CATNull);
 * @endcode
 * This function will dump a message to stdout when it is called.
 *
 * Then we instantiate and register event handlers to call this
 * functions:
 * @code
 *   CATSYPTstEventSampleListener * const pListener = new CATSYPTstEventSampleListener();
 * 
 *   // add a handler on mouse press event on node2 that calls the
 *   // HandleEvent member function of the pListener object. This handler
 *   // is register so that it receive consumed events.
 *   AddCATSYPWRefMethEventHandler(pNode2,
 *                                 CATSYPTstEventSampleNode::MousePress(),
 *                                 pListener,
 *                                 &CATSYPTstEventSampleListener::HandleEvent,
 *                                 1);
 * 
 *   // add a handler on button click event on root that calls the
 *   // HandleEvent member function of the pListener object . This
 *   // handler is register so that it only receive non consumed events.
 *   AddCATSYPWRefMethEventHandler(pRoot,
 *                                 CATSYPTstEventSampleButton::Click(),
 *                                 pListener,
 *                                 &CATSYPTstEventSampleListener::HandleEvent);
 * 
 *   // add mouse press event handlers on button that tranform mouse
 *   // press events into click events
 *   AddCATSYPStaticEventHandler(pButton1,
 *                               CATSYPTstEventSampleNode::MousePress(),
 *                               &CATSYPTstEventSampleButton::HandleMousePress); 
 *   AddCATSYPStaticEventHandler(pButton2,
 *                               CATSYPTstEventSampleNode::MousePress(),
 *                               &CATSYPTstEventSampleButton::HandleMousePress);
 * @endcode
 * As you notice we create two different handlers for the @c
 * CATSYPTstEventSampleListener::HandleEvent member method and
 * register them on different component.<br/>
 * The code <code>AddCATSYPWRefMethEventHandler(pNode2, ...)</code>
 * ensures that if a mouse press event reaches the @c node2 node, then
 * we will call the @c CATSYPTstEventSampleListener::HandleEvent
 * member method of the object @c pListener. The code
 * <code>AddCATSYPWRefMethEventHandler(pRoot, ...)</code> ensures that
 * if a button click event reaches the root, then the @c HandleEvent
 * method of @c pListener is called.
 *
 * The two calls @c AddCATSYPStaticEventHandler on @c pButton1 and @c
 * pButton2 will ensure that the static method @c
 * CATSYPTstEventSampleButton::HandleMousePress is called when a mouse
 * press event reaches the button.
 *
 * If we then dispatch a mouse press event on @c pButton2:
 * @code
 *   CATSYPTstEventSampleMousePressArgs *pMousePressArgs =
 *     new CATSYPTstEventSampleMousePressArgs(CATSYPTstEventSampleNode::MousePress(),
 *                                            5, 18);
 *   CHECK_TRUE(pButton2->Dispatch(pMousePressArgs));
 *   pMousePressArgs->Release();
 * @endcode
 * Then we will have the following dumps:
 * @verbatim
  CATSYPTstEventSampleListener::HandleEvent
    evt=CATSYPTstEventSampleButton.Click
    sender=root:CATSYPTstEventSampleDialog
    origin=button2:CATSYPTstEventSampleButton
CATSYPTstEventSampleListener::HandleEvent
  evt=CATSYPTstEventSampleNode.MousePress
  sender=node2:CATSYPTstEventSampleNode
  origin=button2:CATSYPTstEventSampleButton
  [consumed]
 @endverbatim
 * The indentation with two spaces on the first dumped event is added
 * to signify that this event has been dispatched while an other event
 * was already being dispatched. This is due to the fact that the
 * first dumped event, @c CATSYPTstEventSampleButton::Click, has been
 * emmited by the static function @c
 * CATSYPTstEventSampleButton::HandleMousePress called by an event
 * handler registered on @c pButton2 for the second dumped event.
 *
 * The second dump is the reception by @c node2 from the first
 * event. It is printed after the second event because event
 * dispatching is synchronous:
 *   - first the mouse press event is dispatch on the @c button2
 *   - there is a static handler on the button that emit a click event
 *     on the button itself
 *   - this click event is dispatched synchronously so the dispatch of
 *     the first event is paused until the dispatch of this new event
 *     is done.
 *   - the click event reaches the root node where the listener has
 *     been registered to catch click events: it is printed.
 *   - then we go back to the propagation of the mouse press event; 
 *     that has been consumed by the static function
 *   - this event finally reaches @c node2 where the listener has
 *     been registered to catch mouse press event: it is printed.
 *
 * Now if we make the same test but instead use @c pButton1:
 * @code
 *   CATSYPTstEventSampleMousePressArgs *pMousePressArgs =
 *     new CATSYPTstEventSampleMousePressArgs(CATSYPTstEventSampleNode::MousePress(),
 *                                            5, 18);
 *   CHECK_TRUE(pButton1->Dispatch(pMousePressArgs));
 *   pMousePressArgs->Release();
 * @endcode
 * the output is:
 * @verbatim
  CATSYPTstEventSampleListener::HandleEvent
    evt=CATSYPTstEventSampleButton.Click
    sender=root:CATSYPTstEventSampleDialog
    origin=button1:CATSYPTstEventSampleButton
 @endverbatim
 * We don't see any trace of the mouse event since no handler for the
 * mouse press event has been registered on the branch that ends to @c
 * pButton1.
 *
 * @subsection groupSypEvent_UsageSample_ClassHandlers Handling Events with Class Handler
 * In the previous sample we have had to add a new handler for each
 * button. These handlers called the same static function.
 *
 * Another solution could have been to use a class handler.
 *
 * To be able to register class handlers, we have to use a @ref
 * CATSYPClassEventHandlersSupport:
 * @code
 * class CATSYPTstEventSampleNode : public CATBaseUnknown
 * {
 * ...
 *   // Add an handler for a given event and a given class.
 *   //
 *   // The handlers will be called in the order of their
 *   // registration. The class handlers will be called before any
 *   // instance handler (i.e. handlers registered using @ref
 *   // #AddHandler).
 *   //
 *   // If this function is called during the dispatch of an event, the
 *   // registered event handler won't be called for this dispatch but
 *   // will only be called for next dispatches.
 *   //
 *   // It is possible to call multiple times this function with the same
 *   // event, the same handler instance and the same class. In that case
 *   // there will be multiple registrations; no checks are made for
 *   // duplication (the caller will have to call @ref #RemoveHandler
 *   // multiple times).
 *   //
 *   // @param i_pClass the class. Can't be @c NULL.
 *   //
 *   // @param i_pEvent the event that we are interested in. Note that @c
 *   // AddRef will be called on the event. Can't be @c NULL.
 *   //
 *   // @param i_pHandler the handler to call. Can't be @c NULL. 
 *   // @c AddRef will be called on this pointer. Note that the type of 
 *   // @c CATSYPEventArgs supported by this handler will be compared to
 *   // the type of arguments of the event. It must be a super-type of
 *   // the one of the event.
 *   //
 *   // @param i_handleConsumedEvents @c !=0 if the handler should be
 *   // called for consumed events.
 *   //
 *   // @return @c !=0 if succeeded, @c 0 if failed to add handler due to
 *   // invalid input or internal error (in that case a @ref FAILURE has
 *   // been raised).
 *   static int AddClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents) {
 *     return _classSupport.AddClassHandler(i_pClass, i_pEvent, i_pHandler, i_handleConsumedEvents);
 *   }
 * 
 *   // Remove an handler for an event and a given class.
 *   //
 *   // If this function is called during the dispatch of an event, the
 *   // unregistered event handler will be called for this dispatch but
 *   // will not be called for next dispatches.
 *   //
 *   // If the same handler has been added multiple times, this function
 *   // removes the first found registration (starting the look up from
 *   // the most ancient registration).
 *   //
 *   // @param i_pClass the class. Can't be @c NULL.
 *   //
 *   // @param i_pEvent the event. Can't be @c NULL.
 *   //
 *   // @param i_pHandler the handler. Can't be @c NULL.
 *   //
 *   // @return @c !=0 if succeeded, @c 0 if failed to remove handler due
 *   // to invalid input or internal error (in that case a @ref FAILURE has
 *   // been raised) or if the handler was never registered for the given
 *   // event (in that case NO @ref FAILURE is raised, it is valid to do
 *   // so; this is important for auto-remove handlers).
 *   static int RemoveClassHandler(CATMetaClass *i_pClass, CATSYPEvent *i_pEvent, CATSYPEventHandler *i_pHandler) {
 *     return _classSupport.RemoveClassHandler(i_pClass, i_pEvent, i_pHandler);
 *   }
 * ...
 *   static CATSYPClassEventHandlersSupport _classSupport;
 * };
 * @endcode
 * @code
 * class CATSYPTstEventSamplePathBuilder : public CATSYPSupportsEventPathBuilder
 * {
 * ...
 *   // @copydoc CATSYPSupportsEventPathBuilder#GetClassSupportForNode
 *   virtual CATSYPClassEventHandlersSupport *GetClassSupportForNode(CATBaseUnknown *i_pNode) {
 *     return &CATSYPTstEventSampleNode::_classSupport;
 *   }
 * ...
 * };
 * @endcode
 *
 * We can now use this class handler registration instead:
 * @code
 *   // add mouse press event handlers on button class that transform
 *   // mouse press events into click events
 *   AddSCATSYPStaticEventHandler(&CATSYPTstEventSampleNode::AddClassHandler,
 *                                CATSYPTstEventSampleButton::MetaObject(),
 *                                CATSYPTstEventSampleNode::MousePress(),
 *                                &CATSYPTstEventSampleButton::HandleMousePress); 
 * @endcode
 *
 * Using class handlers registration, we only have to register once
 * the handler. It will then be automatically called for any instance
 * of @ref CATSYPTstEventSampleButton. Note that @c
 * CATSYPTstEventSampleButton::HandleMousePress does not have to be
 * public. It is in our sample since the registration is made outside
 * the class.
 *
 * We could have implemented a new kind of handler specializing @ref
 * CATSYPAbstractMethEventHandler and that calls a method of the
 * sender. This way the @c CATSYPTstEventSampleButton::HandleMousePress 
 * may have been a regular member function instead of an instance
 * member function. But this was out of the scope of this sample.
 *
 * @section groupSypEvent_Shortcuts Implementation Shortcuts
 * There are some classes and functions that can be used to shortcut
 * the implementation of events for a tree of objects.
 *
 * The function @ref CATSYPEventPathBuilder#Dispatch can be used when
 * the dispatching code only calls @ref CATSYPEventPath#Dispatch on
 * the built path.
 *
 * The class @ref CATSYPSingleEventPathBuilder can be used to
 * implement dispatching when the events are used on a single item
 * that is not part of a tree:
 * @code
 * int XXXXX::Dispatch(CATSYPEventArgs *i_pArgs)
 * {
 *   CHECK_POINTER_RETV(_pSupport, 0);
 * 
 *   CATSYPSingleEventPathBuilder builder(_pSupport, NULL);
 *   return builder.Dispatch(GetImpl(), i_pArgs);
 * }
 * @endcode
 */

/** @ingroup groupSypEvent
 * @defgroup groupSypEventEvent Event
 *
 * The <b>Event</b> sub-module groups the classes that defines events.
 *
 * The @ref CATSYPEvent class represents an event that can be
 * dispatched on a tree node of objects.
 *
 * It is built by a @ref CATSYPEventFactory factory. There should only
 * be one instance of factory for a kind of tree node.
 *
 * The event is static, it is instantiated once to identify a kind of
 * events. The @ref CATSYPEventArgs class is there to associate
 * specific data to one event dispatching. It is called the "arguments
 * of the dispatching". <br/>
 * It can be specialized to associate event specific data. The event
 * declares the exact type of arguments it is expecting. This type is
 * identified using the Object Modeler Runtime Type System (i.e.  @ref
 * CATMetaClass).
 *
 * Please refer to the @link groupSypEvent main module documentation@endlink
 * for details.
 *
 * @see groupSypEvent
 */
