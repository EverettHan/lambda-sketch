#ifndef CATMshCVMTetMesher_h
#define CATMshCVMTetMesher_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMTetMesher.h"

class ExportedByCATMshCVMTetMesher CATMshCVMTetMesher : protected CATMshCVM{

public:

    CATMshCVMTetMesher(CATIMshMesh &mesh);
    virtual ~CATMshCVMTetMesher();

    HRESULT Init();
    using CATMshCVM::Release;

    void SetGradation(double volumeGradation);

    virtual HRESULT Mesh();

private:
    CATIMshMesh &_mesh;
};

#endif
