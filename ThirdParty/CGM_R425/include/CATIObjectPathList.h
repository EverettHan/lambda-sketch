#ifndef CATIObjectPathList_h
#define CATIObjectPathList_h
/* COPYRIGHT DASSAULT SYSTEMES 1999 */

#include <IUnknown.h>

class CATIObjectPath;

/**
 * This interface abstracts a list of IUnknown interface pointers.
 * The first element in the list has index 0.
 */
class CATIObjectPathList : public IUnknown
{
public:
  
  /**
   * Returns the number of elements in the list.
   * @param oCount
   *   Number of elements
   */
  virtual HRESULT Count(unsigned int * oCount) const = 0;
  
  /**
   * Returns the iPosition-th element.
   * If iPosition does not respect respect the following rule:
   * 0 &lt;= position &lt; Count, E_FAIL is returned.
   * @param iPosition
   *   Element to be returned.
   * @param oItem
   *   Returned element.
   */
  virtual HRESULT Item(const unsigned int iPosition,
		       CATIObjectPath ** oItem) const = 0;
  
  /**
   * Adds an element at a given position in the list.
   * If iPosition does not respect respect the following rule:
   * 0 &lt;= position &lt;= Count, E_FAIL is returned.
   * The element to add must not be a NULL reference or
   * E_POINTER will be returned.
   * @param iPosition
   *   Position of the added element in the list.
   * @param iItem
   *   Element to be added.
   */
  virtual HRESULT Add(const unsigned int iPosition,
		      CATIObjectPath * iItem) = 0;
  
  /**
   * Removes the first occurence of an element from the list.
   * If the element cannot be found in the list, E_FAIL
   * is returned.
   * @param iItem
   *   Element to be removed.
   */
  virtual HRESULT Remove(CATIObjectPath * iItem) = 0;
};

/* 8D29A0AE-6925-0000-0280-020F32000000 */
extern "C" const IID IID_CATIObjectPathList;

#endif
