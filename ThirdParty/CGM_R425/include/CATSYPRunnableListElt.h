#ifndef CATSYPRunnableListElt_H
#define CATSYPRunnableListElt_H


#include <UIVCoreTools.h>
#include <CATSysMacroPtr.h>
class CATSYPRunnable;

/** @ingroup groupUIVCoreToolsThreading
 * Element in linked list @ref CATSYPRunnableList.
 *
 * The next element is pointed by @ref #pNext; the value is @ref
 * #pRunnable.
 *
 * @see CATSYPRunnableList.
 */
struct ExportedByUIVCoreTools CATSYPRunnableListElt
{
  /** next element in the list */
  CATSYPRunnableListElt *pNext;

  /** pointer on the runnable; it will be released by destructor of
      this class */
  CATSYPRunnable *pRunnable;

  /** 
   * Initialize this class with @a i_pRunnable and @c NULL for @ref #pNext 
   *
   * The reference count of @a i_pRunnable will be incremented.
   */
  CATSYPRunnableListElt(CATSYPRunnable *i_pRunnable);

  /** Destroy this class and release @ref #pRunnable */
  ~CATSYPRunnableListElt();

  /**
   * Destroy each element of a list starting from @a i_pHead and
   * continuing until @ref #pNext is @c NULL.
   *
   * @param i_pHead the head of the list; can be @c NULL in that case
   * no action is taken (as with an empty list).
   */
  static void DestroyList(CATSYPRunnableListElt *i_pHead);

private:
  CATSYPRunnableListElt(const CATSYPRunnableListElt &);
  CATSYPRunnableListElt &operator=(const CATSYPRunnableListElt &);
};


#endif // CATSYPRunnableListElt_H
