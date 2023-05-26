/* -*-C++-*-*/
#ifndef CATHLRTorusSpec_H
#define CATHLRTorusSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRTorusSpec 
//
// DESCRIPTION :
/**
 * Specifications for a surface that is a Torus.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : Yes
//=============================================================================
//
// History
//
// Jun. 1999 HKL Creation
// Dec. 1999 HKL Retrait du destructeur
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRSurfaceSpec.h"

class CATMathPoint;
class CATMathDirection;

class ExportedByHLRGeometry CATHLRTorusSpec : public CATHLRSurfaceSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRTorusSpec(const CATMathPoint     & iCenter,
                  const CATMathDirection & iAxis,
                  double                   iMinorRadius,
                  double                   iMajorRadius);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the center of the torus.
*/
  void GetCenter(CATMathPoint & oCenter) const;

/** Gets the axis of the torus.
*/
  void GetAxis(CATMathDirection & oAxis) const;

/** Gets the major radius.
 */
  inline double GetMajorRadius() const;

/** Gets the minor radius.
 */
  inline double GetMinorRadius() const;

//=============================================================================
// OVERRIDDEN METHODS
//=============================================================================
/** Gets the type of the surface.
 */
  virtual CATHLRConstant::TypeSurface GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Coordinates of the center
  double   _Center[3];
  double   _Axis[3];
  double   _MinorRadius;
  double   _MajorRadius;

};

//=============================================================================
// INLINE FUNCTIONS
//=============================================================================
inline double CATHLRTorusSpec::GetMajorRadius() const
{
  return _MajorRadius;
}

inline double CATHLRTorusSpec::GetMinorRadius() const
{
  return _MinorRadius;
}

#endif
