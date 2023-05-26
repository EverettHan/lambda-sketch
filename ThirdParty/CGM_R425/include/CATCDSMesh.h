#ifndef CATCDSMesh_H
#define CATCDSMesh_H

#include "CATCDSArray.h"
#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"
#include "CATCDSAssert.h"
#include "CDSMathematics.h"

#include <array>

class CATCDSString;
class CATCDSTransformation;

class CATCDSMeshTriangle
{
public:
  CATCDSMeshTriangle(int iVertex1, int iVertex2, int iVertex3, int iFace);
  CATCDSMeshTriangle() = default;
  ~CATCDSMeshTriangle() = default;
  CATCDSMeshTriangle(CATCDSMeshTriangle const &) = default;
  CATCDSMeshTriangle& operator=(CATCDSMeshTriangle const &) = default;

  cds::span<int const, 3> GetVertices() const;
  cds::span<int const, 3> GetNeighbours() const;
  cds::span<int const, 3> GetEdges() const;
  int GetFace() const;

  std::array<int, 3> _vertices = { -1, -1, -1 };
  std::array<int, 3> _neighbours = { -1, -1, -1 };
  std::array<int, 3> _edges = { -1, -1, -1 };
  int _face = 0;
  
  bool operator==(CATCDSMeshTriangle const &iTriangle) const;
  bool operator!=(CATCDSMeshTriangle const &iTriangle) const;
};

class CATCDSMeshEdge
{
public:
  std::array<int, 2> _vertices = { -1, -1 };
  // Be careful second triangle index can be -1 if mesh is not closed
  std::array<int, 2> _triangles = { -1, -1 };
};

class ExportedByCDSMathematics CATCDSMesh
{
public:
  CATCDSMesh(int inVertices, int inTriangles, int inFaces);
  CATCDSMesh();
  CATCDSMesh(CATCDSMesh const &);
  CATCDSMesh& operator=(CATCDSMesh const &);
  CATCDSMesh(CATCDSMesh &&);
  CATCDSMesh& operator=(CATCDSMesh &&);
  ~CATCDSMesh();

  void AddMesh(CATCDSMesh const &iMesh);

  int GetNbOfVertices() const;
  int GetNbOfTriangles() const;
  
  int GetNbOfFaces() const;
  void SetNbOfFaces(int inFaces);

  CATCDSArray<CATCDS3Point> const & GetVertices() const;
  CATCDSArray<CATCDS3Point> & GetVertices();
  void SetVertices(CATCDSArray<CATCDS3Point> const &iVertices);

  CATCDSArray<CATCDSMeshTriangle> const & GetTriangles() const;
  CATCDSArray<CATCDSMeshTriangle> & GetTriangles();
  void SetTriangles(CATCDSArray<CATCDSMeshTriangle> const &iTriangles);

  CATCDS3Point const & GetVertex(int idx) const;
  CATCDS3Point & GetVertex(int idx);
  void SetVertex(int idx, CATCDS3Point const &iVertex);
  void AddVertex(CATCDS3Point const &iVertex);

  CATCDSMeshTriangle const & GetTriangle(int idx) const;
  CATCDSMeshTriangle & GetTriangle(int idx);
  void SetTriangle(int idx, CATCDSMeshTriangle const &iVertex);
  void AddTriangle(CATCDSMeshTriangle const &iTriangle);

  static CATCDS3Vector GetTriangleNormal(CATCDS3Point const &iPoint1, CATCDS3Point const &iPoint2, CATCDS3Point const &iPoint3);
  static double GetTriangleArea(CATCDS3Point const &iPoint1, CATCDS3Point const &iPoint2, CATCDS3Point const &iPoint3);
  static CATCDS3Point GetTriangleBarycenter(CATCDS3Point const &iPoint1, CATCDS3Point const &iPoint2, CATCDS3Point const &iPoint3);

  CATCDS3Vector GetTriangleNormal(int iTriangle) const;
  CATCDS3Vector GetTriangleNormal(CATCDSMeshTriangle const &iTriangle) const;
  double GetTriangleArea(int iTriangle) const;

  int GetNbOfEdges() const;
  CATCDSMeshEdge const & GetEdge(int iEdge) const;
  CATCDSArray<CATCDSMeshEdge> const & GetEdges() const;

  void ComputeTriangleNeighbours();
  void SetHasNeighbours(bool ibHasNeighbours);

  bool Is2DFace(int iFace, double iAngularTolerance, CATCDS3Vector &oNormal);

  CATCDSMesh CreateSubMesh(CATCDSArray<int> const &iTriangles) const;

  CATCDSMesh& operator*=(CATCDSTransformation const & iT);

  bool operator==(CATCDSMesh const &iMesh) const;
  bool operator!=(CATCDSMesh const &iMesh) const;

  void MergeFaces(double iMinScalarProduct);
  void BuildFaces(double iMinScalarProduct);

  void MergeIdenticalVertices();

  static CATCDSArray<CATCDSMesh> MergeAndSplit(CATCDSArray<CATCDSMesh> const &iMeshes);

  bool IsClosed() const;

  // Checks if face is a plane orthogonal to X, Y or Z
  bool IsFacePlanar(int iFace) const;

  // Returns true if mesh is a XYZ axis aligned box 
  bool IsBox() const;
  
  bool IsRotationInvariant(CATCDS3Point const &iAxisOrigin, CATCDS3Vector const &iAxisDirection, double iTolerance) const;

  CATCDSMesh CreateFinerMesh() const;

private:
  void ComputeEdges() const;

  CATCDSArray<CATCDS3Point> _vertices;
  mutable CATCDSArray<CATCDSMeshTriangle> _triangles;
  int _nFaces = 1;
  mutable bool _bNeighbours = false;
  mutable bool _bFilledEdges = false;
  // A list of ordered vertex idx pair which represents all edges of the mesh
  mutable CATCDSArray<CATCDSMeshEdge> _edges;
  mutable CATCDSArray<bool> _isPlanarFaces;
};

inline CATCDSMesh::CATCDSMesh(int inVertices, int inTriangles, int inFaces)
  : _vertices(inVertices)
  , _triangles(inTriangles)
  , _nFaces(inFaces)
{
}

inline int CATCDSMesh::GetNbOfVertices() const
{
  return _vertices.Size();
}

inline int CATCDSMesh::GetNbOfTriangles() const
{
  return _triangles.Size();
}

inline int CATCDSMesh::GetNbOfFaces() const
{
  return _nFaces;
}

inline void CATCDSMesh::SetNbOfFaces(int inFaces)
{
  _nFaces = inFaces;
}

inline CATCDSArray<CATCDS3Point> const & CATCDSMesh::GetVertices() const
{
  return _vertices;
}

inline CATCDSArray<CATCDS3Point> & CATCDSMesh::GetVertices()
{
  return _vertices;
}

inline void CATCDSMesh::SetVertices(CATCDSArray<CATCDS3Point> const &iVertices)
{
  _vertices = iVertices;
}

inline CATCDSArray<CATCDSMeshTriangle> const & CATCDSMesh::GetTriangles() const
{
  return _triangles;
}

inline CATCDSArray<CATCDSMeshTriangle> & CATCDSMesh::GetTriangles()
{
  return _triangles;
}

inline void CATCDSMesh::SetTriangles(CATCDSArray<CATCDSMeshTriangle> const &iTriangles)
{
  _triangles = iTriangles;
}

inline CATCDS3Point const & CATCDSMesh::GetVertex(int idx) const
{
  return _vertices[idx];
}

inline CATCDS3Point & CATCDSMesh::GetVertex(int idx)
{
  return _vertices[idx];
}

inline void CATCDSMesh::SetVertex(int idx, CATCDS3Point const &iVertex)
{
  _vertices[idx] = iVertex;
}

inline void CATCDSMesh::AddVertex(CATCDS3Point const &iVertex)
{
  _vertices.Append(iVertex);
}

inline CATCDSMeshTriangle const & CATCDSMesh::GetTriangle(int idx) const
{
  return _triangles[idx];
}

inline CATCDSMeshTriangle & CATCDSMesh::GetTriangle(int idx)
{
  return _triangles[idx];
}

inline void CATCDSMesh::SetTriangle(int idx, CATCDSMeshTriangle const &iTriangle)
{
  _triangles[idx] = iTriangle;
}

inline void CATCDSMesh::AddTriangle(CATCDSMeshTriangle const &iTriangle)
{
  _bNeighbours = false;
  _bFilledEdges = false;
  _isPlanarFaces.RemoveAll();
  _triangles.Append(iTriangle);
}

inline int CATCDSMesh::GetNbOfEdges() const
{
  ComputeEdges();
  return _edges.Size();
}

inline CATCDSArray<CATCDSMeshEdge> const & CATCDSMesh::GetEdges() const
{
  ComputeEdges();
  return _edges;
}

inline CATCDSMeshEdge const & CATCDSMesh::GetEdge(int iEdge) const
{
  ComputeEdges();
  return _edges[iEdge];
}

inline CATCDSMesh operator*(CATCDSTransformation const & iT, CATCDSMesh const &iMesh)
{
  auto res = iMesh;
  return res *= iT;
}

inline bool CATCDSMesh::operator==(CATCDSMesh const &iMesh) const
{
  return _vertices == iMesh._vertices && _triangles == iMesh._triangles;
}

inline bool CATCDSMesh::operator!=(CATCDSMesh const &iMesh) const
{
  return !(*this == iMesh);
}

inline void CATCDSMesh::SetHasNeighbours(bool ibHasNeighbours)
{
  _bNeighbours = ibHasNeighbours;
}

inline CATCDSMeshTriangle::CATCDSMeshTriangle(int iVertex1, int iVertex2, int iVertex3, int iFace)
  : _vertices{iVertex1, iVertex2, iVertex3}
  , _face(iFace)
{

}

inline cds::span<int const, 3> CATCDSMeshTriangle::GetVertices() const
{
  return _vertices;
}

inline cds::span<int const, 3> CATCDSMeshTriangle::GetNeighbours() const
{
  return _neighbours;
}

inline cds::span<int const, 3> CATCDSMeshTriangle::GetEdges() const
{
  return _edges;
}

inline int CATCDSMeshTriangle::GetFace() const
{
  return _face;
}

inline bool CATCDSMeshTriangle::operator==(CATCDSMeshTriangle const &iTriangle) const
{
  return _vertices == iTriangle._vertices;
}

inline bool CATCDSMeshTriangle::operator!=(CATCDSMeshTriangle const &iTriangle) const
{
  return !(*this == iTriangle);
}

#endif
