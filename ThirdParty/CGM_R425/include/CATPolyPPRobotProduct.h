
#ifndef CATPolyPPRobotProduct_HH
#define CATPolyPPRobotProduct_HH
/**
 *  \addtogroup PathPlanRobot
 *  @{ */
#include "CATPolyPPCartesianProduct.h"

/**
 * Specific implementation of CATPolyPPCartesianProduct used by CATPolyPPRobotChecker.
 */
class DSYExport CATPolyPPRobotProduct : public CATPolyPPCartesianProduct
{
public:

  CATPolyPPRobotProduct(CATListPV & iListOfTopoSpaces, CATPolyPPConfigurationDistance * pDistance);

  //override methods , see doc in the original interface CATPolyPPCartesianProduct

  CATPolyPPPosition * GetRandomPosition() const;
  CATPolyPPPosition * GetRandomPosition(const double ** iLimits, double iTolerance) const;
  CATPolyPPPosition * GetRandomPosition(CATPolyPPPosition * iRef, double iNeighborhood) const;
  virtual CATPolyPPPosition * GetRandomPosition(CATPolyPPPosition * iRef, double iMinimumRadius, double iMaximumRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;
  virtual CATPolyPPPosition * GetPosition( CATPolyPPPosition * iRef, double iRadius, CATPolyConcentricIterator* Iterator, double iRotationMode) const;

  CATPolyPPPosition** Interpolate(const CATPolyPPPosition& iPoint1, const CATPolyPPPosition& iPoint2, double iDistMax, unsigned int& oNbSteps, bool iCDIST) const;
  CATPolyPPPosition ** Interpolate(const CATPolyPPPosition & iPoint1, const CATPolyPPPosition & iPoint2, unsigned int iNbSteps) const;


  ~CATPolyPPRobotProduct()=default;
protected:
  int _currentDof=0;
};
/**   @} */
#endif
