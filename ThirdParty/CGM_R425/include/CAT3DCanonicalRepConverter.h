#ifndef CAT3DCanonicalRepConverter_h_
#define CAT3DCanonicalRepConverter_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"

// SpecialAPI (PublicInterfaces)
#include "CATSysErrorDef.h"

class CATRep;
class CATSurfacicRep;
class CAT3DCanonicalRep;

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

class ExportedBySGInfra CAT3DCanonicalRepConverter
{
public:
    static HRESULT ConvertToSurfacicRep(CAT3DCanonicalRep& iCanonicalRep, CATSurfacicRep*& oSurfacicRep, const bool iWithEdges = false);
    static HRESULT ConvertToSurfacicRepWithTopology(CAT3DCanonicalRep& iCanonicalRep, CATSurfacicRep*& oSurfacicRep, const bool iWithEdges = false);
    /** Will call either ConvertToSurfacicRep or ConvertToSurfacicRepWithTopology depending on SGUseCanonicalReps current values. */
    static HRESULT ConvertToSurfacicRepAccordingToSettings(const int iConversionMode, CAT3DCanonicalRep& iCanonicalRep, CATSurfacicRep*& oSurfacicRep);

    static HRESULT ConvertToCanonicalRep(CATRep& iRep, CAT3DCanonicalRep*& oCanonicalRep);
};

#endif // !CAT3DCanonicalRepConverter_h_
