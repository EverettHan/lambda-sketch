// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATSectionDeformEngine:
// Utility for sweep section computation by external solver
//
//                                                    Christophe Pradal
//=============================================================================
// Usage notes:
//
// remarque: les NurbsMultiForm ont ete reorientees avant l'appel
// à l'evaluateur de maniere a ce que la fin de l'une soit le debut de
// la suivante

// remarque: cette classe doit permettre
//  - de realiser une implementation du sweep variationnel
//  - de realiser de maniere externe les mises en continuite pour les lofts

//
//=============================================================================
// 22 09 99 CPL Creation
// 25 02 04 MNA Modif : Ajout de SetTangentInfo( int iIsTangent =1) et _IsTangent
// 14 09 04 JSX Ajout de InitializeSections_Loft
// 31 08 06 JSX Ajout de SetPointDeformation.
//              Deformation des profils avant la construction des nurbs d'interpolation dans le repere local.
//              On les "colle" sur les guides par une deformation en point, le G1 est conservé grace au similar.
//              Ce n'est pas le cas du recalage complet actuel de sweepcrvcrv qui peut casser le G1
// 08 04 10 JSX Deformation G2 + Meneage de nomenclature (keepG1/KeepG2/Balance)
// 28 09 10 JSX Ajout de SetExternalMaxContinuity SetExternalCorrectionMode SetInternalContinuity
//              Pour mieux gerer les deformations du loft
// 03 11 10 JSX Ajout argument nbBreak au constructeur et a GetBreakInfo (verif de taille du tableau)
//              Suppression de SetBreakInfo
// 16 11 10 JSX Ajout de GetExternalCurvatureUsed
// 06 06 11 NLD EvalCourbureOnExtremitiesOfNurbsCurve() renommée en EvalCurvatureOnExtremitiesOfNurbsCurve()
// 25 06 13 NLD Ajout ComputeLawsControl()
//              Smart indent
//=============================================================================
#ifndef CATSectionDeformEngine_H
#define CATSectionDeformEngine_H

#include "FrFOpeCrv.h"
#include "CATSectionSolverEngine.h"
#include "CATGeoFactory.h"
#include "CATFreeFormDef.h"
class CATSectionDeformation;
class CATSoftwareConfiguration;
class CATLaw;
class CATBreakInfo;
class ExportedByFrFOpeCrv CATSectionDeformEngine : public CATSectionSolverEngine
  {
  public:

                           CATSectionDeformEngine                (      CATGeoFactory           *  iFactory                 ,
                                                                        CATSoftwareConfiguration*  iConfig                  ,
                                                                        CATBreakInfo           **  iBreakInfo               ,
                                                                        CATLONG32                  nbBreak                  );

    virtual               ~CATSectionDeformEngine                ();

    // methode supplémentaire pour le loft
    // a appeler avant InitializeSections
    // indique les courbes degenerees dans les profils (cas des pointes)
    // iTabCrvDegener apartient a l'appelant. il doit survivre jusqu'a InitializeSections
    virtual void           InitializeSections_Loft               (      int                    **  iTabCrvDegener           );

    // Methode Specifique au loft
    // Mode ou l'on prend en compte la deformation en point necessaire pour
    // plaquer les profils sur les guides
            void           SetExternalMaxContinuity              (      CATFrFContinuity           iMaxExternalContinuity   = CATFrFCurvatureCont);
 // virtual void SetPointDeformation(CATBoolean iPointDeformationMode = TRUE);

    // mode de correction 1 projection sur le plan tangent // 2 Rotation dans le plan du MvFrame
            void           SetExternalCorrectionMode             (      CATLONG32                  iExtCorrectionMode       = 1);
    //virtual void SetPointDeformation(CATBoolean iPointDeformationMode = TRUE);

    // LoftG2 Activation de la deformation G2 Interne (Historiquement G1)
            void           SetInternalContinuity                 (      CATFrFContinuity           iInternalContinuity      );

            void           InitializeSections                    (      int                        iNbImposedSections       ,
                                                                        double                  *  iParamsForImposedSections,
                                                                        int                        iNbElementsPerSection    ,
                                                                        CATFrFNurbsMultiForm  ***  iImposedSections         ,
                                                                        CATBoolean                 isClosed                 = CATBoolean(0));

    // Passage du peigne de tangence aux profils extremites:
    //   iFirst0OrLast1= 0 pour le premier profil
    //   iFirst0OrLast1= 1 pour le dernier profil
    // Les peignes de tangence peuvent etre utilises
    // pour le calcul global des lois.

            void           SetTangents                           (      int                        iFirst0OrLast1           ,
                                                                  const CATMathVector           *  iVectors                 );

            void           SetTangentInfo                        (      int                        iFirst0OrLast1           ,
                                                                        int                        iIsTangent               = 1);

    // Imposition du MovingFrame
            void           SetMovingFrame                        (      CATFrFMovingFrame       *  iMovingFrame             );


    // 2) Methodes a appeler en cours de cheminement
    ////////////////////////////////////////////////

    // Les informations des BreakPoints ne sont pas toujours utiles.
    // Methode separee de l'Eval.
    ////JSX041110 void  SetBreakInfo( CATBreakInfo** iBreakInfo );

    // A VOIR: passage des guides et des parametres sur celles-ci
    // virtual 
    // remarque: on supprimera le passage du plan une fois le movingframe exporté

            void           EvalSection                           (      double                     iParam                   ,
                                                                  const CATMathPlane             & iSectionPlane            ,
                                                                        CATFrFNurbsMultiForm  **   iInitialSection          ,
                                                                        CATFrFNurbsMultiForm  **   oFinalSection            );

    // Tolerance en point uniquement pour le moment
            void           SetTol(double *TabTol);

            void           EvalCurvatureOnExtremitiesOfNurbsCurve(      CATFrFNurbsMultiForm    *  iNurbs                   ,
                                                                        int                        iExtr                    ,
                                                                        double                   & oCurvature               ,
                                                                        CATMathVector            & oCurvatureVector         );

            CATBreakInfo** GetBreakInfo                          (      CATLONG32               *  nbBreak                  = NULL);

            void           GetExternalCurvatureUsed              (      double                   & StartCurvature           ,
                                                                        CATMathVector            & EndCurvatureVector       ,
                                                                        double                   & EndCurvature             ,
                                                                        CATMathVector            & StartCurvatureVector    );

  private:

            void           ComputeLaws                           (      CATLONG32                  iNbProfiles              ,
                                                                        double                  *  iProfilParams            ,
                                                                        CATFrFNurbsMultiForm  ***  iProfiles                );
            void           ComputeLawsControl                    (      CATLONG32                  iNbProfiles              ,
                                                                        double                  *  iProfilParams            ,
                                                                        CATFrFNurbsMultiForm  ***  iProfiles                );
    //===========================
    // DATA
    //===========================
  private:

    CATGeoFactory            * _Factory;
    CATSoftwareConfiguration * _SoftwareConfig;
    CATLONG32                  _CGMLevel;

    double                     _TolG0;

    CATLONG32                  _NbElt;                        // Nb of Section (Profile) elements
    CATLONG32                  _NbVertices;                   // Sum of all numbers of vertices in each element
    CATBoolean                 _Closed;                       // Is the section closed?
    CATBreakInfo            ** _BreakInfo;                    // Array of Break Info fill by the calling
    CATLONG32                  _NbBreak;                      // nb de breakinfo (un peu redondant, mais permet des verifications)

    CATSectionDeformation    * _Engine;                       // Internal engine used to deform each section
    CATLONG32                  _TargetProfilContinuity;       // Continuité interne du profil demandé par l'application
    CATBoolean                 _ForceG1OnlySimilarCorrection; // Gap trop grand en G2 le similar ne fear que du G1
    CATLONG32                  _ExtCorrectionMode;            // 1: projection 2: rotation


    CATLONG32                  _NbLaws;
    CATLaw                  ** _KeepG1Laws;                   // are used to compute a G1 Deformation (replaces _Laws)
    CATLaw                  ** _KeepG2Laws;                   // are used to compute a G2 Deformation
    CATLaw                  ** _BalanceLaws;                  // Proportion des (demi)Tangences initiales  pour le calcule de la tangence objectif


    CATLONG32                * _SplitIndices;
    int                        _IsTangent[2];
    int                     ** _TabCrvDegener;                // indique les zones degenerées

  } ;
#endif
