// COPYRIGHT DASSAULT SYSTEMES 2011, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarDefaultIntersector2D.h
//
//===================================================================
// December 2011  Creation: ndo
//===================================================================
#ifndef CATPolyBarDefaultIntersector2D_H
#define CATPolyBarDefaultIntersector2D_H

#include "PolygonalBoolean.h"
#include "CATPolyIntersection.h"
#include "CATPolyBarIntersector2D.h"
#include "CATPolySegmentIntersector2D.h"
#include "CATErrorDef.h"

class CATPolyBar2D;
class CATPolyExactArithmetic;
class CATPolyIntersectionPointConstructor2D;
class CATMathPoint2D;


/**
 * Implements a default a bar intersector.  
 * This implementation uses the exact arithmetic to determine if the bars intersect or not.
 *
 * If there is a point intersection between the two bars, it computes it given 
 * an intersection point constructor.  Without the point constructor, the method
 * will fail with an error.
 */
class ExportedByPolygonalBoolean CATPolyBarDefaultIntersector2D : public CATPolyBarIntersector2D
{

public:

  /**
   * Constructor.  
   * Without an intersection-point construction, the method Intersect () will fail 
   * when there is a point-intersection between the two bars.
   */
  CATPolyBarDefaultIntersector2D (const CATPolyExactArithmetic& iExactArithmetic);

  /**
   * Constructor.  
   * @param iExactArithmetic
   * @param iPointConstructor
   *   An intersection-point constructor for computation of the point-intersection.
   */
  CATPolyBarDefaultIntersector2D (const CATPolyExactArithmetic& iExactArithmetic, 
                                  const CATPolyIntersectionPointConstructor2D& iPointConstructor);

  virtual ~CATPolyBarDefaultIntersector2D () {}

public:

  /**
   * Implements CATPolyBarIntersector2D::Intersect.
   *
   * The method will return a symbolic description of the intersection between the two bars.
   * If there is a point intersection between the two bars, it will compute it given the point constructor.
   * Without the point construction, the method fails when there is a point intersection with an error.
   * @param iBar0
   *  The first bar.
   * @param iBar1
   *  The second bar.
   * @param oIntersectionType
   *  An output parameter describing the symbolic intersection between the two bars.
   * @param oError
   *  A description of the error when the call to the method fails.
   *  Without a point constructor, the error is set to CATPolyIntersection::eBadConstruction
   *  when there is a point intersection between the two bars and the method returns <tt>E_FAIL</tt>
   */
  HRESULT Intersect (const CATPolyBar2D& iBar0, const CATPolyBar2D& iBar1, 
                     CATPolyIntersection::Type& oIntersectionType, CATPolyIntersection::Error& oError,
                     CATMathPoint2D& oIntersectionPoint);


  /**
   * Implements CATPolyBarIntersector2D::Intersect.
   *
   * The method will return a symbolic description of the intersection between the two bars.
   * If there is a point intersection between the two bars, it will compute its barycentric coordinates w.r.t. both bars.
   * @param iBar0
   *  The first bar.
   * @param iBar1
   *  The second bar.
   * @param oIntersectionType
   *  An output parameter describing the symbolic intersection between the two bars.
   * @param oError
   *  A description of the error when the call to the method fails.
   */
  HRESULT Intersect (const CATPolyBar2D& iBar0, const CATPolyBar2D& iBar1,
                     CATPolyIntersection::Type& oIntersectionType, CATPolyIntersection::Error& oError,
                     double oBar0Coords[2], double oBar1Coords[2]);

private:

  CATPolySegmentIntersector2D _Intersector;

};

#endif
