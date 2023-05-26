#pragma once
#include "PolyBodyBoolean.h"

#include "CATIPolyMesh.h"
#include "CATIPolyHoleBoundary.h"

/**
* Operator that computes the mid surface between two surfaces
*/
class ExportedByPolyBodyBoolean CATPolyMidSurfacer {
public:
  //CATPolyMidSurfacer();

  HRESULT Run(const CATIPolyMesh& m1, const CATIPolyMesh& m2, CATIPolyMesh* om, const CATIPolyHoleBoundary* midBoundary = nullptr);
};
