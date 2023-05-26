/* -*-C++-*-*/
#ifndef CATHLRCurveSpec_H
#define CATHLRCurveSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRCurveSpec 
//
// DESCRIPTION :
/**
 * Abstract class of specifications of a curve. One object of this type is
 * associated to each curve that is of a canonic type (line of circle).
 * <BR> The different types of curves recognised are :
 *  <UL><LI> Spline : for any curve </LI>
 *  <LI> Line </LI>
 *  <LI> Circle </LI> </UL>
 */
//
// Main Methods :
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

#include "CATHLRConstant.h"

class ExportedByHLRGeometry CATHLRCurveSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================

//=============================================================================
// METHODS
//=============================================================================
/** Gets the type of the curves. This should be used to cast this class into
 * the real type of object.
 */
  virtual CATHLRConstant::TypeCurve GetType() const = 0;

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
