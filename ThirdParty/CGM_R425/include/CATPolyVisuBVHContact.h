//==================================================================-*- C++ -*-
// COPYRIGHT Dassault Systemes 2009
//=============================================================================
//
// Simulia® contact visualization interface.  Proposes an interface
// between Visualization data and the Simulia Contact operator
// @CATPolyBVHContact, based on Bounding Volume Hierarchies
// (@CATBVHTree).
//
//=============================================================================
// 2009-11-05   XXC: New.
// 2013-07-02   JXO: CATTolerance in constructor
//=============================================================================

#ifndef CATPolyVisuBVHContact_h
#define CATPolyVisuBVHContact_h

#include "PolyVisuContact.h"
#include "CATSysBoolean.h"
#include "CATBVHTreeRepBuilder.h"
#include "CATPolyBVHContact.h"

class CATBVHTree;
class CATRep;
class CAT4x4Matrix;
class CATPolyBVHTreeFilterHiddenAndPrimitive;
class CATMathPoint;
class CATPolyInContactBodyPairList;

class CATPolyMeshContactThicknessCallback;

#include "CATTolerance.h"

class ExportedByPolyVisuContact CATPolyVisuBVHContact
{
 public:
  CATPolyVisuBVHContact(const CATTolerance & iTol = CATGetDefaultTolerance());

  ~CATPolyVisuBVHContact();

  /** Defines the two objects to use for the distance computation.
   *@param iRep1: visualization representation of the first 3D object.
   *@param iPosition1: position to use for the first 3D object.
   *@param iRep2: visualization representation of the first 3D object.
   *@param iPosition2: position to use for the second 3D object.
   *@return S_OK if the initialization succeeded, E_FAIL otherwise.
   */
  HRESULT SetOperands(CATRep * iRep1, CAT4x4Matrix * iPosition1,
                              CATRep * iRep2, CAT4x4Matrix * iPosition2);

  /** Sets the contact tolerance, that is a distance below which two
   *  triangles/faces/bodies are considered in contact. If the minimal
   *  distance D, between two bodies, is such that 0 < D <=
   *  +tolerance, then the bodies are in contact. If D == 0,
   *  then the bodies intersect each others. And finally, if D >
   *  tolerance, the two bodies are separated.
   */
  void SetTolerance(double tolerance = 0.1);

  /** Indicates if the tolerance must be increased by the SAG of
   *  tesselated geometry.
   *  The operator DO NOT use the SAG by default.
   */
  void UseSAG(CATBoolean iUseIt = TRUE);

  /** Indicates if contact computation must take edges into 
   *  account. Default is not to compute contact with edges.
   *  Note that you must enable it before the SetOperands call,
   *  and that the performances could dramatically decrease.
   */
  void EnableEdges(CATBoolean iEdges = TRUE);

  /** Defines the maximum thickness a any mesh in the assembly (the
   *  geometry surfaces). If set to 0.0, no thickness is used and
   *  contact are computed only with the reference surfaces. If set
   *  above 0.0 but no Thickness callback is defined, the thickness is
   *  considered uniform and equal to the maximum surface given for
   *  all surfaces. If a callback is defined, the thickness for a
   *  geometric element (triangle) is given by a point on the surface
   *  and an id of the surface (see @).
   */
  void SetMeshMaximumThickness(double iMaximumThickness);

  /** Add a callback that, each time the solver tries to compute a
   *  contact, ask for the triangle thicknesses that has to be added
   *  to the two sides of the oriented geometry. Only one callback can
   *  be defined. If no callback is defined, the thickness is supposed
   *  uniform for any geometry and with value the maximum thickness
   *  defined in CATPolyVisuBVHContact::SetMeshMaximumThickness. (uniform
   *  thickness with maximum thickness valued to 0.0 obviously means
   *  "no thickness").
   */
  void AddMeshThicknessCallback(CATPolyMeshContactThicknessCallback * iThicknessCallback);

  /** Run the operator: compute the minimum distance between the two
   *  given objects, according to two optional positions.
   *@param oResult: the result containing all body pairs in contact.
   *@param iPosition1: position to apply to the first object.
   *@param iPosition2: position to apply to the second object.
   */
  HRESULT Run(CATPolyInContactBodyPairList *& oResult, const CAT4x4Matrix * iPosition1 = NULL, const CAT4x4Matrix * iPosition2 = NULL);

  /** Force the freed of recorded data and refresh the operator to admit new operands.
   */
  void Reboot();

 private:
  CATPolyBVHContact _Operator;     // The main contact operator.
  CATBVHTree * _Tree1, * _Tree2; // BVH trees
  CATRep *_Operand1, *_Operand2;
};

#endif //CATPolyVisuBVHContact_h
