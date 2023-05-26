#ifndef CATMshCVMCore_h
#define CATMshCVMCore_h

// COPYRIGHT DASSAULT SYSTEMES 2022
//=============================================================================
/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATIMshMesh.h"
#include "CATIMshMesher.h"
#include "ExportedByCATMshCVMCore.h"
#include "CATSysErrorDef.h"

extern "C" {
#include <meshgems/meshgems.h>
#include <meshgems/cvm.h>
#include <meshgems/cvm_short_names.h>
}

#include <vector>
#include <map>
#include <tuple>

/**
 * Class holding the CVMVerbose parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMVerbose{
	Minimal,
	Normal,
	Maximal,
};

/**
 * Class holding the CVMMetric parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMMetric{
	Isotropic,
	Anisotropic,
};

/**
 * Class holding the CVMMetricPropagation parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMMetricPropagation{
	InAllDirections,
	InDirection,
	TowardIsotropic,
};

/**
 * Class holding the CVMComponents parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMComponents{
	All,
	Outside,
};

/**
 * Class holding the CVMInternalPointsRemovalEffort parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMInternalPointsRemovalEffort{
	Minimal,
	Light,
	Standard,
	Strong,
	Maximal,
};

/**
 * Class holding the CVMOptimisationLevel parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMOptimisationLevel{
	Light,
	Standard,
	Strong,
};

/**
 * Class holding the CVMOverConstrainedElement parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMOverConstrainedElement{
	Edges,
	Tetrahedra,
	Elements,
};

/**
 * Class holding the CVMReproducibility parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMReproducibility{
	Always,
	NotGuaranteed,
};

/**
 * Class holding the CVMMemoryTradeoff parameter
 */
enum class ExportedByCATMshCVMCore CATMshCVMMemoryTradeoff{
	PerformanceInsteadOfMemory,
	MemoryInsteadOfPerformance,
};

/**
 * Private class holding the CVM Core
 * Should never be used directly
 */
class ExportedByCATMshCVMCore CATMshCVMCore : public CATIMshMesher{

public:
	explicit CATMshCVMCore() noexcept;
	virtual ~CATMshCVMCore();

    CATMshCVMCore(const CATMshCVMCore&) = delete;
    CATMshCVMCore& operator=(CATMshCVMCore&) = delete;
    CATMshCVMCore& operator=(CATMshCVMCore &&) noexcept = default;

    HRESULT Init();

    HRESULT SetInterruptCallback(CATMshInterruptCB callback, void *userData);
    HRESULT SetMessageCallback(CATMshMessageCB callback, void *userData);

    void SetVerbose(const CATMshCVMVerbose verbose);

    void SetMaxNumberOfThreads(const int maxNumberOfThreads);
    void SetNumberOfSubdomains(const int numberOfSubdomains);

    void SetReproducibility(const CATMshCVMReproducibility reproducibility);
    void SetMemoryTradeoff(const CATMshCVMMemoryTradeoff memoryTradeoff);

    void SetNumericalResolution(const double numericalResolution);
    void SetEnforceNumericalResolution(const bool enforceNumericalResolution);

    void SetDiscardUnrelevantDomains(const bool discardUnrelevantDomains);

    void SetMetric(const CATMshCVMMetric metric);
    void SetMetricPropagation(const CATMshCVMMetricPropagation propagation);

    void SetComputeComponents(const CATMshCVMComponents components);
    void SetInternalPointsRemovalEffort(const CATMshCVMInternalPointsRemovalEffort effort);
    void SetOptimisationLevel(const CATMshCVMOptimisationLevel level);
    void SetOverconstrainedElement(const CATMshCVMOverConstrainedElement overConstrainedElement);

    void SetSurfaceGradation(const double surfaceGradation);
    void SetSurfaceMinEdgeLength(const double surfaceMinEdgeLength);
    void SetSurfaceMaxEdgeLength(const double surfaceMaxEdgeLength);
    void SetSurfaceMinSize(const double surfaceMinSize);
    void SetSurfaceMaxSize(const double surfaceMaxSize);
    void SetBoxSurfaceMinSize(const double boxSurfaceMinSize);
    void SetBoxSurfaceMaxSize(const double boxSurfaceMaxSize);
    void SetChordalError(const double chordalError);
    void SetGeometricApproximationAngle(const double geometricApproximationAngle);
    void SetSurfaceProximityLayers(const int numberOfLayers);

    void SetRemoveInternalSurfaces(const bool removeInternalSurfaces);

    void SetSmoothWrapSurface(const bool smoothWrapSurface);
    void SetWrapSurfaceTag(const int tag);
    void SetGapSize(const double gapSize);
    void SetExternalGapSize(const double gapSize);
    void SetInternalGapSize(const double gapSize);
    void SetHoleSize(const double holeSize);
    void SetVoxelSize(const double voxelSize);
    void SetPenetrationDepth(const double penetrationDepth);
    void SetMinimumPenetrationDepth(const double minimumPenetrationDepth);
    void SetAvoidExternalSurfacesEffort(const double avoidExternalSurfacesEffort);
    void SetCostFactorForBoundarySurfaceFace(const double costFactorForBoundarySurfaceFace);
    void SetAvoidExternalSurfaces(const bool avoidExternalSurfaces);
    void SetEnforceGapFilling(const bool enforceGapFilling);
    void SetWrapOptimisationEffort(const double wrapOptimisationEffort);
    void SetWrapSmoothSurfaceAngle(const double wrapSmoothSurfaceAngle);
    void SetWrapSmoothSurfaceEffort(const double wrapSmoothSurfaceEffort);

    void SetSurfaceOptimizationFlatAngle(const double flatAngle);
    void SetSurfaceOptimisationDensity(const bool surfaceOptimisationDensity);
    void SetCrossSurfaceVolumeOptimisation(const bool crossSurfaceVolumeOptimisation);

    void SetIdealisationTolerance(const double idealisationTolerance);

    void SetVolumeGradation(const double volumeGradation);
    void SetVolumeMinEdgeLength(const double volumeMinEdgeLength);
    void SetVolumeMaxEdgeLength(const double volumeMaxEdgeLength);
    void SetVolumeMinSize(const double volumeMinSize);
    void SetVolumeMaxSize(const double volumeMaxSize);
    void SetVolumeProximityLayers(const int numberOfLayers);

    void SetBoundaryLayerImprinting(const bool boundaryLayerImprinting);
    void SetBoundaryLayerRidgeAngle(const double boundaryLayerRidgeAngle);

    void SetJacobianThreshold(const double jacobianThreshold);

    void SetAdaptationVolumeOnly(const bool adaptationVolumeOnly);

    CATMshCVMVerbose GetVerbose() const;
    CATMshCVMMetric GetMetric() const;

    double GetSurfaceGradation() const;
    double GetSurfaceMinEdgeLength() const;
    double GetSurfaceMaxEdgeLength() const;
    double GetSurfaceMinSize() const;
    double GetSurfaceMaxSize() const;
    double GetBoxSurfaceMinSize() const;
    double GetBoxSurfaceMaxSize() const;
    double GetChordalError() const;
    double GetGeometricApproximationAngle() const;

    double GetVolumeGradation() const;

    HRESULT AddBoundaryLayerUniformConstraint(CATIMshMesh *mesh,
            const double h0, const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(const CATMshTag &tag,
    		const double h0, const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(const CATMshTag &tag,
    		const CATMshElement::Orientation orientation,
			const double h0, const int n, const bool r);

    HRESULT AddBoundaryLayerArithmeticConstraint(CATIMshMesh *mesh,
    		const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(const CATMshTag &tag,
    		const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(const CATMshTag &tag,
    		const CATMshElement::Orientation orientation,
			const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);

    HRESULT AddBoundaryLayerGeometricConstraint(CATIMshMesh *mesh,
            const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(const CATMshTag &tag,
            const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(const CATMshTag &tag,
    		const CATMshElement::Orientation orientation,
			const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);

    HRESULT AddCartesianCoreConstraint(CATIMshMesh *mesh);
    HRESULT AddCartesianCoreConstraint(CATIMshMesh *mesh, double sizeIso);

    HRESULT AddSurfaceGeometricConstraint(const CATMshTag &tag,
            const double geometricApproximationAngle, const double chordalError,
            const double minSize, const double maxSize);

    HRESULT AddVertexSizeConstraint(const double (&xyz)[3],
    		const double sizeIso);
    HRESULT AddVertexSizeConstraint(const double (&xyz)[3],
    		const double (&sizeAniso)[6]);
    HRESULT AddVertexSizeConstraint(const double (&xyz)[3],
    		const double dx, const double dy,
			const double dz, const double sizeIso);
    HRESULT AddVertexSizeConstraint(const double (&xyz)[3],
    		const double dx, const double dy,
			const double dz, const double (&sizeAniso)[6]);

    HRESULT AddVertexSizeConstraint(const CATMshVertexIndex &vertexIndex,
    		const double sizeIso);
    HRESULT AddVertexSizeConstraint(const CATMshVertexIndex &vertexIndex,
    		const double sizeIso, const bool relative);

    HRESULT AddVertexSizeConstraint(const CATMshVertexIndex &vertexIndex,
    		const double (&sizeAniso)[6]);
    HRESULT AddVertexSizeConstraint(const CATMshVertexIndex &vertexIndex,
    		const double (&sizeAniso)[6], const bool relative);

    HRESULT AddSphereSizeConstraint(const double (&center)[3],
    		const double radius, const double size);
    HRESULT AddCylinderSizeConstraint(const double (&p1)[3],
    		const double (&p2)[3], const double radius, const double size);
    HRESULT AddCubeSizeConstraint(const double (&xyzMin)[3],
    		const double (&xyzMax)[3], const double size);
    HRESULT AddCubeSizeConstraint(const double (&xyzV1)[3],
    		const double (&xyzV2)[3], const double (&xyzV3)[3],
    		const double (&xyzV4)[3], const double (&xyzV5)[3],
			const double (&xyzV6)[3], const double (&xyzV7)[3],
			const double (&xyzV8)[3], const double size);

    HRESULT AddShapeSizeConstraint(CATIMshMesh *mesh, const double sizeIso);
    HRESULT AddShapeSizeConstraint(CATIMshMesh *mesh, const double (&sizeAniso)[6]);

    HRESULT AddFrozenConstraint(const CATMshTag &tag);
    HRESULT AddFrozenConstraint(CATMshVertexIndex &vertexIndex);
    HRESULT AddFrozenConstraint(CATMshElementIndex &elementIndex);

    HRESULT AddDomainImplicitConstraint(const CATMshTag &tag,
    		CATMshElement::Orientation orientation, const bool toKeep);

    HRESULT AddDomainExplicitConstraint(CATIMshMesh *mesh,
    		const bool toKeep, const bool toWrap);
    HRESULT AddDomainExplicitConstraint(const CATMshDomain &domain,
    		const bool toKeep, const bool toWrap);
    HRESULT AddDomainExplicitConstraint(const CATMshTag &tag,
    		CATMshElement::Orientation orientation,
			const bool toKeep, const bool toWrap);

    HRESULT AddDomainArtificialConstraint(const CATMshDomain &domain);
    HRESULT AddDomainArtificialConstraint(const CATMshTag &tag,
    		CATMshElement::Orientation orientation);

    virtual HRESULT Mesh() = 0;
    virtual HRESULT UpdateMesh();

    virtual CATIMshMesh* GetMesh() = 0;
    virtual CATIMshMesh* GetMesh(CATIMshMesh *mesh);
    virtual CATIMshMesh* GetMesh(CATIMshMesh *mesh, const CATMshTag &tag);
    virtual CATIMshMesh* GetMesh(CATIMshMesh* mesh, const CATMshTag& tag, CATMshElement::Orientation orientation);

    mesh_t* LegacyGetCVMInputMesh();
    mesh_t* LegacyGetCVMOutputMesh();
    sizemap_t* LegacyGetCVMOutputSizemap();
    cvm_session_t* LegacyGetCVMSession();
    cvm_domain_specification_t* LegacyGetDomainSpecification();

protected:

    HRESULT PrepareInsertion();
    HRESULT InsertSurfaceVertices();
    HRESULT InsertSurfaceElements();
    HRESULT EnforceCompatibility();
    HRESULT Wrap();
    HRESULT Idealize();
    HRESULT Morph();
    HRESULT OptimizeSurface();
    HRESULT InsertBoundaryLayers();
    HRESULT InsertCartesianCore();
    HRESULT InsertRegular();
    HRESULT RemoveInternalPoints();
    HRESULT EnforceComplexConformity();
    HRESULT Optimize();
    HRESULT SplitOverConstrainedEntities();
    HRESULT AdaptSurface();
    HRESULT AdaptBoundaryLayers();
    HRESULT AdaptVolume();

    void LegacySetNRU(const bool nru);
    void LegacySetExternalWrap(const bool wrap);
    void LegacySetIdealisation(const bool idealisation);
    void LegacySetSurfaceOptimisation(const bool surfaceOptimisation);
    void LegacySetRemoveInternalPoints(const bool removeInternalPoints);
    void LegacySetRegular(const bool regular);
    void LegacySetBoundaryLayer(const bool boundaryLayer);
    void LegacySetCartesianCore(const bool cartesianCore);
    void LegacySetComplexConformity(const bool complexConformity);
    void LegacySetSplitOverConstrained(const bool splitOverConstrained);
    void LegacySetOptimisation(const bool optimisation);
    void LegacySetAdaptation(const bool adaptation);
    void LegacySetExtractPolyBody(const bool extractPolyBody);
    void LegacySetExtractCATIMshMesh(const bool extractCATIMshMesh);

    bool LegacyIsNRUNeeded() const;
    bool LegacyIsExternalWrapNeeded() const;
    bool LegacyIsIdealisationNeeded() const;
    bool LegacyIsSurfaceOptimisationNeeded() const;
    bool LegacyIsRemoveInternalPointsNeeded() const;
    bool LegacyIsRegularNeeded() const;
    bool LegacyIsBoundaryLayerNeeded() const;
    bool LegacyIsCartesianCoreNeeded() const;
    bool LegacyIsComplexConformityNeeded() const;
    bool LegacyIsSplitOverConstrainedNeeded() const;
    bool LegacyIsOptimisationNeeded() const;
    bool LegacyIsAdaptationNeeded() const;

    CATMshInterruptCB LegacyGetInterruptCB();
    CATMshMessageCB LegacyGetMessageCB();
    sizemap_t* LegacyGetSizemapIso3D();

    HRESULT LegacyCreateSizemapCreator(double (&xyz_min)[3], double (&xyz_max)[3]);
    cvm_domain_specification_t* LegacyGetCVMDomainSpecification();
    cvm_size_specification_t* LegacyGetCVMSizeSpecification();

    HRESULT Import(CATIMshMesh *mesh);
    HRESULT LegacyImportDiscreetSizemap();
    HRESULT LegacyImportContinuousSizemap();

    HRESULT LegacyRunCVMSession(mesh_t *givenMesh = nullptr);
    HRESULT LegacyUpdateCVMSession();

private:

    HRESULT AddDomainConstraint(const CATMshTag &tag,
    		CATMshElement::Orientation orientation,
			const bool toKeep, const bool toWrap,
			const bool implicit, const bool artificial);

    friend status_t CATMshCVMLegacyMessageCallback(meshgems_message_t *msg, void *user_data);
    friend status_t CATMshCVMLegacyInterruptCallback(meshgems_integer *interrupt_status, void *user_data);

    friend status_t LegacyIsoMeshAtVertexCallback(integer pid, real *size,
    		void *user_data);
    friend status_t LegacyAnisoMeshAtVertexCallback(integer pid, real *met,
    		void *user_data);

protected:

    context_t* _legacyImportedPolyContext;
    mesh_t* _legacyPolyBodyTransformedMesh;

    std::vector<std::reference_wrapper<CATIMshMesh>> _importedMesh;

private:

    context_t *_legacyImportedContext;
    mesh_t *_legacyImportedMesh;

    context_t *_legacyCVMContext;
    cvm_session_t *_legacyCVMSession;
    cvm_size_specification_t *_legacyCVMSizeSpecification;
    cvm_domain_specification_t *_legacyCVMDomainSpecification;
    sizemap_t *_legacyCVMSizemapIsoMeshAtVertex;
    sizemap_t *_legacyCVMSizemapAnisoMeshAtVertex;
    sizemap_creator_t *_legacyCVMIso3DSizemapCreator;
    sizemap_creator_t *_legacyCVMAniso3DSizemapCreator;
    sizemap_t *_legacyCVMSizemapIso3D;
    sizemap_t *_legacyCVMSizemapAniso3D;
    mesh_t *_legacyCVMInputMesh;
    mesh_t *_legacyCVMOutputMesh;
    sizemap_t *_legacyCVMOutputSizemap;

    CATMshInterruptCB _interruptCB;
    void *_interruptCBUserData;

    CATMshMessageCB _messageCB;
    void *_messageCBUserData;

    bool _legacyNRU;
    bool _legacyExternalWrap;
    bool _legacyIdealisation;
    bool _legacySurfaceOptimisation;
    bool _legacyRemoveInternalPoints;
    bool _legacyRegular;
    bool _legacyBoundaryLayer;
    bool _legacyCartesianCore;
    bool _legacyComplexConformity;
    bool _legacySplitOverConstrained;
    bool _legacyOptimisation;
    bool _legacyAdaptation;

    CATMshCVMVerbose _legacyVerbose;
    CATMshCVMMetric _legacyMetric;
    CATMshCVMOverConstrainedElement _legacyOverConstrainedElement;
    double _legacySurfaceGradation;
    double _legacySurfaceMinEdgeLength;
    double _legacySurfaceMaxEdgeLength;
    double _legacySurfaceMinSize;
    double _legacySurfaceMaxSize;
    double _legacyBoxSurfaceMinSize;
    double _legacyBoxSurfaceMaxSize;
    double _legacyGeometricApproximationAngle;
    double _legacyChordalError;
    double _legacyVolumeGradation;
    int _legacyMaxNumberOfThreads;

    std::map<CATMshVertexIndex, double> _legacySizeIsoAtVertexIndex;
    std::map<CATMshVertexIndex, std::vector<double>> _legacySizeAnisoAtVertexIndex;
};

#endif
