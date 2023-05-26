//============================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//============================================================================
//
// CATFrFRefElement:
// Interface class of the Reference Element
//
//============================================================================
//
// Usage notes:
// This class can be used as is for simple DistMin on Surface or derived
// in order to implement specific algorithm or capabilities.
//
//============================================================================
// January  99     Creation                      Christophe Pradal
//============================================================================
// 090409 JSX : Ajout de GetCombContinuity
//
#ifndef CATFrFRefElement_H
#define CATFrFRefElement_H

#include "FrFAdvancedObjects.h"
#include "CATCGMVirtual.h"
#include "CATListOfInt.h"
class CATMathPoint;
class CATMathVector;
class CATMathDirection;
class CATGeometry;
class CATFrFCCvParam;
class CATFrFCompositeCurve;

#include "CATBoolean.h"

//-----------------------------------------------------------------------------
class  ExportedByFrFAdvancedObjects CATFrFRefElement : public CATCGMVirtual
{
  public :

    virtual  ~CATFrFRefElement();

    virtual void EvalNormal(const CATMathPoint& iPoint,
                            CATMathVector& oNormalResult) = 0;

    virtual CATBoolean EvalNormal(const CATFrFCCvParam& iParam,
                                  CATMathVector& oNormalResult) = 0;

    virtual CATBoolean EvalCurvature(const CATFrFCCvParam& iParam,const CATMathDirection& iDir,
                                     double& oCurvature) = 0;

    virtual CATBoolean EvalNormalDerivative(const CATFrFCCvParam& iParam,
                                            CATMathVector& oN,
                                            CATMathVector& odN ) = 0;

    virtual CATGeometry* GetGeometry() const = 0;

    virtual CATFrFCompositeCurve* GetCcv() const = 0;
    virtual void SetCcv( CATFrFCompositeCurve* iCcv ) = 0;
    virtual void GetCombContinuity(CATListOfInt ioContinuity) const = 0;

    //True means that RefElement has C1 continuous vector field.
    //Default implementation return FALSE.
    virtual CATBoolean IsC1ContinuousOnDomain();

    // To get maximal angular deformation. The result is expressed in radian.
    double GetMaxAngleDeviation();

};

#endif // CATFrFRefElement_H





