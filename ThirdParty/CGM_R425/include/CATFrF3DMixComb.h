// COPYRIGHT DASSAULT SYSTEMES 2000
//==========================================================================
//
// Objet d'extraction de peigne : cas d'une courbe posee - contrainte G1 - 
// Gestion par mixage 3D des vecteurs de reference
// 
//==========================================================================
// June 2000  Creation                          DHN
//==========================================================================
// August 2004 Add _UseOfGeneralComb            JSX
// 04/11/05 NLD Argument iConfig dans le constructeur
// 04/03/09 JSX SetSmoothMode devient SetCleanMode, 
//              car on lance le clean de comb sans la partie de smoothing.
// 12 11 09 JSX SetCleanMode devient meme SetEvalOnGeneralComb
// 18/11/09 JSX : nettoyage
// 23/11/09 JSX Ajout de GetEvalOnGeneralComb et EvalLocalCoordSystemInternal 
// 10/03/10 JSX Ajout ComputeG2Laws et _LawNormDerV pour les profils G2 (necessaire avec des guides) 
// 19 10 10 JSX Ajout ier a ComputeDeformDataFromDir et EvalLocalCoordSystem 
//              Ajout de EvalLocalCoordSystemInternal
// 28/05/13 NLD Ajout de _Debug
//              Ajout de ComputeLawNormParam()
//==========================================================================
#ifndef CATFrF3DMixComb_H
#define CATFrF3DMixComb_H

#include "FrFOpeCrv.h"
#include "CATFrFComb.h"

class CATCurve;
class CATGeoFactory;
class CATMathDirection;
class CATMathSetOfPointsND;
class CATCrvParam;
class CATFrFGeneralComb;
class CAT3DTangentFunction;
class CATSoftwareConfiguration;
class CATFrF3DMixCombDebug;

//--------------------------------------------------------------------------
class ExportedByFrFOpeCrv CATFrF3DMixComb : public CATFrFComb
  {
  void ComputeG2Laws(double iParam, double iLg1, double &oL2OnG1, double &oL2Cross) const;

  public:
    //--------------------
    // Constructor
    //--------------------
    CATFrF3DMixComb(      CATGeoFactory           * iFactory,
                          CATSoftwareConfiguration* iConfig,
                    const CATPCurve               * iPCurve,
                    const CATCrvLimits            * iPCurveLimits,
                    const CATMathSetOfPointsND    * iSetOfParams, 
                    const CATMathSetOfPointsND    * iSetOfVectors,
                          CATMathDirection        * iRefDirection);

    //--------------------
    // Destructor
    //--------------------
    virtual ~CATFrF3DMixComb();

    //To get the type of Comb.
    virtual CATBoolean IsATypeOf(const CATTypeOfComb &iType) const;
    //To add or replace a reference vector.
    void SetDirection(const CATCrvParam &iParam,const CATMathVector &iVect);
    //To be defined, it should have at least one imposed non zero direction at its extremities.
    CATBoolean IsDefined();

    void ImposeLawOfNorms(CATLaw *iLaw, CATLaw *iDerLaw, double iStartGlobalLawParam, double iEndGlobalLawParam);

    // To get maximal angular deformation. The result is expressed in radian.
    virtual double GetAngularDeviation(const CATCrvLimits *iLim=0);

    //To get the minimal and maximal length of the comb.
    virtual void GetMinMaxCombLength(double &oMinLength,double &oMaxLength);

    //Private method.To get informations.
    virtual void ComputeDeformDataFromDir(CATError *&oer, const CATCrvParam &iParam,const CATMathVector &iDir,
                             double &iLength,double &iAngleDir,double &iAngleDef);

    void Dump() const;

    CATFrFGeneralComb* GetGeneralComb();

    void SetEvalOnGeneralComb(CATBoolean iUseCleanComb);
    void GetEvalOnGeneralComb(CATBoolean &iUsedCleanComb);

  protected:
    virtual void EvalLocalCoordSystem(CATError *&ier, double iParam,
                                      double *iDefaultDirForG1,             double *iDerCrv ,   double *iNormal,
                                      double *iFirstDerivDefaultDirForG1=0, double *iDer2Crv=0, double *iDerNormal=0);

    virtual void EvalDirectionForG2(double iparam,double *iDirForG2);

  private :
    void EvalLocalCoordSystemInternal(double iParam,
                                      double *iDefaultDirForG1,             double *iDerCrv,    double *iNormal,
                                      double *iFirstDerivDefaultDirForG1=0, double *iDer2Crv=0, double *iDerNormal=0, int iUseOfGeneralComb=0);
    void ComputeLawNormParam         (double  iParam    ,
                                      double& oParLaw   ,
                                      double& oDerParLaw) const;

    //======================================================
    //Data
    //======================================================
  protected :
    CATLONG32                                _IsUpToDate;
 //   CATMathDirection                     * _RefDir;
    // Law On Local Param (Curveparam)
    CATLaw                                 * _LawX;
    CATLaw                                 * _LawY;
    CATLaw                                 * _LawZ;
    // Law On Gloabal Param
    CATLaw                                 * _LawNorm;
    CATLaw                                 * _LawNormDerV;
    double                                   _StartL, _EndL;

  private:
    CAT3DTangentFunction                   * _GeneralComb;
    CATBoolean                               _UseOfGeneralComb;
    CATFrF3DMixCombDebug                   * _Debug;
  };
#endif
