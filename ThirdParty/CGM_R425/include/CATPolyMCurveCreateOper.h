// COPYRIGHT DASSAULT SYSTEMES 2003, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMCurveCreateOper.h
// Header definition of CATPolyMCurveCreateOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// nov 2003 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveCreateOper_h
#define CATPolyMCurveCreateOper_h

#include "CATPolyMCurveCreateOperators.h"
#include "CATPolyBaseOper.h"

class CATListPtrCATPolyMCurve;
class CATIPolyMesh;


class CATPolyMCurveCreateOper : public CATPolyBaseOper
{

public :

  CATPolyMCurveCreateOper (CATIPolyMesh * polyMesh);

  CATPolyMCurveCreateOper (void);

  ~CATPolyMCurveCreateOper (void);

  virtual HRESULT Run (const CATListPtrCATPolyMCurve & iMeshCurves, CATListPtrCATPolyMCurve & oMeshCurves);

  virtual HRESULT Run (CATListPtrCATPolyMCurve & oMeshCurves);

protected :

  CATIPolyMesh * _polyMesh;

};

#endif

