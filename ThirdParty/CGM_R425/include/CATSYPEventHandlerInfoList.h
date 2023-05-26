#ifndef CATSYPEventHandlerInfoList_H
#define CATSYPEventHandlerInfoList_H

#include <UIVCoreTools.h>


class CATSYPEventHandlerInfoListData;
class CATSYPEventHandlerInfo;
class CATSYPEventHandler;

/** @ingroup groupSypEventRegistration
 * A value-like class that is a list of @ref CATSYPEventHandlerInfo.
 *
 * This list keeps a reference on each item (using @c AddRef).
 *
 * @par Copy On Write
 * This list shares an internal structure that contains the actual
 * list of @ref CATSYPEventHandlerInfos. This internal structure is
 * shared between copies of the list until on list is modified. When
 * this happens, a clone of the internal structure is used and
 * modified.
 *
 * @par
 * As a consequence making copies of this list is pretty cheap.
 */
class ExportedByUIVCoreTools CATSYPEventHandlerInfoList
{
public:
  /** 
   * Initialize this class with an empty list.
   */
  CATSYPEventHandlerInfoList();

  /** 
   * Copy constructor.
   *
   * See class documentation about Copy On Write.
   */
  CATSYPEventHandlerInfoList(const CATSYPEventHandlerInfoList &i_other);

  /** 
   * Assignement operator.
   *
   * See class documentation about Copy On Write.
   */
  CATSYPEventHandlerInfoList &operator=(const CATSYPEventHandlerInfoList &i_other);

  /** Destroy this class */
  virtual ~CATSYPEventHandlerInfoList();

  /** 
   * Get the length of the list.
   *
   * @return the length. @c >=0.
   */ 
  int GetSize() const;

  /**
   * Get one of the item of the list.
   *
   * @param i_index the index of the item; must be in the range
   * <tt>[0;GetSize()-1]</tt>.
   *
   * @return the item. @c NULL if @c i_index is invalid (in that case
   * a @c FAILURE has been raised).
   */ 
  CATSYPEventHandlerInfo *Get(int i_index) const;

  /**
   * Append a new item.
   *
   * No check is made for duplication.
   *
   * @c AddRef will be called on @c i_pHandlerInfo.
   *
   * @param i_pHandlerInfo the item. Can't be @c NULL.
   *
   * @see #AddHandler
   */
  void Add(CATSYPEventHandlerInfo *i_pHandlerInfo);

  /**
   * Build a @ref CATSYPEventHandlerInfo with @c i_pHandler and 
   * @c i_handleConsumedEvents and add it to the list.
   *
   * This function is simply a shortcut to constructing the 
   * @c CATSYPEventHandlerInfo explicitely and adding it to this list
   * using @ref #Add.
   *
   * @param i_pHandler the handler to point. Can't be @c NULL. 
   * @c AddRef will be called on this pointer.
   *
   * @param i_handleConsumedEvents @c !=0 if the handler should be
   * called for consumed events.
   *
   * @see #Add
   * @see CATSYPEventHandlerInfo
   */
  void AddHandler(CATSYPEventHandler *i_pHandler, int i_handleConsumedEvents);

  /**
   * Remove an item.
   *
   * @param i_index the index of the item; must be in the range
   * <tt>[0;GetSize()-1]</tt>.
   */
  void Remove(int i_index);

  /**
   * Remove all items having a handler that returns @c !=0 when called
   * on @ref CATSYPEventHandler#ShouldAutoRemove.
   */
  void AutoRemove();
private:
  /**
   * Instantiate or clone if necessary the shared data to prepare for
   * a modification.
   *
   * This function will modify @ref #_pSharedData. This pointer won't
   * be @c NULL after calling this function unless an internal error
   * occured.
   */
  void UpdateDataForModification();
  
private:
  /** the shared data of the list.
      It will be @c NULL until an item is added in the list. */
  CATSYPEventHandlerInfoListData *_pSharedData;
};

#endif // CATSYPEventHandlerInfoList_H
