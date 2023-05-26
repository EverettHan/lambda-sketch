#ifndef CATPolyBentleyOttmannInterface_H
#define CATPolyBentleyOttmannInterface_H

#include "PolygonalBoolean.h"

class CATPolyVertex2D;
class CATPolyBar2D;
class CATMathPoint2D;
class CATExpFPExpansion;

/*
 * An interface for implementing predicates used by BentleyOttmann algorithm when vertex coordinates cannot be represented as double.
 */
class CATPolyBentleyOttmannExactCoordinateInterface
{
public:
  /*
   * A bar defined by its left and right vertices.
   * The vertices in this structure will always be vertices which exist pior to BentleyOttmann run, never intersection vertices.
   */
  struct Bar
  {
    CATPolyVertex2D const &leftVertex;
    CATPolyVertex2D const &rightVertex;
  };

  /*
   * An intersection vertex is defined by the vertex created and returned by IsIntersecting
   * and the two input bars of IsIntersecting.
   */
  struct IntersectionVertex
  {
    CATPolyVertex2D const &vertex;
    Bar bottomBar;
    Bar topBar;
  };

  /*
   * Comparison functions between vertices.
   * CATPolyVertex2D vertices exist pior to BentleyOttmann run and IntersectionVertex are intersection vertices
   */
  virtual int Compare(CATPolyVertex2D const& iVertex1, CATPolyVertex2D const& iVertex2) = 0;
  virtual int Compare(CATPolyVertex2D const& iVertex1, IntersectionVertex const &iVertex2) = 0;
  virtual int Compare(IntersectionVertex const& iVertex1, IntersectionVertex const& iVertex2) = 0;

  /*
   * Compute the sign of the determinant | (iVertex1, iVertex2) (iVertex1, iVertex3) |.
   * All vertices here exist pior to BentleyOttmann run.
   */
  virtual int Orientation(CATPolyVertex2D const& iVertex1, CATPolyVertex2D const& iVertex2, CATPolyVertex2D const& iVertex3) = 0;

  /*
   * Returns a new vertex describing the intersection between the two bars if they intersect
   * a null ptr otherwise.
   * The function might be called several times with the same bars.
   * Left vertex of iBottomBar (resp iTopBar) is below (resp above) iTopBar (resp iTopBar).
   */
  virtual CATPolyVertex2D* IsIntersecting(Bar const& iBottomBar, Bar const& iTopBar) = 0;

  /*
   * Compute pixel length as 2^p so 2^p <= iTolerance < 2^{p+1}
   */
  ExportedByPolygonalBoolean static double GetPixelLength(double iTolerance);

  /*
   * Utility functions to snap coordinate x on a grid.
   * The result is the closest multiple of pixelLength to x.
   * Vertex coordinates are ignored when this interface is enabled but using approx coordinates 
   * can be useful to optimize computation of predicates.
   */
  ExportedByPolygonalBoolean static CATMathPoint2D SnapOnGrid(double pixelLength, CATMathPoint2D const &iPoint);
  ExportedByPolygonalBoolean static double SnapOnGrid(double pixelLength, double x);
  ExportedByPolygonalBoolean static double SnapOnGrid(double pixelLength, CATExpFPExpansion const& x);
};

#endif
