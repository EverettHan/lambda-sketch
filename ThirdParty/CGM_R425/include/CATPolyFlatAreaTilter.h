#ifndef CATPolyFlatAreaTilter_h__
#define CATPolyFlatAreaTilter_h__

// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFlatAreaTilterFlatArea.h
// Header definition of CATPolyFlatAreaTilterFlatArea
//
//===================================================================
//
// Usage notes: deform the input mesh so that no horizontal triangle remaing (the coordinate z-component is modified accordingly)
//
//===================================================================
//
// 02/03/2018 : NUA : Creation
//===================================================================

// Math
#include "CATMathVector.h"
#include "CATSysErrorDef.h"

// export
#include "ExportedByCATPolyWatershedOperators.h"

struct CATPolyWatershedCallback;
class CATIPolyMesh;
class CATTolerance;

class ExportedByCATPolyWatershedOperators CATPolyFlatAreaTilter
{
public:
  //------------------ creation of the operator
  static CATPolyFlatAreaTilter * CreateInstance(CATIPolyMesh & iMesh, const CATTolerance & iTolObject);


  virtual ~CATPolyFlatAreaTilter() {}

  virtual HRESULT Run() = 0;

  virtual void SetProgressCallback(CATPolyWatershedCallback * iCB) = 0;

  virtual bool GetComputeStage() const = 0;
};

#endif // CATPolyFlatAreaTilter_h__
