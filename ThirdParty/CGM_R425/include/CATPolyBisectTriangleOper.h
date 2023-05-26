// COPYRIGHT Dassault Systemes 2003, all rights reserved
//===================================================================
//
// CATPolyBisectTriangleOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  dec 2003 Creation: dhp
//===================================================================
#ifndef CATPolyBisectTriangleOper_h
#define CATPolyBisectTriangleOper_h

#include "CATPolyModOperators.h"
#include "CATPolyModOper.h"

class CATIPolyMesh;


class ExportedByCATPolyModOperators CATPolyBisectTriangleOper : public CATPolyModOper
{

public :

  CATPolyBisectTriangleOper (CATIPolyMesh * polyMesh);

  ~CATPolyBisectTriangleOper (void);

  HRESULT RunOnSelectedTriangle (const int triangle,
    const int vertex0,
    const int vertex1,
    const int newVertex,
    int & newTriangle0,
    int & newTriangle1);

  HRESULT RunOnSelectedTriangle (const int triangle,
    const int vertex0,
    const int vertex1,
    const int newVertex);

private :

};

#endif
