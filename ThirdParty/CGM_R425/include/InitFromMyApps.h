#ifndef INITFROMMYAPPS_H
#define INITFROMMYAPPS_H

#include "JS0LIB.h"
#include "CATUnicodeString.h"


HRESULT ExportedByJS0LIB InitFromMyApps(CATUnicodeString &Tenant, CATUnicodeString &MyApps, CATUnicodeString &Url, int iOnPremise=0);
HRESULT ExportedByJS0LIB CreateDPCRTV();

#endif  //INITFROMMYAPPS_H
