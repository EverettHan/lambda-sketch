// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
//
// CATBreakInfo:
//   Utility for section Deformation 
//
//                                                    Christophe Pradal
//=============================================================================
// Usage notes:
//
// Configuration et options de deformation
// ---------------------------------------
//   Reference: Objectif de deformation donne par l'utilisateur
//   Both: On deforme les 2 elements jointifs en calculant un objectif de deformation
//  
//   G1 Isopar : Au point de deformation, la section est G1
//               (les isopars entre les surfaces seront G1/G2)
//   G2 Isopar : Au point de deformation, la section est G2
//   G1 Surface: Au point de deformation, les surfaces qui seront generees seront G1
//   G2 Surface: Au point de deformation, les surfaces qui seront generees seront G2
//   
// Informations necessaires:
// ------------------------
//   Reference: _Guide != 0(_Continuity == all)
//              _LongitudinalTgt == 0
//   Both: Si G1/G2 Isopar => _Guide == _LongitudinalTgt == 0
//         Si G1/G2 Surface=> _Guide == 0
//                            _LongitudinalTgt != 0
//
// Specifications:
// --------------
//  * si >_IsOnGuide == TRUE, on ne doit pas modifier la position du point
//  * en mode both, il faut gerer la deformation autour de la fermeture
//  * 0 <= _DeformEffectivity <= 1
// 
//=============================================================================
// 30 08 99 CPL Creation
// 01 12 00 CPL Modification: Suppression des Multiformes
// 31 05 02 MNA Modification de _Guide : ce n'est plus une CATPCurve mais une
//              CATCurve (Dans le cas des peigne 3Dmixcomb, on a une curve)
// 29 08 02 MNA Ajout des donnees relatives au Smooth des courbes guides dans le Loft.
// 20 09 02 MNA Ajout des methodes de paassage des donnees membres (donnees membres mises
//              en protected).
//                -SetInfoAboutGuide()
//                -SetInfoAboutComb()
//                -SetInfoForSmooth()
// 01 10 03 JSX Ajout de _SmoothedComb et _CCVMaping (Peigne de normale C1 Loft et Unspect)
// 27 11 03 JSX Ajout _SmoothCcv
// 31 08 06 JSX Ajout de MathPoint dans l'interface de EvalExternalConstraint
// 2x 03 10 JSX EvalExternalConstraint decoupé en EvalTangencyExternalConstraint EvalCurvatureExternalConstraint
// 08 04 10 JSX _DeformEffectivity devient _Deform[G1]Effectivity et CurvatureEffectivity=> DeformBalance
//              ajout de _DeformG2Effectivity
// 11 05 10 JSX SetReferenceContinuity iRefference (bool) devient un CATFrFContinuity 
// 04 11 10 JSX CopieConstructeur et Affection sont interdits (en private)
//              La copie d'un BreakInfo pointant sur des ccvs est assez dangereuse et pas vraiment utile
//              j'interdis maintenant cette possibilité
// 12 11 10 JSX CGMlevel dans le constructeur, suppression de CATBreakInfo_NoCopy, Menages
// 01/07/14 NLD Changement d'interface de EvalTangencyExternalConstraint() qui desormais remplit
//              le plan fourni au lieu d'en allouer un
// 09/12/15 NLD L'argument iProfileParamToCrvParam de SetSmoothedCurvature() est dimensionne a [3] et non [2]
//              (pour remise en conformite avec son usage reel depuis Decembre 2008)
// 11/05/16 NLD GetReferenceContinuity() remplace Reference()
//=============================================================================

#ifndef CATBreakInfo_H
#define CATBreakInfo_H

#include "FrFAdvancedObjects.h"

#include "CATPGMBreakInfo.h"

#include "CATMathDef.h"
#include "CATMathDiagnostic.h"
#include "CATMathDirection.h"

#include "CATCrvParam.h"

#include "CATFreeFormDef.h"

class CATMathVector;
class CATMathPlane;
class CATLaw;
class CATCurve;
class CATFrFCompositeCurve;
class CATFrFCompositeCurveMapping;
class CATFrFNormalMultiComb;
class CATFrFSmoothedComb;
class CATFrFScaleCurvature;

//=============================================================================
enum BreakContinuity { G1Iso, G1Sur, G2Iso, G2Sur };
//=============================================================================

class ExportedByFrFAdvancedObjects CATBreakInfo : public CATPGMBreakInfo
  {
  // Constructeur Destructeur
  public: 
             CATBreakInfo(CATLONG32 iCGMLevel);
    virtual ~CATBreakInfo();
  private:
             CATBreakInfo              (const CATBreakInfo &iCATBreakInfo) {;};
             CATBreakInfo & operator = (const CATBreakInfo &iCATBreakInfo) {return *(new CATBreakInfo(0));};


  public:

    //-------------------------------------------------------------------------
    // Set Global
    void SetIsOnGuide(CATBoolean iIsOnGuide)
      {
       _IsOnGuide = iIsOnGuide;
      }

    //-------------------------------------------------------------------------
    void SetGuideRank(int iGuideRank)
      {
       _GuideRank = iGuideRank;
      }

    //-------------------------------------------------------------------------
    void SetWithReferencePlane(CATBoolean iWithReferencePlane)
      {
       _WithReferencePlane = iWithReferencePlane;
      }

    //-------------------------------------------------------------------------
    void SetReferenceContinuity(CATFrFContinuity iReferenceG1G2=0) // 0=G0/1=G1/2=G2/
      {
       _ContinuityOnGuide = iReferenceG1G2;
      }

    //-------------------------------------------------------------------------
    void SetTangentOnGuidePoint(CATMathPlane *iGuidePointTgtPlane)
      {
       _GuidePointTgtPlane = iGuidePointTgtPlane;
      }

    //-------------------------------------------------------------------------
    void SetMultiComb(CATFrFNormalMultiComb *iMultiComb)
      {
       _MultiComb = iMultiComb;
      }

    //-------------------------------------------------------------------------
    void SetSmoothInfo       (      CATFrFCompositeCurve        * iSmoothCcv[2]);
    //-------------------------------------------------------------------------
    void SetSmoothInfo       (      CATFrFCompositeCurve        * iSmoothCcv   ,
                                    CATFrFCompositeCurveMapping * CCVMapping   ,
                              const CATListOfInt                & iShiftMap    ,
                              const CATListOfDouble             & iShiftParam  );
    //-------------------------------------------------------------------------
    void SetSmoothedCurvature(      CATFrFCompositeCurve        * iSmoothedCurvature       ,
                                    double                        iProfilParamToCrvParam[3], // [3] et non plus [2] depuis Dec2008. NLD091215
                                    CATLaw                      * i_iT_to_W    );


    //-------------------------------------------------------------------------
    // Get Global
    //-------------------------------------------------------------------------
    CATBoolean IsOnGuide()
      {
       return _IsOnGuide;
      }

    //-------------------------------------------------------------------------
    int GuideRank()
      {
       return _GuideRank;
      }

    //-------------------------------------------------------------------------
    CATMathPlane* TransversalTgt()
      {
       return _GuidePointTgtPlane;
      }

    //-------------------------------------------------------------------------
    CATBoolean WithReferencePlane()
      {
       return _WithReferencePlane;
      }

    //-------------------------------------------------------------------------
    CATLONG32 GetReferenceContinuity() // NLD110516 anciennement Reference()
      {
       return _ContinuityOnGuide;
      }

    //-------------------------------------------------------------------------
    CATBoolean IsCombSmoothed() 
      {
       return _IsSmooth;
      }

    //-------------------------------------------------------------------------
    // 0:: defaut 1::_SmoothCcv  2::_SmoothedComb
    int SmoothMode()
      {
       return _SmoothTangentMode;
      }


    // SetGet pour les evaluations
    //============================

    // Set avant chaque evaluation

    //-------------------------------------------------------------------------
    void SetDeformG1Effectivity(double iDeformG1Effectivity)
      {
       _DeformG1Effectivity = iDeformG1Effectivity;
      }

    //-------------------------------------------------------------------------
    void SetDeformG2Effectivity(double iDeformG2Effectivity)
      {
       _DeformG2Effectivity = iDeformG2Effectivity;
      }

    //-------------------------------------------------------------------------
    void SetDeformBalance      (double iDeformBalance)
      {
       _DeformBalance = iDeformBalance;
      }

    //-------------------------------------------------------------------------
    void SetInfoAboutGuide     (CATCurve * iGuide, CATCrvParam &iParamOnGuide);
    //-------------------------------------------------------------------------
    void SetInfoAboutComb      (CATLONG32 iPeigneIndex);
    //-------------------------------------------------------------------------
    void SetInfoForSmooth      (CATLONG32 iSmoothDomainIndex ,
                                double    iParamForSmoothData,
                                CATLONG32 iSmoothGuideIndex  );


    //-------------------------------------------------------------------------
    // Get
    //-------------------------------------------------------------------------
    double DeformG1Effectivity()
      {
       return _DeformG1Effectivity;
      }

    //-------------------------------------------------------------------------
    double DeformG2Effectivity()
      {
       return _DeformG2Effectivity;
      }

    //-------------------------------------------------------------------------
    double DeformBalance()
      {
       return _DeformBalance;
      }

    //-------------------------------------------------------------------------
    void              EvalPointExternalConstraint    (CATMathPoint     *  ioGuidePoint);
    //-------------------------------------------------------------------------
    CATMathDiagnostic EvalTangencyExternalConstraint (CATMathPlane      & oTangentPlane); // NLD010714 (CATMathPlane     *& ioTangentPlane);
    //-------------------------------------------------------------------------
    void              EvalCurvatureExternalConstraint(CATMathDirection  & iDirOnTgPlane, CATMathVector &oCurvature);

    //-------------------------------------------------------------------------
    void GetUsedCurvature(double &LastEvalCurvature,CATMathVector & LastEvalCurvatureVector);

    //========================================================
    // DATA
    //========================================================

  private:

    CATLONG32                     _CGMLevel;

    CATBoolean                    _IsOnGuide;                // indique si le vertex est sur une guide
    int                           _GuideRank;                // indice de la guide between 1 to n
    CATLONG32                     _ContinuityOnGuide;        // Continuite a respecter
    CATBoolean                    _WithReferencePlane;       // Guide avec tangence definie par un plan => ne pas aller chercher les pcurves
    CATMathPlane                * _GuidePointTgtPlane; 

    // Break correspondant a un point interne
    //    Effectivités & Balance 
    double                        _DeformG1Effectivity;      // anciennement _DeformEffectivity // 
    double                        _DeformG2Effectivity;
    double                        _DeformBalance;            // anciennement CurvatureEffectivity;


    // Break correspondant sur une guide
    //   Smooth General
    CATBoolean                    _IsSmooth;                 // 0: non eval sur le multicomb, 1: smooth en fonction de _SmoothTangentMode  

    //   Smooth de la normale
    int                           _SmoothTangentMode;        // 0:: defaut 1::_SmoothCcv  2::_SmoothedComb
   
    //   _IsSmooth==0) Utilisation du Multicomb
    CATFrFNormalMultiComb       * _MultiComb;
    int                           _CombIndex;

    // _SmoothTangentMode==2) Sur une Guide representant un peigne
    CATCurve                    * _GuideCrv;
    CATCrvParam                   _ParamOnGuide;   
    CATFrFSmoothedComb          * _SmoothedComb;
    CATFrFCompositeCurveMapping * _SmoothedCombCCVMapping;   // utilisé par SmoothedComb

    // _SmoothTangentMode==1) Sur un couple de guides smoothées representant un peigne 
    CATFrFCompositeCurve        * _SmoothCcv[2];
    double                        _SmoothParam;     
    int                           _SmoothGuideIndex;         // pour le smooth des combs de tangence (parametre par la guide)
    int                           _SmoothDomainIndex;        // pour le smooth des combs de courbure (parametre par la spine)

    // Smooth de la courbure
    int                           _SmoothCurvatureMode;      // 0:: pas de smooth 1:: Smooth
    CATFrFScaleCurvature        * _OpeCurvature;
    CATFrFCompositeCurve        * _SmoothedCurvature;        // ccv representant la courbure lissée
    double                        _SmoothedCurvaturePP2CP[2];// Ratio de parametrage 
    CATLaw                      * _SmoothedCurvaturePLaw;    // Loi de rattrapage de la déformation provoquée par le clean 

    // Memorisation de la coubure
    double                        _LastEvalCurvature ;
    CATMathVector                 _LastEvalCurvatureVector;
  } ;
#endif 
