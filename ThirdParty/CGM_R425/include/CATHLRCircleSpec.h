/* -*-C++-*-*/
#ifndef CATHLRCircleSpec_H
#define CATHLRCircleSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCircleSpec 
//
// DESCRIPTION :
/**
 * Specifications of a curve that is in reality a circle.
 * <BR> One can read the center, normal and radius of the circle.
 *
 */
//
//  
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 1998 JCH Creation            
// Dec. 1999 HKL Retrait du destructeur
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurveSpec.h"
#include "CATHLRConstant.h"

class CATMathDirection; 
class CATMathPoint;
class CATMathVector;

class ExportedByHLRGeometry CATHLRCircleSpec : public CATHLRCurveSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor with the center, normal and radius.
 * <BR> Note tha the normal is supposed to be normalized.
 */
  CATHLRCircleSpec(const CATMathPoint     & iCenter,
		   const CATMathDirection & iNormal,
		   double iRadius);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the center of the circle
 */
  void GetCenter(CATMathPoint &  oCenter) const;

/** Gets the normal to the circle. The returned vector is normalized
 */
  void GetNormal(CATMathVector & oNormal) const;

/** Gets the radius of the circle
 */
  double GetRadius() const;

/** Overridden method to get the type of the curve : Circle
 */
  virtual CATHLRConstant::TypeCurve GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Center of the circle
  double   _Center[3];
  double   _Normal[3];
  double   _Radius;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
