#ifndef CATWBxUtilities_H
#define CATWBxUtilities_H

#include "CATIAV5Level.h"

// FCX 04.2021 : removed in CXR32/R424
#if !defined(CATIAV5R32) && !defined(CATIAR424)

#include "WBxUtilities.h"

class CATSoftwareConfiguration;
class CATWBFactory;

//-----------------------------------------------------------------------

class ExportedByWBxUtilities CATWBxUtilities
{
public:
  static CATWBFactory* CreateWBFactory(CATSoftwareConfiguration *ipSoftwareConfiguration);
};

#endif
#endif
