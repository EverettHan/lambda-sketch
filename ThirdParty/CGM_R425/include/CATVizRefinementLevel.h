#ifndef CATVizRefinementLevel_H
#define CATVizRefinementLevel_H

#include "SGInfra.h"

#include "CATVizPtrList.h"
class CATViz3DFace;
class CATViz3DEdge;
class CATVizVertexBuffer;

#include "CATVizPrimitive.h"

class ExportedBySGInfra CATVizRefinementLevel
{
public:

   CATVizRefinementLevel();
   CATVizRefinementLevel(const CATVizRefinementLevel & source);
   virtual ~CATVizRefinementLevel();
   const CATVizRefinementLevel & operator=(const CATVizRefinementLevel & source);

   // This method calls AddRef() on iVB.
   void                 SetVertexBuffer(CATVizVertexBuffer * iVB);
   CATVizVertexBuffer * GetVertexBuffer() const;

   void           AddFace(CATViz3DFace * iFace);
   unsigned int   GetNbFaces() const;
   CATViz3DFace * GetFace(unsigned int iIndex) const;

   void           AddEdge(CATViz3DEdge * iEdge);
   unsigned int   GetNbEdges() const;
   CATViz3DEdge * GetEdge(unsigned int iIndex) const;

   void              AddPrimitive(CATVizGeomType iType, CATVizPrimitive * iPrimitive);
   unsigned int      GetNbPrimitives(CATVizGeomType iType) const;
   CATVizPrimitive * GetPrimitive(CATVizGeomType iType, unsigned int iIndex) const;

   void Clear(int destroyPrimitives = 0);

protected:

   CATVizVertexBuffer *          _vertexBuffer;
   CATVizPtrList<CATViz3DFace> _faces;
   CATVizPtrList<CATViz3DEdge> _edges;

   CATVizPtrList<CATVizPrimitive> _primitives[10];
};

#endif
