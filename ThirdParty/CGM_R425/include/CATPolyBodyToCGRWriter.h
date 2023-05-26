// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyToCGRWriter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ndo, ZFI
//===================================================================
#ifndef CATPolyBodyToCGRWriter_h
#define CATPolyBodyToCGRWriter_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"
#include "CATBoolean.h"

class CATUnicodeString;
class CATPolyBody;
class CAT4x4Matrix;

class CATPolyBodyVisLayerSet;
class CATPolyBodyImportVizLayer;


class ExportedByPolyVizUtils CATPolyBodyToCGRWriter
{

public:

  static HRESULT Write (const CATUnicodeString& iFileName, const CATPolyBodyVisLayerSet& iPolyBodies, const CATBoolean iStreamAsVisPrimitiveGroupRep = FALSE);

  // Write a CGR a list of CATPolyBody's into a CGR file.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CATListPV& iPolyBodies, 
                        const CATPolyBodyImportVizLayer* iImportVizLayer = 0, CATBoolean iWireType = FALSE);

  // Write a CGR a list of CATPolyBody's and their position matrices into a CGR file.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CATListPV& iPositionMatrices,
                        const CATListPV& iPolyBodies, 
                        const CATPolyBodyImportVizLayer* iImportVizLayer = 0,CATBoolean iWireType = FALSE);

public:

  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CATPolyBody& iPolyBody, 
                        const CATPolyBodyImportVizLayer* iImportVizLayer = 0,CATBoolean iWireType = FALSE);

  static HRESULT Write (const CATUnicodeString& iFileName, 
                        const CAT4x4Matrix& iPosition,
                        const CATPolyBody& iPolyBody, 
                        const CATPolyBodyImportVizLayer* iImportVizLayer = 0,CATBoolean iWireType = FALSE);

};

#endif
