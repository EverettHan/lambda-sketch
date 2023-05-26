/* -*-C++-*- */
#ifndef CATTopFreezeMode_H
#define CATTopFreezeMode_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
//
// CATTopFreezeMode
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Usage notes:
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Jan. 99    Creation                         C. Foucart
//------------------------------------------------------------------------------



/**
 * Defines the freeze mode for the topological operators.
 * @param  CatTopFreezeOff
 * The resulting body is not frozen
 * @param  CatTopFreezeOn
 * The resulting body is frozen
 */

enum CATTopFreezeMode
{ CatFreezeOff, CatFreezeOn };

#endif
