// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPTopologicalSpaceR2.h
//
//===================================================================
//
// Usage notes: Description of the topological spaces representing
// Translation in R^2.
//
//===================================================================
//
// 2013-02-13 XXC: Creation
// 2013-10-07 JXO: Clamp method
// 2017-01-26 JXO: New GetRandomPoint methods
//===================================================================

#ifndef CATPolyPPTopologicalSpaceR2_HH
#define CATPolyPPTopologicalSpaceR2_HH

#include "PolyPathPlanning.h"
#include "CATMathInline.h"
#include "CATPolyPPTopologicalSpace.h"
#include "CATPolyConcentricIterator.h"

class CATPolyUniformRandomGenerator;
class CATPolyPPTopologicalPoint;
/**
 * Description of the topological spaces representing
 * Translation in R^2.
 * */
class ExportedByPolyPathPlanning CATPolyPPTopologicalSpaceR2 : public CATPolyPPTopologicalSpace
{
public:
  CATPolyPPTopologicalSpaceR2(CATPolyUniformRandomGenerator & iRandomGenerator);
  CATPolyPPTopologicalSpaceR2( const CATPolyPPTopologicalSpaceR2& iOther, CATPolyUniformRandomGenerator & iRandomGenerator );
  virtual ~CATPolyPPTopologicalSpaceR2();

  virtual CATPolyPPTopologicalPoint * GetRandomPoint();
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);

  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iMinimumRadius, double iMaximumRadius,CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);
  virtual CATPolyPPTopologicalPoint * GetPoint(const CATPolyPPTopologicalPoint * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);

  virtual double SqDistance(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2) const;
  virtual double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const;
  virtual CATPolyPPTopologicalPoint * Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam);
  virtual void Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam, CATPolyPPTopologicalPoint& ioPoint);

  virtual HRESULT ClampToLimits(CATPolyPPTopologicalPoint & ioPoint) const;

  virtual CATPolyPPTopologicalSpaceR2* Clone( CATPolyUniformRandomGenerator & iRandomGenerator ) const;
  virtual CATPolyPPTopologicalSpace* Clone() const ;
private:
  CATPolyUniformRandomGenerator & _Randomize;
};

#endif
