// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATCSCircularPattern.h
// Header definition of CATCSCircularPattern
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Jul 2009  Creation                 Nikolay SNYTNIKOV
//===================================================================

#ifndef CATCSCircularPattern_H
#define CATCSCircularPattern_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSPattern.h"

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSCircularPattern : public CATCSPattern
{
public:
  CATCSCircularPattern();

  virtual ~CATCSCircularPattern();

  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
};

//-----------------------------------------------------------------------

#endif
