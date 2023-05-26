/* -*-C++-*- */

#ifndef CATTopRibHermetizationUtilities_H
#define CATTopRibHermetizationUtilities_H

// COPYRIGHT DASSAULT SYSTEMES 2003

//===================================================================
//===================================================================
//
// Utilitaires de CATTopRibHermetization
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// Mars. 2003    Creation                         F.Deboulle
//===================================================================

//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATTopRibDef.h" 
#include "CATMathDef.h"

class CATEdge;
class CATVertex;
class CATPointOnCurve;
class CATPointOnEdgeCurve;
class CATCell;
class CATFace;
class CATCurve;
class CATEdgeCurve;
class CATMacroPoint;

class CATTopRib;
class CATTopRibNuplet;
class CATCrvParam;

struct ExportedByRIBLight CATHermetizationInfoForMergeVertices
{
  CATHermetizationInfoForMergeVertices();
  ~CATHermetizationInfoForMergeVertices();

  int _LeftSupportIndex;
  int _RightSupportIndex;
  CATVertex * _Vertex;
  double _GapInVertex;
  CATBoolean _IsOnLinkCell;
  CATBoolean _MergeWithLeftNuplet;
  CATBoolean _MergeWithRightNuplet;
};

/*
ExportedByRIBLight CATBoolean UpdateAfterHermetization 
                                    (CATTopRib * iLeftRib,
                                     CATTopRibNuplet * iLeftNuplet,                                     
                                     CATTopRibSign iLeftDirection,
                                     int iLeftSupportIndex,
                                     CATCrvParam iLeftParam,
                                     CATTopRib * iRightRib,
                                     CATTopRibNuplet * iRightNuplet,
                                     CATTopRibSign iRightDirection,
                                     int iRightSupportIndex,
                                     CATCrvParam iRightParam);
//-------------------------------------------------------------------------
// Hermetize the tracks of 2 Nuplets on a common support
// (Calculate the medium point of the confused area between the two Tracks)
//-------------------------------------------------------------------------
ExportedByRIBLight CATBoolean ComputeHermetizationForTracksOnCommonSupport
                                (CATCell* iLeftTrackCell, CATVertex* iLeftVertex, 
                                 CATCell* iRightTrackCell, CATVertex* iRightVertex,
                                 CATCell* CommonCell,
                                 CATCrvParam & oLeftParam, CATCrvParam &oRightParam);
*/

//------------------------------------------------------------------
// Hermetize the tracks of two Nuplets on a common Support Cell
// if the Support Cell corresponding to iLeftSupportIndex and 
// iRightSupportIndex are not the same, 
// a CATBoolean FALSE is returned
// iMode can take the following values :
//    iMode = 0 Update the Poecs according to the Hermetization Data, (default value) corresponds to "Multi-Ribbon" need
//    iMode = 1 Store the Hermetization Data in the Rib, corresponds to "Hermetization" need
//------------------------------------------------------------------
ExportedByRIBLight CATBoolean ComputeHermetizationOnCommonSupport(CATTopRib * iLeftRib, int iLeftNupletIndex, int iLeftSupportIndex, CATTopRibSign iLeftDirection,
                                                                  CATTopRib * iRightRib, int iRightNupletIndex, int iRightSupportIndex, CATTopRibSign iRightDirection, 
                                                                  int iMode = 0);

//------------------------------------------------------------------
// Hermetize the tracks of two Nuplets on a Support with a link
// if the Support Cell corresponding to iLeftSupportIndex and 
// iRightSupportIndex are not the same, 
// a CATBoolean FALSE is returned
// iMode can take the following values :
//    iMode = 0 Update the Poecs according to the Hermetization Data, (default value) corresponds to "Multi-Ribbon" need
//    iMode = 1 Store the Hermetization Data in the Rib, corresponds to "Hermetization" need
//------------------------------------------------------------------
ExportedByRIBLight CATBoolean ComputeHermetizationOnLink
                                (CATTopRib * iLeftRib, int iLeftNupletIndex, int iLeftSupportIndex, CATTopRibSign iLeftDirection, 
                                 CATTopRib * iRightRib, int iRightNupletIndex, int iRightSupportIndex, CATTopRibSign iRightDirection, 
                                 int iMode = 0);
//-----------------------
// Update Poec with Param
//-----------------------
ExportedByRIBLight CATBoolean UpdatePoecWithParam (CATEdgeCurve * iEdgeCurve, CATCrvParam & iParam, 
                                                     CATPointOnEdgeCurve * ioPoec, CATMacroPoint* iMacroPoint=NULL);

#endif
