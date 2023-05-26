/**
 * @fullreview JSX jsx1 01:01:05
 */
// --------------------------------------------------------
 // COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
//
// CATTopologicalBlendCurveInt:
//    Interface interediaire, NON public, pour plus de souplesse 
//=============================================================================
//
//=============================================================================
// 2005  Creation                                   JSX
//=============================================================================
#ifndef CATTopologicalBlendCurveInt_H
#define CATTopologicalBlendCurveInt_H

#include "CATTopologicalBlendCurve.h"

//-----------------------------------------------------------------------------
class CATTopologicalBlendCurveInt : public CATTopologicalBlendCurve
{
 public:
  CATTopologicalBlendCurveInt (CATGeoFactory *iFactory, CATCGMJournalList *iReport);

  CATTopologicalBlendCurveInt (CATGeoFactory *iFactory, CATTopData        *iData);
  
//  virtual ~CATTopologicalBlendCurveInt();

  //  Methods
//=========
  // Only For Test (coverage of a blend curve option not proposed to CAA users)
  virtual void SetSurfacicBehavior() =0;
};

#endif






