// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVertexGroupOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  mar 2004 Creation: dhp
//===================================================================
#ifndef CATPolyVertexGroupOper_h
#define CATPolyVertexGroupOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyAnalyzeOper.h"

class CATPolySpatialPartitionOper;

#include "CATListPV.h"
#include "CATListOfInt.h"

class CATIPolyMesh;

/**
This operator is used to merge vertex into groups such that the vertices
in each group are separated in distance by less than a tolerance.

The groups are returned as a list of pointers CATListOfInt whose
memory must be deallocated by the caller.
*/

class ExportedByCATPolyHealOperators CATPolyVertexGroupOper : public CATPolyAnalyzeOper
{
  
public :

  CATPolyVertexGroupOper (CATIPolyMesh * body,
    const CATListOfInt & vertices,
    CATPolySpatialPartitionOper * spatialPartitionOper);

  ~CATPolyVertexGroupOper (void);

  HRESULT Run (const double distance,
    CATListPV & vertexGroups);

private :

  CATPolySpatialPartitionOper * _spatialPartitionOper;

  CATListOfInt _vertices;

};

#endif


