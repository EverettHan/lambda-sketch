//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Atlas definition: set of texture charts which do not overlap each
// others. Use basic class CATPolySurfaceVertexTextureChart for
// charts, by default (see the CreateChart method for details).
//
//=============================================================================
// 2008-09-19   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureAtlas_H
#define CATPolySurfaceVertexTextureAtlas_H

#include "CATListPV.h"
#include "PolyhedralTexture.h"
#include "IUnknown.h"

class CATPolySurfaceVertexTexturePacking;
class CATPolySurfaceVertexTextureProjection;
class CATPolySurfaceVertexTextureChart;
class CATPolyBody;
class CATIPolySurface;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureAtlas
{
 public:
  CATPolySurfaceVertexTextureAtlas();
  CATPolySurfaceVertexTextureAtlas(CATPolySurfaceVertexTexturePacking * ioPackingMethod,
				   CATPolySurfaceVertexTextureProjection * ioProjectionMethod);
  virtual ~CATPolySurfaceVertexTextureAtlas();
  
 public:
  /** Generate non-overlapping texture coordinates, for each face of a poly body.
   * It iterates on each face of the given poly body, generate one
   * chart per face, use it to project the face vertices, according to
   * the projection method, then pack all the charts, according to the
   * packing method (the projection and packing methods are given with
   * the atlas).
   *@param oObjectModel: The poly body on which the texture
   *coordinates are computed
   *@return Fail if the atlas does not contain a projection method or
   *a packing method; succeed otherwise.
   */
  HRESULT GenerateAtlas(CATPolyBody * oObjectModel);

  /** Define the packing method used to generate an atlas
   *@param ioPackingMethod: the packing method which is to be
   *associated with the atlas
   */
  HRESULT SetPackingMethod(CATPolySurfaceVertexTexturePacking * ioPackingMethod);

  /** Define the projection method used to generate an atlas
   *@param ioProjectionMethod: the projection method which is to be
   *associated with the atlas
   */
  HRESULT SetProjectionMethod(CATPolySurfaceVertexTextureProjection * ioProjectionMethod);

 private:
  CATPolySurfaceVertexTextureAtlas(const CATPolySurfaceVertexTextureAtlas & iPacker);
  CATPolySurfaceVertexTextureAtlas & operator = (const CATPolySurfaceVertexTextureAtlas & iPacker) const;

  /** Create a chart of the right type (here a
   *  CATPolySurfaceVertexTextureChart). Must be redefined by
   *  inherited classes if the type changes.
   * Since the type of chart used in an atlas can depends on the type
   * of the packing method or the projection used, a specific type of
   * chart has to be created in order to make everything going
   * alright. The user should know what type of chart correspond to
   * what type of packer/projection.
   *@param iSurface: the surface used in the created chart
   *@return a pointer on the created chart. Null if it fails.
   */
  virtual CATPolySurfaceVertexTextureChart * CreateChart (CATIPolySurface * iSurface) const=0;
  
 private:
  CATPolySurfaceVertexTexturePacking * PackingMethod;
  CATPolySurfaceVertexTextureProjection * ProjectionMethod;
  CATListPV ListOfCharts;
};

#endif // !CATPolySurfaceVertexTextureAtlas_H

