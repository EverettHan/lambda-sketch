#ifndef CATFrFShapeConstraint_H
#define CATFrFShapeConstraint_H

// #define CATFrFShapeConstraint_StressTestOnContinuity "TEST ONLY NLD140218 pour validation du 140218 - VERSION NON LIVREE"

// COPYRIGHT DASSAULT SYSTEMES 1997 
//==========================================================================
//
// CATFrFShapeConstraint:
// Interface class of FrF Shape Constraint Object.
//
//==========================================================================
//
// Usage notes:
// This class can be used as is for simple Shape Constraint or derived
// in order to implement specific algorithm or capabilities.
//
// A Shape Constraint is a set of :
//   1 Geometry
//   2 Angular laws ( Phi, Theta)
//   1 Radius Law
//   1 ContinuityMode
//   1 Support Orientation
//   1 Ccv (Curve) Orientation
//========================================================================== 
//   May 97 tpg Creation                                          Tuan Phung
// 06 02 02 MNA Ajout des methodes Set et GetRelimitingPlane.
// 11 02 02 MNA Ajout des methodes AngularLawIsExtrapolate et 
//              IsAngularLawExtrapolated, elles permettent de notifier l'extrapolation 
//              de la loi d'angle, et de recuperer l'information.
// 27/04/04 jsx Ajout SetAreaLaw()/GetAreaLaw() et SetType()/GetType()
// 15/10/15 NLD Mise au propre.
//              - Smart indent
//              - reordonnancement
//              Ajout CATFrFShapeConstraint_Type
//              Ajout des methodes relatives aux lois de tension
//              (anciennement seulement dans la classe derivee CATFrFShapeConstraintCx2)
//              GetTensionLawDsDu(),   SetTensionLawDsDu()
//              GetTensionLawD2sDu2(), SetTensionLawD2sDu2()
// 30/05/17 NLD Renommage de iType en iAngleType
//              Migration des definitions de types depuis CreateFrFShapeConstraint.h
//              Ajout SetRhoLaw(), GetRhoLaw() (auparavant: Rho gere via SetRadiusLaw(). GetRadiusLaw())
// 31/05/17 NLD Ajout SetScalingLaw(), GetScalingLaw()
//              Ajout SetLengthLaw1(), GetLengthLaw1() et SetLengthLaw2(), GetLengthLaw2()
//              (anciennement dans la derivation CATFrFSweepConstraintCx2)
// 02/06/17 NLD Ajout d'une deuxieme loi de rayon:
//              - ajout de SetRadiusLaw2(), GetRadiusLaw2()
// 27/06/17 NLD Suite du demelage du noeud des valeurs de contraintes
//              Typage plus fort: distinction CATFrFShapeConstraint_Type/CATFrFShapeConstraint_AngleType
//              Suppression des arguments iAngleType et iAngleRef de SetGeometry()
// 13/02/18 NLD Renommage de ContinuityMode en FrFContinuityMode
//              Définition explicite de toutes les valeurs de cette énumération
//              Commentaires détaillés sur les faiblesses et les risques de cette énumération
//              Deflaggage
// 14/02/18 NLD Ajout convertisseurs FrFGContinuityConvertor(), FrFCContinuityConvertor(), FrFContinuityLevel()
//========================================================================== 


#include "FrFAdvancedObjects.h"
#include "CATCGMVirtual.h"
//
// #include "CreateFrFShapeConstraint.h"

#include "CATMathDef.h"
#include "CATMathDirection.h"
#include "CATLISTV_CATMathPoint.h"

//
class CATGeometry;
class CATLaw;
class CATMathPlane;

//-----------------------------------------------------------------------------
// Enumeration(s) pour les types de contraintes
//-----------------------------------------------------------------------------
// - V0 NLD151015 d'apres informations de  CATFrFShapeConstraintCx2 // 0: (defaut)  guide ( profile ?) // 1 Moving Frame // 2 Contrainte d'aire
//   (en fait ceci me parait tres tres incomplet voire inexact. NLD300517)
//
//    V0 premiere serie de valeurs  NLD151015
//    ----------------------------
//    CATFrFShapeConstraint_Type0_Default,
//    CATFrFShapeConstraint_Type1_MovingFrame,
//    CATFrFShapeConstraint_Type2_Area
//
//    N.B l'usage  de CATFrFShapeConstraint_Type1_MovingFrame
//        et       de CATFrFShapeConstraint_Type2_Area
//        est limite a CATCrvCrvSweepCx2 et CATFrFSweepCrvCrvCx2
//        et les acces y sont faits via SetType() et GetType() respectivement
//
// - V1 NLD300517 d'apres informations de CreateSweepConstraint_6 et CATFrFConicProfileCx2
//
//    V1 deuxieme serie de valeurs  NLD300517
//    ----------------------------
//    CATFrFShapeConstraint_AngleType0_Default
//    CATFrFShapeConstraint_Type1_FunctionalGuide
//    CATFrFShapeConstraint_Type2_Surface
//    CATFrFShapeConstraint_Type3_RefElem
//    autres valeurs d'apres CreateSweepConstraint_6 dans CreateFrFShapeConstraint.h
//    a terme il faudra changer les valeurs pour eviter tout conflit avec les valeurs ci-dessus
//    tout cela n'etant pas encore tres clair.      NLD270617
//    les valeurs qui suivent sont utilisees dans CATCanonicProfileSweepCx2 et CATFrFConicProfileCx2
//    la lecture depuis CATFrFConicProfileCx2 est faite par GetAngleType()
               //
//    N.B on trouve des la version historique de CATFrFSweepConstraintCx2.h de 2000,
//        (et encore a ce jour) des informations qui me semblent tout a fait sujettes a caution
//        pour la documentation de la variable _Type devenue _AngleType
//        The vector is an angular reference.
//          type= 1 PCurve
//          type= 2 Surface
//          type= 3 plan
//          type= 4 vecteur == Y du MF
//          type= 5 Body contenant au moins deux Cells
//
//       on trouve encore l'enumeration suivante dans le CreateSweepConstraint_1 de CreateFrFShapeConstraint.h
//          iType==1 => surface for angle law == PCurve surface
//          iType==2 => surface == iGeometry
//          iType==3 => surface == plan
//          iType==4 => iAngleRef is needed
//          iType==5 => Body (shell)
//
//
// - V2 NLD270617 distinction des deux enumerations
typedef enum {
               CATFrFShapeConstraint_Type0_Default              = 0, // doit rester nulle
               CATFrFShapeConstraint_Type1_MovingFrame          = 1,
               CATFrFShapeConstraint_Type2_Area                 = 2
             }
               CATFrFShapeConstraint_Type;
typedef enum {
               CATFrFShapeConstraint_AngleType0_Default         = 0, // doit rester nulle
               CATFrFShapeConstraint_Type1_FunctionalGuide      = 1, // autre valeur 1 d'apres CreateSweepConstraint_6
               CATFrFShapeConstraint_Type2_Surface              = 2, // autre valeur 2 d'apres CreateSweepConstraint_6
               CATFrFShapeConstraint_Type3_RefElem              = 3  // autre valeur 3 dans CATFrFConicProfileCx2
             }
               CATFrFShapeConstraint_AngleType;

//-----------------------------------------------------------------------------
// Enumeration pour les continuites
//-----------------------------------------------------------------------------
// Deplacement depuis CreateFrFShapeConstraint.h NLD300517
//-----------------------------------------------------------------------------
typedef const char * CATShapeConstraintClassId;

// A noter:
// - au 130218 l'énumération ContinuityMode,
//   anciennement dans CreateFrFShapeConstraint, est inchangée
//   depuis 2000
// - il y a des conversions et des cast à la kéké dans un sens et dans l'autre, au moins dans CATGeometricBlendSurfaceCx2
// - il y a aussi des tests d'inegalité (beaucoup plus légitimes toutefois)
//   du moins pour trier par niveau de continuité entre FrFG0, FrFG1, FrFG2
//   mais pas pour les FrFG* et les FrFC* qui sont mal ordonnés les uns par rapport aux autres
// - NE SURTOUT PAS CHANGER L'ORDRE SANS PRECAUTION DONC
// - mais j'ajoute la définition, transparente, des valeurs, pour que tout soit bien clair au moins ici
// - et je renomme ContinuityMode en CATFrFContinuityMode pour identifier et controler toutes les utilisations
// - a ne pas confondre avec CATFrFContinuity et ses valeurs CATFrFNoCont CATFrFPointCont CATFrFTangentCont ...
// - ATTENTION ENCORE
//   on a FrFC1 < FrFG1 et FrFC2 < FrFG2 (ainsi d'ailleurs que FrFC0 < FrFG0) alors qu'en toute logique
//   cela devrait etre le contraire
//   MAIS reordonner ceci est une opération bien perilleuse
//   on trouve par exemple dans CATFrFExtrapolShapeCx2::ComputeData()
//   mais peut-etre aussi ailleurs
//       if (Continuity > FrFG0) (anciennement > 1)
//    et if (Continuity > FrFG1) (anciennement > 3)
//   soit du code bien moisi (que je reprends)
// - HEUREUSEMENT on semble n'utiliser partout que les FrFGi et non les FrFCi et encore moins les mélanges
// - voir marquage <@FrFContinuityMode_GeneralMarkUp_ToReview> pour tous les trucs pas nets dans les différents sources
//   voir marquage <@FrFContinuityMode_GeneralMarkUp_Fixed>    pour tous les trucs pas nets corrigés
// - utiliser si besoin les nouveaux convertisseurs FrFGContinuityConvertor(), FrFCContinuityConvertor(), FrFContinuityLevel()
// NLD130218
#ifndef CATFrFShapeConstraint_StressTestOnContinuity
// valeurs correspondant au code historique
typedef enum  {FrFC0 = 0,
               FrFG0 = 1,
               FrFC1 = 2,
               FrFG1 = 3,
               FrFC2 = 4,
               FrFG2 = 5} FrFContinuityMode;
#else
// valeurs pour detection des décodages abusifs, en particulier des divisions du mode par 2 pour avoir la continuité
typedef enum  {FrFC0 = 101,
               FrFG0 = 100,
               FrFC1 = 103,
               FrFG1 = 102,
               FrFC2 = 105,
               FrFG2 = 104} FrFContinuityMode;

#endif
// #define ContinuityMode FrFContinuityMode // alias transitoire devant disparaitre pour faciliter migration des utilisations

//-----------------------------------------------------------------------------
class ExportedByFrFAdvancedObjects CATFrFShapeConstraint : public CATCGMVirtual
{
  public :

  virtual                                 ~CATFrFShapeConstraint ();

  // Information methods

  virtual       CATShapeConstraintClassId  IsA                   ()                                                       const = 0;

  virtual       CATBoolean                 IsAKindOf             (const CATShapeConstraintClassId   iClassId         )    const = 0;

  //  Get Geometry 
  virtual const CATGeometry              * GetGeometry           ()                                                       const = 0;
  virtual       void                       SetGeometry           (const CATGeometry              *  iReference       )          = 0;

  // Get & Set Angular Laws
  virtual const CATLaw                   * GetAngularLawPhi      ()                                                       const = 0;
  virtual       void                       SetAngularLawPhi      (      CATLaw                   *  iAngularLaw      )          = 0;

  virtual const CATLaw                   * GetAngularLawTheta    ()                                                       const = 0;
  virtual       void                       SetAngularLawTheta    (      CATLaw                   *  iAngularLaw      )          = 0;

  // Renseignements sur l'extrapolation de la loi d'angle.
  virtual       void                       AngularLawIsHomogenous()                                                             = 0;
  virtual       CATBoolean                 IsAngularLawHomogenous()                                                             = 0;

  // Get & Set Radius Laws
  // --------------------
  virtual const CATLaw                   * GetRadiusLaw          ()                                                       const = 0;
  virtual       void                       SetRadiusLaw          (      CATLaw                   *  iRadiusLaw       )          = 0;

  virtual const CATLaw                   * GetRadiusLaw2         ()                                                       const = 0;
  virtual       void                       SetRadiusLaw2         (      CATLaw                   *  iRadiusLaw2      )          = 0;

  // Get & Set Area Law
  // -------------------
  virtual const CATLaw                   * GetAreaLaw            ()                                                       const = 0;
  virtual       void                       SetAreaLaw            (      CATLaw                   *  iAreaLaw         )          = 0;

  // Get & Set Tension Laws
  // --------------------- Non presentes dans cette classe mere avant le 15/10/15
  
  virtual const CATLaw                   * GetTensionLawDsDu     ()                                                       const = 0;

  virtual       void                       SetTensionLawDsDu     (      CATLaw                   *  iTensionLawDsDu  )          = 0;

  virtual const CATLaw                   * GetTensionLawD2sDu2   ()                                                       const = 0;

  virtual       void                       SetTensionLawD2sDu2   (      CATLaw                   *  iTensionLawD2sDu2)          = 0;

  // Get & Set Rho Law
  // ----------------- la loi de Rho etait geree par SetRadiusLaw()/GetRediusLaw() avant NLD300517
  virtual const CATLaw                   * GetRhoLaw             ()                                                       const = 0;
  virtual       void                       SetRhoLaw             (      CATLaw                   *  iRhoLaw          )          = 0;

  // Get & Set Scaling Law
  // ----------------- nouveaute NLD310517
  virtual const CATLaw                   * GetScalingLaw         ()                                                       const = 0;
  virtual       void                       SetScalingLaw         (      CATLaw                   *  iScalingLaw      )          = 0;

  // Get & Set Length Law 1 & 2
  // ----------------- nouveaute NLD310517 (anciennement dans CATFrFSweepConstraintCx2)
  virtual const CATLaw                   * GetLengthLaw1         ()                                                       const = 0;
  virtual       void                       SetLengthLaw1         (      CATLaw                   *  iLengthLaw1      )          = 0;
  virtual const CATLaw                   * GetLengthLaw2         ()                                                       const = 0;
  virtual       void                       SetLengthLaw2         (      CATLaw                   *  iLengthLaw2      )          = 0;


  // Get & Set RelimitingPlane
  // -------------------------
  virtual const CATMathPlane             * GetRelimitingPlane1   ()                                                             = 0;
  virtual       void                       SetRelimitingPlane1   (      CATMathPlane             *  iRelimitingPlane1)          = 0;

  virtual const CATMathPlane             * GetRelimitingPlane2   ()                                                             = 0;
  virtual       void                       SetRelimitingPlane2   (      CATMathPlane             *  iRelimitingPlane2)          = 0;

  // Get & Set Direction
  // -------------------
  virtual       void                       SetDirection          (      double                      iT               ,
                                                                        int                         iKind            ,
                                                                        CATMathDirection         *  iListDir         )          = 0;

  virtual       void                       GetDirection          (      CATListOfDouble           & iTDir            ,
                                                                        CATListOfInt              & iKind            ,
                                                                        CATListValCATMathPoint    & oListDir         )          = 0;

  virtual       void                       DeformLawToDir        ()                                                             = 0;


  // Get & Set Continuity Mode
  // -------------------------
  // Value : FrFG0, FrFG1, FrFG2, FrFC0, FrFC1, FrFC2
  // CAUTION: FrFContinuityMode values in bad order. NLD130218
  // By Default : FrFG0
  virtual const FrFContinuityMode          GetContinuity         ()                                                       const = 0;
  virtual       void                       SetContinuity         (      FrFContinuityMode           iContinuity      )          = 0;

  // continuity convertors (to avoid direct and dangerous conversions in code) NLD140218
  // 1) from continuity level 0, 1, 2 to FrFG0, FrFG1, FrFG2
  static        FrFContinuityMode          FrFGContinuityConvertor(     CATLONG32                   iContinuityLevel );
  // 2) from continuity level 0, 1, 2 to FrFC0, FrFC1, FrFC2
  static        FrFContinuityMode          FrFCContinuityConvertor(     CATLONG32                   iContinuityLevel );
  // 3) from       FrFG0, FrFG1, FrFG2 to 0, 1, 2
  //    and from   FrFC0, FrFC1, FrFC2 to 0, 1, 2
  static        CATLONG32                  FrFContinuityLevel     (     FrFContinuityMode           iContinuityMode  );

  // Get & Set Orientation
  // ---------------------
  // Value = +1 or -1
  // By Default : +1
  virtual       CATLONG32                  GetCurveOrientation   ()                                                       const = 0;
  virtual       void                       SetCurveOrientation   (      CATLONG32                   iOrientation     )          = 0;

  virtual       CATLONG32                  GetSupportOrientation ()                                                       const = 0;
  virtual       void                       SetSupportOrientation (      CATLONG32                   iOrientation     )          = 0;

  virtual       CATFrFShapeConstraint_Type GetType               ()                                                       const = 0;
  virtual       void                       SetType               (      CATFrFShapeConstraint_Type  iContType        )          = 0;
  };

#endif
