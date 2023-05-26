// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// Header definition of CATPolyMathCGMSurface
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2010  Creation: zfi
//===================================================================


#ifndef CATPolyMathCGMSurface_H
#define CATPolyMathCGMSurface_H

#include "CATErrorDef.h"   // HRESULT Definition.
#include "CATPolyMathQuadSurface.h" 
#include "CATSurLimits.h"
#include "CATBoolean.h"
#include "CATMapOfFloatsToPtr.h"
#include "ExportedByTessellateCommon.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

class CATSurface;
class CATSurLimits;
class CATMathFunctionX;

class ExportedByTessellateCommon CATPolyMathCGMSurface   : public CATPolyMathQuadSurface
{
public:

  CATPolyMathCGMSurface (CATGeoFactory* iGeoFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                         CATSurface* iCGMSurface, const CATSurLimits& iSurLimits, int iOrientation,CATBoolean iReleaseSurface);

  virtual ~CATPolyMathCGMSurface ();

public:
  Type GetType () const;

public:

  CATPolyMathQuadSurface * Clone () const;  
  void GetPoint (const unsigned int vertex, CATMathPoint& oPoint) const;
  void GetNormal (const unsigned int vertex, CATMathVector& oNormal) const;

public:

  void Evaluate (const double u, const double v, CATMathPoint& oPoint) const;
  void Evaluate (const double u, const double v, CATMathVector& oNormal) const;
 
  void Evaluate (const double u, const double v, CATMathPoint& oPoint,
                         CATMathVector& oNormal) const;

  void EvaluatePartialDerivatives (const double u, const double v, double odPdu[], double odPdv[]) const;

public:

  void EvaluateAlongSide (const int iSide, const double t, CATMathPoint& oPoint) const ;
  void EvaluateAlongSide (const int iSide, const double t, CATMathPoint& oPoint, CATMathVector& oNormal) const;
  void EvaluateDerivativeAlongSide (const int iSide, const double t, double odPdt[]) const;
  void GetMaxSecondDerivatives(double& oMaxSecondDerivativeAlongU,double& oMaxSecondDerivativeAlongV)const;
  void GetSecondDerivatives(const double u, const double v, double oDuu[],double oDvv[], double oDuv[])const;

public:
  virtual HRESULT Accept (CATPolyMathSurfaceConstVisitor &iV) const;
  virtual HRESULT Accept (CATPolyMathSurfaceVisitor &iV) ;

public:
  CATSurface* _CGMSurface;
  CATSurLimits* _SurLimits;
  int _Orientation;

  CATGeoFactory* _GeoFactory;
  CATSoftwareConfiguration * _SoftwareConfiguration;

  CATBoolean _ReleaseSurface;

  CATMathFunctionX* _Optimizer;
};


#endif
