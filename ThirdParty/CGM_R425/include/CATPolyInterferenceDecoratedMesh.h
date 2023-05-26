// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyInterferenceDecoratedMesh.h
//
//===================================================================
//
// Usage notes:
// Class adding additional informations on a mesh (CATIPolyMesh).
//
//===================================================================
//
// Jul 2009 Creation: JS9
// May 2011 Modification JXO: Normals are now normalized (pb with scale transformations)
//===================================================================

#ifndef CATPolyInterferenceDecoratedMesh_h
#define CATPolyInterferenceDecoratedMesh_h

#include "CATPolyBoundingVolumeOperators.h"

#include "CATPolyInterferenceDecoratedSurface.h"

// System
#include "CATBoolean.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"
#include "CATMathVectorf.h"
#include "CATMathPointf.h"

class CATMapOfIntToInt;

// Polyhedral
#include "CATIPolySurface.h"
#include "CATIPolyMesh.h"
#include "CATPolyBoxf.h"

class CATIPolyMeshTriangleIterator;
class CATIPolySurfaceVertexPositionConstLayer;
class CATIPolySurfaceVertexNormalConstLayer;


// BVH
// #include "CATBVHAttribute.h"
// #include "CATPolyBVHAttribute.h"
#include "CATBVHNodeConst.h"

// Interference
// #include "CATPolyInterfDecoratedPolyBody.h"
class CATPolyInterfDecoratedTriangle;
class CATPolyInterfDecoratedObjectsVisitor;
class CATPolyInterfDecoListPV;
class CATPolyTrimmedCanonic;

//#define CATPOLYINTERFERENCEDECORATEDMESH_DEBUG

// To use floats instead of double in positionned meshes
// uncomment the following line
//#define CPIDM_DECOVERTEX_USE_FLOAT


// Definition of CATPolyInterfVector and
// CATPolyInterfPoint which are either in float
// (CATMathPointf, CATMathVectorf) or in double
// (CATMathPoint, CATMathVector) depending on the required
// accuracy and memory consumption
#ifdef CPIDM_DECOVERTEX_USE_FLOAT

// To be able to use Getters and setters on the CATMathVectorf
class CATPolyInterfVectorf : public CATMathVectorf
{
public:
  CATPolyInterfVectorf() : CATMathVectorf() {}
  CATPolyInterfVectorf(float x, float y, float z) : CATMathVectorf(x, y, z) {}

  inline float GetX() const {return x;}
  inline float GetY() const {return y;}
  inline float GetZ() const {return z;}

  inline void SetCoord(float xCoord, float yCoord, float zCoord)
  {
    x = xCoord;
    y = yCoord;
    z = zCoord;
  }
};

class CATPolyInterfPointf : public CATMathPointf
{
public:
  CATPolyInterfPointf() : CATMathPointf() {}
  CATPolyInterfPointf(float x, float y, float z) : CATMathPointf(x, y, z) {}

  inline float GetX() const {return x;}
  inline float GetY() const {return y;}
  inline float GetZ() const {return z;}

  inline void SetCoord(float xCoord, float yCoord, float zCoord)
  {
    x = xCoord;
    y = yCoord;
    z = zCoord;
  }
};

// Here is the actual definition of the inteff point and vectors
typedef CATPolyInterfVectorf CATPolyInterfVector;
typedef CATPolyInterfPointf CATPolyInterfPoint;

#else

// Here is the actual definition of the inteff point and vectors
typedef CATMathVector CATPolyInterfVector;
typedef CATMathPoint CATPolyInterfPoint;
#endif

/**
 * Structure stored for each vertices of the mesh.
 * It contains:
 * - position and normals of the vertex.
 * - Id of the vertex on the corresponding CATIPolyMesh.
 * - A pointer to the normal to be used for interference.
 */
struct CATPolyInterfDecoratedVertex
{
  CATPolyInterfDecoratedVertex() {_pInterfNormal = &_oNormal;}
  ~CATPolyInterfDecoratedVertex() {_pInterfNormal = NULL;}

  inline void GetCoords(CATMathPoint & coords) const
  {
    coords.SetCoord(_oCoords.GetX(), _oCoords.GetY(), _oCoords.GetZ());
  }
  inline void GetNormal(CATMathVector & normal) const
  {
    normal.SetCoord(_oNormal.GetX(), _oNormal.GetY(), _oNormal.GetZ());
  }

  inline void GetInterfNormal(CATMathVector & interfNormal) const
  {
    if (NULL != _pInterfNormal)
    {
      interfNormal.SetCoord(_pInterfNormal->GetX(), _pInterfNormal->GetY(), _pInterfNormal->GetZ());
    }
  }

  inline void GetInterfNormalNoCheck(CATMathVector & interfNormal) const
  {
    // Use [] operator to fool mkchecksource
    interfNormal.SetCoord(_pInterfNormal[0].GetX(), _pInterfNormal[0].GetY(), _pInterfNormal[0].GetZ());
  }

  inline void SetCoords(float x, float y, float z)
  {
    _oCoords.SetCoord(x, y, z);
  }

  inline void SetCoords(double x, double y, double z)
  {
    _oCoords.SetCoord(x, y, z);
  }

  inline void SetCoords(const CATMathPoint & coords)
  {
    _oCoords.SetCoord(coords.GetX(), coords.GetY(), coords.GetZ());
  }

  inline void SetNormal(float x, float y, float z)
  {
    _oNormal.SetCoord(x, y, z);
  }
  inline void SetNormal(double x, double y, double z)
  {
    _oNormal.SetCoord(x, y, z);
  }

  inline void SetNormal(const CATMathVector & normal)
  {
    _oNormal.SetCoord(normal.GetX(), normal.GetY(), normal.GetZ());
  }

  inline void Translate(const CATMathVector & trans)
  {
    _oCoords.SetCoord(_oCoords.GetX() + trans.GetX(),
                      _oCoords.GetY() + trans.GetY(),
                      _oCoords.GetZ() + trans.GetZ());
  }

  inline void Transform(const CATMathTransformation & transfo)
  {
    TransformCoords(transfo);
    TransformNormals(transfo);
  }

  inline void TransformCoords(const CATMathTransformation & transfo)
  {
#ifdef CPIDM_DECOVERTEX_USE_FLOAT
    CATMathPoint coordD(_oCoords.x, _oCoords.y, _oCoords.z);
    coordD = transfo * coordD;
    _oCoords.SetCoord(coordD.GetX(), coordD.GetY(), coordD.GetZ());
#else
    _oCoords = transfo * _oCoords;
#endif
  }

  inline void TransformNormals(const CATMathTransformation & transfo)
  {
#ifdef CPIDM_DECOVERTEX_USE_FLOAT
    CATMathVector normD(_oNormal.x, _oNormal.y, _oNormal.z);
    normD = transfo * normD;
    _oNormal.SetCoord(normD.GetX(), normD.GetY(), normD.GetZ());
    /* if (_pInterfNormal && _pInterfNormal != &_oNormal) { */
    /*   normD.SetCoord(_pInterfNormal->GetX(), _pInterfNormal->GetY(), _pInterfNormal->GetZ()); */
    /*   normD = transfo * normD; */
    /*   _pInterfNormal->SetCoord(normD.GetX(), normD.GetY(), normD.GetZ()); */
    /* } */
#else
    _oNormal = transfo * _oNormal;
    /* if (_pInterfNormal && _pInterfNormal != &_oNormal) */
    /*   (*_pInterfNormal) = transfo * (*_pInterfNormal); */
#endif
    _oNormal.Normalize();
  }

  // Get the AABB of a set of CATPolyInterfDecoratedVertex
  static void GetVectorsBounds(const CATPolyInterfDecoListPV & vertices,
                               double & xMind, double & xMaxd, double & yMind,
                               double & yMaxd, double & zMind, double & zMaxd);

  CATPolyInterfPoint _oCoords; // Coordinates of the vertex
  CATPolyInterfVector _oNormal; // Normal of the vertex on the face
  CATPolyInterfVector * _pInterfNormal; // Normal to be used for interference computation
  int _oIndex; // Index in the original mesh
};

/**
 * Class adding additional informations on a mesh (CATIPolyMesh).
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyInterferenceDecoratedMesh : public CATPolyInterferenceDecoratedSurface
{
public:

  /**
   * Constructor of the mesh from a parent polybody and a
   * CATIPolymesh.
   * @param initialize only for derived classes.
   */
  CATPolyInterferenceDecoratedMesh(CATPolyInterfDecoratedPolyBody & parentBody,
                                   const CATBVHNodeConst & node,
                                   CATIPolyMesh & realMesh,
                                   CATBoolean computeNormals,
                                   const CATPolyFace* pFace);
  virtual ~CATPolyInterferenceDecoratedMesh();

public:

  CATPolyInterferenceDecoratedMesh * CastAsDecoMesh() { return this; }

public:

  /**
   * @return Enclosed mesh
   */
  inline CATIPolyMesh * GetMesh() const;

  /**
   * @return Canonic surface computed from the enclosed mesh
   */
  inline const CATPolyTrimmedCanonic * GetCanonicSurface() const;

  /**
   * If already registered, return the triangle and its decoration knowing its index.
   * Otherwise return NULL.
   */
  CATPolyInterfDecoratedTriangle & GetCorrespondingTriangle(int triIndex);

  /**
   * Inverse GetCorrespondingTriangle function. If already registered,
   * return the index of a triangle in the decorated mesh.
   * return -1 if the triangle is not in the mesh.
   */
   int GetCorrespondingIndex(const CATPolyInterfDecoratedTriangle & iTriangle) const;

  /**
   * Get the array containing all the triangles to be used.
   */
  inline CATPolyInterfDecoratedTriangle * GetTriangles();


  /**
   * Flush the temporary data stored on the triangles.
   */
  void FlushTriangleCoords();

  /**
   * Flush the coordinates stored per vertex.
   */
  inline void FlushVertexCoords();


  /**
   * Release the mesh and flush all the decorated triangles
   * but keep per vertex data.
   */
  inline void Destroy();

  /**
   * Get the number of triangles contained in the mesh.
   */
  inline int GetNbTriangles() const;

  /**
   * Get the number of vertices contained in the mesh.
   */
  inline int GetNbVertices() const;

  /**
   * Get the coordinate of a vertex.
   */
  inline void GetVertexCoordinate(int localVertexId, CATMathPoint & coords) const;

  /**
   * Get the index of a vertex in the original mesh.
   */
  inline int GetVertexOriginIndex(int localVertexId) const;

  /**
   * Get the index of a vertex in the original mesh.
   */
  int GetTriangleOriginIndex(int localTriangleId) const;

  /**
   * Get the normal of a vertex of the mesh.
   * @param localVertexId id of the vertex between 0 and nbVertices
   */
  inline void GetVertexNormal(int localVertexId, CATMathVector & normal);

  /**
   * Get the normal of a vertex of the mesh. The normal is the average
   * of the different normals of a vertex if its located on an edge.
   * @param localVertexId id of the vertex between 0 and nbVertices
   */
  void GetVertexInterfNormal(int localVertexId, CATMathVector & normal);

  /**
   * Construct a polymesh from a BVH leaf node.
   * An addref should be done afterwards.
   */
  static CATIPolyMesh * ConstructFace(const CATBVHNodeConst & leafNode);

  /**
   * Accept a visitor and call its visit method on the children triangles.
   */
  void Accept(CATPolyInterfDecoratedObjectsVisitor & visitor);

  inline const CATPolyInterfDecoratedVertex & GetVertexData(int localVertexId) const {return _aVerticesData[localVertexId];}
  inline CATPolyInterfDecoratedVertex & GetVertexData(int localVertexId) {return _aVerticesData[localVertexId];}
  /**
   * Retrieve the normals form the polymesh and position them.
   * Whenever possible, normals should be computed when constructing the mesh,
   * it is faster.
   */
  void ComputeNormals();
  static void ComputeInterferenceNormal(const CATPolyInterfDecoListPV & vertexMerge,
                                        CATPolyInterfVector & oNormal);

  inline CATBoolean AreNormalsComputed() {return _bNormalComputed;}

protected:

  /**
   * Its needed to call this function to be sure that the mesh is really initialized.
   */
  void Initialize(CATIPolyMesh & mesh, CATBoolean computeNormals);
  void FinalizeInitialization(); // Must be called after the creation and initial displacement

private:

  //----------------------------------------------------------------------
  // Case when pos is a general transformation
  void ActualPositionSurface(const CATMathTransformation & pos);
  // Case when tranformation is a translation
  void ActualPositionSurface(const CATMathVector & pos);

  void ActualComputeNormals(const CATMathTransformation & pos);
  void ActualComputeNormals();

  // Locate a value either from the array if it is not NULL of the realMap.
  // key must be positive.
  inline CATBoolean Locate(const int * arrayMap, const CATMapOfIntToInt * realMap, int key, int & value) const;

  // Insert a value either in the arrayMap or the realMap
  // key must be positive
  inline void Insert(int * arrayMap, CATMapOfIntToInt * realMap, int key, int value) const;

  void CreateDecoVerticesAndTriangles(CATIPolyMesh & iMesh,
                                      CATIPolyMeshTriangleIterator & triIt,
                                      const CATIPolySurfaceVertexPositionConstLayer & posLayer,
                                      const CATIPolySurfaceVertexNormalConstLayer * normLayer,
                                      int minVertex,
                                      int * arrayMap, CATMapOfIntToInt * realMap,
                                      int & oNbVertices);

  void RestorePosition();

  //----------------------------------------------------------------------

  int _iNbTriangles; // Number of triangles contained in the mesh
  int _iNbVertices; // Number of vertices in the mesh

  CATPolyInterfDecoratedVertex * _aVerticesData;
  CATPolyInterfDecoratedTriangle * _aDecoratedTriangles;
  CATIPolySurfaceVertexPositionConstLayer * _vertexpositionscache;
  CATBoolean _bNormalComputed;
  //----------------------------------------------------------------------
  // Canonical informations
  CATPolyTrimmedCanonic * _Canonic;
};

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
inline CATIPolyMesh * CATPolyInterferenceDecoratedMesh::GetMesh() const
{
  CATIPolySurface * surf = GetSurface();
  return (surf ? surf->CastToTriMesh() : NULL);
}
//-------------------------------------------------------------------------------
inline const CATPolyTrimmedCanonic * CATPolyInterferenceDecoratedMesh::GetCanonicSurface() const
{
  return _Canonic;
}
//-------------------------------------------------------------------------------
inline CATPolyInterfDecoratedTriangle * CATPolyInterferenceDecoratedMesh::GetTriangles()
{
  if (_UpdatePosition) PositionSurface();
  return _aDecoratedTriangles;
}
//-------------------------------------------------------------------------------
inline void CATPolyInterferenceDecoratedMesh::FlushVertexCoords()
{
  // free(_aVerticesData);
  delete[] _aVerticesData;
  _aVerticesData = NULL;
}
//-------------------------------------------------------------------------------
inline void CATPolyInterferenceDecoratedMesh::Destroy()
{
  // Everything except vertex data
  FlushTriangleCoords();
  FlushVertexCoords();
}
//-------------------------------------------------------------------------------
inline int CATPolyInterferenceDecoratedMesh::GetNbTriangles() const
{
  return _iNbTriangles;
}
//-------------------------------------------------------------------------------
inline int CATPolyInterferenceDecoratedMesh::GetNbVertices() const
{
  return _iNbVertices;
}
//-------------------------------------------------------------------------------
inline void CATPolyInterferenceDecoratedMesh::GetVertexCoordinate(int localVertexId, CATMathPoint & coords) const
{
  if (_UpdatePosition) ((CATPolyInterferenceDecoratedMesh *) this)->PositionSurface();
  _aVerticesData[localVertexId].GetCoords(coords);
}
//-------------------------------------------------------------------------------
inline void CATPolyInterferenceDecoratedMesh::GetVertexNormal(int localVertexId, CATMathVector & normal)
{
  if (_UpdatePosition) PositionSurface();
  _aVerticesData[localVertexId].GetNormal(normal);
}
//-------------------------------------------------------------------------------
inline void CATPolyInterferenceDecoratedMesh::GetVertexInterfNormal(int localVertexId, CATMathVector & normal)
{
  if (_UpdatePosition) PositionSurface();
  _aVerticesData[localVertexId].GetInterfNormalNoCheck(normal);
}
//-------------------------------------------------------------------------------
inline int CATPolyInterferenceDecoratedMesh::GetVertexOriginIndex(int localVertexId) const
{
  return _aVerticesData[localVertexId]._oIndex;
}
//-------------------------------------------------------------------------------

#endif // CATPolyInterferenceDecoratedMesh_h
