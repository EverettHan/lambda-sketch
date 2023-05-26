/* -*-C++-*- */
#ifndef CATTopRibCriticalZone_H
#define CATTopRibCriticalZone_H

// COPYRIGHT DASSAULT SYSTEMES  2001

//----------------------------------------------------------------------
//- Software Modifications for Rib-based operators
//----------------------------------------------------------------------
#include "Ribbon.h"


/**
 * @nodoc
 */	
ExportedByRibbon void CATTopRibResetCriticalZones();

ExportedByRibbon int CATTopRibGetIgnoreSharpEdgeCriticalZoneState();

ExportedByRibbon void CATTopRibSetIgnoreSharpEdgeCriticalZoneState(int iState);


#endif
