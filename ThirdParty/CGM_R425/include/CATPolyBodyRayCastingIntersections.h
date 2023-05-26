// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyRayCastingIntersections.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Mars 2012 Creation: JXO
//===================================================================
#ifndef CATPolyBodyRayCastingIntersections_h
#define CATPolyBodyRayCastingIntersections_h

// Poly
class CATPolyBodyRayCastingIntersection;
#include "CATMapOfIntToPtr.h"

// System
#include "CATBoolean.h"

// ExportedBy
#include "PolyBodyBVHOperators.h"

class ExportedByPolyBodyBVHOperators CATPolyBodyRayCastingIntersections
{
public:
  /** Constructor */
  CATPolyBodyRayCastingIntersections();
  /** Destructor */
  ~CATPolyBodyRayCastingIntersections();

  /**
   * This method returns the number of intersections.
   * (Should be the same as the number of rays given to the CastMultipleRays method.
   */
  int GetNbOfRays();

  /**
   * Returns intersection with Ray number iRay.
   * May be null. Do not delete.
   */
  CATPolyBodyRayCastingIntersection * Get(int iRay) const;

  /** @nodoc */
  void AddIntersection(int iRay, CATPolyBodyRayCastingIntersection * iInter);
  /** @nodoc */
  void Absorb(CATPolyBodyRayCastingIntersections * iInters);
  /** To be deleted by caller */
  CATPolyBodyRayCastingIntersection * GetFirst();

protected:
  CATMapOfIntToPtr m_List;
  int m_NumberOfRays;
};

#endif
