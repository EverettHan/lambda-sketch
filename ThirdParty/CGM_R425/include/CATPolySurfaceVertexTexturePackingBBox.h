//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Packing operation on a set of surface textures, based on the
// textures bounding boxes: allows to set the textures (one texture
// per surface) of a full poly body in a [0;1]² square, without
// overlapping.
//
//=============================================================================
// 2008-09-19   XXC: New.
// 2011-07-01   zfi:Review
//=============================================================================

#ifndef CATPolySurfaceVertexTexturePackingBBox_H
#define CATPolySurfaceVertexTexturePackingBBox_H

#include "CATPolySurfaceVertexTexturePacking.h"
#include "PolyhedralTexture.h"

class ExportedByPolyhedralTexture CATPolySurfaceVertexTexturePackingBBox: public CATPolySurfaceVertexTexturePacking
{
public:
  CATPolySurfaceVertexTexturePackingBBox();
  
  //iSpacing : percent value (relatif spacing*100)
  CATPolySurfaceVertexTexturePackingBBox(double iSpacing); 
  virtual ~CATPolySurfaceVertexTexturePackingBBox();
  
private:
  /** Considering a list of charts, pack all together the textures of
   *  the surfaces contained in the charts.
   *  Notice that this packing method requires specific BBox
   *  charts. This is verified in the method thanks to a "secured"
   *  cast (see declaration of the
   *  CATPolySurfaceVertexTextureChartBBox class).
   */
  virtual HRESULT Pack(CATListPV & iListOfCharts, double iSquareRatio) const;

 private:
  CATPolySurfaceVertexTexturePackingBBox(const CATPolySurfaceVertexTexturePackingBBox & iPacker);
  CATPolySurfaceVertexTexturePackingBBox & operator = (const CATPolySurfaceVertexTexturePackingBBox & iPacker) const;
};

#endif // !CATPolySurfaceVertexTexturePackingBBox_H
