#ifndef CATMshCVMFmkMainstream_h
#define CATMshCVMFmkMainstream_h

#include "CATMshCVMFmkGeneralPurpose.h"
#include "ExportedByCATMshCVMFmkMainstream.h"

enum class ExportedByCATMshCVMFmkMainstream CATMshCVMFmkMainstreamRefinement{
	Coarse,
	Medium,
	Fine
};

class ExportedByCATMshCVMFmkMainstream CATMshCVMFmkMainstream : protected CATMshCVMFmkGeneralPurpose{

public:

    explicit CATMshCVMFmkMainstream() noexcept;
    virtual ~CATMshCVMFmkMainstream();
    CATMshCVMFmkMainstream& operator=(CATMshCVMFmkMainstream &&) noexcept = default;

    HRESULT Init(CATListPtrCATBody &listOfBody);
    using CATMshCVMFmkGeneralPurpose::Release;

    using CATMshCVMFmkGeneralPurpose::SetInterruptCallback;
    using CATMshCVMFmkGeneralPurpose::SetMessageCallback;

    using CATMshCVMFmkGeneralPurpose::SetResilientInsertion;

    using CATMshCVMFmkGeneralPurpose::SetVerbose;

    void SetRefinement(CATMshCVMFmkMainstreamRefinement refinement);
    using CATMshCVMFmkGeneralPurpose::SetMaxSize;

    CATMshCVMFmkMainstreamRefinement GetRefinement();
    using CATMshCVMFmkGeneralPurpose::GetMaxSize;

    using CATMshCVMFmkGeneralPurpose::AddSphereSizeConstraint;
    using CATMshCVMFmkGeneralPurpose::AddCylinderSizeConstraint;
    using CATMshCVMFmkGeneralPurpose::AddCubeSizeConstraint;

    HRESULT AddSurfaceGeometricConstraint(CATEdge *edge, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATFace *face, const double maxSize);

    HRESULT AddFluidDomain(CATBody *body);
    HRESULT AddFluidDomain(CATVolume *volume);
    HRESULT AddFluidDomain(CATFace *face, CATSide side);
    HRESULT AddFluidDomain(CATLISTP(CATFace) &listOfFace, CATListOfInt &listOfSide);

    HRESULT AddMRFDomain(CATVolume *volume);

    HRESULT AddDomain(CATVolume *volume, const bool toKeep);
    HRESULT AddDomain(CATBody *body, const bool toKeep);

    using CATMshCVMFmkGeneralPurpose::Mesh;

    virtual CATIMshMesh* GetMesh() override;
    virtual CATIMshMesh* GetMesh(CATVolume *volume) override;
    virtual CATIMshMesh* GetMesh(CATFace *face, CATSide side) override;
    virtual CATIMshMesh* GetMesh(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides) override;
    virtual CATIMshMesh* GetMesh(CATFace *face) override;
    virtual CATIMshMesh* GetMesh(CATEdge *edge) override;
    virtual CATIMshMesh* GetMesh(CATVertex *vertex) override;

    CATMshCVMFmkGeneralPurpose* GetCVMGeneralPurpose();

private:

    CATMshCVMFmkMainstreamRefinement _refinement;
};

#endif
