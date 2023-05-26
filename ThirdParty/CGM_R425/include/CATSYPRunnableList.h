#ifndef CATSYPRunnableList_H
#define CATSYPRunnableList_H


#include <UIVCoreTools.h>
#include <CATSYPRunnableListElt.h>
class CATSYPRunnable;

/** @ingroup groupUIVCoreToolsThreading
 * Linked list of @ref CATSYPRunnable.
 *
 * The @ref CATSYPRunnable instances are referenced (using @ref
 * CATSYPRunnable#AddRef) by this class.
 *
 * This linked list can be used in a multi-threaded code but accesses
 * must be synchronized by the caller. It does not contain any
 * synchronization mechanism.
 */
class ExportedByUIVCoreTools CATSYPRunnableList
{
public:
  /** Initialize this class */
  CATSYPRunnableList();

  /** Destroy this class */
  ~CATSYPRunnableList();

  /** 
   * Add a new runnable at the end of the list.
   *
   * @param i_pRunnable the runnable. Can't be @c NULL. The reference
   * counter will be incremented.
   */
  void Append(CATSYPRunnable *i_pRunnable);

  /**
   * Remove all elements from the list and return the pointer on the
   * head.
   *
   * It is then the resonsibility of the caller to destroy those
   * elements, using @ref CATSYPRunnableListElt#DestroyList.
   *
   * Example
   * @code
   * CATSYPRunnableList &list = ...;
   *
   * // remove all elements from the list
   * CATSYPRunnableListElt * pHead = list.PopAll();
   *
   * // ... use pHead here ...
   *
   * // destroy list elements (works with pHead == NULL)
   * CATSYPRunnableListElt::DestroyList(pHead); pHead = NULL;
   * @endcode
   *
   * @return the head of the list
   *
   * @see #Clear
   */
  CATSYPRunnableListElt *PopAll();

  /**
   * Remove all elements from the list and destroy them.
   *
   * @see #PopAll.
   */
  void Clear();

  /**
   * Get head of the list.
   *
   * @return the head; @c NULL if list is empty.
   */
  CATSYPRunnableListElt *GetHead();

  /**
   * Get tail of the list.
   *
   * @return the tail; @c NULL if list is empty.
   */
  CATSYPRunnableListElt *GetTail();
private:
  CATSYPRunnableList(const CATSYPRunnableList &);
  CATSYPRunnableList &operator=(const CATSYPRunnableList &);
private:
  /** head of the linked list */
  CATSYPRunnableListElt *_pHead;

  /** tail of the linked list */
  CATSYPRunnableListElt *_pTail;
};


#endif // CATSYPRunnableList_H
