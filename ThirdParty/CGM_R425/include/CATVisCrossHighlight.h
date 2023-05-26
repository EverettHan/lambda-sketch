/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2004
//
//==============================================================================
// Abstract
// --------
// 
//==============================================================================
// Usage
// -----
// 
//==============================================================================
// History
// -------
//     - August 10, 2004: Created. SRX
//==============================================================================
#ifndef CATVisCrossHighlight_H
#define CATVisCrossHighlight_H


/**
 * Flags to be used internally.
 * Used for 2D/3D Design to manage the highlight when using embedded cells.
 * 
 */

typedef int CATVisCrossHighlight;



#define AlwaysCallHighlight        0x01
#define TestTreeRoot               0x02
#define AddTreeRoot				   0x04

#endif

