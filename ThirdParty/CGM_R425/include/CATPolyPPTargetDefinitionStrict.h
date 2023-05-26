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
// 2020-09-14 GH7: Creation 
//===================================================================

#ifndef CATPolyPPDefinitionTargetStrict_HH
#define CATPolyPPDefinitionTargetStrict_HH

#include "PolyPathPlanning.h"
#include "CATPolyPPTargetDefinitionBase.h"
#include "CATPolyPPPosition.h"
//#include "CATPolyDeprecated.h"
#include "CATCGMSharedPtr.h"
#include <vector>

/**
  Implementation very strict (old mode) that valid a target only if it is equal to
  a CATPolyPPPosition
*/
class ExportedByPolyPathPlanning CATPolyPPTargetDefinitionStrict: public CATPolyPPTargetDefinitionBase
{
public:
  CATPolyPPTargetDefinitionStrict(CATCGMSharedPtr< CATPolyPPPosition> & iTarget);
  /**
    return true if iTargetProposal==iTarget pass to contructor
  */
  virtual bool IsValidTarget(const CATPolyPPPosition & iFromPosition, const CATPolyPPPosition & iTargetProposal,CATPolyPPConfigurationChecker *iCheckerFromThread=nullptr);

  /**
    return iTarget pass to constructor
  */
  virtual std::vector<CATCGMSharedPtr<CATPolyPPPosition>> GetValidTargetFrom(const CATPolyPPPosition & iFromPosition);
protected:
  CATCGMSharedPtr< CATPolyPPPosition> _Target;
};


#endif
