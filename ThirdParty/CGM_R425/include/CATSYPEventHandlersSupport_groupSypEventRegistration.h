/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group groupSypEventRegistration.
 */

#error this file must never be included; doxygen file only.

/** @ingroup groupSypEvent
 * @defgroup groupSypEventRegistration Event Registration
 *
 * The <b>Event Registration</b> sub-module groups classes that takes
 * in charge the registration of event handlers on nodes of the tree.
 *
 * Handlers are implementations of the @ref CATSYPEventHandler C++
 * interface (see @ref groupSypEventHandlers for details).
 *
 * There are two kind or registration:
 *   - node instance registration
 *   - static class registration
 *
 * @par Node Instance Registration
 * Handlers can be registered on one instance of node in a tree node.
 * They are associated to a specific @ref CATSYPEvent.
 *
 * @par
 * This registration is implemented on nodes using the @ref
 * CATSYPEventHandlersSupport class. This class also stores an
 * additional information for each handler: a boolean flag indicating
 * if the handler should be called for consumed events (see @ref
 * CATSYPEventArgs#IsConsumed).
 *
 * @par Static Class Registration
 * Handlers may also be registered for any instance of a class and for
 * a specific @ref CATSYPEvent.
 *
 * @par 
 * This is implemented on a kind of tree node using a single instance
 * of the @ref CATSYPClassEventHandlersSupport class.
 *
 * @par Internal Classes
 * The @ref CATSYPEventHandlersSupport uses the @ref
 * CATSYPEventHandlerInfo class to point a handler and store the
 * boolean flag indicating if the handler should be called for handled
 * events. This class is immutable.
 *
 * @par
 * The @ref CATSYPEventHandlerInfoList can be used to keep a list of
 * handlers. This class is a value-like class with a copy-on-write
 * behavior that ensure that copies are efficient.
 *
 * @par
 * Both @ref CATSYPEventHandlerInfo and @ref CATSYPEventHandlerInfoList
 * are reused by the @link groupSypEventDispatching Event
 * Dispatching@endlink.
 *
 * @par Implementation Notes
 * The @ref CATSYPEventHandlersSupport class should not be directly
 * available to clients of the tree node; instead a node should
 * contain @c AddHandler and @c RemoveHandler functions that forward
 * their calls to the node's support. This way the event registration
 * infrastucture may be changed in the future without impacting the
 * clients.
 *
 * @par
 * Some template functions that can create an instance of @ref
 * CATSYPStaticEventHandler or @ref CATSYPWRefMethEventHandler and
 * register it are available to make registration easier (see @ref
 * AddCATSYPStaticEventHandler, @ref AddCATSYPWRefMethEventHandler for
 * example).
 *
 * @par
 * The @ref CATSYPClassEventHandlersSupport should also not be directly
 * available. It may be used through static functions on the root
 * class shared by all node classes of the tree, for example @c
 * AddClassHandler and @c RemoveClassHandler. These should forward
 * calls to the static instance of the class support.
 *
 * @par
 * Some static template functions are available to create instances of
 * @ref CATSYPStaticEventHandler or @ref CATSYPSenderMethEventHandler
 * and register them on the class support (see @ref
 * AddSCATSYPStaticEventHandler, @ref AddSCATSYPSenderMethEventHandler
 * for example).
 *
 * @see groupSypEventHandlers
 * @see groupSypEventDispatching
 * @see groupSypEvent
 */
