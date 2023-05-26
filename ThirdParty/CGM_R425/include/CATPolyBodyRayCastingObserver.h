// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRayCastingObserver.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// March 2012 Creation: JXO
//===================================================================
#ifndef CATPolyBodyRayCastingObserver_h
#define CATPolyBodyRayCastingObserver_h

// Poly
#include "CATRefCounted.h"
class CATCellId;
class CATBVHTreeSet;
class CATPolyBodyRayCastingIntersection;

// Math
class CATMathPoint;
class CATMathVector;
class CATMathSetOfPoints;
class CATMathSetOfVectors;

// ExportedBy
#include "PolyBodyBVHOperators.h"

/** Status Enum memo
 * No point: 1
 * No other points: 2
 * No ray: 4
 * No other rays: 8
 */

/**
 * Observer on CATPolyBodyRayCastingOper to be implemented by callers
 * And react to intersection events.
 * In case of multiple rays, implementation'd better be thread-safe.
 */
class ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingObserver : public CATRefCounted
{
public:
  /** Constructor */
  CATPolyBodyRayCastingObserver(){}

  /** Tells the operator what to do after having found an intersection */
  enum Status{
    Continue = 0, // Intersection is added to the result and the operator continues as planned.
    Skip = 1, // Just skip intersection and continue searching
    AddIntersectionAndStopForThisRay = 2, // Intersection is added and no further search is done for the current ray.
    AddIntersectionAndBreak = 10, // Intersection is added but computation stops.
    Break = 15 // Intersection is not added to the result and computation stops.
  };

  /** To be implemented. */
  virtual Status AddIntersection(int iRayId, const CATMathPoint & iPoint, const CATMathVector & iNormal, int iBodyId = -1, const CATCellId * iCellid = 0, int iFaceIndex = -1, int iTriangleIndex = -1) = 0;

  /** To be implemented. */
  virtual Status AddRayIntersections(int iRayId, const CATPolyBodyRayCastingIntersection * iInter) = 0;


public:
  /** Observe operator operand */
  virtual void SetOperand(CATBVHTreeSet * pTree){}
  /** Observe multithread argument */
  virtual void SetNbThreads(int iNbThreads){}
  /** Observe calls to CastRay */
  virtual void CastRay(int CheckPointOperand, const CATMathPoint & iPoint, const CATMathVector & iDirection, double iRadius = -1., int iRay = 0){}
  /** Observe calls to CastMultipleRays */
  virtual void CastMultipleRays(int CheckPointOperand, const CATMathSetOfPoints & iPoints, const CATMathSetOfVectors & iDirections, double iRadius = -1., int iPackSize = -1.){}

protected:
  /** Destructor */
  ~CATPolyBodyRayCastingObserver(){}

};

/** Operator on enum. */
extern ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingObserver::Status operator |= (CATPolyBodyRayCastingObserver::Status & stat1, CATPolyBodyRayCastingObserver::Status stat2);

#endif

