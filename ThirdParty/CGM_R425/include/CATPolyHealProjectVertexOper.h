// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyHealProjectVertexOper.h
// Header definition of CATPolyHealProjectVertexOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// apr 2004 Creation: dhp
//===================================================================
#ifndef CATPolyHealProjectVertexOper_h
#define CATPolyHealProjectVertexOper_h

#include "CATPolyHealOperators.h"
#include "CATPolyModOper.h"

class CATIPolyMesh;
class CATPolyVertexProjectRecord;
class CATMathPoint;

class CATPolyGeomUtil;

/**
* This class is used by healing to project a vertex to the boundary
* of the mesh (either to another vertex or to a bar).
*/
class ExportedByCATPolyHealOperators CATPolyHealProjectVertexOper : public CATPolyModOper
{

public:

  CATPolyHealProjectVertexOper (CATIPolyMesh * body);

  ~CATPolyHealProjectVertexOper (void);

  HRESULT Run (const int vertex,
    const int vertex0,
    const int vertex1,
    const CATMathPoint & point);

  HRESULT Run (const int projectVertex,
    const int vertex);

  HRESULT Run (CATPolyVertexProjectRecord * projectRecord);

private:

};

#endif

