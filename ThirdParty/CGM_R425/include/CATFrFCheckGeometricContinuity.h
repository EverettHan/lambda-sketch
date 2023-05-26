// COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFCheckGeometricContinuity:
//
//==========================================================================
//
// Usage notes: Objet servant a tester la continuite geometrique (i.e en des 
// points discretises) entre des courbes et/ou des surfaces.
// L analyse est faite en des paires de points discretises (actuellement 
// equidistants), un sur chaque courbe.
//
//========================================================================== 
//    01/98 JBX Creation
// 08/12/03 MNA Ajout de _SoftwareConfig
// 20/06/22 NLD Smart indent; Documentation
// 21/06/22 NLD Instrumentation CGMReplay en escroc via macros CATFrFOperator
//              *** le filtre d'enregistrement (Keep=) doit etre strictement egal à CATFrFCheckGeometricContinuity ***
//                        - ajout RunOperator()
//                        - Run() devient de type int au lieu de void
//                        - ajout WriteInput()
//                                Dump()
//                                IsRecordable()
//                                RunOperator()
//                                WriteOutput()
//                                ValidateOutput()
//                                DumpOutput()
//                                CheckOutput()
//                                GetOperatorId()
//                                ReadOutput()
//                        - ajout _LoadedFromReplay
//                                _LoadingOperator
//                                _OperatorId
//                                _ScaleRatio
//========================================================================== 
#ifndef CATFrFCheckGeometricContinuity_H
#define CATFrFCheckGeometricContinuity_H

  #define ImplementCATFrFCheckGeometricContinuityCGMReplay

//-----------------------------------------------------------------------------
#include "FrFOpeUtil.h"

#include "CATCrvLimits.h"
#include "CATCGMVirtual.h"

#ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay
#include "CATCGMStream.h"
#include "CATFrFOperator.h"
#endif


class CATCurve;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATCartesianPoint;

#ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay
class CATFrFCheckGeometricContinuityReplay;
class CATFrFCheckGeometricContinuitySister;
class CATExtCGMReplay;
class CATFrFCheckGeometricContinuitySister;
#endif

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
class ExportedByFrFOpeUtil CATFrFCheckGeometricContinuity  : public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATFrFCheckGeometricContinuity);

 #ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay
  friend class CATFrFCheckGeometricContinuitySister;
 #endif

public :

    //-------------------  Basic Methods ------------------- 
    //  constructors
    CATFrFCheckGeometricContinuity(      CATGeoFactory            * iFactory ,
                                   const CATCurve                 * C1       ,
                                   const CATCurve                 * C2       ,
                                   const CATCrvLimits             & CL1      ,
                                   const CATCrvLimits             & CL2      ,
                                         CATSoftwareConfiguration * iSoftwareConfiguration=NULL);
  
    //  destructor
    virtual ~CATFrFCheckGeometricContinuity();
  
    //------------------- Data Access Methods -------------------  
  
    // Recuperation des resultats ; la methode Run doit avoir ete appelee
    // auparavant et le double Results doit DEJA etre alloue.
    // Results[0] = distance maximale entre 2 points
    // (anciennement documenté comme un carré de distance, mais c'était FAUX; NLD200622)
    // Results[1] = angle maximal entre les normales 
    // Results[2] = angle maximal entre les tangentes a la surface dans la
    //              direction orthogonale a la tangente a la courbe (la continuite
    //              C0 donnant deja l'information pour la direction de la tangente a la 
    //              courbe).
    // Results[3] = difference maximale entre les courbures gaussiennes
    // Results[4] = difference maximale entre les courbures gaussiennes 
    //              rapportee a la somme des valeurs absolues des courbures.
    void GetResults(double * Results) const ;
  
    // Recuperation des resultats ; la methode Run doit etre appelee apres
    // et le retour est alloue par la methode (a detruire donc).
    // Point[0] et Point[1] = distance maximale entre 2 points (carre de la distance)
    // Point[2] et Point[3] = angle maximal entre les normales 
    // Point[4] et Point[5] =  difference maximale entre les courbures gaussiennes 
    // ATTENTION:
    // je précise les informations et la logique Bouixiennes:
    // GetPoints() préalable au Run() va allouer, et indiquer au Run() qu'il devra remplir
    // les tableaux qui sont aloués en interne et devenus propriété de l'appelant
    // NLD200622
    CATCartesianPoint ** GetPoints(); 
  
    // impose les courbes et leur crvlimits
    void                 SetCurveOne(const CATCurve    * C1 ,
                                     const CATCrvLimits& CL1);
    void                 SetCurveTwo(const CATCurve    * C2,
                                     const CATCrvLimits& CL2);

    // impose le type de continuite
    // 1  : C0                        DEFAULT
    // 2  : Colinear normals     (G1)
    // 3  : Colinear tangents    (C1)  (dans la direction orthogonale a la tangente a la courbe)
    // 4  : Curvature continuity (C2)
    void                 SetContinuityMode       (int ContinuityMode);
     
    // Impose le nombre de points discretises (equisdistants en parametre)
    // ou se feront les tests de continuite (10 par defaut).
    void                 SetNbOfDiscretizedPoints(int NbOfDiscretizedPoints);
   
    // Impose le type de coupling :
    // 1 = a isoparametre (a la reorientation pres) DEFAULT
    // 2 = par projection sur la courbe opposee
    void                 SetCouplingType         (int iCType);

    // Impose l orientation relative des courbes
    // a un sens seulement pour coupling isoparameter 
    // 1  : orientees dans le meme sens
    // -1 : orientees de maniere inverse
    void                 SetOrientation          (int iOrientation);

    // Affiche les resultats
    // 1 == oui, 0 == non (DEFAUT)
    void                 SetDisplay              (int iDisplay);

    // Rend symetrique le calcul (uniquement avec report par min distance).
    // Par defaut non symetrique : La courbe 1 est discretisee et une distance min est faite avec la courbe 2.
    void                 SetSymetricComputation  ();

    // Permet de mettre des plafonds au dessus desquels, on ne souhaite pas poursuivre l'analyse
    void                 SetMaxValues            (double *iMaxPt        ,
                                                  double *iMaxNormal    = 0,
                                                  double *iMaxCurvature = 0);
  
    //------------------- Compute Methods -------------------  
    int                  Run                     ();
 // void                 Run                     ();
    int                  RunOperator             ();

#ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay
         // Méthodes relatives au CGMReplay
         void                        WriteInput                       (CATCGMStream             & ioStream      );
         void                        Dump                             (CATCGMOutput             & os            );
         CATExtCGMReplay*
                                     IsRecordable                     (short                    & LevelOfRuntime  ,
                                                                       short                    & VersionOfStream);
         void                        WriteOutput                (      CATCGMStream             & os            );
 
         CATBoolean                  ValidateOutput             (      CATCGMStream             & ioStream      ,
                                                                       CATCGMOutput             & os            ,
                                                                       int                        VersionNumber = 1);

         void                        DumpOutput                 (      CATCGMOutput             & os            );
         void                        DumpOutput                 (      CATCGMStream             & ioStream      ,
                                                                       CATCGMOutput             & os            ,
                                                                       int                        VersionNumber = 1);

         CATCGMOperator::CATCheckDiagnostic
                                     CheckOutput                (      CATCGMOutput             & os         );

   const CATString                 * GetOperatorId              ();
#endif

  private :

    //-------------------PrivateMethods-----------------------------
    void OneRun                  ();
  
    //------------------- Datas -------------------  
    CATGeoFactory            * _Factory;
    CATSoftwareConfiguration * _SoftwareConfig;
    const CATCurve           * _Curve1;
    const CATCurve           * _Curve2;
    CATCrvLimits               _CrvLimits1;
    CATCrvLimits               _CrvLimits2;
  
    int                        _ContinuityMode;
    int                        _NbOfDiscretizedPoints;
    int                        _Orientation;
    int                        _CouplingType;
    int                        _Display;
    CATLONG32                  _Sym;

    // distinguons par des commentaires, avec ces notations ambigues _Max* les entrées des sorties; NLD200622
    double                     _MaxDist;                  // sortie
    double                     _MaxNormalsAngle;          // sortie
    double                     _MaxTangenciesAngle;       // sortie
    double                     _MaxDifCourbure;           // sortie
    double                     _MaxDifCourbureRapportee;  // sortie

    double                   * _MaxPt;                    // entree
    double                   * _MaxNormal;                // entree
    double                   * _MaxCurvature;             // entree
    CATCartesianPoint       ** _Points;

#ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay

    // Management data for CGMReplay
          int                                    _LoadedFromReplay;          // internal
          CATFrFCheckGeometricContinuityReplay * _LoadingOperator;           // internal
          double                                 _ScaleRatio;

 public:
   static CATString                              _OperatorId;
#endif
};


#ifdef ImplementCATFrFCheckGeometricContinuityCGMReplay
// Definition d'un pseudo operateur CATFrFCheckGeometricContinuityReplay permettant l'enregistrement des CGMReplays. NLD170622
CATFrFOperatorDefineReplayOperator(CATFrFCheckGeometricContinuity, CATFrFCheckGeometricContinuityReplay) 
#endif

#endif
