// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodySimpleClashResultIterator.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Nov 2009 Creation: JXO
//===================================================================

#ifndef CATPolyBodySimpleClashResultIterator_h
#define CATPolyBodySimpleClashResultIterator_h

#include "PolyBodyBVHOperators.h"
#include "CATPolyBodySimpleClashOper.h"
#include "CATPolyRefCounted.h"

// System
#include "CATBoolean.h"
#include "CATListPV.h"
class CATIPolyCurveIterator;

class CATPolyBodySimpleClashFaceEdgeIterator;

class ExportedByPolyBodyBVHOperators CATPolyBodySimpleClashResultIterator : public CATPolyRefCounted
{
public:
  CATPolyBodySimpleClashResultIterator();
  ~CATPolyBodySimpleClashResultIterator();

  enum SortType
  {
    NoSort = 0,
    Ascending1,
    Ascending2,
    Descending1,
    Descending2
  };

  /**
   * Sets the iterator at the beginning.
   */
  void Begin();
  /**
   * Returns TRUE if you're at the end (no result in this case), FALSE otherwise.
   */
  CATBoolean End();
  /**
   * Increments the iterator.
   */
  void operator ++();
  /**
   * Sorts the colling couples list on the IDs.
   * Side effect is that the list is reset to its beginning.
   */
  void Sort(SortType iSortType);

  /**
   * Results:
   */

  /**
   * Returns ID of first colliding Polybody.
   * ID corresponds to the one in CATPolyBodyBVHTreeSet.
   */
  int GetFirstID();
  /**
   * Returns ID of second colliding Polybody.
   * ID corresponds to the one in CATPolyBodyBVHTreeSet.
   */
  int GetSecondID();
  /**
   * Returns an iterator on the faces/edges intersections. Should be released by caller.
   * @return [out, IUnknown#Release]
   */
  CATPolyBodySimpleClashFaceEdgeIterator * GetFaceEdgeIterator();
  /**
   * Returns the clash status between the two colliding polybodies
   */
  CATPolyBodySimpleClashOper::ClashStatus GetClashStatus();

  /**
   * Returns an iterator on the curves, do not delete!
   */
  const CATIPolyCurveIterator * GetCurveIterator();

  /**
   * Addition of a new result.
   * iFaceIter can be released afterwards.
   */
  void Add(int iID1, int iID2, CATPolyBodySimpleClashFaceEdgeIterator * iFaceEdgeIter, CATPolyBodySimpleClashOper::ClashStatus iStatus);
  /**
   * Addition of a new result.
   * iCurveIterator now belongs to the SimpleClashResultIterator and will be deleted by it.
   */
  void Add(int iID1, int iID2, CATIPolyCurveIterator * iCurveIterator, CATPolyBodySimpleClashOper::ClashStatus iStatus);

private:
  CATListPV _Results;
  int _index;
  
};

#endif /* CATPolyVisuInterfBVHTreeSet_h */
