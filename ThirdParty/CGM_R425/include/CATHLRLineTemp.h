#ifndef CATHLRLineTemp_H
#define CATHLRLineTemp_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRLineTemp : three-dimensional line, defined for the HLR silhouettes
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
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jun 99 HKL Creation            
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurve.h"

#include "CATMathLine.h"
#include "CATHLRCrvParamRef.h"
#include "CATCGMScaleCategoryDef.h" // for enum CATCGMScaleCategory

class CATCrvLimits;
class CATCrvParam;
class CATCrvParamReference;
class CATMathPoint;


class ExportedByHLRGeometry CATHLRLineTemp : public CATHLRCurve
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a jele and a container and a transformation, and a pointer
 * on the specifity of the curve ( that might be NULL).
 */
  CATHLRLineTemp(int                  iIdentifierInContainer,
                 CATHLRContainer    * iContainer,
                 const CATMathPoint & iStart,
                 const CATMathPoint & iEnd,
                 CATCGMScaleCategory  iScaleCategory,
                 CATHLRCurveSpec    * iSpecifity);

//=============================================================================
// EVALUATION METHODS
//=============================================================================
/** Evaluates a point on the curve
 */
  virtual void EvalPoint(const CATCrvParam & iParam,
			                   CATMathPoint      & oEvaluatedPoint) const;

/** Evaluates the derivative of the curve
 */
  virtual void EvalFirstDeriv(const CATCrvParam & iParam,
			                        CATMathVector     & oEvaluatedTangent) const;

/** Evalutes Second derivatives on the curve
 */
  virtual void EvalSecondDeriv(const CATCrvParam & iParam,
			                         CATMathVector     & oEvaluatedDerivative) const;

//=============================================================================
// MANAGEMENT METHODS
//=============================================================================
/** Gets the limits of the curve
 */
  virtual void GetLimits(CATCrvLimits & oLimits) const;
  virtual void GetStartLimit(CATCrvParam & oStartLimit) const;
  virtual void GetEndLimit  (CATCrvParam & oEndLimit) const;

/** Gets the reference to build the parameters
 */
  virtual const CATCrvParamReference * GetReference() const;

//=============================================================================
// ABOUT THE GEOMETRY OF THE CURVE
//=============================================================================
/** Finds the parameter closest to the point within the limits.
 */
  virtual CATHLRCurve::Diagnostic GetParam(const CATMathPoint & iPoint, 
                                           CATCrvParam        & oParam,
                                           CATCrvLimits       * iLimits=(CATCrvLimits*) 0) const;

//=============================================================================
// ABOUT THE GEOMETRY OF THE CURVE
//=============================================================================
/** For the display of the curve : returns a good number of points to
 *  discretize the curve for the display.
 */
  virtual CATLONG32 GetDiscretization() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Reference for the pcurve
  CATHLRCrvParamRef _CurveReference;

// Line data
  CATMathLine _MathLine;
};

#endif


