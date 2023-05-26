#ifndef CATMshCVMEmagFusion_h
#define CATMshCVMEmagFusion_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMEmagFusion.h"

/**
 * CVMEmagFusion API
 * Performs resilient meshing for Emag Fusion use cases.
*/
class ExportedByCATMshCVMEmagFusion CATMshCVMEmagFusion : protected CATMshCVM{

public:

    explicit CATMshCVMEmagFusion() noexcept;
    virtual ~CATMshCVMEmagFusion();
    CATMshCVMEmagFusion& operator=(CATMshCVMEmagFusion &&) noexcept = default;

    HRESULT Init(CATIMshMesh *mesh);
    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;
    using CATMshCVM::SetVerbose;

    using CATMshCVM::SetSurfaceMinSize;
    using CATMshCVM::SetSurfaceMaxSize;

    using CATMshCVM::SetSurfaceMinEdgeLength;

    using CATMshCVM::SetIdealisationTolerance;

    using CATMshCVM::SetWrapSurfaceTag;
    using CATMshCVM::SetHoleSize;
    using CATMshCVM::SetRemoveInternalSurfaces;
    using CATMshCVM::SetAvoidExternalSurfaces;
    using CATMshCVM::SetSmoothWrapSurface;
    using CATMshCVM::SetWrapSmoothSurfaceAngle;
    using CATMshCVM::SetWrapSmoothSurfaceEffort;
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

};

#endif
