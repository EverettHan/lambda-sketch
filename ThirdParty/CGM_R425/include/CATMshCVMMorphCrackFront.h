#ifndef CATMshCVMMorphCrackFront_h
#define CATMshCVMMorphCrackFront_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMMorphCrackFront.h"

/**
 * CVMMorphCrackFront API
 * Performs mesh morphing of the crack front.
*/
class ExportedByCATMshCVMMorphCrackFront CATMshCVMMorphCrackFront : protected CATMshCVM{

public:

    explicit CATMshCVMMorphCrackFront() noexcept;
    virtual ~CATMshCVMMorphCrackFront();
    CATMshCVMMorphCrackFront& operator=(CATMshCVMMorphCrackFront &&) noexcept = default;

    HRESULT Init(CATIMshMesh *mesh);
    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;
    using CATMshCVM::SetVerbose;

    using CATMshCVMCore::SetSurfaceGradation;
    using CATMshCVMCore::SetVolumeGradation;
    
    using CATMshCVMCore::SetNumberOfSubdomains;

    /**
     * Generate a mesh.
     *  @return
     *   A HRESULT.
     */
    virtual HRESULT Mesh();

     /**
     * Generate a mesh.
     *  @return
     *   A HRESULT.
     */   
    virtual HRESULT UpdateMesh();

    /**
     * Get the generated mesh.
     * @return
     *   The mesh.
     */
    virtual CATIMshMesh* GetMesh();

};

#endif
