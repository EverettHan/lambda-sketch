// COPYRIGHT DASSAULT SYSTEMES 2005, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyQMetricOper.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Sep 2001/Aug 2005 creation: NDO
//===================================================================
#ifndef CATPolyQMetricOper_H
#define CATPolyQMetricOper_H

#include "CATErrorDef.h"     // HRESULT definition (compil under UNIX)
#include "CATPolyAnalyzeOperators.h"
#include "CATBoolean.h"

#include "CATListOfInt.h"

class CATIPolyMesh;
class CATMathPoint;
class CATMathVector;

/**
* Class used to compute a matrix that can be used to decide if a vertex (or triangle)
* should be decimated or refined.
* <b>Role</b>: The matrix is calculated for a vertex by considering all triangles
* that share the vertex. The plane equation of the normal of the triangle
* is computed (ax+by+cz+d=0) and the entries in the matrix are updated
* with the cofficients in the following way:<br>
* 
* <pre>
* a^2 ab  ac  ad
* ab  b^2 bc  bd
* ac  bc  c^2 cd
* ad  bd  cd  d^2
* </pre>
* 
* Because the matrix is symmetric, only the upper triangular portion is stored.
* The storage of the matrix is as follows: <br>
*
* <pre>
* q[0] q[1] q[2] q[3]
*      q[4] q[5] q[6]
*           q[7] q[8]
*                q[9]
* </pre>
*
* If the vertex is on the boundary of the mesh then some special treatment
* is necessary. The normal processing is done and then an extra plane is
* created for each edge along the boundary that shares the vertex. The normal
* to the plane is in the same direction as the edge.
*/

class ExportedByCATPolyAnalyzeOperators CATPolyQMetricOper
{

public :

  /**
  * Default constructor.
  */
	CATPolyQMetricOper (CATIPolyMesh * polyMesh, const int vertex);

  /**
  * Destructor.
  */
	~CATPolyQMetricOper (void);

  /**
  * Calculates the Q matrix for the specified vertex.
  * @param ipPolygon
  *   The polygon containing the vertex.
  * @param iNoVertex
  *   The relative index of the vertex for which the Q matrix is calculated.
  * @param qCoeff
  *   The cofficients of the Q matrix.
  */

  HRESULT Run (double * qCoeff);

  /**
  * Calculates the Q matrix for the specified vertex.
  * @param ipPolygon
  *   The polygon containing the vertex.
  * @param iNoVertex
  *   The relative index of the vertex for which the Q matrix is calculated.
  * @param iEdgeVertices
  *   A list of vertices for edges along the boundary of the mesh.
  * @param qCoeff
  *   The cofficients of the Q matrix.
  */

  HRESULT Run (const CATListOfInt & iEdgeVertices, double * qCoeff);

  /**
  * Evaluates the quadratic form v^T Q v.
  * @param qCoeff
  *   Coefficients of the symmetric 4x4 matrix Q.
  * @param v
  *   The vector for which the quadratic form is computed.
  * @return
  *   The quadratic form.
  */

  static double EvaluateQuadraticForm (const double * qCoeff, const double * v);

  static double EvaluateQuadraticForm (const double * qCoeff, const CATMathPoint & point);

private :

  CATIPolyMesh * _PolyMesh;

  int _Vertex;

  // Member variables for stable computation of quadratic form.
  int _I0, _I1, _I2, _I3, _I4, _I5, _I6, _I7, _I8;
  int _J0, _J1, _J2, _J3, _J4, _J5, _J6, _J7, _J8;

  void UpdateMatrix (const CATMathPoint & point,
                     const double N[],
                     double * qCoeff, double alpha = 1.) const;

  /**
   * Same functionality as EvaluateQuadraticForm except that it stabilizes the arithmetic
   * w.r.t. different OS.  (Non-static: uses member variables.)
   * Author: DNR.
   */
  double EvalQuadForm (const double* QCoef, const double* v) const;

};

#endif
