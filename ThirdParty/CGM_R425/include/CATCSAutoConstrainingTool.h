// COPYRIGHT Dassault Systemes 2006
//===================================================================
//
// CATCSAutoConstrainingTool.h
// Header definition of CATCSAutoConstrainingTool
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jan 2006  Creation                       Ilia IVANOV
//===================================================================

#ifndef CATCSAutoConstrainingTool_H
#define CATCSAutoConstrainingTool_H

#include "CATCDS.h"

class CATCSConstraintDescr;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSAutoConstrainingTool
{
public:
  CATCSAutoConstrainingTool();
  virtual ~CATCSAutoConstrainingTool();

  virtual double GetWeight(CATCSConstraintDescr *ipConstraint) = 0;
};

//-----------------------------------------------------------------------

#endif
