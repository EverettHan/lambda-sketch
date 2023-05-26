/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group groupSypEventDispatching.
 */

#error this file must never be included; doxygen file only.

/** @ingroup groupSypEvent
 * @defgroup groupSypEventDispatching Event Dispatching
 *
 * The sub-module <b>Event Dispatching</b> groups classes that can be
 * used to implement the dispatching of @ref CATSYPEvent events.
 *
 * @par Dispatching Path Freeze
 * The first step of a dispatch is to freeze the path of the of
 * dispatching. That means that before the first handler (i.e. @ref
 * CATSYPEventHandler) is called, the list of all handlers that will
 * have to be called is computed. This ensures that modifications on
 * the tree or on handlers registered on the nodes during a dispatch
 * have no impact on the dispatch itself. They will only impact future
 * dispatch (or recursive dispatch, i.e. dispatch triggered directly
 * or indirectly by one of the handler or the current dispatch).
 *
 * @par
 * This freeze of the list of handlers to call during a dispatch is
 * represented by the @ref CATSYPEventPath class.<br/>
 * A path is a list of @ref CATSYPEventPathElt that associates a node
 * to the list of handlers to call. Actually it associates a node with
 * a list of @ref CATSYPEventHandlerInfoList; those lists pointing to
 * the handlers.
 *
 * @par
 * The path construction depends on the event propagation mode (see
 * @ref CATSYPEvent#Propagation). If the mode is @ref
 * CATSYPEvent#NoPropagation then the path will only contain one @ref
 * CATSYPEventPathElt for the origin node. If the mode is @ref
 * CATSYPEvent#RootToOrigin, then the path will start with the root;
 * respectively if the mode is @ref CATSYPEvent#OriginToRoot then the
 * path will start with the origin.
 * 
 * @par Path Construction
 * The abstract class @ref CATSYPEventPathBuilder can be used to build
 * the dispatching path for an event. See class documentation for
 * details about how it must be specialized to be able to build paths.
 *
 * @par
 * Note that if you use @ref CATSYPEventHandlersSupport and @ref
 * CATSYPClassEventHandlersSupport to implement event handlers
 * registration you may use the @ref CATSYPSupportsEventPathBuilder
 * partial implementation of the path builder.<br/>
 * It's important to note that the dispatch infrastructure does not
 * necessarily depends on the use of the @ref
 * CATSYPEventHandlersSupport class. It may be used with an
 * alternative event handlers registration infrastructure.
 *
 * @par
 * The class @ref CATSYPSingleEventPathBuilder can be used to
 * implement dispatching when the events are used on a single item
 * that is not part of a tree and uses @ref CATSYPEventHandlersSupport
 * (and optionally @ref CATSYPClassEventHandlersSupport) for handlers
 * registration:
 * @code
 * int XXXXX::Dispatch(CATSYPEventArgs *i_pArgs)
 * {
 *   CHECK_POINTER_RETV(_pSupport, 0);
 * 
 *   CATSYPSingleEventPathBuilder builder(_pSupport, NULL);
 *   return builder.Dispatch(GetImpl(), i_pArgs);
 * }
 * @endcode
 *
 * @par Path Dispatch
 * The actual dispatch is made with the @ref CATSYPEventPath#Dispatch
 * member function. The shortcut method @ref
 * CATSYPEventPathBuilder#Dispatch can be used to simplify the
 * implementation of the dispatch when there is no need to access to
 * the @ref CATSYPEventPath instance.
 *
 * @par Usage
 * Sample usage, assuming @c MyPathBuilder is a specialization of @ref
 * CATSYPEventPathBuilder and @c MyNode is the base class for nodes in
 * the object tree:
 * @code
 * int MyNode::Dispatch(CATSYPEventArgs *i_pArgs) {
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
 *   // build the disptaching path of the event
 *   MyPathBuilder pathBuilder;
 *   CATSYPEventPath * const pEventPath = pathBuilder.BuildPath(i_pArgs);
 *   CHECK_POINTER_RETV_MSG(pEventPath, 0, "Failed to build the path of the event");
 *
 *   // dispatch the event
 *   pEventPath->Dispatch(i_pArgs);
 *
 *   // delete the path
 *   delete pEventPath;
 *
 *   return 1;
 * }
 * @endcode
 * It can be simplified using the @ref CATSYPEventPathBuilder#Dispatch
 * shortcut method:
 * @code
 * int MyNode::Dispatch(CATSYPEventArgs *i_pArgs) {
 *   MyPathBuilder pathBuilder;
 *   return pathBuilder.Dispatch(this, i_pArgs);
 * }
 * @endcode
 *   
 * @see groupSypEventRegistration
 * @see groupSypEventHandlers  
 * @see groupSypEvent
 */
