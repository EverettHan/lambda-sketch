/* -*-C++-*- */
#ifndef CATTopSplitType_H
#define CATTopSplitType_H

// COPYRIGHT DASSAULT SYSTEMES 1999

//------------------------------------------------------------------------------
//
// CATTopSplitType
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
 * Defines the bodies to be kept after the split operation 
 * @param  CatSplitBothSides
 * All resulting bodies are kept
 * @param  CatSplitPositiveSideOnly
 * Are only kept bodies compatible with the left matterside of the splitting geometry 
 * @param  CatSplitNegativeSideOnly
 * Are only kept bodies compatible with the right matterside of the splitting geometry
 */ 

enum CATTopSplitType
{ CatSplitBothSides, CatSplitPositiveSideOnly, CatSplitNegativeSideOnly};

#endif



