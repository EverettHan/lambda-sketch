// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPTopologicalSpaceSO3.h
//
//===================================================================
//
// Usage notes: Description of the topological spaces representing
// Rotation in R^3.
//
//===================================================================
//
// 2013-02-06 XXC: Creation
// 2013-10-07 JXO: Clamp method
// 2017-01-26 JXO: New GetRandomPoint and min and max radius methods
// 2018-11-07 JXO: Public convert methods
//===================================================================

#ifndef CATPolyPPTopologicalSpaceSO3_HH
#define CATPolyPPTopologicalSpaceSO3_HH

#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATPolyPPTopologicalSpace.h"
#include "CATPolyConcentricIterator.h"

// Math
#include "CATMath.h"
class CATMath3x3Matrix;

class CATPolyPPTopologicalPoint;
class CATPolyUniformRandomGenerator;
class CATPolyPPPosition;

/**
 * Description of the topological spaces representing
 * Rotation in R^3.
 * */
class ExportedByPolyPathPlanning CATPolyPPTopologicalSpaceSO3 : public CATPolyPPTopologicalSpace
{
 public:

  // Limits can be set on Euler angles. These limits must be in the
  // following ranges:
  // Yaw (z) in [-pi;pi], Pitch (y) in [-pi/2;pi/2], Roll (x) in [-pi;pi].
  // Twist (z) in [-pi;pi], Swing (x) in [0;pi], Roll (z) in [-pi;pi].
  // Default limit values are set to these latter extremum values (no constraint).
  enum RotationType {
    EulerAnglesZYX, // "Yaw, Pitch and Roll"
    EulerAnglesZXZ, // "Swing and Twist (and Roll)"
    Quaternions
  };

 public:
  CATPolyPPTopologicalSpaceSO3(CATPolyUniformRandomGenerator & iRandomGenerator, RotationType iRotationType);
  CATPolyPPTopologicalSpaceSO3( const CATPolyPPTopologicalSpaceSO3& iOther, CATPolyUniformRandomGenerator & iRandomGenerator );
  virtual ~CATPolyPPTopologicalSpaceSO3();

  virtual CATPolyPPTopologicalPoint * GetRandomPoint();
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator,double iRotationMode, double & oJequi, double * v_rotation);
  virtual CATPolyPPTopologicalPoint * GetPoint(const CATPolyPPTopologicalPoint * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);


  virtual double SqDistance(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2) const;
  virtual double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const;
  virtual CATPolyPPTopologicalPoint * Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam);
  virtual void Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam, CATPolyPPTopologicalPoint& ioPoint);

  virtual HRESULT ClampToLimits(CATPolyPPTopologicalPoint & ioPoint) const;

  INLINE virtual RotationType GetRotationType() const { return m_RotationType; }

  INLINE void SetMaximumRadius(double iRadiusMax) { m_RadiusMax = iRadiusMax; }
  INLINE void SetMaximumRadius(double iRadiusMaxX, double iRadiusMaxY, double iRadiusMaxZ)
  {
    m_RadiusMaxX = iRadiusMaxX;
    m_RadiusMaxY = iRadiusMaxY;
    m_RadiusMaxZ = iRadiusMaxZ;
    m_jEquiX = CATSqrt(m_RadiusMaxZ*m_RadiusMaxZ+m_RadiusMaxY*m_RadiusMaxY);
    m_jEquiY = CATSqrt(m_RadiusMaxZ*m_RadiusMaxZ+m_RadiusMaxX*m_RadiusMaxX);
    m_jEquiZ = CATSqrt(m_RadiusMaxX*m_RadiusMaxX+m_RadiusMaxY*m_RadiusMaxY);
  }

  virtual CATPolyPPTopologicalSpaceSO3* Clone( CATPolyUniformRandomGenerator & iRandomGenerator ) const;
  virtual CATPolyPPTopologicalSpace* Clone(  ) const;

  virtual void Convert(const CATMath3x3Matrix & iMatrix, double & oYaw, double & oPitch, double & oRoll) const;

  virtual void Convert(const CATPolyPPTopologicalPoint & iPoint, CATMath3x3Matrix & oMatrix) const ;

  /** Can be used externaly */
  static void Convert(RotationType type, const CATMath3x3Matrix & iMatrix, double & oYaw, double & oPitch, double & oRoll) ;
  /** Can be used externaly */
  static void Convert(RotationType type, double d1, double d2, double d3, double d4 /* Only used in quaternions */, CATMath3x3Matrix & oMatrix) ;

private:
  void ConvertToQuaternion(const CATPolyPPTopologicalPoint & iPoint, double & w, double & i, double & j, double & k) const;
  void ConvertFromQuaternion(CATPolyPPTopologicalPoint & oPoint, const double w, const double i, const double j, const double k) const;

 protected:
  double m_RadiusMax;
  double m_RadiusMaxX;
  double m_RadiusMaxY;
  double m_RadiusMaxZ;
  RotationType m_RotationType;
  CATPolyUniformRandomGenerator & m_Randomize;

  // Necessary for uniform extraction
  double m_jEquiX;
  double m_jEquiY;
  double m_jEquiZ;
};

#endif
