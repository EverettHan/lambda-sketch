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
// 2011-07/06 ZFI ->canonics
//=============================================================================

#ifndef CATPolySurfaceVertexTextureProjectionCanonic_H
#define CATPolySurfaceVertexTextureProjectionCanonic_H

#include "CATPolySurfaceVertexTextureProjection.h"
#include "CATPolyCanonicOperators.h"

class CATIPolySurfaceVertexIterator;
class CATIPolySurfaceVertexTextureCoordLayer;

class ExportedByCATPolyCanonicOperators CATPolySurfaceVertexTextureProjectionCanonic: public CATPolySurfaceVertexTextureProjection
{
public:
  CATPolySurfaceVertexTextureProjectionCanonic();
  virtual ~CATPolySurfaceVertexTextureProjectionCanonic();
  
protected: 
  //inherited
  HRESULT Initialize();
  HRESULT ProjectSurfaceVertex(const int iIndex, double* oU, double* oV, CATMathVector* oTn, CATMathVector* oBn) const;

private:

  //plane fitting
  HRESULT ComputePlaneFitting(CATIPolySurface& iPolySurface, 
                              CATMathPoint& oOrigin, CATMathVector& oU, CATMathVector& oV, CATMathVector& oW, 
                              double& oAvFitting, double& oMaxFitting)const;

  //cylinder fitting
  HRESULT ComputeCylinderFitting(CATIPolySurface& iPolySurface,
                                 CATMathPoint& oOrigin, CATMathVector& oU, CATMathVector& oV, CATMathVector& oW, double& oRadius, 
                                 double& oAvFitting, double& oMaxFitting)const;

  HRESULT ComputeCylinderProjectionOffset(CATIPolySurface& iPolySurface,
                                          const CATMathPoint& iOrigin, const CATMathVector& iU, const CATMathVector& iV, const CATMathVector& iW, const double oRadius, 
                                          double& oAngleOffset)const;

  //complete basis
  HRESULT CompleteBasis (const CATMathVector& iW, CATMathVector& oU, CATMathVector& oV)const;

private:
  int _ProjectionType;
  CATMathPoint _Origin;
  CATMathVector _U, _V, _W;
  double _Radius, _AngleOffset;

};

#endif // !CATPolySurfaceVertexTextureProjectionCanonic_H
