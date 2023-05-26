// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPTopologicalSpaceR3.h
//
//===================================================================
//
// Usage notes: Description of the topological spaces representing
// translations in R^3.
//
//===================================================================
//
// 2013-02-06 XXC: Creation
// 2013-10-07 JXO: Clamp method
// 2017-01-26 JXO: New GetRandomPoint methods
//===================================================================

#ifndef CATPolyPPTopologicalSpaceR3_HH
#define CATPolyPPTopologicalSpaceR3_HH

#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATPolyPPTopologicalSpace.h"
#include "CATPolyNormalRandomGenerator.h"
#include "CATPolyConcentricIterator.h"
#include "CATMath.h"

class CATPolyUniformRandomGenerator;
class CATPolyPPTopologicalPoint;

/**
 * Description of the topological spaces representing
 * translations in R^3.
 * */
class ExportedByPolyPathPlanning CATPolyPPTopologicalSpaceR3 : public CATPolyPPTopologicalSpace
{
public:
  CATPolyPPTopologicalSpaceR3(CATPolyUniformRandomGenerator & iRandomGenerator);
  CATPolyPPTopologicalSpaceR3( const CATPolyPPTopologicalSpaceR3& iOther, CATPolyUniformRandomGenerator & iRandomGenerator );
  virtual ~CATPolyPPTopologicalSpaceR3();

  virtual CATPolyPPTopologicalPoint * GetRandomPoint();
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);
  virtual CATPolyPPTopologicalPoint * GetPoint(const CATPolyPPTopologicalPoint * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);
  virtual double SqDistance(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2) const;
  virtual double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const;
  virtual CATPolyPPTopologicalPoint * Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam);
  virtual void Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam, CATPolyPPTopologicalPoint& ioPoint);
  
  virtual HRESULT ClampToLimits(CATPolyPPTopologicalPoint & ioPoint) const;

  virtual CATPolyPPTopologicalSpaceR3* Clone( CATPolyUniformRandomGenerator & iRandomGenerator ) const;
  virtual CATPolyPPTopologicalSpace* Clone() const ;

  INLINE void SetMaximumRadius(double iRadiusMaxX, double iRadiusMaxY, double iRadiusMaxZ)
  {
    m_jEquiX = CATSqrt(iRadiusMaxZ*iRadiusMaxZ+iRadiusMaxY*iRadiusMaxY);
    m_jEquiY = CATSqrt(iRadiusMaxZ*iRadiusMaxZ+iRadiusMaxX*iRadiusMaxX);
    m_jEquiZ = CATSqrt(iRadiusMaxX*iRadiusMaxX+iRadiusMaxY*iRadiusMaxY);
  }

protected:
  CATPolyUniformRandomGenerator & _Randomize;
  CATPolyNormalRandomGenerator _NormalRandomize;

  double m_jEquiX;
  double m_jEquiY;
  double m_jEquiZ;
};

#endif
