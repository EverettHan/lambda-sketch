/* -*-C++-*-*/
#ifndef CATHLRAxisSpecSurface_H
#define CATHLRAxisSpecSurface_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRAxisSpecSurface 
//
// DESCRIPTION :
/**
 * Specifity for surfaces that have an axis
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

class CATMathAxis;
class CATMathDirection;
class CATMathPoint;

class ExportedByHLRGeometry CATHLRAxisSpecSurface : public CATHLRSurfaceSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/** Default constructor.
*/
  CATHLRAxisSpecSurface(const CATMathPoint     & iOrigin,
                        const CATMathDirection & iDirection);

//=============================================================================
// METHODS
//=============================================================================
/** Gets an axis.
 */
  void GetAxis(CATMathAxis & oAxis);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Position of the axis
  double     _AxisOrigin[3]; // dimension dependant
  double     _Direction[3];  // dimensionless

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
