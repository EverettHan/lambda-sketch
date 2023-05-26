#ifndef CATCContactWithMap_h
#define CATCContactWithMap_h

#include "GeoPlate.h"

#include "CATCContactDerivative.h"
#include "CATCrvParam.h"
#include "CATTolerance.h"

//#define VerifDeriv

class CATPCurve;
class CATCurve;
class CATEdgeCurve;
class CATMapX;
class CATMathFunctionX;
class CATSoftwareConfiguration;

class ExportedByGeoPlate   CATCContactWithMap : public CATCContactDerivative
 {
 public :

  CATCContactWithMap(CATPCurve* iPCurve1, CATPCurve* iPCurve2,const CATTolerance & iFactoryTolerance);
  ~CATCContactWithMap();

 protected :
	virtual void  BuildMap( CATEdgeCurve* iCurve,
													const CATCrvParam& iStartParam1, 
												  const CATCrvParam& iEndParam1,
												  const CATCrvParam& iStartParam2, 
													const CATCrvParam& iEndParam2,												 
													const CATBoolean iAdjustedMap,
													int iOption = 1, CATBoolean iForceEquiv=1,
													CATSoftwareConfiguration * iConfig=NULL);

	virtual double EvalMap(const double t1) const;

	virtual double FirstDerivativeMap(const double t1) const;

	virtual void VerifDeriv(int NbPoints , double * FromTab , double * ToTab) const;

	CATPCurve*  _PCurve1;
	CATPCurve*  _PCurve2;
	CATCurve *  _RefCurve;
	CATMapX * _MapX;
	CATMapX * _OldMapX;

	CATMathFunctionX * _FunctionX;
	CATBoolean _ForceEquiv;
	const CATTolerance & _Tolerance;
 };
#endif
