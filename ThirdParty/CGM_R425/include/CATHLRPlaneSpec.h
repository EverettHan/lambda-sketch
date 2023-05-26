/* -*-C++-*-*/
#ifndef CATHLRPlaneSpec_H
#define CATHLRPlaneSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRPlaneSpec 
//
// DESCRIPTION :
/**
 * Specification of a surface this is in reality a Plane.
 * <BR> One can read the origin and the normal of the plane
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

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRAxisSpecSurface.h"

#include "CATHLRConstant.h"  
class CATMathDirection;
class CATMathPoint;
class CATMathVector;

class ExportedByHLRGeometry CATHLRPlaneSpec : public CATHLRAxisSpecSurface
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor : with the origin of the plane an the normal, that is
 * supposed normalized.
 */
  CATHLRPlaneSpec(const CATMathPoint     & iOrigin,
		  const CATMathDirection & iNormal);

//=============================================================================
// METHODS
//=============================================================================
/** Reads the origin of the plane
 */
  void GetOrigin(CATMathPoint & oOrigin) const;

/** Reads the normal to the plane.
 * <BR> The result vector in normalized.
 */
  void GetNormal(CATMathVector & oNormal) const;

//------------------------------------------------------------
// Overridden method
//------------------------------------------------------------
 virtual CATHLRConstant::TypeSurface GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
