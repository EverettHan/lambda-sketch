/**
 * @quickReview TPG 01:07:24
 */
#ifndef CATHLRCurve_H
#define CATHLRCurve_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRCurve : three-dimensional curve, defined for the HLR, for all 
// the evaluations that will lead to the result
//
/** Three-dimensional curve, defined for the HLR, for all 
 *  the evaluations that will lead to the result.
 */
// 
// Main Methods :
//  - EvalPoint
//  - EvalFirstDeriv
//  - EvalSecondDeriv
//  - GetReference
//  - GetLimits
//  
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Nov. 97 JCH Creation            
// Jun. 99 HKL Added GetParam, GetParameters, Eval methods
// Oct. 99 HKL Stored CurveType in CurveSpec to save memory
// Nov. 99 HKL Added the FixCorrupt method
// Jul. 01 TPG Added the SetDiscretization method
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRGeometry.h"
#include "CATHLRConstant.h"

class CATBaseUnknown;
class CATCrvLimits;
class CATCrvParam;
class CATCrvParamReference;
class CATCrvEvalCommand;
class CATCrvEvalLocal;

class CATHLRCurveSpec;
class CATMathPoint;
class CATMathVector;
/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

class ExportedByHLRGeometry CATHLRCurve : public CATHLRGeometry
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a jele and a container and a transformation, and a pointer
 * on the specifity of the curve ( that might be NULL).
 */
  CATHLRCurve(int                          iJele,
	            CATHLRContainer            * iContainer,
              const CATHLRTransformation * iTransformation,
              CATHLRCurveSpec            * iSpecifity);

/** Constructor from a pointer on geometry and a container and a transformation
 */
  CATHLRCurve(void                       * iGeometry,
	            CATHLRContainer            * iContainer,
              const CATHLRTransformation * iTransformation,
              CATHLRCurveSpec            * iSpecifity);

//=============================================================================
// EVALUATION METHODS
//=============================================================================
/** Evaluates a point on the curve
 */
  virtual void EvalPoint(const CATCrvParam & iParam,
			                   CATMathPoint      & oEvaluatedPoint) const = 0;

/** Evaluates the derivative of the curve
 */
  virtual void EvalFirstDeriv(const CATCrvParam & iParam,
			                        CATMathVector     & oEvaluatedTangent) const = 0;

/** Evaluates the (at most 2) derivatives of the curve
 */
  virtual void EvalFirstDeriv(const CATCrvParam & iParam,
			                        CATMathVector      oEvaluatedTangent[2], int &oNbTgt1or2) const;

/** Evalutes Second derivatives on the curve
 */
  virtual void EvalSecondDeriv(const CATCrvParam & iParam,
			                         CATMathVector     & oEvaluatedDerivative) const = 0;

/** Evaluates point and derivatives in one shot
 */
  virtual void Eval(const CATCrvParam       & iPoint,
		                const CATCrvEvalCommand & iCommand,
                    CATCrvEvalLocal         & oResult) const ;

//=============================================================================
// MANAGEMENT METHODS
//=============================================================================
/** Gets the limits of the curve
 */
  virtual void GetLimits    (CATCrvLimits & oLimits) const = 0;
  virtual void GetStartLimit(CATCrvParam  & oStartLimit) const;
  virtual void GetEndLimit  (CATCrvParam  & oEndLimit) const;

/** Gets the reference to build the parameters
 */
  virtual const CATCrvParamReference * GetReference() const = 0;

//=============================================================================
// ABOUT THE GEOMETRY OF THE CURVE
//=============================================================================
/** Finds the parameter closest to the point within the limits.
 */
  enum Diagnostic {NoSolution, SingleSolution, MultipleSolution};
  virtual CATHLRCurve::Diagnostic GetParam(const CATMathPoint & iPoint, 
                                           CATCrvParam        & oParam,
                                           CATCrvLimits       * iLimits=(CATCrvLimits*) 0) const = 0;

/** Gets the type of the curves. This should be used to cast this class into
 * the real type of object.
 */
  CATHLRConstant::TypeCurve GetTypeOfCurve() const;

/** Gets the curve's specificity.
 * <BR> It returns NULL if the curve is a spline, with no known properties.
 * <BR> It returns a pointer on a CATHLRCurveSpec, on which a Type of curve
 * can be read, and which can be cast to the good class inherited from 
 * CATHLRCurveSpec.
 */
  const CATHLRCurveSpec * GetSpecificity() const;

/** Sets the curve's specificity.
 */
  void SetSpecificity(CATHLRCurveSpec * iCurveSpec);

/** Gets the entity version.
 *  0: unknown   1: V5    2: V4    3: Rep  ....
 */  
  virtual CATLONG32 GetEntityVersion() const;

//=============================================================================
// ABOUT THE GEOMETRY OF THE CURVE
//=============================================================================
/** For the display of the curve : returns a good number of points to
 *  discretize the curve for the display.
 */
  virtual CATLONG32 GetDiscretization() const = 0;

/** For the display of the curve : sets a good number of points to
 *  discretize the curve for the display.
 */
  virtual void SetDiscretization(CATLONG32 iDiscretization);

/** For Polylines, retrieves the curve parametrization.
 *  For other curves, returns NULL
 */
  virtual const double * GetParameters() const;

/** Try to modify the curve parametrization if it's said corrupt by HLM
 */
  //virtual void FixCorrupt();

/** Retrieves the ParameterFactor (used by the CATHLREdgeCGM constructor)
 */
  //inline double GetParameterFactor();
  
//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointer on a curve specifity.
  CATHLRCurveSpec * _CurveSpecificity;

// For curves with large parameters and small distances..
//  double      _ParameterFactor;

// Discretization.
  CATLONG32        _Discretization;

// Type of curve
//  CATHLRConstant::TypeCurve _CurveType;

};

//-----------------------------------------------------------------------------

/*inline double CATHLRCurve::GetParameterFactor()
{
  return _ParameterFactor;
}*/

#endif
