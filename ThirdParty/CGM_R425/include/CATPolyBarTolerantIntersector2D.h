// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBarTolerantIntersector2D.h
//
//===================================================================
// July 2018  Creation: xxc
// April 2020 Fix bugs - Tip contact only construction + exact segment detection
//===================================================================
#ifndef CATPolyBarTolerantIntersector2D_H
#define CATPolyBarTolerantIntersector2D_H

#include "CATBoolean.h"
#include "PolygonalBoolean.h"
#include "CATPolyIntersection.h"
#include "CATErrorDef.h"
#include "CATPolyBarIntersector2D.h"
#include "CATMathPoint2D.h"
#include "CATPolyOverlayClosestPointConstructor2D.h"
#include "CATPolyIntersectionPointDefaultConstructor2D.h"

class CATPolyBar2D;
class CATPolyExactArithmetic;
class CATPolyPolygonOverlayOptions2D;

/**
 */
class ExportedByPolygonalBoolean CATPolyBarTolerantIntersector2D : public CATPolyBarIntersector2D
{
public:

  CATPolyBarTolerantIntersector2D (const CATPolyPolygonOverlayOptions2D & iOptions, bool iTipIntersectionOnly = false);
  virtual ~CATPolyBarTolerantIntersector2D ();

public:
  void UseReclassification(CATBoolean iReclassification);

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
                             CATMathPoint2D& oIntersectionPoint);

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
                                        CATMathPoint2D & P2);

private:

  bool TestBVBV(const CATMathPoint2D & V0L, const CATMathPoint2D & V0R,
                const CATMathPoint2D & V1L, const CATMathPoint2D & V1R, double tol);

private:
  void ClearResult();
  double _SqTolerance;
  double _Tolerance;
  const CATPolyPolygonOverlayOptions2D & _Options;
  const CATPolyExactArithmetic & _ExactArithmetic;
  CATPolyOverlayClosestPointConstructor2D _TipConstructor;
  CATPolyIntersectionPointDefaultConstructor2D _InsideConstructor;
  bool _TipIntersectionOnly;
  CATBoolean _Reclassify;
  const CATPolyBar2D * m_bar1;
  const CATPolyVertex2D * m_V11;
  const CATPolyVertex2D * m_V12;
  CATMathPoint2D m_P1;
  const CATPolyBar2D * m_bar2;
  const CATPolyVertex2D * m_V21;
  const CATPolyVertex2D * m_V22;
  CATMathPoint2D m_P2;
};

#endif
