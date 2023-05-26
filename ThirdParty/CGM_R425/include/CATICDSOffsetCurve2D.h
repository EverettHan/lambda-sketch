#ifndef CATICDSOffsetCurve2D_H
#define CATICDSOffsetCurve2D_H

// COPYRIGHT DASSAULT SYSTEMES  2011

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"
#include "CATIAV5Level.h"

#include "CATICDSEnums.h"
#include "CATCDSBoolean.h"
#include "CATICDSCurve2D.h"

class CATICDSFactory;
class CATICDSVariable;

/**
 * Constructed from an arbitrary CATICDSMonoParameteric instance,
 * CATICDSOffsetCurve2D represents its offset curve with a given offset radius.
 * The offset may include cusps and local self-intersections
 * that appear around the input curve discontinuities and
 * intervals where curvature radius is less than offset radius.
 * The offset curve parametrization is induced by the input curve,
 * its limits are identical to those of the input curve if the offset is not extrapolated.
 * Extrapolation options are given by SetExtrapolationMode(): none, linear, or C2 extrapolations
 * are provided in option. The default is a linear extrapolation.
 */
class ExportedByCDSInterface CATICDSOffsetCurve2D : public CATICDSCurve2D
{
public:
  
  /**
   * Retreive base curve.
   */
  virtual CATICDSMonoParametric2D* GetBaseCurve() const = 0;
  
  /**
   * Retreive offset's radius variable.
   */
  virtual CATICDSVariable* GetOffsetVariable() const = 0;

  /**
  /*Extend the parametric domain from [Low, Up] to [-1e12, 1e12] with linear extrapolation
  /* @param 
  /*  - FALSE deactivate the extrapolation
  /*  - TRUE activate the extrapolation 
  /* @return FALSE if extrapolation is not allowed for the given curve and/or for the given extrapolation mode
  */
  virtual CATCDSBoolean Extrapolate(CATCDSBoolean iExtrapolate) const = 0;

  /**
   * Return an approximation of the offset curve
   *
   * @SIZE oaControlPoints oNbOfControlPoints
   * @SIZE oaKnots oNbOfControlPoints+oDegree+1
   * @SIZE oaWeights oNbOfControlPoints
   *
   * @SKIP
   */
  virtual CATCDSBoolean GetNURBSApprox(double iLinearTolerance, int& oNbOfControlPoints, int& oDegree, double*& oaControlPoints, double*& oaKnots, double*& oaWeights) = 0;

  /**
   * Creates an instance of the CATICDSOffsetCurve2D geometry
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipBaseCurve
   *   Pointer to the base curve to offset (can be anything by a line or a circle).
   * @param ipDistanceVariable
   *   Pointer to the variable to use as offset distance.
   *
   * @RENAME CreateVariableOffset
   */
   static CATICDSOffsetCurve2D* Create(CATICDSFactory* ipFactory, CATICDSMonoParametric2D* ipBaseCurve, CATICDSVariable* ipDistanceVariable);

#if defined(CATIAV5R27) || defined (CATIAR419) || defined(_EMSCRIPTEN_SOURCE)
  /**
   * Creates an instance of the CATICDSOffsetCurve2D geometry
   * @param ipFactory
   *   Pointer to the instance of CATICDSFactory to use.
   * @param ipBaseCurve
   *   Pointer to the base curve to offset (can be anything by a line or a circle).
   * @param iDistance
   *   Value of the offset distance.
   *
   * @RENAME CreateFixOffset
   */
   static CATICDSOffsetCurve2D* Create(CATICDSFactory* ipFactory, CATICDSMonoParametric2D* ipBaseCurve, double iDistance);
#endif

   virtual ~CATICDSOffsetCurve2D() {}
};

#endif
