// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarIntersector2D.h
//
//===================================================================
// April 2008  Creation: ndo
//===================================================================
#ifndef CATPolyBarIntersector2D_H
#define CATPolyBarIntersector2D_H

#include "PolygonalBoolean.h"
#include "CATPolyIntersection.h"
#include "CATErrorDef.h"

class CATPolyBar2D;
class CATPolyVertex2D;
class CATMathPoint2D;


/**
 * Interface to a bar intersector.  
 * This interface provides the mean of computing the intersection of two bars from a polygon.
 * Different behaviors of the bar intersector can be implemented.
 *
 * @see CATPolyBarDefaultIntersector2D
 */
class ExportedByPolygonalBoolean CATPolyBarIntersector2D
{

public:

  virtual ~CATPolyBarIntersector2D () {}

public:

  /**
   * Computes the intersection between two bars.
   * The method sets an enum argument that describes the type of the intersection (symbolic type).
   * If an error occurs during the computation of the intersection, an error code is also set.
   * (see CATPolyIntersection).
   * @param iBar0
   *   The first bar.
   * @param iBar1
   *   The second bar.
   * @param oIntersectionType
   *   The type of the intersection (see CATPolyIntersection).
   * @param oError
   *   An enum corresponding to a potential error (see CATPolyIntersection).
   * @param oIntersectionPoint
   *   The constructed intersection point.
   * @return
   * <ul>
   *   <li> <tt>S_OK</tt> if the computation of the intersection succeeds; and,
   *   <li> <tt>E_FAIL</tt> if the computation of the intersection fails.
   * </ul>
   */
  virtual HRESULT Intersect (const CATPolyBar2D& iBar0, const CATPolyBar2D& iBar1, 
                             CATPolyIntersection::Type& oIntersectionType, CATPolyIntersection::Error& oError,
                             CATMathPoint2D& oIntersectionPoint) = 0;
  /**
   * In case of eSegmentIntersection, returns the logical description.
   */ 
  virtual HRESULT GetSegmentDescription(const CATPolyBar2D *& bar1,
                                        const CATPolyVertex2D *& V11,
                                        const CATPolyVertex2D *& V12,
                                        const CATPolyBar2D *& bar2,
                                        const CATPolyVertex2D *& V21,
                                        const CATPolyVertex2D *& V22,
                                        CATMathPoint2D & P1,
                                        CATMathPoint2D & P2)
  {return S_FALSE;}
};

#endif
