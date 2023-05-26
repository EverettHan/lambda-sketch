/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2013
//-----------------------------------------------------------------------------

#ifndef CATOmyIncidentInhibitor_H
#define CATOmyIncidentInhibitor_H

#include "CATOmyIncidentCollect.h"
#include "CATSysBoolean.h"

/**
* Declare this class instance on the stack to locally inhibit CATIOmyIncidentCell
* error creation into CATIOmyIncidentCollector.
* inhibition is reset at the end of this instance scope.
*/

class ExportedByCATOmyIncidentCollect CATOmyIncidentInhibitor
{
public :

  CATOmyIncidentInhibitor();
  ~CATOmyIncidentInhibitor();
  static CATBoolean IsActive();
};

//-----------------------------------------------------------------------

#endif
