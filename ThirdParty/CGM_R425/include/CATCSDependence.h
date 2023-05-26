// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// CATCSDependence.h
// Header definition of CATCSDependence
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Aug 2004  Creation:                Evgueni ROUKOLEEV
//===================================================================
#ifndef CATCSDependence_H
#define CATCSDependence_H

#include "CATCDSVirtual.h"
#include "CATCDS.h"
#include "CATCSGeomConstraint.h"

//-----------------------------------------------------------------------

class ExportedBySolverInterface CATCSDependence : public CATCSGeomConstraint
{
public:
  CATCSDependence();
  virtual ~CATCSDependence();

  // An application should never re-define this method.
  virtual CATCSType GetType() const CATCDSOverride;
  virtual CATCDSBoolean IsMatched(CATCSType iType) const CATCDSOverride;
};

//-----------------------------------------------------------------------

#endif
