// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyArea.h
//
//===================================================================
//
// January 2009  Creation: TL1
//===================================================================
#ifndef CATPolyBodyArea_H
#define CATPolyBodyArea_H

#include "PolyBodyMeasures.h"

#include "CATErrorDef.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

#include "CATMath.h"

#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "CATIPolySurface.h"
#include "CATIPolyMesh.h"

#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATPolyBodyAreaObserver;
class CATechExt;
#endif //CATIAR418


/**
* Class representing the CATPolyBody area operator.
*
* <br><b>Role</b>: Provide a @href CATPolyFace / @href CATPolyBody area operator
* <p>
* Can be applied on a whole @href CATPolyBody
* Compute the center of Gravity.
* @example
*  CATPolyBodyArea pOper;
*  pObject.ComputeBodyArea(iPolyBody, oArea);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByPolyBodyMeasures CATPolyBodyArea
{
public:

	CATPolyBodyArea ();
	~CATPolyBodyArea();

public:

  /** 
  * Short role of the method.
  *
  * <br><b>Role</b>: Compute area of CATPolyBody.
  * The method takes into account all its Polyfaces
  * @param iPolyBody [in]
  *   The CATPolyBody to measure.
  * @param oPolyBodyGravity [out]
  *   Center Of Gravity of iPolyBody
  * @param oPolyBodyArea [out]
  *   The area result.
  *
  * @return
  *   <code>S_OK</code> : always.
  *
  */
  HRESULT ComputeBodyArea ( const CATPolyBody &iPolyBody,
	  						            CATMathPoint  &oPolyBodyGravity,
					                  double &oPolyBodyArea) const;


  /** 
  * Compute area of CATPolyFace
  *
  * <br><b>Role</b>: Compute area of CATPolyFace
  * Sum of its triangles.
  * @param iPolyFace [in]
  *   The CATPolyFace to measure
  * @param oFaceGravity [out]
  *   Center Of Gravity of iPolyFace
  * @param oPolyFaceArea [out]
  *   The area result.
  *
  * @return
  *   <code>S_OK</code> if everything ran ok.
  *	  <code>E_FAIL</code> if face has no mesh.
  */
  HRESULT ComputeFaceArea (	const CATPolyFace &iPolyFace, 
	  						            CATMathPoint  &oFaceGravity,
							              double &oPolyFaceArea) const;

private:

	/** 
	* Compute Triangle Area from its three points.
	*
	* <br><b>Role</b>: Compute Triangle Area from its three points.
	*
	* @param iPoint1 [in]
	*   first point on triangle
	* @param iPoint2 [in]
	*   second point on triangle
	* @param iPoint3 [in]
	*   third point on triangle
	*
	* @return
	*  area of triangle (computed using normal vector length).
	*
	*/
	double ComputeTriangleArea(	const CATMathPoint &iPoint1,
								const CATMathPoint &iPoint2,
								const CATMathPoint &iPoint3) const;

#ifdef CATIAR418
  // For internal use
public:
  inline void SetObserver (CATPolyBodyAreaObserver* iObserver);
  inline CATPolyBodyAreaObserver* GetObserver () const;

protected:
  CATPolyBodyAreaObserver* _Observer;
  CATechExt *_Extension;
#endif //CATIAR418
};

#ifdef CATIAR418
inline void CATPolyBodyArea::SetObserver (CATPolyBodyAreaObserver* iObserver)
{
  _Observer = iObserver;
}

inline CATPolyBodyAreaObserver* CATPolyBodyArea::GetObserver () const
{
  return _Observer;
}
#endif //CATIAR418

/*
 * Compute Triangle Area by normal length
 */
inline double CATPolyBodyArea::ComputeTriangleArea( const CATMathPoint &iPoint1,
													const CATMathPoint &iPoint2,
													const CATMathPoint &iPoint3) const
{
	// triangle bars
	CATMathVector v1 = (iPoint2-iPoint1);
	CATMathVector v2 = (iPoint3-iPoint1);

	// triangle normal
	CATMathVector triangleNormal = v1 ^ v2;

    return 0.5*(triangleNormal.Norm());
}

#endif // !CATPolyBodyArea_H
