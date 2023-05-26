#ifndef CATMshCVMFmkIndustrySpecialized_h
#define CATMshCVMFmkIndustrySpecialized_h

#include "CATMshCVM.h"
#include "ExportedByCATMshCVMFmkIndustrySpecialized.h"

#include "ListPOfCATBody.h"
#include "ListPOfCATIMshMesh.h"

class CATMshCVMFmkSpec;

class ExportedByCATMshCVMFmkIndustrySpecialized CATMshCVMFmkIndustrySpecialized : protected CATMshCVM{

public:

    explicit CATMshCVMFmkIndustrySpecialized() noexcept;
    virtual ~CATMshCVMFmkIndustrySpecialized();
    CATMshCVMFmkIndustrySpecialized& operator=(CATMshCVMFmkIndustrySpecialized &&) noexcept = default;

    HRESULT Init(CATListPtrCATIMshMesh &listOfMeshes);
    HRESULT Init(CATListPtrCATBody &listOfBodies);
    HRESULT Init(CATListPtrCATIMshMesh &listOfMeshes, CATListPtrCATBody &listOfBodies);
    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;

    void SetResilientInsertion(const bool resilientInsertion);
    void SetGapSize(const double gapSize);

    using CATMshCVM::SetVerbose;

    using CATMshCVM::SetChordalError;
    using CATMshCVM::SetGeometricApproximationAngle;
    using CATMshCVM::SetSurfaceGradation;
    using CATMshCVM::SetVolumeGradation;
    using CATMshCVM::SetSurfaceMinSize;
    using CATMshCVM::SetSurfaceMaxSize;
    using CATMshCVM::SetBoxSurfaceMinSize;
    using CATMshCVM::SetBoxSurfaceMaxSize;
    using CATMshCVM::SetSurfaceMinEdgeLength;
    using CATMshCVM::SetSurfaceMaxEdgeLength;

    using CATMshCVM::GetChordalError;
    using CATMshCVM::GetGeometricApproximationAngle;
    using CATMshCVM::GetSurfaceGradation;
    using CATMshCVM::GetVolumeGradation;
    using CATMshCVM::GetSurfaceMinSize;
    using CATMshCVM::GetSurfaceMaxSize;
    using CATMshCVM::GetSurfaceMinEdgeLength;
    using CATMshCVM::GetSurfaceMaxEdgeLength;

    HRESULT AddBoundaryLayerConstraint(CATIMshMesh *mesh,
            const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(const CATMshTag &tag,
            const CATMshElement::Orientation orientation,
			const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(const CATMshTag &tag,
            const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(CATBody *body,
    		const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(CATVolume *volume,
    		const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(CATLISTP(CATFace) &listOfFaces, CATListOfInt &listOfSides,
    		const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(CATFace *face, CATSide side,
    		const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);
    HRESULT AddBoundaryLayerConstraint(CATFace *face,
    		const double h0, const double progression, const double blending,
			const int nMin, const int nMax, const bool relative);

    HRESULT AddSurfaceGeometricConstraint(const CATMshTag &tag,
    		const double geometricApproximationAngle, const double chordalError,
            const double minSize, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATEdge *edge,
            const double geometricApproximationAngle, const double chordalError,
            const double minSize, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATFace *face,
            const double geometricApproximationAngle, const double chordalError,
            const double minSize, const double maxSize);

    HRESULT AddSphereSizeConstraint(const double (&center)[3],
    		const double radius, const double size);
    HRESULT AddCylinderSizeConstraint(const double (&p1)[3],
    		const double (&p2)[3], const double radius, const double size);
    HRESULT AddCubeSizeConstraint(const double (&xyzV1)[3],
    		const double (&xyzV2)[3], const double (&xyzV3)[3],
			const double (&xyzV4)[3], const double (&xyzV5)[3],
			const double (&xyzV6)[3], const double (&xyzV7)[3],
			const double (&xyzV8)[3], const double size);

    HRESULT AddFluidDomain(CATIMshMesh *mesh);
    HRESULT AddFluidDomain(CATBody *body);
    HRESULT AddFluidDomain(CATVolume *volume);
    HRESULT AddFluidDomain(CATLISTP(CATFace) &listOfFaces, CATListOfInt &listOfSides);
    HRESULT AddFluidDomain(CATFace *face, CATSide side);

    HRESULT AddDomain(CATVolume *volume, const bool toKeep);
    HRESULT AddDomain(CATBody *body, const bool toKeep);

    HRESULT AddMRFDomain(CATVolume *volume);

    HRESULT AddBox(CATIMshMesh *mesh);
    HRESULT AddBox(const CATMshTag &tag);
    HRESULT AddBox(CATBody *body);
    HRESULT AddBox(CATFace *face);

    bool GetResilientInsertion() const;

    virtual HRESULT Mesh() override;

    virtual CATIMshMesh* GetMesh() override;
    virtual CATIMshMesh* GetMesh(CATVolume *volume) override;
    virtual CATIMshMesh* GetMesh(CATFace *face, CATSide side) override;
    virtual CATIMshMesh* GetMesh(CATLISTP(CATFace) &listOfFaces,
        		CATListOfInt &listOfSides) override;
    virtual CATIMshMesh* GetMesh(CATFace *face) override;
    virtual CATIMshMesh* GetMesh(CATEdge *edge) override;
    virtual CATIMshMesh* GetMesh(CATVertex *vertex) override;

    CATMshCVM* GetCVM();

protected:
    double GetDefaultNumericalResolution() const;
    double GetDefaultIdealisationTolerance() const;
    double GetDefaultGapSize() const;

    void UpdateBoundaryLayers(const double h0, const double p,
            const double b, const int nMin,
			const int nMax, const bool r);
    void UpdateGeometricApproximations(
    		const double geometricApproximationAngle,
            const double chordalError);
    void CapMinMaxSize(const double minAccaptableMinSize,
            const double minAcceptableMaxSize);

    HRESULT Import(CATIMshMesh *mesh);
    HRESULT Import(CATBody *body);

private:
    HRESULT ComputeBbox();

protected:
    double _bbox[6];
    double _lmax;

private:
    std::vector<std::reference_wrapper<CATMshCVMFmkSpec>> _allSpec;

    /*
     * To be removed
     */
    CATListPtrCATBody* _tmpConstructor;

    bool _resilientInsertion;
};

#endif
