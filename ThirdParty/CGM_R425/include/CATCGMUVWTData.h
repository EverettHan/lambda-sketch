// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATCGMUVWTData.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Mars 2012  Creation: ZFI
//===================================================================

#ifndef CATCGMUVWTData_H
#define CATCGMUVWTData_H

#include "ExportedByTessellateCommon.h"

#include "CATMapOfPtrToPtr.h"
#include "CATSetOfPtr.h"

class CATFace;
class CATEdge;
class CATVertex;

class CATCGMUVFaceWTData;
class CATCGMUVEdgeWTData;
class CATCGMUVVertexWTData;

class ExportedByTessellateCommon CATCGMUVWTData
{
public:
  CATCGMUVWTData();
  virtual ~CATCGMUVWTData();

  //TOPOLOGY
public:
  //Watertight
  int GetNbFaces(){return _Face2FaceWTData.Size();}
  int GetNbEdges(){return _Edge2EdgeWTData.Size();}
  int GetNbVertices(){return _Vertex2VertexWTData.Size();}
  
  HRESULT AddFaceWTData(CATFace& iFace, CATCGMUVFaceWTData*& oFaceWTData);
  CATCGMUVFaceWTData* GetFaceWTData(CATFace& iFace);
  const CATCGMUVFaceWTData* GetFaceWTData(CATFace& iFace)const;
  
  HRESULT AddEdgeWTData(CATEdge& iEdge, CATCGMUVEdgeWTData*& oEdgeWTData);
  CATCGMUVEdgeWTData* GetEdgeWTData(CATEdge& iEdge);
  const CATCGMUVEdgeWTData* GetEdgeWTData(CATEdge& iEdge)const;

  //Wire Edge
  int GetNbWireEdges(){return _Edge2WireEdgeWTData.Size();}

  HRESULT AddWireEdgeWTData(CATEdge& iEdge, CATCGMUVEdgeWTData*& oEdgeWTData);
  CATCGMUVEdgeWTData* GetWireEdgeWTData(CATEdge& iEdge);
  const CATCGMUVEdgeWTData* GetWireEdgeWTData(CATEdge& iEdge)const;

	//Vertex
  HRESULT AddVertexWTData(CATVertex& iVertex, CATCGMUVVertexWTData*& oVertexWTData);
  CATCGMUVVertexWTData* GetVertexWTData(CATVertex& iVertex);
  const CATCGMUVVertexWTData* GetVertexWTData(CATVertex& iVertex)const;

	//Isolated Vertex
  int GetNbIsolatedVertices(){return _IsolatedVertex2VertexWTData.Size();}

	HRESULT AddIsolatedVertexWTData(CATVertex& iVertex, CATCGMUVVertexWTData*& oVertexWTData);
  CATCGMUVVertexWTData* GetIsolatedVertexWTData(CATVertex& iVertex);
  const CATCGMUVVertexWTData* GetIsolatedVertexWTData(CATVertex& iVertex)const;

  //Free Vertex
  int GetNbFreeVertices(){return _FreeVertices.Size();}
  HRESULT AddFreeVertex(CATVertex& iVertex);

private:
  //topo
  CATMapOfPtrToPtr _Face2FaceWTData;
  CATMapOfPtrToPtr _Edge2EdgeWTData;
  CATMapOfPtrToPtr _Edge2WireEdgeWTData;
  CATSetOfPtr _FreeVertices;    

	CATMapOfPtrToPtr _Vertex2VertexWTData;
	CATMapOfPtrToPtr _IsolatedVertex2VertexWTData;

private:
  friend class CATCGMUVFaceWTDataIterator;
  friend class CATCGMUVEdgeWTDataIterator;
  friend class CATCGMUVWireEdgeWTDataIterator;
  friend class CATCGMUVFreeVertexIterator;
  friend class CATCGMUVVertexWTDataIterator;
  friend class CATCGMUVIsolatedVertexWTDataIterator;

  friend class CATCGMUVFaceWTData;
  friend class CATCGMUVEdgeWTData;
  friend class CATCGMUVVertexWTData;
  friend class CATCGMUVLoopWTData;
};

//ITERATORS
class ExportedByTessellateCommon CATCGMUVFaceWTDataIterator
{
public:
  CATCGMUVFaceWTDataIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVFaceWTDataIterator();

public:
  CATCGMUVFaceWTDataIterator& Begin();
  CATBoolean End()const;
  CATCGMUVFaceWTDataIterator& operator++();

  CATFace* GetFace();
  CATCGMUVFaceWTData* GetData();

private:
  const CATCGMUVWTData& _WTData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVEdgeWTDataIterator
{
public:
  CATCGMUVEdgeWTDataIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVEdgeWTDataIterator();

public:
  CATCGMUVEdgeWTDataIterator& Begin();
  CATBoolean End()const;
  CATCGMUVEdgeWTDataIterator& operator++();

  CATEdge* GetEdge();
  CATCGMUVEdgeWTData* GetData();

private:
  const CATCGMUVWTData& _WTData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVWireEdgeWTDataIterator
{
public:
  CATCGMUVWireEdgeWTDataIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVWireEdgeWTDataIterator();

public:
  CATCGMUVWireEdgeWTDataIterator& Begin();
  CATBoolean End()const;
  CATCGMUVWireEdgeWTDataIterator& operator++();

  CATEdge* GetEdge();
  CATCGMUVEdgeWTData* GetData();

private:
  const CATCGMUVWTData& _WTData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVFreeVertexIterator
{
public:
  CATCGMUVFreeVertexIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVFreeVertexIterator();

public:
  CATCGMUVFreeVertexIterator& Begin();
  CATBoolean End()const;
  CATCGMUVFreeVertexIterator& operator++();

  CATVertex* GetVertex();

private:
  const CATCGMUVWTData& _WTData;
  CATSetOfPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVVertexWTDataIterator
{
public:
  CATCGMUVVertexWTDataIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVVertexWTDataIterator();

public:
  CATCGMUVVertexWTDataIterator& Begin();
  CATBoolean End()const;
  CATCGMUVVertexWTDataIterator& operator++();

  CATVertex* GetVertex();
  CATCGMUVVertexWTData* GetData();

private:
  const CATCGMUVWTData& _WTData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

class ExportedByTessellateCommon CATCGMUVIsolatedVertexWTDataIterator
{
public:
  CATCGMUVIsolatedVertexWTDataIterator(const CATCGMUVWTData& iWTData);
  virtual ~CATCGMUVIsolatedVertexWTDataIterator();

public:
  CATCGMUVIsolatedVertexWTDataIterator& Begin();
  CATBoolean End()const;
  CATCGMUVIsolatedVertexWTDataIterator& operator++();

  CATVertex* GetVertex();
  CATCGMUVVertexWTData* GetData();

private:
  const CATCGMUVWTData& _WTData;
  CATMapOfPtrToPtr::Iterator _Iter;
};

#endif
