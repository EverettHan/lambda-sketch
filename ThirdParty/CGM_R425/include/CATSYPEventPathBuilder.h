#ifndef CATSYPEventPathBuilder_H
#define CATSYPEventPathBuilder_H

#include <UIVCoreTools.h>
#include <CATSYPArray.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPEventPathElt.h>

class CATSYPEventPath;
class CATSYPEventArgs;
class CATBaseUnknown;

/** @ingroup groupSypEventDispatching
 * Abstract builder of @ref CATSYPEventPath.
 *
 * This abstract implementation of a builder has to be specialized for
 * a specific tree node to build a dispatch path (@ref CATSYPEventPath) 
 * for an event.
 *
 * @par Path Construction
 * The construction of the path is iterative.
 *
 * @par
 * First the list of nodes in the path is built starting at the 
 * origin of the event (which must have been positioned on the event
 * args using @ref CATSYPEventArgs#SetOrigin before calling @ref #BuildPath
 * function) and going up the root.
 *
 * @par
 * For each node @ref #GetParent is called to obtain the parent node
 * of the current node. And the algorithm continue with @c
 * BuildElement until @c GetParent returns @c NULL.<br/>
 * Note that if the propagation mode is @ref CATSYPEvent#NoPropagation
 * then the algorithm stops at the origin.
 *
 * @par
 * Then for each node (including the origin) @ref #BuildElement is
 * called to build the item of the path corresponding to the
 * node.
 *
 * @par
 * The order of insertion of elements in the path will depends on the
 * propagation mode of the event. If the mode is @ref CATSYPEvent#RootToOrigin, 
 * @c BuildElement will be called first on the root. If the mode is 
 * @ref CATSYPEvent#OriginToRoot then it will start with the origin.
 *
 * @par Specialization
 * There are two functions to implement for specializing classes:
 *   - @ref #BuildElement
 *   - @ref #GetParent
 *
 * @par Shortcut Dispatch
 * To ease the use the of propagating events infrastructure a shortcut
 * @ref #Dispatch function is provided on this class.<br/>
 * It can be use when the user of @ref CATSYPEventPathBuilder does not
 * need to access to the built @ref CATSYPEventPath.
 */
class ExportedByUIVCoreTools CATSYPEventPathBuilder
{
public:
  /** Initialize this class */
  CATSYPEventPathBuilder();

  /** Destory this class */
  virtual ~CATSYPEventPathBuilder();

  /**
   * Build the propagation path of the event.
   *
   * See class documentation for details about the algorithm.
   *
   * @par Event Origin
   * The origin used to build the path will be retrieved on the
   * arguments using @ref CATSYPEventArgs#GetOrigin. As a consequence
   * the caller must ensure that the origin has been set before
   * calling this function.
   *
   * @par Arguments Type Compatibility
   * Before trying to build a path this function will check that the
   * type of @c i_pArgs is compatible with the expected arguments type
   * of the event (returned by @ref CATSYPEventArgs#GetEvent).
   *
   * @par
   * The type of @c i_pArgs must be the same class or a sub-class of
   * the type expected by the event.
   *
   * @param i_pArgs the arguments. Can't be @c NULL. The origin must
   * have been set to a non @c NULL value. It will be used to start
   * the path building algorithm.
   * 
   * @return the built path. @c NULL in case of invalid arguments or
   * internal error (in those case a @ref FAILURE has been raised).
   *
   * @see #BuildElement
   * @see #GetParent
   */
  CATSYPEventPath *BuildPath(CATSYPEventArgs *i_pArgs);

  /**
   * Shortcut function to dispatch an event.
   *
   * This function can be used to make a simple dispatch when the user
   * of this class does not need to access to the @ref
   * CATSYPEventPath.
   *
   * This function will:
   *   - if @c i_pArgs->GetOrigin() is @c NULL, set @a i_pArgs origin 
   *     to @a i_pOrigin.
   *   - if @c i_pArgs->GetOrigin() is not @c NULL, check that it is
   *     @a i_pOrigin and fail with a @ref FAILURE if not.
   *   - build the path using @ref #BuildPath.
   *   - fail with a FAILURE if returned path is @c NULL.
   *   - call @ref CATSYPEventPath#Dispatch on the built path.
   *   - delete the build path.
   * 
   * @param i_pOrigin the origin of the dispatch. Can't be @c NULL.
   *
   * @param i_pArgs the arguments of the event to dispatch (the
   * dispatched event is retrieved using @ref
   * CATSYPEventArgs#GetEvent). @ref CATSYPEventArgs#GetOrigin must be
   * either @a i_pOrigin or @c NULL.
   * 
   * @return @c !=0 if the dispatch succeeded, @c 0 if failed.
   */
  int Dispatch(CATBaseUnknown *i_pOrigin, CATSYPEventArgs *i_pArgs);

protected:

  /**
   * This element is used as a return value of @ref #BuildElement to
   * indicate that no element should be associated to the node being
   * built.
   *
   * @return the element to return to signal no value. Can't be 
   * @c NULL.
   *
   * @see #BuildElement
   */
  static CATSYPEventPathElt *NO_ELEMENT();

  /**
   * Build the element of the path for a node.
   *
   * See class documentation for details about the usage of this
   * function in the path building algorithm.
   *
   * @param i_pArgs the arguments. Can't be @c NULL.
   *
   * @param i_pNode the node. Can't be @c NULL.
   *
   * @return the created element or @ref #NO_ELEMENT if no element is
   * needed (for example when the node don't have any handlers for the
   * given event). @c NULL in case of error (in that case the
   * construction of the path will fail).
   *
   * @see #BuildPath
   * @see #NO_ELEMENT
   */
  virtual CATSYPEventPathElt *BuildElement(CATSYPEventArgs *i_pArgs, CATBaseUnknown *i_pNode) = 0;

  /**
   * Get the parent node of a node.
   *
   * See class documentation for details about the usage of this
   * function in the path building algorithm.
   *
   * @param i_pArgs the arguments. Can't be @c NULL.
   *
   * @param i_pNode the node. Can't be @c NULL.
   *
   * @return the parent node; @c NULL if there is no parent node. 
   * @c AddRef must NOT be called on the returned value.
   *
   * @see #BuildPath
   */
  virtual CATBaseUnknown *GetParent(CATSYPEventArgs *i_pArgs, CATBaseUnknown *i_pNode) = 0;
  
private:

  /**
   * Build the ordered list of nodes for the dispatching of the given
   * event.
   *
   * The list of nodes order will depend on the propagation mode of
   * the event. If the propagation mode is @ref CATSYPEvent#NoPropagation 
   * then only the origin will be added to the output list. If this
   * mode is @ref CATSYPEvent#RootToOrigin then the list will start
   * with the root and end with the origin.
   *
   * @param io_list the list to fill. @ref CATSYPArray#RemoveAll will
   * be called at the beginning of this function to ensure the list is
   * empty.
   *
   * @param i_pArgs the arguments of the event. Can't be @c NULL; the
   * origin must not be @c NULL.
   *
   * @return @c !=0 if the construction of the list succeeded; @c 0 if
   * it failed.
   */
  int FillListOfNodes(CATSYPArray<CATBaseUnknown_var> &io_list, CATSYPEventArgs *i_pArgs);

private:
  CATSYPEventPathBuilder(const CATSYPEventPathBuilder &);
  CATSYPEventPathBuilder &operator=(const CATSYPEventPathBuilder &);
};

#endif // CATSYPEventPathBuilder_H
