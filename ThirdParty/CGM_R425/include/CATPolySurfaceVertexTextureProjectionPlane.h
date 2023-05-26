//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Projection interface for the making of the layer of
// per-surface-vertex texture coordinates
//      _
//     / \    This class requires charts made from CATIPolyMesh's only !
//    / | \
//   /  |  \
//  /   ¤   \
//  ---------
//=============================================================================
// 2008-09-17   XXC: New.
// 2011-7/6  zfi:Review
//=============================================================================

#ifndef CATPolySurfaceVertexTextureProjectionPlane_H
#define CATPolySurfaceVertexTextureProjectionPlane_H

#include "CATPolySurfaceVertexTextureProjection.h"
#include "PolyhedralTexture.h"

class CATIPolySurfaceVertexIterator;
class CATIPolySurfaceVertexTextureCoordLayer;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureProjectionPlane: public CATPolySurfaceVertexTextureProjection
{
 public:
  CATPolySurfaceVertexTextureProjectionPlane();
  virtual ~CATPolySurfaceVertexTextureProjectionPlane();
  
protected:
  //inherited
  HRESULT Initialize();

  /** Projects (computes the texture coordinates of) a vertex in a
   *plane obtained from the tangent and the binormal to the
   *surface. These attributes are obtained from the mother class which
   *needs to compute them.
   *@param iIndex: index of the vertex to project in the surface
   *contained in the Chart currently associated to the projector
   *@param oU,oV: texture coordinates computed in the method.
   */
  
   virtual HRESULT ProjectSurfaceVertex(const int iIndex, double *oU, double *oV, CATMathVector* oTn, CATMathVector* oBn) const;

public:
   /** Get the normal to the projected surface.
   */
  inline const CATMathVector & GetPlaneNormal();

  /** Get the tangent to the projected surface. This is the tangent
   *  used in the texture coordinates layer.
   */
  inline const CATMathVector & GetPlaneUdir();

  /** Get the binormal to the projected surface. This is the binormal
   *  used in the texture coordinates layer.
   */
  inline const CATMathVector & GetPlaneVdir();

private:
  // An orthonormal basis, given by the average normal N to the surface, a direction U in the xOy plane, a second direction V, orthogonale to both U and N. This basis is used for the binormal and tangent texture data.
  CATMathVector _AvgNormal, _U, _V;

};

inline const CATMathVector & CATPolySurfaceVertexTextureProjectionPlane::GetPlaneNormal()
{
  return _AvgNormal;
}

inline const CATMathVector & CATPolySurfaceVertexTextureProjectionPlane::GetPlaneUdir()
{
  return _U;
}

inline const CATMathVector & CATPolySurfaceVertexTextureProjectionPlane::GetPlaneVdir()
{
  return _V;
}


#endif // !CATPolySurfaceVertexTextureProjectionPlane_H

