// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// Header definition of CATPolyMathCGMCurve
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// June 2010  Creation: zfi
//===================================================================


#ifndef CATPolyMathCGMCurve_H
#define CATPolyMathCGMCurve_H

#include "CATErrorDef.h" 
#include "CATPolyMathCurve.h" 
#include "CATCrvLimits.h"
#include "CATBoolean.h"
#include "ExportedByTessellateCommon.h"

class CATGeoFactory;
class CATSoftwareConfiguration;

class CATCurve;
class CATCrvLimits;

class ExportedByTessellateCommon CATPolyMathCGMCurve : public CATPolyMathCurve
{
public:
  CATPolyMathCGMCurve (CATGeoFactory* iGeoFactory, CATSoftwareConfiguration * iSoftwareConfiguration,
                       CATCurve* iCurve, CATBoolean iReleaseCurve);
  virtual ~CATPolyMathCGMCurve ();

public:
  Type GetType () const;

public:
  CATPolyMathCurve* Clone () const;  
  void GetPoint (const unsigned int vertex, CATMathPoint& oPoint) const;

public:
  void Evaluate (const double t, CATMathPoint& oPoint) const;
  void EvaluateDerivative (const double t, double odPdt[]) const;
  void EvaluateSecondDerivative(const double t, double odDdt[])const;
  double GetMaxSecondDerivative()const;

public:
  HRESULT Accept (CATPolyMathCurveConstVisitor &iV) const;
  HRESULT Accept (CATPolyMathCurveVisitor &iV);

public:
  CATCurve* _CGMCurve;

  CATGeoFactory* _GeoFactory;
  CATSoftwareConfiguration * _SoftwareConfiguration;

  CATBoolean _ReleaseCurve;
};


#endif
