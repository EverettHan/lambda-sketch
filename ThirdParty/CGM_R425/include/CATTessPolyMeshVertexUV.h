//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Wrap CATFace and U,V coordinates of a vertex as output by the tessellation.
//
//=============================================================================
//  2006-10-30  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshVertexUV_H
#define CATTessPolyMeshVertexUV_H

#include "CATErrorDef.h"

#include "CATFace.h"

//
class CATSurParam;
class CATSurLimits;
class CATSurface;

//
#include "TessPolygon.h"
class ExportedByTessPolygon CATTessPolyMeshVertexUV
{
public:
  inline CATTessPolyMeshVertexUV(double iU, double iV, CATFace *iFace);
  inline ~CATTessPolyMeshVertexUV();

public:
  inline double GetU() const;
  inline double GetV() const;

  inline const CATFace *GetFace() const;
  inline CATFace *GetFace();

  inline const CATSurface *GetSurface() const;

public:
  HRESULT EvalPoint(CATMathPoint &oPoint) const;

  HRESULT EvalNormal(CATMathVector &oNormal, CATBoolean iInvert) const;

// public:
//   HRESULT ExtractGeometricContext(CATSurParam *oSurParam, CATSurface **oSurface, CATSurLimits *oSurLimits) const;

protected:
  const double _U;
  const double _V;

  CATFace *_Face;
};

//

inline
CATTessPolyMeshVertexUV::CATTessPolyMeshVertexUV(double iU, double iV, CATFace *iFace):
  _U(iU), _V(iV), _Face(iFace)
{
  // if (iFace) iFace->AddRef();
}

inline
CATTessPolyMeshVertexUV::~CATTessPolyMeshVertexUV()
{
  // if (iFace) iFace->Release();
  _Face = 0;
}

inline double
CATTessPolyMeshVertexUV::GetU() const
{
  return _U;
}

inline double
CATTessPolyMeshVertexUV::GetV() const
{
  return _V;
}

inline const CATSurface *
CATTessPolyMeshVertexUV::GetSurface() const
{
  if (!_Face) return 0;
  return _Face->GetSurface();
}

inline const CATFace *
CATTessPolyMeshVertexUV::GetFace() const
{
  return _Face;
}

inline CATFace *
CATTessPolyMeshVertexUV::GetFace()
{
  return _Face;
}

#endif // !CATTessPolyMeshVertexUV_H
