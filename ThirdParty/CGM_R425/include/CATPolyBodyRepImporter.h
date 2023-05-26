// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRepImporter.h
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
#ifndef CATPolyBodyRepImporter_H
#define CATPolyBodyRepImporter_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"
#include "CATPolyDeprecatedM.h"

class CATPolyBody;
class CATPolyBodyImportVizLayer;

class CATSurfacicRep;
class CATVizVertexBufferRep;

class CAT3DRep;
class CAT4x4Matrix;
class CATGraphicAttributeSet;
class CATGraphicMaterial;

class ExportedByPolyVizUtils CATPolyBodyRepImporter
{

public:

  // YOU SHOULD NOT USE THIS METHOD
  // Tou should use CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter instead
  // Import a rep into a list of CATPolyBody's.
  // Position matrices are applied to each CATPolyBody.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  // Supported reps are CATSurfacicRep, CAT3DCustomRep, and CATVizVertexBufferRep, and nothing else.
  /**
   * @deprecated
   */
  POLY_DEPRECATED("Replace by calls to CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter",
    static HRESULT Import(const CAT3DRep& iRep,
      CATListPV& oPolyBodies,
      CATPolyBodyImportVizLayer* ioVizLayer = 0,
      int iImportEdges = 1,
      int iIgnorePolyBodysWithImportError = 0););

  // YOU SHOULD NOT USE THIS METHOD
  // Tou should use CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter instead
  // Import a rep into a list of CATPolyBody's and position matrices.
  // Position matrices are NOT applied to the CATPolyBody's.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional.
  // Supported reps are CATSurfacicRep, CAT3DCustomRep, and CATVizVertexBufferRep, and nothing else.
  /**
   * @deprecated
   */
  POLY_DEPRECATED("Replace by calls to CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter",
    static HRESULT Import(const CAT3DRep& iRep,
      CATListPV& oPolyBodies,
      CATListPV& oPositionMatrices,
      CATPolyBodyImportVizLayer* ioVizLayer = 0,
      int iImportEdges = 1,
      int iIgnorePolyBodysWithImportError = 0););

public:

  /**
   * @deprecated
   */
  POLY_DEPRECATED("Replace by calls to CAT3DRepHierarchyIterator and CATPolyBodyRepAdapter",
    static HRESULT Import(const CATSurfacicRep& iRep,
      CATPolyBody*& oPolyBody,
      CATPolyBodyImportVizLayer* ioVizLayer = 0,
      int iImportEdges = 1););

private:

  static HRESULT ImportGPRepPrivate(const CAT3DRep& iRep,
                                    const CAT4x4Matrix* iPosition,
                                    CATGraphicAttributeSet* iParentGA,
                                    int* iParentTransparency,
                                    CATGraphicMaterial* iParentGM,
                                    CATPolyBody*& oPolyBody,
                                    CATPolyBodyImportVizLayer* ioVizLayer , 
                                    int iImportEdges);

  static HRESULT ImportVizRepPrivate(const CATVizVertexBufferRep& iRep,
                                     const CAT4x4Matrix* iPosition,
                                     CATGraphicAttributeSet* iParentGA,
                                     int* iParentTransparency,
                                     CATGraphicMaterial* iParentGM,
                                     CATPolyBody*& oPolyBody,
                                     CATPolyBodyImportVizLayer* ioVizLayer , 
                                     int iImportEdges);

                               

  static HRESULT VisitRep (const CAT3DRep& iRep, 
                           const CAT4x4Matrix* iPosition,
                           CATGraphicAttributeSet* iParentGA,
                           int* iParentTransparency,
                           CATGraphicMaterial* iParentGM,
                           CATListPV& ioPolyBodies, 
                           CATListPV* ioPositionMatrices,
                           CATPolyBodyImportVizLayer* ioVizLayer, 
                           int iImportEdges,
                           int iIgnorePolyBodysWithImportError);

};

#endif
