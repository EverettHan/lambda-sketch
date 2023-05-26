#ifndef CATVisPolygonalScissorFilter_H
#define CATVisPolygonalScissorFilter_H
//
// CATIA Version 5 Release 18 Framework Visualization
// Copyright Dassault Systemes 2006

#include "SGInfra.h"
#include "CATVisFilter.h"

class CATMathPointf;
class CATMathDirectionf;
class CATGraphicAttributeSet;
class IVisSGScissorFilter;

class ExportedBySGInfra CATVisPolygonalScissorFilter  : public CATVisFilter 
{
   CATDeclareVisFilter(CATVisPolygonalScissorFilter);
   CATVisDeclarePublicInterfaceAdhesion(CATVisPolygonalScissorFilter, IVisSGScissorFilter, CATVisPolygonalScissorFilterIVisSGScissorFilterBOAImpl);

 public :

  static CATVisPolygonalScissorFilter* Create(const int iNbVertex,
                                              const float *iVertices,
                                              const CATMathPointf &iPoint,
                                              const CATMathDirectionf &iDir_x,
                                              const CATMathDirectionf &iDir_y,
                                              const CATGraphicAttributeSet &iGas);

  /**
  * Create poly-polygon scissor 
  * @param iNbPolygon
  *   number of polygons
  * @param ipNbVertex
  *   number of points in each polygon (array size is iNbPolygon)
  * @param ipVertices
  *   polygon coordinates in same order as ipNbVertex (array size is SUM OF(ipNbVertex))
  * @param iPoint
  *   point for defining plane of this scirror 
  * @param iDir_x
  *   x direction for defining plane of this scirror 
  * @param iDir_y
  *   y direction for defining plane of this scirror 
  * @param iGas
  *   Graphic properties in case the polygons are displayed (@see SetBoundariesVisible)
  **/
  static CATVisPolygonalScissorFilter* Create(const int iNbPolygon,
                                              const int *ipNbVertex,
                                              const float *ipVertices,
                                              const CATMathPointf &iPoint,
                                              const CATMathDirectionf &iDir_x,
                                              const CATMathDirectionf &iDir_y,
                                              const CATGraphicAttributeSet &iGas);

  void SetPolygonAndPlane(const int iNbVertex,
                          const float *iVertices,
                          const CATMathPointf &iPoint,
                          const CATMathDirectionf &iDir_x,
                          const CATMathDirectionf &iDir_y,
                          const CATGraphicAttributeSet &iGas);

  /** Poly-polygon support: to be removed **/
  void GetPolygonAndPlane(int *oNbVertex,
                          float **oVertices,
                          CATMathPointf &oPoint,
                          CATMathDirectionf &oDir_x,
                          CATMathDirectionf &oDir_y,
                          CATGraphicAttributeSet *oGas);

  void SetPolygonAndPlane(const int iNbPolygon,
                          const int *ipNbVertex,
                          const float *ipVertices,
                          const CATMathPointf &iPoint,
                          const CATMathDirectionf &iDir_x,
                          const CATMathDirectionf &iDir_y,
                          const CATGraphicAttributeSet &iGas);

  void GetPolygonAndPlane(int &oNbPolygon,
                          float **opNbVertex,
                          float **opVertices,
                          CATMathPointf &oPoint,
                          CATMathDirectionf &oDir_x,
                          CATMathDirectionf &oDir_y,
                          CATGraphicAttributeSet *oGas);

  void SetBoundariesVisible (const unsigned int iVisible = 0);
  unsigned int GetBoundariesVisible () const;

  virtual unsigned char GetType() const;
	
 protected :

  CATVisPolygonalScissorFilter(const int iNbPolygon,
                               const int *ipNbVertex,
                               const float *ipVertices,
                               const CATMathPointf &iPoint,
                               const CATMathDirectionf &iDir_x,
                               const CATMathDirectionf &iDir_y,
                               const CATGraphicAttributeSet &iGas);

  virtual ~CATVisPolygonalScissorFilter();
};
#endif 
  
  
