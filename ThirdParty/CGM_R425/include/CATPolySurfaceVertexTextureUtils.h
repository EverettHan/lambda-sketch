//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Methods used to project surface, pack and generate atlas textures
// of a CATPolyBody.
//
//=============================================================================
// 2008-11-28   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureUtils_H
#define CATPolySurfaceVertexTextureUtils_H

/* #include "CATBoolean.h" */
#include "PolyhedralTexture.h"
/* #include "CATPolyRefCounted.h" */
#include "CATMathVector.h"
#include "CATErrorDef.h"

class CATIPolySurface;
class CATIPolySurfaceVertexPositionLayer;
class CATPolySurfaceVertexTextureChart;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureUtils
{
 public:
  /* CATPolySurfaceVertexTextureUtils(); */
  /* virtual ~CATPolySurfaceVertexTextureUtils(); */
  
  /** Compute the average normal to the surface contained in the chart.
   *@param oAvgNormal: Out average normal, computed in the method.
   *@return: S_OK if everything goes alright, E_FAIL otherwise
   */
  static HRESULT ComputeAverageNormal(CATIPolySurface * iPolySurface, CATMathVector & oAvgNormal);
  
  /** Compute two vectors U and V, such that U is in the xOy plane,
   *  and that Sight, U and V define a direct orthonormal basis.
   *@param iSight: original vector from which the basis is
   *generated. It is supposed to be normalized
   *@param oU: generated unitary vector, orthogonal to iSight and
   *contained in the plane xOy. Colinear to the x direction if iSight
   *is colinear to the z direction.
   *@param oY: generated unitary vector, orthogonal to oU and iSight
   */
  static void GenerateBasis_xOyPlane(const CATMathVector & iSight, CATMathVector & oU, CATMathVector & oV);

};

#endif
