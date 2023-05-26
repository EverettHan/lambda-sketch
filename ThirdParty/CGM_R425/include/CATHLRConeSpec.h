/* -*-C++-*-*/
#ifndef CATHLRConeSpec_H
#define CATHLRConeSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRConeSpec 
//
// DESCRIPTION :
/**
 * Specifications of a surface this is in reality a cone.
 * <BR> One can get :
 * <UL>
 * <LI> the point of the axis that is at the larger extremity of the cone </LI>
 * <LI> the direction of the axis </LI>
 * <LI> the start radius and end radius </LI>
 * <LI> the semi-angle at the top of the cone </LI>
 * <LI> the length of the cone
 * </UL>
 * <BR> Note that the less large extremity of the cone is obtained
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

class ExportedByHLRGeometry CATHLRConeSpec : public CATHLRAxisSpecSurface
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor with the axis, the two radius and the length.
 */
  CATHLRConeSpec(const CATMathPoint     & iAxisOrigin,
		 const CATMathDirection & iAxisDirection,
		 double                   iStartRadius,
		 double                   iEndRadius,
		 double                   iSemiAngle,
		 double                   iLength);

//=============================================================================
// METHODS
//=============================================================================
/** Reads the origin of the axis
 */
  void GetAxisOrigin(CATMathPoint & oAxisPoint) const;

/** Reads the axis direction. The result is normalized.
 */
  void GetAxisDirection(CATMathVector & oAxisDirection) const;

/** Reads the radius of the cone at the axis origin. 
 */
  double GetStartRadius() const;

/** Reads the radius of the cone at the other extremity of the cone.
 */
  double GetEndRadius() const;

/** Reads the semi-angle at the top of the cone
 */
  double GetSemiAngle() const;

/** Reads the length of the cone
 */
  double GetLength() const;

//------------------------------------------------------------
// Overridden method
//------------------------------------------------------------
 virtual CATHLRConstant::TypeSurface GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Datas of the geometry
  double     _StartRadius, _EndRadius;
  double     _SemiAngle;
  double     _Length;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
