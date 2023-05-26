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
// 2008-11-28   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTexturePackingBox_H
#define CATPolySurfaceVertexTexturePackingBox_H

#include "CATPolySurfaceVertexTexturePacking.h"
#include "PolyhedralTexture.h"

class ExportedByPolyhedralTexture CATPolySurfaceVertexTexturePackingBox: public CATPolySurfaceVertexTexturePacking
{
 public:
  CATPolySurfaceVertexTexturePackingBox();
  CATPolySurfaceVertexTexturePackingBox(double space);
  virtual ~CATPolySurfaceVertexTexturePackingBox();
  
  /** Considering a list of charts, pack all together the textures of
   *  the surfaces contained in the charts.
   *  Notice that this packing method requires specific Box
   *  charts. This is verified in the method thanks to a "secured"
   *  cast.
   */
  virtual HRESULT Pack(CATListPV & iListOfCharts) const;

 private:
  /** Not supposed to be used. The user must only call the public Pack method.
   */
  virtual HRESULT Pack(CATListPV & iListOfCharts, double iSquareRatio) const;

 private:
  CATPolySurfaceVertexTexturePackingBox(const CATPolySurfaceVertexTexturePackingBox & iPacker);
  CATPolySurfaceVertexTexturePackingBox & operator = (const CATPolySurfaceVertexTexturePackingBox & iPacker) const;
};

#endif // !CATPolySurfaceVertexTexturePackingBox_H
