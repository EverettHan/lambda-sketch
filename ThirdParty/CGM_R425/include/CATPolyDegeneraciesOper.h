// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyDegeneraciesOper.h
// Header definition of CATPolyDegeneraciesOper
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// October 2004  Creation: NDO
//===================================================================
#ifndef CATPolyDegeneraciesOper_H
#define CATPolyDegeneraciesOper_H

#include "CATPolyAnalyzeOper.h"
#include "CATPolyAnalyzeOperators.h"
#include "CATBoolean.h"

#include "CATListOfInt.h"

class CATMathPoint;


/**
 * This operator finds the degeneracies contained in a polymesh.
 * The type of degeneracies found by the operator are:
 *   1) Needles: triangles with a bar below a tolerance.
 *   2) Caps: triangles with a height below a tolerance.
 *   3) Small angle triangles: triangles that have a very small angle.
 * The degeneracies are checked in the order given above.  For example, if a triangle is a needle (Check 1), 
 * it will not be checked for caps and small angles (Checks 2 and 3.)
 * Checks can be turned on or off.
 */
class ExportedByCATPolyAnalyzeOperators CATPolyDegeneraciesOper : public CATPolyAnalyzeOper
{

public :

  enum DegeneraciesType
  {
    TriangleNotDegenerate,
    TriangleNeedle,
    TriangleCap,
    TriangleSmallAngle
  };

  /**
   * Constructor
   */
  CATPolyDegeneraciesOper (CATIPolyMesh* iPolyMesh);

  /**
   * Destructor
   */
  virtual ~CATPolyDegeneraciesOper ();

  /**
   * Turn on or off the search for needles.
   * A needle is a triangle with a bar below a tolerance.
   */
  void CheckNeedles (const CATBoolean iCheck);

  /**
   * Turn on or off the search for caps.
   * A cap is a triangle with a height below a tolerance.
   */
  void CheckCaps (const CATBoolean iCheck);

  /**
   * Turn on or off the search for small angle triangles.
   * A small angle triangle is a triangle with one of its angle below a tolerance.
   */
  void CheckSmallAngleTriangles (const CATBoolean iCheck);

  /**
   * Sets the tolerance for needles.  A triangle with a bar length smaller than this tolerance is a needle, 
   */
  void SetNeedleTolerance (const double iNeedleTolerance);

  /**
   * Sets the tolerance for caps.  A triangle with a height smaller than this tolerance is a cap. 
   */
  void SetCapTolerance (const double iCapTolerance);

  /**
   * Sets the tolerance for small angles.  If one of the angle in a triangle is smaller than this tolerance, 
   * then the triangle is a small angle triangle.  This is an angle tolerance in radians.
   */
  void SetSmallAngleTolerance (const double iSmallAngleTolerance);

  /**
   * Run the operator
   * @return
   *   S_OK if the operator runs successfully and E_FAIL otherwise.
   */
  HRESULT Run (void);

  /**
   * Run the operator on the selected triangles
   * @return
   *   S_OK if the operator runs successfully and E_FAIL otherwise.
   */
  HRESULT RunOnSelectedTriangles (const CATListOfInt& iTriangles);

  /**
   * Check the triangle and returns the type of its degeneracy. 
   * @return
   *   S_OK if the operator runs successfully and E_FAIL otherwise.
   */
  //HRESULT RunOnSelectedTriangle (const int triangle, DegeneraciesType & degeneracyType);

  //HRESULT RunOnSelectedTriangle (const CATMathPoint & p0,
  //  const CATMathPoint & p1,
  //  const CATMathPoint & p2,
  //  DegeneraciesType & degeneracyType);

  /**
   * Returns the needle triangles.
   * @return
   *   The list of needle triangles.
   */
  const CATListOfInt& GetNeedleTriangles () const;

  /**
   * Returns the bar indices of the needle triangles.
   * For a given needle triangle, this is the index (0, 1 or 2) of the shortest bar.
   * @return
   *   The list of bar indices.
   */
  const CATListOfInt& GetBarIndicesOfNeedleTriangles () const;

  /**
   * Returns the cap triangles.
   * @return
   *   The list of cap triangles.
   */
  const CATListOfInt& GetCapTriangles () const;

  /**
   * Returns the vertex indices of the cap triangles.
   * For a given cap triangle, this is the index (0, 1 or 2) of the vertex with the largest angle.
   * @return
   *   The list of vertex indices.
   */
  const CATListOfInt& GetVertexIndicesOfCapTriangles () const;

  /**
   * Returns the small angle triangles.
   * @return
   *   The list of small angle triangles.
   */
  const CATListOfInt& GetSmallAngleTriangles () const;

  /**
   * Returns the vertex indices of the small angle triangles.
   * For a given small angle triangle, this is the index (0, 1 or 2) of the vertex with the smallest angle.
   * @return
   *   The list of vertex indices.
   */
  const CATListOfInt& GetVertexIndicesOfSmallAngleTriangles () const;

  /**
   * Returns the minimum bar length of the triangles analyzed.
   */
  double GetMinimumBarLength () const;

  /**
   * Returns the minimum cap height of the triangles analyzed.
   */
  double GetMinimumCapHeight () const;

  /**
   * Returns the minimum angle of the triangles analyzed.
   */
  double GetMinimumAngle () const;

private :

  CATBoolean _CheckNeedles;
  CATBoolean _CheckCaps;
  CATBoolean _CheckSmallAngleTriangles;

  double _NeedleTolerance;
  double _CapTolerance;
  double _SmallAngleCosineTolerance;
  double _CapAngleCosineTolerance;

  double _MinimumBarLength;
  double _MinimumCapHeight;
  double _MinimumAngle;

  CATListOfInt _NeedleTriangles;
  CATListOfInt _CapTriangles;
  CATListOfInt _SmallAngleTriangles;

  CATListOfInt _BarIndicesNeedles;
  CATListOfInt _VertexIndicesCaps;
  CATListOfInt _VertexIndicesSmallAngles;
};

#endif
