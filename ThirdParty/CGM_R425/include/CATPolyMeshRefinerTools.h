// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshRefinerTools.h
//
//===================================================================
// Sep 2009 Move GetCurve and IsBarOnEdge to CATPolyBodyUtil : JS9
// June 2007  Creation: ndo
//===================================================================
#ifndef CATPolyMeshRefinerTools_h
#define CATPolyMeshRefinerTools_h

#include "PolyVizRefiners.h"
#include "CATErrorDef.h"  // HRESULT definition.
#include "CATPolyBodyUtil.h"
#include "CATMathInline.h"

class CATIPolyMesh;
class CATIPolySurface;
class CATIPolyCurve;

class CATPolyEdge;

class CATIPolySurfaceVertexNormalConstLayer;
class CATIPolySurfaceVertexCellConstLayer;
class CATIPolySurfaceVertexUVConstLayer;

class CATPolyMathPNTriangleSurface;
class CATPolyMathTriangleSurfaceWithSupport;
class CATPolyMathQuadSurface;


/**
* Tools to construct a CATPolyMathPNTriangleSurface object from a CATIPolyMesh object.
*/
class ExportedByPolyVizRefiners CATPolyMeshRefinerTools 
{

public:

  /**
   * @see CATPolyBodyUtil::IsBarOnAnEdge
   */
  //static INLINE CATPolyEdge* IsBarOnAnEdge (const CATIPolySurfaceVertexCellConstLayer& iCellLayer,
  //                                          const int meshPoint1, const int meshPoint2,
  //                                          int& oEdgePoint1, int& oEdgePoint2);

  /**
   * @see CATPolyBodyUtil::GetCurve
   */
  static INLINE CATIPolyCurve* GetCurve (const CATIPolySurface& iSurface, const CATPolyEdge& iEdge);

public:

  /**
   * Constructs a CATPolyMathPNTriangleSurface object given a triangle from a CATIPolyMesh.
   * Caller is responsible for deleting the output object oSurface (delete operator).
   */
  static HRESULT ConstructMathSurface (const CATIPolyMesh& iMesh, const int iTriangle,
                                       const CATIPolySurfaceVertexNormalConstLayer& iNormalLayer,
                                       const CATIPolySurfaceVertexCellConstLayer& iCellLayer,
                                       CATPolyMathPNTriangleSurface*& oSurface) ;

  /**
   * Constructs a CATPolyMathPNTriangleSurface object given the three vertices of a triangle from a CATIPolyMesh.
   * Caller is responsible for deleting the output object oSurface (delete operator).
   * @param iIsolatedVertexMode
   *    iIsolatedVertexMode = 0: vertices linked by bars of triangle
   *    iIsolatedVertexMode = 1: vertices not linked by bars of triangle
   */
  static HRESULT ConstructMathSurface (const CATIPolyMesh& iMesh, const int iVertices[],
                                       const CATIPolySurfaceVertexNormalConstLayer& iNormalLayer,
                                       const CATIPolySurfaceVertexCellConstLayer& iCellLayer,
                                       CATPolyMathPNTriangleSurface*& oSurface, int iIsolatedVertexMode = 1) ;

  /**
   * Constructs a CATPolyMathTriangleSurfaceWithSupport object.
   * Caller is responsible for deleting the output object oSurface (delete operator).
   */
  static HRESULT ConstructMathSurface (const CATIPolyMesh& iMesh, const int iTriangle, 
                                       const CATPolyMathQuadSurface * iSupport,
                                       const CATIPolySurfaceVertexUVConstLayer& iUVLayer,
                                       CATPolyMathTriangleSurfaceWithSupport*& oSurface) ;
                                
};


//INLINE CATPolyEdge* CATPolyMeshRefinerTools::IsBarOnAnEdge (const CATIPolySurfaceVertexCellConstLayer& iCellLayer,
//                                                            const int meshPoint1, const int meshPoint2,
//                                                            int& oEdgePoint1, int& oEdgePoint2)
//{
//  return CATPolyBodyUtil::IsBarOnAnEdge (iCellLayer, meshPoint1, meshPoint2, oEdgePoint1, oEdgePoint2);
//}


INLINE CATIPolyCurve* CATPolyMeshRefinerTools::GetCurve(const CATIPolySurface& iSurface, const CATPolyEdge& iEdge)
{
  return CATPolyBodyUtil::GetCurve(iSurface, iEdge);
}

#endif
