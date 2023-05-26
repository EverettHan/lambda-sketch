/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

/**
  * @level Protected
  * @usage U1
  */

#ifndef PMRPGPMigrationReservedServices_H
#define PMRPGPMigrationReservedServices_H
#include "CATObjectModelerBase.h"
#include "PLMPublicLinkFacade.h"
#include "sequence.h"
#include "sequence_octet.h"
#include "CATINamingContext.h"
#include "CATBaseUnknown.h"
#include "CATOmxSR.h"

class PLMPublicLinkFacade;

ExportedByCATObjectModelerBase HRESULT ExtractLinkInfoForPMRPGPMigration(PLMPublicLinkFacade & iLink, SEQUENCE(octet) & LigthName);
ExportedByCATObjectModelerBase HRESULT GetFeatureFromLinkInfoPMRPGPMigration(CATINamingContext*  iNamingContext, SEQUENCE(octet) & iLigthName, CATOmxSR<CATBaseUnknown>& oRes);

#endif
