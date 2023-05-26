#ifndef CATWBUtilities_H
#define CATWBUtilities_H

#include "WBUtilities.h"
#include "CATIAV5Level.h"
#include "CATIACGMLevel.h"

#if   defined(CATIAV5R23)  ||  defined(CATIAR214) 
class CATSoftwareConfiguration;
class CATWBManager;
#ifdef CATIACGMR418Code
class CATWBFactory;
class CATWBModel;
#endif

//-----------------------------------------------------------------------

class ExportedByWBUtilities CATWBUtilities
{
public:
  //static CATWBManager* CreateWBManager(CATSoftwareConfiguration *ipSoftwareConfiguration);
  //static int SolveWBxSystem(CATSoftwareConfiguration *ipSoftwareConfiguration, CATWBManager* iManager);


#ifdef CATIACGMR418Code
  static CATWBFactory* CreateWBFactory(CATSoftwareConfiguration *ipSoftwareConfiguration);
  //static CATWBModel* CreateWBModel(CATSoftwareConfiguration *ipSoftwareConfiguration);
#endif
};
#endif
#endif
