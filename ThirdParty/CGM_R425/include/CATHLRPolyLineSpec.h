/* -*-C++-*-*/
#ifndef CATHLRLineSpec_H
#define CATHLRLineSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2012
//
// CATHLRPolyLineSpec 
//
// DESCRIPTION :
/**
 * Specifications of a curve that is in reality a PolyLine.
 * <BR> Only for the type.
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
// June. 2012 DPS Creation            
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRCurveSpec.h"
#include "CATHLRConstant.h"


class ExportedByHLRGeometry CATHLRPolyLineSpec : public CATHLRCurveSpec
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from the two extremities of the curve
 */
  CATHLRPolyLineSpec();

//=============================================================================
// METHODS
//=============================================================================

/** Overridden method to get the type of the curve : Line
 */
  virtual CATHLRConstant::TypeCurve GetType() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:

};

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

#endif
