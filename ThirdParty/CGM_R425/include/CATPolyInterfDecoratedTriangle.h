// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterfDecoratedTriangle.h
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a triangle of a mesh.
//
//===================================================================
//
// Jul 2009 Creation: JS9
//===================================================================

#ifndef CATPolyInterfDecoratedTriangle_h
#define CATPolyInterfDecoratedTriangle_h

// Math
#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATMathPointf.h"
#include "CATMathBox.h"
#include "CATMath.h"
class CATMathTransformation;

// Polyhedral
#include "CATPolyBoundingSphere.h"
#define POLYBOXF
#ifdef POLYBOXF
#include "CATPolyBoxf.h"
#endif
// #include "CATMathOBB.h"


//#define DECOTRIANGLE_DEBUG

// Interference
#include "CATPolyInterferenceDecoratedMesh.h"
class CATPolyInterfDecoratedObjectsVisitor;

/**
 * Class adding additional informations on a mesh.
 */
class CATPolyInterfDecoratedTriangle
{
public:

  /**
   * Constructor and destructor.
   */
  inline CATPolyInterfDecoratedTriangle(CATPolyInterferenceDecoratedMesh & parentMesh, const int index, const int verticesIds[3]);
  inline CATPolyInterfDecoratedTriangle(CATPolyInterferenceDecoratedMesh & parentMesh);
  /**
   * Much easier if it does nothing (because of the placement new).
   */
  inline ~CATPolyInterfDecoratedTriangle() {} // final class



  /**
   * Get the bounding box of the triangle
   */
#ifdef POLYBOXF
  inline const CATPolyBoxf & GetBoundingBox() const;
#else
  inline const CATMathBox & GetBoundingBox() const;
#endif

  /**
   * Apply translation
   */
  void Translate(const CATMathVector & iTranslation);

  /**
   * Apply general transformation on the triangle
   * newCoords transformed coordinates.
   */
  void Move(const CATMathTransformation & transfo);

  /**
   * @return Whether the two triangles intersect at a tolerance 0.
   */
  inline CATBoolean TestTriTriBVs(CATPolyInterfDecoratedTriangle & otherTri, double tolerance = 0.0) const;

  /**
   * Get a pointer on an array of size 3 pointing the ids of the triangle vertices.
   */
  inline const int * GetVerticesIds() const;

  /**
   * Get the coordinates of the 3 vertices of the triangle.
   */
  inline void GetCoords(CATMathPoint coords[3]) const;

  /**
   * Get the three normals of the triangle from the face it belongs to.
   */
  inline void GetNormals(CATMathVector normals[3]) const;

  /**
   * Get the three normals of the the triangles to be used for intererence computation.
   */
  inline void GetInterferenceNormals(CATMathVector normals[3]) const;

  /**
   * @return Whether the triangle belongs to a surfacic polybody or not.
   */
  inline CATBoolean IsSurfacic() const;

  /**
   * @return The accuracy oof the polybody from which the triangle belongs.
   */
  inline double GetAccuracy() const;

  /**
   * Get the data associated with one of the three vertices of the triangle.
   * @param vertexId must be 1, 2 or 3.
   */
  inline const CATPolyInterfDecoratedVertex & GetVertexData(int vertexId) const;

  /**
   * @return The parent mesh of the triangle.
   */
  inline CATPolyInterferenceDecoratedMesh * GetParentMesh();

  /**
   * @return Whether the triangle BV intersects the mesh one.
   */
  inline CATBoolean TestTriMeshBVs(const CATPolyInterferenceDecoratedMesh & mesh, double tolerance = 0.0) const;

  /**
   *Compute the center of the triangle
   */
  inline void GetCenter(CATMathPoint & oCenter) const;

  /**
   * Compute the OBB of the triangle.
   */
  /*void ComputeOBB();*/

  /**
   * Accept a visitor and call its visit method.
   */
  void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

  /**
   * Placement new to be able to call the constructor on an array of objets.
   */
  inline void * operator new(size_t size, CATPolyInterfDecoratedTriangle * pos)
  {
    return pos;
  }

  inline void ComputeboundingBox()
  {
    const CATPolyInterfPoint & p1 = GetVertexData(0)._oCoords;
    const CATPolyInterfPoint & p2 = GetVertexData(1)._oCoords;
    const CATPolyInterfPoint & p3 = GetVertexData(2)._oCoords;
    double xm, xp, ym, yp, zm, zp;
    // Compute X interval
    if (p1.GetX() < p2.GetX()) {
      if (p1.GetX() < p3.GetX()) {
        xm = p1.GetX();
        if (p2.GetX() < p3.GetX()) xp = p3.GetX();
        else             xp = p2.GetX();
      }
      else {
        xm = p3.GetX();
        xp = p2.GetX();
      }
    }
    else {
      if (p2.GetX() < p3.GetX()) {
        xm = p2.GetX();
        if (p1.GetX() < p3.GetX()) xp = p3.GetX();
        else             xp = p1.GetX();
      }
      else {
        xm = p3.GetX();
        xp = p1.GetX();
      }
    }

    // Compute Y interval
    if (p1.GetY() < p2.GetY()) {
      if (p1.GetY() < p3.GetY()) {
        ym = p1.GetY();
        if (p2.GetY() < p3.GetY()) yp = p3.GetY();
        else             yp = p2.GetY();
      }
      else {
        ym = p3.GetY();
        yp = p2.GetY();
      }
    }
    else {
      if (p2.GetY() < p3.GetY()) {
        ym = p2.GetY();
        if (p1.GetY() < p3.GetY()) yp = p3.GetY();
        else             yp = p1.GetY();
      }
      else {
        ym = p3.GetY();
        yp = p1.GetY();
      }
    }

    // Compute Z interval
    if (p1.GetZ() < p2.GetZ()) {
      if (p1.GetZ() < p3.GetZ()) {
        zm = p1.GetZ();
        if (p2.GetZ()< p3.GetZ()) zp = p3.GetZ();
        else             zp = p2.GetZ();
      }
      else {
        zm = p3.GetZ();
        zp = p2.GetZ();
      }
    }
    else {
      if (p2.GetZ() < p3.GetZ()) {
        zm = p2.GetZ();
        if (p1.GetZ() < p3.GetZ()) zp = p3.GetZ();
        else             zp = p1.GetZ();
      }
      else {
        zm = p3.GetZ();
        zp = p1.GetZ();
      }
    }
    _oTriangleBox.AddInside(CATMathPoint(xm, ym, zm));
    _oTriangleBox.AddInside(CATMathPoint(xp, yp, zp));
  }

  // Get one of the three vertex indices of the triangle
  inline int & GetVertexId(int index) {return _aVerticesIds[index];}

  // Get the index of the triangle in the original mesh
  inline int GetOriginIndex() { return _oIndex; }

private:

  //------------------------------------------------
  /*inline CATMathOBB & GetOBB();*/
  //------------------------------------------------
  //CATPolyBoundingSphere _oBoundingSphere;
  /*CATMathOBB _oTriangleBV;
  CATMathOBB _oInflatedTriangleBV;
  double _dLastTolerance;*/
  CATPolyInterferenceDecoratedMesh & _rParentMesh;
  int _aVerticesIds[3];
  int _oIndex; // Index in the original mesh

#ifdef POLYBOXF
  CATPolyBoxf _oTriangleBox;
#else
  CATMathBox _oTriangleBox;
#endif
  //------------------------------------------------

#ifdef DECOTRIANGLE_DEBUG
  static int _siNbTrianglesMem;
  static int _siNbMaxTrianglesUsedMem;
#endif

};

//-------------------------------------------------------------------------------
//inline void CATPolyInterfDecoratedTriangle::SetData(const int verticesIds[3], CATPolyInterferenceDecoratedMesh * parentMesh)
//{
//  if (NULL == parentMesh)
//  {
//    return;
//  }
//
//
//
//  _pParentMesh = parentMesh;
//  // Compute AABB
//  int i;
//  for (i = 0; i < 3; i++)
//  {
//    _oTriangleBox.AddInside(parentMesh->GetVertexCoordinate(verticesIds[i]));
//    //_oTriangleBox.AddInside(coords[i]);
//    _aVerticesIds[i] = verticesIds[i];
//    //_aCoords[i] = coords[i];
//  }
//
//  //// Compute the bounding sphere
//  //CATMathVector ab = coords[1] - coords[0];
//  //CATMathVector ac = coords[2] - coords[0];
//  //CATMathPoint center;
//  //CATMathPoint referencePoint = coords[0];
//  //double normAB = ab.SquareNorm();
//  //double abac = ab * ac;
//  //double normAC = ac.SquareNorm();
//  //double d = 2.0 * (normAB * normAC - abac * abac);
//  //if (d < _sdEpslison && d > -_sdEpslison)
//  //{
//  //    // a, b, and c lie on a line. Circle center is center of AABB of the
//  //    // points, and radius is distance from circle center to AABB corner
//  //    double minX = CATMin(coords[0].GetX(), coords[1].GetX(), coords[2].GetX());
//  //    double maxX = CATMax(coords[0].GetX(), coords[1].GetX(), coords[2].GetX());
//  //    double minY = CATMin(coords[0].GetY(), coords[1].GetY(), coords[2].GetY());
//  //    double maxY = CATMax(coords[0].GetY(), coords[1].GetY(), coords[2].GetY());
//  //    double minZ = CATMin(coords[0].GetZ(), coords[1].GetZ(), coords[2].GetZ());
//  //    double maxZ = CATMax(coords[0].GetZ(), coords[1].GetZ(), coords[2].GetZ());
//
//  //    center.SetCoord(0.5 * (minX + maxX), 0.5 * (minY + maxY), 0.5 * (minZ + maxZ));
//  //    referencePoint.SetCoord(minX, minY, minZ);
//  //}
//  //else
//  //{
//  //    double s = (normAB * normAC - normAC * abac) / d;
//  //    double t = (normAC * normAB - normAB * abac) / d;
//  //    // s controls height over AC, t over AB, (1-s-t) over BC
//  //    if (s <= 0.0)
//  //    {
//  //      center = 0.5 * (coords[0] + coords[2]);
//  //    }
//  //    else if (t <= 0.0)
//  //    {
//  //      center = 0.5 * (coords[0] + coords[1]);
//  //    }
//  //    else if (s + t >= 1.0)
//  //    {
//  //      center = 0.5 * (coords[1] + coords[2]);
//  //      referencePoint = coords[1];
//  //    }
//  //    else
//  //    {
//  //      // Point is inside the triangle
//  //      center = coords[0] + s * ab + t * ac;
//  //    }
//  //}
//  //double radius = center.DistanceTo(referencePoint);
//
//
//
//  /*double denom = 2.0 * ((coords[0] - coords[1]) ^ (coords[1] - coords[2])).SquareNorm();
//  double alpha = (coords[1] - coords[2]).SquareNorm() * (coords[0] - coords[1]) * (coords[0] - coords[2]) / denom;
//  double beta = (coords[0] - coords[2]).SquareNorm() * (coords[1] - coords[0]) * (coords[1] - coords[2]) / denom;
//  double gamma = (coords[0] - coords[1]).SquareNorm() * (coords[2] - coords[0]) * (coords[2] - coords[1]) / denom;
//  CATMathPoint center = alpha * coords[0] + beta * coords[1] + gamma * coords[2];
//  double radius = coords[0].DistanceTo(center);*/
//
//  /*_oBoundingSphere.Set(center, radius);*/
//}
//-------------------------------------------------------------------------------
inline CATPolyInterfDecoratedTriangle::CATPolyInterfDecoratedTriangle(CATPolyInterferenceDecoratedMesh & parentMesh,
                                                                      const int index, const int verticesIds[3])
  : _rParentMesh(parentMesh),
    _oIndex(index)
{
  int i;
  for (i = 0; i < 3; i++)
  {
    _aVerticesIds[i] = verticesIds[i];
  }
}
//-------------------------------------------------------------------------------
inline CATPolyInterfDecoratedTriangle::CATPolyInterfDecoratedTriangle(CATPolyInterferenceDecoratedMesh & parentMesh)
  : _rParentMesh(parentMesh)
{
  // indices must be set afterwards
}
//-------------------------------------------------------------------------------
#ifdef POLYBOXF
inline const CATPolyBoxf & CATPolyInterfDecoratedTriangle::GetBoundingBox() const
#else
inline const CATMathBox & CATPolyInterfDecoratedTriangle::GetBoundingBox() const
#endif
{
  return _oTriangleBox;
}
//-------------------------------------------------------------------------------
inline CATBoolean CATPolyInterfDecoratedTriangle::TestTriTriBVs(CATPolyInterfDecoratedTriangle & otherTri, double tolerance) const
{
  //if (_oTriangleBox.IsIntersecting(otherTri._oTriangleBox, tolerance))
  //{
  //  /*float * curDiag = _oTriangleBV.GetDiagonal();
  //  float curDiagBackUp[3] = {curDiag[0], curDiag[1], curDiag[2]};
  //  float tolf = (float) (tolerance + DecoTriangleEpsilon);
  //  curDiag[0] += tolf;
  //  curDiag[1] += tolf;
  //  curDiag[2] += tolf;

  //  CATBoolean res = (CATPolyOBB::Overlap == _oTriangleBV.Test(otherTri._oTriangleBV));
  //   restore diagonal
  //  curDiag[0] = curDiagBackUp[0];
  //  curDiag[1] = curDiagBackUp[1];
  //  curDiag[2] = curDiagBackUp[2];

  //  return res;*/

  //  if (_dLastTolerance < 0.0)
  //  {
  //    // We need to compute the OBB for the first time
  //    ComputeOBB(tolerance);
  //  }
  //  else if (_dLastTolerance != tolerance)
  //  {
  //    _oInflatedTriangleBV = _oTriangleBV;
  //    _oInflatedTriangleBV.Inflate(tolerance);
  //    _dLastTolerance = tolerance;
  //  }
  //  AdditionalData & data = (AdditionalData &) GetAdditionalData();
  //  if (data._dLastTolerance != tolerance)
  //  {
  //     restore obb then inflate it
  //    data._oInflatedTriangleBV = data._oTriangleBV;
  //    data._oInflatedTriangleBV.Inflate(tolerance);
  //    data._dLastTolerance = tolerance;
  //  }
  //  return data._oInflatedTriangleBV.FastIsIntersecting(otherTri.GetAdditionalData()._oTriangleBV);
  //}
  //return FALSE;

  // first test the boundg spheres
  /*double sqDist = _oBoundingSphere.GetCenter().SquareDistanceTo(otherTri._oBoundingSphere.GetCenter());
  double testDist =  (_oBoundingSphere.GetRadius() + otherTri._oBoundingSphere.GetRadius() + tolerance)
                   * (_oBoundingSphere.GetRadius() + otherTri._oBoundingSphere.GetRadius() + tolerance);
  if (sqDist <= testDist)
  {*/
    // Test the boxes
    //return _oTriangleBox.IsIntersecting(otherTri._oTriangleBox, tolerance);
  /*}
  else
  {
    return FALSE;
  }*/

  return _oTriangleBox.FastIsIntersecting(otherTri._oTriangleBox, (polycoordstype)tolerance);
}
//-------------------------------------------------------------------------------
const int * CATPolyInterfDecoratedTriangle::GetVerticesIds() const
{
  return _aVerticesIds;
}
//-------------------------------------------------------------------------------
inline void CATPolyInterfDecoratedTriangle::GetCoords(CATMathPoint coords[3]) const
{
  _rParentMesh.GetVertexCoordinate(_aVerticesIds[0], coords[0]);
  _rParentMesh.GetVertexCoordinate(_aVerticesIds[1], coords[1]);
  _rParentMesh.GetVertexCoordinate(_aVerticesIds[2], coords[2]);
}
//-------------------------------------------------------------------------------
inline void CATPolyInterfDecoratedTriangle::GetNormals(CATMathVector normals[3]) const
{
  _rParentMesh.GetVertexNormal(_aVerticesIds[0], normals[0]);
  _rParentMesh.GetVertexNormal(_aVerticesIds[1], normals[1]);
  _rParentMesh.GetVertexNormal(_aVerticesIds[2], normals[2]);
}
//-------------------------------------------------------------------------------
inline void CATPolyInterfDecoratedTriangle::GetInterferenceNormals(CATMathVector normals[3]) const
{
  _rParentMesh.GetVertexInterfNormal(_aVerticesIds[0], normals[0]);
  _rParentMesh.GetVertexInterfNormal(_aVerticesIds[1], normals[1]);
  _rParentMesh.GetVertexInterfNormal(_aVerticesIds[2], normals[2]);
}
//-------------------------------------------------------------------------------
inline CATBoolean CATPolyInterfDecoratedTriangle::IsSurfacic() const
{
  return _rParentMesh.IsSurfacic();
}
//-------------------------------------------------------------------------------
inline double CATPolyInterfDecoratedTriangle::GetAccuracy() const
{
  return _rParentMesh.GetAccuracy();
}
//-------------------------------------------------------------------------------
const CATPolyInterfDecoratedVertex &
  CATPolyInterfDecoratedTriangle::GetVertexData(int vertexId) const
{
  return _rParentMesh.GetVertexData(_aVerticesIds[vertexId]);
}
//-------------------------------------------------------------------------------
//inline CATMathOBB & CATPolyInterfDecoratedTriangle::GetOBB()
//{
//  if (_dLastTolerance < 0.0)
//  {
//    ComputeOBB(0.0);
//  }
//  return _oTriangleBV;
//}
//-------------------------------------------------------------------------------
inline CATPolyInterferenceDecoratedMesh * CATPolyInterfDecoratedTriangle::GetParentMesh()
{
  return &_rParentMesh;
}
//-----------------------------------------------------------------------------------
inline CATBoolean CATPolyInterfDecoratedTriangle::TestTriMeshBVs(const CATPolyInterferenceDecoratedMesh & mesh,
                                                                 double tolerance) const
{
  return _oTriangleBox.FastIsIntersecting(mesh.GetBoundingBoxf(), (polycoordstype)tolerance);
}
//---------------------------------------------------------------------------
inline void CATPolyInterfDecoratedTriangle::GetCenter(CATMathPoint & oCenter) const
{
  const CATPolyInterfPoint & coord0 = GetVertexData(0)._oCoords;
  const CATPolyInterfPoint & coord1 = GetVertexData(1)._oCoords;
  const CATPolyInterfPoint & coord2 = GetVertexData(2)._oCoords;
  oCenter.SetCoord((coord0.GetX() + coord1.GetX() + coord2.GetX()) / 3.0,
                   (coord0.GetY() + coord1.GetY() + coord2.GetY()) / 3.0,
                   (coord0.GetZ() + coord1.GetZ() + coord2.GetZ()) / 3.0);
}

//---------------------------------------------------------------------------

#endif // CATPolyInterfDecoratedTriangle_H
