// COPYRIGHT DASSAULT SYSTEMES 2009, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyVolume.h
//
//===================================================================
//
// March 2009  Creation: TL1
// June  2013  Modification JXO: CATTolerance for XScale compliance
// Nov   2022  Modification JXO: CATPolyVolume
//===================================================================
#ifndef CATPolyBodyVolume_H
#define CATPolyBodyVolume_H

#include "PolyBodyMeasures.h"

// Poly
#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "CATIPolySurface.h"
#include "CATIPolyMesh.h"
#include "CATMath3x3Matrix.h"
#include "CATPolyVolume.h"

// Math
#include "CATMath.h"
#include "CATTolerance.h"
#include "CATMathVector.h"
#include "CATMathPoint.h"

// System
#include "CATErrorDef.h"
#include "CATBoolean.h"
#include "CATIAV5Level.h"

#ifdef CATIAR418
class CATPolyBodyVolumeObserver;
class CATechExt;
#endif //CATIAR418


/**
 * Class representing the CATPolyBody volume operator.
 *
 * <br><b>Role</b>: Provide a closed @href CATPolyBody volume operator
 * <p>
 * Compute the center of Inertia while computing the volume.
 * @example
 *  CATPolyBodyVolume volumeOper;
 *  volumeOper.ComputeBodyVolumeAndInertia(iPolyBody, oVolume, oInertiaCenter);
 *
 * @href ClassReference, Class#MethodReference, #InternalMethod...
 */
class ExportedByPolyBodyMeasures CATPolyBodyVolume
{
public:

  // do not compute inertia matrix by default
  CATPolyBodyVolume (CATBoolean iComputeInertiaMatrix = FALSE);

  ~CATPolyBodyVolume ();

public:

  /**
   * Compute Poly Body Volume And Inertia
   *
   * <br><b>Role</b>:  Compute Poly Body Volume And Inertia
   * using method :http://www.geometrictools.com/Documentation/PolyhedralMassProperties.pdf
   * the polyBody must be closed
   * @param iPolyBody [in]
   *   Input Poly body
   *   Note that faces with a 0 multiplicity will  be skipped.
   * @param ipPosition [in]
   *   Optional Poly body transformation. If the determinant is negative, we invert the orientation of triangles.
   * @param oPolyBodyInertia [out]
   *   CATMathPoint : center of intertia of iPolyBody
   * @param oPolyBodyVolume [out]
   *   volume of iPolyBody
   *
   * @return
   *   <code>S_OK</code> if everything ran ok.
   *   <code>S_FALSE</code> if volume is null or negative (non manifold geometry)
   *   <code>E_FAIL</code> if one of its polyFace has no geometry
   */
  HRESULT ComputeBodyVolumeAndInertia (const CATPolyBody &iPolyBody, const CATMathTransformation* ipPosition,
                                       CATMathPoint &oPolyBodyInertia, double &oPolyBodyVolume,
                                       const CATTolerance & iTol = CATGetDefaultTolerance ());

  /**
   * Overload method without position (treated as the identity).
   */
  HRESULT ComputeBodyVolumeAndInertia (const CATPolyBody &iPolyBody,
                                       CATMathPoint  &oPolyBodyInertia, double &oPolyBodyVolume,
                                       const CATTolerance & iTol = CATGetDefaultTolerance ());

  /**
   * Same as above, but for a particular CATPolyVolume
   */
  HRESULT ComputeBodyVolumeAndInertia(const CATPolyBody& iPolyBody, const CATPolyVolume * iVolume, const CATMathTransformation* ipPosition,
    CATMathPoint& oPolyBodyInertia, double& oPolyBodyVolume,
    const CATTolerance& iTol);

  /**
   * Same as above, but for a particular CATPolyVolume
   */
  HRESULT ComputeBodyVolumeAndInertia(const CATPolyBody& iPolyBody, const CATPolyVolume * iVolume,
    CATMathPoint& oPolyBodyInertia, double& oPolyBodyVolume,
    const CATTolerance& iTol);


  // get inertia matrix
  // ComputeBodyVolumeAndInertia have to be called before
  // oInertiaMatrix is unchanged otherwise
  HRESULT GetInertiaMatrix (CATMath3x3Matrix &oInertiaMatrix)
  {
    if (_MatrixComputed)
    {
      oInertiaMatrix = _InertiaMatrix;
      return S_OK;
    }
    return E_FAIL;
  }

private:
  /**
   * Compute triangle contribution to global intertia computation.
   *
   * <br><b>Role</b>: compute volume and update intertia center of polyBody
   *
   * @param iTrianglePoint1 [in]
   *   first point of triangle
   * @param iTrianglePoint2 [in]
   *   second point of triangle
   * @param iTrianglePoint3 [in]
   *   third point of triangle
   *
   * @return
   *  nothing
   *
   */
  void ComputeTriangleContrib (const CATMathPoint &iTrianglePoint1,
                               const CATMathPoint &iTrianglePoint2,
                               const CATMathPoint &iTrianglePoint3);

  //internal utility method (intergral computation)
  inline void Subexpressions (const double &iw0, const double &iw1, const double &iw2,
                              double &of1, double &of2, double &of3,
                              double &og0, double &og1, double &og2);

private:

  const CATMathTransformation* _pPosition;
  CATMath3x3Matrix _InertiaMatrix;
  double _Mult[10];
  double _Integ[10];
  CATBoolean _MatrixComputed;
  CATBoolean _ComputeInertiaMatrix;

#ifdef CATIAR418
  // For internal use
public:
  inline void SetObserver (CATPolyBodyVolumeObserver* iObserver);
  inline CATPolyBodyVolumeObserver* GetObserver () const;

protected:
  CATPolyBodyVolumeObserver* _pObserver;
  CATechExt *_pExtension;
#endif //CATIAR418

};

#ifdef CATIAR418
inline void CATPolyBodyVolume::SetObserver (CATPolyBodyVolumeObserver* iObserver)
{
  _pObserver = iObserver;
}

inline CATPolyBodyVolumeObserver* CATPolyBodyVolume::GetObserver () const
{
  return _pObserver;
}
#endif //CATIAR418

/*
 * David Eberly Method (Geometric Tools) which is based on the Brian Mirtich Method (Revisited)
 * sub expressions used by intergrals computation for inertia
 */
void CATPolyBodyVolume::Subexpressions (const double &iw0, const double &iw1, const double &iw2,
                                        double &of1, double &of2, double &of3,
                                        double &og0, double &og1, double &og2)
{
  double temp0 = iw0 + iw1;
  double temp1 = iw0 * iw0;
  double temp2 = temp1 + iw1 * temp0;

  of1 = temp0 + iw2;
  of2 = temp2 + iw2 * of1;

  if (_ComputeInertiaMatrix)
  {
    of3 = iw0 * temp1 + iw1 * temp2 + iw2 * of2;

    og0 = of2 + iw0 * (of1 + iw0);
    og1 = of2 + iw1 * (of1 + iw1);
    og2 = of2 + iw2 * (of1 + iw2);
  }
}

#endif // !CATPolyBodyVolume_H
