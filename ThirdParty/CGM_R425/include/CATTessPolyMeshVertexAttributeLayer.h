//=============================================================================
// COPYRIGHT Dassault Systemes 2006
//=============================================================================
//
// Layer of tessellation's vertex attributes.
//
//=============================================================================
//  2006-11-02  BPG: New.
//=============================================================================
#ifndef CATTessPolyMeshVertexAttributeLayer_H
#define CATTessPolyMeshVertexAttributeLayer_H

#include "TessPolygon.h"

#include "CATTessPolyMeshVertexAttributeList.h"
#include "CATErrorDef.h"

class CATTessPolyMeshVertexAttribute;

//
class ExportedByTessPolygon CATTessPolyMeshVertexAttributeLayer
{
public:
  CATTessPolyMeshVertexAttributeLayer();
  /** WARNING: be aware that the layer own its attributes, and will delete them
      at its destruction */
  virtual ~CATTessPolyMeshVertexAttributeLayer();

  // public:
  // HRESULT Reserve(int iNbElements);

public:
  inline CATTessPolyMeshVertexAttribute *Get(int v);
  inline const CATTessPolyMeshVertexAttribute *Get(int v) const;

public:
  /** WARNING: the layer will own the given attribute, and will delete 
      it at its destruction */
  HRESULT Set(int v, CATTessPolyMeshVertexAttribute *iAttribute);

protected:
  CATTessPolyMeshVertexAttributeList _Attributes;
};

//

inline CATTessPolyMeshVertexAttribute *
CATTessPolyMeshVertexAttributeLayer::Get(int v)
{
  if (_Attributes.Size() < v) return 0; // Do not fail
  return _Attributes[v]; // Let v <= 0 fail
}

inline const CATTessPolyMeshVertexAttribute *
CATTessPolyMeshVertexAttributeLayer::Get(int v) const
{
  if (_Attributes.Size() < v) return 0;
  return _Attributes[v];
}

#endif // !CATTessPolyMeshVertexAttributeLayer_H
