//===================================================================
//   
// COPYRIGHT   : DASSAULT SYSTEMES 2000
//
// DESCRIPTION :Utilities for Curves improvement
//
//===================================================================
// 27/09/17 NLD : Argument supplementaire iForceLocalOpti3Level a ApproxToNurbs()
//                Mise au propre complete
// 12/03/13 NLD : XScale: argument iIsoScale a PromptInfosOnCCV() pour traces independantes de l'echelle
// 05/01/10 RNO : Corrections OLKS dans les Approx, restructuration DelMCCCV, suppression DelCCV,
//                creation de methode de destrcution avec systeme de protection.
// 03/12/09 RNO : Tout nouveau tout beau DelOneCurveOfCCV qui bute bien la courbe dans la factory (OLK aware)
// 09/10/09 RNO : Amelioration DelMCCCV avec Hashtable et sans GetObjectFromTag + Export pour utilisation dans TopCleanCrvC6
// 26/09/05 RNO : Suppression Methode BasicCurveFitting (inutilisee)
// 18/06/04 RNO : Refonte DelMCCCV
// 22/03/04 RNO : Ajout RemoveAllAttributesOnCurvesInCCV
// 23/01/03 RNO : Modif PromptInfosOnCCV
// 15/12/03 RNO : long->CATLONG32
// 12/11/03 RNO : Approx en mode Hybride !
// 03/09/03 RNO : Versionning CompositeCrv
// 18/07/03 RNO : Ajout CreateCrvLengths pour homogeneisation CCVCleaner/Reduce
// 28/05/03 RNO : Mirroir OK
// 21/05/03 RNO ; Versionning CATMassProperties1D (1 appels)
// 13/03/03 HLN : Ajout SnapNode, deplace de CATCCVCleanerCx6 car utile.
// 11/02/03 RNO : Ajout PromptInfosOnCCV pour traces de debug
// 05/09/02 RNO : Ajout CreateSymetricCurveAtVertex
// 08/07/02 HLN Ajout ExtractPCCVFromMCCCV, BuildMergedCurve et DELMCCCV dasn le cadre de
//              l'extension du mode hybride a la red. de donnees et a l'opt. glo.
// 04/06/02 HLN Ajout ExtractPCFromMC : extraction PCurve d'une MergeCurve dans le cadre
//              du mode hybride 2D+3D
// 14/03/02 NLD ajout IsCurveDegenerated()
// December, 2000 : JCV : ajout DelOneCurveOfCCV
// November, 2000 : JCV : Creation 
//===================================================================
#ifndef CATCurvesImprovementUtilities_H
#define CATCurvesImprovementUtilities_H
#include "FrFAdvancedOpeCrv.h"
//Pour Perfo
#ifndef _WINDOWS_SOURCE
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/times.h>
#else
#include <fstream.h>
#include <stdio.h>
#include <time.h>
#endif

#include "CATCurvesImprovementDefine.h"
#include "CATListOfCATCurves.h"
#include "CATListOfCATCrvLimits.h"
#include "CATListOfInt.h"
#include "CATLISTP_CATMathPoint.h"

class CATFrFCompositeCurve;
class CATCrvParam;
class CATSurParam;
class CATCrvLimits;
class CATGeoFactory;
class CATCurve;
class CATNurbsCurve;
class CATSoftwareConfiguration;
class CATCrvLengths;
class CATMathVector;

class CATCrvEvalCommand;
class CATCrvEvalLocal;
class CATMathNurbsMultiForm;

#include "CATMathDef.h" // pour class CATBoolean;
#include "CATMathLimits.h"
#include "CATPCurve.h"


//RNO 03/12/2009 Pour faire plus C++ je met tous ces utilitaires dans une classe
// avec des methode static de class cela permet notamment aux appelants de specifier le nom de domaine
// ie "CATCurvesImprovementUtilities::"
class ExportedByFrFAdvancedOpeCrv CATCurvesImprovementUtilities
{
public :
  //Suppression de la premiere oude la derniere courbe d'une CCV
  //Avec controle de l'existence dans 2 autres CCV
  static CATFrFCompositeCurve * DelOneCurveOfCCV (
                                                     CATGeoFactory            *  FactoryForRemove  ,
                                                     CATSoftwareConfiguration *  iSoftConfig       ,
                                                     CATFrFCompositeCurve     *& iCCV              ,
                                                     CATLONG32                   iRankToDel        ,
                                                     CATFrFCompositeCurve     *  iInputCCVNotToDel = 0
                                                  );

  //DelMCCCV : Destruction de la CCV et des courbes inclues avec verification de la presence des courbes dans les autres CCV
  //tient compte des possiblilites des courbes cachees dans une MergedCurve 
  static void    DelMCCCV                     (      CATGeoFactory            *  iFactory              ,
                                                     CATFrFCompositeCurve     *& iCCVToDelete          ,
                                                     CATFrFCompositeCurve     *  iInputCCVDoNotDel     = 0,
                                                     CATFrFCompositeCurve     *  iOutputCCVDoNotDel    = 0,
                                                     CATFrFCompositeCurve     *  iOptionnalCCVDoNotDel = 0);

  static void    Del2MCCCV                    (      CATGeoFactory            *  iFactory              ,
                                                     CATFrFCompositeCurve     *& iCCVToDelete1         ,
                                                     CATFrFCompositeCurve     *& iCCVToDelete2         ,
                                                     CATFrFCompositeCurve     *  iInputCCVDoNotDel     = 0,
                                                     CATFrFCompositeCurve     *  iOutputCCVDoNotDel    = 0,
                                                     CATFrFCompositeCurve     *  iOptionnalCCVDoNotDel = 0);


  //Meme chose mais pour juste une courbe (plus simple donc)
  static void    MiniDelMergeCurve            (      CATGeoFactory            *  iFactory              ,
                                                     CATCurve                 *& iCurveToDel           ,
                                               const CATCurve                 *  iInputCurveDoNotDel   ,
                                               const CATCurve                 *  iOutputCurveDoNotDel  ,
                                               const CATCurve                 *  iOptionnalCurveDoNotDel=0);

  //Same as DelMCCCV (means MergedCurve aware)
  static void    DelMCListCurV                (      CATGeoFactory            *  iFactory              ,
                                                     CATLISTP(CATCurve)        & iCurvesToDelete       ,
                                               const CATLISTP(CATCurve)        & iCurvesNotToDel       );

  // SnapNode :
  // If the length of the part of the curve between Eval at ioGlobalParam and Eval at
  // the closest knot is below C0Resolution (0.001), the ioGlobalParam parameter value is
  // changed either to the knot value, or to a value in order to avoid later creation of "illegal small segments"
  //
  // Inputs : A Curve and a GlobalParamater on this Curve
  //          iSnapBorderMode :
  //iSnapBorderMode == 0 No Snapping if ioGlobalParam is near a knot border of the curve
  //iSnapBorderMode == 1 Snapping Near an extremity is allowed
  //iSnapBorderMode == 2 Repulsive Mode : 
  // Outputs : ioGlobalParam the snapped parameter (if needed)
  //return 0 if NoSnap has been done
  //return > 0 if Snapped
  //return <0 if a problem occurs
  static int     SnapNode                     (      CATGeoFactory            *  iFactory              ,
                                                     CATLONG32                   iCGMLevel             ,
                                               const CATCurve                 *  iCurve                ,
                                                     double                    & ioGlobalParam         ,
                                                     int                         iSnapBorderMode       );




private:
  //Realize the destrcution on flattened listof curve in 2 passes MergedCurve than Curve
  static void    SubToolForDelMerge           (      CATGeoFactory            *  iFactory              ,
                                                     CATLISTP(CATCurve)        & iCurvesToDelete       ,
                                               const CATLISTP(CATCurve)        & iCurvesNotToDel       );

};



// Is a curve in a composite curve degenerated? (length smaller than iNullCurveLength)
// (index between 0 and number of curves minus 1)
CATBoolean       IsCurveDegenerated
                                              (      CATFrFCompositeCurve     *  iCCV                  ,
                                                     CATLONG32                   index                 ,
                                                     double                      iNullCurveLength      ,
                                                     double                    & oLengthIfSmall        );

double           LengthCurve                  (      CATFrFCompositeCurve     *  iCCV                  ,
                                                     CATLONG32                   index                 );

CATCrvParam    * ParamCurve                   (      CATFrFCompositeCurve     *  iCCV                  ,
                                                     CATLONG32                   index                 ,
                                                     CATLONG32                   iSide                 );

// after the treatment of each CCV Part, it's necessary to concatenate
// each CCV result.
// ConcatCCV return this concatenate CCV, and delete all CCV part.
// Only the table must be delete by the caller
CATFrFCompositeCurve * ConcatCCV              (      CATLONG32                    iNumberOfCCVs  ,
                                                     CATFrFCompositeCurve     **  iCCVs          ,
                                                     CATSoftwareConfiguration  *  iSoftConfig    );


/*
void DelCCV (CATGeoFactory        *  iFactory,
             CATFrFCompositeCurve *& iCCVToDelete,
             CATFrFCompositeCurve *  iInputCCVDoNotDel = 0,
             CATFrFCompositeCurve *  iOutputCCVDoNotDel= 0);
*/



int                   ExtractCurves                 (CATFrFCompositeCurve     *  iCCV           ,
                                                     CATLISTP(CATCurve)        & oCurvesToDelete);
//Create a CCV From a ListOfCurves,limitsOrientations ...
// Relimited from iStartRank To iEndRank 1<=StartRank<=EndRank<=ListOfCurves.Size()
//Default From The Whole List
// Default Support Orientations Is 1

CATFrFCompositeCurve * MakeCCVFromLists(             CATSoftwareConfiguration *  iSoftConfig    ,
                                                     CATLISTP(CATCurve)        & iListOfCurves  ,
                                                     CATLISTP(CATCrvLimits)    & iListOfLimits  ,
                                                     CATListOfInt              & iListOfOrientations,
                                                     CATLONG32                   iStartRank     = -1,
                                                     CATLONG32                   iEndRank       = -1);

//Create a CCV From a ListOfCurves,limitsOrientations ...
// Relimited from iStartRank To iEndRank 0<=StartRank<=EndRank<iCCV->GetNumberOfCurves
//Default From The Whole CCV

void             AppendListsFromCCV           (      CATFrFCompositeCurve    *  iCCV            ,
                                                     CATLISTP(CATCurve)       & oListOfCurves   ,
                                                     CATLISTP(CATCrvLimits)   & oListOfLimits   ,
                                                     CATListOfInt             & oListOfOrientations,
                                                     CATLONG32                  iStartIndex     = -1,
                                                     CATLONG32                  iEndIndex       = -1);

// Extraction de la PCurve a partir d'une MergeCurve
int              ExtractPCFromMC              (const CATCurve                *& iMC             ,
                                                     CATCurve                *& oPC             );

// Aplatir la structure
int              RecursiveExtractFromEdgeCurve(const CATCurve                *  iMC             ,
                                                     int                        DeepNess        ,
                                                     CATLISTP(CATCurve)       & oAllCurves      );


int              ExtractPCCVFromMCCCV         (const CATFrFCompositeCurve    *& iMCCCV          ,
                                                     CATFrFCompositeCurve    *& oPCCV           ,
                                                     CATSoftwareConfiguration*  iSoftConfig     );

/*
int              ExtractRefCCVFromMCCCV       (const CATFrFCompositeCurve     *& iMCCCV         ,
                                                     CATFrFCompositeCurve     *& oCCV           ,
                                                     CATSoftwareConfiguration * iSoftConfig     );

int              RemoveAllMergedCurveAndCCV   (      CATFrFCompositeCurve     *& iMCCVToDelete  ,
                                                     CATGeoFactory            *  iFactory      );
*/
int              BuildMergedCurve             (      CATSoftwareConfiguration *  iSoftConfig    ,
                                                     CATGeoFactory            *  Factory        ,
                                                     CATCurve                 *  iNewCurveHyb3D ,
                                                     CATCrvLimits             *  iNewLimitsHyb3D,
                                                     CATCurve                 *  iNewCurve      ,
                                                     CATCrvLimits             *  iNewLimits     ,
                                                     double                      iStart         ,
                                                     double                      iEnd           ,
                                                     CATPositiveLength           iGap           ,
                                                     double                      iTolOnGap      ,
                                                     CATCurve                 *& oMC            ,
                                                     double                      iMaxParamGapForLinearMap = CATMathInfinite);

/*
CATCurve       * CreateSymetricCurveAtVertex  (const CATFrFCompositeCurve      *  iCCCV         ,
                                               const CATLONG32                    iRank         ,
                                               const CATBoolean                   IsStart       ,
                                                     CATGeoFactory             *  iFactory      ,
                                               const CATBoolean                   iComputein2D  );
*/



// CreateNewCATCrvLengths : 
// Check in the atributes if exist then get else Create A new CATCrvLength
CATCrvLengths  * CreateCrvLengths             (      CATSoftwareConfiguration  *  iSoftConfig  ,
                                                     CATCurve                  *  iCurve       ,
                                               const CATCrvLimits               & iLimits      );


// Look if the Curve is C2 and manage also the HybridMode
int              ApproxToNurbs                (      CATSoftwareConfiguration *  iSoftConfig  ,
                                                     CATGeoFactory            *  iGeoFact     ,
                                               const CATCurve                 *& iCurve       ,
                                               const CATCrvLimits              & iLimits      ,
                                                     CATLONG32                 & ioOrientation,
                                                     double                      i3DTolerance ,
                                                     CATLONG32                   iMaxDegree   ,
                                                     int                         i2DRep       ,         // 0:3D, 1:2D, 2: Hybride 
                                                     int                         iForceLocalOpti3Level, // NLD270917
                                                     CATCurve                 *& oApproxCurve ,
                                                     CATCrvLimits              & oLimits      ,
                                                     double                    & oErreurApprox,
                                                     int                         iManageC2    = 0);

CATBoolean       IsLimitEqualMaxLimitsOfCurve (      CATSoftwareConfiguration *  SoftConfig,
                                                     CATGeoFactory            *  Factory   ,
                                               const CATCurve                 *  iCurve    ,
                                               const CATCrvLimits              & iLimits   );

CATBoolean       IsDegreeEqualCurveDegree     (      CATSoftwareConfiguration *  SoftConfig,
                                                     CATGeoFactory            *  Factory   ,
                                               const CATCurve                 *  iCurve    ,
                                                     int                         iDegree   );

CATBoolean       IsCurveWellParametrized      (      CATSoftwareConfiguration *  SoftConfig,
                                                     CATGeoFactory            *  Factory   ,
                                               const CATCurve                 *  iCurve    ,
                                               const CATCrvLimits              & iLimits   );

CATBoolean       IsCurveSmoothAtNodes         (      CATSoftwareConfiguration *  SoftConfig,
                                                     CATGeoFactory            *  Factory   ,
                                               const CATCurve                 *  iCurve    ,
                                               const CATCrvLimits              & iLimits   );

//int            InvertHybridCurve            (      CATCurve                 *& CurveApprochee,
//                                                   CATGeoFactory            * iGeoFact);

CATCurve       * InvertHybridCurve            (      CATSoftwareConfiguration *  iSoftConfig,
                                                     CATGeoFactory            *  iGeoFact   ,
                                                     CATCurve                 *  iCurveToInvert,
                                               const CATCrvLimits              & iLimits    ,
                                                     CATCrvLimits              & oLimits    );

CATCurve       * InvertCurve                  (      CATSoftwareConfiguration *  SoftConfig   ,
                                                     CATGeoFactory            *  iGeoFact     ,
                                                     CATCurve                 *  iCurveToInvert,
                                                     CATBoolean                  i2DRep       );

int              BasicCurveApproxToNurbs      (      CATSoftwareConfiguration *  iSoftConfig  ,
                                                     CATGeoFactory            *  iGeoFact     ,
                                               const CATCurve                 *& iCurve       ,
                                               const CATCrvLimits              & iLimits      ,
                                                     double                      iTolSecuriteApprox,
                                                     CATLONG32                   iMaxDegree   ,
                                                     int                         i2DRep       , //0:3D, 1:2D,
                                                     CATCurve                 *& oApproxCurve ,
                                                     CATCrvLimits              & oLimits      ,
                                                     double                    & oErreurApprox);


int              BasicHybridCurveApproxToNurbs(      CATSoftwareConfiguration *  iSoftConfig  ,
                                                     CATGeoFactory            *  iGeoFact     ,
                                               const CATCurve                 *& iCurve       ,
                                               const CATCrvLimits              & iLimits      ,
                                                     double                      iTolSecuriteApprox,
                                                     CATLONG32                   iMaxDegree   ,
                                                     CATCurve                 *& oApproxCurve ,
                                                     CATCrvLimits              & oLimits      ,
                                                     double                    & oErreurApprox);



int           RemoveAllAttributesOnCurvesInCCV(const CATFrFCompositeCurve     *  iCCV);

void             RemoveKnotAtConfusion        (      CATSoftwareConfiguration *  SoftConfig   ,
                                                     CATGeoFactory            *  iFactory     ,
                                               const CATCurve                 *  iCurve       ,
                                                     CATCurve                 *& oNewCurve    ,
                                                     double                      i3DTol       );

///Utility To Make a Curve from a Multiform
CATCurve    * NewCurveFromMF                  (const CATMathNurbsMultiForm     & MF           ,
                                                     CATSoftwareConfiguration *  SoftConfig   ,
                                                     CATGeoFactory            *  iGeoFact     ,
                                                     CATSurface               *  iSurface     = 0);



// Redefinition d'operations vectorielles standard orientees stabilite et precision numerique

int           GetCurvatureGContStable         (const CATMathVector             & iFstDer      ,
                                               const CATMathVector             & iScnDer      ,
                                                     CATMathVector             & oCurvature   );

double        AddByKahan                      (      double                      iX []        ,
                                                     int                         Nb           );

double        StableNorm                      (const CATMathVector             & Vec          );

double        StableSquareNorm                (const CATMathVector             & Vec          );

double        StableCrossProduct              (const CATMathVector             & iVec1        ,
                                               const CATMathVector             & iVec2        );

//Evaluation "Stable" avec preference a gauche ou droite
int           StableEval                      (      CATSoftwareConfiguration *  iSoftConfig  ,
                                                     CATCurve                 *  iCurve       ,
                                               const CATCrvParam               & iParam       ,
                                               const CATCrvEvalCommand         & iCommand     ,
                                                     CATCrvEvalLocal           & ioResult     ,
                                               const CATCrvImprvEvalPosition     iPreferedPosition);

int           EvalCompose                     (      CATSoftwareConfiguration *  iSoftConfig   ,
                                               const CATPCurve                *  iCurve        ,
                                               const CATSurface               *  iSurface      ,
                                               const CATCrvParam               & iParam        ,
                                               const CATSurParam               & iSurParam     ,
                                               const CATCrvEvalCommand         & iCommand      ,
                                                     CATCrvEvalLocal           & ioResult      );

int           GetC2DiscontinuityFromSupport   (      CATSoftwareConfiguration *  SoftConfig    ,
                                                     CATGeoFactory            *  iFactory      ,
                                                     CATPCurve                *  iCurve        ,
                                               const CATCrvLimits              & iLimits       ,
                                                     CATListOfDouble           & oParams       );
                                  


// OnlyStartOrEnd ==  1 Only Compare the EndLimit
// OnlyStartOrEnd == -1 Only Compare the StartLimit
int CheckAndModifyLimitsToHaveSameSupportSpans(      CATSoftwareConfiguration *  SoftConfig    ,
                                                     CATGeoFactory            *  iFactory      ,
                                               const CATCurve                 *  iInitialCurve ,
                                               const CATCrvLimits              & iInitialLimits,
                                               const CATCurve                 *  iNewCurve     ,
                                                     CATCrvLimits              & ioNewLimits   ,
                                                     int                         Orientation   ,
                                                     int                         OnlyStartOrEnd = 0);


                                               //FOR DEBUGGING PURPOSE ONLY NO COVERAGE !!!!!

//Debug Tool Warning NoCoverage !

void          PromptInfosOnCCV                (      CATGeoFactory            *  iFactory      ,
                                                     CATFrFCompositeCurve     *  iCCCV         ,
                                                     CATSoftwareConfiguration *  iSoftConfig   ,
                                                     double                      iSizeofSmall  ,
                                                     int                         iEachCurve    ,
                                                     int                         iIsoScale     = 0); // 1 for traces not depending on factory Scale

clock_t       CleanCrv_GetClock               ();

double        CleanCrv_StopTimer              (const clock_t                   & clockdebut    );

void          DumpParam                       (const CATCrvParam               & iParam        );

void          DumpSurParam                    (const CATSurParam               & iParam        );

void          DumpPCurve                      (      CATCurve                 *  iCurve        ,
                                               const CATCrvParam               & iParam        );

void          DumpExtremityConstraints       (       CATCurve                 *  iCurve        ,
                                              const CATCrvLimits               & iLimits       );

#endif
