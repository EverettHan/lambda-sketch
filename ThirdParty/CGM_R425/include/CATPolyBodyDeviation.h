//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2014
//=============================================================================
//
// Distance Operator between a point cloud and a triangulated surface.
// The distance is given by a map that associate a value to each point
// in the point cloud, corresponding to the minimum distance from this
// point to the surface. Only triangles are considered in the
// given surface.
//
//=============================================================================
// 2014-09-05   XXC: New.
//=============================================================================
#pragma once

#include "PolyBodyDistance.h"

#include "CATListPV.h"
#include "CATListOfDouble.h"
#include "CATPolyRefCounted.h"
#include "CATMathInline.h"
#include "CATMathPoint.h"

#include "CATMapOfPtrToInt.h"
#include "CATHTableOfPtrToPtr.h"

#include "CATTolerance.h"

class CATMathBox;
class CATPolyBody;
class CATMathTransformation;
class CATPolyBoundingVolume;

class PolyDistanceBBOper_Distance;
class CATPolyBodyVertexDistanceLayer;

class CATBVHTree;
class CATBVHNodeConst;
class CAT3DPointSetKDTree;
class Deviation_Surface;
class Deviation_Node;

class ExportedByPolyBodyDistance CATPolyBodyDeviation
{
public:


  class CATPolyDeviationDistance {
  public:
    INLINE CATPolyDeviationDistance ()
      : _Distance (-1.0), _Side (0) {}
    ~CATPolyDeviationDistance () {}

    INLINE double & Distance () { return _Distance; }
    INLINE CATMathPoint & Projection () { return _Projection; }
    INLINE const double & Distance () const { return _Distance; }
    INLINE const CATMathPoint & Projection () const { return _Projection; }
    INLINE double & Side () { return _Side; }
    INLINE const double & Side () const { return _Side; }

  private:
    double _Distance;
    CATMathPoint _Projection;
    double _Side;
  };

  struct StatiscalData {
    StatiscalData():
      Min(-1.),
      Max(-1.),
      Mean(-1.),
      Median(-1.),
      StandardDeviation(-1.),
      Decils{-1,-1,-1,-1,-1,-1,-1,-1,-1}
      {}
    double Min;
    double Max;
    double Mean;
    double Median;
    double StandardDeviation;
    double Decils[9];
  };

  class ExportedByPolyBodyDistance PolyDeviationMap : public CATPolyRefCounted
  {
  public:
    INLINE PolyDeviationMap (int iSizeMap) : _Size (iSizeMap) { _List = new CATPolyDeviationDistance[iSizeMap]; }
    INLINE ~PolyDeviationMap () { delete [] _List; _List = NULL; }

    INLINE void GetProjection (const int iIndex, CATMathPoint & oProjection) const { oProjection = _List[iIndex].Projection (); }
    INLINE void SetProjection (const int iIndex, CATMathPoint iProjection) { _List[iIndex].Projection () = iProjection; }

    INLINE const double operator [] (const int iIndex) const {
      return (_List[iIndex].Side () < 0.0
              ? -_List[iIndex].Distance ()
              : _List[iIndex].Distance ());
    }
    INLINE const CATMathPoint & operator () (const int iIndex) const { return _List[iIndex].Projection (); }

    StatiscalData GetStatiscalData(bool signedStats = true);

  private:
    friend class CATPolyBodyDeviation;
    friend class CATPolyPCAssemblyMinimalDistance;
    INLINE double & operator ^ (const int iIndex) { return _List[iIndex].Distance (); }
    INLINE CATMathPoint & operator / (const int iIndex) { return _List[iIndex].Projection (); }

    INLINE double & operator % (const int iIndex) { return _List[iIndex].Side (); }

    INLINE void Reset () {
      unsigned int i;
      for (i = 0; i < _Size; i++) {
        _List[i].Distance () = -1.0;
        _List[i].Side () = 0;
      }
    }

  private:
    unsigned int _Size;
    CATPolyDeviationDistance * _List;
  };

public:

  /** Main class constructor.
   *@param iToleranceForLengthTest: defines the small epsilon
   *tolerance used for length and scalar products.
   */
  CATPolyBodyDeviation (const CATTolerance & iTol = CATGetDefaultTolerance ());
  virtual ~CATPolyBodyDeviation ();

  /** Defines the poly bodies to use in each set and initialize these
   *  sets by calling the initialization of the mother generic class.
   *@param iPolyBody_diff: the distant CATPolyBody to use to define
   *the set of vertices
   *@param iPolyBody_ref: the reference CATPolyBody to use to define
   *the set of triangles
   *@return S_OK if the initialization worked, E_FAIL otherwise.
   */
  virtual HRESULT Initialize (const CAT3DPointSetKDTree * iPointCloud, CATBVHTree * iPolyBody, CATMathTransformation * iSurfacePosition = NULL);
  virtual HRESULT Initialize (const CAT3DPointSetKDTree * iPointCloud, CATBVHNodeConst * iPolyBody, CATMathTransformation * iSurfacePosition = NULL);

  virtual HRESULT Run (const CATMathTransformation * iSurfacePosition = NULL);
  // HRESULT Brunt();

  /** Release the distance layer, if exists, and reboot the generic
   *  polyhedral distance operator.
   */
  virtual void Reboot ();

  PolyDeviationMap * GetResult () const;
  double GetMin () const;
  double GetMax () const;

protected:

  void Reset ();

  virtual HRESULT Descent (const Deviation_Node & iNode, CATListPV & oChildrenNodes);

  /** Computes the distance between a small point cloud and a small
   *  mesh. Consists basically in iterating on each point then on each
   *  triangles then to computes the distance for each couple
   *  point/triangle.
   *@param iPoints: the vertices in the first set.
   *@param iMesh: the triangle of the second set.
   */
  virtual void ElementToElementDistance (const CAT3DPointSetKDTree & iPoints, const Deviation_Surface & iMesh);
  // void ElementToTreeDistance(const CATMathPoint & iPoint, const int iIndex, const Deviation_Surface & iMesh, double & ioCeilingDistance);

  const CATPolyBoundingVolume* GetBVHNodeBV (const CATBVHNodeConst& iNode);

protected:
  double _ToleranceForLengthTest, _Infinite;
  double * _MapKDTreeNodeToDistance;

  const CAT3DPointSetKDTree * _PointSet;
  CATBVHNodeConst * _TriangleSet;

  CATHTableOfPtrToPtr _BVHLeafToTriangles;
  CATHTableOfPtrToPtr _BVHNodeToTransformedBV;

  int _Min; // Contains the index
  int _Max; // Contains the index

  PolyDeviationMap * _DistancesData; // Distance data for all vertices
  const CATMathPoint ** _BarReferences;

  CATMathTransformation * _MeshPosition;
};
