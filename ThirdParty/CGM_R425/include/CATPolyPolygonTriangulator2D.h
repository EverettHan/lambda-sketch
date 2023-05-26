// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPolygonTriangulator2D.h
//
//===================================================================
// August 2004 Creation: ndo
//===================================================================
#ifndef CATPolyPolygonTriangulator2D_H
#define CATPolyPolygonTriangulator2D_H

#include "PolygonalOperators.h"
#include "CATListPV.h"
#include "CATErrorDef.h"     // HRESULT definition
#include "CATBoolean.h"

class CATPolyPolygon2D;
class CATPolyLoop2D;
class CATPolyFace2D;
class CATPolyCoBar2D;
class CATPolyVertex2D;
class CATPolyExactArithmetic;
class CATPolyRegularizeOper2D;

class CATPolyFaceIntLayer2D;

#if 0

/**
 Operator that computes the triangulation of a CATPolyPolygon2D object.
 The triangulation of the CATPolyPolygon2D object is Delaunay with the regularization operator.
*/
class ExportedByPolygonalOperators CATPolyPolygonTriangulator2D
{

public :

  /**
   * Constructs a triangulator given an instance of exact arithmetic.
   */
  CATPolyPolygonTriangulator2D (const CATPolyExactArithmetic& iExactArithmetic);

  ~CATPolyPolygonTriangulator2D ();

  /**
   * Sets an operator to regularize the polygon after triangulation (Delaunay triangulation.)
   */
  void SetRegularizeOperator (CATPolyRegularizeOper2D* iOper);

  /**
   * Sets a flag to ignore the free vertices in the polygon during triangulation.
   * By default the free vertices are not ignored: any free vertex inside the polygon
   * is used in the triangulation. Free vertices are triangulation constraints.
   */
  void IgnoreFreeVertices (const CATBoolean iIgnoreFreeVertices);

  /**
   * Triangulates the input CATPolyPolygon2D object.  
   * All the non-hole faces of the polygon are triangulated.
   * The triangulation is done in place.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolyPolygon, CATListPV * iListFaces=0);

  /**
   * Triangulates a polygon with update of the face attributes when the face is split.
   */
  HRESULT Run (CATPolyPolygon2D& ioPolygon, CATPolyFaceIntLayer2D& ioFaceLayer);

  /** 
   * Returns the error code different from 0 when the operator fails.
   * See CATPolyError2D.h for a definition of the various errors.
   */
  int GetError () const;

private:

  const CATPolyExactArithmetic& _ExactArithmetic;
  CATPolyRegularizeOper2D* _RegularizeOper;

  CATBoolean _IgnoreFreeVertices;

  int _Orientation;
  int _ErrorCode;

  void* _BarData;
  CATPolyFaceIntLayer2D* _PolygonFaceLayer;

  // No implementation of copy constructor and operator =.
  CATPolyPolygonTriangulator2D (CATPolyPolygonTriangulator2D& iOther) ;
  CATPolyPolygonTriangulator2D& operator= (CATPolyPolygonTriangulator2D& iOther) ;

private:

  HRESULT Triangulate (CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace, CATPolyCoBar2D** eventVertices,
                       const CATListPV* iFreeVertices);

  HRESULT ConstructMonotonePolygons (CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                     CATPolyCoBar2D** cobars, const int nbCoBars);

  HRESULT ConstructMonotonePolygonsNeg (CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                        CATPolyCoBar2D** cobars, const int nbCoBars);

  HRESULT ConstructMonotonePolygonsPos (CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                        CATPolyCoBar2D** cobars, const int nbCoBars);

  HRESULT ExtractMonotonePolygon (CATPolyLoop2D* iLoop,
                                  int* ranks, int iMaxIndex ,int inbCoBars,
                                  CATPolyCoBar2D** cobars, int& nbCoBars);

  HRESULT TriangulateMonotonePolygon (CATPolyPolygon2D& ioPolygon, CATPolyFace2D* iFace,
                                      CATPolyCoBar2D** cobars, const int nbCoBars);

  int GetOrientation (const CATPolyPolygon2D& iPolygon, 
                      CATPolyCoBar2D** cobars, const int nbCoBars) const;

  int GetOrientation (CATPolyVertex2D* vertex0, CATPolyVertex2D* vertex1, CATPolyVertex2D* vertex2) const;

};

#endif

#endif
