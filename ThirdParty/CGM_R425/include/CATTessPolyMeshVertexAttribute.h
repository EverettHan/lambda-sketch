//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Set of CATTessPolyMeshVertexUVs and CATTessPolyMeshVertexWs
//
//=============================================================================
//  2006-10-30  BPG * New.
//=============================================================================
#ifndef CATTessPolyMeshVertexAttribute_H
#define CATTessPolyMeshVertexAttribute_H

#include "TessPolygon.h"

#include "CATListPV.h"
#include "CATErrorDef.h"

//
class CATTessPolyMeshVertexUV;
class CATTessPolyMeshVertexW;
class CATVertex;

//
class ExportedByTessPolygon CATTessPolyMeshVertexAttribute
{
private:
  CATTessPolyMeshVertexAttribute(CATTessPolyMeshVertexUV **iUVContextArray, unsigned int iNbUVContexts,
                                 CATTessPolyMeshVertexW **iWContextArray, unsigned int iNbWContexts,
                                 CATVertex *iVertex);
public:
  ~CATTessPolyMeshVertexAttribute();

public:
  inline unsigned int GetNbUVContexts() const;

  inline const CATTessPolyMeshVertexUV *GetUVContext(unsigned int c) const;
  inline CATTessPolyMeshVertexUV *GetUVContext(unsigned int c);

public:
  inline unsigned int GetNbWContexts() const;

  inline const CATTessPolyMeshVertexW *GetWContext(unsigned int c) const;
  inline CATTessPolyMeshVertexW *GetWContext(unsigned int c);

public:
  inline const CATVertex *GetVertex() const;
  inline CATVertex *GetVertex();


  // Methods reserved to internal use (ie CATTessStorePolyMesh)
private:
  friend class CATTessStorePolyMesh;
  friend class CATWallThicknessPolyhedronFactory;

  static CATTessPolyMeshVertexAttribute *New(CATTessPolyMeshVertexUV **iUVContexts, unsigned int iNbUVContexts);
  
  inline HRESULT AppendWContext(CATTessPolyMeshVertexW *WContext);
  inline HRESULT SetVertex(CATVertex *iVertex);

private:
  CATTessPolyMeshVertexUV **_UVContexts;
  unsigned int _NbUVContexts;

  CATListPV _WContexts;
  // CATTessPolyMeshVertexW **_WContexts;
  // unsigned int _NbWContexts;

  CATVertex *_Vertex;
};

// ----------------------------------------------------------------------------

inline unsigned int
CATTessPolyMeshVertexAttribute::GetNbUVContexts() const
{
  return _NbUVContexts;
}

inline const CATTessPolyMeshVertexUV *
CATTessPolyMeshVertexAttribute::GetUVContext(unsigned int c) const
{
  if (!_UVContexts || _NbUVContexts <= c) return 0;
  return _UVContexts[c];
}

inline CATTessPolyMeshVertexUV *
CATTessPolyMeshVertexAttribute::GetUVContext(unsigned int c)
{
  if (!_UVContexts || _NbUVContexts <= c) return 0;
  return _UVContexts[c];
}

//

inline unsigned int
CATTessPolyMeshVertexAttribute::GetNbWContexts() const
{
  return _WContexts.Size();
  // return _NbWContexts;
}

inline const CATTessPolyMeshVertexW *
CATTessPolyMeshVertexAttribute::GetWContext(unsigned int c) const
{
//   if (!_WContexts || _NbWContexts <= c) return 0;
  return (CATTessPolyMeshVertexW*) _WContexts[c + 1];
}

inline CATTessPolyMeshVertexW *
CATTessPolyMeshVertexAttribute::GetWContext(unsigned int c)
{
//   if (!_WContexts || _NbWContexts <= c) return 0;
  return (CATTessPolyMeshVertexW*) _WContexts[c + 1];
}

//

inline const CATVertex *
CATTessPolyMeshVertexAttribute::GetVertex() const
{
  return _Vertex;
}

inline CATVertex *
CATTessPolyMeshVertexAttribute::GetVertex()
{
  return _Vertex;
}

//

inline HRESULT
CATTessPolyMeshVertexAttribute::AppendWContext(CATTessPolyMeshVertexW *iWContext)
{
  _WContexts.Append(iWContext);
  return S_OK;
}

inline HRESULT
CATTessPolyMeshVertexAttribute::SetVertex(CATVertex *iVertex)
{
  if (_Vertex) return E_FAIL;
  _Vertex = iVertex;
  return S_OK;
}

#endif // !CATTessPolyMeshVertexAttribute_H
