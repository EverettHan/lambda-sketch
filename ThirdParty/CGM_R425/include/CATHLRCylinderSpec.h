/* -*-C++-*-*/
#ifndef CATHLRCylinderSpec_H
#define CATHLRCylinderSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCylinderSpec 
//
// DESCRIPTION :
/**
 * Specification of a surface this is in reality a cylinder.
 * <BR> One can get :
 * <UL>
 * <LI> a point of the axis </LI>
 * <LI> the direction of the axis </LI>
 * <LI> the radius </LI>
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

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRAxisSpecSurface.h"

#include "CATHLRConstant.h"  

class CATMathDirection;
class CATMathPoint;
class CATMathVector;

class ExportedByHLRGeometry CATHLRCylinderSpec : public CATHLRAxisSpecSurface
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Default constructor, with all the datas.
 */
  CATHLRCylinderSpec(const CATMathPoint     & iAxisPoint,
		     const CATMathDirection & iAxisDirection,
		     double                   iRadius);

//=============================================================================
// METHODS
//=============================================================================
/** Reads a point on the axis of the cylinder considered as an origin
 */
  void GetAxisOrigin(CATMathPoint & oAxisOrigin) const;

/** Reads the axis direction of the cylinder.
 *  <BR> The direction of the axis is normalized.
 */
  void GetAxisDirection(CATMathVector & oDirection) const;

/** Reads the radius of the cylinder
 */
  double GetRadius() const;

//------------------------------------------------------------
// Overridden method
//------------------------------------------------------------
 virtual CATHLRConstant::TypeSurface GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Radius of the cylinder.
  double   _Radius;
};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
