#ifndef TopologicalUtilities3_H
#define TopologicalUtilities3_H

// COPYRIGHT DASSAULT SYSTEMES 2004

//=============================================================================
//=============================================================================
//
// TopologicalUtilities3.cpp 
//
// Suite de TopologicalUtilities.cpp 
//
//=============================================================================

//=============================================================================
// Dec  2004  Creation                               R. Rorato
//=============================================================================
//=============================================================================
#include "RibbonLight.h"
#include "CATFilletDefine.h"
#include "CATTopDefine.h"
#include "CATMathDef.h"
#include "CATIsoParameter.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "TopoUtilitiesForLight.h"

class CATVertex;
class CATCell;
class CATBody;
class CATLiveBody;
class CATShell;
class CATDomain;
class CATSurface;
class CATSurLimits;
class CATSurParam;
class CATVertexIterator;
class CATTopData;
class CATGeoFactory;
class CATMathPlane;
class CATMathLine;
class CATCurve;
class CATCrvParam;
class CATCrvLimits;
class CATSoftwareConfiguration;
class CATTopologicalOperator;
class CATRibbonsReorderTracker;


//===========================================================================================================
// Move Poec (or Pos) on Geometry supporting iSupportCell 
// from MacroPoint of iVertexToDelete to MacroPoint of iVertexToKeep
//===========================================================================================================
ExportedByRibbonLight void TransfertPoecAndPosBeforeMergingVertices(CATVertex* iVertexToKeep, CATVertex* iVertexToDelete, CATCell* iSupportCell);


ExportedByRibbonLight void GetFreeBrdrEdges (CATDomain * iDomain, ListPOfCATEdge &FreeBrdrEdges);

//===========================================================================================================
// Check if an edge is inside a face
//===========================================================================================================
ExportedByRibbonLight CATBoolean IsEdgeInsideFace(CATSoftwareConfiguration *iConfig,
                                                  CATTopologicalOperator   &iTopOp,
                                                  CATEdge                  *iCutEdge,
                                                  CATFace                  *iSplittingFace);

CATBoolean ComputeDWDS(const CATSurface* iSurface, CATSurLimits& iUVBox, double& oDWDSMin, double& oDWDSMax);

ExportedByRibbonLight CATBoolean IsEdgeInsideFacePreviousVersion(CATSoftwareConfiguration *iConfig,
                                                                 CATTopologicalOperator   &iTopOp,
                                                                 CATEdge                  *iCutEdge,
                                                                 CATFace                  *iSplittingFace);
//===========================================================================================================
// Regarde si une edge est isopare via ses vertex
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight void CheckVtxIsopar(CATSoftwareConfiguration* iConfig,
                                          CATEdge*                  iEdge,
                                          CATFace*                  iFace,
                                          CATBoolean&               oIsoU,
                                          CATBoolean&               oIsoV);

//===========================================================================================================
// Cherche a "matcher" deux edges par intersection
// - On prend un point Pt sur iEdge au parametre defini par iRatio, iStParOnEdge et iEnParOnEdge
// - On cree un plan qui passe par le Pt et dont la normale est la tgte a la courbe en Pt
// - On lance l'X entre ce plan et la courbe iCurveToX, dans les limites iLimitsOfX
// - On renvoie le nb de sol + la dist entre le pt d'X le plus proche de Pt et Pt
//===========================================================================================================
/** @nodoc @nocgmitf */
ExportedByRibbonLight CATBoolean EdgeMatchingWithX (CATGeoFactory*            iGeoFac,
                                                    CATSoftwareConfiguration* iConfig,
                                                    CATCurve*                 iCurve,
                                                    CATCrvParam&              iStParOnCurve,
                                                    CATCrvParam&              iEnParOnCurve,
                                                    double                    iRatioOnCurve,
                                                    CATCurve*                 iCurveToX,
                                                    CATCrvLimits&             iLimitsOfX, 
                                                    CATLONG32&                oNbSol,
                                                    double&                   oDistMin);

//===========================================================================================================
ExportedByRibbonLight CATBoolean IsAFilletFace(CATSoftwareConfiguration* iConfig,
                                               CATRibbonsReorderTracker* iRibbonsReorderTracker,
                                               CATLiveBody* iLiveBody, // if !NULL then DRep information will help
                                               CATFace* iFaceToTest, 
                                               CATVertex* iLocationVertex, 
                                               CATCell* iCellSupportingLocationVertex, // FilletTrackEdge
                                               CATSurParam &oLocationOnFace, 
                                               CATPositiveLength &oRadius,
                                               CATFilletRadiusType& oRadiusType,
                                               CATFilletSectionType& oSectionType, 
                                               CATIsoParameter &oCircularIsopar,
                                               CATBoolean &oConstantRadius);
//===========================================================================================================
  // NB: oSupportFace[x] is null in case of ambiguity or face is no longer adjacent
ExportedByRibbonLight CATBoolean IsAFilletFace(CATSoftwareConfiguration *iConfig, CATFace* iFaceToTest, CATBody* iBody, CATFace* oSupportFace[2]);
//===========================================================================================================

#endif

