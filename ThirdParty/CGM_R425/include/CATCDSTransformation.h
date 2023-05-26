// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATCDSTransformation:
//   Transformation class based on CATMathTransformation.
//
//=============================================================================
//
// Usage notes:
//
//
//=============================================================================
//  Jan 2003  Creation                                 Ilia Ivanov
//=============================================================================

#ifndef CATCDSTransformation_H
#define CATCDSTransformation_H

#include "CDSMathematics.h"

#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"
#include "CATCDS3Frame.h"
#include "CATCDS3x3Matrix.h"
#include "CATCDSConstants.h"
#include "CATCDSInline.h"
#include "CATCDSQuaternion.h"
#include "CATCDSStream.h"

class CATCDSMatrix;
class CATCDSStream;
class CATMemAllocator;

/**
 * Class representing a transformation in dimension 3.
 * <br>It is composed of a matrix <tt>Matrix</tt>,
 * and of a translation <tt>Vector</tt>.
 * <br><tt><table width = 40>
 *    <tr><td> Matrix= </td><td> a11 </td><td> a12 </td><td> a13 </td>
 *        <td> Vector= </td><td> u1 </td></tr>
 *    <tr><td></td>         <td> a21 </td><td> a22 </td><td> a23 </td>
 *        <td>         </td><td> u2 </td></tr>
 *    <tr><td></td>         <td> a31 </td><td> a32 </td><td> a33 </td>
 *        <td>         </td><td> u3 </td></tr>
 *        </table></tt>
 * <br>Apply transformations by using the <tt>*</tt> operator.
 */
class ExportedByCDSMathematics CATCDSTransformation
{
public:
  //============================================================================
  //- Constructors
  //============================================================================
  /**
   * Constructs an Identity transformation.
   * <br> <tt>Matrix = Identity</tt>, <tt>Vector = (0,0,0)</tt>
   */
  CATCDSTransformation();

  /**
   * Constructs a CATCDSTransformation from a CATMath3x3Matrix and a CATCDS3Vector.
   */
  CATCDSTransformation(const CATCDS3x3Matrix& iMatrix, const CATCDS3Vector& iVector);
  CATCDSTransformation(const CATCDS3Vector& iVector, const CATCDS3x3Matrix& iMatrix);
  CATCDSTransformation(const CATCDS3Point& iPos, const CATCDS3x3Matrix& iMatrix);

  CATCDSTransformation(const CATCDS3Vector& iPos, const CATCDSQuaternion& iOrientation);
  CATCDSTransformation(double iX, double iY, double iZ, const CATCDSQuaternion& iOrientation);

  /**
   * Constructs a translation.
   */
  explicit CATCDSTransformation(const CATCDS3Vector& iVector);

  /**
   * Copy constructor.
   */
  CATCDSTransformation(const CATCDSTransformation& iTransformation);

  /**
   * Assignment operator.
   */
  CATCDSTransformation& operator=(const CATCDSTransformation& iTransformation);

  // Equality test operators
  bool operator==(const CATCDSTransformation& iTransformation) const;

  bool operator!=(const CATCDSTransformation& iTransformation) const;

  bool operator<(const CATCDSTransformation& iTransformation) const;

  //===========================================================================
  //  Get/Set
  //===========================================================================
  /**
   * Retrieves the CATMath3x3Matrix associated with <tt>this</tt> CATCDSTransformation.
   */
  void GetMatrix(CATCDS3x3Matrix& oMatrix) const;

  /**
   * Retrieves the CATMath3x3Matrix associated with <tt>this</tt> CATCDSTransformation.
   */
  CATCDS3x3Matrix const& GetMatrix() const;

  /**
   * Retrieves the CATMath3x3Matrix associated with <tt>this</tt> CATCDSTransformation.
   */
  CATCDS3x3Matrix& GetMatrix();

  /**
   * Sets the matrix of <tt>this</tt> CATCDSTransformation.
   */
  void SetMatrix(const CATCDS3x3Matrix& iMatrix);

  /**
   * Retrieves the CATCDS3Vector associated with <tt>this</tt> CATCDSTransformation.
   */
  void GetVector(CATCDS3Vector& ioVector) const;

  /**
   * Retrieves the CATCDS3Vector associated with <tt>this</tt> CATCDSTransformation.
   */
  CATCDS3Vector const& GetVector() const;

  /**
   * Retrieves the CATCDS3Vector associated with <tt>this</tt> CATCDSTransformation.
   */
  CATCDS3Vector& GetVector();

  /**
   * Sets the vector of <tt>this</tt> CATCDSTransformation.
   */
  void SetVector(const CATCDS3Vector& iVector);

  /**
   * Retrieves the vector associated with <tt>this</tt> CATCDSTransformation.
   */
  void GetVector(double oaVector[3]) const;

  /**
   * Retrieves the coefficients of <tt>this</tt> CATCDSTransformation in an
   * array[3][3] and an array[3] of doubles.
   */
  void GetCoef(double oaMatrix[3][3], double oaVector[3]) const;

  /**
   * Retrieves the 2D transformation associated with <tt>this</tt> CATCDSTransformation.
   */
  void GetTransformation2D(double oaMatrix[3][3]) const;

  /**
   * Set Euler parameters for this transformation
   * (3 rotation angles around + 3 translations along the main axes).
   * @param iaParams array of 6 parameters: 3 angles + 3 shifts
   */
  void SetEulerParameters(const double iaParams[6]);

  /**
   * Get exponential parameters for this transformation.
   * @param oaParams array of 6 exponential parameters
   */
  void GetExponentialParameters(double oaParams[6]) const;

  /**
   * Set exponential parameters for this transformation.
   * @param iaParams array of 6 exponential parameters
   */
  void SetExponentialParameters(const double iaParams[6]);

  /**
   * Get helical parameters for this transformation.
   * Each 3D transformation can be represented as a helical transformation:
   * a rotation around some axis and a translation along this axis.
   * @param oPoint point on the axis nearest to the origin
   * @param oVector unit vector for the axis
   * @param oAngle rotation angle around the axis
   * @param oShift translation shift along the axis
   */
  void GetHelicalParameters(
    CATCDS3Vector& oPoint,
    CATCDS3Vector& oVector,
    double& oAngle,
    double& oShift) const;

  /**
   * Set helical parameters for this transformation.
   * Each 3D transformation can be represented as a helical transformation:
   * a rotation around some axis and a translation along this axis.
   * @param iPoint point on the axis nearest to the origin
   * @param iVector unit vector for the axis
   * @param iAngle rotation angle around the axis
   * @param iShift translation shift along the axis
   */
  void SetHelicalParameters(
    const CATCDS3Vector& iPoint,
    const CATCDS3Vector& iVector,
    double iAngle,
    double iShift);

  /**
  * Scale exponential parameters for this transformation.
  * @param iPower exponential parameters scale factor
  */
  void Pow(double iPower);

  void Orthonormalize();

  /**
   * Retrieves the inverse of <tt>this</tt> CATCDSTransformation.
   */
  void Inverse(CATCDSTransformation& oInverse) const;

  /**
   *  Set element a44 in 4x4 representation to zero (used for derivation).
   *  @param iVal
   *    value to set up
   *  @return
   *    previous value
   */
  CATCDSBoolean SetZero(CATCDSBoolean iVal);

  /**
   *  Set transformation that transform specified object into
   *  canonical position.
   *  Canonical position is [(0.0, 0.0, 0.0) for point,
   *  [(0.0, 0.0, 0.0, 1.0, 0.0, 0.0) for line or plane.
   *  @param iType
   *    size of array of coordinates iaCoord
   *  @param iaCoord
   *    array of coordinates of specified object
   */
  void SetLeftAdjustment(int iType, double const iaCoord[]);

  /**
   *  Set transformation that transform specified object from
   *  canonical position into specified placement.
   *  Canonical position is [(0.0, 0.0, 0.0) for point,
   *  [(0.0, 0.0, 0.0, 1.0, 0.0, 0.0) for line or plane.
   *  @param iType
   *    size of array of coordinates iaCoord
   *  @param iaCoord
   *    array of coordinates of specified object
   */
  void SetRightAdjustment(int iType, double const iaCoord[]);

  /**
   *  Set transformation that transform XY plane into sketch plane.
   *  @param iaCoord
   *    sketch coordinates
   */
  void SetSketch(const double iaCoord[]);

  /**
   *  Compares transformation with given tolerance.
   *  @param iTransformation
   *    transformation to compare with
   *  @return
   *    TRUE if equal and FALSE otherwise
   */
  CATCDSBoolean IsEqual(const CATCDSTransformation& iTransformation, double iLinearTolerance, double iAngularTolerance) const;

  /**
   *  Checks whether matrix is identity with given tolerance.
   *  @return
   *    TRUE if identity and FALSE otherwise
   */
  CATCDSBoolean IsIdentityMatrix(double iTolerance) const;

  /**
   *  Checks whether vector is null with given tolerance.
   *  @return
   *    TRUE if null and FALSE otherwise
   */
  CATCDSBoolean IsNullVector(double iTolerance) const;

  /**
   *  Checks whether transformation is identity with given tolerance.
   *  @return
   *    TRUE if identity and FALSE otherwise
   */
  CATCDSBoolean IsIdentity(double iLinearTolerance = CATCDSEpsilon, double iAngularTolerance = CATCDSEpsilon) const;

  /**
   *  Scale vector.
   */
  void Scale(double iFactor);

  /**
   *  Write transformation.
   */
  void Write(const char* iName) const;

  //===========================================================================
  //  Overloaded operators
  //===========================================================================
  /**
   * Defines the composition of two CATCDSTransformations.
   * @return
   * The CATCDSTransformation defined by:
   * <tt> Matrix = iTransformation1.Matrix * iTransformation2.Matrix</tt>
   *<br><tt> Vector = iTransformation1.Matrix * iTransformation2.Vector + iTransformation1.Vector</tt>
   */
  friend ExportedByCDSMathematics CATCDSTransformation operator*(
    const CATCDSTransformation& iTransformation1,
    const CATCDSTransformation& iTransformation2);

  CATCDSTransformation& operator*=(const CATCDSTransformation& iTransformation);

  /**
   * Defines the composition of two CATCDSTransformations
   * (*this * iTransformation OR iTransformation * *this).
   * The _is_zeroed flag is used.
   */
  void Multiply(const CATCDSTransformation& iTransformation, CATCDSBoolean iLeft = FALSE);

  /**
   * Defines the CATCDS3Point transformation.
   * @return
   *  The CATCDS3Point defined by:
   * <tt> iTransformation.Matrix*iPoint + iTransformation.Vector</tt>
   */
  friend ExportedByCDSMathematics CATCDS3Point operator*(
    const CATCDSTransformation& iTransformation,
    const CATCDS3Point& iPoint);

  /**
  * Defines the CATCDS3Point inverse transformation.
  * @return
  *  The CATCDS3Point defined by:
  * <tt> Inverse(*this) * iPoint </tt>
  */
  CATCDS3Point MultTranspose(const CATCDS3Point& iPoint) const;

  /**
   * Defines the CATCDS3Vector transformation.
   * @return
   *  The CATCDS3Vector defined by <tt> iTransformation.Matrix*iVector </tt>
   */
  friend ExportedByCDSMathematics CATCDS3Vector operator*(
    const CATCDSTransformation& iTransformation,
    const CATCDS3Vector& iVector);

  /**
  * Defines the CATCDS3Vector inverse transformation.
  * @return
  *  The CATCDS3Vector defined by:
  * <tt> Inverse(*this) * iVector </tt>
  */
  CATCDS3Vector MultTranspose(const CATCDS3Vector& iVector) const;

  /**
   * Defines the CATCDS3Frame transformation.
   * @return
   *  The CATCDS3Frame defined by:
   * <tt> iTransformation.Matrix*iFrame.Origin + iTransformation.Vector</tt>
   * <tt> iTransformation.Matrix*iFrame.VectorI</tt>
   * <tt> iTransformation.Matrix*iFrame.VectorJ</tt>
   * <tt> iTransformation.Matrix*iFrame.VectorK</tt>
   */
  friend ExportedByCDSMathematics CATCDS3Frame operator*(
    const CATCDSTransformation& iTransformation,
    const CATCDS3Frame& iFrame);

  /**
  * Apply the inverse transformation to input transformation.
  * @return
  *  The transformation defined by:
  * <tt> Inverse(*this) * iT </tt>
  */
  CATCDSTransformation MultTranspose(CATCDSTransformation const &iT) const;

  //===========================================================================
  //  Special functions
  //===========================================================================

  /**
   * Compute a 6-vector H such that: exp(dt*H)exp(U) = exp(U+dt*L),
   * where exp is the exponential mapping of 6-vectors into 3D transformations.
   */
  static void ComputeExpDerivativeAlongDirection(
    const double iaU[6],
    const double iaL[6],
    double oaH[6]);

  /**
   * Compute a 6x6 left-to-right Lie algebra matrix A(this):
   * see "Architecture of RR", paragraph 1.4.
   */
  void GetLeftToRightLieAlgebraMapping(CATCDSMatrix& oM);

  //Getters, Setters
  void GetPosition(double& oX, double& oY, double& oZ);
  CATCDS3Vector const& GetPosition() const;
  CATCDS3Vector& GetPosition();
  void GetPosition(CATCDS3Vector& oPosition) const;
  CATCDS3x3Matrix const& GetOrientation() const;
  void GetOrientation(CATCDS3x3Matrix& oOrientation) const;
  void GetOrientation(CATCDSQuaternion& oQ) const;

  void SetPosition(double iX, double iY, double iZ);
  void SetPosition(CATCDS3Vector const& iVector);
  void SetPosition(CATCDS3Point const& iPoint);
  void SetOrientation(CATCDS3x3Matrix const& iMatrix);
  void SetOrientation(CATCDSQuaternion const& iQ);
  void SetOrientation(double iAngle, double iXRotAxis, double iYRotAxis, double iZRotAxis);

  void Set(const CATCDS3Vector& iPos, const CATCDS3x3Matrix& iOrientation);
  void Set(const CATCDS3Vector& iPos, const CATCDSQuaternion& iOrientation);

  void GetOrientationBasis(CATCDS3Vector& oAxisX, CATCDS3Vector& oAxisY, CATCDS3Vector& oAxisZ) const;

#ifdef CPP11_AVAILABLE
  void GetPositionAndOrientation(cds::span<double, 3> iPosition, cds::span<double, 4> iOrientation) const;
#endif
  //
  // Translate
  //
  void Translate(double iX, double iY, double iZ);
  void Translate(const CATCDS3Vector& iPosition);

  //
  // Rotate
  //
  void Rotate(double iAngle, double iXRotAxis, double iYRotAxis, double iZRotAxis);
  void Rotate(CATCDSQuaternion const& iOrientation);

  //
  // Inverse
  //
  void Invert();
  CATCDSTransformation GetInverse() const;

  //
  // Frame composition
  //
  void ParentToChild(CATCDSTransformation& ioPlacement) const;
  void ChildToParent(CATCDSTransformation& ioPlacement) const;
  void ChildToParentOrientation(CATCDSTransformation& ioPlacement) const;
  //
  // Point transformation
  //
  void ParentToChild(CATCDS3Point& ioPoint) const;
  void ParentToChild(CATCDS3Vector& ioPoint) const;
  void ChildToParent(CATCDS3Point& ioPoint) const;
  void ChildToParent(CATCDS3Vector& ioPoint) const;
  //
  // Vector transformation; apply only the rotation
  //
  void ParentToChildVector(CATCDS3Vector& ioVector) const;
  void ChildToParentVector(CATCDS3Vector& ioVector) const;

  void ParentToChild(CATCDSQuaternion& ioQuaternion) const;
  void ChildToParent(CATCDSQuaternion& ioQuaternion) const;

  void ChildToParentMatrix(CATCDS3x3Matrix& ioMatrix) const;
  void ParentToChildMatrix(CATCDS3x3Matrix& ioMatrix) const;
  void ChildToParent(CATCDS3x3Matrix& ioMatrix) const;
  void ParentToChild(CATCDS3x3Matrix& ioMatrix) const;

#ifdef CDS_DEBUG
  void Write(CATCDSStream& ioStream) const;
#endif

protected:
  CATCDS3x3Matrix _matrix;
  CATCDS3Vector _vector;
  CATCDSBoolean _is_zeroed;
};

#ifdef CDS_DEBUG
CATCDSInline CATCDSStream& operator<<(CATCDSStream& ioStream, CATCDSTransformation const& iTransformation)
{
  iTransformation.Write(ioStream);
  return ioStream;
}
#endif

CATCDSInline CATCDSTransformation::CATCDSTransformation(const CATCDS3Vector& iPos, const CATCDSQuaternion& iOrientation)
  : _vector(iPos)
{
  iOrientation.ExportMatrix(_matrix);
}

CATCDSInline CATCDSTransformation::CATCDSTransformation(const CATCDS3Point& iPos, const CATCDS3x3Matrix& iMatrix)
  : _vector(iPos[0], iPos[1], iPos[2])
  , _matrix(iMatrix)
{

}

CATCDSInline CATCDSTransformation::CATCDSTransformation(double iX, double iY, double iZ, const CATCDSQuaternion& iOrientation)
{
  _vector.Set(iX, iY, iZ);
  iOrientation.ExportMatrix(_matrix);
}

CATCDSInline void CATCDSTransformation::GetPosition(double& oX, double& oY, double& oZ)
{
  oX = _vector.GetX();
  oY = _vector.GetY();
  oZ = _vector.GetZ();
}

CATCDSInline CATCDS3Vector const& CATCDSTransformation::GetPosition() const
{
  return _vector;
}

CATCDSInline CATCDS3Vector& CATCDSTransformation::GetPosition()
{
  return _vector;
}

CATCDSInline void CATCDSTransformation::GetPosition(CATCDS3Vector& oPosition) const
{
  oPosition = _vector;
}

CATCDSInline CATCDS3x3Matrix const& CATCDSTransformation::GetOrientation() const
{
  return _matrix;
}

CATCDSInline void CATCDSTransformation::GetOrientation(CATCDS3x3Matrix& oOrientation) const
{
  oOrientation = _matrix;
}

CATCDSInline void CATCDSTransformation::GetOrientation(CATCDSQuaternion& oQ) const
{
  oQ.ImportMatrix(_matrix);
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDSTransformation::GetPositionAndOrientation(cds::span<double, 3> iPosition, cds::span<double, 4> iOrientation) const
{
  CATCDSQuaternion q;
  q.ImportMatrix(_matrix);
  q.Get(iOrientation[3], iOrientation[0], iOrientation[1], iOrientation[2]);
  _vector.Get(iPosition);
}
#endif

CATCDSInline void CATCDSTransformation::SetPosition(double iX, double iY, double iZ)
{
  _vector.Set(iX, iY, iZ);
}

CATCDSInline void CATCDSTransformation::SetPosition(CATCDS3Vector const& iVector)
{
  _vector = iVector;
}

CATCDSInline void CATCDSTransformation::SetPosition(CATCDS3Point const &iPoint)
{
  _vector.Set(iPoint[0], iPoint[1], iPoint[2]);
}

CATCDSInline void CATCDSTransformation::SetOrientation(CATCDS3x3Matrix const& iMatrix)
{
  _matrix = iMatrix;
}

CATCDSInline void CATCDSTransformation::SetOrientation(CATCDSQuaternion const& iQ)
{
  iQ.ExportMatrix(_matrix);
}

CATCDSInline void CATCDSTransformation::Set(const CATCDS3Vector& iPos, const CATCDS3x3Matrix& iOrientation)
{
  _vector = iPos;
  _matrix = iOrientation;
}

CATCDSInline void CATCDSTransformation::Set(const CATCDS3Vector& iPos, const CATCDSQuaternion& iOrientation)
{
  _vector = iPos;
  iOrientation.ExportMatrix(_matrix);
}

CATCDSInline void CATCDSTransformation::GetOrientationBasis(CATCDS3Vector& oAxisX, CATCDS3Vector& oAxisY, CATCDS3Vector& oAxisZ) const
{
  _matrix.GetColumn(0, oAxisX);
  _matrix.GetColumn(1, oAxisY);
  _matrix.GetColumn(2, oAxisZ);
}

CATCDSInline void CATCDSTransformation::Translate(double iX, double iY, double iZ)
{
  Translate(CATCDS3Vector(iX, iY, iZ));
}

CATCDSInline void CATCDSTransformation::Translate(const CATCDS3Vector& iPosition)
{
  _vector += iPosition;
}

CATCDSInline void CATCDSTransformation::Rotate(const CATCDSQuaternion& iOrientation)
{
  CATCDS3x3Matrix M;
  iOrientation.ExportMatrix(M);
  _matrix = M * _matrix;
}

CATCDSInline void CATCDSTransformation::Invert()
{
  CATCDSTransformation inv;
  Inverse(inv);
  *this = inv;
}

CATCDSInline CATCDSTransformation CATCDSTransformation::GetInverse() const
{
  CATCDSTransformation inv;
  Inverse(inv);
  return inv;
}

CATCDSInline void CATCDSTransformation::ChildToParent(CATCDSTransformation& ioPlacement) const
{
  ioPlacement._vector = _vector + _matrix * (ioPlacement._vector);
  //just for perfo ioPlacement._matrix = _matrix*ioPlacement._matrix;
  ioPlacement._matrix.MultFromLeftBy(_matrix);
}

CATCDSInline void CATCDSTransformation::ChildToParentOrientation(CATCDSTransformation& ioPlacement) const
{
  //just for perfo ioPlacement._matrix = _matrix*ioPlacement._matrix;
  ioPlacement._matrix.MultFromLeftBy(_matrix);
}

CATCDSInline void CATCDSTransformation::ParentToChild(CATCDSTransformation& ioPlacement) const
{
  ioPlacement._matrix = _matrix.MultTranspose(ioPlacement._matrix);
  ioPlacement._vector = _matrix.MultTranspose(ioPlacement._vector - _vector);
}

CATCDSInline void CATCDSTransformation::ParentToChild(CATCDS3Vector& ioPoint) const
{
  ioPoint -= _vector;
  ioPoint = _matrix.MultTranspose(ioPoint);
}

CATCDSInline void CATCDSTransformation::ParentToChild(CATCDS3Point& ioPoint) const
{
  ioPoint -= _vector;
  ioPoint = _matrix.MultTranspose(ioPoint);
}

CATCDSInline void CATCDSTransformation::ChildToParent(CATCDS3Vector& ioPoint) const
{
  ioPoint = _matrix * ioPoint;
  ioPoint += _vector;
}

CATCDSInline void CATCDSTransformation::ChildToParent(CATCDS3Point& ioPoint) const
{
  ioPoint = *this * ioPoint;
}

CATCDSInline void CATCDSTransformation::ParentToChildVector(CATCDS3Vector& ioVector) const
{
  ioVector = _matrix.MultTranspose(ioVector);
}

CATCDSInline void CATCDSTransformation::ChildToParentVector(CATCDS3Vector& ioVector) const
{
  ioVector = _matrix * ioVector;
}

CATCDSInline void CATCDSTransformation::ParentToChild(CATCDSQuaternion& ioQuaternion) const
{
  CATCDS3Vector axe(ioQuaternion.GetX(), ioQuaternion.GetY(), ioQuaternion.GetZ());
  axe = _matrix.MultTranspose(axe);
  ioQuaternion.Set(ioQuaternion.GetW(), axe.GetX(), axe.GetY(), axe.GetZ());
}

CATCDSInline void CATCDSTransformation::ChildToParent(CATCDSQuaternion& ioQuaternion) const
{
  CATCDS3Vector axe(ioQuaternion.GetX(), ioQuaternion.GetY(), ioQuaternion.GetZ());
  axe = _matrix * axe;
  ioQuaternion.Set(ioQuaternion.GetW(), axe.GetX(), axe.GetY(), axe.GetZ());
}

CATCDSInline void CATCDSTransformation::ChildToParentMatrix(CATCDS3x3Matrix& ioMatrix) const
{
  ioMatrix = _matrix * ioMatrix;
}
CATCDSInline void CATCDSTransformation::ParentToChildMatrix(CATCDS3x3Matrix& ioMatrix) const
{
  ioMatrix = _matrix.MultTranspose(ioMatrix);
}

CATCDSInline void CATCDSTransformation::ChildToParent(CATCDS3x3Matrix& ioMatrix) const
{
  return ChildToParentMatrix(ioMatrix);
}

CATCDSInline void CATCDSTransformation::ParentToChild(CATCDS3x3Matrix& ioMatrix) const
{
  return ParentToChildMatrix(ioMatrix);
}

CATCDSInline CATCDSTransformation CATCDSTransformation::MultTranspose(CATCDSTransformation const &iT) const
{
  CATCDSTransformation res(iT);
  ParentToChild(res);
  return res;
}

#endif
