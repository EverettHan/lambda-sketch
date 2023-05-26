//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// Mesh triangle attribute gathering results from tessellation
//
//=============================================================================
//  2007-06-26  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshTriangleAttribute_H
#define CATTessPolyMeshTriangleAttribute_H

#include "TessPolygon.h"

#include "CATErrorDef.h"

//
class CATFace;

//
class ExportedByTessPolygon CATTessPolyMeshTriangleAttribute
{
private:
  CATTessPolyMeshTriangleAttribute(CATFace *iFace);
public:
  ~CATTessPolyMeshTriangleAttribute();

public:
  inline const CATFace *GetFace() const;
  inline CATFace *GetFace();

  // Methods reserved to internal use (ie CATTessStorePolyMesh)
private:
  friend class CATTessStorePolyMesh;

  static CATTessPolyMeshTriangleAttribute *New(CATFace *iFace);

private:
  CATFace *_Face;
};

// ----------------------------------------------------------------------------

inline const CATFace *
CATTessPolyMeshTriangleAttribute::GetFace() const
{
  return _Face;
}

inline CATFace *
CATTessPolyMeshTriangleAttribute::GetFace()
{
  return _Face;
}

#endif // !CATTessPolyMeshTriangleAttribute_H
