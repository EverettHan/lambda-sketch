/**
 * @quickReview ABT 01:07:17
 * @quickReview LVL 01:07:24
 */
#ifndef CATHLRProjection_H
#define CATHLRProjection_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
//
// CATHLRProjection : object that computes a projection of a point for the HLR
//
// DESCRIPTION : the projected point coordinates are those that would have been
// if the Target plane was the (OXY) plane, without taking in account the z
// coodinate.
//
// Main Methods :
//  EvalProjection()
//
//=============================================================================
// Abstract Class     : Yes
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jul. 97   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

#include "HLRGeometry.h"

#include "CATHLRConstant.h"
#include "CATMathVector.h"
#include "CATMathDirection.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATMathDirection;
class CATPlane;
class CATMathPoint;
class CATMathPoint2D;
class CATMathVector2D;
class CATMathTransformation;
class CATTolerance;

class ExportedByHLRGeometry CATHLRProjection
{
public:

//=============================================================================
// Static methods
//=============================================================================
// Function that makes a CATHLRProjection from a target, observer and projection type
static CATHLRProjection * CreateProjection(const CATMathPoint           & iObserver, 
					                                 const CATMathPoint           & iTarget,
                                           CATHLRConstant::TypeProjection iTypeProjection,
                                           const CATTolerance           & iTol,
					                                 const CATMathDirection       &iUpVector=CATMathK );

// Create an orthogonal projection on a plane 
static CATHLRProjection * CreateProjection(const CATPlane               * iPlaneScreen,
                                           CATHLRConstant::TypeProjection iTypeProjection,
                                           const CATTolerance           & iTol);

//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

// Constructor from an Observer and a target
CATHLRProjection(const CATMathPoint  & iObserver,
                 const CATMathPoint  & iTarget,
                 const CATMathVector & iUpVector,
                 const CATTolerance  & iTol);

// Destructor
virtual ~CATHLRProjection();

//=============================================================================
// Evaluation
//=============================================================================
// Project a point in the screen's axis
virtual void EvalProjection(const CATMathPoint & iPointToProject,
                            CATMathPoint       & oProjectedPoint) const = 0;

// Project a tangent and replace it in the screen's axis
virtual void EvalProjection(const CATMathPoint     & iPoint,
                            const CATMathDirection & iTangent,
                            CATMathDirection       & oProjectedDirection) const = 0;

// Project a point and replace it in a two dimensional space
virtual void EvalProjection(const CATMathPoint & iPointToProject,
                            CATMathPoint2D     & oProjectedPoint) const = 0;


// Evaluate the direction of view (sight) at a given point
virtual CATMathDirection GetSight(const CATMathPoint &iPoint) const = 0;

// Returns the Z coordinate of the Observer versus the projectionplane
virtual double GetZObserverVsProjectionPlane() const;

virtual CATBoolean IsConical() const;

// Project a point from the projection screen's axis to the 3D axis
HRESULT InverseProjectPtPosition(const CATMathPoint & iPtVsProjScreenAxis, CATMathPoint & oPt3DRefAxis);

// For debug
//  virtual void Dump() const;


private:

  // Default constructor
  CATHLRProjection();


//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

// Coordinates of the transformation matrix
  double _A11, _A12, _A13;
  double _A21, _A22, _A23;
  double _A31, _A32, _A33;

// Coordinates of the translation to place the Target at the origin
  double                  _TranslationX;
  double                  _TranslationY;
  double                  _TranslationZ;

  // Position of the observer in the original space
  CATMathPoint            _Observer;

  CATMathTransformation * _InverseMatrix;
  const CATTolerance    & _Tol;
};


#endif
