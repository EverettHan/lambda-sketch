// COPYRIGHT DASSAULT SYSTEMES 2004, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyRegularizeOper2D.h
//
//===================================================================
//
// October 2004  Creation: NDO
//===================================================================
#ifndef CATPolyRegularizeOper2D_H
#define CATPolyRegularizeOper2D_H

#include "PolygonalOperators.h"
#include "CATErrorDef.h"     // HRESULT definition (for compil under UNIX)
#include "CATBoolean.h"
#include "CATMathInline.h"

class CATPolyPolygon2D;
class CATPolyFace2D;
class CATPolyExactArithmetic;
class CATMathPoint2D;
class CATPolyVertex2D;
class CATSetOfPtr;

//#define POLYREGULARIZEOPERFIX 1


/**
* This operator regularizes the triangulation of a CATPolyPolygon2D object
* by flipping bars.  It is applied during triangulation of a polygon for
* optimization of the triangles (constrained Delaunay triangulation).
*
* Here is a usage example of the class:

\code
HRESULT Triangulate (CATPolyPolygon2D& polygon)
{
CATPolyExactArithmetic ea (CATPolyExactArithmetic::eDouble);
CATPolyRegularizeOper2D regularizer (ea);
regularizer.SetUseInCircleForFlipBar ();  // Always set this option.
CATPolyTriangulateOper2D triangulator (ea);
triangulator.SetRegularizeOperator (&regularizer);
return triangulator.Run (polygon);
}
\endcode

* Make sure to always turn on the SetUseInCircleForFlipBar ().
* @see CATPolyTriangulateOper2D
*/
class ExportedByPolygonalOperators CATPolyRegularizeOper2D
{

public:

  /**
  * Constructor.
  */
  CATPolyRegularizeOper2D (const CATPolyExactArithmetic& iExactArithmetic);

  /**
  * Destructor.
  */
  ~CATPolyRegularizeOper2D ();

  /**
  * Sets the in-circle option for regularization.
  * This option should always be set because it speeds up the optimization.
  * Furthermore, without this option the result obtained may not be an optimum solution.
  * It is not set by default.
  */
  INLINE void SetUseInCircleForFlipBar ();

  /**
  * Regularizes the triangulation of a CATPolyPolygon2D object and turn it into
  * a Delaunay triangulation.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT Regularize (CATPolyPolygon2D& ioPolygon);

  //#ifdef POLYREGULARIZEOPERFIX

  /**
  * Regularizes the triangulation of a CATPolyPolygon2D object by iteratively swapping the bars from the input set.
  * This method turns the triangulation of the polygon into a Delaunay triangulation.
  * @param ioPolygon
  *   The input polygon.
  * @param iBars
  *   The input set of bars that are to be tested and swapped if needed.
  *   The bars on this set should only border triangles.
  * @return
  *   <ul>
  *      <li> <tt>S_OK</tt> if the operator runs successfully.
  *      <li> <tt>E_FAIL</tt> if an error occurs.  For example, if a bar is not the boundary of a triangular face.
  *   </ul>
  */
  HRESULT Regularize (CATPolyPolygon2D& ioPolygon, const CATSetOfPtr& iBars);

  //#else

  // TO DO: Revise this method to pass instead a list of bars that can be swapped
  // (instead of a face). Currently, we regularize by swapping the bars whose index is
  // strictly greater than the minimum bar index. 
  // This is not quite correct. 
  // Nov 23, 2006 -NDO
  //
  /**
  * @deprecated
  * Same method as the previous Regularize except that it works with all the triangles assigned to the
  * same face number.
  * @param ioPolygon
  *   The polygon to regularize.
  * @param iFace
  *   The face to which the triangles belong.
  * @return
  *   S_OK if the operator runs successfully and E_FAIL otherwise.
  */
  HRESULT Regularize (CATPolyPolygon2D& ioPolygon, const CATPolyFace2D* iFace,
    const int iMinimumBarIndex);
  //#endif

  /**
  * Provides and external function to flip the bar between two adjacent triangles according to an external criteria.
  *
  *               C                    C
  *              / \                  /|\
  *             /   \                / | \
  *            / T1  \              /  |  \
  *           /       \            /   |   \
  *          A---------B          A T3 | T4 B
  *           \  T2   /            \   |   /
  *            \     /              \  |  /
  *             \   /                \ | /
  *              \ /                  \|/
  *               D                    D
  *
  *     return    0                    1
  *
  *  return 0: no flip bar required
  *         1: flip bar required
  *
  */
  void SetExternalFlipBarFunction (int (*iExternalFlipBarFunction) (void * iContext,
    const CATMathPoint2D &A,
    const CATMathPoint2D &B,
    const CATMathPoint2D &C,
    const CATMathPoint2D &D),
    void * iContext);

  void SetExternalFlipBarFunction (int (*iExternalFlipBarFunction) (void * iContext,
    const CATPolyVertex2D * iVertexA,
    const CATPolyVertex2D * iVertexB,
    const CATPolyVertex2D * iVertexC,
    const CATPolyVertex2D * iVertexD),
    void * iContext);

  // Can't use c++11 under AIX, use functor instead
  struct GetPositionFunctor
  {
    virtual ~GetPositionFunctor(){};
    virtual CATMathPoint2D operator()(const CATPolyVertex2D*) = 0;
  };

  inline void SetGetPositionFunction(GetPositionFunctor * iGetPosition);

private:

  const CATPolyExactArithmetic& _ExactArithmetic;

private:

  CATBoolean _DoUseInCircle;

  int (*_ExternalFlipBarFunction) (void * iContext,
    const CATMathPoint2D &A,
    const CATMathPoint2D &B,
    const CATMathPoint2D &C,
    const CATMathPoint2D &D);

  int (*_ExternalFlipBarFunctionVertex) (void * iContext,
    const CATPolyVertex2D * iVertexA,
    const CATPolyVertex2D * iVertexB,
    const CATPolyVertex2D * iVertexC,
    const CATPolyVertex2D * iVertexD);

  GetPositionFunctor * _GetPosition;

  void *_ContextForExternalFlipBarFunction;

public:

  /**
  * @deprecated
  */
  CATPolyRegularizeOper2D (const CATPolyExactArithmetic* iExactArithmetic);

};


INLINE void CATPolyRegularizeOper2D::SetUseInCircleForFlipBar ()
{
  _DoUseInCircle = TRUE;
}

inline void CATPolyRegularizeOper2D::SetGetPositionFunction(CATPolyRegularizeOper2D::GetPositionFunctor * iGetPosition)
{
  _GetPosition = iGetPosition;
}

#endif

