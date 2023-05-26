//=============================================================================
// COPYRIGHT Dassault Systemes
//=============================================================================
//
// CATPolyBodyVizImporter
// Import a Rep description into a CATPolyBody.
//
//=============================================================================
// 2007-10-30   BPG: New.
//=============================================================================
#ifndef CATPolyBodyVizImporter_H
#define CATPolyBodyVizImporter_H

#include "PolyImportExport.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

#include "CATListOfInt.h"

//
class CATMathPoint;
class CATCGMHashTableWithAssoc;
class CATMapOfIntToInt;
class CATMapOfPtrToPtr;

class CATSurfacicRep;
// 
class CATVizVertexBufferRep;
class CATVizVertexBuffer;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;
class CATViz3DMarker;

class CAT3DFaceGP;
class CAT3DEdgeGP;
class CAT3DLineGP;
class CAT3DMarkerGP;

class CAT4x4Matrix;

template <class T> class CATVizPtrList;

// 
class CATPolyBodyVizImporterBuilder;
class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyVertex;
class CATIPolyCurve;
class CATPolyMeshVertexLine;
class CATIPolyMesh;

class CATPolyVizContainer;
class CATMapOfPtrToInt;

//
class ExportedByPolyImportExport CATPolyBodyVizImporter
{
public:

  CATPolyBodyVizImporter (const CATBoolean DoFailOnError = FALSE);
  virtual ~CATPolyBodyVizImporter();

public:

  /*
   * Import a list of line, edge and face GPs into a CATPolyBody.
   * The method creates a new CATPolyBody and a map from the CATPolyCell's to the GP's. 
   */
  HRESULT Import (const CATVizPtrList<CAT3DLineGP>& iLines,
                  const CATVizPtrList<CAT3DEdgeGP>& iEdges,
                  const CATVizPtrList<CAT3DFaceGP>& iFaces,
                  const CAT4x4Matrix * iPosition,
                  CATPolyBody*& oPolyBody,
                  CATMapOfPtrToPtr*& oMapFromPolyCellToGP);

public:

  HRESULT Import (const CATVizPtrList<CAT3DLineGP>& iLines,
                  const CATVizPtrList<CAT3DEdgeGP>& iEdges,
                  const CATVizPtrList<CAT3DFaceGP>& iFaces,
                  const CAT4x4Matrix * iPosition,
                  CATPolyBody*& oPolyBody,
                  const CATPolyVizContainer& iVizContainer,
                  CATMapOfPtrToInt*& oMapFromPolyCellToKey);

  HRESULT Import3DCellGPs (CATVizPtrList<CAT3DEdgeGP> &iEdges, CATVizPtrList<CAT3DFaceGP> &iFaces, 
                           const CATPolyVizContainer& iVizContainer,
                           const CAT4x4Matrix * iPosition,
                           CATPolyBody *&oPolyBody,
                           CATMapOfPtrToInt*& oMapFromPolyCellToKey);

public:  

  HRESULT ImportSurfacicRep(CATSurfacicRep &iSurfacicRep,
                            CATPolyBody *&oPolyBody,
                            CATCGMHashTableWithAssoc *&ioTabAssocFaceVzGPPolyFace,
                            CATCGMHashTableWithAssoc *&ioTabAssocEdgeVzGPPolyEdge);

  HRESULT Import3DCellGPs(CATVizPtrList<CAT3DEdgeGP> &iEdges, CATVizPtrList<CAT3DFaceGP> &iFaces,
                          const CAT4x4Matrix * iPosition,
                          CATPolyBody *&oPolyBody,
                          CATCGMHashTableWithAssoc *&ioTabAssocFaceVzGPPolyFace,
                          CATCGMHashTableWithAssoc *&ioTabAssocEdgeVzGPPolyEdge);

  HRESULT ImportWireGP(CATVizPtrList<CAT3DLineGP> &iList3DLineGPs,
                       CATVizPtrList<CAT3DMarkerGP> *iMarkerGPs,
                       CATPolyBody *&oPolyBody,
                       CATCGMHashTableWithAssoc *&ioTabAssocLineVzGPPolyEdge);

public:
  HRESULT ImportViz3DCells(CATVizVertexBuffer &iVizVertexBuffer, CATVizPtrList<CATViz3DEdge> &iEdges, CATVizPtrList<CATViz3DFace> &iFaces,
                           const CAT4x4Matrix * iPosition,
                           CATPolyBody *&oPolyBody,
                           CATCGMHashTableWithAssoc *&ioTabAssocFaceVzGPPolyFace,
                           CATCGMHashTableWithAssoc *&ioTabAssocEdgeVzGPPolyEdge);

  HRESULT ImportWireViz(CATVizPtrList<CATViz3DLine> &iLines,
                        CATVizPtrList<CATViz3DMarker> *iMarkers,
                        CATPolyBody *&oPolyBody,
                        CATCGMHashTableWithAssoc *&ioTabAssocLineVzGPPolyEdge);
  
public:
  inline HRESULT DoKeepGPLinks(CATBoolean iFlag = TRUE);
  inline HRESULT DoImportTextureCoords(CATBoolean iFlag = TRUE);

  //
protected:
  HRESULT CreateListOfGPObjects(CATSurfacicRep &iSurfacicRep,
                                CATVizPtrList<CAT3DEdgeGP> &oEdges,
                                CATVizPtrList<CAT3DFaceGP> &oFaces);

protected:
  CATBoolean _KeepGPLinks;
  CATBoolean _ImportTextureCoords;
  CATBoolean _DoFailOnError;
};

// ----------------------------------------------------------------------------

inline HRESULT
CATPolyBodyVizImporter::DoKeepGPLinks(CATBoolean iFlag)
{
  _KeepGPLinks = iFlag;
  return S_OK;
}

inline HRESULT
CATPolyBodyVizImporter::DoImportTextureCoords(CATBoolean iFlag)
{
  _ImportTextureCoords = iFlag;
  return S_OK;
}

#endif // !CATPolyBodyVizImporter_H
