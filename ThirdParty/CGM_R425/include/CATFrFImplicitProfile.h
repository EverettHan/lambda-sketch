// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFImplicitProfile:
// Interface class of Implicit Profile Object.
// The Profile description is implicit (Segment, cicle)
//
//==========================================================================
//
// Usage notes:
//
//==========================================================================
//  Sept 98 CPL Creation                                            C.Pradal
// 24 02 99 NLD Ajout GetOneCurve
// 15 01 01 CPL Ajout EvalFirstDeriv
// 21 11 01 JSX Ajout GetConstraintArray et EvalDistance
// 16 12 01 NDN Ajout SetSmoothOption, SetSmoothAngleThreshold et SetCGMLevel
// 10/10/03 JSX Passage des CATLONG32 en int
// 15 04 05 JSX Ajout des methodes pour les Polydomaines (Evolution Blend Sur SweepTopo)
// 14/03/07 NLD Le constructeur recoit un CATFrFObject
// 07/07/10 JSX Ajout argument iFixedNormalVertex a SetSmoothOption
// 07/05/14 NLD Smart indent
//              Enumeration CATFrFImplicitProfileType
// 16/11/15 NLD Remontee des codes d'evaluation du Blend
//              avec option de precompilation pour stress tests des multiplexages/demultiplexages
//              Ajout de GetProfileType()
// 01/12/15 NLD Suite mise au propre des methodes du Blend
//              - SetDataForOneDomain() remplace SetDataForOneDomaine()
//              - iDiscType remplace iDisType dans les signatures de ComputeG0RecoverValue() et SetG0RecoverLaw()
//              - reordonnancement des arguments de ComputeG0RecoverValue()
//              - marquage des methodes specifiques blend: <@BlendOnly>
//              Ajout GetCanonicSweepType() (en prevision du futur)
// 09/12/15 NLD L'argument iParameterRatio de SetSmoothedCurvature() est dimensionne a [3] et non [2]
//              (pour remise en conformite avec son usage reel depuis Decembre 2008)
// 03/03/17 NLD Suppression du EvalFirstDeriv() rendant un CATMathSetOfVectors, jamais derive en dessous de l'implementation par defaut
// 08/06/17 NLD Ajout SetRoadWidthOption()
// 18/12/19 NLD Ajout CATFrFImplicitProfileSegment7_Pyramid
//==========================================================================
//
#ifndef CATFrFImplicitProfile_H
#define CATFrFImplicitProfile_H

//==========================================================================
//Ne genere pas de KO ODT si tous Eval bien codes. Validation complete *Sweep* *Blend* OK171115"
//#define CATFrFBlendProfileCx2_ForceStressTestOptionForEvalAll "TEST ONLY ne pas livrer actif"
//==========================================================================

//
#include "CATFrFGeneralizedProfile.h"
#include "CATFrFObject.h"

class CATGeoFactory;
class CATMathVector;
class CATMathAxis;
class CATMathSetOfVectors;
class CATLaw;
class CATFrFSweepShape;
class CATFrFCompositeCurveMapping;
//-----------------------------------------------------------------------------
typedef enum {
              // Types generaux
              CATFrFImplicitProfileType0_Unknown                    = 0,

              // Type segment
              CATFrFImplicitProfileSegment1_2Limits                 = 1,
              CATFrFImplicitProfileSegment2_1Limit1Functional       = 2,
              CATFrFImplicitProfileSegment3_1Limit1Middle           = 3,
              CATFrFImplicitProfileSegment4_1Guide1Reference        = 4,
              CATFrFImplicitProfileSegment5_Cone                    = 5,
              CATFrFImplicitProfileSegment6_Ridge                   = 6, // Nouveaute 060514 pour pliure
              CATFrFImplicitProfileSegment7_Pyramid                 = 7, // Nouveaute 181219 pour pyramide

              // Type cercle
              CATFrFImplicitProfileCircle1_3Lim                     = 1,
              CATFrFImplicitProfileCircle2_2Lim1Rad                 = 2,
              CATFrFImplicitProfileCircle3_2Mid2Ang                 = 3,
              CATFrFImplicitProfileCircle4_1Mid1Rad                 = 4,
              CATFrFImplicitProfileCircle5_1Mid1Rad2Ang             = 5,
              CATFrFImplicitProfileCircle6_2Lim1Ang1Sur             = 6,
              CATFrFImplicitProfileCircle7_1Lim1Rad1Sur             = 7,
              CATFrFImplicitProfileCircle8_1Mid1Rad1Len1OptAng_Elec = 8,

              // Type conique
              CATFrFImplicitProfileConic1_5Lim                      = 1, // 5 lim
              CATFrFImplicitProfileConic2_4Lim1Tan                  = 2, // 4 lim  1 Slope
              CATFrFImplicitProfileConic3_3Lim2Tan                  = 3, // 3 lim  2 Slopes
              CATFrFImplicitProfileConic4_2Lim2Tan1Rho              = 4, // 2 lim  2 Slopes  1 Rho Law

              // Type interpol
              CATFrFImplicitProfileInterpol1_Any                    = 1,

              // Type blend
              CATFrFImplicitProfileBlend1_Any                       = 1

             }CATFrFImplicitProfileType;

//                                                         // Si tout est bien code, ne genere pas de KO ODT
//                                                         // mais l'absence de KO ODT ne prouve pas que tout est bien code
//                                                         // un KO provient d'une mauvaise definition, sans utilisation de l'enumeration,
//                                                         // d'une option d'evaluation
#ifdef  CATFrFBlendProfileCx2_ForceStressTestOptionForEvalAll 
//                                                         // N.B 5 OK: les valeurs 0 a 4 decalees de 5 restent dans la plage [1,9],
//                                                         //           compatibles multiplexage de CATFrFSweepCanonicProfileCx2::EvalDebug()
#define CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest 5
#else
#define CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest 0 // ceci est le code standard
#endif
typedef enum {
              //  0 = complet                         <-- commentaire JSX issu de CATFrFBlendProfileCx2
              //  1 = sans loi d'angle                <-- commentaire JSX issu de CATFrFBlendProfileCx2
              //  2 = Loi angulaire mais sans smooth  <-- commentaire JSX issu de CATFrFBlendProfileCx2
              //  3 et 4 sont plus obscurs avec micmac entre smooth actif/inactif et bug d'application du smooth
              //  3 = sans loi d'angle   sans smooth  <-- commentaire NLD d'apres le code
              //  4 = equivalent a 2 on dirait        <-- commentaire NLD d'apres le code
              //  N.B le codage des options est specifique Blend et l'on trouve des appels ne precisant pas de code
              //      ex: CATFrFImplicitProfileCx2::GetOneCurve()
              //      il est donc importantissime que le code 0 corresponde toujours au traitement standard.
              //      En consequence aussi, je laisse cette valeur fixe meme dans le cadre de mes StressTests  NLD161115
              //      Mais dans un second temps je fais en sorte de migrer tous les appels y compris
              //      ceux deduits d'un SetFastEval(0) (qui devient SetFastEval(CATFrFBlendProfileCx2_OptionForEvalAll_0_Full))
              //      et dans ces conditions je peux liberer aussi cette valeur                                NLD171115
              CATFrFBlendProfileCx2_OptionForEvalAll_0_Full                   = 0     + CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest,
              CATFrFBlendProfileCx2_OptionForEvalAll_1_NoAngularLaw           = 1     + CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest,
              CATFrFBlendProfileCx2_OptionForEvalAll_2_NoSmooth               = 2     + CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest,
              CATFrFBlendProfileCx2_OptionForEvalAll_3_NoAngularLaw_BugDomain = 3     + CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest,
              CATFrFBlendProfileCx2_OptionForEvalAll_4_Full_BugDomain         = 4     + CATFrFBlendProfileCx2_OptionForEvalAll_DeltaForStressTest
             }CATFrFBlendProfileCx2_OptionForEvalAll;

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFImplicitProfile :public CATFrFGeneralizedProfile
{
 public :

                    //CATFrFImplicitProfile     (CATSoftwareConfiguration *  iConfig             = 0);
                      CATFrFImplicitProfile     (CATFrFObject              & iFrFObject          );
                      CATFrFImplicitProfile     (CATGeoFactory            *  iFactory            ,
                                                 CATSoftwareConfiguration *  iConfig             );

   virtual           ~CATFrFImplicitProfile     ();

    // 1) Derivation des methodes de CATFrFGeneralizedProfile
    //    ---------------------------------------------------
    // N.B beaucoup sont derivees directement dans l'implementation CATFrFImplicitProfileCx2 sans l'etre ici

   virtual CATCurve * GetOneCurve               (int                         iIndex              )               = 0;

    // 2) Methodes specifiques
    //    --------------------
   virtual void       SetShapeConstraints       (int                         iNumberOfConstraints,
                                                 CATFrFShapeConstraint   **  iConstraints        )               = 0;

    // N.B            SetProfileType() et GetProfileType() sont en fait des acces au sous-type de profil
    //                defini pour chaque type par une enumeration specifique (ci-dessus)
    //                (l'enumeration des types de segments, celle des types de cercles, ...)
    //                en aucun cas le type principal (segment/cercle/blend...)
    //                Dans ces conditions GetProfileType() n'a pas specialement d'interet a ce jour
    //                Mais on pourrait dorenavant fournir une methode rendant une valeur dans l'enumeration
    //                CATCanonicProfileSweep::CATCanonicProfileSweepType
    //                ce que je fais avec GetCanonicSweepType()
    //                NLD171115
   virtual void       SetProfileType            (int                         iType               )               = 0;

   virtual int        GetProfileType            ()                                                               = 0;

   // Donne le type de Sweep, dans l'enumeration CATCanonicProfileSweep::CATCanonicProfileSweepType
   // (pour le sous-type, soit en fait le CaseNumber, voir GetProfileType() ci-dessus)
   virtual int        GetCanonicSweepType()                                                                      = 0;

   virtual CATBoolean IsRational                ()                                                         const = 0;


   virtual CATBoolean IsEvalFirstDerivAvailable ()                                                               = 0;

// format de sortie CATMathSetOfVectors correspondant a CATMathSetOfPoints pour Eval(), jamais concretise. en commentaires NLD030317
// virtual CATBoolean EvalFirstDeriv            (double                      iT                  ,
//                                               CATMathSetOfVectors      *  iDer1               )               = 0;

   virtual CATBoolean EvalFirstDeriv            (double                      iT                  ,
                                                 double                   *  iDer1               )               = 0;

   // N.B le couple   DataForNextEval()/DataFromLastEval() existe pour les shapes,
   //                 mais seul         DataFromLastEval() existe pour les profils. NLD241115 
   virtual void       DataFromLastEval          (int                         iDataIndex          ,
                                                 CATLONG32                *  oTLong              ,
                                                 double                   *  oTDouble            )               = 0;

   virtual CATBoolean GetConstraintArray        (int                      *  ioConstraint        )         const = 0;

   virtual void       SetSmoothOption           (int                         iOption             ,
                                                 CATListOfInt             *  iFixedNormalVertex  = NULL  )       = 0;

   virtual void       SetSmoothAngleThreshold   (double                      iAngle              )               = 0;

   // N.B iParameterRatio est logiquement dimensionne a [3] et non plus [2] depuis Dec2008
   //     je change la signature en consequence le 09/12/15. NLD
   //     On trouve aussi dans les implementations la notation iProfileParamToCrvParam au lieu de iParameterRatio
   //     Contient:
   //      iParameterRatio[0]: longueur
   //      iParameterRatio[1]: largeur moyenne
   //      iParameterRatio[2]: mode (0 ou 1) directement transmis apres traduction en entier a CATFrFScaleCurvature
   //     NLD091215
   virtual void       SetSmoothedCurvature      (CATLONG32                   iCote               ,
                                                 CATFrFCompositeCurve     *  iCcvSmothedCurvature,
                                                 double                      iParameterRatio  [3],
                                                 CATLaw                   *  i_iT_to_W           )               = 0;

   virtual void       SmoothNormal              ()                                                               = 0;

   //                <@BlendOnly>
   virtual void       ComputeLawThetaFromDir    (CATLONG32                   iDom                ,
                                                 double                      iT                  ,
                                                 CATLONG32                   iRef                ,
                                                 CATMathVector            *  Dir                 ,
                                                 double                    & oAngle              )               = 0;

   // To get G0 shape on G0 parameter (G-1 otherwise)  
   //                <@BlendOnly>
   virtual void       ComputeG0RecoverValue     (CATFrFSweepShape         *  iShape              ,
                                                 int                         iDiscType           ,                      // NLD011215 ancienne notation iType
                                                 double                      iT                  ,
                                                 int                         iDom             [2],
                                                 double                   *  ioRecValue          ,
                                                 int                      *  ioRecEff            ,
                                                 int                       & oNbLaw              
                                                )                                                                = 0;

   //                <@BlendOnly>
   virtual void       SetG0RecoverLaw           (CATLONG32                   iDiscType           ,
                                                 CATLONG32                   iNbLaw              ,
                                                 CATLaw                  **  iG0Law              )               = 0;

   //                <@BlendOnly>
   // la methode semble n'avoir ete definie dans CATFrFImplicitProfile que pour les besoins du Blend.                   NLD181115
   // mais on a affaire a un protocole general a instanciation specifique
   // apparemment, seule valeur possible au 18/11/15
   // iType : 1 pour pointe laterale, avec
   //         iLongData[0]: cote de la pointe
   //         iDoubleData   inutile
   virtual void       SetDataForOneDomain       (CATFrFSweepShape         *  iShape              ,
                                                 CATLONG32                   iType               ,
                                                 CATLONG32                   iDom                ,
                                                 CATLONG32                *  iLongdata           ,
                                                 double                   *  iDoubleData         )               = 0;

   //                 <@SegmentProfileOnly> 
   virtual void       SetRoadWidthOption        (int                         iOption             )               = 0;

};
#endif

