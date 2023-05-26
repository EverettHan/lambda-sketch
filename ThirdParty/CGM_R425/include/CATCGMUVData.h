// COPYRIGHT DASSAULT SYSTEMES 2010, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Dec 2010  Creation: ZFI
//===================================================================

#ifndef CATCGMUVData_H
#define CATCGMUVData_H

#include "ExportedByTessellateCommon.h"

#include "CATErrorDef.h"
#include "CATMapOfPtrToPtr.h"

//model
class CATBody;
class CATFace;
class CATEdge;

class CATCGMUVFace;
class CATCGMUVEdge;

class ExportedByTessellateCommon CATCGMUVData
{
public :
  CATCGMUVData();
  virtual ~CATCGMUVData();

public:
  //Associate
  HRESULT SetFace(CATCGMUVFace* iTessFace, CATFace* iFace);
  HRESULT SetEdge(CATCGMUVEdge* iTessEdge, CATEdge* iEdge);

  //Get
  inline CATCGMUVFace* GetFace(CATFace* iFace);
  inline const CATCGMUVFace* GetFace(CATFace* iFace)const;

  inline CATCGMUVEdge* GetEdge(CATEdge* iEdge);
  inline const CATCGMUVEdge* GetEdge(CATEdge* iEdge)const;

private: 
  CATMapOfPtrToPtr _Face2TessFace;
  CATMapOfPtrToPtr _Edge2TessEdge;

  friend class CATCGMUVFacesIterator;
  friend class CATCGMUVEdgesIterator;
};

inline CATCGMUVFace* CATCGMUVData::GetFace(CATFace* iFace)
{
  CATCGMUVFace* tessFace=0;
  _Face2TessFace.Locate((void*)iFace, (void*&)tessFace);
  return tessFace;
}

inline const CATCGMUVFace* CATCGMUVData::GetFace(CATFace* iFace)const
{
  const CATCGMUVFace* tessFace=0;
  _Face2TessFace.Locate((void*)iFace, (void*&)tessFace);
  return tessFace;
}

inline CATCGMUVEdge* CATCGMUVData::GetEdge(CATEdge* iEdge)
{
  CATCGMUVEdge* tessEdge=0;
  _Edge2TessEdge.Locate((void*)iEdge, (void*&)tessEdge);
  return tessEdge;
}

inline const CATCGMUVEdge* CATCGMUVData::GetEdge(CATEdge* iEdge)const
{
  const CATCGMUVEdge* tessEdge=0;
  _Edge2TessEdge.Locate((void*)iEdge, (void*&)tessEdge);
  return tessEdge;
}

class ExportedByTessellateCommon CATCGMUVFacesIterator
{
public:
  CATCGMUVFacesIterator(const CATCGMUVData& iTessData);
  virtual ~CATCGMUVFacesIterator();

public:
  CATCGMUVFacesIterator& Begin();
  CATBoolean End()const;
  CATCGMUVFacesIterator& operator++();
  CATCGMUVFace* Get();

private:
  const CATCGMUVData& _TessData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVEdgesIterator
{
public:
  CATCGMUVEdgesIterator(const CATCGMUVData& iTessData);
  virtual ~CATCGMUVEdgesIterator();

public:
  CATCGMUVEdgesIterator& Begin();
  CATBoolean End()const;
  CATCGMUVEdgesIterator& operator++();
  CATCGMUVEdge* Get();

private:
  const CATCGMUVData& _TessData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

#endif
