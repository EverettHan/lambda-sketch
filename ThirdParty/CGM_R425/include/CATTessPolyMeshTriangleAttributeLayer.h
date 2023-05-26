//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Layer of tessellation's triangle attributes.
//
//=============================================================================
// 2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshTriangleAttributeLayer_H
#define CATTessPolyMeshTriangleAttributeLayer_H

#include "TessPolygon.h"

#include "CATTessPolyMeshTriangleAttributeList.h"
#include "CATErrorDef.h"

class CATTessPolyMeshTriangleAttribute;

//
class ExportedByTessPolygon CATTessPolyMeshTriangleAttributeLayer
{
public:
  CATTessPolyMeshTriangleAttributeLayer();
  virtual ~CATTessPolyMeshTriangleAttributeLayer();

  // public:
  // HRESULT Reserve(int iNbElements);

public:
  inline CATTessPolyMeshTriangleAttribute *Get(int v);
  inline const CATTessPolyMeshTriangleAttribute *Get(int v) const;

public:
  /** WARNING: the layer will own the given attribute, and will delete 
      it at its destruction */
  HRESULT Set(int v, CATTessPolyMeshTriangleAttribute *iAttribute);

protected:
  CATTessPolyMeshTriangleAttributeList _Attributes;
};

// ----------------------------------------------------------------------------
 
inline CATTessPolyMeshTriangleAttribute *
CATTessPolyMeshTriangleAttributeLayer::Get(int v)
{
  if (_Attributes.Size() < v) return 0; // Do not fail
  return _Attributes[v]; // Let v <= 0 fail
}

inline const CATTessPolyMeshTriangleAttribute *
CATTessPolyMeshTriangleAttributeLayer::Get(int v) const
{
  if (_Attributes.Size() < v) return 0;
  return _Attributes[v];
}

#endif // !CATTessPolyMeshTriangleAttributeLayer_H
