/* -*-C++-*-*/
//#define NEWNEW
#ifdef NEWNEW
#ifndef CATTessPolyAttrContainers_h
#define CATTessPolyAttrContainers_h
#include "ListPOfCATTessCldTessTriangleInfo.h"
#include "ListPOfCATTessCldTessVertexInfo.h"
#include "TessPolygon.h"

#include "CATTessCldTessInformations.h"

class CATTessCldTessTriangleInfo;
class CATTessCldTessVertexInfo;

class ExportedByTessPolygon CATTessPolyTriangleAttrContainer
{
public:
  CATTessPolyTriangleAttrContainer();
  virtual ~CATTessPolyTriangleAttrContainer();

public:
  HRESULT Set(int t, CATTessCldTessTriangleInfo *iAttribute);
  inline CATTessCldTessTriangleInfo *Get(int t) const;

protected:
  ListPOfCATTessCldTessTriangleInfo _Attributes;
};

// Inline methods implementation

inline CATTessCldTessTriangleInfo *
CATTessPolyTriangleAttrContainer::Get(int t) const
{
  if (t <= _Attributes.Size())
    return _Attributes[t];
  return 0;
}

class ExportedByTessPolygon CATTessPolyVertexAttrContainer
{
public:
  CATTessPolyVertexAttrContainer();
  virtual ~CATTessPolyVertexAttrContainer();

public:
  HRESULT Set(int t, CATTessCldTessVertexInfo *iAttribute);
  inline CATTessCldTessVertexInfo *Get(int t) const;

protected:
  ListPOfCATTessCldTessVertexInfo _Attributes;
};

// Inline methods implementation

inline CATTessCldTessVertexInfo *
CATTessPolyVertexAttrContainer::Get(int t) const
{
  if (t <= _Attributes.Size())
    return _Attributes[t];
  return 0;
}
#endif
#endif
