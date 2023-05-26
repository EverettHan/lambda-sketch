//
/*-*-C++-*-*/
//
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
//
// CATParallelUtilities :
//
// Utilities class for Parallel Connect
//
//=============================================================================
// Usage notes:
// Static methods only to be used as utilities for Parallel Connect
//=============================================================================
// 08/08/22 S9L Creation
// 08/03/23 S9L Interface for smoothening consecutive connect pieces 
//=============================================================================
//

#ifndef CATParallelUtilities_h
#define CATParallelUtilities_h

#include "Connect.h"

#include "CATMathSetOfLongs.h"
#include "CATMathSetOfPointsND.h"

class CATConnectCrvSurCx2;

//===================================================================
// CATParallelUtilities
//===================================================================
class ExportedByConnect CATParallelUtilities
{
public:

  //----------------------------------------------------------------------------------------
  // Method for cleaning of tangentially overlapping twists within 1 micron
  //----------------------------------------------------------------------------------------
  static HRESULT CleanOverlappedTwists(CATMathSetOfPointsND  & ioParameters,
                                       CATMathSetOfPointsND  & ioPoints,
                                       CATMathSetOfPointsND  & ioTangents,
                                       CATMathSetOfPointsND  & ioSecondDerivatives,
                                       CATMathSetOfLongs     & iC1Discontinuities,
                                       CATLONG32               iOverlapIndex,
                                       const CATTolerance    & iTolObject);

  //----------------------------------------------------------------------------------------
  // Check for the overlap of twisted set with the neighboring non-twisted sets
  //----------------------------------------------------------------------------------------
  static void DetectOverlappedTwists(CATMathSetOfPointsND  ** ipSetOfPoints,
                                     CATMathSetOfLongs     &  iTwistedResults,
                                     CATMathSetOfLongs     &  ioOverlappedTwists,
                                     CATLONG32                iNumberOfResults,
                                     const CATTolerance    &  iTolObject);

  //----------------------------------------------------------------------------------------
  // Force G1 continuouity on consecutive connect pieces, if twisted at the junction
  // The connect pieces should have the same support surface and terminal twists within 1 micron
  // The method modifies the p-curves in both the connects near the terminal twist zone
  // That would change the image of the nuplet junction on the common support
  //----------------------------------------------------------------------------------------
  static HRESULT SmoothenConnectPieces(CATConnectCrvSurCx2 *& ipFirstConnectCrvSur,
                                       CATConnectCrvSurCx2 *& ipSecondConnectCrvSur,
                                       const CATTolerance   & iTolObject);
};

#endif

/* -*-C++-*- */
