//===============================================================
// Copyright Dassault Systemes Provence 2003-2006, all rights reserved
//===============================================================
//===================================================================
//
// CATG2IntoC2CommonEngine : Classe permettant de partager 
// et stocker le calcul de plusieurs instances de CATFunctionG2IntoC2
// C'est une fonction de R->R3
//
//===================================================================
//  16/11/2017 : NLD : Stream/UnStream
//                     Ajout Stream()/UnStream()/IsStreamable()
//                     Ajout _LoadedFromReplay
//  10/11/2017 : NLD : Ajout EvalFirstDeriv_i()  pour calcul commun des derivees premieres
//                     Ajout EvalSecondDeriv_i() pour calcul commun des derivees secondes
//  08/11/2017 : NLD : Renommages: (sortie des notations polonaises (non inverses!))
//                     EvalNewFirstDerivX_T      remplace EvalNewFrstDrvX_T
//                     EvalNewFirstDerivT_S      remplace EvalNewFrstDrvT_S
//                     EvalNewSecondDerivT_S     remplace EvalNewScnDrvT_S
//                     EvalSecondDeriv_*         remplace EvalScndDeriv_* (X, Y, Z)
//                     EvalNewUpToSecondDerivX_T remplace EvalNewUpToScndDrvX_T
//                     EvalSecondDeriv3D         remplace EvalScndDeriv3D
//  07/11/2017 : NLD : Smart indent
//                     Ajout Init()
//                     Ajout IsStreamable(), Stream(), UnStream()
//  04/11/2010 : RBD : Doc improvement
//  07/01/2010 : RBD : _NbCurvesCCV en donnees membres.
//  22/12/2009 : RBD : Ajout sorties en CATMathPoint, CATMathVector, ...
//  28/05/2003 : RNO : Mirroir OK
//  23/07/2002 : RNO : Creation
//===================================================================


#ifndef CATG2IntoC2CommonEngine_H
#define CATG2IntoC2CommonEngine_H

#include "FrFAdvancedOpeCrv.h"

#include "CATCGMVirtual.h"
#include "CATListOfDouble.h"
#include "CATListOfCATCurves.h"
#include "CATFrFCompositeCurve.h"
#include "CATBoolean.h"

#include "CATMathPoint.h"
#include "CATMathVector.h"

#include "CATCGMStreamVersion.h"
#include "CATCGMStream.h"
#include "CATMathStream.h"

class CATCurve;
class CATFrFCompositeCurve;
class CATCrvLengths;
//class CATBoolean;
//class CATMathPoint;

class ExportedByFrFAdvancedOpeCrv CATG2IntoC2CommonEngine  : public CATCGMVirtual
{

// public methods
 public:
  //----------------------------
  // Constructeur / Destructeur
  //----------------------------
  virtual ~CATG2IntoC2CommonEngine();


  // Constructor_1_withCATCrvLength
  // Constructeur avec CrvLengths et Snoeuds
  // Les CrvLengths doivent etre a 10-8 de precision
            CATG2IntoC2CommonEngine                 (      CATFrFCompositeCurve     * iCCV           ,
                                                           CATListOfDouble          * iSNoeuds       ,
                                                           CATCrvLengths           ** TheCurveLengths,
                                                           CATSoftwareConfiguration * iSoftConfig    );


  // Constructor2_UsedInOldReduceData
            CATG2IntoC2CommonEngine                 (      CATFrFCompositeCurve     * iCCV           ,
                                                           CATLISTP(CATCurve)       * iParamFromABC  ,
                                                           CATListOfDouble          * iTNoeuds       ,
                                                           CATListOfDouble          * iSNoeuds       ,
                                                           CATSoftwareConfiguration * iSoftConfig    );

  // Constructor3_Simple
            CATG2IntoC2CommonEngine                 (      CATFrFCompositeCurve     *  iCCV          );

  void      Set2DRepresentationToImprove            (      CATBoolean                  iChoice       );

  double    GetTotalCCVLength                       ();

  //based on SNoeuds infos
  void      GetGlobalExtremitiesOfCrv               (      int                         iIndexCrv     ,
                                                           double                    & oStart        ,
                                                           double                    & oEnd          );
  CATLONG32 GetTotalNumberOfArcs                    ();

  //Return X,Y, or Z coordinate of the Point evaluated by eval 
  //Ordre 0
  // Parameter x is the Global CurviLinear parameter 
  // (Start parameter is 0.0, end parameter is the _MyCCV global length)
  double    EvalX                                   (const double        & x          );
  double    EvalY                                   (const double        & x          );
  double    EvalZ                                   (const double        & x          );
  double  * NewEval                                 (const double        & x          );
  double    EvalPoint3D                             (const double        & x          ,
                                                           CATMathPoint  & oPoint     );
  
  // Ordre 1
  // Parameter x is ALWAYS the Global CurviLinear parameter 
  // (Start parameter is 0.0, end parameter is the _MyCCV global length)
  double    EvalFirstDeriv_X                        (const double        & x          );

  double    EvalFirstDeriv_Y                        (const double        & x          );

  double    EvalFirstDeriv_Z                        (const double        & x          );

  double    EvalFirstDeriv3D                        (const double        & x          ,
                                                           CATMathVector & oFirstDeriv);

  double  * EvalNewFirstDerivX_T                    (const double        & x          ,
                                                           CATLONG32     & oIndexCurve);

  double    EvalNewFirstDerivT_S                    (const double        & x          ,
                                                          CATLONG32      & iIndexCurve);

  // Ordre 2
  // Parameter x is ALWAYS the Global CurviLinear parameter 
  // (Start parameter is 0.0, end parameter is the _MyCCV global length)

  double    EvalSecondDeriv_X                      (const double        & x          );

  double    EvalSecondDeriv_Y                      (const double        & x          );

  double    EvalSecondDeriv_Z                      (const double        & x          );

  double    EvalSecondDeriv3D                      (const double        & x          ,
                                                          CATMathVector & oSecondDeriv );

  void      EvalNewUpToSecondDerivX_T               (const double        & x          ,
                                                           CATLONG32     & oIndexCurve,
                                                           double       *& FirstX_T   ,
                                                           double       *& ScndX_T    );

  double    EvalNewSecondDerivT_S                   (const double        & x          ,
                                                           CATLONG32     & iIndexCurve);


  //------------------
  // Local parameter 
  //------------------

  void      GlobalToLocal                            (const double       & x          ,
                                                            CATLONG32    & indexf     ,
                                                            double       & t          );


  // Same as above but Locally to a curve
  int       GlobalCurvLinParamToLocalParam           (const CATLONG32      index      ,
                                                      const double       & x          ,
                                                            double       & t          );


  // index : index of curve
  // x global param on this curve
  // return t the global curvlinear param on the ccv
  // int GlobalCurvLinParamToGlobalParam(const CATLONG32 index, const double & x, double & t);
  //-----------------


  // N.B pas besoin de caractere virtual pour ces methodes relatives au stream
  //     car l'on n'herite pas d'un protocole de classe derivee comme par exemple pour les CATMathFunctionX. NLD161117
  CATBoolean IsStreamable                            (const CATCGMStreamVersion   iTargetVersion,
                                                            CATBoolean          & ioReversible  ) const;

  void      Stream                                   (      CATMathStream       & Str           ,
                                                      const char                  iLabelReserved[] ) const ;
  
//void      UnStream                                 (      CATMathStream       & Str           ) ;

  static CATG2IntoC2CommonEngine* UnStream           (
                                                            CATMathStream       & Str           ,
                                                      const CATTolerance        & iTolerance    ,
                                                      const char                  iLabelReserved[]);

  // protected data
  //-----------------
 private:
   // Copy constructor and equal operator
   // Non definis => interdiction de les utiliser
   CATG2IntoC2CommonEngine           (CATG2IntoC2CommonEngine &);
   CATG2IntoC2CommonEngine& operator=(CATG2IntoC2CommonEngine &);

   void     Init                                    (      CATFrFCompositeCurve     * iCCV           ,
                                                           CATListOfDouble          * iSNoeuds       ,
                                                           CATCrvLengths           ** TheCurveLengths,
                                                           CATSoftwareConfiguration * iSoftConfig    );

   // first  derivative for coordinate 0: X, 1: Y, 2: Z
   double    EvalFirstDeriv_i                       (const double        & x          ,
                                                           int             i          );

   // second derivative for coordinate 0: X, 1: Y, 2: Z
   double    EvalSecondDeriv_i                      (const double        & x          ,
                                                           int             i          );

   //========================
   // Les champs de la classe
   //========================
   double                      _LastEvaluatedAbscisse_G0;    // Derniers Calculs pour Eval

   double                      _LastEvalAbscisse_FrstDrvX_T; // Derniers Calculs pour FrstDrvX_T
   double                    * _LastEvaluatedX_T;            // Derniers Calculs pour FrstDrvX_T (Dim 2 ou 3 selon _Is2D)
   CATLONG32                   _LastGtoLIndex_FrstDrvX_T;

   double                      _LastEvalAbscisse_FrstDrvT_S;
   double                      _LastEvaluatedT_S;            // Derniers Calculs pour FrstDrvT_S

   
   double                      _LastEvalAbs_ScdDrvX_T;       // Pour EvalSecond
   double                    * _LastEvaluatedScdDrvX_T;      // Derniers Calculs pour la derivee seconde
   CATLONG32                   _LastGtoLIndex_ScndDrvX_T;

   double                      _LastEvalAbscisse_ScndDrvT_S;
   double                      _LastEvaluatedScndDrvT_S;     // Derniers Calculs pour ScndDrvT_S

   double                      _LastGToLCurvAbscisse;        // Derniers Calculs de GlobalToLocal
   double                      _LastGtoLLocalParameter;      // Derniers Calculs de GlobalToLocal
   CATLONG32                   _LastGtoLIndex;               // Derniers Calculs de GlobalToLocal
  
   CATFrFCompositeCurve      * _MyCCV;
   CATLONG32                   _NbCurvesCCV;
   CATCrvLengths            ** _MyLengths; 
   CATLISTP(CATCurve)        * _FunctionStoT;                // Pour compatibilite ancienne version
   CATListOfDouble           * _SNoeuds;
   CATListOfDouble           * _TNoeuds;
   CATSoftwareConfiguration  * _SoftConfig;

   double                      _CachePoint[3],
                               _CacheFrstXT[3],
                               _CacheScndXT[3]; 

   double                      _TolParam,
                               _TolForRecalage;
   CATBoolean                  _DeleteMyLengths,             // pour le cas ou l'utlisateur n'est pas defini de CrvLengths
                               _DeleteSNoeuds,               // IdemSNoeuds
                               _Is2D,                        // 2D ou 3D
                               _AlmostABC;                   // Compatibilite ancienne version

   int                         _CGMLevel;

 public:
   int                         _LoadedFromReplay;  


};

#endif
