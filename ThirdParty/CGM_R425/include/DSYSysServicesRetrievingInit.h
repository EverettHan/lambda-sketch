// COPYRIGHT DASSAULT SYSTEMES 2021
#ifndef DSYSysServicesRetrievingInit_H
#define DSYSysServicesRetrievingInit_H

#include "WebLogonPanel.h"
#include "JS0HTTP.h"   // ExportedByJS0HTTP

/////////////////////
//ONLY FOR SYSTEMTS//
/////////////////////
/**
* Initialize the singleton with no-CAS WS (3DRegistry: tenant ids, services URLs).
*/
ExportedByJS0HTTP bool DSYSysTenantDataSingletonInitNoCAS();
/**
* Initialize totally the singleton with no-CAS WS if not already initialized (3DRegistry: tenant ids, services URLs) and CAS WS (MyApps: tenant display name).
*/
ExportedByJS0HTTP bool DSYSysTenantDataSingletonInitCAS();
/////////////////////
/////////////////////

#endif  // DSYSysServicesRetrieving_H
