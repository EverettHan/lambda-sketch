// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTetrisChart.h
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// Nov 2008  Creation: ZFI
//===================================================================


#ifndef CATPolyTetrisChart_H
#define CATPolyTetrisChart_H

#include "CATPolySurfaceVertexTextureChart.h"
#include "CATPolyVisuTetrisAtlas.h"
#include "CATMathVector.h"
#include "CATBoolean.h"

class CATPolyTetrisContour;

class CATSupport;
class CAT2DViewpoint;
class CAT2DBagRep;
class CATMathPoint2D;

class ExportedByPolyVisuTetrisAtlas CATPolyTetrisChart : public CATPolySurfaceVertexTextureChart
{

public:
  CATPolyTetrisChart(CATIPolySurface * ioSurface);
  virtual ~CATPolyTetrisChart();

public:
  static inline CATPolyTetrisChart * Cast(CATPolySurfaceVertexTextureChart * iChart);
    
  //virtual
  virtual HRESULT ReactToAddTextureCoordinate(const int iIndex, const double iU, const double iV, const CATMathVector & Tangent, const CATMathVector & Binormal);
  virtual HRESULT ReactToTranslateTexture(const double du, const double dv);
  virtual HRESULT ReactToScaleTexture(const double scalingFactor);
  virtual HRESULT PrepareForPacking();
  virtual HRESULT UpdateAfterPacking();
  inline virtual CATBoolean IsInstanceOf(const TypeChartID iId_Instance) const;

  //bounding, inline
  inline double GetBBHeight() const;
  inline double GetBBWidth() const;
  inline double GetBBArea() const;
  inline int GetNbVertices() const;

  //directions
  inline int GetNbDirections() const;

  //best pos
  inline HRESULT SetBottomLeftCorner(const double iX, const double iY) ;
  inline HRESULT GetBottomLeftCorner(double &oX, double &oY) const;

  inline HRESULT SetDirection(const int iDirection);
  inline int GetDirection() const;

  inline HRESULT SetScaling(const double iSpacing);
  inline double GetScaling()const;
  
  //main methods
  HRESULT GetHorizLimits(int** oBottom, 
                         int** oTop,
                         int& oRasterWidth,
                         int& oRasterHeight,
                         const double iPixelSize)const;

  HRESULT ComputeRotatedContours(int iNbDirections);
  HRESULT ComputeFreeEdges(double*& oEdgesVertices,int& oNbEdges)const;
  
  HRESULT Generate2DDistance(const int iWidth, const double iGutter, 
                             double& oHPos, double& oVPos, 
                             double& oZoomX, double& oZoomY, 
                             double& oPixelSize, 
                             double** oDistance, 
                             int& oHeight)const;
  
  HRESULT FlagDistance(const double iCoords[6], 
                       const double iSpacing, 
                       double* iDistance, 
                       const int iWidth, 
                       const int iHeight)const;
  
  double PointTriangleDistance(const CATMathPoint2D& iP,
                               const CATMathPoint2D& iP1, 
                               const CATMathPoint2D& iP2, 
                               const CATMathPoint2D& iP3)const;

  HRESULT Threshold(double* ioDistance,
                    const int iWidth, const int iHeight, 
                    const double iThresh)const;

  HRESULT MarchingSquares(const double* iDistance, 
                          const int iWidth, const int iHeight, 
                          double** oEdges, int& oNbEdges)const;

  HRESULT GetRotatedVertexPosition(int iVertex, double& oX, double& oY);

private:
  double _VMin, _VMax, _UMin, _UMax;
  double _BLX, _BLY;
  int _NbVertices;
  int _Direction, _NbDirections;
  double _Scaling;
  CATPolyTetrisContour** _RotatedContours;
  CATBoolean _Initialized;

//for debug
private:
  HRESULT AddEdgesToView(const double* iEdges, 
                         const int iNbEdges, 
                         const unsigned  int  iColor);
  
  HRESULT Print(const char* outputFile,
                const int iWidth, 
                const int iHeight)const;

private:
  CATSupport* _DebugSupport;
  CAT2DViewpoint* _DebugViewpoint;
  CAT2DBagRep* _DebugRep;

};

//inline
inline CATPolyTetrisChart * CATPolyTetrisChart::Cast(CATPolySurfaceVertexTextureChart * iChart)
{
  if (iChart && iChart->IsInstanceOf(ID_Chart_Tetris)) 
  {
    iChart->AddRef();
    return (CATPolyTetrisChart *) iChart;
  }
  else
    return NULL;
}

inline CATBoolean CATPolyTetrisChart::IsInstanceOf(const TypeChartID iId_Instance) const
{
  // If iId_Instance does not correspond to the current class, we
  // must check it with the mother class: a child is also an
  // instance of the mother.
  return (iId_Instance == ID_Chart_Tetris || CATPolySurfaceVertexTextureChart::IsInstanceOf(iId_Instance))?TRUE:FALSE;
}


inline double CATPolyTetrisChart::GetBBHeight() const
{
  return _VMax-_VMin;
}

inline double CATPolyTetrisChart::GetBBWidth() const
{
  return _UMax-_UMin;
}

inline double CATPolyTetrisChart::GetBBArea() const
{
  return (_VMax-_VMin)*(_UMax-_UMin);
}

inline int CATPolyTetrisChart::GetNbVertices() const
{
  return _NbVertices;
}

inline HRESULT CATPolyTetrisChart::SetBottomLeftCorner(const double iX, const double iY) 
{
  _BLX = iX;
  _BLY = iY;
  return S_OK;
}

inline HRESULT CATPolyTetrisChart::GetBottomLeftCorner(double &oX, double &oY) const
{
  oX = _BLX;
  oY = _BLY;
  return S_OK;
}

inline HRESULT CATPolyTetrisChart::SetDirection(const int iDirection)
{
  _Direction = iDirection;
  return S_OK;
}

inline int CATPolyTetrisChart::GetDirection() const
{
  return _Direction;
}

inline int CATPolyTetrisChart::GetNbDirections() const
{
  return _NbDirections;
}

inline HRESULT CATPolyTetrisChart::SetScaling(const double iScaling)
{
  _Scaling = iScaling;
  return S_OK;
}

inline double CATPolyTetrisChart::GetScaling()const
{
  return _Scaling;
}



#endif
