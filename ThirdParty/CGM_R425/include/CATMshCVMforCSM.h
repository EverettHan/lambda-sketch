#ifndef CATMshCVMforCSM_h
#define CATMshCVMforCSM_h

#include "CATMshCVMCore.h"
#include "ExportedByCATMshCVMforCSM.h"

class ExportedByCATMshCVMforCSM CATMshCVMforCSM : public CATMshCVMCore{

public:

    HRESULT SetInputMesh(CATIMshMesh&);
    HRESULT Mesh();
    CATIMshMesh* GetMesh();
};

#endif
