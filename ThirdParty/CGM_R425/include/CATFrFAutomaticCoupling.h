// COPYRIGHT DASSAULT SYSTEMES 2001
//==========================================================================
//
// CATFrFAutomaticCoupling:
// 
//==========================================================================
//
// Usage notes: 
//
//
// 
//
//========================================================================== 
// 28/08/01 ALV Creation
// 03/08/17 NLD Mise au propre. Smart indent
//              Les structures locales sont mises dans la classe
// 04/08/17 NLD Reception de la configuration
//              Ajout _Config
//========================================================================== 

//========================================================================== 
// ALGO OPTIONS
//========================================================================== 
// TEST OPTIONS
//========================================================================== 

//========================================================================== 
// DEFINES
#ifndef CATFrFAutomaticCoupling_H
#define CATFrFAutomaticCoupling_H

#include <AdvTopoUtil.h>
#include <CATTopData.h>
#include <CATBody.h>
#include <CATGeoFactory.h>
#include <CATFrFCoupling.h>
#include <CATFrFCompositeCurve.h>
#include <CATCrvParam.h>

#include <CATMathDef.h>
#include <CATMathDirection.h>
#include <CATEdgeCurve.h>
#include <CATSkillValue.h>
#include <CATListPV.h>
class CATVertex ;
#include <ListPOfCATBody.h>
#include <ListPOfCATVertex.h>

class CATCGMJournalList;
class CATFrFCCvParam;
class CATTopOpInError;
class CATSoftwareConfiguration;

//========================================================================== 

class ExportedByAdvTopoUtil CATFrFAutomaticCoupling 
{
//========================================================================== 
// Les Structuctures utilisees par la classe:
//========================================================================== 
struct Point{
    int             IndWire;
    int             IndCrv;
    CATBoolean      ToReport;
    CATBoolean      InAutomaticCoupling; // est-il couple par l'AutomaticCoupling
    CATLONG32       NumDomain;
    CATLONG32       Continuity;
    double          Ratio;               // valeur en ratio du point sur la CCv.
};

struct NewPoint{//les nouveaux points dans le cas des lignes partielles 
    int             IndWire;
    int             IndCrv;
    CATCrvParam     ParamOnProfil;
    CATBoolean      OnGuide;
    CATBoolean      NotRecord;           // Le nouveau point a t'il ete enregistre par l'utilisateur du couplage?
    double          Ratio;               // valeur en ratio du point sur la CCv.
};

struct Coupling1X1{
    Point*          StartPoint;
    Point*          EndPoint;
    CATBoolean      Activate;            // les deux points doivent etre dans le meme domaine
    double          DiffAlpha2D;         // difference entre les ratios des points
};

struct CouplingLine
{   //attention detruire aIndPoints une fois fini avec une variable de ce type!!
    CATBoolean      Active;            // sert lors de la boucle de choix des lignes
    CATBoolean      Complete;          // Si NbOfCoupling1X1 == _NbOfWires
    int*            aIndPoints;        // tableau des indices des Points de la ligne
    double          DiffAlpha2D;       // sauvegarde des differentes Diff
    double          DiffAlpha3D;
    double          DiffGamma;
    double          DiffBeta;
};

  public :
    
    
    //--  Constructeur --
             CATFrFAutomaticCoupling          (CATGeoFactory        *  iFactory                     ,
                                               CATSoftwareConfiguration* iConfig                    ,
                                               int                     iNbOfWires                   ,
                                               CATFrFCompositeCurve**  iCCV                         ,
                                               CATLONG32               iNbIntersectingWires         ,
                                               CATFrFCCvParam       *  iIntersectionsWithWiresCCvPar);
    
    
    //--  Destructeur --
    virtual ~CATFrFAutomaticCoupling();
    
    
    //-- Les methodes d'entree des informations --

             void        Init                 (CATLONG32           **  iDomain                   = NULL ,
                                               CATBoolean              iComputNewDomain          = FALSE);

            //si le tableau de domain est null, il nous faut le calculer, si set seulement si le _Coupling est connu!!.
             void        SetSnappingParameters(double                  iMaximumSnappingValue     = .1,
                                               CATBoolean              iRelativeSnapping         = TRUE);

             void        SetNewDomain         (CATLONG32           **  iDomain                   );

             void        SetCoupling          (CATFrFCoupling       *  iCoupling                 ,
                                               CATBoolean              iComputeDomain            );

             void        SetWeights           (CATBoolean              iAutomaticChoiceOfWeights = TRUE,
                                               double                  iAlpha                    = 0.5,
                                               double                  iBeta                     = 0.3,
                                               double                  iGamma                    = 0.2,
                                               double                  iTaux3D                   = 0.5,
                                               int                     iNumDomain                = 0);

            //Si le iNumDomain = 0 les taux sont applique a tous les taux.
             void       SetPointsToReport     (int                 **  PointsToReport            );
    
    //-- Les methodes de calcul --

             // reinitialise dans le cas d'un relancement manuel du calcul des domaines
             //+ d'un SetNewDomain, ou d'un SetCoupling....
             void       InitBeforeCompute     ();

             void       Run                   ();

             void       RunInOneDomain        (int                     iNumDomain                );
    
    
    //-- Les methodes de recuperation des informations --
    //       void       GetCoupling           (CATFrFCoupling       *& oCoupling) const;
             void       GetCoupledVertices    (int                     oNbOfCoupledVertices      ,
                                               CATBoolean          **  oCoupledVertices          );

    //renvoie un tableau de booleen sur chaque fin de courbe des CCv.
    //Celui-ci indique ou non si la fin de courbe est couplee par AutomaticCoupling.
             CATBoolean GetNewVertices        (int                   & oNbNewVertices            ,
                                               int                  *  oaIndWire                 ,
                                               int                  *  oaNumCrv                  ,
                                               CATCrvParam          *  NewParamVertices          ,
                                               CATBoolean           *  OnGuide                   );

    //       CATLONG32** GetDomain            (double                & oNbOfDomain               );

    //       void        GetSnappingParameters(double                  oMaximumSnappingValue     ,
    //                                         CATBoolean              oRelativeSnapping         );
    
    
    


  private :

    //-- Private methods --

             void      ComputeRatioInOneDomain(int                     iNumDomain                );

             // Recalcule les domaines a partir de _Coupling (uniquement)
             void       ComputeDomain         ();

             // affichage des points du domaine, ou de tout les points si 0
             void        ShowPoints           (int                     iNumDomain                );

             void        PointOfDomain        (int                     iNumDomain                ,
                                               int                   & oNbOfPoints               ,
                                               int                  *  oNbOfPointsByWires        ,
                                               int                 **  oIndPoints                );

             void       ComputeNbOfCoupling1X1(int                     iNumDomain                ,
                                               int                     iNbOfPoints               ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               int                   & oNbOfCoupling1X1          );

             void       ComputeCoupling1X1    (int                     iNumDomain                ,
                                               int                     iNbOfPoints               ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               int                   & oNbOfCoupling1X1          ,
                                               Coupling1X1          *  oAllCoupling1X1           ,
                                               int                   & oNbCoupling1X1OK          ,
                                               int                  *  oaNbCpl1X1Cumule          );

             void       ComputeLeftAndRightGuides
                                              (int                     oLeftGuide                ,
                                               int                     oRightGuide               ,
                                               int                     iNumDomain                ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               double               *  WGuideGauche              ,
                                               double               *  WGuideDroite              );

    //lignes "completes"
             void       ComputeNbOfCompleteLines
                                              (int                     iNumDomain                ,
                                               int                     iNbOfCoupling1X1          ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               Coupling1X1          *  iAllCoupling1X1           ,
                                               int                   & oNbLigne                  ,
                                               int                 **  oaNbLignesPassante        );

             void       ComputeCompleteLines  (int                     iNumDomain                ,
                                               int                     iNbOfCoupling1X1          ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               Coupling1X1          *  iAllCoupling1X1           ,
                                               int                     iNbLigne                  ,
                                               CouplingLine         *  oLignes                   ,
                                               int                  *  iaNbCpl1X1Cumule          ,
                                               int                 **  iaNbLignesPassante        );

    //lignes "partielles"
             void       ComputeNbOfPartialLines
                                              (int                     iNumDomain                ,
                                               int                     iNbOfCoupling1X1          ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               Coupling1X1          *  iAllCoupling1X1           ,
                                               int                   & oNbLinesP                 ,
                                               int                 **  oaNbLignesFinissantes     );

             void       ComputePartialLines   (int                     iNumDomain                ,
                                               int                     iNbOfCoupling1X1          ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               Coupling1X1          *  iAllCoupling1X1           ,
                                               int                     iNbLinesP                 ,
                                               CouplingLine         *  oLinesP                   );

             CATBoolean    AddLineToCoupling  (CouplingLine         *  iLinesP                   ,
                                               int                     iNumDef                   ,
                                               int                     GuideGaucheLigne          ,
                                               int                     GuideDroiteLigne          ,
                                               double               *  WGuideGauche              ,
                                               double               *  WGuideDroite              );

    //Outils permettant ls choix des lignes
             CATBoolean  IntersectLines       (CouplingLine            iLine1                    ,
                                               CouplingLine            iLine2                    );

             CATBoolean  ThisLineIsOK         (CouplingLine            iLine                     ,
                                               int                  *  iGuideGauche              ,
                                               int                  *  iGuideDroite              ,
                                               int                 **  iSommetDuDomaine          ,
                                               int                  *  iNbSommet                 );

             double      DiffLine             (CouplingLine         *  iaLines                   ,
                                               double                  iDiffMinCourant           ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               int                     iNbLine                   ,
                                               int                     iNumLigne                 ,
                                               int                     iNumPassage               );

             void        ChoixDesTaux         (CouplingLine         *  iLines                    ,
                                               int                     iNbLine                   ,
                                               double                  iMaximumGreatSnappingValue,
                                               double                  iMaxTorsion3D             ,
                                               int                  *  iNbOfPointsByWires        ,
                                               int                 **  iIndPoints                ,
                                               int                     iNumPassage               );

    //methodes permettant d'eviter les pb lie a _Coupling.
    //ces methodes sont les meme que celle de CATFrFWiresHomogenization.
             CATBoolean  MyInvEvalCouplingParameters
                                        (const CATLONG32               iCCvIndex                 ,
                                         const CATLONG32               iCurveIndex               ,
                                         const CATCrvParam          *  iCurveParam               ,
                                               double                & oT                        ,
                                               CATBoolean              ThrowError                );

             CATBoolean  MyEvalCouplingParameters
                                        (const double                  iT                        ,
                                               CATLONG32               iCCVIndex                 ,
                                               CATLONG32             & oCurveNumber              ,
                                               CATCrvParam           & oCurveParam               ,
                                               CATBoolean              ThrowError                );

  private :
  
    CATGeoFactory*            _Factory;
    CATSoftwareConfiguration* _Config;
    int                       _NbOfWires;
    CATFrFCoupling*           _Coupling;
    CATFrFCompositeCurve**    _MyCCV;

    CATLONG32**               _CcvContinuity;
    CATLONG32**               _CcvDomain;
    int                       _NbOfDomain;
    CATBoolean                _ComputeNewDomain;

    CATFrFCCvParam*           _IntersectionsWithWiresCCvPar;
    CATLONG32                 _NbIntersectingWires;

    CATBoolean                _RelativeSnapping;
    double*                   _WMaxSnapping;
    double                    _MaximumSnappingValue;

    CATBoolean                _AutomaticChoiceOfWeights;
    double**                  _AlphaDomain;              // sauvegarde des taux pour chaque domaines initiaux
    double**                  _BetaDomain;
    double**                  _GammaDomain;
    double**                  _Taux3DDomain;

    //                      // les Taux des calculs courants.
    double                    _Alpha;
    double                    _Beta;
    double                    _Gamma;
    double                    _Taux3D;

    Point**                   _MyPoints;
    int                       _NbPoints;
    int                       _NbNewPoints;
    NewPoint*                 _NewPoints;
    
};
#endif
