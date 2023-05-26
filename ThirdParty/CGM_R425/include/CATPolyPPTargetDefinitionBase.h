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

#ifndef CATPolyPPDefinitionTargetBase_HH
#define CATPolyPPDefinitionTargetBase_HH

#include "PolyPathPlanning.h"
#include "CATPolyPPPosition.h"
//#include "CATPolyDeprecated.h"
#include "CATCGMSharedPtr.h"
#include <vector>

class CATPolyPathPlanningSolver;
class CATPolyPPConfigurationChecker;

class ExportedByPolyPathPlanning CATPolyPPTargetDefinitionBase: public CATPolyRefCounted
{
public:
  /**
    @brief return true if iTargetProposal is a valid target 
    @param[in] iFromPosition the position parent of the iTargetProposal (can be used or not for the validation)
    @param[in] iTargetProposal the configuration to validate

    @remarks : must be override by user
  */
  virtual bool IsValidTarget(const CATPolyPPPosition & iFromPosition, const CATPolyPPPosition & iTargetProposal, CATPolyPPConfigurationChecker *iCheckerFromThread=nullptr) = 0;

  /**
    @brief return a list that contains valid target from  iFromPosition
    @remarks : must be override by user
  */
  virtual std::vector<CATCGMSharedPtr<CATPolyPPPosition>> GetValidTargetFrom(const CATPolyPPPosition & iFromPosition) = 0;

  /**
   * will be used when this TargetDefinition will be associate to a solver 
   **/
  INLINE void SetSolver(CATPolyPathPlanningSolver * iSolver);
  INLINE CATPolyPathPlanningSolver * GetSolver() const;

  protected:
  CATPolyPathPlanningSolver *_Solver=nullptr;

};

void CATPolyPPTargetDefinitionBase::SetSolver(CATPolyPathPlanningSolver * iSolver)
{
  _Solver=iSolver;
}

CATPolyPathPlanningSolver * CATPolyPPTargetDefinitionBase::GetSolver() const
{
  return _Solver;
}


#endif
