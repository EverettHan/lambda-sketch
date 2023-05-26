// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATCDS3x3Matrix:
//
//=============================================================================
//
// Usage notes:
//
//=============================================================================
//  Jan 2003  Creation                         Ilia Ivanov
//=============================================================================

#ifndef CATCDS3x3Matrix_H
#define CATCDS3x3Matrix_H

#include "CDSMathematics.h"

#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"
#include "CATCDSAssert.h"
#include "CATCDSDebug.h"
#include "CATCDSInline.h"
#include "CATCDSCPlusPlusVersions.h"

class CATCDSStream;

/*
 Euler convention used for the 3 rotation angles
*/
enum CATCDSEulerConvention
{
  ecZXY,
  ecZYX,
  ecZXZ
};

/**
 * Class representing a matrix in dimension 3.
 *<br><tt><table width = 40>
 *    <tr><td> Matrix= </td><td> A11 </td><td> A12 </td><td> A13 </td>
 *        </tr>
 *    <tr><td>         </td><td> A21 </td><td> A22 </td><td> A23 </td>
 *        </tr>
 *    <tr><td>         </td><td> A31 </td><td> A32 </td><td> A33 </td>
 *        </tr>
 *        </table></tt>
 */
class ExportedByCDSMathematics CATCDS3x3Matrix
{

public:
#ifdef CPP11_AVAILABLE
  CATCDS3x3Matrix(CATCDS3x3Matrix const &) = default;
  CATCDS3x3Matrix& operator=(CATCDS3x3Matrix const &) = default;
  ~CATCDS3x3Matrix() = default;
  CATCDS3x3Matrix(cds::span<double const, 3, 3> iMatrix);
#endif
  //=============================================================================
  // Constructors
  //============================================================================
  /**
 * Constructs the Identity CATCDS3x3Matrix.
 * @return
 *    <tt><table width = 40>
 *    <tr><td> Matrix= </td><td> 1 </td><td> 0 </td><td> 0 </td>
 *        </tr>
 *    <tr><td>         </td><td> 0 </td><td> 1 </td><td> 0 </td>
 *        </tr>
 *    <tr><td>         </td><td> 0 </td><td> 0 </td><td> 1 </td>
 *        </tr>
 *        </table></tt>
 */
  CATCDS3x3Matrix();

  /**
 * Constructs the iA*Identity CATCDS3x3Matrix.
 * @return
 *    <tt><table width = 40>
 *    <tr><td> Matrix= </td><td> iA </td><td> 0 </td><td> 0 </td>
 *        </tr>
 *    <tr><td>         </td><td> 0  </td><td>iA </td><td> 0 </td>
 *        </tr>
 *    <tr><td>         </td><td> 0  </td><td> 0 </td><td> iA </td>
 *        </tr>
 *        </table></tt>
 */
  CATCDS3x3Matrix(double iA);

  /**
 * Constructs a CATCDS3x3Matrix from its coefficients.
 * @return
 *    <tt><table width = 40>
 *    <tr><td> Matrix= </td><td> iA11  </td><td>iA12 </td><td> iA13 </td>
 *        </tr>
 *    <tr><td>         </td><td> iA21  </td><td>iA22 </td><td> iA23 </td>
 *        </tr>
 *    <tr><td>         </td><td> iA31  </td><td>iA32 </td><td> iA33 </td>
 *        </tr>
 *        </table></tt>
 */
  CATCDS3x3Matrix(double iA11, double iA12, double iA13, double iA21, double iA22, double iA23, double iA31, double iA32, double iA33);

  /**
 * Constructs a CATCDS3x3Matrix from its coefficients.
 */
  CATCDS3x3Matrix(const double iaA[3][3]);

  /**
   * Create cross product vector matrix
   */
  explicit CATCDS3x3Matrix(const CATCDS3Vector& iCrossProductVector);

  /**
   * Create matrix (iV1 iV2 iV3)
   */
  CATCDS3x3Matrix(CATCDS3Vector const &iV1, CATCDS3Vector const &iV2, CATCDS3Vector const &iV3);

  /*
 *  Equality test operator
 */
  bool operator==(const CATCDS3x3Matrix& iMatrix) const;
  bool operator!=(const CATCDS3x3Matrix& iM) const;

  bool operator<(const CATCDS3x3Matrix& iM) const;

  //===========================================================================
  //- Get/Set
  //===========================================================================
  /**
 * Retrieves the coefficients of <tt>this</tt> CATCDS3x3Matrix.
 * <br>
 *    <tt><table width = 40>
 *    <tr><td> Matrix= </td><td> oA11  </td><td>oA12 </td><td> oA13 </td>
 *        </tr>
 *    <tr><td>         </td><td> oA21  </td><td>oA22 </td><td> oA23 </td>
 *        </tr>
 *    <tr><td>         </td><td> oA31  </td><td>oA32 </td><td> oA33 </td>
 *        </tr>
 *        </table></tt>
 */
  void GetCoef(double& oA11, double& oA12, double& oA13, double& oA21, double& oA22, double& oA23, double& oA31, double& oA32, double& oA33) const;

  /**
 * Retrieves the coefficients of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetCoef(double oA[3][3]) const;

#ifdef CPP11_AVAILABLE
  void GetCoef(cds::span<double, 3, 3> oA) const;
#endif
  /**
 * Sets the coefficients of <tt>this</tt> CATCDS3x3Matrix.
 * <br>
 *    <tt><table width = 40>
 *    <tr><td> Matrix= </td><td> iA11  </td><td>iA12 </td><td> iA13 </td>
 *        </tr>
 *    <tr><td>         </td><td> iA21  </td><td>iA22 </td><td> iA23 </td>
 *        </tr>
 *    <tr><td>         </td><td> iA31  </td><td>iA32 </td><td> iA33 </td>
 *        </tr>
 *        </table></tt>
 */
  void SetCoef(double iA11, double iA12, double iA13, double iA21, double iA22, double iA23, double iA31, double iA32, double iA33);

  /**
 * Sets the coefficients of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetCoef(const double iaA[3][3]);

  /**
 * Retrieves the first column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetFirstColumn(CATCDS3Vector& oColumn) const;

  /**
 * Modifies the first column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetFirstColumn(const CATCDS3Vector& iColumn);

  /**
 * Retrieves the second column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetSecondColumn(CATCDS3Vector& oColumn) const;

  /**
 * Modifies the second column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetSecondColumn(const CATCDS3Vector& iColumn);

  /**
 * Retrieves the third column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetThirdColumn(CATCDS3Vector& oColumn) const;

  /**
 * Modifies the third column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetThirdColumn(const CATCDS3Vector& iColumn);

  /**
 * Retrieves the first column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetFirstLine(CATCDS3Vector& oLine) const;

  /**
 * Modifies the first column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetFirstLine(const CATCDS3Vector& iLine);

  /**
 * Retrieves the second column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetSecondLine(CATCDS3Vector& oLine) const;

  /**
 * Modifies the second column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetSecondLine(const CATCDS3Vector& iLine);

  /**
 * Retrieves the third column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void GetThirdLine(CATCDS3Vector& oLine) const;

  /**
 * Modifies the third column of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetThirdLine(const CATCDS3Vector& iLine);

  /**
 * Modifies the columns of <tt>this</tt> CATCDS3x3Matrix.
 */
  void SetMatrix(const CATCDS3Vector& iColumn1,
    const CATCDS3Vector& iColumn2,
    const CATCDS3Vector& iColumn3);

  /**
 * Round the coefficients that are close to 1 or 0.
 */
  void Round();

  /**
 * Set the coefficients of the matrix such that they define a rotation
 * around main axes on given angles.
 * @param iAngleOX rotation angle around OX axis
 * @param iAngleOY rotation angle around OY axis
 * @param iAngleOZ rotation angle around OZ axis
 */
  void SetRotation(double iAngleOX, double iAngleOY, double iAngleOZ);

  /**
 * Set the coefficients of the matrix such that they define a rotation
 * on angle iAngle around an axis passed through the origin
 * with direction iVector.
 * The vector iVector is supposed to be normalized.
 * @param iVector rotation axis vector
 * @param iAngle rotation angle
 */
  void SetRotation(const CATCDS3Vector& iVector, double iAngle);

  /**
 * Set the coefficients of the matrix such that they define a shortest rotation
 * from iOldVector to iNewVector.
 * @param iOldVector initial position
 * @param iNewVector final position
 */
  void SetRotation(const CATCDS3Vector& iOldVector, const CATCDS3Vector& iNewVector);

  /**
 * Set the coefficients of the matrix such that they define a shortest rotation
 * from iOldVector to iNewVector.
 * @param iOldVector initial position
 * @param iNewVector final position
 * @param iAxis      unitary vector which defined the axis of the rotation (should be colinear to iOldVector^iNewVector)
 */
  void SetRotation(const CATCDS3Vector& iOldVector, const CATCDS3Vector& iNewVector, const CATCDS3Vector& iAxis);

  /**
 * Set the coefficients of the matrix such that they define a rotation
 * from the coordinate frame defined by (iU1, iV1)
 * to the one defined by (iU2, iV2).
 * Vectors are supposed to be normalized (if not, the result of this function
 * is unpredictable.)
 * @param iU1 first coordinate vector for the old frame
 * @param iV1 second coordinate vector for the old frame
 * @param iU2 first coordinate vector for the new frame
 * @param iV2 second coordinate vector for the new frame
 */
  void SetRotation(const CATCDS3Vector& iU1,
    const CATCDS3Vector& iV1,
    const CATCDS3Vector& iU2,
    const CATCDS3Vector& iV2);

  /**
  * Returns unnormalized quaternion (with norm >= 1),
  * assuming the matrix is special orthogonal.
  * @param oRe quaternion real part (non-negative)
  * @param oIm quaternion imaginary part
  */
  void GetQuaternion(double& oRe, CATCDS3Vector& oIm) const;

  /**
   * DEPRECATED
   * Get Euler angles for this rotation (ZXY extrinsic convention).
   * @param oAngle1 rotation angle around z
   * @param oAngle2 rotation angle around x
   * @param oAngle3 rotation angle around y
   */
  void GetEulerAngles(double& oAngle1, double& oAngle2, double& oAngle3) const;

  /**
   * Get Euler angles for this rotation using the input convention (extrinsic).
   * @param iConvention Euler convention to use
   * @param oAngle1 first rotation angle
   * @param oAngle2 second rotation angle
   * @param oAngle3 third rotation angle
   */
  void GetEulerAngles(CATCDSEulerConvention iConvention, double& oAngle1, double& oAngle2, double& oAngle3) const;

  //===========================================================================
  //- Methods
  //===========================================================================
  /**
 * Returns the determinant of <tt>this</tt> CATCDS3x3Matrix.
 */
  double Determinant() const;
  double Det() const;

  /**
 * Transposes <tt>this</tt> CATCDS3x3Matrix.
 */
  void Transpose(CATCDS3x3Matrix& oTransposed) const;

  CATCDS3x3Matrix Transpose() const;

  /**
 * Inverses <tt>this</tt> CATCDS3x3Matrix.
 *@return
 * <tt>TRUE</tt> if <tt>this</tt> CATCDS3x3Matrix is invertible, <tt>FALSE</tt> otherwise.
 * In this last case, <tt>oInverse</tt> is not modified.
 */
  CATCDSBoolean Inverse(CATCDS3x3Matrix& oInverse) const;

  void Orthonormalize();

  double const& operator()(int iRow, int iCol) const;
  double& operator()(int iRow, int iCol);

  double NormInf() const;

  void EigenVectors(               
    int& nbeigenvalues,
    double         eigenvalues[],
    CATCDSBoolean     []  ,
    CATCDS3Vector  eigenvectors[]) const ;

  /**
   *  Write matrix.
   */
  void Write(const char* iName) const;

  //===========================================================================
  //- Overloaded Operators
  //===========================================================================
  /**
 * Defines the addition of two CATCDS3x3Matrix.
 * @return
 * The CATCDS3x3Matrix whose coefficients are the sum of the coefficients
 * of two CATCDS3x3Matrix.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator+(const CATCDS3x3Matrix& iMatrix1, const CATCDS3x3Matrix& iMatrix2);

  /**
 * Defines the subtraction of two CATCDS3x3Matrix.
 * @return
 * The CATCDS3x3Matrix whose coefficients are the difference of the
 *  coefficients of two CATCDS3x3Matrix.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator-(const CATCDS3x3Matrix& iMatrix1, const CATCDS3x3Matrix& iMatrix2);

  /**
  * Defines the opposite of a CATCDS3x3Matrix.
  * @return
  * The CATCDS3x3Matrix whose coefficients are the opposite of the coefficients of a CATCDS3x3Matrix.
  */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator-(const CATCDS3x3Matrix& iMatrix);

  /**
 * Defines the left side scalar multiplication.
 * @return
 * The CATCDS3x3Matrix whose coefficients are the multiplication of the
 * coefficients of a CATCDS3x3Matrix by a scalar.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator*(double iScalar, const CATCDS3x3Matrix& iMatrix);

  /**
 * Defines the right side scalar multiplication.
 * @return
 * The CATCDS3x3Matrix whose coefficients are the multiplication of the
 * coefficients of a CATCDS3x3Matrix by a scalar.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator*(const CATCDS3x3Matrix& iMatrix, double iScalar);

  /**
 * Defines the scalar division.
 * @return
 * The CATCDS3x3Matrix whose coefficients are the division of the
 * coefficients of a CATCDS3x3Matrix by a scalar.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator/(const CATCDS3x3Matrix& iMatrix, double iScalar);

  /**
 * Defines the product of two CATCDS3x3Matrix.
 */
  friend ExportedByCDSMathematics CATCDS3x3Matrix operator*(const CATCDS3x3Matrix& iMatrix1, const CATCDS3x3Matrix& iMatrix2);
  
  CATCDS3x3Matrix& operator*=(const CATCDS3x3Matrix& iMatrix);

  /**
 * Defines the product of a CATCDS3x3Matrix by a CATCDS3Vector.
 */
  friend ExportedByCDSMathematics CATCDS3Vector operator*(const CATCDS3x3Matrix& iMatrix, const CATCDS3Vector& iVector);

  /**
 * Defines the product of a CATCDS3x3Matrix by a CATCDS3Point.
 */
  friend ExportedByCDSMathematics CATCDS3Point operator*(const CATCDS3x3Matrix& iMatrix, const CATCDS3Point& iPoint);

  // Multiplies matrix on matrix as it was transpose
  // Economizes matrix creation
  const CATCDS3Point MultTranspose(const CATCDS3Point& iP) const;
  const CATCDS3Vector MultTranspose(const CATCDS3Vector& iV) const;
  const CATCDS3x3Matrix MultTranspose(const CATCDS3x3Matrix& iM) const;

  void MultFromLeftBy(const CATCDS3x3Matrix& iM);

  //
  // return a vector with the absolute value of the coordinate of the matrix vector product
  //
  const CATCDS3Vector AbsMult(const CATCDS3Vector& iV) const;
  void AbsMult(const CATCDS3Vector& iV, CATCDS3Vector& oV) const;

  // Sum and difference
  CATCDS3x3Matrix& operator+=(const CATCDS3x3Matrix& iM);
  CATCDS3x3Matrix& operator-=(const CATCDS3x3Matrix& iM);

  // Transposition and inverse
  CATCDS3x3Matrix GetTranspose() const;
  void GetTranspose(CATCDS3x3Matrix& oMat) const;

  CATCDS3x3Matrix GetInverse() const;
  void GetInverse(CATCDS3x3Matrix& oMat) const;

  // Elements
  void Set(const double iA[3][3]);
  void Set(const double iM9[9]);
#ifdef CPP11_AVAILABLE
  void Set(cds::span<double const, 9> iM9);
#endif

  void Get(double oA[3][3]) const;

  // Lines and columns
  void SetLine(int iLineIndex, const double iLine[3]);
  void SetLine(int iLineIndex, const CATCDS3Vector& iLine);
#ifdef CPP11_AVAILABLE
  void SetLine(int iLineIndex, cds::span<double const, 3> iLine);
#endif

  void SetColumn(int iColumnIndex, const double iColumn[3]);
  void SetColumn(int iColumnIndex, const CATCDS3Vector& iColumn);
#ifdef CPP11_AVAILABLE
  void SetColumn(int iColumnIndex, cds::span<double const, 3> iColumn);
#endif

  void GetLine(int iLineIndex, double oLine[3]) const;
  void GetLine(int iLineIndex, CATCDS3Vector& oLine) const;
  CATCDS3Vector GetLine(int iLineIndex) const;

  void GetColumn(int iColumnIndex, double oColumn[3]) const;
  void GetColumn(int iColumnIndex, CATCDS3Vector& oColumn) const;
  CATCDS3Vector GetColumn(int iColumnIndex) const;
#ifdef CPP11_AVAILABLE
  void GetColumn(int iColumnIndex, cds::span<double, 3> oColumn) const;
#endif

  // Rotate
  void RotateX(double angle);
  void RotateY(double angle);
  void RotateZ(double angle);

  typedef double Buffer[3][3];

  Buffer& GetBuffer();
  Buffer const & GetBuffer() const;

  //===========================================================================
  // Private data.
  //===========================================================================
private:
  double _a[3][3];
};

#ifdef CPP11_AVAILABLE
CATCDSInline CATCDS3x3Matrix::CATCDS3x3Matrix(cds::span<double const, 3, 3> iMatrix)
  : CATCDS3x3Matrix(iMatrix(0, 0), iMatrix(0, 1), iMatrix(0, 2), iMatrix(1, 0), iMatrix(1, 1), iMatrix(1, 2), iMatrix(2, 0), iMatrix(2, 1), iMatrix(2, 2))
{
}
#endif

ExportedByCDSMathematics CATCDSStream& operator<<(CATCDSStream& ioStream, CATCDS3x3Matrix const& iMatrix);

CATCDSInline double const& CATCDS3x3Matrix::operator()(int iRow, int iCol) const
{
  return _a[iRow][iCol];
}

CATCDSInline double& CATCDS3x3Matrix::operator()(int iRow, int iCol)
{
  return _a[iRow][iCol];
}

CATCDSInline double CATCDS3x3Matrix::Det() const
{
  return Determinant();
}

CATCDSInline CATCDS3x3Matrix CATCDS3x3Matrix::GetTranspose() const
{
  CATCDS3x3Matrix res;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      res._a[i][j] = _a[j][i];
    }
  }
  return res;
}

CATCDSInline void CATCDS3x3Matrix::GetTranspose(CATCDS3x3Matrix& oMat) const
{
  oMat = GetTranspose();
}

CATCDSInline CATCDS3x3Matrix CATCDS3x3Matrix::GetInverse() const
{
  return GetTranspose();
}

CATCDSInline void CATCDS3x3Matrix::GetInverse(CATCDS3x3Matrix& oMat) const
{
  GetTranspose(oMat);
}

CATCDSInline void CATCDS3x3Matrix::Set(const double iA[3][3])
{
  _a[0][0] = iA[0][0];
  _a[0][1] = iA[0][1];
  _a[0][2] = iA[0][2];

  _a[1][0] = iA[1][0];
  _a[1][1] = iA[1][1];
  _a[1][2] = iA[1][2];

  _a[2][0] = iA[2][0];
  _a[2][1] = iA[2][1];
  _a[2][2] = iA[2][2];
}

CATCDSInline void CATCDS3x3Matrix::Get(double oA[3][3]) const
{
  oA[0][0] = _a[0][0];
  oA[0][1] = _a[0][1];
  oA[0][2] = _a[0][2];

  oA[1][0] = _a[1][0];
  oA[1][1] = _a[1][1];
  oA[1][2] = _a[1][2];

  oA[2][0] = _a[2][0];
  oA[2][1] = _a[2][1];
  oA[2][2] = _a[2][2];
}

CATCDSInline void CATCDS3x3Matrix::Set(const double iM9[9])
{
  operator()(0, 0) = iM9[0];
  operator()(0, 1) = iM9[1];
  operator()(0, 2) = iM9[2];
  operator()(1, 0) = iM9[3];
  operator()(1, 1) = iM9[4];
  operator()(1, 2) = iM9[5];
  operator()(2, 0) = iM9[6];
  operator()(2, 1) = iM9[7];
  operator()(2, 2) = iM9[8];
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3x3Matrix::Set(cds::span<double const, 9> iM)
{
  Set(iM.data());
}
#endif

CATCDSInline void CATCDS3x3Matrix::SetLine(int iLineIndex, const double iLine[3])
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  _a[iLineIndex][0] = iLine[0];
  _a[iLineIndex][1] = iLine[1];
  _a[iLineIndex][2] = iLine[2];
}

CATCDSInline void CATCDS3x3Matrix::SetLine(int iLineIndex, const CATCDS3Vector& iLine)
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  _a[iLineIndex][0] = iLine[0];
  _a[iLineIndex][1] = iLine[1];
  _a[iLineIndex][2] = iLine[2];
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3x3Matrix::SetLine(int iLineIndex, cds::span<double const, 3> iLine)
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  _a[iLineIndex][0] = iLine[0];
  _a[iLineIndex][1] = iLine[1];
  _a[iLineIndex][2] = iLine[2];
}
#endif

CATCDSInline void CATCDS3x3Matrix::SetColumn(int iColumnIndex, const double iColumn[3])
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  _a[0][iColumnIndex] = iColumn[0];
  _a[1][iColumnIndex] = iColumn[1];
  _a[2][iColumnIndex] = iColumn[2];
}

CATCDSInline void CATCDS3x3Matrix::SetColumn(int iColumnIndex, const CATCDS3Vector& iColumn)
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  _a[0][iColumnIndex] = iColumn[0];
  _a[1][iColumnIndex] = iColumn[1];
  _a[2][iColumnIndex] = iColumn[2];
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3x3Matrix::SetColumn(int iColumnIndex, cds::span<double const, 3> iColumn)
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  _a[0][iColumnIndex] = iColumn[0];
  _a[1][iColumnIndex] = iColumn[1];
  _a[2][iColumnIndex] = iColumn[2];
}
#endif

CATCDSInline void CATCDS3x3Matrix::GetLine(int iLineIndex, double oLine[3]) const
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  oLine[0] = _a[iLineIndex][0];
  oLine[1] = _a[iLineIndex][1];
  oLine[2] = _a[iLineIndex][2];
}

CATCDSInline void CATCDS3x3Matrix::GetLine(int iLineIndex, CATCDS3Vector& oLine) const
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  oLine[0] = _a[iLineIndex][0];
  oLine[1] = _a[iLineIndex][1];
  oLine[2] = _a[iLineIndex][2];
}

CATCDSInline CATCDS3Vector CATCDS3x3Matrix::GetLine(int iLineIndex) const
{
  CATCDSAssert(iLineIndex >= 0 && iLineIndex < 3);
  CATCDS3Vector res;
  GetLine(iLineIndex, res);
  return res;
}

CATCDSInline void CATCDS3x3Matrix::GetColumn(int iColumnIndex, double oColumn[3]) const
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  oColumn[0] = _a[0][iColumnIndex];
  oColumn[1] = _a[1][iColumnIndex];
  oColumn[2] = _a[2][iColumnIndex];
}

CATCDSInline void CATCDS3x3Matrix::GetColumn(int iColumnIndex, CATCDS3Vector& oColumn) const
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  oColumn[0] = _a[0][iColumnIndex];
  oColumn[1] = _a[1][iColumnIndex];
  oColumn[2] = _a[2][iColumnIndex];
}

CATCDSInline CATCDS3Vector CATCDS3x3Matrix::GetColumn(int iColumnIndex) const
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  return CATCDS3Vector(_a[0][iColumnIndex], _a[1][iColumnIndex], _a[2][iColumnIndex]);
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3x3Matrix::GetColumn(int iColumnIndex, cds::span<double, 3> oColumn) const
{
  CATCDSAssert(iColumnIndex >= 0 && iColumnIndex < 3);
  oColumn[0] = _a[0][iColumnIndex];
  oColumn[1] = _a[1][iColumnIndex];
  oColumn[2] = _a[2][iColumnIndex];
}
#endif

CATCDSInline CATCDS3x3Matrix operator+(const double iFactor, const CATCDS3x3Matrix& iM)
{
  CATCDS3x3Matrix MP;
  int l;
  for (l = 0; l < 3; l++)
  {
    int c;
    for (c = 0; c < 3; c++)
    {
      MP(l, c) = iFactor + iM(l, c);
    }
  }
  return MP;
}

CATCDSInline CATCDS3x3Matrix operator+(const CATCDS3x3Matrix& iM, const double iFactor)
{
  CATCDS3x3Matrix MP = iFactor + iM;
  return MP;
}

CATCDSInline CATCDS3x3Matrix CATCDS3x3Matrix::Transpose() const
{
  CATCDS3x3Matrix res;
  Transpose(res);
  return res;
}

CATCDSInline CATCDS3x3Matrix::Buffer& CATCDS3x3Matrix::GetBuffer()
{
  return _a;
}

CATCDSInline CATCDS3x3Matrix::Buffer const & CATCDS3x3Matrix::GetBuffer() const
{
  return _a;
}

#endif
