// COPYRIGHT DASSAULT SYSTEMES 2013

#ifndef CATVizGeometryStripper_h
#define CATVizGeometryStripper_h

#include "SGInfra.h"

#include "CATVizPtrList.h"
#include "CATVizIndexType.h"

#include "CATListOfCATUnicodeString.h"

#include "CATLISTV_Declare.h"
#undef CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy ExportedBySGInfra

class CATGraphicPrimitive;
class CAT3DFaceGP;
class CAT3DEdgeGP;
class CATViz3DFace;
class CATViz3DEdge;
class CATVizVertexBuffer;

class _Vertex;

//==============================================================================
struct ExportedBySGInfra CATVizGeometryStripperPrimitive
{
  CATGraphicPrimitive* pPrimitive;
  unsigned lodIndex;

  bool operator == (const CATVizGeometryStripperPrimitive& rhs) const
  {
    return pPrimitive == rhs.pPrimitive && lodIndex == rhs.lodIndex;
  }

  bool operator != (const CATVizGeometryStripperPrimitive& rhs) const
  {
    return !(*this == rhs);
  }
};

CATLISTV_DECLARE(CATVizGeometryStripperPrimitive);

//==============================================================================
struct ExportedBySGInfra CATVizGeometryStripperPrimitiveGroup
{
  CATLISTV(CATVizGeometryStripperPrimitive) primitives;
  CATVizVertexBuffer* pVertexBuffer;
  unsigned offset;

  bool operator == (const CATVizGeometryStripperPrimitiveGroup& rhs) const
  {
    return primitives == rhs.primitives && pVertexBuffer && rhs.pVertexBuffer && offset == rhs.offset;
  }

  bool operator != (const CATVizGeometryStripperPrimitiveGroup& rhs) const
  {
    return !(*this == rhs);
  }
};
CATLISTV_DECLARE(CATVizGeometryStripperPrimitiveGroup);

//==============================================================================
class ExportedBySGInfra CATVizGeometryStripper
{
public:
  CATVizGeometryStripper();
  ~CATVizGeometryStripper();

  void Queue(CATVizGeometryStripperPrimitiveGroup& ioGroup);
  CATVizVertexBuffer* Process();

private:
  void GenerateVertexBuffer();
  void RemapVertex(unsigned& ioIndex);

  void RemapPrimitives();
  void RemapFace(CAT3DFaceGP* iFaceGP,CATViz3DFace* ipFace, unsigned iOffset);
  void RemapEdge(CAT3DEdgeGP* iEdgeGP,CATViz3DEdge* ipEdge, unsigned iOffset);
  void RemapIndices(
    unsigned* ioIndices, unsigned iIndexCount,
    bool iIndexPacked, unsigned iOffset);

  CATLISTV(CATVizGeometryStripperPrimitiveGroup) _groups;

  bool _hasNormals;
  bool _hasTexCoords;
  bool _hasTanBinorms;
  bool _hasUVs;

  unsigned _texCoordDimension;
  unsigned _vertexCount;

  unsigned _nbExtraTexCoords;
  unsigned* _extraTexCoordsDims;

  CATListOfCATUnicodeString _listofnames;

  unsigned _maxLodIndex;

  unsigned _newVertexCount;
  unsigned _newNormalCount;

  _Vertex* _vertices;

  unsigned* _indexMap;
  bool* _indexMapped;

  float* _newPositions;
  float* _newNormals;
  float* _newTexCoords;
  float* _newTangents;
  float* _newBinormals;
  float* _newUVs;
  float** _newExtraTexCoords;


  CATVizVertexBuffer* _newVertexBuffer;

  CATVizGeometryStripper(const CATVizGeometryStripper&);
  void operator = (const CATVizGeometryStripper&);
};

#endif  // CATVizGeometryStripper_h
