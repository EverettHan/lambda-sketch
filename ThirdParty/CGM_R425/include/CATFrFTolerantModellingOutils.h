//====================================================================
// Copyright Dassault Systemes Provence 2005, all rights reserved 
//====================================================================
//
// CATFrFTolerantModellingOutils :
//
// Declaration de functions globales communes au Passage au Tolrant Modelling C1, C-1
//
//==========================================================================
// 24/11    2021 : NLD : Utilitaire() et UtilitaireBis() ne sont plus visibles
// April,   2005 : ANR/FZA : Creation  (D'apres  CATTolerantModellingOutils)
//==========================================================================

#ifndef CATFrFTolerantModellingOutils_H
#define CATFrFTolerantModellingOutils_H

#include "CATFrFNetSurface.h"

#include "CATDataType.h"
#include "CATBoolean.h"

class CATCurve ;
class CATNurbsCurve ;
class CATKnotVector;
class CATGeoFactory;
class CATFrFNurbsMultiForm;
class CATMathPoint;
class CATSoftwareConfiguration;

//
void                            NewC2KnotVector          (CATCurve                 *  iCurve          ,
                                                          CATBoolean                & oIsC1           ,
                                                          CATKnotVector            *& oNewKnotVect    ) ;

//
// N.B iTolEpsg apparue pour portage XScale le 12/06/07
//     - doit etre indépendante de l'échelle
//     - n'a pas vraiment de signification dans cet API
//     - il eut mieux valu faire transiter le bloc de tolérances
//       (que l'on peut d'ailleurs récupérer sous la courbe désormais)
//     NLD241121
void ExportedByCATFrFNetSurface CheckParamContOfNurbsCrv (double                      iTolEpsg        ,
                                                          CATNurbsCurve            *  iCurve          ,
                                                          double                      iEpsParam       ,
                                                          double                      iEpsAng         ,
                                                          CATLONG32                 & oContinuity     ,
                                                          CATLONG32                *& oTabOfContinuity) ;
//
void ExportedByCATFrFNetSurface CheckParamContinuity     (CATGeoFactory            *  iFactory        ,
                                                          CATCurve                 *  iCurve          ,
                                                          double                      iEpsParam       ,
                                                          double                      iEpsAng         ,
                                                          CATLONG32                 & oContinuity     ,
                                                          CATLONG32                *& oTabOfContinuity) ;
//
void ExportedByCATFrFNetSurface SmoothC0TabOfMfs         (CATGeoFactory            *  iFactory        ,
                                                          CATSoftwareConfiguration *  iconfig         ,
                                                          CATLONG32                   iNbreOfMfs      ,
                                                          CATFrFNurbsMultiForm    **  ionurbsMultiForm) ;

//
/*
ces utilitaires internes non exportés non documentés n'ont pas lieu d'apparaitre ici; NLD241121
void                            Utilitaire               (CATGeoFactory            *  iFactory        ,
                                                          CATSoftwareConfiguration *  iConfig         ,
                                                    const CATMathPoint              & iPt             ,
                                                          CATFrFNurbsMultiForm     *  iMF1            ,
                                                          CATFrFNurbsMultiForm     *  iMF2            ) ;

// 
void                            UtilitaireBis            (CATGeoFactory            *  iFactory        ,
                                                          CATSoftwareConfiguration *  iConfig         ,
                                                    const CATMathPoint              & iPt             ,
                                                          CATLONG32                   iSide           ,
                                                          CATFrFNurbsMultiForm     *& ioMF            );
*/

#endif
