/* -*-C++-*-*/
#ifndef CATHLRNurbsSpec_H
#define CATHLRNurbsSpec_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2014
//
// CATHLRNurbsSpec 
//
// DESCRIPTION :
/**
 * Specifications for a surface that is a Nurbs surface.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Nov. 2014 NG4 Creation
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRSurfaceSpec.h"

class ExportedByHLRGeometry CATHLRNurbsSpec : public CATHLRSurfaceSpec
{
public:

//=============================================================================
// OVERRIDDEN METHODS
//=============================================================================
/** Gets the type of the surface.
 */
  virtual CATHLRConstant::TypeSurface GetType() const;

};

#endif
