// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyClearanceInterf.h
//
//===================================================================
//
// Usage notes:
// Interface describing a clearance.
//
//===================================================================
//
// Jul 2009 Creation: JS9
//===================================================================

#ifndef CATPolyClearanceInterf_h
#define CATPolyClearanceInterf_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
class CATMathPoint;

// Polyhedral
class CATIPolyMesh;

// Interference
#include "CATPolyContactInterf.h"
#include "CATIPolyInterference.h"

/**
 * Interface describing a clearance.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyClearanceInterf : public CATPolyContactInterf
{
public:

  /**
   * Constructor and destructor
   */
  CATPolyClearanceInterf(int firstObjId, int secondObjId,
                         double firstObjectAccuracy, double secondObjectAccuracy,
                         int firstObjectNbTriangles, int secondObjectNbTriangles);
  virtual ~CATPolyClearanceInterf();

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const ;

  /**
   * Get the triangles of the first object involved in the interference.
   * The resulting mesh derives from CATBaseUnkown and must released afterwards.
   */
  CATIPolyMesh * GetFirstObjectClearance();

  /**
   * Get the triangles of the second object involved in the interference.
   * The resulting mesh derives from CATBaseUnkown and must released afterwards.
   */
  CATIPolyMesh * GetSecondObjectClearance();

  /**
   * Get the minimal distance between the local minimum distance in the clearance area.
   */
  double GetMinDistance() const;

  /**
   * Get two points realizing the minimum distance.
   * @return S_OK if the p1 and p2 can be retrived, E_FAIL is minimal distance computation was not selected.
   */
  HRESULT GetMinDistancePoints(CATMathPoint & p1, CATMathPoint & p2) const;

  /**
   * Get a refined view of the area in clearance between the two object.
   * The mesh is a triangulation of the area using tha accuracy as sag.
   * @return triangular mesh of the area belonging to the first object,
   *         must be released after use.
   */
  CATIPolyMesh * GetFirstObjectRefinedClearanceArea();

  /**
   * Get a refined view of the area in clearance between the two object.
   * The mesh is a triangulation of the area using tha accuracy as sag.
   * @return triangular mesh of the area belonging to the second object,
   *         must be released after use.
   */
  CATIPolyMesh * GetSecondObjectRefinedClearanceArea();

  /**
   * Set the two points satisfying the manimal distance.
   */
  void SetMinDistancePoints(const CATMathPoint & p1, const CATMathPoint & p2);

  /**
   * Swap the data of the two interfering objects.
   * First object id become second object id, accuracy are inverted,
   * meshes are inverted,...
   */
  virtual void SwapInterferingObjects();

};

#endif // CATPolyClearanceInterf_h
