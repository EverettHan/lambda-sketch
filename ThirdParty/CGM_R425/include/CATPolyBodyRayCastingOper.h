// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRayCastingOper.h
//
//===================================================================
//
// Usage notes:
// Operator to do ray-casting against a BVHTree set.
//
//===================================================================
//
// February 2012 Creation: JXO
// April    2012 Modification: JXO, better architecture for multiple rays
// June     2013 Modification: JXO, CATTolerance for XScale compliance
//===================================================================
#ifndef CATPolyBodyRayCastingOper_h
#define CATPolyBodyRayCastingOper_h

// Poly
class CATBVHTreeSet;
class CATPolyBodyRayCastingIntersection;
class CATPolyBodyRayCastingIntersections;
class CATPolyBodyRayCastingObserver;
class CATPolyBodyRayCastingMetaObserver;
class CATIPolyBodyBVHInputFilter;
class CATIPolyBodyBVHInputFaceFilter;

// Math
class CATMathPoint;
class CATMathVector;
class CATMathSetOfPoints;
class CATMathSetOfVectors;
#include "CATTolerance.h"

// System
#include "CATBoolean.h"
class DSYSysJobScheduler;
#include "CATErrorDef.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

/**
 * Operator to do ray-casting against a BVHTree set.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingOper
{
public:
  /**
   * Constructor
   * @param iInputScene
   *        See documentation of CATPolyBodyBVHTreeSet or CATPolyVisuBVHTreeSet.
   *        BVH tree set may be modified between two calls to method CastRay.
   * @iNbThreads Default is to activate multithread in case of multiple rays.
   */
  CATPolyBodyRayCastingOper(CATBVHTreeSet & iInputScene, int iNbThreads = -1, const CATTolerance & iTol = CATGetDefaultTolerance());
  /** Destructor */
  ~CATPolyBodyRayCastingOper();

  /**
   * Casts a ray in the scene.
   * @param iPoint
   *        Origin of ray
   * @param iDirection
   *        Direction of ray
   * @param oResult
   *        Intersection result. May be null if there is no intersection. To be deleted by caller.
   * @param iRadius
   *        Thickness of the ray. If set to a non negative value, it will define the radius of the cylinder that represents the ray.
   *        Note: Currently not supported.
   * @return S_OK if everything went fine, error code otherwise.
   */
  HRESULT CastRay(const CATMathPoint & iPoint, const CATMathVector & iDirection, CATPolyBodyRayCastingIntersection *& oResult, double iRadius = -1., int iRay = 0);

  /**
   * Casts several rays in the scene.
   * @param iPoints
   *        Origins of rays
   * @param iDirections
   *        Directions of rays. Must be same size as iPoints.
   * @param oResults
   *        Intersection results. May be null if there is no intersection. To be deleted by caller.
   * @param iRadius
   *        Thickness of the rays. If set to a non negative value, it will define the radius of the cylinder that represents the rays.
   *        Note: Currently not supported.
   * @param iPackSize
   *        Used internally to control the way rays are packed together. Don't use.
   * @return S_OK if everything went fine, error code otherwise.
   */
  HRESULT CastMultipleRays(const CATMathSetOfPoints & iPoints, const CATMathSetOfVectors & iDirections, CATPolyBodyRayCastingIntersections *& oResult, double iRadius = -1., int iPackSize = -1.);

  /** Adds an observer on the creation of intersections */
  HRESULT AddObserver(CATPolyBodyRayCastingObserver * pObs);

  /** Set a filter to manage frozen objects or objects 'out of the world' properly. You can release it afterwards. */
  HRESULT SetFilter(CATIPolyBodyBVHInputFilter * iFilter);

  /** Set a filter for faces. You can release it afterwards. */
  HRESULT SetFilter(CATIPolyBodyBVHInputFaceFilter * iFilter);

  /** Result will also contain triangle points and normals, and barycentric coordinates of intersection point. Default is FALSE */
  void SetFullResult(CATBoolean fullresult = TRUE);

  /** Default is to skip Origin of ray whenever it lies on a surface. */
  void KeepOriginInResult(CATBoolean keep = TRUE);

private:
  int m_NbThreads;
  CATBVHTreeSet & m_InputScene;
  const CATTolerance & m_Tol;

  CATIPolyBodyBVHInputFilter * m_BVHFilter;
  CATIPolyBodyBVHInputFaceFilter * m_FaceFilter;
  CATPolyBodyRayCastingMetaObserver * m_MetaObserver;

  int m_NbRealThreads;
  DSYSysJobScheduler * m_pScheduler;

  CATBoolean m_FullResult;
  CATBoolean m_Keep;
};

#endif // CATPolyBodyRayCastingOper_H

