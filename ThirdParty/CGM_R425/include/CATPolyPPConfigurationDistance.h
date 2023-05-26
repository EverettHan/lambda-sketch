// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPConfigurationDistance.h
//
//===================================================================
//
// Usage notes: Abstract distance between configuration positions
//
//===================================================================
//
// 2013-09-25 JXO: Creation
//===================================================================

#ifndef CATPolyPPConfigurationDistance_HH
#define CATPolyPPConfigurationDistance_HH

#include "PolyPathPlanning.h"

class CATPolyPPPosition;

// Math
#include "CATBoolean.h"
#include "CATErrorDef.h"

/** Class defining the Configuration distance interface.
 */
class ExportedByPolyPathPlanning CATPolyPPConfigurationDistance
{
public:
  /**
   * Returns the square distance from first configuration (iConfig1) to second configuration (iConfig2),
   * @param iConfig1: the first configuration of moving objects.
   * @param iConfig2: the second configuration of moving objects.
   * @param ioSquareDistance: square distance
   * @return E_FAIL if computation failed, S_OK otherwise
   */
  virtual HRESULT SquareDistance(const CATPolyPPPosition & iConfig1, const CATPolyPPPosition & iConfig2, double& ioSquareDistance) = 0;

  virtual ~CATPolyPPConfigurationDistance(){}
protected:
  CATPolyPPConfigurationDistance(){}
  

    friend class DDRRTThread;
};

#endif
