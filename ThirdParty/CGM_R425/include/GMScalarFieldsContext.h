/* -*-c++-*- */
#ifndef GMScalarFieldsContext_H
#define GMScalarFieldsContext_H

// COPYRIGHT DASSAULT SYSTEMES  2021
//=============================================================================
//
// CATGeoImplicitSurface:
// implementation of the CATGeoImplicitSurface interface in the CGM Modeler
//
//=============================================================================
// Usage Notes:
//
//=============================================================================
// Nov. 2021 Creation from CATGMPolySurface                                WZC
//=============================================================================

// STD
#include <vector>
#include <memory>

// CGM
// Stream
#include "CATCGM_STREAM.h"
#include "CATCGMStream.h"
#include "CATCGMStreamImpl.h"
#include "CATCGMStreamVersion.h"
#include "CATCGMStreamVersionLimited.h" // CatCGMStream_2022Fall
#include "CATMathStreamImpl.h" // CATCGMStreamIsNewerThanOrEqualTo
#include "CATCGMStreamAttrData.h"

// ScalarFields
#include "SFTypes.h"
#include "SFSWContext.h"
#include "GMScalarFieldsObjects.h"
#include "GMScalarFieldsGeo.h"

// Lattice
#include "LatticeNBModel.h"

// CGM
#include "CATIACGMLevel.h"
#include "GMScalarFieldsGeo.h"                // ExportedBy
#include "CATCGMLISTPP_Declare.h"
#include "CATGMModelInterfaces.h"

class ExportedByGMScalarFieldsGeo GMScalarFieldsContext : public SF::SFSWContext
{
  public:
    GMScalarFieldsContext();
    virtual ~GMScalarFieldsContext();

  private:
};

typedef std::unique_ptr<GMScalarFieldsContext>            GMScalarFieldsContextUPtr;
typedef std::shared_ptr<GMScalarFieldsContext>            GMScalarFieldsContextPtr;

#endif // !GMScalarFieldsContext_H
