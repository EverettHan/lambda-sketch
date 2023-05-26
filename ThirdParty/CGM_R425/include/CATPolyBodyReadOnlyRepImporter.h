// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyReadOnlyRepImporter.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// August 2009 Creation: zfi
//===================================================================

#ifndef CATPolyBodyReadOnlyRepImporter_H
#define CATPolyBodyReadOnlyRepImporter_H

#include "PolyVizUtils.h"
#include "CATErrorDef.h" // HRESULT.
#include "CATListPV.h"

class CATPolyBody;
class CATPolyBodyImportVizLayer;

class CATSurfacicRep;
class CATVizVertexBufferRep;

class CAT3DRep;
class CAT4x4Matrix;

class CATGraphicAttributeSet;
class CATGraphicMaterial;
class CATPolyBodyRepAdapter;

class ExportedByPolyVizUtils CATPolyBodyReadOnlyRepImporter
{
public:
  CATPolyBodyReadOnlyRepImporter();
  virtual ~CATPolyBodyReadOnlyRepImporter();

public:
  // Import a rep into a list of CATPolyBody's and position matrices.
  // The third argument is a mapping of the poly cells to graphics primitive and attributes.
  // This argument is optional. 
  HRESULT Import (const CAT3DRep& iRep,
                  CATListPV& oPolyBodies,CATListPV& oPositionMatrices,
                  CATListPV& oNonImportedReps,
                  CATPolyBodyImportVizLayer* ioVizLayer = 0);

  //deprecated
  HRESULT Import (const CAT3DRep& iRep,
                  CATListPV& oPolyBodies,CATListPV& oPositionMatrices,
                  CATPolyBodyImportVizLayer* ioVizLayer = 0);

  //some options, import rep with at least one face
  inline HRESULT SetRepsWithoutFacesImport(int iEnable);

  //import edges
  inline HRESULT SetEdgesImport(int iEnable);
  inline HRESULT SetPartialImport(int iEnable);

public:
  HRESULT ImportGeo (const CAT3DRep& iRep,
                     CATGraphicAttributeSet* iParentGA,
                     int* iParentTransparency, 
                     CATGraphicMaterial* iParentGM,
                     CATPolyBody*& oPolyBody,
                     CATPolyBodyImportVizLayer* ioVizLayer);

  HRESULT ImportViz(const CATVizVertexBufferRep& iRep,
                    CATGraphicAttributeSet* iParentGA,
                    int* iParentTransparency,
                    CATGraphicMaterial* iParentGM,
                    CATPolyBody*& oPolyBody,
                    CATPolyBodyImportVizLayer* ioVizLayer );
                               
private:
  HRESULT VisitRep (const CAT3DRep& iRep, 
                    const CAT4x4Matrix* iPosition,
                    CATGraphicAttributeSet* iParentGA,
                    int* iParentTransparency,
                    CATGraphicMaterial* iParentGM,
                    CATListPV& ioPolyBodies,CATListPV& ioPositionMatrices,
                    CATListPV& ioNonImportedReps,
                    CATPolyBodyImportVizLayer* ioVizLayer);

private:
  int _EdgesImport;
  int _RepsWithoutFacesImport;
  CATPolyBodyRepAdapter* _VizAdapter;
  int _PartialImport;
};

//inline
inline HRESULT CATPolyBodyReadOnlyRepImporter::SetRepsWithoutFacesImport(int iEnable)
{
  _RepsWithoutFacesImport=iEnable;
  return S_OK;
}


inline HRESULT CATPolyBodyReadOnlyRepImporter::SetEdgesImport(int iEnable)
{
  _EdgesImport=iEnable;
  return S_OK;
}

inline HRESULT CATPolyBodyReadOnlyRepImporter::SetPartialImport(int iEnable)
{
  _PartialImport=iEnable;
  return S_OK;
}

#endif
