// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealVertexGroupOper.h
// Header definition of CATPolyHealVertexGroupOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyHealVertexGroupOper_h
#define CATPolyHealVertexGroupOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"

#include "CATListPV.h"
#include "CATListOfInt.h"
#include "CATBooleanDef.h"

class CATIPolyMesh;

class CATPolySpatialPartitionOper;

/**
This operator is used to merge vertices into groups such that the vertices
in each group are separated in distance by less than a tolerance.
*/

class ExportedByCATPolyHealOperators CATPolyHealVertexGroupOper : public CATPolyModOper
{

public:

  CATPolyHealVertexGroupOper (CATIPolyMesh * polyMesh,
    const CATListOfInt & vertices);

  ~CATPolyHealVertexGroupOper (void);

  void SetTolerance (const double vertexTolerance);

  HRESULT Run (void);

  int GetNumVertexGroups (void) const;

private:

  CATBoolean GetVertexGroups (CATListPV & vertexGroups) const;

  CATBoolean MergeVertexGroups (const CATListPV & vertexGroups);

  CATBoolean MergeVertexGroup (const CATListOfInt & vertexGroup);

  CATListOfInt _vertices;

  double _tolerance;

  CATPolySpatialPartitionOper * _spatialPartitionOper;

};

#endif

