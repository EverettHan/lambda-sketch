#ifndef CATMshCVMAdapt_h
#define CATMshCVMAdapt_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMAdapt.h"

class ExportedByCATMshCVMAdapt CATMshCVMAdapt : protected CATMshCVM{

public:

    // FIXME
    CATMshCVMAdapt();
    virtual ~CATMshCVMAdapt();

    HRESULT Init();
    using CATMshCVM::Release;

    virtual HRESULT Mesh();
};

#endif
