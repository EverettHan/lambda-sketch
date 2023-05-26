// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyGridWithConstraintsTriangulateOper2D.h
// Header definition of CATPolyGridWithConstraintsTriangulateOper2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2013 Creation: tpg
//
//===================================================================
#ifndef CATPolyGridWithConstraintsTriangulateOper2D_H
#define CATPolyGridWithConstraintsTriangulateOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"

#include "CATMathBox2D.h"
//#include "CATListPV.h"
//#include "CATErrorDef.h"     // HRESULT definition
//#include "CATBoolean.h"

class CATMathBox2D;
class CATPolyPolygon2D;

/**
 Operator that computes the triangulation of a grid inside a contraints polygon (constrained Delaunay triangulation of a grid).
*/
class ExportedByPolygonalOperators CATPolyGridWithConstraintsTriangulateOper2D
{

public :

  /**
   * Constructs a grid triangulator.
	 * iGridBox : 2D box defining the input grid limitation
	 * iNbGridPointsU : Number of grid points in U direction
	 * iNbGridPointsV : Number of grid points in V direction
   */
  CATPolyGridWithConstraintsTriangulateOper2D (const CATMathBox2D& iGridBox, int iNbGridPointsU, int iNbGridPointsV);

  ~CATPolyGridWithConstraintsTriangulateOper2D ();

  /**
   * Triangulates the input Grid inside the constraint polygon object.  
   * ioPolyPolygon : contraints polygon, output triangulation will be done in place.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolyPolygon);

private:

	const CATMathBox2D _GridBox;
	int _NbGridPointsU;
	int _NbGridPointsV;

private:

  HRESULT BooleanPolygonIntersectedGridCells (CATPolyPolygon2D& ioPolygon) const;
  HRESULT AddGridPointsAndTriangulate (CATPolyPolygon2D& ioPolygon) const;
  void RemoveFreePoints (CATPolyPolygon2D& polygon) const;
  HRESULT CheckTriangularPolygon (CATPolyPolygon2D& polygon) const;
  HRESULT TriangulateNonTriangularFaces (CATPolyPolygon2D& polygon, int iRegularize=0) const;
  HRESULT RemoveNonGridBars (CATPolyPolygon2D& ioPolygon, double iDeltaU, double iDeltaV, const CATMathBox2D& iBox) const;

	//HRESULT AddGridPoints (CATPolyPolygon2D& polygon, int iGridPointCountU, int iGridPointCountV, CATMathBox2D& oBox) const;
  //HRESULT TriangulateGridPoints (CATPolyPolygon2D& polygon, int iGridPointCountU, int iGridPointCountV, CATMathBox2D& oBox) const;
  //HRESULT BooleanPolygonGridPoints (CATPolyPolygon2D& polygon, int iGridPointCountU, int iGridPointCountV, CATMathBox2D& oBox) const;
  //HRESULT RegularizeNonGridBars (CATPolyPolygon2D& polygon, double iDeltaU, double iDeltaV) const;

};

#endif
