// COPYRIGHT Dassault Systemes 2004, all rights reserved
//===================================================================
//
// CATPolyDecimateBarsOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  jun 2004 Creation: dhp
//===================================================================
#ifndef CATPolyDecimateBarsOper_h
#define CATPolyDecimateBarsOper_h

#if 0

#include "CATPolyDecimateOperators.h"
#include "CATPolyModOper.h"

#include "CATBoolean.h"
#include "CATMathPoint.h"

class CATIPolyMesh;
class CATPolyMeshPartitionOper;


class ExportedByCATPolyDecimateOperators CATPolyDecimateBarsOper : public CATPolyModOper
{

public :

  CATPolyDecimateBarsOper (CATIPolyMesh * polyMesh,
    const CATListOfInt & barVertices0,
    const CATListOfInt & barVertices1,
    CATPolyMeshPartitionOper * meshPartition);

  ~CATPolyDecimateBarsOper (void);

  HRESULT Run (void);

  int GetNumCollapsedBars (void) const;

  void GetCollapsedBars (CATListOfInt & collapsedBarVertices0,
    CATListOfInt & collapsedBarVertices1) const;

  void GetRemovedTriangles (CATListOfInt & removedTriangles) const;

protected :

  CATBoolean GetBars (CATListOfInt & barVertices0,
    CATListOfInt & barVertices1) const;

  CATPolyMeshPartitionOper * _meshPartition;

  CATListOfInt _barVertices0;
  CATListOfInt _barVertices1;

  double _tolerance;

  int _numCollapsedBars;

  CATListOfInt _collapsedBarVertices0;
  CATListOfInt _collapsedBarVertices1;

  CATListOfInt _removedTriangles;

};

#endif
#endif
