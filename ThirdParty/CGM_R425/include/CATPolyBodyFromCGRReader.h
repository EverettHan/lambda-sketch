// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyFromCGRReader.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ndo, zfi
// March 2022 :
// YOU SHOULD NOT USE THIS FILE
// Tou should use CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter instead
//===================================================================
#ifndef CATPolyBodyFromCGRReader_h
#define CATPolyBodyFromCGRReader_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"

class CATUnicodeString;
class CATPolyBody;
class CATPolyBodyImportVizLayer;


class ExportedByPolyVizUtils CATPolyBodyFromCGRReader
{

public:

  // YOU SHOULD NOT USE THIS METHOD
  // Read a CGR into a list of CATPolyBody's.
  // Position matrices are applied to each CATPolyBody.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  // Supported reps are CATSurfacicRep, CAT3DCustomRep, and CATVizVertexBufferRep, and nothing else.
  static HRESULT Read (const CATUnicodeString& iFileName,
                       CATListPV& oPolyBodies,
                       CATPolyBodyImportVizLayer* ioVizLayer = 0);

  // YOU SHOULD NOT USE THIS METHOD
  // Read a CGR into a list of CATPolyBody's and position matrices.
  // Position matrices are NOT applied to the CATPolyBody's.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  // Supported reps are CATSurfacicRep, CAT3DCustomRep, and CATVizVertexBufferRep, and nothing else.
  static HRESULT Read (const CATUnicodeString& iFileName,
                       CATListPV& oPolyBodies,
                       CATListPV& oPositionMatrices,
                       CATPolyBodyImportVizLayer* ioVizLayer = 0);

};

#endif
