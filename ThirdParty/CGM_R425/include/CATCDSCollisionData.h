#ifndef CATCDSCollisionData_H
#define CATCDSCollisionData_H

// Spatial builds CDS on VC12.  Some of the advanced
// C++ features are not supported on this compiler, and the collision detection
// functionality is not needed for them.
#if !defined(_MSC_VER) || _MSC_VER >= 1900
#include "CATCDS3Point.h"
#include "CATCDS3Vector.h"
#include "CATCDSVirtual.h"
#include "CATCDSAssert.h"
#include "CATCDSArray.h"
#include "CATCDSFixedSizeArray.h"

/*
type of collision
*/
enum CATCDSCollisionType
{
  coNULL_TYPE = 0,
  coCLASH_POINT_TYPE,
  coAREA_CLASH_TYPE,
  coBIG_CLASH_TYPE
};

// ================================
// Class of all collisions
// ================================
class ExportedByCATCDSUtilities CATCDSCollisionData CATCDSFinal
{
public:
  CATCDSCollisionData();
  CATCDSCollisionData(CATCDSCollisionType iType, int iIdx1, int iIdx2, int iIdxPart1, int iIdxPart2);

#ifdef CPP11_AVAILABLE
  CATCDSCollisionData(const CATCDSCollisionData& iCollData) = default;
  CATCDSCollisionData& operator=(const CATCDSCollisionData& iCollData) = default;
  CATCDSCollisionData(CATCDSCollisionData &&iCollData) = default;
  CATCDSCollisionData& operator=(CATCDSCollisionData &&iCollData) = default;
  ~CATCDSCollisionData() = default;
#endif

  void SetCollisionPoint(double iX, double iY, double iZ);
  void SetCollisionNormal(double iNx, double iNy, double iNz);
  void SetCollisionPoint(CATCDS3Point const &iPoint);
  void SetCollisionNormal(CATCDS3Vector const &iVector);
  void SetSlaveCollisionNormal(CATCDS3Vector const &iVector);
  void SetDepth(double iDepth);
  void SetAbutment(CATCDSBoolean iIsAbut); // SetAbutment(TRUE) for contact whose depth is under the resolution
  void SetAreaCollision(double iArea,
    double iTrianglePointX_1, double iTrianglePointY_1, double iTrianglePointZ_1,
    double iTrianglePointX_2, double iTrianglePointY_2, double iTrianglePointZ_2,
    double iTrianglePointX_3, double iTrianglePointY_3, double iTrianglePointZ_3);
  void SetArea(double iArea);
  void SetTriangleVertices(CATCDS3Point iPoint1, CATCDS3Point iPoint2, CATCDS3Point iPoint3);

  void SetIndices(int iIdx1, int  iIdx2, int iIdxPart1, int iIdxPart2);
  void GetIndices(int &oIdx1, int& oIdx2, int& oiIdxPart1, int& oiIdxPart2) const;
  void GetCollisionPoint(double &oCx, double &oCy, double &oCz) const;
  void GetCollisionNormal(double &oNx, double &oNy, double &oNz) const;
  CATCDS3Point const & GetCollisionPoint() const;
  CATCDS3Vector const & GetCollisionNormal() const;
  CATCDS3Vector const & GetSlaveCollisionNormal() const;
  CATCDSBoolean isAbut() const;
  double GetArea() const;
  double GetDepth() const;
  void GetTriangleCoordinates(double& oTrianglePointX_1, double& oTrianglePointY_1, double& oTrianglePointZ_1,
    double& oTrianglePointX_2, double& oTrianglePointY_2, double& oTrianglePointZ_2,
    double& oTrianglePointX_3, double& oTrianglePointY_3, double& oTrianglePointZ_3) const;
  void GetTriangleVertices(CATCDS3Point& oPoint1, CATCDS3Point& oPoint2, CATCDS3Point& oPoint3) const;

  void SetType(CATCDSCollisionType iType);
  CATCDSCollisionType GetType() const;
  CATCDSBoolean isA(CATCDSCollisionType iType) const;

  bool operator==(CATCDSCollisionData const &iCollision) const;
  bool operator!=(CATCDSCollisionData const &iCollision) const;

  bool IsPlanar() const;
  void SetPlanar(bool iPlanar);

protected:
  CATCDSCollisionType _type;
  int _Index1;
  int _Index2;
  int _IndexPart1;
  int _IndexPart2;
  // Contact and normal are in WCS
  CATCDS3Point _contact;
  CATCDS3Vector _normal;
  CATCDS3Vector _slaveNormal;
  double _depth;
  CATCDSBoolean _isAbut;
  bool _isPlanar = false;
  // Triangle points are in first collidable coordinate system
  CATCDS3Point _Point1, _Point2, _Point3;
  double _area;
};

inline void CATCDSCollisionData::SetType(CATCDSCollisionType iType)
{
  _type = iType;
}

inline CATCDSCollisionType CATCDSCollisionData::GetType() const
{
  return _type;
}

inline void CATCDSCollisionData::SetIndices(int iIdx1, int  iIdx2, int iIdxPart1, int iIdxPart2)
{
  _Index1 = iIdx1;
  _Index2 = iIdx2;
  _IndexPart1 = iIdxPart1;
  _IndexPart2 = iIdxPart2;
}

inline void CATCDSCollisionData::GetIndices(int &oIdx1, int& oIdx2, int& oiIdxPart1, int& oiIdxPart2) const
{
  oIdx1 = _Index1;
  oIdx2 = _Index2;
  oiIdxPart1 = _IndexPart1;
  oiIdxPart2 = _IndexPart2;
}

inline CATCDS3Point const & CATCDSCollisionData::GetCollisionPoint() const
{
  return _contact;
}

inline CATCDS3Vector const & CATCDSCollisionData::GetCollisionNormal() const
{
  return _normal;
}

inline CATCDS3Vector const & CATCDSCollisionData::GetSlaveCollisionNormal() const
{
  return _slaveNormal;
}

inline double CATCDSCollisionData::GetDepth() const
{
  CATCDSAssert(isA(coCLASH_POINT_TYPE));
  return _depth;
}

inline void CATCDSCollisionData::SetCollisionPoint(double iX, double iY, double iZ)
{
  _contact = CATCDS3Point(iX, iY, iZ);
}

inline void CATCDSCollisionData::SetCollisionNormal(double iNx, double iNy, double iNz)
{
  _normal = CATCDS3Vector(iNx, iNy, iNz);
}

inline void CATCDSCollisionData::SetCollisionPoint(CATCDS3Point const &iPoint)
{
  _contact = iPoint;
}

inline void CATCDSCollisionData::SetCollisionNormal(CATCDS3Vector const &iVector)
{
  _normal = iVector;
}

inline void CATCDSCollisionData::SetSlaveCollisionNormal(CATCDS3Vector const &iVector)
{
  _slaveNormal = iVector;
}

inline void CATCDSCollisionData::SetDepth(double iDepth)
{
  _depth = iDepth;
}

inline void CATCDSCollisionData::SetAbutment(CATCDSBoolean iIsAbut)
{
  _isAbut = iIsAbut;
}

inline void CATCDSCollisionData::SetAreaCollision(double iArea,
  double iTrianglePointX_1, double iTrianglePointY_1, double iTrianglePointZ_1,
  double iTrianglePointX_2, double iTrianglePointY_2, double iTrianglePointZ_2,
  double iTrianglePointX_3, double iTrianglePointY_3, double iTrianglePointZ_3)
{
  _Point1 = CATCDS3Point(iTrianglePointX_1, iTrianglePointY_1, iTrianglePointZ_1);
  _Point2 = CATCDS3Point(iTrianglePointX_2, iTrianglePointY_2, iTrianglePointZ_2);
  _Point3 = CATCDS3Point(iTrianglePointX_3, iTrianglePointY_3, iTrianglePointZ_3);
  _area = iArea;
}

inline void CATCDSCollisionData::SetArea(double iArea)
{
  _area = iArea;
}
inline void CATCDSCollisionData::SetTriangleVertices(CATCDS3Point iPoint1, CATCDS3Point iPoint2, CATCDS3Point iPoint3)
{
  _Point1 = iPoint1;
  _Point2 = iPoint2;
  _Point3 = iPoint3;
}

inline CATCDSBoolean CATCDSCollisionData::isAbut() const
{
  CATCDSAssert(isA(coCLASH_POINT_TYPE));
  return _isAbut;
}

inline double CATCDSCollisionData::GetArea() const
{
  CATCDSAssert(isA(coAREA_CLASH_TYPE));
  return _area;
}

inline void CATCDSCollisionData::GetTriangleVertices(CATCDS3Point& oPoint1, CATCDS3Point& oPoint2, CATCDS3Point& oPoint3) const
{
  oPoint1 = _Point1;
  oPoint2 = _Point2;
  oPoint3 = _Point3;
}

inline bool CATCDSCollisionData::operator==(CATCDSCollisionData const &iCollision) const
{
  return _type == iCollision._type &&
    _Index1 == iCollision._Index1 &&
    _Index2 == iCollision._Index2 &&
    _IndexPart1 == iCollision._IndexPart1 &&
    _IndexPart2 == iCollision._IndexPart2 &&
    _contact == iCollision._contact &&
    _normal == iCollision._normal &&
    _depth == iCollision._depth &&
    _area == iCollision._area &&
    _isAbut == iCollision._isAbut &&
    _Point1 == iCollision._Point1 &&
    _Point2 == iCollision._Point2 &&
    _Point3 == iCollision._Point3;
}

inline bool CATCDSCollisionData::operator!=(CATCDSCollisionData const &iCollision) const
{
  return !(*this == iCollision);
}

inline bool CATCDSCollisionData::IsPlanar() const
{
  return _isPlanar;
}

inline void CATCDSCollisionData::SetPlanar(bool iPlanar)
{
  _isPlanar = iPlanar;
}

#endif
#endif
