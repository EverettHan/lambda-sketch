/* -*-C++-*-*/
#ifndef CATHLRHelixSpec_H
#define CATHLRHelixSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2002
//
// CATHLRHelixSpec 
//
// DESCRIPTION :
/**
 * Specifications of a curve that is in reality a Helix.
 * <BR> One can read the axis, first point and limit angles of the Helix.
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
// Dec. 2002 TPG Creation            
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurveSpec.h"
#include "CATHLRConstant.h"

#include "CATMathLine.h" 
#include "CATMathPoint.h"

class ExportedByHLRGeometry CATHLRHelixSpec : public CATHLRCurveSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor with the center, normal and radius.
 * <BR> Note tha the normal is supposed to be normalized.
 */
  CATHLRHelixSpec(const CATMathLine & iAxis, const CATMathPoint & iFirstPoint,
                  CATAngle iStartAngle, CATAngle iEndAngle);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the first point of the Helix
 */
  inline void GetFirstPoint(CATMathPoint & oFirstPoint) const;

/** Gets the axis of the Helix.
 */
  inline void GetAxis(CATMathLine & oAxis) const;

/** Gets the limit angle of the Helix.
 */
  inline void GetLimitAngle(CATAngle & oStartAngle, CATAngle & oEndAngle) const;

/** Overridden method to get the type of the curve : Helix
 */
  virtual CATHLRConstant::TypeCurve GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

  CATAngle     _StartAngle;
  CATAngle     _EndAngle;
  CATMathPoint _FirstPoint;
  CATMathLine  _Axis;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline void CATHLRHelixSpec::GetFirstPoint(CATMathPoint & oFirstPoint) const
{
  oFirstPoint = _FirstPoint;
}

inline void CATHLRHelixSpec::GetAxis(CATMathLine & oAxis) const
{
  oAxis = _Axis;
}

inline void CATHLRHelixSpec::GetLimitAngle(CATAngle & oStartAngle, CATAngle & oEndAngle) const
{
  oStartAngle = _StartAngle;
  oEndAngle   = _EndAngle;
}

#endif
