#ifndef CATPolyPPTopologicalSpace1Dof_HH
#define CATPolyPPTopologicalSpace1Dof_HH
/**
 * \addtogroup PathPlanRobot
 * @{
 */
#include "PolyPathPlanning.h"
#include "DSYExport.h"


#include "CATMathInline.h"
#include "CATPolyPPTopologicalSpace.h"
#include "CATPolyConcentricIterator.h"

class CATPolyPPTopologicalPoint;
class CATPolyUniformRandomGenerator;

/**
* Implementation of the CATPolyPPTopologicalSpace for a space of dimension 1.
* This space can by use to represent the movement of dof associate to a robot joint.
* More specific implementation can be required for Rotation or translation in the future.
*/
class DSYExport CATPolyPPTopologicalSpace1Dof : public CATPolyPPTopologicalSpace
{
 public:
  CATPolyPPTopologicalSpace1Dof(CATPolyUniformRandomGenerator & iRandomGenerator);
  CATPolyPPTopologicalSpace1Dof( const CATPolyPPTopologicalSpace1Dof& iOther, CATPolyUniformRandomGenerator & iRandomGenerator );
  virtual ~CATPolyPPTopologicalSpace1Dof();

  //override method see the doc in original interface CATPolyPPTopologicalSpace

  virtual CATPolyPPTopologicalPoint * GetRandomPoint();
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const double * iMin, const double * iMax, double iTolerance);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iNeighborhood);
  virtual CATPolyPPTopologicalPoint * GetRandomPoint(const CATPolyPPTopologicalPoint * iRef, double iMinimumRadius, double iMaximumRadius,  CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);
  virtual CATPolyPPTopologicalPoint * GetPoint(const CATPolyPPTopologicalPoint * iRef, double iRadius,  CATPolyConcentricIterator* Iterator, double iRotationMode, double & oJequi, double * v_rotation);

  virtual double SqDistance(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2) const;
  virtual double SqDistanceInterval(unsigned int iDim, double iRef, double iInf, double iSup) const;
  virtual CATPolyPPTopologicalPoint * Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam);
  virtual void Interpolate(const CATPolyPPTopologicalPoint & iPoint1, const CATPolyPPTopologicalPoint & iPoint2, double iParam, CATPolyPPTopologicalPoint& ioPoint);
  virtual HRESULT ClampToLimits(CATPolyPPTopologicalPoint & ioPoint) const;

  virtual CATPolyPPTopologicalSpace1Dof* Clone(CATPolyUniformRandomGenerator & iRandomGenerator) const;
  virtual CATPolyPPTopologicalSpace* Clone() const;

 private:
  CATPolyUniformRandomGenerator & _Randomize;
};
/**   @} */
#endif
