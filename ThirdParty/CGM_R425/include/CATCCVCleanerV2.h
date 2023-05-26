#ifndef CATCCVCleanerV2_H
#define CATCCVCleanerV2_H

// COPYRIGHT DASSAULT SYSTEMES 1999 
//==============================================================================
//
// CATCCVCleaner:
// Nettoyage d'une CCV : correction des discontinuites en point, tangente,
// courbure et petits elements.
// Ce nettoyage est sans changement de parametrisation et est "isotopologique".
//
//==============================================================================
//
// Usage notes:
// Nettoyage de CCV , regardez aussi CATCurvesImprovement qui permet 
// - le nettoyage de connection entre courbes
// - la simplification de wire par concatenation de courbes voisines.
// 
//======================================================================
// 13/10/2017      : NLD : Deflaggage: non reversibilite de la migration sur CATTopOperator et de l'instrumentation CGMReplay
// 05/10/2017      : NLD : le journal est ajoute a la signature de CreateCCVCleanerV2()
// 29/09/2017      : NLD : Nouvelle signature      de CreateCCVCleanerV2()
//                         avec configuration et sans CGMLevel
//                         (Suppression de l'ancienne signature)
//                         Ajout constructeur explicite avec factory et configuration
//                         Run() devient typee int et non plus void (pour conformite CATCGMOperator)
// 25/09/2017      : NLD : Changement de signature de CreateCCVCleanerV2()
//                         - suppression de l'argument iMode
// 25/09/2017      : NLD : Ajout SetForceLocalOpti3()
//                         Reindentation homogene complete
// 24/10/2014      : NLD : Suppression de l'ancien Create
// 22/03/2004      : RNO : Modif signature SetAllowByPassingTolIfNecessary
// 15/04/2003      : RNO : Changement createur Approx pour versionning
// July   ,   2002 ; RNO : Ajout de SetMaxG2Threshold
// June   ,   2002 ; RNO : Ajout SetFirstCurveActiveLowInterval 
//                         pour gestion des wires "fermes-eclates"
// June   ,   2002 ; RNO : NouveauCreate avec Versionnement
// June,      2002 : HLN ; Mode hybride 2D+3D (cb resultat CATMergedCurve) : Add SetHybridMode2D3D
// October,   2001 ; HLN : Add GetPtsDeformOnInputCCV
// June,      2001 ; NLD : Add SetMinG0Treshold(), SetMinG1Treshold(), 
// June,      2001 : MWE ; on relache les cibles
// March,     2001 : MWE ; Add GetHighTotalDeformation
// March,     2001 : HLN ; Add Set2DRepresentationToImprove
// January,   2001 : HLN : Add SetMinToleranceDeform & GetPtsDeformOnInputCCV
// January,   2001 : HLN : Introduction de "SetPriorityMode"
// December,  2000 ; JCV ; CATCCVCleanerV2 -> CATCCVCleanerV2
// December,  2000 ; JCV ; Add Set*IsFixed
// October,   2000 ; MWE ; Add functions for CurvesImprovement
// September, 1999 ; DHN ; Creation
//======================================================================

#include "CATCGMVirtual.h"

#include "FrFAdvancedOpeCrv.h"

#include "CATBoolean.h"

#include "CATSkillValue.h"

#include "CATFreeFormDef.h"
#include "CATCurvesImprovementDefine.h"

#include "CATLISTP_CATMathPoint.h"

#include "CATTopOperator.h"
class CATMathPoint;
class CATGeoFactory;
class CATFrFCompositeCurve;
class CATSoftwareConfiguration;
class CATTopData;
class CATCGMJournalList;
class CATLocalizer2DFrom3D;

//----------------------------------------------------------------------
#define CATCCVCleanerV2MotherClass CATTopOperator
class  ExportedByFrFAdvancedOpeCrv CATCCVCleanerV2 : public CATCCVCleanerV2MotherClass
 
{
public:
  virtual ~CATCCVCleanerV2() {};

                                 CATCCVCleanerV2               (CATGeoFactory            * iFactory              ,
                                                                CATTopData               * iTopData              );
                                                            //  CATSoftwareConfiguration * iSoftwareConfiguration);

  virtual void                   SetSoftConfig                 (CATSoftwareConfiguration * iSoftwareConfiguration) = 0;
  
  // NLD250917 equivalent a activation de CGM_Versionning_CleanCurve_LocalOpti3
  virtual void                   SetForceLocalOpti3            (int                        iForceLocalOpti3Level ) = 0;

  // To indicate the continuity level to improve, default value : CATFrFTangentCont 
  //  it could be also : CATFrFPointCont, CATFrFCurvatureCont
  virtual void                   SetLevelContinuityToImprove   (CATFrFContinuity           iLevel)                 = 0;
  
  // Threshold below the G0 correction is applied. 
  //
  // Default value : C0Resolution = 0.001
  //
  virtual void                   SetG0Threshold                (double                     iMaxG0)                 = 0;
  
  // Threshold above which the G0 correction is applied. 
  //
  // Default value : null value = 0.0
  //
  virtual void                   SetG0MinThreshold             (double                     iMinG0)                 = 0;
  
  // Threshold below the G1 correction is applied. It is an angle in degree.
  // If angle(Tgt1,Tgt2) < iMaxG1, then G1 correction is applied
  // (Tgt1, and Tgt2 are tangent vectors : on extremity of curve1 and origin of curve2).
  //
  // Default value : C1Resolution = 0.5 degree
  //
  virtual void                   SetG1Threshold                (double                     iMaxG1)                 = 0;
  
  // Threshold above which the G1 correction is applied. 
  //
  // Default value : null value = 0.0
  //
  virtual void                   SetG1MinThreshold             (double                     iMinG1)                 = 0;
  
  //
  // Threshold above the G2 correction is applied. It is a percent (in [0,1]). 
  //
  // Default value : 0.98
  //
  // If  || Rho1-Rho2|| / ||Rho2|| < (1-percent)/percent, then correction is applied
  // (Rho1, and Rho2 are curvature vectors, where ||Rho1|| < ||Rho2||)
  //
  virtual void                   SetG2Threshold                (double                     iMinG2)                 = 0;
  
  // Threshold below which the G2 correction is applied. 
  //
  // Default value : 1.0 
  //
  virtual void                   SetG2MaxThreshold             (double                     iMaxG2)                 = 0;
  
  //
  // imposer le degre max et la tolerance d'approx si le passage en Bspline est
  // necessaire
  // 
  // Default value Degre     : 11
  // Default value Tolerance : C0Resolution/3.
  //
  virtual void                   SetMaxDegree                  (CATLONG32                  iMaxDegree)             = 0;
  virtual void                   SetMaxToleranceApprox         (double                     iTolApprox)             = 0;
  //
  // imposer la tolerance MINIMALE de deformation pour la correction des discontinuites,
  // la tolerance effective etant: iTolDeform + iTolApprox - ErreurApprox  avec
  // ErreurApprox <= iTolApprox
  //
  // Default value : 2.*C0Resolution/3.
  //
  virtual void                   SetMinToleranceDeform         (double                     iTolDeform)             = 0;

  // If this option is set the CCV cleaner could locally by-pass the SetMinToleranceDeform
  // this option is usefull in the CurvesImprovement Process where both controled deformation
  // and nice corrections are required. Especially when a G0 gap is bigger than the SetMinToleranceDeform
  // One coul precise the tolerance to never bypass
  // By default it is equivalent to iNeverByPassThisOne=iTolDeform
  virtual void                   SetAllowByPassingTolIfNecessary(double                     iNeverByPassThisOne)   = 0;
  //
  // pour fixer des courbes extremites fixes
  virtual void                   SetStartIsFixed               ()                                                  = 0;
  virtual void                   SetEndIsFixed                 ()                                                  = 0;
  
  //pour reduire l'intervalle de deformation des courbes extremes 
  // a 50% de leur longueur au lieu de 99% : necessaire pour assurer la symetrie de 
  // la deformation en cas de wire "periodique" 
  // (par ex : 1ere courbe=avant derniere et deuxieme courbe = derniere courbe) 
  virtual void                   SetFirstCurveActiveLowInterval()                                                  = 0;
  virtual void                   SetEndCurveActiveLowInterval  ()                                                  = 0;
  
  //
  // pour definir la priorite de nettoyage : correction de discontinuite avec maitrise
  // de la deformation (iPriority==Deformation) ou non (iPriority==Continuity)
  virtual void                   SetPriorityMode               (CATCrvImprvPriority         iPriority)             = 0;
  //
  // dans le cas de courbes sur surface, pour definir la representation geometrique
  // a corriger (2D ou 3D).
  // valeur par defaut : FALSE, signifie que la geometrie a corriger est 3D.
  //   virtual void                   Set2DRepresentationToImprove (CATBoolean iChoice) = 0;
  virtual void                   Set2DRepresentationToImprove  (CATLocalizer2DFrom3D      * iLocalizer)            = 0;
  
  // Effective if 2D representation and iPriority==Deformation have been previously chosen.
  // Allows to have both 2D and 3D representation for the output curves that have been
  // corrected (fixed curves are unchanged through this mode). Output corrected curves are
  // of CATMergedCurve type where 3D curves are placed as reference curves.
  // Default value : 0 (2D Representation only)
  virtual void                   SetHybridMode2D3D             (int                         iHybridMode2D3D)       = 0;
  
  //   on relache les cibles;
  //   iOptimization=0 on ne relache pas les cibles, pas d'optimisation, etat anterieur de l'algo
  //   iOptimization=1 on relache les cibles, optimisation,
  //   return 0 if OK, >0 KO
  virtual void                   SetLocalOptimization          (int                         iOptimization)         = 0;


   //  o  DefaultC1ToC2Management   :   By default only the C1-curves that need a modification to reach
   //                                    the SetLevelContinuityToImprove continuity becomes C2 ;
   //  o  AllCurvesC1ToC2Management :   if this option is set ALL C1 curves becomes  C2 (exceptions 
   //                                                for fixed curves that are stil untouched) ;
   //  o  NoC1ToC2Management         :   No Special Management are made WARNING with this option,
   //                                                            output curves could be C1 Only
  virtual void                   SetC1ToC2Management           (CATCrvImprvC1ToC2Management iChoice)               = 0;

  
  virtual int                    Run                           ()                                                  = 0;
  //
  // Pour recuperer le resultat du nettoyage 
  // Si la CCV a nettoyer etait continue en tangence et en point,
  // le pointeur retourne est celui de la CCV en entree
  // Si la CCV a ete nettoyee, le pointeur est celui d'une nouvelle
  // CCV pointant vers les memes courbes plus des nouvelles courbes
  // issues de la deformation
  //
  virtual CATFrFCompositeCurve*  GetCleanedCCV                 ()                                                  = 0;
  //
  // Comment savoir quelles courbes sont nouvelles ?
  // Si le pointeur rendu est nul, il n'y a pas eu de deformation
  // Sinon, la taille du tableau rendu est le nombre d'element constitutifs
  // de la CCV. L'indicateur vaut 0 si l'element n'a pas ete deforme (cet
  // element est donc aussi pointe par la CCV a deformer), il vaut 1 sinon.
  // Attention, dans ce dernier cas, les nouvelles courbes ne sont pas streamables,
  // elles doivent donc IMPERATIVEMENT etre detruites. 
  //
  virtual const CATLONG32      * IsANewCurve                   () const                                            = 0;
  

  //
  // Projection sur la CCV d'entree des points de deformation locale maximale
  // (Append dans la Liste passee en arguments)
  virtual int                    GetPtsDeformOnInputCCV        (CATLISTP(CATMathPoint)    & oPtsDeformOnInputCCV)  = 0;
  //
  // Points de deformation locale maximale sur la CCV "nettoyee"
  // (Append dans la Liste passee en arguments)
  //
  virtual int                    GetPtsDeformOnCleanedCCV      (CATLISTP(CATMathPoint)    & oPtsDeformOnCleanedCCV)= 0;

  
  

  //
  // Recuperer la deformation maxi commise pour passer a la reduction type Nurbs 
  // ATTENTION : c'est un MAJORANT de la deformation totale (a priori superieur
  // a la deformation totale maxi exacte)
  virtual const double           GetHighTotalDeformation       ()                                            const =  0;
};

//==================================================================
// ancienne signature (historique) avec CGMLevel
/*
ExportedByFrFAdvancedOpeCrv
CATCCVCleanerV2* CreateCCVCleanerV2 (  CATGeoFactory        * iFactory    ,
                                       CATFrFCompositeCurve * iCCV        ,
                                       int                    iCATCGMLevel);
                  //NLD250917          CATSkillValue          iMode       = BASIC);
*/
// Nouvelle signature pour migration aisee sur CATTopOperator NLD290917
ExportedByFrFAdvancedOpeCrv
CATCCVCleanerV2* CreateCCVCleanerV2 (  CATGeoFactory            * iFactory    ,
                                       CATSoftwareConfiguration * iConfig     ,
                                       CATFrFCompositeCurve     * iCCV        ,
                                       CATCGMJournalList        * iJournal    = NULL);

//==================================================================

ExportedByFrFAdvancedOpeCrv
void Remove(CATCCVCleanerV2 *&iCATCCVCleaner);



#endif

