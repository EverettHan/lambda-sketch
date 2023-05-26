// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonSplitBarsObserver2D.h
//
//===================================================================
// November 2011  Creation NDO
//===================================================================
#ifndef CATPolyPolygonSplitBarsObserver2D_H
#define CATPolyPolygonSplitBarsObserver2D_H

#include "PolygonalBoolean.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)

class CATPolyVertex2D;
class CATPolyBar2D;


/**
* Observer base class of a split-bars event.
*/
class ExportedByPolygonalBoolean CATPolyPolygonSplitBarsObserver2D
{

public :

  CATPolyPolygonSplitBarsObserver2D () {}
  virtual ~CATPolyPolygonSplitBarsObserver2D () {}

public:

/** @name Listening to Event
    @{ */

  /**
   * A call made before two intersecting bars are split by a new vertex.
   * @param iBar0
   *   The first bar.
   * @param iBar1
   *   The second bar.
   * @param iVertex
   *   The vertex constructed by intersecting the two bars.  
   */
  virtual HRESULT PrepareToSplitBars (const CATPolyBar2D* iBar0, const CATPolyBar2D* iBar1, const CATPolyVertex2D* iVertex) = 0;

/** @} */

};

#endif
