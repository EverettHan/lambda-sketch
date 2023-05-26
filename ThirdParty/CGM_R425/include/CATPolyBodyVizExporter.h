//=============================================================================
// COPYRIGHT Dassault Systemes 2007, 2008
//=============================================================================
//
// CATPolyBodyVizExporter
// Export a CATPolyBody into a Rep description
//
//=============================================================================
// 2007-10-30   BPG: New.
//=============================================================================
#ifndef CATPolyBodyVizExporter_H
#define CATPolyBodyVizExporter_H

#include "PolyImportExport.h"

#include "CATBoolean.h"
#include "CATErrorDef.h"

#include "CATPolyMacroTopologyFwd.h"
#include "CATPolyMicroTopologyFwd.h"

//
class CATMapOfPtrToPtr;
class CATCGMHashTableWithAssoc;

// 
class CATVizVertexBuffer;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;

class CAT3DFaceGP;
class CAT3DEdgeGP;
class CAT3DLineGP;

template <class T> class CATVizPtrList;


//
class ExportedByPolyImportExport CATPolyBodyVizExporter
{
public:

  CATPolyBodyVizExporter();
  virtual ~CATPolyBodyVizExporter();

public:

  // TO BE IMPLEMENTED...

  // You'll need to do a CATVisHelpers::SetVertexBuffer on output faceGPs afterwards
  HRESULT Export (const CATPolyBody& iPolyBody,
                  CATVizPtrList<CAT3DLineGP>& ioLines,
                  CATVizPtrList<CAT3DEdgeGP>& ioEdges,
                  CATVizPtrList<CAT3DFaceGP>& ioFaces,
                  CATVizVertexBuffer*& oVizVertexBuffer, 
                  CATMapOfPtrToPtr* ioPolyCellToVizGP) const;

  HRESULT Export (const CATPolyBody& iPolyBody,
                  CATVizPtrList<CATViz3DLine>& ioLines,
                  CATVizPtrList<CATViz3DEdge>& ioEdges,
                  CATVizPtrList<CATViz3DFace>& ioFaces,
                  CATVizVertexBuffer*& oVizVertexBuffer, 
                  CATMapOfPtrToPtr* ioPolyCellToVizGP) const;

public:

  // TO BE ELIMINATED...

  // You'll need to do a CATVisHelpers::SetVertexBuffer on output faceGPs afterwards
  HRESULT Export3DCellGPs(CATVizPtrList<CAT3DEdgeGP> &ioEdges, CATVizPtrList<CAT3DFaceGP> &ioFaces,
                          CATPolyBody &iPolyBody,CATVizVertexBuffer *& oVizVertexBuffer,
                          CATCGMHashTableWithAssoc *&ioTabAssocPolyFaceVzGPFace,
                          CATCGMHashTableWithAssoc *&ioTabAssocPolyEdgeVzGPEdge) const;

  HRESULT ExportWireGP(CATVizPtrList<CAT3DLineGP> &ioList3DLineGPs,
                       CATPolyBody &iPolyBody,
                       CATCGMHashTableWithAssoc *&ioPolyEdgeVizLineMap) const;

public:

  // TO BE ELIMINATED...

  HRESULT ExportViz3DCells(CATVizPtrList<CATViz3DEdge> &ioEdges, CATVizPtrList<CATViz3DFace> &ioFaces,
                            CATPolyBody &iPolyBody,CATVizVertexBuffer *&iVizVertexBuffer,
                            CATCGMHashTableWithAssoc *&ioTabAssocPolyFaceVzGPFace,
                            CATCGMHashTableWithAssoc *&ioTabAssocPolyEdgeVzGPEdge) const;

  HRESULT ExportWireViz(CATVizPtrList<CATViz3DLine> &ioLines,
                        CATPolyBody &iPolyBody,
                        CATCGMHashTableWithAssoc *&ioPolyEdgeVizLineMap) const;
};

#endif // !CATPolyBodyVizExporter_H
