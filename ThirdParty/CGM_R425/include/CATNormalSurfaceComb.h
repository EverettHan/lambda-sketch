#ifndef CATNormalSurfaceComb_H
#define CATNormalSurfaceComb_H

// #define CATNormalSurfaceCombOnExternalComb "Essai NLD270120"

//==========================================================================
// Copyright Dassault Systemes Provence 2002-2009, all rights reserved 
//==========================================================================
//
//==========================================================================
// 27/01/20 : NLD : Migration sur CATFrFExternalComb: essai concluant;inactif
// 17/06/19 : NLD : Merge V5/V6
// 06/06/19 : mwe : Ajout _crvMinParam, _crvMaxParam
// 29/05/19 : MWE ; remplace MassProperties par CATCrvLengths
// 28/05/19 : NLD : Ajout EvalPointOnSupport()
// 23/05/19 : NLD : Ajout de CreateListOfCATNormalSurfaceComb()
//                  pour création liste de peignes depuis CCV
//                  Suppression de _factory        (utiliser GetFactory())
//                  Suppression de _OrientationCrv (utiliser _OrnSupport)
//                  Renommage   de _Support en _SupportSurface
//                  Ajout RescaleParameter()
//                  Ajout GetCrvParam()
// 22/05/19 : NLD : Suppression de SetCombOrientation() et GetCombOrientation()
//                  (existent dans la classe mère)
// 22/05/19 : NLD : N.B pour l'historique Adele 2003/2019 on se reportera à
//                  CAT3DDSP2.tst/ProtectedInterfaces/CATNormalSurfaceComb.h
// 02/05/19 : RAQ : Déplacement   de   CAT3DDSP2.tst vers FreeFormOperators pour projet Honda
// 16/03/09 : MMO : Redeplacement dans CAT3DDSP2.tst (pour corriger le cycle archi)
// 05/03/09 : RNO : Deplacement dans CurveBasedTopoOperator.tst (sinon cycle archi)
// 11/02/08 : NLD : Changement de signature pour le constructeur. signature standard peignes
//   /02/03 : MWE : Creation pour test;                                  MWE
//==========================================================================


#include "FrFObjects.h"

#include "CATFrFGeneralComb.h"
#ifdef CATNormalSurfaceCombOnExternalComb
#include "CATFrFExternalComb.h"
#endif


#include "CATPCurve.h"
#include "CATSurface.h"
#include "CATCrvLimits.h"

//#include "CATIPGMMassProperties1D.h"
#include "CATIPGMCrvLengths.h"

#include "CATListOfCATFrFGeneralComb.h"

//#include "CATMathDef.h"
class CATMathInterval;
class CATLaw;
class CATMathVector;
class CATFrFCompositeCurve;


//--------------------------------------------------------------------------
class ExportedByFrFObjects
#ifdef CATNormalSurfaceCombOnExternalComb
CATNormalSurfaceComb : public CATFrFExternalComb
#else
CATNormalSurfaceComb : public CATFrFGeneralComb
#endif
{
public:
  // ================
  // Constructor
  // ================
  // N.B protocole de création
  //     l'intervalle iTdTf (mal nommé: ne correspondant pas à la notation iT des évaluateurs)
  //     me semble redondant avec iLimits, et, sauf erreur de la part, eut gagné à etre calculé en interne
  //     avec l'outil de mesure de longueur choisi
  //     on pourrait ne recevoir plutot que le parametre debut (le parametre fin s'en déduisant)
  //     NLD220519
                 CATNormalSurfaceComb(CATFrFObject     *  iFrFObject, CATLONG32 iMinLevel,//NLD110208 CATGeoFactory * iFactory,
                                      CATPCurve        *  iCurve    ,
                                      CATCrvLimits      & iLimits   ,
                                      CATLONG32           iOrienCrv ,
                                      CATLONG32           iOrienSrf ,
                                      CATMathInterval   & iTdTf     ); // limites du peigne (longueurs curvilignes debut et fin; commentaire NLD220519)
  //==========================================================================
  // Destructor
  virtual       ~CATNormalSurfaceComb();
  
  //==========================================================================
  // To change the orientation of the comb ; iOrientation=1(default) or -1.
  // See mother class NLD220519
  // void           SetCombOrientation(CATLONG32 iOrientation);
  // CATLONG32      GetCombOrientation() const;
 
  //==========================================================================
  // To get the type of comb.
  CATMathClassId IsA() const;
  
  //==========================================================================
  // Evaluators
  //==========================================================================
  CATLONG32      Eval               (double iT, CATMathVector & oDir     ) const;

  // N.B cette méthode est spécifique, ne dérive pas de la classe mère; NLD270120
  CATLONG32      EvalNoneNormed     (double iT, CATMathVector & oDir     ) const;

  CATLONG32      EvalFirstDerivative(double iT, CATMathVector & oDerivDir) const;
//CATLONG32      EvalSecondDerivative(double iT,CATMathVector & oDersecDir) const;
  

  // return tangent vector on supporting Curve
  void           EvalTgtOnSupport   (double iT, CATMathVector & oDir     ) const;
  // return point          on supporting Curve
  void           EvalPointOnSupport (double iT, CATMathPoint  & oPoint   ) const;

protected:
  // Passage du paramètre d'évaluation (global) au paramètre sur courbe (local)
  // en fait du parametrage global sur la liste de peignes, au parametrage local sur courbe
  // (meme nom de méthode que dans les autres peignes de la famille)                     NLD230519
  double         RescaleParameter   (double iT)                            const;

  void           GetCrvParam        (double        iT       ,
                                     CATCrvParam & oCrvParam)              const;

  //==========================================================================
  // Data
  //==========================================================================
  double                    _crvMinParam;      // limite inférieure utile de la Pcurve 
  double                    _crvMaxParam;      // limite supérieure utile de la Pcurve 
  // Intervalle des parametres sur le wire ABC
  double                    _TotalLengthDeb;
  double                    _TotalLengthFin;
  double                    _Length;           // longueur de la courbe = (_TotalLengthFin - _TotalLengthDeb)
  CATPCurve               * _CurveOnSurf;
  //                                           // _SupportSurface remplace _Support, maladroit vis à vis de EvalTgtOnSupport; NLD230519
  CATSurface              * _SupportSurface;   // en hommage au groupe support surfaces;
//CATIPGMMassProperties1D * _MyProperties;
  CATIPGMCrvLengths       * _MyProperties;

};

//==========================================================================
// Creation d'une liste de peignes de type CATNormalSurfaceComb
// N.B (mais renvoyés sous forme de CATFrFGeneralComb pour faciliter l'usage du CombCleaner)
//==========================================================================
ExportedByFrFObjects
void CreateListOfCATNormalSurfaceComb      (CATGeoFactory              * iFactory    ,
                                            CATSoftwareConfiguration   * iConfig     ,
                                            CATFrFCompositeCurve       * iCCVInput   ,
                                            CATLISTP(CATFrFGeneralComb)& oListOfComb );

#endif
