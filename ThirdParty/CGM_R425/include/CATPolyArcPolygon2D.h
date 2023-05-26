// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyArcPolygon2D.h
// Header definition of CATPolyArcPolygon2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2012 Creation: JXO
//===================================================================
#ifndef CATPolyArcPolygon2D_H
#define CATPolyArcPolygon2D_H

// ExportedBy
#include "PolygonalModel.h"

// Polygon model
#include "CATPolyPolygon2D.h"
#include "CATPolyBarIter2D.h"
#include "CATPolySegmentIterator2D.h"

// Poly maths
#include "CATMapOfPtrToPtr.h"

// Maths
#include "CATMathPoint2D.h"

// System
#include "CATErrorDef.h"
#include "CATListPV.h"

class CATPolyBar2D;

/**
 * CATPolyArcPolygon2D defines a 2D polygon with line segments and circle arcs.
 * Segments are defined by their extremities.
 * Arcs are defined by their extremities and one intermediary point.
 */
class ExportedByPolygonalModel CATPolyArcPolygon2D : private CATPolyPolygon2D
{
public:
  CATPolyArcPolygon2D() : CATPolyPolygon2D() {}

  using CATPolyPolygon2D::AddVertex;
  using CATPolyPolygon2D::AddBar;

  HRESULT AddVertex(CATPolyVertex2D*& oVertex, const CATMathPoint2D& iPoint);
  HRESULT AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D*& oBar, const CATMathPoint2D& ArcPoint);

  /**
   * Iterator on the bars on all the bars.
   */
  class ExportedByPolygonalModel Iterator : public CATPolySegmentIterator2D
  {
  public:
    Iterator(const CATPolyArcPolygon2D & iPolygon);
    CATPolySegmentIterator2D & Begin ();
    CATBoolean End() const;
    CATPolySegmentIterator2D & operator ++();
    CATPolyBar2D * Get() const;
    const CATMathPoint2D & GetStartPoint() const;
    const CATMathPoint2D & GetEndPoint() const;
    const CATMathPoint2D * GetArcPoint() const;

  private:
    CATPolyBarIter2D m_iter;
    CATPolyBar2D* m_bar;
  };

  friend class Iterator;
};

inline HRESULT CATPolyArcPolygon2D::AddVertex(CATPolyVertex2D*& oVertex, const CATMathPoint2D& iPoint)
{
  return CATPolyPolygon2D::AddVertex(iPoint, oVertex);
}

inline HRESULT CATPolyArcPolygon2D::AddBar(CATPolyVertex2D* iVertex0, CATPolyVertex2D* iVertex1, CATPolyBar2D*& oBar, const CATMathPoint2D& ArcPoint)
{
  return CATPolyPolygon2D::AddBar(iVertex0, iVertex1, ArcPoint, true, oBar);
}

#endif
