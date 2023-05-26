#ifndef CATCSBBoxCurve2D_H
#define CATCSBBoxCurve2D_H

#include "CATCDSVirtual.h"
#include "CATICDSEnums.h"
#include "CATICDSBBoxCurve2DAdapter.h"
#include "CATCSRigidSet.h"
#include "CATCSCurve2D.h"
#include "CATCDSInline.h"

class CATCSBBoxCurve2D CATCDSFinal : public CATCSCurve2D
{
private:
  CATICDSBBoxCurve2DAdapter* _pAdapter;
public:
  CATCSBBoxCurve2D() : _pAdapter(0) {}
  ~CATCSBBoxCurve2D() { delete _pAdapter; _pAdapter = 0; }
  void SetAdapter(CATICDSBBoxCurve2DAdapter* pAdapter) { _pAdapter = pAdapter; }
  CATICDSBBoxCurve2DAdapter* GetAdapter() { return _pAdapter; }
  CATParamType GetLimits(double &oLow, double &oUp) CATCDSOverride { return _pAdapter->GetLimits(oLow, oUp); }
  void Evaluate2D(double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) CATCDSOverride { _pAdapter->Evaluate2D(iT, oaPoint, oaFirstDeriv, oaSecondDeriv, oaThirdDeriv); }
  void EvaluateAtDiscontinuity2D(int iIdx, CATDiscontinuitySide iSide, double iT, double* oaPoint, double* oaFirstDeriv, double* oaSecondDeriv, double* oaThirdDeriv = 0) CATCDSOverride { _pAdapter->EvaluateAtDiscontinuity2D(iIdx, iSide, iT, oaPoint, oaFirstDeriv, oaSecondDeriv, oaThirdDeriv); }
  void ApplyTransformation2D(double[][3]) CATCDSOverride {}
  void GetDirection2D(double &oX, double &oY) CATCDSOverride { _pAdapter->GetDirection2D(oX, oY); }
  int GetNbOfDiscontinuities() CATCDSOverride { return _pAdapter->GetNbOfDiscontinuities(); }
  void GetDiscontinuitiesParams(double *oaValues) CATCDSOverride { _pAdapter->GetDiscontinuitiesParams(oaValues); }
  CATCDSBoolean Regenerate() CATCDSOverride { return _pAdapter->Regenerate(); }
  CATCDSBoolean EvaluateLength(double iStart, double iEnd, double &oLength) CATCDSOverride { return _pAdapter->EvaluateLength(iStart, iEnd, oLength); }
  CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride { return _pAdapter->IsMatched(iType) || CATCSCurve2D::IsMatched(iType); }
};

#endif
