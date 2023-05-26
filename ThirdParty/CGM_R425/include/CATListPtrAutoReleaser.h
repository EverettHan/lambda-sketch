#ifndef CATListPtrAutoReleaser_H
#define CATListPtrAutoReleaser_H

#include "CATOmxListPtrHelpers.h"
#include "CATListPtrIterator.h"

/**
 * very basic wrapper on CATListPtr that ensures that the pointers are Release'd when the collection is destroyed
 *
 * the collection must be defined using CATLISTP_DECLARE/CATLISTP_DEFINE and must hold IUnknown derived AddRef'ed pointers
 *
 * only the destruction is handled, Append or any other declared method are not overriden to handle AddRef/Release.
 * (as we need to expose the raw "bad" collection, there is no way to wrap it safely)
 *
 * For example, given the function:
 * <code>
 *    //outputs a list of pointers that must be Release'd by caller
 *    void QueryListOfAddRefedPointers(CATListPtrCATIXXX& oPointers);
 * </code>
 *
 * you can safely replace this pattern:
 * <code>
 *   CATListPtrCATIXXX pointers;
 *   QueryListOfAddRefedPointers(pointers);
 *   for(int i=1; i<=pointers.Size(); i++)
 *   {
 *     //useful code
 *
 *     //Release pointer
 *     CATSysReleasePtr(pointers[i]);
 *   }
 * </code>
 *
 * by this one:
 * <code>
 *   CATListPtrAutoReleaser<CATListPtrCATIXXX> pointers;
 *   QueryListOfAddRefedPointers(pointers);
 *   for(int i=1; i<=pointers.Size(); i++)
 *   {
 *     //useful code
 *
 *     //no need to Release pointers
 *   }
 * </code>
 *
 * notice that this wrapper provides also range-for support.
 */
template<class CATListPtrXXX>
class CATListPtrAutoReleaser : public CATListPtrXXX
{
public:
  /** forward constructor from CATListPtr */
  inline CATListPtrAutoReleaser() {}
  /** forward constructor from CATListPtr */
  explicit inline CATListPtrAutoReleaser(int i) :CATListPtrXXX(i) {}

  /** empty the collection, pointers are Release'd*/
  inline void Clear() { CATOmxReleaseListPtr(*this); }
  /** destroy the collection, pointers are Release'd*/
  inline ~CATListPtrAutoReleaser() { Clear(); }

  /** range-for support */
  inline CATListPtrIterator<CATListPtrXXX> begin() const { return CATListPtrIterator<CATListPtrXXX>(*this, true); }
  /** range-for support */
  inline CATListPtrIterator<CATListPtrXXX> end() const { return CATListPtrIterator<CATListPtrXXX>(*this, false); }

private:
  CATListPtrAutoReleaser(const CATListPtrAutoReleaser&);
  CATListPtrAutoReleaser& operator=(const CATListPtrAutoReleaser&);
  CATListPtrAutoReleaser(const CATListPtrXXX&);
  CATListPtrAutoReleaser& operator=(const CATListPtrXXX&);
};

#endif
