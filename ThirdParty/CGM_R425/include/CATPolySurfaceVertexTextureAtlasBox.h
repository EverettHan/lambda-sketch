//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Specific Atlas definition for Bounding Box Charts and Packing method
//
//=============================================================================
// 2008-11-28   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureAtlasBox_H
#define CATPolySurfaceVertexTextureAtlasBox_H

#include "PolyhedralTexture.h"
#include "CATPolySurfaceVertexTextureAtlas.h"

class CATIPolySurface;
class CATPolySurfaceVertexTextureChart;
class CATPolySurfaceVertexTexturePacking;
class CATPolySurfaceVertexTextureProjection;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureAtlasBox : public CATPolySurfaceVertexTextureAtlas
{
 public:
  CATPolySurfaceVertexTextureAtlasBox();
  CATPolySurfaceVertexTextureAtlasBox(CATPolySurfaceVertexTexturePacking * ioPackingMethod,
				       CATPolySurfaceVertexTextureProjection * ioProjectionMethod);

  virtual ~CATPolySurfaceVertexTextureAtlasBox();

  /** Redefinition of the CreateChart method, to create charts of the
   *  right type CATPolySurfaceVertexTextureChartBox, which is
   *  necessary to the Box packing method.
   *@param iSurface: the surface used in the created chart
   *@return a pointer on the created
   *CATPolySurfaceVertexTextureChartBox. Null if it fails.
   */
  virtual CATPolySurfaceVertexTextureChart * CreateChart (CATIPolySurface * iSurface) const;

};

#endif // !CATPolySurfaceVertexTextureAtlasBox_H
