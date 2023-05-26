#ifndef CATGEOUTILITY_H
#define CATGEOUTILITY_H

   #define CATGEOUTILITY_IntersectIsoCurvePCurveX_ForceBasisFunctionX         "XScale control issue NLD010223"

/**
* @quickReview SMT1 04:08:22
*/
//=============================================================================
//    2016  SMT1   Utility class for basic geometric operations SMT1
// 04/08/22 SME31  Move DumpInit from CATConnectCx2 to CATGeoUtilities
// 18/01/23 S9L    Intersection of p-curve with iso-curve on the same surface
// 01/02/23 NLD    XScale: IntersectIsoCurvePCurveX must derive from CATMathBasisFunctionX
//                 if being used with a solver
// 21/03/23 S9L    Improvement in the interface of IntersectIsoCurveWithPCurve
//=============================================================================


// Base class
#include "CATCGMVirtual.h"

// ExportedBy
#include "Y3DYNOPE.h"

#include "CATCGMOperator.h"
#include "CATCGMVirtual.h"

#include "CATMathBasisFunctionX.h"
#include "CATMathFunctionX.h"
#include "CATMathNormal.h"
#include "CATMathVector.h"
#include "CATMathVector2D.h"
#include "CATMath2x2Matrix.h"
#include "CATMathSetOfPointsND.h"

#include "CATCrvLimits.h"
#include "CATSetOfCrvParams.h"
#include "CATSurParam.h"

//DumpInit
#include "CATGeoFactory.h"
#include "CATConnectTool.h"
#include "CATVariableFilletTool.h"
#include "CATVariableSweepCircleTool.h"
#include "CATHoldCurveCircleFilletTool.h"
#include "CATPointOnCurve.h"
#include "CATPointOnSurface.h"
#include "CATCGMOutput.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATGeometry;
class CATPoint;
class CATCurve;
class CATPCurve;
class CATSurface;
class CATInclusionPtCrv;
class CATConnectSupport;


// ---------------------------------------------------------------------------------------------------------
class ExportedByY3DYNOPE CATGeoUtility : public CATCGMVirtual
{
public:

  // Methods to for casting to non-const
  static CATGeometry* GetAsGeometry(const CATGeometry*);
  static CATPoint   * GetAsPoint(const CATPoint*);
  static CATCurve   * GetAsCurve(const CATCurve*);
  static CATSurface * GetAsSurface(const CATSurface*);

  static CATGeometry* GetAsGeometryOK(const CATGeometry*); // for cases where the cast is validated OK
  static CATPoint   * GetAsPointOK(const CATPoint*); // for cases where the cast is validated OK
  static CATCurve   * GetAsCurveOK(const CATCurve*); // for cases where the cast is validated OK
  static CATSurface * GetAsSurfaceOK(const CATSurface*); // for cases where the cast is validated OK

  static void         Lock  (const CATCurve * iCurve, const CATCGMOperator         * iReferencing);
  static void         UnLock(const CATCurve * iCurve, const CATCGMOperator         * iReferencing);
  static void         Lock  (const CATCurve * iCurve, const CATMathFunctionGeneral * iReferencing);
  static void         UnLock(const CATCurve * iCurve, const CATMathFunctionGeneral * iReferencing);

  static void         Lock  (const CATSurface * iSurface, const CATCGMOperator         * iReferencing);
  static void         UnLock(const CATSurface * iSurface, const CATCGMOperator         * iReferencing);
  static void         Lock  (const CATSurface * iSurface, const CATMathFunctionGeneral * iReferencing);
  static void         UnLock(const CATSurface * iSurface, const CATMathFunctionGeneral * iReferencing);

  static const CATCurve  * CATCGMNativeInterfaceImpl(const CATCurve*);
  static const CATSurface* CATCGMNativeInterfaceImpl(const CATSurface*);

  static CATGeoFactory* GetFactory(const CATGeometry* iGeom); // cast to non-const then get factory

  static void FindIndices(const CATMathSetOfLongs & iSet, CATMathSetOfLongs &ioIndices, CATLONG32 iElement);

  // Checks if iPCurve and iSurParam are defined on the same surface and uses CATInclusionPtPCrv.
  // Returns TRUE if any solutions are found and stores them in ioParam
  static CATBoolean PCurveContainsSurParam(      CATGeoFactory            * iFactory,
                                                 CATSoftwareConfiguration * iConfig,
                                           const CATPCurve                * iPCurve,
                                           const CATSurParam              & iSurParam,
                                                 CATSetOfCrvParams        & ioParam,
                                           const CATTolerance             & iTolObject);

  static CATBoolean IsFilletTrackAndContact(const CATPCurve * iPCrv1,
                                            const CATPCurve * iPCrv2);

  static CATBoolean FindMinimalAngle(      CATGeoFactory            *  iFactory,
                                           CATSoftwareConfiguration *  iConfig,
                                     const CATPCurve                *  iPCrv1,
                                     const CATCrvLimits              & iLim1,
                                     const CATPCurve                *  iPCrv2, 
                                     const CATCrvLimits              & iLim2,
                                           CATCrvParam               & ioCrvPar1,
                                           CATCrvParam               & ioCrvPar2);

  // S9L24102016 : Start
  //------------------------------------------------------------------------------
  // Check whether a given surface is developable or not
  //------------------------------------------------------------------------------
  static CATBoolean IsDevelopableSurface(CATGeoFactory             * ipFactory,
                                         CATSoftwareConfiguration  * ipConfig,
                                         CATSurface                * ipSurface);
  // S9L24102016 : End

  static void DumpInit( CATCGMOutput& os, const CATConnectTool* iProfile, CATGeoFactory* iFactory,
                        CATMathSetOfPointsND* iInitPointToDisp, CATConnectSupport* iSupport0,
                        CATConnectSupport* iSupport1, CATConnectSupport* iSupport2,
                        CATConnectSupport* iSupport3, const int iDim);

  //------------------------------------------------------------------------------------
  // Check whether an iso-curve with iPrimaryIsoParamType (CATIsoParamU or CATIsoParamV)
  // at iPrimaryIsoParam (u or v value) intersect the given p-curve on the same surface
  // Gives list of oSecondaryIsoParams (v or u value) of another surface param on p-curve
  // Returns TRUE if at least one intersection is found, FALSE otherwise
  //------------------------------------------------------------------------------------
  static CATBoolean IntersectIsoCurveWithPCurve(CATGeoFactory             * ipGeoFactory,
                                                CATSoftwareConfiguration  * ipConfig,
                                                CATPCurve                 * ipPCurve, 
                                                double                      iPrimaryIsoParam, 
                                                CATIsoParameter             iPrimaryIsoParamType, 
                                                CATListOfDouble           & oSecondaryIsoParams);

  //------------------------------------------------------------------------------------
  // Check whether an iso-curve with iPrimaryIsoParamType (CATIsoParamU or CATIsoParamV)
  // at iPrimaryIsoParam (u or v value) intersect the given p-curve on the same surface
  // iCrvLimits is the portion of the input p-curve in which intersection will be computed
  // Gives list of oSecondaryIsoParams (v or u value) of another surface param on p-curve
  // The last argument is default one, which will populate the p-curve params of intersection
  // Returns TRUE if at least one intersection is found, FALSE otherwise
  //------------------------------------------------------------------------------------
  static CATBoolean IntersectIsoCurveWithPCurve(CATGeoFactory             * ipGeoFactory,
                                                CATSoftwareConfiguration  * ipConfig,
                                                CATPCurve                 * ipPCurve,
                                                CATCrvLimits              & iCrvLimits,
                                                double                      iPrimaryIsoParam,
                                                CATIsoParameter             iPrimaryIsoParamType,
                                                CATListOfDouble           & oSecondaryIsoParams,
                                                CATMathSetOfPointsND      * opCrvParams = NULL);

private:

  static CATBoolean IsFilletTrackAndContact_Order(const CATPCurve * iPCrv1,
                                                  const CATPCurve * iPCrv2);

};

// ---------------------------------------------------------------------------------------------------------
class ExportedByY3DYNOPE CATGeoCGMReplayUtility : public CATCGMVirtual
{
public:

  static CATBoolean IsUnderCGMReplay(const CATCGMOperator * iOp);
};

// ---------------------------------------------------------------------------------------------------------
class MinAngleFunc : public CATMathFunctionX
{
public:

    MinAngleFunc(CATGeoFactory            * iFactory,
                 CATSoftwareConfiguration * iConfig,
                 const CATPCurve          * iPC1,
                 const CATCrvLimits       & iLim1,
                 const CATPCurve          * iPC2,
                 const CATCrvLimits       & iLim2);

    ~MinAngleFunc();

    virtual CATMathClassId IsA() const {return "MinAngleFunc";}
    virtual CATMathFunctionX * Duplicate() const {return NULL;}

    CATBoolean IsOption(const CATMathOption iOption) const;
    virtual double Eval           (const double & iT) const;

    virtual double EvalFirstDeriv (const double & iT) const;

    void GetCrvParams(const double      & iT       ,
                            CATCrvParam & ioCrvPar1,
                            CATCrvParam & ioCrvPar2) const;

protected:

    CATGeoFactory            * _Factory;
    CATSoftwareConfiguration * _Config;
    const CATPCurve          * _PC[2];
    CATSurface               * _Supp[2];
    CATCrvLimits               _Lim1,_Lim2;
    CATInclusionPtCrv        * _Incl;
    CATMathNormal              _Normal[2];
    double                     _Scale;
};

// ---------------------------------------------------------------------------------------------------------
class TangentSpaceBaseChange
{
public:
    TangentSpaceBaseChange(      CATSurface  * iSurface,
                           const CATSurParam & iSurParam);

    void SetParam(const CATSurParam & iSurParam);

    void Convert3DToLocal2D(const CATMathVector &i3DTan, CATMathVector2D & io2DTan);
    void ConvertLocal2DTo3D(const CATMathVector2D &i2DTan, CATMathVector & io3DTan);

    void Convert3DToOrtho2D(const CATMathVector &i3DTan, CATMathVector2D & io2DTan);
    void ConvertOrtho2DTo3D(const CATMathVector2D &i2DTan, CATMathVector & io3DTan);

    void ConvertLocal2DToOrtho2D(const CATMathVector2D &i2DLocal, CATMathVector2D & io2DOrtho);
    void ConvertOrtho2DToLocal2D(const CATMathVector2D &i2DOrtho, CATMathVector2D & io2DLocal);

private:

    CATSurface     * _Surface;
    CATMathVector    _DU,_DV,_B[2];
    CATMath2x2Matrix _BaseChange, _InvBaseChange;

};

// ---------------------------------------------------------------------------------------------------------
#ifdef CATGEOUTILITY_IntersectIsoCurvePCurveX_ForceBasisFunctionX
class IntersectIsoCurvePCurveX : public CATMathBasisFunctionX
#else
class IntersectIsoCurvePCurveX : public CATMathFunctionX
#endif
{
public:
  #ifdef CATGEOUTILITY_IntersectIsoCurvePCurveX_ForceBasisFunctionX
  IntersectIsoCurvePCurveX(const CATTolerance    & TolObject    ,
                           const CATMathFunctionX* ipFunctionX  ,
                                 double            iValFunctionX)
     : CATMathBasisFunctionX(TolObject,
                             1 , // PowerScaleF
                             1 ) // PowerScaleX
  #else
  IntersectIsoCurvePCurveX(const CATMathFunctionX* ipFunctionX  ,
                                 double            iValFunctionX)
  #endif
  {
    _PrimaryIsoParamValue = iValFunctionX;
    _pFunctionX = ipFunctionX;
  }

  ~IntersectIsoCurvePCurveX()
  {
    _pFunctionX = NULL;
  }

  virtual CATMathClassId IsA() const
  {
    return "IntersectIsoCurvePCurveX";
  }
  virtual CATMathFunctionX* Duplicate() const
  {
    return NULL;
  }
  CATBoolean IsOption(const CATMathOption iOption) const
  {
    if (((OptionEval + OptionEvalFirstDeriv) & iOption) == iOption)
      return 1;
    return 0;
  }
  virtual double EvalFirstDeriv(const double & iX) const
  {
    return (_pFunctionX->EvalFirstDeriv(iX));
  }
  virtual double Eval(const double & iX) const
  {
    if (!_pFunctionX) CATThrowForNullPointerReturnValue(-1.0);
    return (_pFunctionX->Eval(iX) - _PrimaryIsoParamValue);
  }

private:
  const CATMathFunctionX * _pFunctionX;
        double             _PrimaryIsoParamValue;
};

#endif // CATGEOUTILITY_H
