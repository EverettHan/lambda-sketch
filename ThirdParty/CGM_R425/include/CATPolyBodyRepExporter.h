// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepExporter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2008 Creation: ndo, ZFI
// November 2017 Modification JXO: ExportExploded with marker type
//===================================================================
#ifndef CATPolyBodyRepExporter_h
#define CATPolyBodyRepExporter_h

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
class CATPolyBodyVisLayer;
class CATPolyBodyVisLayerSet;

/**
 * A service to export a CATPolyBody or a set of CATPolyBody (with or without visualization attributes) into a CATRep.
 */
class ExportedByPolyVizUtils CATPolyBodyRepExporter
{

public:

  /**
   * Exports a CATPolyBody and constructs a CAT3DRep (CAT3DBagRep).  
   * An optional position matrix and optional visualization attributes can be specified.
   */
  static HRESULT Export (const CATPolyBody& iPolyBody, const CAT4x4Matrix* iPosition, const CATPolyBodyVisLayer* iVisLayer, CAT3DRep*& oRep);

  /**
   * Exports a set of CATPolyBody (from a CATPolyBodyVisLayerSet) into a CAT3DRep (CAT3DBagRep).
   */
  static HRESULT Export (const CATPolyBodyVisLayerSet& iPolyBodies, CAT3DRep*& oRep);

  // Export a list of CATPolyBody's into a rep.
  // The third and fourth arguments are mappings of the GPs to the poly cells.
  // These arguments are optional.
  static HRESULT Export (const CATListPV& iPolyBodies,
                         CAT3DRep*& oRep,
                         const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                         CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                         int iWithVertices = 0,
                         int iWithEdges=1);

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

public:

  static HRESULT Export (const CATPolyBody& iPolyBody, 
                         CAT3DRep*& oRep, 
                         const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                         CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                         int iWithVertices = 0, 
                         int iWithEdges=1);

  static HRESULT Export (const CATPolyBody& iPolyBody, 
                         const CAT4x4Matrix& iPosition, 
                         CAT3DRep*& oRep, 
                         const CATPolyBodyImportVizLayer* iImportVizLayer = 0,
                         CATPolyBodyExportVizLayer* ioExportVizLayer = 0,
                         int iWithVertices = 0, 
                         int iWithEdges=1);



  static HRESULT GetDefaultGAForVizFace(CATGraphicAttributeSet& ioAttr);
  static HRESULT GetDefaultGAForVizEdge(CATGraphicAttributeSet& ioAttr);
  static HRESULT GetDefaultGAForVizVertex(CATGraphicAttributeSet& ioAttr);
  static HRESULT GetDefaultGAForVizLine(CATGraphicAttributeSet& ioAttr);

  // With exploded mode
  static HRESULT ExportExploded (const CATPolyBody& iPolyBody,
                                 CAT3DRep*& oRep,
                                 const CATPolyBodyImportVizLayer* iImportVizLayer,
                                 CATPolyBodyExportVizLayer* ioExportVizLayer,
                                 int iWithVertices,
                                 int iWithEdges,
                                 int iMarkerType);

  static HRESULT ExportExploded (const CATPolyBody& iPolyBody, 
                                 const CAT4x4Matrix& iPosition, 
                                 CAT3DRep*& oRep,
                                 const CATPolyBodyImportVizLayer* iImportVizLayer,
                                 CATPolyBodyExportVizLayer* ioExportVizLayer,
                                 int iWithVertices,
                                 int iWithEdges,
                                 int iMarkerType);


private:

  static HRESULT ExportPrivate (const CATPolyBody& iPolyBody, 
                                const CATPolyBodyVisLayer* iVisLayer,  // If different from 0, then superceeds iImportVizLayer.
                                const CAT4x4Matrix& iPosition, 
                                CAT3DRep*& oRep, 
                                const CATPolyBodyImportVizLayer& iImportVizLayer,
                                CATPolyBodyExportVizLayer& ioExportVizLayer,
                                int iWithVertices, 
                                int iWithEdges,
                                int iExplodedMode,
                                int iMarkerType);


};

#endif
