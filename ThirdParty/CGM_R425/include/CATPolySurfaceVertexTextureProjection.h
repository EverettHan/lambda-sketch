//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Projection method interface for the making of the layer of
// per-surface-vertex texture coordinates
//      _
//     / \    This class requires charts made from CATIPolyMesh's only !
//    / | \
//   /  |  \
//  /   ¤   \
//  ---------
//=============================================================================
// 2008-09-17   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureProjection_H
#define CATPolySurfaceVertexTextureProjection_H

#include "CATBoolean.h"
#include "PolyhedralTexture.h"
#include "CATPolyRefCounted.h"
#include "CATMathVector.h"
#include "IUnknown.h"

class CATIPolySurface;
class CATIPolySurfaceVertexPositionLayer;
class CATPolySurfaceVertexTextureChart;

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureProjection: public CATPolyRefCounted
{
 public:
  CATPolySurfaceVertexTextureProjection();
  virtual ~CATPolySurfaceVertexTextureProjection();
  
 public:
  /** Projects the surface contained in a chart (which is itself
   *  contained in the projector). The projection consists in
   *  computing, for each vertex of the surface, its texture
   *  coordinates (see ProjectSurfaceVertex method).
   */
  virtual HRESULT ProjectSurface() const;

  /** Defines the chart containing the surface to project. This chart
   *  can be instanciated many times.

   *  First Verifies if a Chart was already defined and Releases it if
   *  necessary. Then, AddRefs the chart and initializes the
   *  projection data specific to the new chart.
   */
  virtual HRESULT SetChart(CATPolySurfaceVertexTextureChart * ioChart);

protected:
  /** Projects (computes the texture coordinates of) a vertex. This
   *  method is pure abstract and only depends on the projection
   *  method.
   *@param iIndex: index of the vertex to project in the surface
   *contained in the current Chart associated to the projector
   *@param oU,oV: texture coordinates computed in the method.
   */
  virtual HRESULT ProjectSurfaceVertex(const int iIndex, double* oU, double* oV, CATMathVector* oTn, CATMathVector* oBn) const = 0;

  /** Get the Chart currently associated to the projector
   */
  inline CATPolySurfaceVertexTextureChart * const GetChart() const;

 private:
  /** Indicates to the projection operator that it is ready to operate
   *  on a surface. This method is called when a chart is given (in
   *  the SetChart method.
   *  It also initializes the binormal and tangent vectors used in the
   *  textures coordinates.
   *@param iSurface: The surface we need to project and texture
   *@return: FAIL if it fails (whatever the reason), S_OK otherwise
   */
  virtual HRESULT Initialize()=0;

protected:
  // Indicates that the projector is initialized (data are initialized
  // according to the non-null current chart) and can operate.
  CATBoolean _Initialized;

  // Note: The chart is not unique and can change according to the
  // surface, linked in the chart, we want to project.
  // The projection operator does not deallocate the chart. This is
  // left to the user of the operator.
  CATPolySurfaceVertexTextureChart * _Reference;
};

// Inline methods implementation
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

inline CATPolySurfaceVertexTextureChart * const CATPolySurfaceVertexTextureProjection::GetChart() const
{
  return _Reference;
}

#endif // !CATPolySurfaceVertexTextureProjection_H

