#ifndef CATSYPEventPathElt_H
#define CATSYPEventPathElt_H

#include <UIVCoreTools.h>
#include <CATSYPArray.h>
#include <CATSYPEventHandlerInfoList.h>
#include <CATBaseUnknown_var.h>

class CATSYPEventArgs;

/** @ingroup groupSypEventDispatching
 * An element of a @ref CATSYPEventPath that associates a node with
 * the lists of its handlers for a given event.
 *
 * @c AddRef is called on the the node to keep an hard reference on
 * it. 
 *
 * The handlers are kept in copies of @ref CATSYPEventHandlerInfoList
 * lists. Note that we keep a several lists since the handler
 * registration infrastructure may use more than one list of handler
 * for a given event (for example to support class handlers; see
 * @ref CATSYPClassEventHandlerSupport for example).
 */
class ExportedByUIVCoreTools CATSYPEventPathElt
{
public:
  /** 
   * Initialize this class.
   *
   * @param i_spNode the node represented by this element. Can't be 
   * @c NULL.
   */
  CATSYPEventPathElt(CATBaseUnknown *i_spNode);

  /** Destory this class */
  virtual ~CATSYPEventPathElt();

  /**
   * Append a list of handlers in this element.
   *
   * A copy of the input list will be kept by this class. Due to the
   * copy-on-write behavior of this kind of list, a modification of @c
   * i_list after this function has been called won't affect the copy
   * made by this class.
   *
   * @param i_list the list to copy.
   */
  void AddList(const CATSYPEventHandlerInfoList &i_list);

  /**
   * Dispatch the event to all the handlers in all lists of this
   * element.
   *
   * Handlers are called in their order in each list; lists are
   * traversed in the order they have been added to this element.
   *
   * Handlers are called if either:
   *   - their @ref CATSYPEventHandlerInfo is in 
   *     `handleConsumedEvents' mode
   *   - or the event has not been consumed
   *
   * The `i_pSender' argument to the @ref CATSYPEventHandler#Call will
   * be a reference to the node.
   *
   * @note
   * This function won't check the compatibility of the given
   * arguments and the handlers supported arguments type. It is the
   * responsibility of the handler registration infrastructure to
   * check that.
   *
   * @param i_pArgs the arguments. Can't be @c NULL.
   */
  void Dispatch(CATSYPEventArgs *i_pArgs) const;
private:
  CATSYPEventPathElt(const CATSYPEventPathElt &);
  CATSYPEventPathElt &operator=(const CATSYPEventPathElt &);
private:
  /** the node */
  CATBaseUnknown_var _spNode;

  /** list of lists of handlers for a given event on the node */
  CATSYPDynArray<CATSYPEventHandlerInfoList> _lists;
};

#endif // CATSYPEventPathElt_H
