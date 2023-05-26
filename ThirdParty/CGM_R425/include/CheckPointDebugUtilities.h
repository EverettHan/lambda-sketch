/* -*-C++-*- */

#ifndef CheckPointDebugUtilities_H
#define CheckPointDebugUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 2001

//------------------------------------------------------------------------------
//
// CheckPoint utilities
//
//------------------------------------------------------------------------------

#include "RibbonLight.h"
#include "CATMathInline.h"



//----------------------------------------------------------------------------
// Set a CheckPoint
//----------------------------------------------------------------------------
extern "C" ExportedByRibbonLight void SetACheckPoint();
INLINE void SetCheckPoint() { SetACheckPoint(); }
#endif
