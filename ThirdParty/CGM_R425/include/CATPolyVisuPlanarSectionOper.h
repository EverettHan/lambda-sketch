// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyVisuPlanarSectionOper.h
//
//===================================================================
// April 2009  Creation: NDO
//===================================================================
#ifndef CATPolyVisuPlanarSectionOper_H
#define CATPolyVisuPlanarSectionOper_H

#include "PolyVisuClash.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfPtrToPtr.h"
#include "CATPolyExactArithmetic.h"
#include "CATIAV5Level.h"

class CATRep;
class CAT3DRep;
class CATBVHTree;
class CATBVHTreeSet;
class CATBVHNodeConst;
class CATPolyBody;
class CATMathPlane;
class CATPolyVisuPlanarSectionObserver;
class CATPolyVisuSectionResult;
class CATMathTransformation;
class CATMathPoint;
class CATPolyBoundingVolume;
class CATBVHTreeObserverForSection;
class CATBVHTreeSetObserverForSection;
class CATSoftwareConfiguration;

class DSYSysJobScheduler;

#ifndef CATIAR215
class CAT4x4Matrix;
#endif

#ifdef CATIAR214
#define MULTITHREAD_CATPolyVisuPlanarSectionOper 1
#endif

class BVHPlanarSectionJob;


/**
 * This operator calculates a planar section of a rep given its spatial hierarchy (CATBVHTree or CATBVHTreeSet) and 
 * returns the result in the form of CATPolyVisuSectionResult.
 */
class ExportedByPolyVisuClash CATPolyVisuPlanarSectionOper
{

public:

  /**
   * Interface defining a vertex iterator through the vertices of the clipping polygon.
   * The clipping polygon is a simple polygon which can be set as an option.
   * This interface iterates through the vertices of the clipping polygon.
   * The position of the vertices should lie in the clipping plane.
   * The implementation of this interface must be thread-safe.
   */
  class ClippingPolygonVertexIterator
  {

  public:

    virtual ~ClippingPolygonVertexIterator () {}

  public:

    virtual ClippingPolygonVertexIterator& Begin () = 0;
    virtual CATBoolean End () const = 0;
    virtual ClippingPolygonVertexIterator& operator++ () = 0;

  public:

    /**
     * Returns the position of the current vertex of the clipping polygon.
     */
    virtual const CATMathPoint* GetVertexPosition () = 0;

  };

public:

  /**
   * Interface defining a clipping polygon within the section plane.
   */
  class ClippingPolygon
  {

  public:

    /**
     * Returns a vertex iterator.
     * The vertex iterator should be deleted after a call to this method.
     * The implementation of this method must be thread-safe.
     */
    virtual ClippingPolygonVertexIterator* GetVertexIterator () const = 0;

  };

public:

  /**
   * Constructs a planar section operator given an operand consisting of
   * <ul>
   *   <li> The BVH tree node associated to a rep; and, 
   *   <li> An optional position matrix.
   * </ul>
   */
  CATPolyVisuPlanarSectionOper (CATBVHTree& iBVHTree,
                                const CATMathTransformation* iPositionMatrix = 0,
                                const CATSoftwareConfiguration *iSoftConfig = 0);

  /**
   * Constructs a planar section operator given an operand consisting of
   * <ul>
   *   <li> The BVH tree set associated to a set of reps and positions.
   * </ul>
   */
  CATPolyVisuPlanarSectionOper (CATBVHTreeSet& iBVHTreeSet,
                                const CATSoftwareConfiguration *iSoftConfig = 0);

  ~CATPolyVisuPlanarSectionOper ();

  /**
   * Sets the clipping polygon.
   * By default, the operator does not use any clipping polygon.
   * To unset the clipping polygon, call this method with a null argument.
   * Do not delete the clipping iterator before unsetting it from the operator or deleting the operator.
   */
  void SetClippingPolygon (const CATMathPlane& iPlane, const ClippingPolygon* iClippingPolygon);

  /**
   * Sets the number of threads for running the section in parallel.
   * By default, the operator is mono-thread.  
   * If the number of threads is set to -1, then the operator will determine 
   * an optimal number of threads automatically.
   */
  void SetNbThreads (const int iNbThreads);

public:

  /**
   * Computes a planar section of the rep (given its spatial hierarchy) instances by the plane.
   * The result is an object of type CATPolyVisuSectionResult which contains a list of polygons with geometry
   * and attribute layers.  The caller must delete the returned object.
   */
  HRESULT Run (const CATMathPlane& iPlane, CATPolyVisuSectionResult*& oResult);

  /**
   * Computes a planar section of the rep spatial hierarchy (as given by the BVH tree) instances by the plane.
   * A thickness for the section plane can be set and a clipping polygon be used for trimming the planar section.
   * @param iPlane
   *   The section plane.
   * @param iHalfThickness
   *   A half-thickness for the section plane. 
   *   All points within this distance to the plane will be considered on the plane.
   *   This parameter can be set to 0 to define a plane without any thickness.
   * @param iClippingPolygon
   *   A pointer to the clipping polygon which can be null (no clipping).
   * @param oResult
   *   The result of the section.  It contains a list of polygons with geometry an attribute layer.
   *   It must be deleted by the caller.
   */
  HRESULT Run (const CATMathPlane& iPlane, const double iHalfThickness, const ClippingPolygon* iClippingPolygon, CATPolyVisuSectionResult*& oResult);

  /**
   * Flushes data that is not used anymore, that the section operator has stored in the cache (BVH attributes and Section jobs)
   */
  void Flush ();

  /**
   * Flushes any data the section operator has stored in the cache (BVH attributes and Section jobs)
   */
  void FlushAll();

  /**
   * Flushes any job data the section operator has stored in the cache (not the BVH attributes)
   */
  void FlushSectionJobs();

private:

  CATPolyVisuPlanarSectionObserver* _Observer;

  CATBVHTree* _BVHTree;
  CATBVHTreeObserverForSection * _BVHTreeObs;
  CATBVHTreeSet* _BVHTreeSet;
  CATBVHTreeSetObserverForSection * _BVHTreeSetObs;
  CATMathTransformation* _PositionMatrix;
  const ClippingPolygon* _ClippingPolygon;
  CATPolyBoundingVolume* _ClippingPolygonBV;

#ifdef MULTITHREAD_CATPolyVisuPlanarSectionOper
  DSYSysJobScheduler* _Scheduler;
#endif

  const CATMathPlane* _Plane;

  const CATSoftwareConfiguration* _SoftConfig;
  CATPolyExactArithmetic _ExactArithmetic;

  // Mapping of nodes from the BVH tree to the section data.
  // (Toggle between the two maps.)
  CATMapOfPtrToPtr _NodeToSectionData[2];

  double _HalfThickness;  // The half thickness of the section plane.
  int _CurrentIndex;  // Index of the current map.

  unsigned int _NbThreads;

protected:

  friend class BVHPlanarSectionJob;

  inline const CATPolyExactArithmetic& GetExactArithmetic () const;
  inline const ClippingPolygon* GetClippingPolygon () const;

  inline const CATMathPlane* GetPlane () const;
  inline double GetHalfThickness () const;

private:

  HRESULT ClashNodeWithPlane (CATBVHNodeConst& iNode, CATBoolean isMetaNode, int iBVHTreeID,
                              const CATMathTransformation* iPositionMatrix,
                              const CATMathPlane& iPlane,
                              CATPolyVisuSectionResult& oResult);

  HRESULT ProcessPolyBodyNode (const CATPolyBody& iPolyBody, const CATRep* iRep,
                               CATBVHNodeConst& iNode, int iBVHTreeID,
                               const CATMathTransformation* iPositionMatrix,
                               const CATMathPlane& iPlane,
                               CATPolyVisuSectionResult& oResult);

  HRESULT FetchResults (BVHPlanarSectionJob& iSectionJob,  CATPolyVisuSectionResult& oResult);

  void PrivateFlush(int mapindex);

public:

  /**
   * Reserved for Phoenix capture.
   * Sets an observer with the operator.
   */
  inline void SetCaptureObserver (CATPolyVisuPlanarSectionObserver* iObserver);

  /**
   * Reserved for Phoenix capture.
   * Returns the observer of the operator.
   */
  inline CATPolyVisuPlanarSectionObserver* GetCaptureObserver () const;

};


inline const CATPolyExactArithmetic& CATPolyVisuPlanarSectionOper::GetExactArithmetic () const
{
  return _ExactArithmetic;
}


inline const CATPolyVisuPlanarSectionOper::ClippingPolygon* CATPolyVisuPlanarSectionOper::GetClippingPolygon () const
{
  return _ClippingPolygon;
}


inline const CATMathPlane* CATPolyVisuPlanarSectionOper::GetPlane () const
{
  return _Plane;
}


inline double CATPolyVisuPlanarSectionOper::GetHalfThickness () const
{
  return _HalfThickness;
}


inline void CATPolyVisuPlanarSectionOper::SetCaptureObserver (CATPolyVisuPlanarSectionObserver* iObserver)
{
  _Observer = iObserver;
}


inline CATPolyVisuPlanarSectionObserver* CATPolyVisuPlanarSectionOper::GetCaptureObserver () const
{
  return _Observer;
}

#endif
