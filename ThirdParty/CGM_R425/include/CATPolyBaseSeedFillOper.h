// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBaseSeedFillOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// dec 2004 Creation: dhp
//===================================================================
#ifndef CATPolyBaseSeedFillOper_h
#define CATPolyBaseSeedFillOper_h

#include "CATPolyAnalyzeOperators.h"
#include "CATPolyAnalyzeOper.h"

#include "CATListOfInt.h"
#include "CATListOfDouble.h"
#include "CATListPV.h"
#include "CATBoolean.h"

class CATIPolyMesh;
class CATSetOfInt;
class CATMathPlane;


class ExportedByCATPolyAnalyzeOperators CATPolyBaseSeedFillOper : public CATPolyAnalyzeOper
{
  
public :

  CATPolyBaseSeedFillOper (CATIPolyMesh * polyMesh);

  ~CATPolyBaseSeedFillOper (void);

  HRESULT Run (const int triangle,
    CATListOfInt & triangles);

protected :

  virtual CATBoolean SetupTriangle (const int triangle);

  virtual CATBoolean OkToFill (const int seedTriangle,
    const int triangleToFill) const;

  CATBoolean SeedFill (const int triangle,
    CATListOfInt & triangles);

  CATSetOfInt * _triangleHashTable;

  int _numTriangles;

};

#endif
