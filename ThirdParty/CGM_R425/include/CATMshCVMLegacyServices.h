#ifndef CATMshCVMLegacyServices_h
#define CATMshCVMLegacyServices_h

#include "CATIMshMesh.h"
#include "CATIMshMesher.h"
#include "ExportedByCATMshCVMCore.h"
#include "CATSysErrorDef.h"

extern "C" {
#include <meshgems/meshgems.h>
}

class ExportedByCATMshCVMCore CATMshCVMLegacyServices{
public:

    CATMshCVMLegacyServices() noexcept = default;
    ~CATMshCVMLegacyServices() = default;

    CATIMshMesh* ConvertLegacyMesh(mesh_t *legacyMesh);
    HRESULT ConvertMeshToLegacyMesh(CATIMshMesh *mesh,
            context_t *&oLegacyContext, mesh_t *&oLegacyMesh);
};

status_t CATMshCVMLegacyMessageCallback(message_t *msg, void *user_data);
status_t CATMshCVMLegacyInterruptCallback(integer *interrupt_status, void *user_data);

#endif
