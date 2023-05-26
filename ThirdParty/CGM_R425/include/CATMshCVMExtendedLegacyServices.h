#ifndef CATMshCVMExtendedLegacyServices_h
#define CATMshCVMExtendedLegacyServices_h

#include "CATMshCVMLegacyServices.h"
#include "CATPolyBody.h"

#include <map>

class CATMshCVMExtendedLegacyServices : public CATMshCVMLegacyServices {
public:

    CATMshCVMExtendedLegacyServices() noexcept = default;
    ~CATMshCVMExtendedLegacyServices() = default;

    HRESULT ConvertPolyBodyToMesh(CATPolyBody* polyBody, context_t** legacyContext, mesh_t** legacyMesh, std::map<integer, CATPolyCell*>* bridgeID2PolyCell);
};


#endif
