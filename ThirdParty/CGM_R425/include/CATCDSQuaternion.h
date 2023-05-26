#ifndef CATCDSQuaternion_H
#define CATCDSQuaternion_H

#include "CDSMathematics.h"

#include "CATCDS3Vector.h"
#include "CATCDSAssert.h"
#include "CATCDSBoolean.h"

#include <cstring>

class CATCDS3x3Matrix;
class CATCDSStream;

class CATCDSQuaternion
{
public:
  //
  // Constructors
  //
  CATCDSQuaternion();
  CATCDSQuaternion(double iQw, double iQx, double iQy, double iQz);
  CATCDSQuaternion(const double iQ[4]);
  ExportedByCDSMathematics CATCDSQuaternion(const double iQ[4], CATCDSBoolean iInputIsXYZW);
  CATCDSQuaternion(const CATCDSQuaternion& iQ);
#ifdef CPP11_AVAILABLE
  CATCDSQuaternion(cds::span<const double, 4> iQ);
  CATCDSQuaternion(cds::span<const double, 4> iQ, CATCDSBoolean iInputIsXYZW);
#endif
  //
  // Set and get the quaternion values
  //
  void Set(double iQw, double iQx, double iQy, double iQz);
  void Set(const double iQ[4]);
  void Set(const CATCDSQuaternion& iQ);
  void Get(double oQ[4]) const;
  ExportedByCDSMathematics void Get(double oQ[4], CATCDSBoolean iOutputIsXYZW) const;
  void Get(double& oW, double& oX, double& oY, double& oZ) const;

#ifdef CPP11_AVAILABLE
  void Get(cds::span<double, 4> oQ) const;
  void Get(cds::span<double, 4>, CATCDSBoolean iOutputIsXYZW) const;
#endif

  const double& GetW() const { return _Q[0]; }
  const double& GetX() const { return _Q[1]; }
  const double& GetY() const { return _Q[2]; }
  const double& GetZ() const { return _Q[3]; }

  //
  // operators
  //
  const CATCDSQuaternion operator+(const CATCDSQuaternion& iQ) const;
  CATCDSQuaternion& operator+=(const CATCDSQuaternion& iQ);
  const CATCDSQuaternion operator-(const CATCDSQuaternion& iQ) const;
  CATCDSQuaternion& operator-=(const CATCDSQuaternion& iQ);
  const CATCDSQuaternion operator*(const CATCDSQuaternion& iQ) const;
  CATCDSQuaternion& operator*=(const CATCDSQuaternion& iQ);
  const CATCDSQuaternion operator*(double iFact) const;
  CATCDSQuaternion& operator*=(double iFact);
  double& operator[](unsigned short int i);
  const double& operator[](unsigned short int i) const;
  //
  // return the transposed quaternion
  //
  CATCDSQuaternion Transpose() const;
  CATCDSQuaternion GetTranspose() const;
  void Inverse();
  //
  // Convert between quaternion and orientation matrix
  //
  ExportedByCDSMathematics void ImportMatrix(const CATCDS3x3Matrix& iM);
  ExportedByCDSMathematics void ExportMatrix(CATCDS3x3Matrix& oM) const;
  ExportedByCDSMathematics CATCDS3x3Matrix ExportMatrix() const;

  //
  // Convert to the equivalent 3 rotation angles (X->Y->Z )
  //
  ExportedByCDSMathematics void ExportAngles(double oxyzAngles[3]) const;
#ifdef CPP11_AVAILABLE
  void ExportAngles(cds::span<double, 3> oxyzAngles) const;
#endif

  ExportedByCDSMathematics double GetNorm() const;
  // normalize this if Norm >= iNormTolerance
  ExportedByCDSMathematics CATCDSBoolean Normalize(double iNormTolerance);

  ExportedByCDSMathematics CATCDSBoolean SetFromVectors(const CATCDS3Vector& iVectorFrom, const CATCDS3Vector& iVectorTo, double iAngleTol);
  ExportedByCDSMathematics void GetAngleAxis(double& oAngle, CATCDS3Vector& oRotationVector, double iTol) const;
  // return the angel compute by GetAngleAxis
  ExportedByCDSMathematics double GetAngle() const;

  //double Debug_GetElement(unsigned short int i) const;
  //friend double CONCAT_NAMES(CATCDSQuaternion, _Debug_GetElement)(const CATCDSQuaternion& iQ, unsigned short int i);

  ExportedByCDSMathematics void Unify(); // if w < 0, multiplies all coordinates by -1. (same rotation represented)

  // for ODT migration only. do not use

#ifdef CPP11_AVAILABLE
  double (&DoNotUse())[4] { return _Q; }
#endif

  CATCDS3Vector Rotate(const CATCDS3Vector&) const;

  /// Quaternion interpolation
  /// iCoef going from 0 to 1
  ///   iCoef == 0 -> q = q0
  ///   iCoef == 1 -> q = q1
  ExportedByCDSMathematics static void Slerp(CATCDSQuaternion& q, double iCoef, const CATCDSQuaternion& q0, const CATCDSQuaternion& q1);

  static void CopyArray(const CATCDSQuaternion* iSrc, CATCDSQuaternion* iDst, int iCount);

  bool operator==(CATCDSQuaternion const&) const;
  bool operator!=(CATCDSQuaternion const&) const;

  bool operator<(CATCDSQuaternion const&) const;

private:
  double _Q[4];
};

ExportedByCDSMathematics CATCDSStream& operator<<(CATCDSStream& ioStream, CATCDSQuaternion const& iQuaternion);

inline CATCDSQuaternion::CATCDSQuaternion()
{
  _Q[0] = 1.;
  _Q[1] = _Q[2] = _Q[3] = 0;
}

inline CATCDSQuaternion::CATCDSQuaternion(const double iQ[4])
{
  memcpy(_Q, iQ, sizeof(_Q));
}

inline CATCDSQuaternion::CATCDSQuaternion(double iQw, double iQx, double iQy, double iQz)
{
  _Q[0] = iQw;
  _Q[1] = iQx;
  _Q[2] = iQy;
  _Q[3] = iQz;
}

#ifdef CPP11_AVAILABLE
inline CATCDSQuaternion::CATCDSQuaternion(cds::span<const double, 4> iQ)
  : CATCDSQuaternion(iQ.data())
{
}

inline CATCDSQuaternion::CATCDSQuaternion(cds::span<const double, 4> iQ, CATCDSBoolean iInputIsXYZW)
  : CATCDSQuaternion(iQ.data(), iInputIsXYZW)
{
}
#endif

inline CATCDSQuaternion::CATCDSQuaternion(const CATCDSQuaternion& iQ)
{
  memcpy(_Q, iQ._Q, sizeof(_Q));
}

inline void CATCDSQuaternion::Set(const double iQ[4])
{
  memcpy(_Q, iQ, sizeof(_Q));
}

inline void CATCDSQuaternion::Set(const CATCDSQuaternion& iQ)
{
  memcpy(_Q, iQ._Q, sizeof(_Q));
}

inline void CATCDSQuaternion::Set(double iQw, double iQx, double iQy, double iQz)
{
  _Q[0] = iQw;
  _Q[1] = iQx;
  _Q[2] = iQy;
  _Q[3] = iQz;
}

inline void CATCDSQuaternion::Get(double oQ[4]) const
{
  memcpy(oQ, _Q, sizeof(_Q));
}

inline void CATCDSQuaternion::Get(double& oW, double& oX, double& oY, double& oZ) const
{
  oW = _Q[0];
  oX = _Q[1];
  oY = _Q[2];
  oZ = _Q[3];
}

#ifdef CPP11_AVAILABLE
inline void CATCDSQuaternion::Get(cds::span<double, 4> oQ) const
{
  Get(oQ.data());
}

inline void CATCDSQuaternion::Get(cds::span<double, 4> oQ, CATCDSBoolean iOutputIsXYZW) const
{
  Get(oQ.data(), iOutputIsXYZW);
}
#endif

inline const CATCDSQuaternion CATCDSQuaternion::operator+(const CATCDSQuaternion& iQ) const
{
  return CATCDSQuaternion(_Q[0] + iQ._Q[0], _Q[1] + iQ._Q[1], _Q[2] + iQ._Q[2], _Q[3] + iQ._Q[3]);
}

inline CATCDSQuaternion& CATCDSQuaternion::operator+=(const CATCDSQuaternion& iQ)
{
  _Q[0] += iQ._Q[0];
  _Q[1] += iQ._Q[1];
  _Q[2] += iQ._Q[2];
  _Q[3] += iQ._Q[3];
  return *this;
}

inline const CATCDSQuaternion CATCDSQuaternion::operator-(const CATCDSQuaternion& iQ) const
{
  return CATCDSQuaternion(_Q[0] - iQ._Q[0], _Q[1] - iQ._Q[1], _Q[2] - iQ._Q[2], _Q[3] - iQ._Q[3]);
}

inline CATCDSQuaternion& CATCDSQuaternion::operator-=(const CATCDSQuaternion& iQ)
{
  _Q[0] -= iQ._Q[0];
  _Q[1] -= iQ._Q[1];
  _Q[2] -= iQ._Q[2];
  _Q[3] -= iQ._Q[3];
  return *this;
}

inline const CATCDSQuaternion CATCDSQuaternion::operator*(const CATCDSQuaternion& iQ) const
{
  return CATCDSQuaternion(
    _Q[0] * iQ._Q[0] - _Q[1] * iQ._Q[1] - _Q[2] * iQ._Q[2] - _Q[3] * iQ._Q[3],
    _Q[0] * iQ._Q[1] + _Q[1] * iQ._Q[0] + _Q[2] * iQ._Q[3] - _Q[3] * iQ._Q[2],
    _Q[0] * iQ._Q[2] + _Q[2] * iQ._Q[0] + _Q[3] * iQ._Q[1] - _Q[1] * iQ._Q[3],
    _Q[0] * iQ._Q[3] + _Q[3] * iQ._Q[0] + _Q[1] * iQ._Q[2] - _Q[2] * iQ._Q[1]);
}

inline const CATCDSQuaternion CATCDSQuaternion::operator*(double iFact) const
{
  return CATCDSQuaternion(iFact * _Q[0], iFact * _Q[1], iFact * _Q[2], iFact * _Q[3]);
}

inline CATCDSQuaternion CATCDSQuaternion::Transpose() const
{
  CATCDSQuaternion Q(_Q[0], -_Q[1], -_Q[2], -_Q[3]);
  return Q;
}

inline CATCDSQuaternion CATCDSQuaternion::GetTranspose() const
{
  return Transpose();
}

inline void CATCDSQuaternion::Inverse()
{
  _Q[1] *= -1;
  _Q[2] *= -1;
  _Q[3] *= -1;
}

#ifdef CPP11_AVAILABLE
inline void CATCDSQuaternion::ExportAngles(cds::span<double, 3> oxyzAngles) const
{
  ExportAngles(oxyzAngles.data());
}
#endif

inline CATCDSQuaternion& CATCDSQuaternion::operator*=(const CATCDSQuaternion& iQ)
{
  return *this = *this * iQ;
}

inline CATCDSQuaternion& CATCDSQuaternion::operator*=(double iFact)
{

  _Q[0] *= iFact;
  _Q[1] *= iFact;
  _Q[2] *= iFact;
  _Q[3] *= iFact;

  return *this;
}

inline double& CATCDSQuaternion::operator[](unsigned short int i)
{
  CATCDSAssert(i < 4);
  return _Q[i];
}

inline const double& CATCDSQuaternion::operator[](unsigned short int i) const
{
  CATCDSAssert(i < 4);
  return _Q[i];
}

inline CATCDS3Vector CATCDSQuaternion::Rotate(const CATCDS3Vector& v) const
{
  const double a = v.GetX();
  const double b = v.GetY();
  const double c = v.GetZ();
  const double w = _Q[0];
  const double x = _Q[1];
  const double y = _Q[2];
  const double z = _Q[3];
  return CATCDS3Vector(
    (w * w + x * x - y * y - z * z) * a + 2 * ((x * y - w * z) * b + (w * y + x * z) * c),
    (w * w - x * x + y * y - z * z) * b + 2 * ((y * z - w * x) * c + (x * y + w * z) * a),
    (w * w - x * x - y * y + z * z) * c + 2 * ((x * z - w * y) * a + (w * x + y * z) * b));
}

/*static inline double CONCAT_NAMES(CATCDSQuaternion, _Debug_GetElement)(const CATCDSQuaternion& iQ, unsigned short int i)
{
  return iQ._Q[i];
}*/

inline bool CATCDSQuaternion::operator==(CATCDSQuaternion const& iQ) const
{
  return iQ._Q[0] == _Q[0] && iQ._Q[1] == _Q[1] && iQ._Q[2] == _Q[2] && iQ._Q[3] == _Q[3];
}

inline bool CATCDSQuaternion::operator!=(CATCDSQuaternion const& iQ) const
{
  return !(*this == iQ);
}

inline bool CATCDSQuaternion::operator<(CATCDSQuaternion const& iQ) const
{
  for (int i = 0; i < 4; i++)
  {
    if (iQ._Q[i] < _Q[i])
      return true;
    if (iQ._Q[i] != _Q[i])
      return false;
  }
  return false;
}

/*inline double CATCDSQuaternion::Debug_GetElement(unsigned short int i) const
{
  return _Q[i];
}*/

inline void CATCDSQuaternion::CopyArray(const CATCDSQuaternion* iSrc, CATCDSQuaternion* iDst, int iCount)
{
  memcpy(iDst, iSrc, iCount * sizeof(CATCDSQuaternion));
}

inline CATCDSQuaternion operator-(const CATCDSQuaternion& iQ)
{
  return CATCDSQuaternion(-iQ[0], -iQ[1], -iQ[2], -iQ[3]);
}

#endif
