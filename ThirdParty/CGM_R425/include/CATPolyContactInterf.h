// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyContactInterf.h
//
//===================================================================
//
// Usage notes:
// Interface describing a contact.
//
//===================================================================
//
// Aug 2009 Creation: JS9
// Aug 2015 Modification JXO: Permanently switch to doubles for XSCale compliance
//===================================================================

#ifndef CATPolyContactInterf_h
#define CATPolyContactInterf_h

#include "CATPolyBoundingVolumeOperators.h"

// Other
#include "CATMathPoint.h"
#include "CATBoolean.h"
#include "CATErrorDef.h"
#include "CATListOfDouble.h"

// Interference
#include "CATPolyInterferenceImpl.h"

// Polyhedral
class CATIPolyMesh;

/**
 * Interface describing a contact.
 */
class ExportedByCATPolyBoundingVolumeOperators CATPolyContactInterf : public CATPolyInterferenceImpl
{
public:

  /**
   * Constructor and destructor
   */
  CATPolyContactInterf(int firstObjId, int secondObjId,
                       double firstObjectAccuracy, double secondObjectAccuracy,
                       int firstObjectNbTriangles, int secondObjectNbTriangles);
  virtual ~CATPolyContactInterf();

  /**
   * Get the type of interference. Might be used to cast the interference to its actual
   * implementing class.
   */
  virtual InterferenceType GetInterferenceType() const;

  /**
   * Add a triangle which is in contact.
   * Knowing its three vertices.
   */
  void AddFirstObjectTriangle(const CATMathPoint tri[3]);

  /**
   * Add a triangle which is in contact.
   * Knowing its three vertices
   */
  void AddSecondObjectTriangle(const CATMathPoint tri[3]);

  /**
   * Get the triangles of the first object involved in the interference.
   * The resulting mesh derives from CATBaseUnkown and must released afterwards.
   */
  CATIPolyMesh * GetFirstObjectContact();

  /**
   * Get the triangles of the second object involved in the interference.
   * The resulting mesh derives from CATBaseUnkown and must released afterwards.
   */
  CATIPolyMesh * GetSecondObjectContact();

  /**
   * Get two points realizing the contact.
   * @return S_OK if the p1 and p2 can be retrived, E_FAIL if the two points computation was not selected.
   */
  HRESULT GetTwoPointsInContact(CATMathPoint & p1, CATMathPoint & p2) const;

  // For friend classes
  void SetTwoPointsInContact(const CATMathPoint & p1, const CATMathPoint & p2);

  /**
   * Swap the data of the two interfering objects.
   * First object id become second object id, accuracy are inverted,
   * meshes are inverted,...
   */
  virtual void SwapInterferingObjects();

  // Construction only
  void SetFirstObjectRefinedMesh(CATIPolyMesh & mesh);
  void SetSecondObjectRefinedMesh(CATIPolyMesh & mesh);

  /**
   * Get a refined view of the area in contact between the two object.
   * The mesh is a triangulation of the area using tha accuracy as sag.
   * @return triangular mesh of the area belonging to the first object,
   *         must be released after use.
   */
  CATIPolyMesh * GetFirstObjectRefinedContactArea();

  /**
   * Get a refined view of the area in contact between the two object.
   * The mesh is a triangulation of the area using tha accuracy as sag.
   * @return triangular mesh of the area belonging to the second object,
   *         must be released after use.
   */
  CATIPolyMesh * GetSecondObjectRefinedContactArea();


private:
  //--------------------------------------------------------
  CATListOfDouble & GetFirstObjectTriangles();
  CATListOfDouble & GetSecondObjectTriangles();
  CATIPolyMesh * CreateMeshFromTriangles(CATListOfDouble & triangles) const;
  //--------------------------------------------------------
  CATMathPoint _oFirstContactingPoint;
  CATMathPoint _oSecondContactingPoint;
  CATBoolean _bContactingPointsSet;
  CATBoolean _IsSwapped;
  CATListOfDouble _oFirstObjectTriangles;
  CATListOfDouble _oSecondObjectTriangles;

  CATIPolyMesh * _pRefinedMesh1;
  CATIPolyMesh * _pRefinedMesh2;
  //--------------------------------------------------------
};

#endif // CATPolyContactInterf_h

