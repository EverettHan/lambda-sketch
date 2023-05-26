/* -*-C++-*-*/
#ifndef CATHLRSphereSpec_H
#define CATHLRSphereSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRSphereSpec 
//
// DESCRIPTION :
/**
 * Specifications for a surface that is a sphere.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Feb. 1998 JCH Creation            
// Dec. 1999 HKL Retrait du destructeur
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRSurfaceSpec.h"

class CATMathPoint;

class ExportedByHLRGeometry CATHLRSphereSpec : public CATHLRSurfaceSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor
 */
  CATHLRSphereSpec(const CATMathPoint & iCenter,
		   double               iRadius);

//=============================================================================
// METHODS
//=============================================================================
/** Gets the center of the sphere.
*/
  void GetCenter(CATMathPoint & oCenter) const;

/** Gets the radius.
 */
  inline double GetRadius() const;

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
  double   _Radius;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================
inline double CATHLRSphereSpec::GetRadius() const
{
  return _Radius;
}

#endif
