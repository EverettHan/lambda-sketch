//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Wrap CATEdge and W coordinate of a vertex as output by the tessellation.
//
//=============================================================================
//  2006-10-30  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshVertexW_H
#define CATTessPolyMeshVertexW_H

#include "CATErrorDef.h"

//
class CATEdge;
class CATCrvParam;

//
class CATTessPolyMeshVertexW
{
public:
  inline CATTessPolyMeshVertexW(double iW, CATEdge *iEdge);
  inline ~CATTessPolyMeshVertexW();

public:
  inline double GetW() const;

  inline const CATEdge *GetEdge() const;
  inline CATEdge *GetEdge();

// public:
//   HRESULT GetCrvParam(CATCrvParam &oParam) const;

protected:
  const double _W;

  CATEdge *_Edge;
};

// ----------------------------------------------------------------------------

inline
CATTessPolyMeshVertexW::CATTessPolyMeshVertexW(double iW, CATEdge *iEdge):
  _W(iW), _Edge(iEdge)
{
  // if (iEdge) iEdge->AddRef();
}

inline
CATTessPolyMeshVertexW::~CATTessPolyMeshVertexW()
{
  // if (iEdge) iEdge->Release();
  _Edge = 0;
}

//

inline double
CATTessPolyMeshVertexW::GetW() const
{
  return _W;
}

inline const CATEdge *
CATTessPolyMeshVertexW::GetEdge() const
{
  return _Edge;
}

inline CATEdge *
CATTessPolyMeshVertexW::GetEdge()
{
  return _Edge;
}

#endif // !CATTessPolyMeshVertexW_H
