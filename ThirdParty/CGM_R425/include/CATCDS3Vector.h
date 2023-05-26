#ifndef CATCDS3Vector_H
#define CATCDS3Vector_H

// COPYRIGHT DASSAULT SYSTEMES 2003

#include "CATCDSBoolean.h"
#include "CATCDSConstants.h"
#include "CDSMathematics.h"
#include "CATCDSCPlusPlusVersions.h"
#include "CATCDSAssert.h"

#ifdef CPP11_AVAILABLE
#include "CATCDSSpan.h"
#endif

#include <cstring>

class CATCDS3Point;
class CATCDSStream;

/**
 * Class representing a mathematical vector in dimension 3.
 */
class ExportedByCDSMathematics CATCDS3Vector
{
public:
#ifdef CPP11_AVAILABLE
  CATCDS3Vector() = default;
  CATCDS3Vector(CATCDS3Vector const &) = default;
  CATCDS3Vector& operator=(CATCDS3Vector const &) = default;
  ~CATCDS3Vector() = default;
  
  CATCDS3Vector(cds::span<double const, 3> iCoord);
#else
  //=============================================================================
  //- Constructors
  //============================================================================
  /**
   * Constructs a (0,0,0) vector.
   */
  CATCDS3Vector();
#endif


  /**
   * Constructs a CATCDS3Vector from three coordinates.
   */
  CATCDS3Vector(double iX, double iY, double iZ);

  /**
   * Constructs a CATCDS3Vector from an array of three coordinates.
   */
  CATCDS3Vector(const double iCoord[]);

  /**
   * Create e  unit vector
   *         i
   */
  explicit CATCDS3Vector(int iIdx);

  //============================================================================
  //- Get/Set
  //============================================================================
  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Vector.
   */
  void Get(double& oX, double& oY, double& oZ) const;
  void GetCoord(double& oX, double& oY, double& oZ) const;
  void GetCoord2D(double& oX, double& oY) const;

  /**
   * Modifies the coordinates of <tt>this</tt> CATCDS3Vector from 3 doubles.
   */
  void Set(double iX, double iY, double iZ);
  void SetCoord(double iX, double iY, double iZ);

  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Vector in an array.
   */
  void Get(double iCoord[]) const;
  void GetCoord(double iCoord[]) const;
#ifdef CPP11_AVAILABLE
  void Get(cds::span<double, 3> oCoord) const;
  void GetCoord(cds::span<double, 3> oCoord) const;
#endif

  /**
   * Modifies the coordinates of <tt>this</tt> CATCDS3Vector from an array of 3 doubles.
   */
  void Set(CATCDS3Vector const& iVector);
  void Set(const double iCoord[]);
  void SetCoord(const double iCoord[]);
  void SetCoord2D(const double iCoord[]);
#ifdef CPP11_AVAILABLE
  void Set(cds::span<double const, 3> iCoord);
#endif

  /**
   * Returns the iIdx coordinate of <tt>this</tt> CATCDS3Vector.
   */
  double GetCoord(int iIdx) const;

  /**
   * Modifies the iIdx coordinate of <tt>this</tt> CATCDS3Vector.
   */
  void SetCoord(unsigned int iIdx, double iValue);

  /**
   * Accessors for vector
   */
  double const& operator[](int iIdx) const;
  double& operator[](int iIdx);

  /**
   * Returns the X coordinate of <tt>this</tt> CATCDS3Vector.
   */
  double GetX() const;

  /**
   * Modifies the X coordinate of <tt>this</tt> CATCDS3Vector.
   */
  void SetX(double iX);

  /**
   * Returns the Y coordinate of <tt>this</tt> CATCDS3Vector.
   */
  double GetY() const;

  /**
   * Modifies the Y coordinate of <tt>this</tt> CATCDS3Vector.
   */
  void SetY(double iY);

  /**
   * Returns the Z coordinate of <tt>this</tt> CATCDS3Vector.
   */
  double GetZ() const;

  /**
   * Modifies the Z coordinate of <tt>this</tt> CATCDS3Vector.
   */
  void SetZ(double iZ);

  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Vector as array of 3 doubles.
   */
  double(&GetCoord())[3];
  double const (&GetCoord() const)[3];

  double (&GetPointer(unsigned short int i))[3];
  double const (&GetPointer(unsigned short int i) const)[3];

  //============================================================================
  //- Norm
  //============================================================================

  /**
   * Returns the square of the euclidean norm of <tt>this</tt> CATCDS3Vector.
   */
  double SquareNorm() const;
  double GetNormSquare() const;

  /**
  * Returns the norm one of <tt>this</tt> CATCDS3Vector.
  */
  double Norm1() const;
  double GetNorm1() const;

  /**
   * Returns the euclidean norm of <tt>this</tt> CATCDS3Vector.
   */
  double Norm() const;
  double GetNorm() const;

  /**
   * Returns the infinite norm of <tt>this</tt> CATCDS3Vector.
   */
  double NormInf() const;
  double GetInfiniteNorm() const;

  /**
   * Normalizes <tt>this</tt> CATCDS3Vector.
   * </br>Simply returns if <tt>this</tt> is null.
   */
  double Normalize(double iTolerance = CATCDSEpsilon);

  /**
   * Round the coefficients that are close to 0.
   */
  void Round();

  CATCDS3Vector GetOrthogonalVector() const;

  void GetOrthogonalVectors(CATCDS3Vector oaVectors[2]) const;

  CATCDS3Vector GetOrthogonalVector(const CATCDS3Vector& iCoplanarVector, double iZeroNorm) const;

  //============================================================================
  //- Angle To
  //============================================================================

  /**
   * Returns the angle (between 0 and CATCDSPI radians) with another CATCDS3Vector.
   * <br> Returns <tt>0</tt> if the vector is null.
   */
  double AngleTo(const CATCDS3Vector& iVector) const;

  /**
   * Returns the signed angle (between -CATCDSPI and CATCDSPI radians), with another CATCDS3Vector,
   *  oriented by a reference vector.
   * <br> Returns <tt>0</tt> if the vector is null.
   */
  double AngleTo(const CATCDS3Vector& iOtherVector, const CATCDS3Vector& iRefVector) const;

  /**
   * Returns TRUE if the vector is collinear to another with given tolerance (in radians).
   */
  CATCDSBoolean IsCollinear(const CATCDS3Vector& iVector, double iAngularTolerance) const;

  /**
   *  Write vector.
   */
  void Write(const char* iName) const;

  //============================================================================
  //- Overloaded Operators
  //============================================================================
  /**
   * Defines the addition of two CATCDS3Vectors.
   * @param iVector1
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iVector2
   * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
   * @return
   * The CATCDS3Vector of <tt>(u1+v1,u2+v2,u3+v3</tt>) coordinates.
   */
  friend CATCDS3Vector operator+(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2);

  /**
   * Translates a CATCDS3Point by a CATCDS3Vector.
   * @param iPoint
   * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Point of <tt>(p1+u1,p2+u2,p3+u3)</tt> coordinates.
   */
  friend CATCDS3Point operator+(const CATCDS3Point& iPoint, const CATCDS3Vector& iVector);

  /**
   * Builds a CATCDS3Vector as the difference of two CATCDS3Points.
   * <br> Note that the iPoint1iPoint2 vector is given by iPoint2-iPoint1.
   * @param iPoint1
   * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
   * @param iPoint2
   * The CATCDS3Point of <tt>(q1,q2,q3)</tt> coordinates.
   * @return
   * The CATCDS3Vector of <tt>(p1-q1,p2-q2,p3-q3)</tt> coordinates.
   */
  friend CATCDS3Vector operator-(const CATCDS3Point& iPoint1, const CATCDS3Point& iPoint2);

  /**
   * Defines the subtraction of two CATCDS3Vectors.
   * @param iVector1
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iVector2
   * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
   * @return
   * The CATCDS3Vector of <tt>(u1-v1,u2-v2,u3-v3</tt>) coordinates.
   */
  friend CATCDS3Vector operator-(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2);

  /**
   * Defines the opposite of a CATCDS3Vector.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Vector of <tt>(-u1,-u2,-u3)</tt> coordinates.
   */
  friend CATCDS3Vector operator-(const CATCDS3Vector& iVector);

  /**
   * Defines the left scalar multiplication.
   * @param iScalar
   * The scalar.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Vector of <tt>(iScalar*u1,iScalar*u2,iScalar*u3)</tt>
   *  coordinates.
   */
  friend CATCDS3Vector operator*(double iScalar, const CATCDS3Vector& iVector);

  /**
   * Defines the right scalar multiplication.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iScalar
   * The scalar.
   * @return
   * The CATCDS3Vector of <tt>(u1*iScalar,u2*iScalar,u3*iScalar)</tt>
   *  coordinates.
   */
  friend CATCDS3Vector operator*(const CATCDS3Vector& iVector, double iScalar);

  /**
   * Defines the scalar division.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iScalar
   * The (not null) scalar.
   * @return
   * The CATCDS3Vector of <tt>(u1/iScalar,u2/iScalar,u3/iScalar)</tt>
   *  coordinates.
   */
  friend CATCDS3Vector operator/(const CATCDS3Vector& iVector, double iScalar);

  /**
   * Defines the dot product of two CATCDS3Vectors.
   * @param iVector1
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iVector2
   * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
   * @return
   * <tt>u1*v1 + u2*v2 + u3*v3</tt>.
   */
  friend double operator*(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2);

  /**
   * Defines the cross product of two CATCDS3Vectors.
   * @param iVector1
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @param iVector2
   * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
   * @return
   * The CATCDS3Vector (u2*iv3-u3*v2, u3*iv1-u1*v3, u1*v2-u2*v1).
   */
  friend CATCDS3Vector operator^(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2);

  /**
  * Defines the addition of two CATCDS3Vectors.
  * @param iVector1
  * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
  * @param iVector2
  * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
  */
  CATCDS3Vector& operator+=(const CATCDS3Vector& iVector);

  /**
  * Defines the subtraction of two CATCDS3Vectors.
  * @param iVector1
  * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
  * @param iVector2
  * The CATCDS3Vector of <tt>(v1,v2,v3)</tt> coordinates.
  */
  CATCDS3Vector& operator-=(const CATCDS3Vector& iVector);

  /**
  * Modifies a CATCDS3Point by using the right scalar multiplication.
  * @param iVector
  * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
  * @param iScalar
  * The scalar.
  * @return
  * The CATCDS3Vector of <tt>(u1=u1*iScalar,u2=u2*iScalar,u3=u3*iScalar)</tt>
  *  coordinates.
  */
  CATCDS3Vector& operator*=(double iScalar);

  /**
  * Modifies a CATCDS3Point by using the scalar division.
  * @param iVector
  * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
  * @param iScalar
  * The (not null) scalar.
  * @return
  * The CATCDS3Vector of <tt>(u1=u1/iScalar,u2=u2/iScalar,u3=u3/iScalar)</tt>
  *  coordinates.
  */
  CATCDS3Vector& operator/=(double iScalar);

  double DotProduct(CATCDS3Vector const& iV) const;
  CATCDS3Vector OuterProduct(CATCDS3Vector const& iV) const;

  bool operator==(CATCDS3Vector const& iV) const;
  bool operator!=(CATCDS3Vector const& iV) const;
  bool operator<(CATCDS3Vector const& iV) const;

  /**
   * Add vector to origin
   */
  CATCDS3Point AddToOrigin();

  void Add(double iX, double iY, double iZ);
  void Add(const CATCDS3Vector& iV);

  void NormalizeRobustly();

  double DistanceToLine(const CATCDS3Vector& iOrigin, const CATCDS3Vector& iDirection) const;
  CATCDS3Vector ProjectOnPlane(const CATCDS3Vector& iOrigin, const CATCDS3Vector& iNormal) const;
  double DistanceTo(const CATCDS3Vector& iV) const;

  static void CopyArray(const CATCDS3Vector* iSrc, CATCDS3Vector* iDst, int iCount);

protected:
#ifdef CPP11_AVAILABLE
  double _aCoord[3] = {};
#else
  double _aCoord[3];
#endif
};

ExportedByCDSMathematics CATCDSStream& operator<<(CATCDSStream& ioStream, CATCDS3Vector const& iVector);

#include "CATCDS3Point.h"

//======================================================================
// INLINE IMPLEMENTATIONS
//======================================================================

#ifdef CPP11_AVAILABLE
CATCDSInline CATCDS3Vector::CATCDS3Vector(cds::span<double const, 3> iCoord)
  : CATCDS3Vector(iCoord.data())
{
}

#else

CATCDSInline CATCDS3Vector::CATCDS3Vector()
{
  _aCoord[0] = _aCoord[1] = _aCoord[2] = 0.0;
}
#endif

CATCDSInline CATCDS3Vector::CATCDS3Vector(double iX, double iY, double iZ)
{
  _aCoord[0] = iX;
  _aCoord[1] = iY;
  _aCoord[2] = iZ;
}

CATCDSInline CATCDS3Vector::CATCDS3Vector(const double iCoord[])
{
  if (iCoord == 0)
    _aCoord[0] = _aCoord[1] = _aCoord[2] = 0.0;
  else
  {
    _aCoord[0] = iCoord[0];
    _aCoord[1] = iCoord[1];
    _aCoord[2] = iCoord[2];
  }
}

CATCDSInline CATCDS3Vector::CATCDS3Vector(int iIdx)
{
  _aCoord[0] = _aCoord[1] = _aCoord[2] = 0.0;
  _aCoord[iIdx] = 1.0;
}

CATCDSInline void CATCDS3Vector::Get(double& oX, double& oY, double& oZ) const
{
  GetCoord(oX, oY, oZ);
}

CATCDSInline void CATCDS3Vector::GetCoord(double& oX, double& oY, double& oZ) const
{
  oX = _aCoord[0];
  oY = _aCoord[1];
  oZ = _aCoord[2];
}

CATCDSInline void CATCDS3Vector::GetCoord2D(double& oX, double& oY) const
{
  oX = _aCoord[0];
  oY = _aCoord[1];
}

CATCDSInline void CATCDS3Vector::Get(double oCoord[]) const
{
  GetCoord(oCoord);
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3Vector::Get(cds::span<double, 3> oCoord) const
{
  Get(oCoord.data());
}

CATCDSInline void CATCDS3Vector::GetCoord(cds::span<double, 3> oCoord) const
{
  GetCoord(oCoord.data());
}
#endif

CATCDSInline void CATCDS3Vector::GetCoord(double oCoord[]) const
{
  oCoord[0] = _aCoord[0];
  oCoord[1] = _aCoord[1];
  oCoord[2] = _aCoord[2];
}

CATCDSInline double CATCDS3Vector::GetCoord(int iIdx) const
{
  return _aCoord[iIdx];
}

CATCDSInline double CATCDS3Vector::GetX() const
{
  return _aCoord[0];
}
CATCDSInline double CATCDS3Vector::GetY() const
{
  return _aCoord[1];
}
CATCDSInline double CATCDS3Vector::GetZ() const
{
  return _aCoord[2];
}

CATCDSInline void CATCDS3Vector::Set(CATCDS3Vector const& iVector)
{
  SetCoord(iVector._aCoord);
}

CATCDSInline void CATCDS3Vector::Set(const double iCoord[])
{
  SetCoord(iCoord);
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3Vector::Set(cds::span<double const, 3> iCoord)
{
  Set(iCoord.data());
}
#endif

CATCDSInline void CATCDS3Vector::Set(double iX, double iY, double iZ)
{
  _aCoord[0] = iX;
  _aCoord[1] = iY;
  _aCoord[2] = iZ;
}

CATCDSInline void CATCDS3Vector::SetCoord(double iX, double iY, double iZ)
{
  _aCoord[0] = iX;
  _aCoord[1] = iY;
  _aCoord[2] = iZ;
}

CATCDSInline void CATCDS3Vector::SetCoord(const double iCoord[])
{
  _aCoord[0] = iCoord[0];
  _aCoord[1] = iCoord[1];
  _aCoord[2] = iCoord[2];
}

CATCDSInline void CATCDS3Vector::SetCoord2D(const double iCoord[])
{
  _aCoord[0] = iCoord[0];
  _aCoord[1] = iCoord[1];
  _aCoord[2] = 0.0;
}

CATCDSInline void CATCDS3Vector::SetCoord(unsigned int iIdx, double iValue)
{
  _aCoord[iIdx] = iValue;
}

CATCDSInline double const& CATCDS3Vector::operator[](int iIdx) const
{
  return _aCoord[iIdx];
}

CATCDSInline double& CATCDS3Vector::operator[](int iIdx)
{
  return _aCoord[iIdx];
}

CATCDSInline void CATCDS3Vector::SetX(double iX)
{
  _aCoord[0] = iX;
}
CATCDSInline void CATCDS3Vector::SetY(double iY)
{
  _aCoord[1] = iY;
}
CATCDSInline void CATCDS3Vector::SetZ(double iZ)
{
  _aCoord[2] = iZ;
}

CATCDSInline double (&CATCDS3Vector::GetCoord())[3]
{
  return _aCoord;
}
CATCDSInline double const (&CATCDS3Vector::GetCoord() const)[3]
{
  return _aCoord;
}

CATCDSInline double (&CATCDS3Vector::GetPointer(unsigned short int i))[3]
{
  CATCDSAssert(i == 0);
  return _aCoord;
}
CATCDSInline double const (&CATCDS3Vector::GetPointer(unsigned short int i) const)[3]
{
  CATCDSAssert(i == 0);
  return _aCoord;
}

CATCDSInline CATCDS3Vector operator+(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2)
{
  return CATCDS3Vector(iVector1[0] + iVector2[0],
    iVector1[1] + iVector2[1],
    iVector1[2] + iVector2[2]);
}

CATCDSInline CATCDS3Vector& CATCDS3Vector::operator+=(const CATCDS3Vector& iVector)
{
  _aCoord[0] += iVector[0];
  _aCoord[1] += iVector[1];
  _aCoord[2] += iVector[2];
  return *this;
}

CATCDSInline CATCDS3Point operator+(const CATCDS3Point& iPoint, const CATCDS3Vector& iVector)
{
  return CATCDS3Point(iPoint[0] + iVector[0],
    iPoint[1] + iVector[1],
    iPoint[2] + iVector[2]);
}

CATCDSInline CATCDS3Vector operator-(const CATCDS3Point& iPoint1, const CATCDS3Point& iPoint2)
{
  return CATCDS3Vector(iPoint1[0] - iPoint2[0],
    iPoint1[1] - iPoint2[1],
    iPoint1[2] - iPoint2[2]);
}

CATCDSInline CATCDS3Point operator-(const CATCDS3Point& iPoint, const CATCDS3Vector& iVector)
{
  return CATCDS3Point(iPoint[0] - iVector[0],
    iPoint[1] - iVector[1],
    iPoint[2] - iVector[2]);
}

CATCDSInline CATCDS3Vector operator-(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2)
{
  return CATCDS3Vector(iVector1[0] - iVector2[0],
    iVector1[1] - iVector2[1],
    iVector1[2] - iVector2[2]);
}

CATCDSInline CATCDS3Vector& CATCDS3Vector::operator-=(const CATCDS3Vector& iVector)
{
  _aCoord[0] -= iVector[0];
  _aCoord[1] -= iVector[1];
  _aCoord[2] -= iVector[2];
  return *this;
}

CATCDSInline CATCDS3Vector operator-(const CATCDS3Vector& iVector)
{
  return CATCDS3Vector(-iVector[0], -iVector[1], -iVector[2]);
}

CATCDSInline CATCDS3Vector operator*(double iScalar, const CATCDS3Vector& iVector)
{
  return CATCDS3Vector(iVector[0] * iScalar, iVector[1] * iScalar, iVector[2] * iScalar);
}

CATCDSInline CATCDS3Vector operator*(const CATCDS3Vector& iVector, double iScalar)
{
  return CATCDS3Vector(iVector[0] * iScalar, iVector[1] * iScalar, iVector[2] * iScalar);
}

CATCDSInline CATCDS3Vector& CATCDS3Vector::operator*=(double iScalar)
{
  _aCoord[0] *= iScalar;
  _aCoord[1] *= iScalar;
  _aCoord[2] *= iScalar;
  return *this;
}

CATCDSInline CATCDS3Vector operator/(const CATCDS3Vector& iVector, double iScalar)
{
  CATCDS3Vector res(iVector);
  return res /= iScalar;
}

CATCDSInline CATCDS3Vector& CATCDS3Vector::operator/=(double iScalar)
{
  double inv = 1 / iScalar;
  _aCoord[0] *= inv;
  _aCoord[1] *= inv;
  _aCoord[2] *= inv;
  return *this;
}

CATCDSInline double operator*(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2)
{
  return ((iVector1[0] * iVector2[0]) +
           (iVector1[1] * iVector2[1])) +
    (iVector1[2] * iVector2[2]);
}

CATCDSInline CATCDS3Vector operator^(const CATCDS3Vector& iVector1, const CATCDS3Vector& iVector2)
{
  return CATCDS3Vector((iVector1[1] * iVector2[2]) - iVector1[2] * iVector2[1],
    (iVector1[2] * iVector2[0]) - iVector1[0] * iVector2[2],
    (iVector1[0] * iVector2[1]) - iVector1[1] * iVector2[0]);
}

CATCDSInline CATCDS3Point CATCDS3Vector::AddToOrigin()
{
  return CATCDS3Point(_aCoord[0] + CATCDSOriginX, _aCoord[1] + CATCDSOriginY, _aCoord[2] + CATCDSOriginZ);
}

CATCDSInline double CATCDS3Vector::GetNormSquare() const
{
  return SquareNorm();
}

CATCDSInline double CATCDS3Vector::GetNorm1() const
{
  return Norm1();
}

CATCDSInline double CATCDS3Vector::GetNorm() const
{
  return Norm();
}

CATCDSInline double CATCDS3Vector::GetInfiniteNorm() const
{
  return NormInf();
}

CATCDSInline double CATCDS3Vector::DotProduct(CATCDS3Vector const& iV) const
{
  return (*this) * iV;
}

CATCDSInline CATCDS3Vector CATCDS3Vector::OuterProduct(CATCDS3Vector const& iV) const
{
  return (*this) ^ iV;
}

CATCDSInline bool CATCDS3Vector::operator==(const CATCDS3Vector& iV) const
{
  return _aCoord[0] == iV[0] && _aCoord[1] == iV[1] && _aCoord[2] == iV[2];
}

CATCDSInline bool CATCDS3Vector::operator!=(const CATCDS3Vector& iV) const
{
  return _aCoord[0] != iV[0] || _aCoord[1] != iV[1] || _aCoord[2] != iV[2];
}

CATCDSInline bool CATCDS3Vector::operator<(const CATCDS3Vector& iV) const
{
  return _aCoord[0] < iV[0] || _aCoord[0] == iV[0] && (_aCoord[1] < iV[1] || _aCoord[1] == iV[1] && _aCoord[2] < iV[2]);
}

CATCDSInline void CATCDS3Vector::Add(double iX, double iY, double iZ)
{
  *this += CATCDS3Vector(iX, iY, iZ);
}

CATCDSInline void CATCDS3Vector::Add(const CATCDS3Vector& iV)
{
  *this += iV;
}

CATCDSInline void CATCDS3Vector::CopyArray(const CATCDS3Vector* iSrc, CATCDS3Vector* iDst, int iCount)
{
  memcpy(iDst, iSrc, iCount * sizeof(CATCDS3Vector));
}

#endif
