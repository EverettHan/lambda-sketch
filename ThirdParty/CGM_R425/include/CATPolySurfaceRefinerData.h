// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolySurfaceRefinerData.cpp
//
//===================================================================
//
// December 2009  Creation: NDO
//===================================================================
#ifndef CATPolySurfaceRefinerData_H
#define CATPolySurfaceRefinerData_H

#include "PolyVizRefiners.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"

class CATMathPoint;
class CATMathVector;


class ExportedByPolyVizRefiners CATPolySurfaceRefinerData 
{

public:

  CATPolySurfaceRefinerData ();
  ~CATPolySurfaceRefinerData ();

public:

  inline unsigned int GetSizeOfVertices () const;
  inline unsigned int GetSizeOfTriangles () const;

  HRESULT ResizeVertices (const int iNbVertices);
  HRESULT ResizeVertices (const int iNbVertices, CATBoolean iWithNormals, CATBoolean iWithUVs);

  HRESULT ResizeTriangles (const int iNbTriangles);

public:

  // Reset the number of vertices and the number of triangles stored in the mesh to 0.
  inline void Reset ();

  HRESULT AddVertex (const CATMathPoint& P, unsigned int& v);

  HRESULT SetVertexNormal (const unsigned int v, const CATMathVector& N);
  HRESULT SetVertexUV (const unsigned int vertex, const float u, const float v);

  HRESULT AddTriangle (const unsigned int v[], unsigned int& t);

public:

  inline unsigned int GetNbVertices () const;
  inline unsigned int GetNbTriangles () const;

  inline const float* GetVertexCoordinates () const;
  inline const float* GetVertexNormals () const;
  inline const float* GetVertexUVs () const;

  inline const unsigned int* GetTriangles () const;

private:

  float* _VertexCoords;
  float* _VertexNormals;
  float* _VertexUVs;

  unsigned int* _Triangles;

  unsigned int _NbVertices;
  unsigned int _NbTriangles;

  unsigned int _SizeVertices; 
  unsigned int _SizeTriangles;

};


inline unsigned int CATPolySurfaceRefinerData::GetSizeOfVertices () const
{
  return _SizeVertices;
}

inline unsigned int CATPolySurfaceRefinerData::GetSizeOfTriangles () const
{
  return _SizeTriangles;
}

inline unsigned int CATPolySurfaceRefinerData::GetNbVertices () const
{
  return _NbVertices;
}

inline unsigned int CATPolySurfaceRefinerData::GetNbTriangles () const
{
  return _NbTriangles;
}

inline const float* CATPolySurfaceRefinerData::GetVertexCoordinates () const
{
  return _VertexCoords;
}

inline const float* CATPolySurfaceRefinerData::GetVertexNormals () const
{
  return _VertexNormals;
}

inline const float* CATPolySurfaceRefinerData::GetVertexUVs () const
{
  return _VertexUVs;
}

inline const unsigned int* CATPolySurfaceRefinerData::GetTriangles () const
{
  return _Triangles;
}

inline void CATPolySurfaceRefinerData::Reset ()
{
  _NbVertices = 0;
  _NbTriangles = 0;
}

#endif
