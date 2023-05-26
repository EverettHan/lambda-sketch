/* -*-c++-*- */
#ifndef CATImplicitResource_H
#define CATImplicitResource_H

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
#include "GMScalarFieldsObjects.h"
#include "GMScalarFieldsGeo.h"

// Lattice
#include "LatticeNBModel.h"

// CGM
#include "CATIACGMLevel.h"
#include "GMScalarFieldsGeo.h"                // ExportedBy
#include "CATCGMLISTPP_Declare.h"
#include "CATGMModelInterfaces.h"

enum ImplicitResourceOwnership { external, retain };

class ExportedByGMScalarFieldsGeo CATImplicitResource
{
  public:
    typedef std::unique_ptr<CATImplicitResource>            UPtr;
    typedef std::shared_ptr<CATImplicitResource>            Ptr;
    typedef std::vector<CATImplicitResource*>               RawPtrs;
    typedef std::vector<CATImplicitResource::Ptr>           Ptrs;
    typedef std::map<std::string, CATImplicitResource::Ptr> Map;

    CATImplicitResource();
    virtual ~CATImplicitResource();

    static  GUID GetImplicitResourceTypeS() { return SF::UndefinedResourceTypeGUID; }
  
    virtual GUID GetImplicitResourceType() { return SF::UndefinedResourceTypeGUID; }

    virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean& ioReversible) const = 0;
    virtual const CATCGMStreamVersion GetFirstStreamableVersion() const = 0;
    virtual void Stream(CATCGMStream& ioStream) = 0;
    virtual void UnStream(CATCGMStream& ioStream, CATLISTP(CATICGMObject)& iListOfDependencies) = 0;

  private:

};

/**
 * @collection CATLISTP(CATImplicitResource)
 * Collection class for raw pointers to implicit resources.
 * All the methods of pointer collection classes are available.
 * Refer to the articles dealing with collections in the encyclopedia.
 */
CATCGMLISTPP_DECLARE(CATImplicitResource);
typedef CATLISTP(CATImplicitResource) ListPOfCATImplicitResource;

#endif // !CATImplicitResource_H
