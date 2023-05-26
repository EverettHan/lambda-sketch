// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATCSSurface.h
// Header definition of CATCSSurface
//
//===================================================================
//
// Usage notes:
//   This class is to derived in the application to represent
//   a callback information about a parametric surface.
//   A surface is supposed to have C2 continuity.
//   This interface also covers swept surfaces.
//
//===================================================================
//
//  Jan 2003  Creation:                   Dmitry USHAKOV
//===================================================================
#ifndef CATCSSurface_H
#define CATCSSurface_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeometryLeaf.h"
#include "CATCDSEnums.h"

//-----------------------------------------------------------------------

/**
 * A callback for parametric surface.
 * Provides an information about parameters limits, and evaluators
 * for surfaces and its derivatives.
 */
class ExportedBySolverInterface CATCSSurface: public CATCSGeometryLeaf
{
public:
  CATCSSurface();
  virtual ~CATCSSurface();

  // Get the type of the surface
  // An application should never re-define this method.
  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;

  virtual void ApplyTransformation(const double iMatrix[3][3], const double iTranslation[3]) CATCDSOverride;

  // Get the limits for first parameter of the curve
  virtual CATParamType GetFirstLimits(double &oLow, double &oUp) = 0;

  // Get the limits for second parameter of the curve
  virtual CATParamType GetSecondLimits(double &oLow, double &oUp) = 0;

  // Evaluate the surface point or/and derivative at given parameter's value
  virtual void Evaluate(double  iFirst,
                        double  iSecond,
                        double* oaPoint,
                        double* oaDerivWithFirstParam,
                        double* oaDerivWithSecondParam,
                        double* oaSecondDeriv_du_du,
                        double* oaSecondDeriv_du_dv,
                        double* oaSecondDeriv_dv_dv) = 0;

  // Regenerate surface from the coordinates
  // @return
  //    TRUE if the dependent surface is created successfully,
  //    FALSE if the surface can't be created.
  virtual CATCDSBoolean Regenerate() CATCDSOverride;

  // Get defining geometric objects and variables
  virtual void GetDependencies(CATCDSLISTP(CATCSEntity) &oNodes) CATCDSOverride;

  /**
   * DO NOT USE
   * TEST ONLY
   */
  virtual void Scale(double iFactor);
};

//-----------------------------------------------------------------------

#endif
