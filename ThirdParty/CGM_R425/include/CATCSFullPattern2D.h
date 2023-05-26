// COPYRIGHT Dassault Systemes 2015
//===================================================================
//
// CATCSFullPattern2D.h
// Header definition of CATCSFullPattern2D
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Nov 2015  Creation                 TE9
//===================================================================

#ifndef CATCSFullPattern2D_H
#define CATCSFullPattern2D_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSPattern.h"

class CATCSAxis2D;

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSFullPattern2D : public CATCSPattern
{
public:
  CATCSFullPattern2D();

  virtual ~CATCSFullPattern2D();

  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
};

//-----------------------------------------------------------------------

#endif
