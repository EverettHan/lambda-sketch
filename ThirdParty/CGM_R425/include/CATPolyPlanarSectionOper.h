// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPlanarSectionOper.h
// Header definition of CATPolyPlanarSectionOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// April 2006  Creation: NDO
//===================================================================
#ifndef CATPolyPlanarSectionOper_H
#define CATPolyPlanarSectionOper_H

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"
#include "CATMathPlane.h"
#include "CATLISTV_CATMathPoint.h"  // Get rid of me.

class CATPolyExactArithmetic;
class CATPolyBooleanSegments2;  // Get rid of me.
class CATPolyPolygon2D;
class CATPolyPolygonVertex3DPositionLayer;
class CATPolyParallelPlanesMeshIntersector;

class CATMathPlane;


/**
 * This operator calculates a planar section of a mesh and returns the result in the form of a polygon 2D
 * and a list of 3D points.  The input mesh does not need to be gridded for exact arithmetic.
 * The Run () can be called as many times as the number of section planes.  It runs efficiently for sequences
 * of parallel planes.
 */
class ExportedByCATPolyAnalyzeOperators CATPolyPlanarSectionOper : public CATPolyAnalyzeOper
{

public:

  /*
   * Construct an instance of planar section operator.  The instance of exact arithmetic is needed for 
   * robust geometry in the computation of the section result.  Its range should be set to encompass all the 
   * coordinate values of the input operand (which does not need to be gridded.)
   */
  CATPolyPlanarSectionOper (const CATPolyExactArithmetic& iExactArithmetic);

  virtual ~CATPolyPlanarSectionOper ();

public:

  /*
   * Perform a planar section of the mesh by the plane.
   * @param iMesh
   *   The input mesh.  It does not need to be gridded.
   * @param isVolume
   *   A flag to specify if the mesh should be processed as a volume or as a skin surface.
   * @param iPlane
   *   The section plane.
   * @param oPolygon
   *   The output polygon containing the result of the section.  The 2D coordinates of the polygon vertices 
   *   are gridded by the exact arithmetic.  The caller is responsible for the life cycle of this object.
   *   (Call delete.)
   * @param oPolygonVertexPositionLayer
   *   An output layer of 3D coordinates associated to the polygon vertices.  The 3D coordinates are not gridded.
   *   The caller is responsible of the life cycle of this object.  (Call delete.)
   * @return
   *   If the section is successful, the method returns S_OK or S_FALSE.  It returns S_FALSE if the section is empty.
   *   If Run returns E_FAIL and there is a section result, it means that an open volume has been sectioned.  In this
   *   case, the result contains just the boundaries of the section (wires) and not the solid faces.
   */
  HRESULT Run (const CATIPolyMesh& iMesh, const CATBoolean isVolume,
               const CATMathPlane& iPlane, 
               CATPolyPolygon2D*& oPolygon, CATPolyPolygonVertex3DPositionLayer*& oPolygonVertexPositionLayer);

private:

  const CATPolyExactArithmetic* _ExactArithmetic;

  CATMathPlane _Plane; 
  CATPolyParallelPlanesMeshIntersector* _Intersector;

private:

  void SetIntersector (const CATIPolyMesh& iMesh, const CATBoolean isVolume, const CATMathPlane& iPlane);

private:

  // Get rid of these members!
  CATPolyPolygon2D* _Polygon;
  CATPolyPolygonVertex3DPositionLayer* _PolygonVertexPositionLayer;

  CATLISTV(CATMathPoint) _Points;  // Get rid of me!  Redundant with PolygonVertexPositionLayer.

  // Get rid of me.
  HRESULT ConstructPolygonPrivate ();

  // Get rid of me.
  void Clean ();

  // Get rid of me.
  CATPolyBooleanSegments2* _Segments2;

public:

  // These methods are still called by BasicTopologicalOpe\FrFShellUnfold.m\src\CATFlattenerODFStrategy.cpp
  // under versioning.

  // DEPRECATED.
  CATPolyPlanarSectionOper (const CATPolyExactArithmetic* iExactArithmetic);

  // DEPRECATED.
  void SetPlane (const CATMathPlane& iPlane);

  // DEPRECATED.
  const CATLISTV(CATMathPoint)* GetPoints ();

  // DEPRECATED.
  HRESULT Run ();

  // DEPRECATED.
  CATPolyPolygon2D* GetPolygon () const;

};

#endif
