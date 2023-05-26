//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2008
//=============================================================================
//
// Inherited class from the basic class
// CATPolySurfaceVertexTextureChart. It is specific to the use of the
// "bounding box" packing method by managing the data of the surface
// texture bounding box.
//
//=============================================================================
// 2008-09-22   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureChartBBox_H
#define CATPolySurfaceVertexTextureChartBBox_H

#include "CATPolySurfaceVertexTextureChart.h"
#include "PolyhedralTexture.h"

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureChartBBox : public CATPolySurfaceVertexTextureChart
{

public:
  CATPolySurfaceVertexTextureChartBBox();
  CATPolySurfaceVertexTextureChartBBox(CATIPolySurface * ioSurface);
  virtual ~CATPolySurfaceVertexTextureChartBBox();
  
public:

  /** Make a "secured" cast from a CATPolySurfaceVertexTextureChart to
   *  a CATPolySurfaceVertexTextureChartBBox. It is "secured" since it
   *  uses polymorphism to verify if the given Chart is indeed a BBox
   *  particular chart (see IsInstanceOf method).
   *@param iChart: a pointer to the (generic) basic chart to cast.
   *@return an AddRefed casted pointer to the chart iChart if it is of
   *the right type, NULL otherwise.
   */
  static inline CATPolySurfaceVertexTextureChartBBox * Cast(CATPolySurfaceVertexTextureChart * iChart);

  /** Inherited method from the basic chart class. Does the same (by
   *  calling the mother class method), but allows in addition to
   *  compute data specific to the bounding box of the surface
   *  texture.
   */
  virtual HRESULT ReactToAddTextureCoordinate(const int iIndex, const double iU, const double iV, const CATMathVector & Tangent, const CATMathVector & Binormal);

  /** Get the surface texture bounding box
   */
  inline HRESULT GetBBox(double & oU_min, double & oU_max, double & oV_min, double & oV_max) const;
  /**@return The height of the bounding box
   */
  inline double GetBBHeight() const;
  /**@return The width of the bounding box
   */
  inline double GetBBWidth() const;
  /**@return The area of the bounding box
   */
  inline double GetBBArea() const;

  /** Translate the data (texture coordinates of vertices) obtained
   *  during the projection process. This translation allows the
   *  texture to be correctly positionned in an atlas.
   *@param du: translation along the u direction
   *@param dv: translation along the v direction
   */
  virtual HRESULT ReactToTranslateTexture(const double du, const double dv);
  
  /** Scale the coordinate of each vertex in a chart texture, by a
   *  given scaling factor.
   *@param scalingFactor: the scale used to apply the homothetie to the
   *texture.
   */
  virtual HRESULT ReactToScaleTexture(const double scalingFactor, unsigned int iMode);

  /** Translate the coordinates of each vertex in order to set the
   *  chart in the bounding box beginning at a particular position.
   *@param Uleft, Vbottom: start position constraint of the texture
   */
  HRESULT SetBottomLeftCorner(const double Uleft, const double Vbottom);

  /** Verify if the chart is an instance of a particular kind of
   *  chart. Use polymorphism to verify this fact.
   *@param iId_Instance: Type of chart ID
   *@return TRUE if iId_Instance is the ID of the basic class
   *CATPolySurfaceVertexTextureChart, FALSE otherwise
   */
  inline virtual CATBoolean IsInstanceOf(const TypeChartID iId_Instance) const;

 protected:
  /** Update the bounding box if the texture coordinates have
   *  changed. Only inherited classes can modify them.
   */
  HRESULT UpdateBoundingBox();
  
 private:
  CATPolySurfaceVertexTextureChartBBox(CATPolySurfaceVertexTextureChartBBox & RefCopy);
  CATPolySurfaceVertexTextureChartBBox & operator = (CATPolySurfaceVertexTextureChartBBox & RefCopy) const;
  
 private:
  // Bounding box data
  CATBoolean initialized;
  double u_min, u_max, v_min, v_max;
};

// Inline methods implementation
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

inline HRESULT CATPolySurfaceVertexTextureChartBBox::GetBBox(double & oU_min, double & oU_max, double & oV_min, double & oV_max) const
{
  if (initialized == TRUE)
    {
      oU_min = u_min;
      oU_max = u_max;
      oV_min = v_min;
      oV_max = v_max;
      return S_OK;
    }
  return E_FAIL;
}

inline double CATPolySurfaceVertexTextureChartBBox::GetBBHeight() const
{
  return v_max-v_min;
}

inline double CATPolySurfaceVertexTextureChartBBox::GetBBWidth() const
{
  return u_max-u_min;
}

inline double CATPolySurfaceVertexTextureChartBBox::GetBBArea() const
{
  return (v_max-v_min)*(u_max-u_min);
}

inline CATBoolean CATPolySurfaceVertexTextureChartBBox::IsInstanceOf(const TypeChartID iId_Instance) const
{
  // If iId_Instance does not correspond to the current class, we
  // must check it with the mother class: a child is also an
  // instance of the mother.
  return (iId_Instance == ID_Chart_BBox || CATPolySurfaceVertexTextureChart::IsInstanceOf(iId_Instance))?TRUE:FALSE;
}

inline CATPolySurfaceVertexTextureChartBBox * CATPolySurfaceVertexTextureChartBBox::Cast(CATPolySurfaceVertexTextureChart * iChart)
{
  if (iChart && iChart->IsInstanceOf(ID_Chart_BBox)) {
    iChart->AddRef();
    return (CATPolySurfaceVertexTextureChartBBox *) iChart;
  }
  else
    return NULL;
}
#endif // !CATPolySurfaceVertexTextureChartBBox_H
