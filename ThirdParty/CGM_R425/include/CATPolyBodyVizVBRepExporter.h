// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVizVBRepExporter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2012 Creation: ZFI
//===================================================================

#ifndef CATPolyBodyVizVBRepExporter_h
#define CATPolyBodyVizVBRepExporter_h

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"


class CATUnicodeString;
class CATPolyBody;

class CATPolyBodyImportVizLayer;
class CATPolyBodyExportVizLayer;
class CAT4x4Matrix;
class CAT3DRep;
class CATGraphicAttributeSet;
class CATIPolyMesh;

class ExportedByPolyVizUtils CATPolyBodyVizVBRepExporter
{

public:

  // Export a list of CATPolyBody's with their position matrices into a rep.
  // The third and fourth arguments are mappings of the GPs to the poly cells.
  // These arguments are optional.
  static HRESULT Export (const CATListPV& iPolyBodies,
                         const CATListPV& iPositionMatrices,
                         CAT3DRep*& oRep,
                         const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                         CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                         int iWithVertices = 0, 
                         int iWithEdges=1);

  static HRESULT Export (const CATPolyBody& iPolyBody, 
                         const CAT4x4Matrix* iPosition, 
                         CAT3DRep*& oRep, 
                         const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                         CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                         int iWithVertices = 0, 
                         int iWithEdges=1);


private:
  static HRESULT ExportPrivate(const CATPolyBody& iPolyBody, 
                               const CAT4x4Matrix& iPosition, 
                               CAT3DRep*& oRep, 
                               const CATPolyBodyImportVizLayer& iImportVizLayer,
                               CATPolyBodyExportVizLayer& ioExportVizLayer,
                               int iWithVertices, 
                               int iWithEdges);


};

#endif
