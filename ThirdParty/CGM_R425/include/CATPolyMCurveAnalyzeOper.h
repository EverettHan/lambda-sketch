// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMCurveAnalyzeOper.h
// Header definition of CATPolyMCurveAnalyzeOper.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveAnalyzeOper_H
#define CATPolyMCurveAnalyzeOper_H

#include "CATPolyMCurveAnalyzeOperators.h"
#include "CATPolyBaseOper.h"

class CATPolyMCurve;
class CATListPtrCATPolyMCurve;


class ExportedByCATPolyMCurveAnalyzeOperators CATPolyMCurveAnalyzeOper : public CATPolyBaseOper
{

public:

  CATPolyMCurveAnalyzeOper (void);

  ~CATPolyMCurveAnalyzeOper (void);

  virtual HRESULT Run (CATPolyMCurve * meshCurve);

  virtual HRESULT Run (const CATListPtrCATPolyMCurve & meshCurves);

protected :

};

#endif

