/* -*-C++-*-*/
#ifndef CATHLRCurveDisc_H
#define CATHLRCurveDisc_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCurveDisc 
//
// DESCRIPTION :
/**
 * Curve for the HLR whose exact representation is a discretized set of points.
 * Is is defined by an array of points and the associated tangents. Evaluation is
 * performed by a Lhermitte approximation.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98 JCH Creation            
// Jun. 99 Added the GetParam method
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurve.h"

// Other includes
#include "CATHLRCrvParamRef.h"
#include "CATCGMScaleCategoryDef.h" // for enum CATCGMScaleCategory

class CATCrvLimits;
class CATCrvParam;
class CATCrvParamReference;
class CATHLRCurveSpec;
class CATMathPoint;
class CATMathVector;

class ExportedByHLRGeometry CATHLRCurveDisc : public CATHLRCurve
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Constructor from a jele and a container and a transformation, a pointer
 * on the specifity of the curve ( that might be NULL), and two array of points
 * and vectors which are the associated tangents.
 */
  CATHLRCurveDisc(int                 iIdentifier,
		              CATMathPoint      * iArrayPoints, 
                  CATMathVector     * iArrayTangents,
                  CATLONG32           iCountPoints,
                  CATHLRContainer   * iContainer,
                  const CATHLRTransformation * iTransformation,
                  CATCGMScaleCategory iScaleCategory,
                  CATHLRCurveSpec   * iSpecifity = 0L);


/**
 * Destructor
 */
  virtual ~CATHLRCurveDisc();

//=============================================================================
// OVERRIDDEN EVALUATION METHODS
//=============================================================================
/** Evaluates a point on the curve
 */
  virtual void EvalPoint(const CATCrvParam & iParam,
			 CATMathPoint      & oEvaluatedPoint) const;

/** Evaluates the derivative of the curve
 * Keep in mind that oEvaluatedTangent has to be dimensionless to be XScale compliant (DPS July 2nd 2013)
 */
  virtual void EvalFirstDeriv(const CATCrvParam & iParam,
			      CATMathVector     & oEvaluatedTangent) const;

/** Evalutes Second derivatives on the curve
 */
  virtual void EvalSecondDeriv(const CATCrvParam & iParam,
			       CATMathVector     & oEvaluatedDerivative) const;

//=============================================================================
// OVERRIDDEN MANAGEMENT METHODS
//=============================================================================
/** Gets the limits of the curve
 */
  virtual void GetLimits(CATCrvLimits & oLimits) const;

/** Gets the reference to build the parameters
 */
  virtual const CATCrvParamReference * GetReference() const;

/** For the display of the curve : returns a good number of points to
 *  discretize the curve for the display.
 */
  virtual CATLONG32 GetDiscretization() const;

/** Finds the parameter closest to the point within the limits.
 */
  virtual CATHLRCurve::Diagnostic GetParam(const CATMathPoint & iPoint, 
                                           CATCrvParam        & oParam,
                                           CATCrvLimits       * iLimits=(CATCrvLimits*) 0) const;


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Reference for the pcurve
  CATHLRCrvParamRef _CurveReference;

// Size of the datas
  CATLONG32              _CountPoints;

// Array of datas
  CATMathPoint    * _ArrayPoints;
  CATMathVector   * _ArrayTangents;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
