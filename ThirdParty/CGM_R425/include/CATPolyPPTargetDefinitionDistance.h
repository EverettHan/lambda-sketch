// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPDefinition.h
//
//===================================================================
//
// introduce new Target defintion class because CATPolyPPPosition  is too strict and too related to the carthesian space
// may some user want have a big ndof carthesian space (n robot dof ) but the target will only use the tool head position (3 dof x,y,z) the rest of the dof can be free.
//
//===================================================================
//
// GH7 : associate to task TSK7134666 Target Area for Path Planning https://dsxdev-online.dsone.3ds.com/enovia/common/emxNavigator.jsp?physicalId=622CB056E03F00006011988E001922C4
// 2020-09-14 GH7: Creation 
//===================================================================

#ifndef CATPolyPPTargetDefinitionDistance_HH
#define CATPolyPPTargetDefinitionDistance_HH

#include "PolyPathPlanning.h"
#include "CATPolyPPTargetDefinitionBase.h"
#include "CATPolyPPPosition.h"
//#include "CATPolyDeprecated.h"
#include "CATCGMSharedPtr.h"
#include <vector>

/**
  Implementation that will validate all configuration that are near the target, the distance 
  to the target must be less than a user parameter.
*/
class ExportedByPolyPathPlanning CATPolyPPTargetDefinitionDistance: public CATPolyPPTargetDefinitionBase
{
public:
  CATPolyPPTargetDefinitionDistance(CATCGMSharedPtr< CATPolyPPPosition> & iTarget, double iDistance=0);

  /**
    return true if iTargetProposal==iTarget pass to contructor
  */
  virtual bool IsValidTarget(const CATPolyPPPosition & iFromPosition, const CATPolyPPPosition & iTargetProposal,CATPolyPPConfigurationChecker *iCheckerFromThread);

  /**
    return iTarget pass to constructor
  */
  virtual std::vector<CATCGMSharedPtr<CATPolyPPPosition>> GetValidTargetFrom(const CATPolyPPPosition & iFromPosition);


  /**
   * if this mode is activate IsValidTarget will try add a segment to reach iTarget.
   * @param iEnable enable/disable the last segment mode
   * */
  void SetValidLastSegment(bool iEnable=true);
  bool GetValidLastSegment() const ;
protected:
  CATCGMSharedPtr< CATPolyPPPosition> _Target = nullptr;

  double _Distance=0;
  bool _ValidLastSegment=false;
};


#endif
