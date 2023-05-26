#ifndef CATSYPEventPath_H
#define CATSYPEventPath_H

#include <UIVCoreTools.h>
#include <CATSYPArray.h>

class CATSYPEventPathElt;
class CATSYPEventArgs;

/** @ingroup groupSypEventDispatching
 * The path of propagation of an event in the tree of objects.
 *
 * The path freezes the list of nodes to call, and for each node the
 * list of handlers to call (pointed by a @ref CATSYPEventHandlerInfo
 * that also stores a flag indicating if the handler should be called
 * for consumed events).
 *
 * The path depends on the event (and maybe the arguments of the
 * event) that will be dispatch; for example:
 *   - the order of the nodes may depend on the propagation mode of
 *     the event (see @ref CATSYPEvent#Propagation).<br/>
 *     When using @ref CATSYPEvent#NoPropagation, there can be only
 *     one node in the path.
 *   - the handlers for each node depend on the type of event (it 
 *     may also depend on the arguments; this is a design decision 
 *     of the dispatching infrastructure)
 *
 * Consequently the exact use of this class depends on the dispatching
 * infrastructure. Please consult the documentation of @ref #Dispatch
 * method before taking any decision.
 *
 * The actual dispatching is made using @ref #Dispatch method. No
 * tests will be made on the @ref CATSYPEventArgs when this method is
 * called; this is not the point of this class to test that, it is the
 * responsibility of the caller.
 *
 * @note
 * This class uses @ref CATSYPEventPathElt objects to represent each
 * node. This kind of object keep copies of @ref CATSYPEventHandlerInfoList.
 * Those lists references the immutable objects @ref CATSYPEventHandlerInfo.
 * As a consequence, once built, a path can't be modified implicitely
 * by a modification in the handler registration infrastructure.<br/>
 * This is an important design principle that ensure that when using a
 * @c CATSYPEventPath to implement the dispatching, the dispatching of
 * one event can't be influenced by modifications of the object tree
 * or modifications of handlers lists.
 *
 * @see CATSYPEvent
 */
class ExportedByUIVCoreTools CATSYPEventPath
{
public:
  /** Initialize this class */
  CATSYPEventPath();

  /** Destory this class */
  virtual ~CATSYPEventPath();

  /**
   * Append an element to this path.
   *
   * The path takes the ownership of the element and will destroy it
   * when it is itself destroyed.
   *
   * @note
   * This method must not be call while @ref #Dispatch is being
   * called.
   *
   * @param i_pElem the element to append. Can't be @c NULL. This
   * class takes the ownership of this object.
   */
  void AddElement(CATSYPEventPathElt *i_pElem);

  /**
   * Dispatch the event to all nodes of the path.
   *
   * The dispatching will occur in the order of addition of the nodes
   * in the path.
   *
   * See @ref CATSYPEventPathElt#Dispatch for details about how
   * handlers are called on each node.
   *
   * @note
   * @ref #AddElement must not be called while this method is being
   * called.
   *
   * @note
   * This method is reentrant.
   *
   * @param i_pArgs the arguments of the event to dispatch. Can't be
   * @c NULL. No test is made on the values of this argument (except
   * that is must not be @c NULL). It is the responsibility of the
   * caller to ensure that @c i_pArgs contains coherent values and is
   * the event expected by handlers referenced by this path.
   *
   * @see #AddElement
   */
  void Dispatch(CATSYPEventArgs *i_pArgs);
private:
  CATSYPEventPath(const CATSYPEventPath &);
  CATSYPEventPath &operator=(const CATSYPEventPath &);
private:
  /** the list of nodes in the path */
  CATSYPDynArray<CATSYPEventPathElt*> _elements;
};

#endif // CATSYPEventPath_H
