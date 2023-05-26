#ifndef CATRefinementLevel_H
#define CATRefinementLevel_H

#include "SGInfra.h"

#include "CATVizPtrList.h"
#include "CAT3DGeomRep.h"
class CAT3DFaceGP;
class CAT3DEdgeGP;
class CATGraphicPrimitive;
class CATVizVertexBuffer;
class CATRender;

class ExportedBySGInfra CATRefinementLevel
{
public:

   CATRefinementLevel();
   CATRefinementLevel(const CATRefinementLevel & source);
   virtual ~CATRefinementLevel();
   const CATRefinementLevel & operator=(const CATRefinementLevel & source);

   // This method calls AddRef() on iVB.
   void                 SetVertexBuffer(CATVizVertexBuffer * iVB);
   CATVizVertexBuffer * GetVertexBuffer() const;

   // This method calls AddRef() on iFace.
   void          AddFace(CAT3DFaceGP * iFace);
   unsigned int  GetNbFaces() const;
   CAT3DFaceGP * GetFace(unsigned int iIndex) const;

   // This method calls AddRef() on iEdge.
   void          AddEdge(CAT3DEdgeGP * iEdge);
   unsigned int  GetNbEdges() const;
   CAT3DEdgeGP * GetEdge(unsigned int iIndex) const;

   void                  AddPrimitive   (CATGeomType iType, CATGraphicPrimitive * iPrimitive);
   unsigned int          GetNbPrimitives(CATGeomType iType);
   CATGraphicPrimitive * GetPrimitive   (CATGeomType iType, unsigned int iIndex);

   // Releases all the primitives.
   void Clear();

protected:

   CATVizVertexBuffer *       _vertexBuffer;
   CATVizPtrList<CAT3DFaceGP> _faces;
   CATVizPtrList<CAT3DEdgeGP> _edges;
   CATVizPtrList<CATGraphicPrimitive> _primitives[10];
};

#endif
