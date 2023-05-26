//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Specific Atlas definition for Bounding Box Charts and Packing method
//
//=============================================================================
// 2008-10-08   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureAtlasBBox_H
#define CATPolySurfaceVertexTextureAtlasBBox_H

#include "PolyhedralTexture.h"
#include "CATPolySurfaceVertexTextureAtlas.h"

class CATIPolySurface;
class CATPolySurfaceVertexTextureChart;
class CATPolySurfaceVertexTexturePacking;
class CATPolySurfaceVertexTextureProjection;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureAtlasBBox : public CATPolySurfaceVertexTextureAtlas
{
 public:
  CATPolySurfaceVertexTextureAtlasBBox();
  CATPolySurfaceVertexTextureAtlasBBox(CATPolySurfaceVertexTexturePacking * ioPackingMethod,
				       CATPolySurfaceVertexTextureProjection * ioProjectionMethod);

  virtual ~CATPolySurfaceVertexTextureAtlasBBox();

  /** Redefinition of the CreateChart method, to create charts of the
   *  right type CATPolySurfaceVertexTextureChartBBox, which is
   *  necessary to the BBox packing method.
   *@param iSurface: the surface used in the created chart
   *@return a pointer on the created
   *CATPolySurfaceVertexTextureChartBBox. Null if it fails.
   */
  virtual CATPolySurfaceVertexTextureChart * CreateChart (CATIPolySurface * iSurface) const;

};

#endif // !CATPolySurfaceVertexTextureAtlasBBox_H
