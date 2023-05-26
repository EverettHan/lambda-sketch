#ifndef CATTopSweepAdapter_H
#define CATTopSweepAdapter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATTopSweepAdapter
// Adapter for internal or forward releases enhancements of CATTopSweep not available on previous levels.
//
//                                                 Nicolas LOCHARD
//=============================================================================
// Usage notes:
//
//=============================================================================
// 26 10 06 NLD Creation
//              ForceMultipleViewingDirMode()
// 18 12 06 NLD Ajout ForceFillTwistMode()
//=============================================================================
// Module definition for Windows
#include <FrFTopologicalOpe.h>
// Advanced topological operators
#include <CATTopSweep.h>

#define CATTopSweepR18Adaption
//=============================================================================
#ifdef CATTopSweepR18Adaption

// Force multiple viewing direction moving frame mode on CATTopSweepOperator
// (this mode is available for a sweep without reference element and without pulling direction)
ExportedByFrFTopologicalOpe void ForceMultipleViewingDirMode(CATTopSweep* iTopSweepOperator) ;

// Force fill twist mode on CATTopSweepOperator
// (this mode is available for a simple sweep with no boolean operation, and if twist reduction mode is active)
ExportedByFrFTopologicalOpe void ForceFillTwistMode(CATTopSweep* iTopSweepOperator) ;
#endif

#endif
