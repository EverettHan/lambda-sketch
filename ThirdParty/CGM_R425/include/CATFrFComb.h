// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peigne : Cas general PCurve sur surface avec conditions G1 ou G2.
//
// A deriver pour les autres cas.
//
//  P(u,v) = S(C(u)) + v*D1(u) + 0.5*v*v*D2(u) + Sp(u) , C est la PCurve et S la surface appui ; P est le peigne.
//  Sp est une spline permettant de deformer la courbe appui.
//
//  D1(u) = L1(u)* (cos(b(u))*cos(a(u))*d1(u) + cos(b(u))*sin(a(u))*dC + sin(b(u))*N) , ||D1|| = L1.
//  ou dC = C'/||C||,
//      N = normale a S au point S(C(u)),
//     d1 = Orn*(dC^N),
//     L1           regle la longueur du peigne ( > 0).
//    Orn = +/- 1 , permet de gerer l'orientation.
//      a           est l'angle entre D1 et d1 dans le plan tangent.
//      b           est l'angle entre D1 et d1 dans le plan definit par (S(C(u)) , dC) -> correspond a une deformation.
//      a et b      appartiennent a ]-Pi/2 , +Pi/2[.
//
//  Si b = 0, le peigne est tangent a la surface.
//  b permet de deformer le peigne pour gerer des problemes d'incompatibilites.
// 
//  D2(u) =    L1*L1*( (Curvature(S,S(C(u)),D1(u))+ ErC )*N(P(u,0))) 
//           + L2*D1 
//           + L3* N( P(u,0) ^ D1 ) 
//  ou
//    L2           est defini par SetNormG2Law,
//    N(P)         est la normale a P,
//    Curvature    est calcule sur S au point S(C(u)) et dans la direction D1.
//    (N(P),D1,D2) sont coplanaires
//
//  JSX 090210 Ajout du terme L3* N(P(u,0) ^ D1) , L3 est definit par SetNormCrossG2Law (direction de G2 dans le plan tangent perpendiculaire a G1)
//  JSX 131010 Ajout du terme ErC; correction de la courbure de la surface.
// * N(P(u,0)^D1 , L3 est definit par SetNormCrossG2Law (direction de G2 dans le plan tangent perpendiculaire a G1)
//
//==========================================================================
//  Classes Amies :
//  CATFrFMultiComb CATFrFGeoCombCompatibilityManager CATFrFEdgesComb
//==========================================================================
//
//   /03/00 NDN Creation
// 04/11/05 NLD On derive de CATFrFObjectVirtual au lieu de CATCGMVirtual
// 27/02/07 NLD Migration vers CATFrFObject au lieu de CATFrFObjectVirtual
// 15/05/09 NLD Ajout _Debug et CATFrFCombDebug (livraison le 22/01/10)
// 29/09/09 NLD Les methodes SetRatio() et GetRatio() vont dans l'implementation
//              en vertu des regles de programmation
// 18/11/09 JSX Ajout d'un constructeur protected avec un Curve ( pour etre utilisé par les classes filles)
//              Methode Init
//              on passe en protected ComputeData / ComputeDataForCrossDeriv / ComputeSystemForCrossDeriv
//              pour les limites aux nouvelles classes friend
//              Ajout de EvalCrvDir pour partage de code avec les derivées
// 23/11/09 JSX Ajout de Set/GetEvalOnGeneralComb et EvalFirstDerivatives(double iParam...
// 08/12/09 JSX Activation de CATFrFComb_JSX_COMB1
// 20/01/10 NLD Definition de nomenclature pour les #define partages: JSX_COMB1 devient CATFrFComb_JSX_COMB1
// 22/01/10 JSX Ajout de EvalSecondDerivatives(double ....)
// 09/02/10 JSX Ajout de _NormCrossG2Law pour traiter les profilsG2 avec des Guides
//              de GetNormCrossG2Law et de l'argument iNormCrossG2Lawa SetNormG2Law
// 25/03/10 JSX Ajout EvalCurvatureInOneDirection pour Loft G2 OnGuide 
//              (eval sur la surface pour l'instant, il faudra tenir compte des corrections )
// 19 10 10 JSX ajout ier a ComputeDeformDataFromDir et EvalLocalCoordSystem
// 09 01 12 JSX Ajout de GetPCurve
// 28/05/13 NLD _Fact devient _Factory
// 29/05/13 NLD Ajout EvalNormal() (renomme EvalNormalAndDeriv() le 10/06/13 pour eviter confusion avec l'ancien)
//              Ajout DebugLocalCoordSystem() qui remplace la methode statique locale
//              Correction erreur UPVA dans EvalCurvatureInOneDirection(): iDir passe en const par adresse
// 10/06/13 NLD EvalNormal() (le nouveau) est renomme EvalNormalAndDeriv()
// 19/06/14 NLD Smart indent (1/3)
// 05/07/18 NLD Smart indent (2/3)
//              Ajout de la derivation SetSoftwareConfiguration() pour passage de la configuration à CATMathNormal
//==========================================================================
#ifndef CATFrFComb_H
#define CATFrFComb_H

#include "FrFOpeCrv.h"
#include "CATMathNormal.h"
#include "CATCrvLimits.h"
#include "CATFrFObject.h"

class CATError;
class CATMathPoint;
class CATMathVector;
class CATMathDirection;
class CATMath3x3Matrix;
class CATMathFunctionX;
class CATGeoFactory;
class CATPCurve;
class CATCurve;
class CATSurface;
class CATLaw;
class CATSplineCurve;
class CATCrvParam;
class CATFrFMultiComb;
class CATFrFGeoCombCompatibilityManager;
class CATFrFEdgesComb;
class CAT3DTangentFunction;
class CATFrFCombDebug;
class CATSoftwareConfiguration;

enum CATTypeOfComb {CATFrFCombType        = 0,
                    CATFrF3DCombType      ,
                    CATFrF3DMixCombType   ,
                    CATFrFPointCombType   ,
                    CATFrFExtrudedCombType};

#define CATFrFComb_JSX_COMB1 // Activation de la factorisation de EvalCrvDir

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrFComb : public CATFrFObject
  {
  public:
    //--------------------
    // Constructor
    // - Extract a G2 Comb. Direction at each parameters is chosen by d(iPCurve)/du ^ Normal.
    // - The G2 point is alway computed in the plane defined by (G0,G1) points and the normal to surface.
    //--------------------
                                  CATFrFComb(      CATGeoFactory * iFactory      ,
                                             const CATPCurve     * iPCurve       ,
                                             const CATCrvLimits  * iPCurveLimits = 0);

    //--------------------
    // Destructor
    //--------------------
    virtual                      ~CATFrFComb();

    //--------------------
    // CATFrFObject methods
    //--------------------
    virtual       void            SetSoftwareConfiguration(CATSoftwareConfiguration* iConfig);

    //--------------------
    // Comb methods
    //--------------------
                  void            ResetLaws();

    // Defining direction for G1, and length for G1 and G2.
    // If a Law=NULL, then it worth 0 everywhere for angle law and 1 for length law.
    // To define angle between target G1 direction and default G1 direction in the tangent plane.
                  void            SetDirectionLaw(CATLaw *iDirLaw);
                  CATLaw        * GetDirectionLaw();

    // To define norm of the tangent in the G1 direction.
                  void            SetNormG1Law(CATLaw *iNormG1Law);
                  CATLaw        * GetNormG1Law();

    // To define norm of the second derivative in the G1 and Normal^G1 directions
                  void            SetNormG2Law(CATLaw *iNormG2Law, CATLaw *iNormCrossG2Law, CATLaw *iNormNormalLaw=NULL);
                  CATLaw        * GetNormG2Law();
                  CATLaw        * GetNormCrossG2Law();

    // To define angle between normal and G1 direction in the plane defined by the tangent to the curve.
                  void            SetDeformationLaw(CATLaw *iDeformLaw);
                  CATLaw        * GetDeformationLaw();

    // To add a deformation spline.
                  void             SetDeformationSpline(CATSplineCurve *iSpline);
                  CATSplineCurve * GetDeformationSpline();

    // Min ratio to get precision.
                  double           GetRatio() const;
                  void             SetRatio(double iRatio = 1.0);

    // To relimit the comb.
                  void             SetLimits(const CATCrvLimits &iPCurveLimits);
                  void             GetLimits(CATCrvLimits &iPCurveLimits) const;

    // To change the orientation of the comb ; iOrientation=1(default) or -1.
    virtual       void             SetOrientation(CATLONG32 iOrientation);
    virtual       CATLONG32        GetOrientation() const;

    // To change the orientation of the curve ; iOrientation=1(default) or -1.
    virtual       void             SetCurveOrientation(CATLONG32 iOrientation);
    virtual       CATLONG32        GetCurveOrientation() const;

    // To get pointer on the curve.
    virtual const CATCurve       * GetCurve() const ;
    // To get pointer on the pcurve.
    virtual const CATPCurve      * GetPCurve() const ;
    // To get pointer on the surface (if there is any...).
    virtual const CATSurface     * GetSurface() const ;

    // To get the type of Comb.
    virtual       CATBoolean       IsATypeOf(const CATTypeOfComb &iType) const;
    // To exchange normal and comb direction evaluation. Used to generate G1 normal combs.
    // default is FALSE;
    virtual       void             SetNormalMode(CATBoolean iActivate=TRUE);
    virtual       CATBoolean       GetNormalMode() const;

    //--------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------
    // Evaluators.
    virtual       void             EvalPoint            (const CATCrvParam &iParam, CATMathPoint &oPt) const;

    // This method returns a rc (i.e. Return Code) if one of the two (or the twice) vectors evaluate is nul:
    //               - rc =1 if Du is nul
    //               - rc =2 if Dv is nul
    //               - rc =3 if the two (Du or Dv) are nul.

    virtual       CATLONG32        EvalFirstDerivatives (double                 iParam, CATMathVector *iDu, CATMathVector *iDv) const;
    virtual       CATLONG32        EvalFirstDerivatives (const CATCrvParam & iCrvParam, CATMathVector *iDu, CATMathVector *iDv) const;

    virtual       void             EvalSecondDerivatives(double                 iParam, CATMathVector *iDuu, CATMathVector *iDuv, CATMathVector *iDvv) const;
    virtual       void             EvalSecondDerivatives(const CATCrvParam & iCrvParam, CATMathVector *iDuu, CATMathVector *iDuv, CATMathVector *iDvv) const;

    // This method return a Rc (return code) if the normal couldn't been evaluated           (i.e. Norme < CATEpsg)
    // This method return a Rc (return code) if the normalDerivative couldn't been evaluated (i.e. Norme < CATEpsg)

    virtual       CATLONG32        EvalNormal          (const CATCrvParam &iParam, CATMathDirection &iNormal) const;
    virtual       CATLONG32        EvalNormalDerivative(const CATCrvParam &iParam, CATMathVector *iDerNormalU, CATMathVector *iDerNormalV) const;

    virtual       void             EvalCurvatureInOneDirection(double iParam, const CATMathVector& iDir, CATMathVector &G2);
 
    // Evaluators for CATMultiformComb.
    virtual       void             EvalComb     (double iParam, double *ioPt, double *ioDv) const;
    virtual       void             EvalDerivComb(double iParam, double *ioDu, double *ioDuv) const;
    //--------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------

    // To get maximal angular deformation. The result is expressed in radian.
    virtual       double           GetAngularDeviation(const CATCrvLimits *iLim = 0);

    // To get the minimal and maximal length of the comb.
    virtual       void             GetMinMaxCombLength(double &oMinLength, double &oMaxLength);


    virtual       void             SetEvalOnGeneralComb(CATBoolean  iUseCleanComb)  {};
    virtual       void             GetEvalOnGeneralComb(CATBoolean &oUsedCleanComb) {};


  protected:
    // friend
    friend class CATFrFMultiComb;
    friend class CATFrFGeoCombCompatibilityManager;
    friend class CATFrFEdgesComb;
    friend class CAT3DTangentFunction;

    // Constructeur protected 
    // Protection
                                   CATFrFComb();
    // (avec Curve et non pCurve)
                                   CATFrFComb(CATGeoFactory *iFactory, const CATCurve *Curve, const CATCrvLimits *iCurveLimits=0);

    // Private methods. For debug.
    virtual       void             Dump() const;

    // Private method.To get informations.
    virtual       void             ComputeDeformDataFromDir          (      CATError *&ier, const CATCrvParam &iParam, const CATMathVector &iDir, 
                                                                            double &oLength, double &oAngleDir, double &oAngleDef); 

    // ComputeDataForCrossDeriv
    virtual       void             ComputeFirstDerivDeformDataFromDir(const CATCrvParam &iParam, const CATMathVector &iCD,
                                                                            double &oDerLength, double &oDerAngleDir, double &oDerAngleDef, 
                                                                            CATMathVector &oReste);

    virtual       void             ComputeSystemForCrossDeriv        (const CATCrvParam &iParam, 
                                                                            CATMath3x3Matrix &oMatrix, double *oSecMember,
                                                                            double *oDerAngleDir=0, double *oDerAngleDef=0, double *oDerLength=0);


  protected:

    // Evaluation des derivées dans la direction de la courbe
    virtual       void             EvalCrv                           (      double iParam, CATMathOption iOption, double *ioPt, double *ioTg=0, double *ioDs=0) const;
    // Evaluation des directions (normées donc) dans la direction de la courbe
    virtual       void             EvalCrvDir                        (      double iParam, double *iDerCrv, double *iDer2Crv);

    // Evaluation de la normale
                  void             EvalNormalAndDeriv
                                                                     (      double   iParam,
                                                                            double * oNormal,
                                                                            double * oDerNormal);


    // Evaluation du systeme orthonormé non corrigé 
    // _NormalMode est pris en compte
    // 
    virtual       void             EvalLocalCoordSystem              (      CATError *&oer,
                                                                            double iParam, 
                                                                            double *iDefaultDirComb           ,    double *iDerCrv  ,    double *iNormal, 
                                                                            double *iFirstDerivDefaultDirComb = 0, double *iDer2Crv = 0, double *iDerNormal = 0);

                  void             DebugLocalCoordSystem             (      int     iForceDebug3D,
                                                                            double  iParam, 
                                                                            double *iDefaultDirComb           , double *iDerCrv  ,    double *iNormal, 
                                                                            double *iFirstDerivDefaultDirComb = 0, double *iDer2Crv = 0, double *iDerNormal = 0);


    // Evaluations corrigées par les lois 
    virtual void EvalDirectionForG1          (double iParam, double *iDirForG1);
    virtual void EvalFirstDerivDirectionForG1(double iParam, double *iFirstDerivDirForG1);
    virtual void EvalDirectionForG2          (double iParam, double *iDirForG2);



    // Loi
    virtual void ComputeG2Laws(double iParam, double iLg1, double &oL2OnG1, double &oL2Cross) const;


  private:
    void Init(CATGeoFactory *iFactory, const CATCurve *Purve, const CATCrvLimits *iPCurveLimits, int iModeDim );

    //
    // Data
    //
  protected :
          CATGeoFactory    * _Factory;
    const CATCurve         * _Crv;
    const CATPCurve        * _PCrv;
    const CATSurface       * _Surf;
          CATCrvLimits       _Lim;

          CATLONG32          _Orn;    // Orientation de la direction du peigne par rapport a la direction par defaut.
          CATLONG32          _OrnCrv; // Orientation de la courbe.
          CATLONG32          _NormalMode;

          CATSplineCurve   * _Spline;
          double             _Ratio; //Ratio de longueur de peigne calcule pour obtenir la precision angulaire suffisante

          CATLaw           * _DirLaw;           // Correction de la direction de G1 par rapport a la reference
          CATLaw           * _DefLaw;           // Correction de la direction de G1 par rapport au plan tangent 
          CATLaw           * _NormG1Law;        // Norme suivant la direction de G1 
          CATLaw           * _NormG2Law;        // Courbure dans la direction de G1 (acceleration)
          CATLaw           * _NormCrossG2Law;   // Courbure dans le plan tangent perpendiculaire au G1 (torsion)
          CATLaw           * _NormNormalG2Law;  // Correction de la courbure suivant la normale a la surface

          CATMathNormal      _EvalNormal;
          CATFrFCombDebug  * _Debug;


    const CATMathFunctionX * _FCrv [3]; //CPU optimization
  };
#endif
