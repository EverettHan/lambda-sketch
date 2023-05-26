//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Basic texture chart. Used in conjonction with a projection method,
// it allows to generate and transform (translation, scale) the
// texture coordinates layer of a surface.
//
// Mainly handles the translation of the initial texture in the atlas
// and allows to manage extra informations required to speed up the
// process (for instance, according to the packing method).
//
//=============================================================================
// 2008-09-17   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureChart_H
#define CATPolySurfaceVertexTextureChart_H

#include "CATIPolySurface.h"
#include "CATIPolySurfaceVertexTextureCoordLayer.h"
#include "CATIPolySurfaceVertexPositionLayer.h"
#include "CATIPolySurfaceVertexIterator.h"
#include "PolyhedralTexture.h"
#include "CATUnicodeString.h"
#include "CATMathVector.h"

// To make "secured" casts between base class and inherited classes
typedef enum {ID_Chart_Base, ID_Chart_BBox, ID_Chart_Box, ID_Chart_Tetris} TypeChartID;

// Cast ID of this class: ID_Chart_Base

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureChart : public CATPolyRefCounted
{
 public:

  CATPolySurfaceVertexTextureChart (CATIPolySurface* ioSurface = 0);
  virtual ~CATPolySurfaceVertexTextureChart();

public:

  virtual HRESULT ReactToAddTextureCoordinate(const int iIndex, const double iU, const double iV, const CATMathVector & Tangent, const CATMathVector & Binormal);
  virtual HRESULT ReactToTranslateTexture(const double du, const double dv);
  virtual HRESULT ReactToScaleTexture(const double scalingFactor, unsigned int iMode);
  virtual HRESULT PrepareForPacking();
  virtual HRESULT UpdateAfterPacking();

public:
  //index
  inline HRESULT SetIndex(const int iIndex);
  inline int GetIndex() const;

 public:
  /** Instantiate the surface to which the chart is associated. The
   *  chart ought to manage the texture coordinates layer of this
   *  surface.
   * A chart is associated to only one surface. One cannot instanciate
   * a second surface to a chart which has been already instanciated
   * previously.
   *@param ioSurface: the surface used in the chart.
   *@return Fail if the chart is already associated to a chart,
   *succeed otherwise.
   */
  HRESULT SetSurface(CATIPolySurface * ioSurface);

  /** Get the surface associated to a chart
   */
  inline CATIPolySurface * GetSurface() const;

  /** Adds new texture coordinates for the vertex of index iIndex in
   *  the surface used in the chart.
   *@param iIndex: index of the vertex in the surface contained in the chart.
   *@param iU,iV: coordinates of the vertex in the texture.
   *@param Tangent: Tangent vector to the surface, used in the texture
   *coordinates layer.
   *@param Binormal: Binormal vector to the surface, used in the texture
   *coordinates layer.
   */
  HRESULT AddTextureCoordinate(const int iIndex, const double iU, const double iV, const CATMathVector & Tangent, const CATMathVector & Binormal);

  /** Initialize an iterator on the vertices of the surface contained
   *  in the chart. Usefull to iterate easily on each vertex of the
   *  surface.
   *@param oIndex: return the index of the first vertex in the
   *surface.
   */
  HRESULT InitVertexIterator(int & oIndex) const;

  /** Get the index of the vertex following the last visited vertex in
   *  the surface contained in the chart.
   *@param oIndex: the index of the next vertex in the surface.
   *@return FALSE if the last visited vertex was the last one (the
   *iteration is finished, there is no more vertex in the surface),
   *TRUE otherwise.
   */
  CATBoolean GetNextVertexIndex(int & oIndex);

  /** Get the 3D space coordinates of a vertex of the surface contained
   *  in the chart.
   *@param iIndex: index of the vertex we want to get the coordinates.
   *@param x,y,z: coordinates of the vertex at index iIndex.
   */
  HRESULT GetXYZCoord(const int iIndex, double & x, double &y, double &z) const;

  /** Get the texture coordinates of a vertex of the surface contained
   *  in the chart.
   *@param iIndex: index of the vertex we want to get the coordinates.
   *@param u, v: coordinates of the vertex at index iIndex.
   */
  HRESULT GetUVCoord(const int iIndex, double &u, double &v) const;

  /** Translate the data (texture coordinates of vertices) obtained
   *  during the projection process. This translation allows the
   *  texture to be correctly positionned in an atlas.
   *@param du: translation along the u direction
   *@param dv: translation along the v direction
   */
  HRESULT TranslateTexture(const double du, const double dv);
  
  /** Scale the coordinate of each vertex in a chart texture, by a
   *  given scaling factor.
   *@param scalingFactor: the scale used to apply the homothetie to the
   *texture.
   */
  HRESULT ScaleTexture(const double scalingFactor, unsigned int iMode);
    
  /** Rotate the coordinate of each vertex in a chart texture, by a
   *  given rotation angle.
   *@param iRotationAngle
   */
  HRESULT RotateTexture(const double iRotationAngle);

  /** Verify if the chart is an instance of a particular kind of
   *  chart. Use polymorphism to verify this fact.
   *@param iId_Instance: Type of chart ID
   *@return TRUE if iId_Instance is the ID of the basic class
   *CATPolySurfaceVertexTextureChart, FALSE otherwise
   */
  virtual CATBoolean IsInstanceOf(const TypeChartID iId_Instance) const;

  public:
  virtual HRESULT GetBBox(double & oU_min, double & oU_max, double & oV_min, double & oV_max) const;

 private:
  CATPolySurfaceVertexTextureChart(CATPolySurfaceVertexTextureChart & RefCopy);
  CATPolySurfaceVertexTextureChart & operator = (CATPolySurfaceVertexTextureChart & RefCopy) const;
  
 protected:
  CATIPolySurface * _Reference;
  // A reference to an iterator in order to enable easy vertices
  // iterations from this class.
  CATIPolySurfaceVertexIterator * _VIterator;
  // To handle successive scales of the texture while keeping a
  // coherent global scale value. Obviously initialized to 1.0.

 private:
  double _CurrentScale;
  int _Index;
};

// Inline methods implementation
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

inline CATIPolySurface * CATPolySurfaceVertexTextureChart::GetSurface() const
{
  return _Reference;
}

inline HRESULT CATPolySurfaceVertexTextureChart::SetIndex(const int iIndex)
{
  _Index = iIndex;
  return S_OK;
}

inline int CATPolySurfaceVertexTextureChart::GetIndex() const
{
  return _Index;
}

#endif // !CATPolySurfaceVertexTextureChart_H
