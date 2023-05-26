/*-*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2003
//=============================================================================
//
//=============================================================================
// Usage notes:
// sample of use :
// to provide
//
//
// Etat des lieux
// --------------
// XScale: - inutilisable, et inutilisée à vraie echelle jusqu'au   160418
//         - utilisable toutes echelles desormais                NLD160418
//
// A noter:                                                     (NLD160418)
// - une duplication 2003 CATCbtCuttingOfScan            qui peut etre remplacée par celle-ci moyennant de menues adaptations
//                                                       (voir commentaires dans son implementation)
//                                                       et qui semble plutot etre le source originel
// - une variante    2013 CATTrimFaceByMeshContours      inactive (code en commentaires)
// - une variante    2013 CATPolyComputeCircleOnSetOfPts
// - une variante    2010 CATP2DAllUtilities (methode P2D_AnalysisOfScan)
//
// - un appel interne FreeForm, par CATFrFSmoothingOperCx2 (avec forcage echelle 1, à la date du 160418)
// - un appel externe FreeForm, par CATBtoSmoothingOperCx2 (avec forcage echelle 1, à la date du 160418)
//
//============================================================================= 
// 16/04/2018 : NLD : XScale; ComputeDefaultParameters() reçoit iTolObject
//                    Smart indent
// 19 Nov  ?? : ANR : Creation (en fait visible Adele le 310510)
//=============================================================================

#ifndef CATFrFCuttingAnalysis_H 
#define CATFrFCuttingAnalysis_H 
 
#include "CATFrFSmoothing.h"
#include "CATFrFSmoothingDef.h"

#include "CATListOfInt.h"
#include "CATBoolean.h"

#include "CATGetTolerance.h"
#include "CATTolerance.h"

class CATCldScan ;
class CATMathPoint ;
class CATMathFunctionX ;
class CATGeoFactory ;
class CATSoftwareConfiguration;

class ExportedByCATFrFSmoothing CATFrFCuttingAnalysis
{
public:

   static int ComputeDefaultParameters (
                                        const CATTolerance            *  iTolObject    ,
                                              int                        NumberOfPts   ,
                                              CATMathPoint            *  iPoints       ,
                                              double                  *  ioParam       ,
                                              CATFrFSmoothingParamType   iParamType    = CATFrFSmoothingParamChordal);
 
   static void SmoothDataFunction      (      double                     ideviation    ,
                                              int                        iNbreOfPts    ,
                                              CATMathPoint            *  ioPts         ,
                                              int                      & oNbreIter     ) ;
 
   static void SmoothCurvatureFunction (      int                        iNbreOfPts    ,
                                              double                  *  iparameters   ,
                                              int                        iNbreIter     ,
                                              double                  *  ioCvt         ) ;

   // fonction pour calculer les Max, Min, pts d'inflexion d'une polyline ...
   // si iParam == 0 , un calcul par default est fait :

   // XScale: ATTENTION methode non convergée au 040418
   //                   tous les appelants ramenant leurs données d'entrée à une independance de l'echelle
   //                   observation et commentaire NLD040418
   //                   mieux au 160418 après corrections
   static int AnalysisOfScan           (      double                      iResolution  ,
                                        const CATTolerance             *  iTolObject   ,
                                              CATSoftwareConfiguration *  iConfig      ,
                                              CATBoolean                  iSimplify    ,
                                              double                      ideviation   ,
                                              CATCldScan               *  iScan        ,
                                              int                       & ioNbrePts    ,
                                              double                   *  ioParam      ,
                                              CATFrFSmoothingParamType    iParamType   ,
                                              double                    & oCurvatureVariation,
                                              CATMathFunctionX         *& oFunc        ,
                                              double                   *& oparameters  ,
                                              int                       & oNbreSol     ,
                                              int                      *& ioIndex      ,
                                              int                       & oNbreZero    ,
                                              int                      *& ioIndex_flex ,
                                              int                       & oNbreTotal   ,
                                              int                      *& ioIndexTotal ,
                                              double                   *& oEstimateCvt ) ;
 
   static int LocalizeCuttingPoint     (      int                         iNbrePts     ,
                                              double                   *  ioParam      ,
                                              CATMathFunctionX         *  iFunc        ,
                                              int                      *  iZone        ,
                                              double                      iratio       ,
                                              int                       & oCuttingIndex,
                                              double                    & oCuttingParam) ;

};

#endif

