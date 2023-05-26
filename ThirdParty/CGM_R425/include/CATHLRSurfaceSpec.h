/* -*-C++-*-*/
#ifndef CATHLRSurfaceSpec_H
#define CATHLRSurfaceSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRSurfaceSpec 
//
// DESCRIPTION :
/**
 * Abstract class of specifications of a curve. One object of this type is
 * associated to each curve that is of a canonic type (line of circle).
 * <BR> The different types of curves recognised are :
 * <UL>
 * <LI> Other : for any curve </LI>
 * <LI> Plane </LI>
 * <LI> Cone </LI>
 * <LI> Cylinder </LI>
 * <LI> Sphere </LI>
 * <LI> TabulatedCylinder </LI>
 * </UL>
 */
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

//=============================================================================
// For Windows NT
//-----------------------------------------------------------------------------
#include "HLRGeometry.h"

//=============================================================================
// Other includes
//-----------------------------------------------------------------------------
#include "CATHLRConstant.h"

//=============================================================================
// Class definition
//-----------------------------------------------------------------------------

class ExportedByHLRGeometry CATHLRSurfaceSpec
{
public:
//=============================================================================
// METHODS
//=============================================================================
/** Gets the type of the surface.
 */
  virtual CATHLRConstant::TypeSurface GetType() const = 0 ;
  
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
