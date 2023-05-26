// COPYRIGHT DASSAULT SYSTEMES 2016, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonCleaner2D.h
// Header definition of CATPolyPolygonCleaner2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2016 Creation: xxc
//===================================================================
#ifndef CATPolyPolygonCleaner2D_H
#define CATPolyPolygonCleaner2D_H

#include "PolygonalOperators.h"

#include "CATErrorDef.h"   // For the definition of HRESULT.
#include "CATBoolean.h"
#include "CATListPV.h"

class CATPolyPolygon2D;
class CATPolyBar2D;
class CATPolyLoop2D;
class CATPolyVertex2D;
class CATPolyExactArithmetic;
class CATMathPoint2D;
class CATTolerance;

/**
 This operator cleans a polygon in different ways. It can:
 - Remove filled faces inside other filled faces and wires inside filled faces,
 - Remove full vertices,
 - Remove aligned vertices,
 - Remove artefacts as very thin (almost degenerated) bars and triangles (vertex triplets linked by two or three bars),
 - Orient consistently a polygon CCW.
 By default, it systematicaly removes auto-intersections and orients
 the polygon according to the CCW orientation.

 Aligned vertices removal: Three vertices linked by two edges are
 considered aligned if they are relatively to the exact arithmetic
 given in the constructor. No tolerance is used except the one
 intrisic to computations performed by the exact arithmetic.

 The artefacts removal also removes full vertices. The tolerance under
 which an element is considered as an artefact is the
 EpsgForLengthTest() provided by the CATTolerance passed to the
 constructor, but it can be override by a user specific tolerance
 trough the method SetToleranceForArtefacts(). An artefact is then
 either an edge with length lower than this tolerance, or two adjacent
 edges where the shorstest edge is folded over the other one such that
 its second extremity (the one that doesn't belong to the other edge)
 is at a distance lower than the tolerance from the other edge, or two
 edges linked by their two extremities, or a full vertex.
*/
class ExportedByPolygonalOperators CATPolyPolygonCleaner2D
{

public :

  CATPolyPolygonCleaner2D (const CATPolyExactArithmetic & iExactArithmetic, const CATTolerance & iTolerance);

  ~CATPolyPolygonCleaner2D ();

  /**
   * Turn on or off an option to remove inner loops with solid surface on both sides.
   */
  inline void SetRemoveDoubleFilledInnerLoops (const CATBoolean iRemoveDoubleFilledInnerLoops);

  /**
   * Turn on or off an option to remove full vertices.
   */
  inline void SetRemoveFullVertices (const CATBoolean iRemoveFullVertices);

  /**
   * Turn on or off an option to remove aligned vertices in loops.
   */
  inline void SetRemoveAlignedVertices (const CATBoolean iRemoveAlignedVertices);

  /**
   * Turn on or off an option to remove artefacts (thin elements in loops).
   */
  inline void SetRemoveArtefacts (const CATBoolean iRemoveArtefacts);

  /**
   * Set the tolerance used to determine the maximum size of an artefact.
   */
  inline void SetToleranceForArtefacts(const double iArtefactMaxSize);

  /**
   * Method that executes the cleaning on the given polygon ioPolygon,
   * according to options defined.
   */
  HRESULT Run (CATPolyPolygon2D & ioPolygon);

 private:
  /**
   * Removes inner loops with solid surface on both sides.
   */
  HRESULT RemoveDoubleFilledInnerLoops (CATPolyPolygon2D & ioPolygon);

  /**
   * Removes full vertices.
   */
  HRESULT RemoveFullVertices (CATPolyPolygon2D & ioPolygon);

  /**
   * Removes aligned vertices in loops.
   */
  HRESULT RemoveAlignedVertices (CATPolyPolygon2D & ioPolygon);

  /**
   * Removes artefacts (thin elements in loops).
   */
  HRESULT RemoveArtefacts (CATPolyPolygon2D & ioPolygon);

  HRESULT GetFullPolyline (CATPolyBar2D * iBar, const CATPolyLoop2D * iLoop1, const CATPolyLoop2D * iLoop2,
                           CATListPV & oListOfBars, CATPolyVertex2D *& oFirst);

  HRESULT RemoveVertexArtefact(CATPolyPolygon2D & ioPolygon, CATPolyVertex2D & iVertex);

  HRESULT GetStar(const CATPolyVertex2D * iVertex, CATListPV & oStarVertices, CATListPV & oStarBars);

 private:

  const CATPolyExactArithmetic & _ExactArithmetic;
  double                         _Tolerance;

  CATBoolean _RemDoubleSolidBars;
  CATBoolean _RemFullVertices;
  CATBoolean _RemAlignedVertices;
  CATBoolean _RemArtefacts;
};

inline void CATPolyPolygonCleaner2D::SetRemoveDoubleFilledInnerLoops (const CATBoolean iRemoveDoubleFilledInnerLoops)
{
  _RemDoubleSolidBars = iRemoveDoubleFilledInnerLoops;
}

inline void CATPolyPolygonCleaner2D::SetRemoveFullVertices (const CATBoolean iRemoveFullVertices)
{
  _RemFullVertices = iRemoveFullVertices;
}

inline void CATPolyPolygonCleaner2D::SetRemoveAlignedVertices (const CATBoolean iRemoveAlignedVertices)
{
  _RemAlignedVertices = iRemoveAlignedVertices;
}

inline void CATPolyPolygonCleaner2D::SetRemoveArtefacts (const CATBoolean iRemoveArtefacts)
{
  _RemArtefacts = iRemoveArtefacts;
}

inline void CATPolyPolygonCleaner2D::SetToleranceForArtefacts(const double iArtefactMaxSize)
{
  _Tolerance = iArtefactMaxSize*iArtefactMaxSize;
}


#endif
