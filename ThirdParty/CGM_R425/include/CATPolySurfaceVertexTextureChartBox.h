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
// 2008-11-27   XXC: New.
//=============================================================================

#ifndef CATPolySurfaceVertexTextureChartBox_H
#define CATPolySurfaceVertexTextureChartBox_H

#include "CATPolySurfaceVertexTextureChartBBox.h"
#include "PolyhedralTexture.h"
#include "CATBoolean.h"

class ExportedByPolyhedralTexture CATPolySurfaceVertexTextureChartBox : public CATPolySurfaceVertexTextureChartBBox
{

public:
  CATPolySurfaceVertexTextureChartBox();
  CATPolySurfaceVertexTextureChartBox(CATIPolySurface * ioSurface);
  virtual ~CATPolySurfaceVertexTextureChartBox();
  
public:

  /** Make a "secured" cast from a CATPolySurfaceVertexTextureChart to
   *  a CATPolySurfaceVertexTextureChartBox. It is "secured" since it
   *  uses polymorphism to verify if the given Chart is indeed a Box
   *  particular chart (see IsInstanceOf method).
   *@param iChart: a pointer to the (generic) basic chart to cast.
   *@return an AddRefed casted pointer to the chart iChart if it is of
   *the right type, NULL otherwise.
   */
  static inline CATPolySurfaceVertexTextureChartBox * Cast(CATPolySurfaceVertexTextureChart * iChart);

  /** Get the three texture coordinates of a vertex of the surface
   *  contained in the chart.
   *@param iIndex: index of the vertex we want to get the coordinates.
   *@param u, v, w: coordinates of the vertex at index iIndex.
   */
  HRESULT GetUVWCoord(const int iIndex, double &oU, double &oV, double &oW) const;

  HRESULT SetDeltaU(const double iDeltaU);
  
  /** Make a symetry of the texture according to the V axis (inverse
   *  each u coordinate)
   *  Method usefull to have a constant U delta for every vertex
   */
  HRESULT ReflexionU();

  /** Verify if the chart is an instance of a particular kind of
   *  chart. Use polymorphism to verify this fact.
   *@param iId_Instance: Type of chart ID
   *@return TRUE if iId_Instance is the ID of the basic class
   *CATPolySurfaceVertexTextureChart, FALSE otherwise
   */
  inline virtual CATBoolean IsInstanceOf(const TypeChartID iId_Instance) const;

 private:
  CATPolySurfaceVertexTextureChartBox(CATPolySurfaceVertexTextureChartBox & RefCopy);
  CATPolySurfaceVertexTextureChartBox & operator = (CATPolySurfaceVertexTextureChartBox & RefCopy) const;
};

// Inline methods implementation
//¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

inline CATBoolean CATPolySurfaceVertexTextureChartBox::IsInstanceOf(const TypeChartID iId_Instance) const
{
  // If iId_Instance does not correspond to the current class, we
  // must check it with the mother class: a child is also an
  // instance of the mother.
  return (iId_Instance == ID_Chart_Box || CATPolySurfaceVertexTextureChartBBox::IsInstanceOf(iId_Instance))?TRUE:FALSE;
}

inline CATPolySurfaceVertexTextureChartBox * CATPolySurfaceVertexTextureChartBox::Cast(CATPolySurfaceVertexTextureChart * iChart)
{
  if (iChart && iChart->IsInstanceOf(ID_Chart_Box)) {
    iChart->AddRef();
    return (CATPolySurfaceVertexTextureChartBox *) iChart;
  }
  else
    return NULL;
}
#endif // !CATPolySurfaceVertexTextureChartBox_H
