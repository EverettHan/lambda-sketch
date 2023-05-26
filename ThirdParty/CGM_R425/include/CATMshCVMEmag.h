#ifndef CATMshCVMEmag_h
#define CATMshCVMEmag_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMEmag.h"
#include "ListPOfCATBody.h"

/**
 * CVMEmag API
 * Performs resilient meshing for Emag use cases.
*/
class ExportedByCATMshCVMEmag CATMshCVMEmag : protected CATMshCVM{

public:

    explicit CATMshCVMEmag() noexcept;
    virtual ~CATMshCVMEmag();
    CATMshCVMEmag& operator=(CATMshCVMEmag&&) noexcept = default;

    HRESULT Init(CATListPtrCATBody& listOfBodies);
    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;
    using CATMshCVM::SetVerbose;

    using CATMshCVM::SetSurfaceMinSize;
    using CATMshCVM::SetSurfaceMaxSize;

    using CATMshCVM::SetSurfaceMinEdgeLength;

    using CATMshCVM::SetNumericalResolution;
    using CATMshCVM::SetIdealisationTolerance;

    using CATMshCVM::SetHoleSize;
    using CATMshCVM::SetRemoveInternalSurfaces;
    using CATMshCVM::SetAvoidExternalSurfaces;

    void SetGapSize(const double gapSize);

    /**
     * Generate a mesh.
     *  @return
     *   A HRESULT.
     */
    virtual HRESULT Mesh();

    /**
     * Get the generated mesh.
     * @return
     *   The mesh.
     */
    virtual CATIMshMesh* GetMesh();

private:
    HRESULT ComputeBbox();

protected:

    HRESULT Import(CATBody* body);

    double _bbox[6];
    double _lmax;
};

#endif
