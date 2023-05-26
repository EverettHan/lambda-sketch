#ifndef CATMshCVMFmkGeneralPurpose_h
#define CATMshCVMFmkGeneralPurpose_h

#include "CATMshCVMFmkIndustrySpecialized.h"
#include "ExportedByCATMshCVMFmkGeneralPurpose.h"

class ExportedByCATMshCVMFmkGeneralPurpose CATMshCVMFmkGeneralPurpose : protected CATMshCVMFmkIndustrySpecialized{

public:

    explicit CATMshCVMFmkGeneralPurpose() noexcept;
    virtual ~CATMshCVMFmkGeneralPurpose();
    CATMshCVMFmkGeneralPurpose& operator=(CATMshCVMFmkGeneralPurpose &&) noexcept = default;

    HRESULT Init(CATListPtrCATIMshMesh &listOfMesh);
    HRESULT Init(CATListPtrCATBody &listOfBody);
    using CATMshCVMFmkIndustrySpecialized::Release;

    using CATMshCVMFmkIndustrySpecialized::SetInterruptCallback;
    using CATMshCVMFmkIndustrySpecialized::SetMessageCallback;

    void SetResilientInsertion(const bool resilientInsertion);

    using CATMshCVMFmkIndustrySpecialized::SetVerbose;

    void SetRefinement(const double refinement);
    void SetMaxSize(const double maxSize);
    void SetBoxMaxSize(const double boxMaxSize);

    void SetThickLayer(const double h0, const int nMin, const int nMax);
    void SetBoundaryLayer(const double h0, const double progression, const double blending);

    double GetRefinementSlider();
    double GetMaxSize();
    double GetBoxMaxSize();
    void GetThickLayer(double &h0, int &nMin, int &nMax);
    void GetBoundaryLayer(double &h0, double &progression, double &blending);

    bool IsThickLayer();
    bool IsBoundaryLayer();

    HRESULT AddSurfaceGeometricConstraint(CATMshTag &tag, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATEdge *edge, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATFace *face, const double maxSize);

    using CATMshCVMFmkIndustrySpecialized::AddSphereSizeConstraint;
    using CATMshCVMFmkIndustrySpecialized::AddCylinderSizeConstraint;
    using CATMshCVMFmkIndustrySpecialized::AddCubeSizeConstraint;

    HRESULT AddFluidDomain(CATIMshMesh *mesh);
    HRESULT AddFluidDomain(CATBody *body);
    HRESULT AddFluidDomain(CATVolume *volume);
    HRESULT AddFluidDomain(CATLISTP(CATFace) &listOfFace, CATListOfInt &listOfSide);
    HRESULT AddFluidDomain(CATFace *face, CATSide side);
    HRESULT AddMRFDomain(CATVolume *volume);

    HRESULT AddDomain(CATVolume *volume, const bool toKeep);
    HRESULT AddDomain(CATBody *body, const bool toKeep);

    using CATMshCVMFmkIndustrySpecialized::AddBox;

    using CATMshCVMFmkIndustrySpecialized::Mesh;

    using CATMshCVMFmkIndustrySpecialized::GetMesh;

    CATMshCVMFmkIndustrySpecialized* GetCVMFmkIndustrySpecialized();

protected:
    void UpdateSlider();

private:
    CATMshCVMFmkGeneralPurpose(CATListPtrCATIMshMesh *listOfMesh,
    		CATListPtrCATBody *listOfBody) noexcept;
    HRESULT Init(CATListPtrCATIMshMesh &listOfMesh, CATListPtrCATBody &listOfBody);

private:
    double _refinement;

    double _maxSize;
    double _boxMaxSize;

    double _h0;
    double _progression;
    double _blending;
    int _nMin;
    int _nMax;
    bool _relative;
};

#endif
