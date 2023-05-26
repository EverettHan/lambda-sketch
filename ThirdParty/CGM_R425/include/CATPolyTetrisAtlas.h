//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Specific Atlas definition for Bounding Box Charts and Packing method
//
//=============================================================================
// 2008-10-08   XXC: New.
//=============================================================================

#ifndef CATPolyTetrisAtlas_H
#define CATPolyTetrisAtlas_H

#include "CATPolyVisuTetrisAtlas.h"
#include "CATPolySurfaceVertexTextureAtlas.h"

class ExportedByPolyVisuTetrisAtlas CATPolyTetrisAtlas : public CATPolySurfaceVertexTextureAtlas
{
 public:
  CATPolyTetrisAtlas();
  CATPolyTetrisAtlas(CATPolySurfaceVertexTexturePacking * ioPackingMethod,
				             CATPolySurfaceVertexTextureProjection * ioProjectionMethod);

  virtual ~CATPolyTetrisAtlas();

  virtual CATPolySurfaceVertexTextureChart * CreateChart (CATIPolySurface * iSurface) const;

};

#endif // !CATPolyTetrisAtlas_H
