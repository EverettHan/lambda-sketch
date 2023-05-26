// COPYRIGHT Dassault Systemes 2003, all rights reserved.
//===================================================================
//
// CATPolyMCurveModOper.h
// Header definition of CATPolyMCurveModOper.
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyMCurveModOper_H
#define CATPolyMCurveModOper_H

#include "CATPolyMCurveModOperators.h"
#include "CATPolyBaseOper.h"

class CATIPolyMesh;
class CATPolyRefineMap;


class ExportedByCATPolyMCurveModOperators CATPolyMCurveModOper : public CATPolyBaseOper
{

public:

  CATPolyMCurveModOper (CATIPolyMesh * polyMesh);

  ~CATPolyMCurveModOper (void);

  virtual HRESULT Run (CATPolyRefineMap * triangleMap);

  virtual HRESULT Run (void);

protected :

  CATIPolyMesh * _polyMesh;

};

#endif
