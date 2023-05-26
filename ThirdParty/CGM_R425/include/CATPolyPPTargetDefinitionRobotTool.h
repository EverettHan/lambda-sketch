// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPDefinition.h
//
//===================================================================
//
// allow Tool Position as target for a full robot (InverseKin is required)
//===================================================================
//
// 2020-10-22 GH7: Creation 
//===================================================================

#ifndef CATPolyPPTargetDefinitionRobotTool_HH
#define CATPolyPPTargetDefinitionRobotTool_HH


#include "DSYExport.h"

#include "CATPolyPPTargetDefinitionBase.h"
#include "CATPolyPPPosition.h"

#include "CATCGMSharedPtr.h"
#include <vector>

#include "PPRobot.h"

/**
  
*/
class DSYExport CATPolyPPTargetDefinitionRobotTool: public CATPolyPPTargetDefinitionBase
{
public:
  CATPolyPPTargetDefinitionRobotTool(
    CATMathAxis  & iNewToolFramePosition,
    CATCGMSharedPtr<PPRobot> iRobot,
    CATCGMSharedPtr<PPRobotNodeModel> iTool, int iToolFrameIndex =-1);
   

  //TODO More specific that pos/rot only (mayby by axis)
  /**  
    if enable we only the positition is used to validate the postion , not the orientation
  */
  void SetModePositionOnly(bool iEnablePositionOnly=true );
  bool GetModePositionOnly()const;
  
  /**
    return true if iTargetProposal==iTarget pass to contructor
  */
  virtual bool IsValidTarget(const CATPolyPPPosition & iFromPosition, const CATPolyPPPosition & iTargetProposal,CATPolyPPConfigurationChecker *iCheckerFromThread=nullptr);

  /**
    return iTarget pass to constructor
  */
  virtual std::vector<CATCGMSharedPtr<CATPolyPPPosition>> GetValidTargetFrom(const CATPolyPPPosition & iFromPosition);
protected:
  CATMathAxis _FrameTarget;
  CATCGMSharedPtr< CATPolyPPPosition> _RobotTarget;

  CATCGMSharedPtr<PPRobot> _Robot = nullptr;
  CATCGMSharedPtr<PPRobotNodeModel> _ToolPart = nullptr;
  int _ToolFrameToMove = -1;

  bool _PositionOnly = false;
};


#endif
