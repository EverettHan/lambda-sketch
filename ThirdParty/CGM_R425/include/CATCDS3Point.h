#ifndef CATCDS3Point_H
#define CATCDS3Point_H

// COPYRIGHT DASSAULT SYSTEMES  2003

#include "CATCDSInline.h"
#include "CDSMathematics.h"
#include "CATCDSCPlusPlusVersions.h"

#ifdef CPP11_AVAILABLE
#include "CATCDSSpan.h"
#endif

class CATCDS3Vector;
class CATCDSStream;

#define CATCDSOriginX 0.
#define CATCDSOriginY 0.
#define CATCDSOriginZ 0.

/**
 * Class representing a mathematical cartesian point in dimension 3.
 */
class ExportedByCDSMathematics CATCDS3Point
{
public:
#ifdef CPP11_AVAILABLE
  CATCDS3Point() = default;
  CATCDS3Point(CATCDS3Point const &) = default;
  CATCDS3Point& operator=(CATCDS3Point const &) = default;
  ~CATCDS3Point() = default;

  CATCDS3Point(cds::span<double const, 3> iCoord);
#else
  //----------------------------------------------------------
  //- Constructors
  //----------------------------------------------------------
  /**
   * Constructs a CATCDS3Point with <tt>(0,0,0)</tt> coordinates.
   */
  CATCDS3Point();
#endif

  /**
   * Constructs a CATCDS3Point from coordinates.
   */
  CATCDS3Point(double iX, double iY, double iZ);
  /**
   * Constructs a CATCDS3Point from an array of 3 coordinates.
   */
  CATCDS3Point(const double iCoord[]);

  explicit CATCDS3Point(int iIdx);

  //----------------------------------------------------------
  //- Get/Set
  //----------------------------------------------------------
  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Point.
   */
  void GetCoord(double& oX, double& oY, double& oZ) const;
  void GetCoord2D(double& oX, double& oY) const;

  /**
   * Modifies the coordinates of <tt>this</tt> CATCDS3Point from 3 doubles.
   */
  void SetCoord(double iX, double iY, double iZ);

  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Point in an array of 3 doubles.
   */
  void GetCoord(double oCoord[]) const;
#ifdef CPP11_AVAILABLE
  void GetCoord(cds::span<double, 3> oCoord) const;
#endif
  /**
   * Modifies the coordinates of <tt>this</tt> CATCDS3Point from an array of 3 doubles.
   */
  void SetCoord(const double iCoord[]);
  void SetCoord2D(const double iCoord[]);
#ifdef CPP11_AVAILABLE
  void SetCoord(cds::span<double const, 3> iCoord);
#endif

  /**
   * Returns the iIdx coordinate of <tt>this</tt> CATCDS3Point.
   */
  double GetCoord(unsigned int iIdx) const;

  /**
   * Modifies the iIdx coordinate of <tt>this</tt> CATCDS3Vector.
   */
  void SetCoord(unsigned int iIdx, double iValue);

  /**
   * Returns the X coordinate of <tt>this</tt> CATCDS3Point.
   */
  double GetX() const;

  /**
   * Modifies the X coordinate of <tt>this</tt> CATCDS3Point.
   */
  void SetX(double iX);

  /**
   * Returns the Y coordinate of <tt>this</tt> CATCDS3Point.
   */
  double GetY() const;

  /**
   * Modifies the Y coordinate of <tt>this</tt> CATCDS3Point.
   */
  void SetY(double iY);

  /**
   * Returns the Z coordinate of <tt>this</tt> CATCDS3Point.
   */
  double GetZ() const;

  /**
   * Modifies the Z coordinate of <tt>this</tt> CATCDS3Point.
   */
  void SetZ(double iZ);

  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Point as array of 3 doubles.
   */
  double(&GetCoord())[3];

  /**
   * Retrieves the coordinates of <tt>this</tt> CATCDS3Point as array of 3 doubles.
   */
  double const (&GetCoord() const)[3];

  /**
   * Returns the distance between <tt>this</tt> CATCDS3Point and another CATCDS3Point.
   */
  double DistanceTo(const CATCDS3Point& iPoint) const;

  /**
   * Returns the square distance between <tt>this</tt> CATCDS3Point and another CATCDS3Point.
   */
  double SquareDistanceTo(const CATCDS3Point& iPoint) const;

  /**
   * Returns the distance between <tt>this</tt> CATCDS3Point  and an array of CATCDS3Points.
   * @param iOtherPoint[]
   *   The array of CATCDS3Points to which the distance is computed.
   * @param iNbPt
   *   The number of points of the array.
   * @param ioIndex
   *   The index of the closest point in the <tt>iOtherPoint[]</tt> array.
   */
  double DistanceTo(const CATCDS3Point iaPoints[], int iNbPoints, int& oIndex) const;

  /**
   * Returns projection point on a given line
   */
  CATCDS3Point ProjectOnLine(const CATCDS3Point& iOrigin, const CATCDS3Vector& iDirection) const;

  /**
   * Returns projection point on a given plane
   */
  CATCDS3Point ProjectOnPlane(const CATCDS3Point& iAnchor, const CATCDS3Vector& iNormal) const;

  /**
   * Returns distance to a given line
   */
  double DistanceToLine(const CATCDS3Point& iOrigin, const CATCDS3Vector& iDirection) const;

  /**
   * Returns signed distance to a given plane
   */
  double DistanceToPlane(const CATCDS3Point& iAnchor, const CATCDS3Vector& iNormal) const;

  /**
   *  Write point.
   */
  void Write(const char* iName) const;

  //- Overloaded Operators

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
   * Modifies a CATCDS3Point by using a translation by a CATCDS3Vector.
   * @param iPoint
   * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Point of <tt>(p1=p1+u1,p2=p2+u2,p3=p3+u3)</tt> coordinates.
   */
  CATCDS3Point& operator+=(const CATCDS3Vector& iVector);

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
   * Translates a CATCDS3Point by a CATCDS3Vector.
   * @param iPoint
   * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Point of <tt>(p1-u1,p2-u2,p3-u3)</tt> coordinates.
   */
  friend CATCDS3Point operator-(const CATCDS3Point& iPoint, const CATCDS3Vector& iVector);

  /**
   * Modifies a CATCDS3Point by using a translation by a CATCDS3Vector.
   * @param iPoint
   * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
   * @param iVector
   * The CATCDS3Vector of <tt>(u1,u2,u3)</tt> coordinates.
   * @return
   * The CATCDS3Point of <tt>(p1=p1-u1,p2=p2-u2,p3=p3-u3)</tt> coordinates.
   */
  CATCDS3Point& operator-=(const CATCDS3Vector& iVector);

  /**
  * Modifies a CATCDS3Point by summing another CATCDS3Point
  * @param iPoint
  * The CATCDS3Point of <tt>(u1,u2,u3)</tt> coordinates.
  * @return
  * The CATCDS3Point of <tt>(p1=p1+u1,p2=p2+u2,p3=p3+u3)</tt> coordinates.
  */
  CATCDS3Point& operator+=(const CATCDS3Point &iPoint);

  /**
  * Sums two points.
  * @param iPoint
  * The CATCDS3Point of <tt>(p1,p2,p3)</tt> coordinates.
  * @param iVector
  * The CATCDS3Point of <tt>(u1,u2,u3)</tt> coordinates.
  * @return
  * The CATCDS3Point of <tt>(p1=p1+u1,p2=p2+u2,p3=p3+u3)</tt> coordinates.
  */
  friend CATCDS3Point operator+(const CATCDS3Point& iPoint1, const CATCDS3Point& iPoint2);

  CATCDS3Point& operator*=(double iC);
  CATCDS3Point& operator/=(double iC);

  /**
   * Builds a CATCDS3Vector from the point to the origin.
   */
  CATCDS3Vector MinusOrigin() const;

  /**
   * Get CDS origin
   */
  static CATCDS3Point GetOrigin()
  {
    return CATCDS3Point(CATCDSOriginX, CATCDSOriginY, CATCDSOriginZ);
  }

  /**
  * Accessors for point
  */
  double const& operator[](int iIdx) const;
  double& operator[](int iIdx);

  bool operator==(CATCDS3Point const& iV) const;
  bool operator!=(CATCDS3Point const& iV) const;
  bool operator<(CATCDS3Point const& iV) const;

private:
#ifdef CPP11_AVAILABLE
  double _aCoord[3] = {};
#else
  double _aCoord[3];
#endif
};

#include "CATCDS3Vector.h"

//======================================================================
// INLINE IMPLEMENTATIONS
//======================================================================

#ifdef CPP11_AVAILABLE
CATCDSInline CATCDS3Point::CATCDS3Point(cds::span<double const, 3> iCoord)
  : CATCDS3Point(iCoord.data())
{
}


#else
CATCDSInline CATCDS3Point::CATCDS3Point()
{
  _aCoord[0] = _aCoord[1] = _aCoord[2] = 0.0;
}
#endif

CATCDSInline CATCDS3Point::CATCDS3Point(double iX, double iY, double iZ)
{
  _aCoord[0] = iX;
  _aCoord[1] = iY;
  _aCoord[2] = iZ;
}

CATCDSInline CATCDS3Point::CATCDS3Point(const double iCoord[])
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

CATCDSInline CATCDS3Point::CATCDS3Point(int iIdx)
{
  _aCoord[iIdx] = 1.;
}

CATCDSInline void CATCDS3Point::GetCoord(double& oX, double& oY, double& oZ) const
{
  oX = _aCoord[0];
  oY = _aCoord[1];
  oZ = _aCoord[2];
}

CATCDSInline void CATCDS3Point::GetCoord2D(double& oX, double& oY) const
{
  oX = _aCoord[0];
  oY = _aCoord[1];
}

CATCDSInline void CATCDS3Point::GetCoord(double oCoord[]) const
{
  oCoord[0] = _aCoord[0];
  oCoord[1] = _aCoord[1];
  oCoord[2] = _aCoord[2];
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3Point::GetCoord(cds::span<double, 3> oCoord) const
{
  GetCoord(oCoord.data());
}
#endif

CATCDSInline double CATCDS3Point::GetCoord(unsigned int iIdx) const
{
  return _aCoord[iIdx];
}

CATCDSInline double CATCDS3Point::GetX() const
{
  return _aCoord[0];
}
CATCDSInline double CATCDS3Point::GetY() const
{
  return _aCoord[1];
}
CATCDSInline double CATCDS3Point::GetZ() const
{
  return _aCoord[2];
}

CATCDSInline void CATCDS3Point::SetCoord(double iX, double iY, double iZ)
{
  _aCoord[0] = iX;
  _aCoord[1] = iY;
  _aCoord[2] = iZ;
}

CATCDSInline void CATCDS3Point::SetCoord(const double iCoord[])
{
  _aCoord[0] = iCoord[0];
  _aCoord[1] = iCoord[1];
  _aCoord[2] = iCoord[2];
}

CATCDSInline void CATCDS3Point::SetCoord2D(const double iCoord[])
{
  _aCoord[0] = iCoord[0];
  _aCoord[1] = iCoord[1];
  _aCoord[2] = 1.0;
}

#ifdef CPP11_AVAILABLE
CATCDSInline void CATCDS3Point::SetCoord(cds::span<double const, 3> iCoord)
{
  SetCoord(iCoord.data());
}
#endif

CATCDSInline void CATCDS3Point::SetCoord(unsigned int iIdx, double iValue)
{
  _aCoord[iIdx] = iValue;
}

CATCDSInline void CATCDS3Point::SetX(double iX)
{
  _aCoord[0] = iX;
}
CATCDSInline void CATCDS3Point::SetY(double iY)
{
  _aCoord[1] = iY;
}
CATCDSInline void CATCDS3Point::SetZ(double iZ)
{
  _aCoord[2] = iZ;
}

CATCDSInline double(&CATCDS3Point::GetCoord())[3]
{
  return _aCoord;
}

CATCDSInline double const (&CATCDS3Point::GetCoord() const)[3]
{
  return _aCoord;
}

CATCDSInline double const& CATCDS3Point::operator[](int iIdx) const
{
  return _aCoord[iIdx];
}

CATCDSInline double& CATCDS3Point::operator[](int iIdx)
{
  return _aCoord[iIdx];
}

CATCDSInline CATCDS3Point& CATCDS3Point::operator+=(const CATCDS3Vector& iVector)
{
  _aCoord[0] += iVector[0];
  _aCoord[1] += iVector[1];
  _aCoord[2] += iVector[2];
  return *this;
}

CATCDSInline CATCDS3Point& CATCDS3Point::operator+=(const CATCDS3Point &iPoint)
{
  _aCoord[0] += iPoint[0];
  _aCoord[1] += iPoint[1];
  _aCoord[2] += iPoint[2];
  return *this;
}

CATCDSInline CATCDS3Point& CATCDS3Point::operator-=(const CATCDS3Vector& iVector)
{
  _aCoord[0] -= iVector[0];
  _aCoord[1] -= iVector[1];
  _aCoord[2] -= iVector[2];
  return *this;
}

CATCDSInline CATCDS3Point operator+(CATCDS3Point const &iPoint1, CATCDS3Point const &iPoint2)
{
  CATCDS3Point res(iPoint1);
  return res += iPoint2;
}

CATCDSInline CATCDS3Point& CATCDS3Point::operator*=(double iC)
{
  _aCoord[0] *= iC;
  _aCoord[1] *= iC;
  _aCoord[2] *= iC;
  return *this;
}

CATCDSInline CATCDS3Point& CATCDS3Point::operator/=(double iC)
{
  _aCoord[0] /= iC;
  _aCoord[1] /= iC;
  _aCoord[2] /= iC;
  return *this;
}

CATCDSInline CATCDS3Point operator*(double iC, CATCDS3Point const &iPoint)
{
  CATCDS3Point res(iPoint);
  return res *= iC;
}

CATCDSInline CATCDS3Point operator*(CATCDS3Point const &iPoint, double iC)
{
  CATCDS3Point res(iPoint);
  return res *= iC;
}

CATCDSInline CATCDS3Point operator/(CATCDS3Point const &iPoint, double iC)
{
  CATCDS3Point res(iPoint);
  return res /= iC;
}

CATCDSInline double operator*(CATCDS3Point const &iPoint, CATCDS3Vector const &iVector)
{
  return ((iPoint[0] * iVector[0]) + (iPoint[1] * iVector[1])) + (iPoint[2] * iVector[2]);
}

CATCDSInline bool CATCDS3Point::operator==(const CATCDS3Point& iV) const
{
  return _aCoord[0] == iV[0] && _aCoord[1] == iV[1] && _aCoord[2] == iV[2];
}

CATCDSInline bool CATCDS3Point::operator!=(const CATCDS3Point& iV) const
{
  return _aCoord[0] != iV[0] || _aCoord[1] != iV[1] || _aCoord[2] != iV[2];
}

CATCDSInline bool CATCDS3Point::operator<(const CATCDS3Point& iV) const
{
  return _aCoord[0] < iV[0] || _aCoord[0] == iV[0] && (_aCoord[1] < iV[1] || _aCoord[1] == iV[1] && _aCoord[2] < iV[2]);
}

CATCDSInline CATCDS3Point operator-(CATCDS3Point const &iPoint)
{
  return CATCDS3Point(-iPoint[0], -iPoint[1], -iPoint[2]);
}

ExportedByCDSMathematics CATCDSStream& operator<<(CATCDSStream& ioStream, CATCDS3Point const& iPoint);

#endif
