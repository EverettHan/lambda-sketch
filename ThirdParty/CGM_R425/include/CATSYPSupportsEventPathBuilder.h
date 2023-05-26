#ifndef CATSYPSupportsEventPathBuilder_H
#define CATSYPSupportsEventPathBuilder_H

#include <UIVCoreTools.h>
#include <CATSYPEventPathBuilder.h>

class CATSYPEventHandlersSupport;
class CATSYPClassEventHandlersSupport;

/** @ingroup groupSypEventDispatching
 * Abstract specialization of @ref CATSYPEventPathBuilder that can be
 * used when the tree of nodes uses @ref CATSYPEventHandlersSupport to
 * store the handlers on its node and @ref CATSYPClassEventHandlersSupport
 * to associate static handlers to classes.
 *
 * @par Specialization
 * This specialization implements @ref #BuildElement. It requires the
 * sub-class to implement two new pure-virtual methods instead:
 *   - @ref #GetSupportForNode that returns the @ref CATSYPEventHandlersSupport
 *     of a node
 *   - @ref #GetClassSupportForNode that returns the class support of the
 *     node tree. 
 *
 * @par
 * They will be used to find out the list of handlers for the event
 * being dispatched.<br/>
 * The handlers lists will be order this way:
 *   - the handlers of the class of the node for the given event
 *   - the handlers of the parent class of the node for the given event
 *   - ...
 *   - the handlers of CATBaseUnknown for the given event
 *   - the handlers of the node for the given event
 *
 * @par
 * As a consequence, the static handlers registered for classes on the
 * @ref CATSYPClassEventHandlersSupport will be called before handlers
 * registered on the instance of the node. And the handler on the class
 * will be called before the handler of its parent class.
 *
 * @par
 * The returned @ref CATSYPEventPathElt will be associated with the
 * node.
 * 
 * @par
 * This class leaves @ref CATSYPEventPathBuilder#GetParent
 * unimplemented.
 *
 * @see CATSYPEventHandlersSupport
 */
class ExportedByUIVCoreTools CATSYPSupportsEventPathBuilder : public CATSYPEventPathBuilder
{
public:
  /** Initialize this class */
  CATSYPSupportsEventPathBuilder();
  /** Destory this class */
  virtual ~CATSYPSupportsEventPathBuilder();

protected:
  /** 
   * @copydoc CATSYPEventPathBuilder#BuildElement 
   * @see #GetSupportForNode
   */
  virtual CATSYPEventPathElt *BuildElement(CATSYPEventArgs *i_pArgs, CATBaseUnknown *i_pNode);

  /**
   * This support is used as a return value of @ref #GetSupportForNode
   * to indicate that the node don't have a support.
   *
   * @return the support indicating that a node has no support. Can't
   * be @c NULL.
   *
   * @see #GetSupportForNode
   */
  static CATSYPEventHandlersSupport *NO_SUPPORT();

  /**
   * This support is used as a return value of @ref #GetClassSupportForNode
   * to indicate that the node tree don't have a class support.
   *
   * @return the support indicating that a node tree has no static
   * support. Can't be @c NULL.
   *
   * @see #GetClassSupportForNode
   */
  static CATSYPClassEventHandlersSupport *NO_CLASS_SUPPORT();

  /**
   * Get the support of the node.
   *
   * This function will be called by the implementation of 
   * @ref #BuildElement to obtain the support for each node.
   *
   * @param i_pNode the node. Can't be @c NULL.
   *
   * @return the support or @ref #NO_SUPPORT if there is no support
   * for the node. @c NULL in case of error (in that case the
   * construction of the path will fail).
   *
   * @see #NO_SUPPORT
   */
  virtual CATSYPEventHandlersSupport *GetSupportForNode(CATBaseUnknown *i_pNode) = 0;

  /**
   * Get the static class support of the node.
   *
   * This function will be called by the implementation of 
   * @ref #BuildElement to obtain the support for each node. It should
   * return the same value value for each node (since they belong to
   * the same kind of tree).
   *
   * @param i_pNode the node. Can't be @c NULL.
   *
   * @return the support or @ref #NO_CLASS_SUPPORT if there is no
   * class support for the node tree. @c NULL in case of error (in
   * that case the construction of the path will fail).
   *
   * @see #NO_CLASS_SUPPORT
   */
  virtual CATSYPClassEventHandlersSupport *GetClassSupportForNode(CATBaseUnknown *i_pNode) = 0;

private:
  CATSYPSupportsEventPathBuilder(const CATSYPSupportsEventPathBuilder &);
  CATSYPSupportsEventPathBuilder &operator=(const CATSYPSupportsEventPathBuilder &);
};

#endif // CATSYPSupportsEventPathBuilder_H
