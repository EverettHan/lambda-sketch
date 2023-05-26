// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyMeshFromCGRReader.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ndo
//===================================================================
#ifndef CATPolyMeshFromCGRReader_h
#define CATPolyMeshFromCGRReader_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.

class CATUnicodeString;
class CATIPolyMesh;


class ExportedByPolyVizUtils CATPolyMeshFromCGRReader
{

public:

  static HRESULT Read (const CATUnicodeString& iFileName, CATIPolyMesh& iMesh);

};

#endif

