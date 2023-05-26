/* -*-c++-*- */
#ifndef CATGMBarGraph_H
#define CATGMBarGraph_H

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

// System
#include "IUnknown.h"

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
#include "ScalarFieldUtils.h"
#include "ScalarFieldsOperatorsCommon.h"
#include "GMScalarFieldsObjects.h"
#include "GMScalarFieldsGeo.h"

// Lattice
#include "LatticeNBModel.h"

// CGM
#include "CATIACGMLevel.h"

// Gm Scalar Fields
#include "GMScalarFieldsGeo.h"                // ExportedBy
#include "CATImplicitResource.h"

class ExportedByGMScalarFieldsGeo CATGMBarGraph : public CATImplicitResource
{
  public:
    typedef std::unique_ptr<CATGMBarGraph>      UPtr;
    typedef std::shared_ptr<CATGMBarGraph>      Ptr;
    typedef std::vector<CATGMBarGraph::Ptr>     Ptrs;

    CATGMBarGraph();
    CATGMBarGraph(ImplicitResourceOwnership iOwnerShip );
    CATGMBarGraph(SF::LatticeNBModelPtr iLatticeNBModel);
    virtual ~CATGMBarGraph();

    void Clear();

    static  GUID GetImplicitResourceTypeS();

    static  CATGMBarGraph* SafeCast(CATImplicitResource* iImplicitResource);

    virtual GUID GetImplicitResourceType();

    void SetLatticeNBModel(SF::LatticeNBModelPtr iLatticeNBModel) { _latticeNBModel = iLatticeNBModel; }
    SF::LatticeNBModelPtr GetLatticeNBModel() { return _latticeNBModel; }

		virtual CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean& ioReversible) const;
		virtual const CATCGMStreamVersion GetFirstStreamableVersion() const;

    virtual void Stream(CATCGMStream& ioStream);
    virtual void UnStream(CATCGMStream& ioStream, CATLISTP(CATICGMObject)& iListOfDependencies);
    virtual void UnStream(CATCGMStream& ioStream);

  private:
    SF::LatticeNBModelPtr           _latticeNBModel;
};

#endif // !CATGMBarGraph_H
