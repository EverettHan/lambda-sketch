// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSLinearPattern.h
// Header definition of CATCSLinearPattern
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation                 Nikolay SNYTNIKOV
//===================================================================

#ifndef CATCSLinearPattern_H
#define CATCSLinearPattern_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSPattern.h"

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSLinearPattern : public CATCSPattern
{
public:
  CATCSLinearPattern();

  virtual ~CATCSLinearPattern();

  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
};

//-----------------------------------------------------------------------

#endif
