// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//===================================================================
//
// CAT3DRepParser.h
//
//===================================================================
//
// February 2008 Creation: MNA
// Feb 2009 : ZFI, add GA, positions
//===================================================================
#ifndef CAT3DRepParser_H
#define CAT3DRepParser_H

#include "PolyImportExport.h"

#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATListOfInt.h"

// The preferred way of parsing a bag rep is to use the following iterator
// through a hierarchy of reps.
#include "CAT3DRepHierarchyIterator.h"

class CAT3DGeomRep;
class CATRep;
class CAT3DRep;
class CAT4x4Matrix;

class CATSurfacicRep;
class CAT3DLineRep;
class CAT3DPointRep;
class CAT3DCustomRep;
class CAT3DFaceGP;
class CAT3DEdgeGP;
class CAT3DLineGP;
class CAT3DCylinderGP;
class CAT3DCurvedPipeGP;

class CATVizVertexBuffer;
class CATViz3DFace;
class CATViz3DEdge;
class CATViz3DLine;
class CAT3DMarkerGP;

class CATMapOfPtrToPtr;
class CATVizVertexBufferRep;

template <class T> class CATVizPtrList;

/**
 * Parser of a CATRep or a CAT3DBagRep tree and appends all its leaf reps into a list.
 * Optionally, the parser returns the position matrices for the leaf reps.
 * Filtering of the reps is also possible during parsing.
 */
class ExportedByPolyImportExport CAT3DRepParser
{
public:

  /**
   * A filter interface which can be implemented for selection of the reps.
   */
  class Filter : public CAT3DRepHierarchyIterator::Filter
  {
  public:

    /**
     * Returns <tt>TRUE</tt> if the rep should be selected in the parsing.
     */
    virtual CATBoolean Select (const CATRep& iRep) = 0;

  };

public:

  /**
   * Extracts the list of leaf rep entities by parsing recursively the bag reps from a CATRep.
   */
  HRESULT Parse (CATRep* iRep,
                 CATVizPtrList<CATRep>& oLeafReps,
                 Filter* iFilter = 0);

  /**
   * Extracts the list of leaf rep entities by parsing recursively the bag reps from a CATRep.
   */
  HRESULT Parse (CATRep* iRep,
                 CATVizPtrList<CATRep>& oLeafReps,
                 CATVizPtrList<CAT4x4Matrix>& oPositions,
                 const CAT4x4Matrix* iInitPosition = NULL,
                 Filter* iFilter = 0);

  /**
   * Extracts the list of graphic primitive entities by parsing recursively the bag reps from a CATRep.
   */
  HRESULT Parse (CATRep* iRep,
                 CATVizPtrList<CAT3DEdgeGP>& ioInputEdges,
                 CATVizPtrList<CAT3DFaceGP>& ioInputFaces,
                 CATVizPtrList<CAT3DLineGP>& ioInputLines,
                 CATVizPtrList<CAT3DCylinderGP>& ioCylinderGPs,
                 CATVizPtrList<CAT3DCurvedPipeGP>& ioCurvedPipeGPs,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 CATMapOfPtrToPtr* ioMapFromGPToGM = 0,
                 Filter* iFilter = 0);

  /**
   * Extracts the list of graphic primitive entities by parsing recursively the bag reps from a CATRep.
   */
  HRESULT Parse (CATRep* iRep,
                 CATVizPtrList<CAT3DEdgeGP>& ioInputEdges,
                 CATVizPtrList<CAT3DFaceGP>& ioInputFaces,
                 CATVizPtrList<CAT3DLineGP>& ioInputLines,
                 CATVizPtrList<CAT3DCylinderGP>& ioCylinderGPs,
                 CATVizPtrList<CAT3DCurvedPipeGP>& ioCurvedPipeGPs,
                 CATVizPtrList<CAT3DMarkerGP>& ioMarkerGPs,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 Filter* iFilter = 0);

  /**
   * Extracts the list of viz primitive entities by parsing recursively the bag reps from a CATRep.
   */
  HRESULT Parse (CATRep* iRep,
                 CATVizVertexBuffer*& oBuffer,
                 CATVizPtrList<CATViz3DFace>& oVizFace,
                 CATVizPtrList<CATViz3DEdge>& oVizEdge,
                 CATVizPtrList<CATViz3DLine>& oVizLine,
                 Filter* iFilter = 0);

public:

  HRESULT Parse (const CAT3DGeomRep* ipGeomRep,
                 CATVizPtrList<CAT3DEdgeGP>& ioInputEdges,
                 CATVizPtrList<CAT3DFaceGP>& ioInputFaces,
                 CATVizPtrList<CAT3DLineGP>& ioInputLines,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 CATMapOfPtrToPtr* ioMapFromGPToGM = 0,
                 Filter* iFilter = 0);

  HRESULT Parse (const CATVizVertexBufferRep* iVBRep,
                 CATVizPtrList<CATViz3DEdge>& ioInputEdges,
                 CATVizPtrList<CATViz3DFace>& ioInputFaces,
                 CATVizPtrList<CATViz3DLine>& ioInputLines,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 Filter* iFilter = 0);

  HRESULT Parse (const CAT3DLineRep * ipLineRep,
                 CATVizPtrList<CAT3DLineGP>& ioInputLines,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 Filter* iFilter = 0);

public:

  HRESULT CreateList3DEdgeGPs(CATSurfacicRep* ipSurfacicRep, CATVizPtrList<CAT3DEdgeGP>*& iopList3DEdgeGPs);

public:

  /**
   * Detects what kind of objects are in the rep. Based on the kind of
   * terminal reps and the kind of graphic primitives contained in
   * them only.
   */
  HRESULT Parse (const CATRep * iRep,
                 CATBoolean & oHasFaces,
                 CATBoolean & oHasCylinders,
                 CATBoolean & oHasCurvedPipes,
                 CATBoolean & oHasEdges,
                 CATBoolean & oHasLines,
                 CATBoolean & oHasVertices,
                 CATBoolean iFilterNoShow = FALSE) const;

  /**
   * Detects what kind of objects (dimension) are in the rep. Based
   * on the kind of terminal reps and the kind of graphic primitives
   * contained in them and also on the type of the terminal reps,
   * obtained from the CATGraphicAttributeSet contained in it.
   */
  HRESULT Parse (const CATRep * iRep,
                 CATBoolean & oHasVolumes,
                 CATBoolean & oHasSurfaces,
                 CATBoolean & oHasWires,
                 CATBoolean & oHasVertices,
                 CATBoolean iFilterNoShow = FALSE) const;

  CATBoolean HasFaces       (const CATRep * iRep) const;
  CATBoolean HasPlanes      (const CATRep * iRep) const;
  CATBoolean HasCylinders   (const CATRep * iRep) const;
  CATBoolean HasCurvedPipes (const CATRep * iRep) const;
  CATBoolean HasEdges       (const CATRep * iRep) const;
  CATBoolean HasLines       (const CATRep * iRep) const;
  CATBoolean HasVertices    (const CATRep * iRep) const;

  /** Parse only faces (better performances) */
  HRESULT Parse (const CAT3DGeomRep* ipGeomRep,
                 CATVizPtrList<CAT3DFaceGP>& ioInputFaces,
                 CATMapOfPtrToPtr* ioMapFromGPToGA = 0,
                 CATMapOfPtrToPtr* ioMapFromGPToGM = 0,
                 Filter* iFilter = 0);
private:

  HRESULT WhatTypesInTheRep (const CATRep & iRep,
                             CATBoolean & oHasFaces, CATBoolean & oHasCylinders, CATBoolean & oHasCurvedPipes,
                             CATBoolean & oHasEdges, CATBoolean & oHasLines,     CATBoolean & oHasVertices,
                             Filter* iFilter = 0) const;

  HRESULT WhatTypesInTheRep (const CATRep & iRep,
                             CATBoolean & oHasVolumes, CATBoolean & oHasSurfaces, CATBoolean & oHasWires,
                             CATBoolean & oHasVertices,
                             Filter* iFilter = 0) const;

  HRESULT CreateListOfGraphicPrimitives (CAT3DCustomRep& ipCustomRep, CATVizPtrList<CAT3DEdgeGP>& ioInputEdges,CATVizPtrList<CAT3DFaceGP>& ioInputFaces,CATVizPtrList<CAT3DLineGP>& ioInputLines, CATVizPtrList<CAT3DMarkerGP>& ioInputMarkers,CATMapOfPtrToPtr* ioMapFromGPToGA=0);
  HRESULT CreateListOfGraphicPrimitives (CAT3DCustomRep& ipCustomRep, CATVizPtrList<CAT3DEdgeGP>& ioInputEdges,CATVizPtrList<CAT3DFaceGP>& ioInputFaces,CATVizPtrList<CAT3DLineGP>& ioInputLines, CATMapOfPtrToPtr* ioMapFromGPToGA=0);

};

#endif
