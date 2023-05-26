// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBVHContact.h
//
//===================================================================
//
// Usage notes: Operator to compute contact (in a Simulia® way)
// between two assembies embeded in a Bounding Volume Hierarchies
// (BVH)
//
//===================================================================
//
// 2009/11/03 XXC: New from CATPolyVisuContact.h
// 2013/07/02 JXO: Tolerances added in constructor
//===================================================================
#ifndef CATPolyBVHContact_h
#define CATPolyBVHContact_h

#include "PolyVisuContact.h"
#include "CATMathTransformation.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATMapOfBVHNodesToAttributes.h"
#include "CATMapOfIntIntToPtr.h"

class CATBVHTree;
class CATBVHNodeConst;
class CATPolyInContactBodyPairList;
class CATPolyMeshContactThicknessCallback;
class CATPolyBVHContactCellPairStack;
class CATPolyBVHMeshContactThread;
class CATPolyBVHAttribute;

#include "CATTolerance.h"

/**
 * Computes contact between two assemblies.
 * These assemblies are passed as CATBVHTree's (Bounding Volume Hierarchies).
 * These two hierarchies should have been computed with the appropriate
 * builder (see @CATBVHTreeBuilder).
 */

class ExportedByPolyVisuContact CATPolyBVHContact
{
public:
  /**
   * Contact result, 6 different possibilities:
   *    Penetration,
   *    VertexVertex,
   *    VertexEdge,
   *    VertexFace,
   *    EdgeEdge,
   *    EdgeFace.
   */
  enum ContactStatus
  {
    Penetration = 0,
    VertexVertex,
    VertexEdge,
    VertexFace,
    EdgeEdge,
    EdgeFace
  };

public:

  /**
   * Constructor and destructor.
   */
  CATPolyBVHContact (const CATTolerance & iTol = CATGetDefaultTolerance());
  ~CATPolyBVHContact ();

  /** Indicates if the tolerance must be increased by the SAG of
   *  tesselated geometry.
   *  The operator DO NOT use the SAG by default.
   */
  void UseSAG(CATBoolean iUseIt);

  /**
   * Sets first solid.
   *      pTree: First solid is passed as a BVH Tree. See @CATBVHTree and
   *             @CATBVHTreeBuilder.
   *      pMat: Optional positioning.
   * You can call this method as many time as you want, for exemple with same
   * BVH tree but different positioning. Temporary contact computation data can
   * then be reused for better performances.
   */
  void SetFirstOperand(CATBVHTree * pTree, const CATMathTransformation * pMat = NULL);

  /**
   * Sets second solid.
   *      pTree: Second solid is passed as a BVH Tree. See @CATBVHTree and
   *             @CATBVHTreeBuilder.
   *      pMat: Optional positioning.
   * You can call this method as many time as you want, for exemple with same
   * BVH tree but different positioning. Temporary clash computation data can
   * then be reused for better performances.
   */
  void SetSecondOperand(CATBVHTree * pTree, const CATMathTransformation * pMat = NULL);
  
  /**
   * Sets first and second solids.
   *      pTree1: First solid.
   *      pTree2: First solid.
   *      pMat1: Optional positioning of first solid.
   *      pMat1: Optional positioning of second solid.
   * You can call this method as many time as you want, for exemple with same
   * BVH tree but different positioning. Temporary clash computation data can
   * then be reused for better performances.
   */
  void SetOperands(CATBVHTree * pTree1, CATBVHTree * pTree2,
                   const CATMathTransformation * pMat1 = NULL, const CATMathTransformation * pMat2 = NULL);

  /** Sets the contact tolerance, that is a distance below which two
   *  triangles/faces/bodies are considered in contact. If the minimal
   *  distance D, between two bodies, is such that 0 < D <=
   *  +tolerance, then the bodies are in contact. If D == 0,
   *  then the bodies intersect each others. And finally, if D >
   *  tolerance, the two bodies are separated.
   */
  void SetTolerance(double tolerance = 0.1);

  /** Indicates if contact computation must take edges into 
   *  account. Default is not to compute contact with edges.
   *  Note that you must enable it before the SetOperands call,
   *  and that the performances could dramatically decrease.
   */
  void EnableEdges(CATBoolean iEdges = TRUE);
  /** Returns contact on edges status */
  CATBoolean AreEdgesEnabled();

  /** Defines the maximum thickness of any mesh in the assembly (the
   *  geometry surfaces) as the maximum distance of the real surface
   *  to the mesh triangles. If set to 0.0, no thickness is used and
   *  contact are computed only with the reference surfaces. If set
   *  above 0.0 but no Thickness callback is defined, the thickness is
   *  considered uniform and equal to 2.0*iMaximumThickness, the mesh
   *  beeing in the middle of the thick surface for all surfaces. If a
   *  callback is defined, the thickness for a geometric element
   *  (triangle) is given by a point on the surface and an id of the
   *  surface (see @CATPolyMeshContactThicknessCallback).
   */
  void SetMeshMaximumThickness(double iMaximumThickness);

  /** Add a callback that, each time the solver tries to compute a
   *  contact, ask for the triangle thicknesses that has to be added
   *  to the two sides of the oriented geometry. Only one callback can
   *  be defined. If no callback is defined, the thickness is supposed
   *  uniform for any geometry and with value the maximum thickness
   *  defined in CATPolyBVHContact::SetMeshMaximumThickness. (uniform
   *  thickness with maximum thickness valued to 0.0 obviously means
   *  "no thickness").
   */
  void AddMeshThicknessCallback(CATPolyMeshContactThicknessCallback * iThicknessCallback);

  /**
   * Run method. Computes the contact between the two assemblies
   * contained in the previously setted CATPolyVisuBVHTree's.
   * Params:
   *   oResult: pairs of faces in contact, may be NULL if there is no contact.
   */
  HRESULT Run(CATPolyInContactBodyPairList *& oResult);

private:

  int ContinueDescent(CATBVHNodeConst * ipNode1, CATBVHNodeConst * ipNode2);
  HRESULT Descent(CATBVHNodeConst * ipNode1, CATBVHNodeConst * ipNode2);

  /**
   * Frees temporary memory
   */
  int DestroyMap(CATMapOfPtrToPtr & map);

  HRESULT RunThreads();

  HRESULT JoinThreads();

  void DestroyThreads();

  HRESULT ContactCouples();

  HRESULT EditResult();

private:
  double _tolerance; // Tolerance define by user.

  double _MaximumThickness;
  CATPolyMeshContactThicknessCallback * _MeshThicknessCallback;

  CATBoolean _useSAG;
  CATBoolean _onEdges;

  CATBVHTree * _Tree1;
  CATBVHTree * _Tree2;
  CATMathTransformation _Pos1;
  CATMathTransformation _Pos2;
  CATMathTransformation _Pos1To2;
  CATMapOfIntIntToPtr _mapBodyBodyToBodyPair;

  CATPolyInContactBodyPairList * _result;

  CATMapOfPtrToPtr _mapNode2PolyBody;

  CATPolyBVHContactCellPairStack * _Couples;
  CATPolyBVHMeshContactThread ** _MeshMeshContactThread;
  const CATTolerance & m_Tol;

private:
  static int _nbThreads;
};

#endif // CATPolyBVHContact_H
