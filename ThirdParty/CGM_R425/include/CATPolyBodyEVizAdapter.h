// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyEVizAdapter.h
//
//===================================================================
//
// February 2009  Creation: NDO
//===================================================================
#ifndef CATPolyBodyEVizAdapter_H
#define CATPolyBodyEVizAdapter_H

#include "PolyVizAdapters.h"
#include "CATIAV5Level.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

#include "CATPolyRefinerDefaultParams.h"
#include "CATPolyUVRefiner.h"

class CATVizPrimitive;
class CATVizVertexBuffer;
class CATViz3DFace;
class CATViz3DEdge;
class CATVizUV3DEdge;
class CATVizUV3DFace;
class CATViz3DLine;
class CATViz3DMarker;
class CAT4x4Matrix;

class CATVizPrimitive;

class CATPolyBody;
class CATPolyFace;
class CATPolyEdge;
class CATPolyCell;

class CATPolyUVRefiner;
class CATPolyBodyVizDiagnosis;

template <class T> class CATVizPtrList;


/*
This is an adapter that constructs a CATPolyBody view of viz (or GP) primitives.
The supported viz primitives (CATVizPrimitive) are:
  o CATViz3DLine
  o CATViz3DEdge
  o CATViz3DFace
and also more generically:
  o CATVizPrimitive

This adapter deals directly with the viz (or GP) primitives (not the rep's; 
See CATPolyBodyEVizRepAdapter for rep's.)

This is an adapter that constructs a CATPolyBody view of lists of UV lines, UV edges and UV faces.
The adapter makes new CATPolyCell's that encapsulate the viz primitives and adds them to 
the CATPolyBody.  In option, the adapter maps the constructed CATPolyCell's to the viz primitives.

This adapter embeds a complete or partial list of viz primitives into a CATPolyBody.  For instance, if the list of 
CATVizUV3DEdge is empty, it provides a view of the CATVizUV3DFace without the edges.  It can process a single face 
or edge too.

This adapter provide a view of the refined UV data.  This is the "expanded" view of the viz data.
Refinement and tessellation are controlled by a unique sag parameter.

Construction of the CATPolyCell's is CPU and memory efficient.  There is no duplication of the visu data.
Working layers (cache) are transparently instanciated when the CATPolyCell data are accessed (for instance
through layers or iterators.)  These working layers are released when the data are no longer accessed. 
It does not keep large buffers in memory when they are not needed (smart memory management.)

The visu objects must remain valid during the whole lifecycle of the CATPolyBody.
*/
class ExportedByPolyVizAdapters CATPolyBodyEVizAdapter
{

public:

  CATPolyBodyEVizAdapter (CATPolyBodyVizDiagnosis* iDiagnosis = 0);

  // Deprecated.
  CATPolyBodyEVizAdapter (const double iSag, 
                          CATPolyBodyVizDiagnosis* iDiagnosis = 0);

  //CATPolyBodyEVizAdapter (const unsigned int iUniformRefinementLevel,
                          //CATMapOfPtrToInt* iBadPrimitives = 0);

  ~CATPolyBodyEVizAdapter ();

public:

  // Construct a CATPolyBody view of a list of CATVizUV3DLine's.
  // The CATViz3DLine's must be of type CATVizUV3DLine.
  // (Otherwise, the call will fail!)  See CATPolyBodyVizAdapter for other types.
  HRESULT Run (const CATVizPtrList<CATViz3DLine>& iLines,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CATVizUV3DEdge's and CATVizUV3DFace's.
  // (Case of global CATVizVertexBuffer associated to the rep.)
  // The CATViz3DEdge's and CATViz3DFace's must be of type CATVizUV3DEdge and CATVizUV3DFace, respectively.
  // (Otherwise, the call will fail!)  See CATPolyBodyVizAdapter for other types.
  HRESULT Run (CATVizVertexBuffer& iVizVertexBuffer, 
               const CATVizPtrList<CATVizUV3DEdge>& iEdges, 
               const CATVizPtrList<CATVizUV3DFace>& iFaces,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CATVizUV3DEdge's and CATVizUV3DFace's.
  // (Case of global CATVizVertexBuffer associated to the rep.)
  // The CATViz3DEdge's and CATViz3DFace's must be of type CATVizUV3DEdge and CATVizUV3DFace, respectively.
  // (Otherwise, the call will fail!)  See CATPolyBodyVizAdapter for other types.
  HRESULT Run (CATVizVertexBuffer& iVizVertexBuffer, 
               const CATVizPtrList<CATViz3DEdge>& iEdges, 
               const CATVizPtrList<CATViz3DFace>& iFaces,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CATVizUV3DEdge's and CATVizUV3DFace's.
  // The CATViz3DEdge's and CATViz3DFace's must be of type CATVizUV3DEdge and CATVizUV3DFace, respectively.
  // (Otherwise, the call will fail!)  See CATPolyBodyVizAdapter for other types.
  HRESULT Run (const CATVizPtrList<CATVizUV3DEdge>& iEdges, 
               const CATVizPtrList<CATVizUV3DFace>& iFaces,
               CATPolyBody& ioPolyBody) const;

  // Construct a CATPolyBody view of a list of CATVizUV3DEdge's and CATVizUV3DFace's.
  // The CATViz3DEdge's and CATViz3DFace's must be of type CATVizUV3DEdge and CATVizUV3DFace, respectively.
  // (Otherwise, the call will fail!)  See CATPolyBodyVizAdapter for other types.
  HRESULT Run (const CATVizPtrList<CATViz3DEdge>& iEdges, 
               const CATVizPtrList<CATViz3DFace>& iFaces,
               CATPolyBody& ioPolyBody) const;

public:

  // Construct a CATPolyBody view of a CATViz3DLine.
  // Return the CATPolyCell associated to the CATViz3DLine.
  HRESULT Run (CATViz3DLine& iVizLine, 
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CATViz3DEdge.
  // Return the CATPolyCell associated to the CATViz3DEdge.
  HRESULT Run (CATVizUV3DEdge& iVizEdge, 
               CATVizVertexBuffer& iVizVertexBuffer,
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CATViz3DEdge.
  // Return the CATPolyCell associated to the CATViz3DEdge.
  HRESULT Run (CATViz3DEdge& iVizEdge, 
               CATVizVertexBuffer& iVizVertexBuffer,
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CATViz3DEdge.
  // Return the CATPolyCell associated to the CATViz3DEdge.
  HRESULT Run (CATViz3DEdge& iVizEdge, 
               CATPolyBody& ioPolyBody,
               CATPolyEdge*& oPolyEdge) const;

  // Construct a CATPolyBody view of a CATViz3DFace.
  // Return the CATPolyCell associated to the CATViz3DFace.
  HRESULT Run (CATVizUV3DFace& iVizFace, 
               CATVizVertexBuffer& iVizVertexBuffer,                     
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CATViz3DFace.
  // Return the CATPolyCell associated to the CATViz3DFace.
  HRESULT Run (CATViz3DFace& iVizFace, 
               CATVizVertexBuffer& iVizVertexBuffer,                     
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

  // Construct a CATPolyBody view of a CATViz3DFace.
  // Return the CATPolyCell associated to the CATViz3DFace.
  HRESULT Run (CATViz3DFace& iVizFace, 
               CATPolyBody& ioPolyBody,
               CATPolyFace*& oPolyFace) const;

public:

  // Construct a CATPolyBody view of a CATVizPrimitive.
  // Return the CATPolyCell associated to the CATVizPrimitive.
  HRESULT Run (CATVizPrimitive& iVizPrimitive, 
               CATVizVertexBuffer& iVizVertexBuffer,                     
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;

#ifdef CATIAR208
  // Construct a CATPolyBody view of a CATVizPrimitive.
  // Return the CATPolyCell associated to the CATVizPrimitive.
  HRESULT Run (CATVizPrimitive& iVizPrimitive, 
               CATPolyBody& ioPolyBody,
               CATPolyCell*& oPolyCell) const;
#endif

private:

  CATPolyBodyVizDiagnosis* _Diagnosis;

private:

  HRESULT RunPrivate (CATVizVertexBuffer* iVizVertexBuffer,   /* Optional */
                      const CATVizPtrList<CATVizUV3DEdge>& iEdges, 
                      const CATVizPtrList<CATVizUV3DFace>& iFaces,
                      CATPolyBody& ioPolyBody) const;

};


#endif // !CATPolyBodyEVizAdapter_H
