#ifndef CATCDSMODIF_H
#define CATCDSMODIF_H
#if !defined(_EMSCRIPTEN_SOURCE)
// COPYRIGHT DASSAULT SYSTEMES 2014

#include "CDSMathInfra.h"
#include "CATBaseUnknown.h"

class CATSoftwareConfiguration;
class CATSoftwareModification;


// Retrieves the CDS level of the code to run.
ExportedByCATCDSMathInfra short GetCDSLevel(CATSoftwareConfiguration* iConfig);

// Retrieves the CDS HF level of the code to run.
ExportedByCATCDSMathInfra short GetCDSHFLevel(CATSoftwareConfiguration* iConfig);

// Force the current CDS Level for the CDS Modification in a given SoftwareConfiguration.
ExportedByCATCDSMathInfra void ForceCurrentCDSLevelInSoftwareConfiguration(CATSoftwareConfiguration* iConfig);

// Updates of a configuration by a CGM modification.
ExportedByCATCDSMathInfra void CATCDSUpdateConfiguration(CATSoftwareConfiguration* iConfig);

#endif
#endif
