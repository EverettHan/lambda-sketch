// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshToCGRWriter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ndo
//===================================================================
#ifndef CATPolyMeshToCGRWriter_h
#define CATPolyMeshToCGRWriter_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.

class CATUnicodeString;
class CATIPolyMesh;


class ExportedByPolyVizUtils CATPolyMeshToCGRWriter
{

public:

  static HRESULT Write (const CATUnicodeString& iFileName, const CATIPolyMesh& iMesh);

};

#endif

