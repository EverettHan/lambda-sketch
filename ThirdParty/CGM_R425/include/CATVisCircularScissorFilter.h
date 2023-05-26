#ifndef CATVisCircularScissorFilter_H
#define CATVisCircularScissorFilter_H
//
// CATIA Version 5 Release 18 Framework Visualization
// Copyright Dassault Systemes 2006

#include "CATVisFilter.h"

class CATMathPointf;
class CATMathDirectionf;
class CATGraphicAttributeSet;
class IVisSGScissorFilter;

class ExportedBySGInfra CATVisCircularScissorFilter  : public CATVisFilter 
{
   CATDeclareVisFilter(CATVisCircularScissorFilter);
   CATVisDeclarePublicInterfaceAdhesion(CATVisCircularScissorFilter, IVisSGScissorFilter, CATVisCircularScissorFilterIVisSGScissorFilterBOAImpl);

 public :

  static CATVisCircularScissorFilter* Create(const float *iCenter,
                                             const float iRadius,
                                             const CATMathPointf &iPoint,
                                             const CATMathDirectionf &iDir_x,
                                             const CATMathDirectionf &iDir_y,
                                             const CATGraphicAttributeSet &iGas);

  void SetCircleAndPlane(const float *iCenter,
                         const float iRadius,
                         const CATMathPointf &iPoint,
                         const CATMathDirectionf &iDir_x,
                         const CATMathDirectionf &iDir_y,
                         const CATGraphicAttributeSet &iGas);

  void GetCircleAndPlane(float **oCenter,
                         float *oRadius,
                         CATMathPointf &oPoint,
                         CATMathDirectionf &oDir_x,
                         CATMathDirectionf &oDir_y,
                         CATGraphicAttributeSet *oGas);

  void SetBoundariesVisible (const unsigned int iVisible = 0);
  unsigned int GetBoundariesVisible () const;

 protected :

  CATVisCircularScissorFilter(const float *iCenter,
                              const float iRadius,
                              const CATMathPointf &iPoint,
                              const CATMathDirectionf &iDir_x,
                              const CATMathDirectionf &iDir_y,
                              const CATGraphicAttributeSet &iGas);

  virtual ~CATVisCircularScissorFilter();

  float _center[2];
  float _radius;
};
#endif 
  
  
