#ifndef CATMshCVM_h
#define CATMshCVM_h

#include "CATMshCVMCore.h"
#include "ExportedByCATMshCVM.h"

#include "CATFace.h"
#include "CATBody.h"
#include "CATPolyBody.h"
#include "CATPolyFace.h"
#include "ListVOfCATMshTag.h"
#include "ListVOfCATMshOrientation.h"

extern "C" {
#include <meshgems/cadsurf.h>
#include <meshgems/cadsurf_short_names.h>
}

class CATMshCVMBridgeCurveEvalData;
class CATMshCVMLegacySizemapGeoData;

class ExportedByCATMshCVM CATMshCVM : protected CATMshCVMCore{

public:

    explicit CATMshCVM() noexcept;
    virtual ~CATMshCVM();
    CATMshCVM& operator=(CATMshCVM &&) noexcept = default;

    HRESULT Init();
    using CATMshCVMCore::Release;

    using CATMshCVMCore::SetInterruptCallback;
    using CATMshCVMCore::SetMessageCallback;

    void SetDumpBridge(const bool dumpBridge);

    using CATMshCVMCore::SetVerbose;

    using CATMshCVMCore::SetNumericalResolution;
    using CATMshCVMCore::SetEnforceNumericalResolution;

    using CATMshCVMCore::SetMetric;
    using CATMshCVMCore::SetMetricPropagation;
    using CATMshCVMCore::SetComputeComponents;
    using CATMshCVMCore::SetInternalPointsRemovalEffort;
    using CATMshCVMCore::SetOptimisationLevel;
    using CATMshCVMCore::SetOverconstrainedElement;

    using CATMshCVMCore::SetMaxNumberOfThreads;
    using CATMshCVMCore::SetNumberOfSubdomains;

    using CATMshCVMCore::SetSurfaceGradation;
    using CATMshCVMCore::SetSurfaceMinEdgeLength;
    using CATMshCVMCore::SetSurfaceMaxEdgeLength;
    using CATMshCVMCore::SetSurfaceMinSize;
    using CATMshCVMCore::SetSurfaceMaxSize;
    using CATMshCVMCore::SetBoxSurfaceMinSize;
    using CATMshCVMCore::SetBoxSurfaceMaxSize;
    using CATMshCVMCore::SetChordalError;
    using CATMshCVMCore::SetGeometricApproximationAngle;

    using CATMshCVMCore::SetSurfaceOptimisationDensity;
    using CATMshCVMCore::SetCrossSurfaceVolumeOptimisation;
    using CATMshCVMCore::SetSurfaceOptimizationFlatAngle;

    using CATMshCVMCore::SetIdealisationTolerance;

    using CATMshCVMCore::SetRemoveInternalSurfaces;

    using CATMshCVMCore::SetSmoothWrapSurface;
    using CATMshCVMCore::SetWrapSurfaceTag;
    using CATMshCVMCore::SetGapSize;
    using CATMshCVMCore::SetExternalGapSize;
    using CATMshCVMCore::SetInternalGapSize;
    using CATMshCVMCore::SetHoleSize;

    using CATMshCVMCore::SetVolumeGradation;
    using CATMshCVMCore::SetVolumeMinEdgeLength;
    using CATMshCVMCore::SetVolumeMaxEdgeLength;
    using CATMshCVMCore::SetVolumeMinSize;
    using CATMshCVMCore::SetVolumeMaxSize;

    using CATMshCVMCore::SetBoundaryLayerImprinting;
    using CATMshCVMCore::SetBoundaryLayerRidgeAngle;

    using CATMshCVMCore::GetSurfaceGradation;
    using CATMshCVMCore::GetSurfaceMinEdgeLength;
    using CATMshCVMCore::GetSurfaceMaxEdgeLength;
    using CATMshCVMCore::GetSurfaceMinSize;
    using CATMshCVMCore::GetSurfaceMaxSize;
    using CATMshCVMCore::GetBoxSurfaceMinSize;
    using CATMshCVMCore::GetBoxSurfaceMaxSize;
    using CATMshCVMCore::GetChordalError;
    using CATMshCVMCore::GetGeometricApproximationAngle;

    using CATMshCVMCore::GetVolumeGradation;

    using CATMshCVMCore::AddBoundaryLayerUniformConstraint;
    HRESULT AddBoundaryLayerUniformConstraint(CATBody *body,
    		const double h0, const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(CATVolume *volume,
    		const double h0, const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides, const double h0,
			const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(CATFace *face,
    		const CATSide side, const double h0,
			const int n, const bool r);
    HRESULT AddBoundaryLayerUniformConstraint(CATFace *face,
    		const double h0, const int n, const bool r);

    using CATMshCVMCore::AddBoundaryLayerArithmeticConstraint;
    HRESULT AddBoundaryLayerArithmeticConstraint(CATBody *body,
       		const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(CATVolume *volume,
       		const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides, const double h0, const double d,
			const double b, const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(CATFace *face,
    		const CATSide side, const double h0, const double d,
			const double b, const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerArithmeticConstraint(CATFace *face,
       		const double h0, const double d, const double b,
			const int nMin, const int nMax, const bool r);

    using CATMshCVMCore::AddBoundaryLayerGeometricConstraint;
    HRESULT AddBoundaryLayerGeometricConstraint(CATListValCATMshTag &listOfTags,
    		CATListValCATMshOrientation &listOfOrientations,
			const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(CATBody *body,
    		const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(CATVolume *volume,
    		const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides, const double h0, const double p,
			const double b, const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(CATFace *face,
    		const CATSide side, const double h0, const double p,
			const double b, const int nMin, const int nMax, const bool r);
    HRESULT AddBoundaryLayerGeometricConstraint(CATFace *face,
            const double h0, const double p, const double b,
			const int nMin, const int nMax, const bool r);

    using CATMshCVMCore::AddSurfaceGeometricConstraint;
    HRESULT AddSurfaceGeometricConstraint(CATEdge *edge,
            const double geometricApproximationAngle, const double chordalError,
            const double minSize, const double maxSize);
    HRESULT AddSurfaceGeometricConstraint(CATFace *face,
            const double geometricApproximationAngle, const double chordalError,
			const double minSize, const double maxSize);

    using CATMshCVMCore::AddVertexSizeConstraint;
    using CATMshCVMCore::AddCubeSizeConstraint;
    using CATMshCVMCore::AddSphereSizeConstraint;
    using CATMshCVMCore::AddCylinderSizeConstraint;

    using CATMshCVMCore::AddShapeSizeConstraint;
    HRESULT AddShapeSizeConstraint(CATBody *body, const double sizeIso);
    HRESULT AddShapeSizeConstraint(CATBody *body, const double (&sizeAniso)[6]);

    using CATMshCVMCore::AddDomainImplicitConstraint;
    HRESULT AddDomainImplicitConstraint(CATListValCATMshTag &listOfTags,
    		CATListValCATMshOrientation &listOfOrientations, const bool toKeep);
    HRESULT AddDomainImplicitConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides, const bool toKeep);
    HRESULT AddDomainImplicitConstraint(CATFace *face, CATSide side, const bool toKeep);
    HRESULT AddDomainImplicitConstraint(CATPolyFace* pPolyFace, CATSide side, const bool toKeep);
    HRESULT AddDomainImplicitConstraint(CATLISTP(CATPolyFace)& listOfPolyFaces,
        CATListOfInt& listOfSides, const bool toKeep);

    using CATMshCVMCore::AddDomainExplicitConstraint;
    HRESULT AddDomainExplicitConstraint(CATListValCATMshTag &listOfTags,
    		CATListValCATMshOrientation &listOfOrientations,
			const bool toKeep, const bool toWrap);
    HRESULT AddDomainExplicitConstraint(CATVolume *volume,
    		const bool toKeep, const bool toWrap);
    HRESULT AddDomainExplicitConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides,
			const bool toKeep, const bool toWrap);
    HRESULT AddDomainExplicitConstraint(CATFace *face, CATSide side,
    		const bool toKeep, const bool toWrap);
	HRESULT AddDomainExplicitConstraint(CATPolyVolume* polyVolume,
        const bool toKeep);

    using CATMshCVMCore::AddDomainArtificialConstraint;
    HRESULT AddDomainArtificialConstraint(CATListValCATMshTag &listOfTags,
    		CATListValCATMshOrientation &listOfOrientations);
    HRESULT AddDomainArtificialConstraint(CATVolume *volume);
    HRESULT AddDomainArtificialConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides);
    HRESULT AddDomainArtificialConstraint(CATFace *face, CATSide side);

    virtual HRESULT Mesh() = 0;

    virtual CATIMshMesh* GetMesh() = 0;
    virtual CATIMshMesh* GetMesh(CATBody *body);
    virtual CATIMshMesh* GetMesh(CATVolume *volume);
    virtual CATIMshMesh* GetMesh(CATFace *face, CATSide side);
    virtual CATIMshMesh* GetMesh(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides);
    virtual CATIMshMesh* GetMesh(CATFace *face);
    virtual CATIMshMesh* GetMesh(CATEdge *edge);
    virtual CATIMshMesh* GetMesh(CATVertex *vertex);
    virtual CATIMshMesh* GetMesh(CATListValCATMshTag& listOfTag, CATListValCATMshOrientation& listOfOrientation);

    mesh_t *LegacyGetCADSurfOutputMesh();

    CATMshCVMCore *GetCVMCore();

    CATFace* DebugGetFaceForGivenID(integer id);
    CATEdge* DebugGetEdgeForGivenID(integer id);
    CATVertex* DebugGetVertexForGivenID(integer id);
    CATVolume* DebugGetVolumeForGivenID(integer id);
    CATBody* DebugGetBodyForGivenID(integer id);

    void DebugDumpBridge();
    void DebugExportAssociativity(CATVolume *volume);
    void DebugExportAssociativity(CATFace *face, CATSide side);
    void DebugExportAssociativity(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides);
    void DebugExportAssociativity(CATVertex *vertex);
    void DebugExportAssociativity(CATEdge *edge);
    void DebugExportAssociativity(CATFace *face);

protected:

    using CATMshCVMCore::PrepareInsertion;
    using CATMshCVMCore::InsertSurfaceVertices;
    using CATMshCVMCore::InsertSurfaceElements;
    using CATMshCVMCore::EnforceCompatibility;
    using CATMshCVMCore::Wrap;
    using CATMshCVMCore::Idealize;
    using CATMshCVMCore::Morph;
    using CATMshCVMCore::OptimizeSurface;
    using CATMshCVMCore::InsertBoundaryLayers;
    using CATMshCVMCore::InsertCartesianCore;
    using CATMshCVMCore::InsertRegular;
    using CATMshCVMCore::RemoveInternalPoints;
    using CATMshCVMCore::EnforceComplexConformity;
    using CATMshCVMCore::Optimize;
    using CATMshCVMCore::SplitOverConstrainedEntities;
    using CATMshCVMCore::AdaptSurface;
    using CATMshCVMCore::AdaptBoundaryLayers;
    using CATMshCVMCore::AdaptVolume;

    using CATMshCVMCore::LegacySetNRU;
    using CATMshCVMCore::LegacySetExternalWrap;
    using CATMshCVMCore::LegacySetIdealisation;
    using CATMshCVMCore::LegacySetSurfaceOptimisation;

    using CATMshCVMCore::Import;
    HRESULT Import(CATBody *body);
    HRESULT Import(CATPolyBody *polyBody);
    HRESULT LegacyImportSizemap();

    HRESULT LegacyRunCADSurfSession();

private:

    HRESULT LegacyImportVertexOnFace(CATVertex *vertex, cad_face_t *f);
    HRESULT LegacyImportEdgeOnFace(CATEdge *edge, CATFace *face, cad_face_t *f);
    HRESULT LegacyImportFace(CATFace *face, CATSide inside, CATBody *body, CATVolume *volume);
    HRESULT LegacyImportWire(CATWire *wire);

    double LegacyComputeGlobalSurfaceMinSize();
    double LegacyComputeGlobalSurfaceMaxSize();

    integer GetNewID();

    HRESULT AddDomainConstraint(CATListValCATMshTag &listOfTags,
    		CATListValCATMshOrientation &listOfOrientations,
			const bool toKeep, const bool toWrap,
			const bool implicit, const bool artificial);
    HRESULT AddDomainConstraint(CATFace *face, CATSide side,
    		const bool toKeep, const bool toWrap,
			const bool implicit, const bool artificial);
    HRESULT AddDomainConstraint(CATLISTP(CATFace) &listOfFaces,
    		CATListOfInt &listOfSides,
			const bool toKeep, const bool toWrap,
			const bool implicit, const bool artificial);
    HRESULT AddDomainConstraint(CATPolyFace* polyFace, CATSide side,
        const bool toKeep, const bool toWrap,
        const bool implicit, const bool artificial);
    HRESULT AddDomainConstraint(CATLISTP(CATPolyFace)& listOfPolyFaces,
        CATListOfInt& listOfSides,
        const bool toKeep, const bool toWrap,
        const bool implicit, const bool artificial);

    friend status_t LegacyGeosizeOnEdgeCallback(integer eid,
            real *geometric_approximation, real *tolerance,
            real *hmin, real *hmax, void *user_data);
    friend status_t LegacyGeosizeOnFaceCallback(integer fid,
            real *geometric_approximation, real *tolerance,
            real *hmin, real *hmax, void *user_data);

protected:
    std::vector<std::reference_wrapper<CATBody>> _importedBody;
    std::vector<std::reference_wrapper<CATPolyBody>> _importedPolyBody;

    std::vector<CATMshCVMBridgeCurveEvalData*> _bridgeCurveData;
    std::map<CATVertex*, integer> _bridgeVertex2ID;
    std::map<integer, CATVertex*> _bridgeID2Vertex;
    std::map<CATEdge*, integer> _bridgeEdge2ID;
    std::map<integer, CATEdge*> _bridgeID2Edge;
    std::map<CATFace*, integer> _bridgeFace2ID;
    std::map<integer, CATFace*> _bridgeID2Face;
    std::map<CATVolume*, integer> _bridgeVolume2ID;
    std::map<integer, CATVolume*> _bridgeID2Volume;
    std::map<CATBody*, integer> _bridgeBody2ID;
    std::map<integer, CATBody*> _bridgeID2Body;
    std::multimap<CATEdge*, CATFace*> _bridgeEdge2Faces;
    std::map<CATFace*, CATOrientation> _bridgeFace2Orientation;
    std::multimap<CATVolume*, std::pair<CATFace*, CATSide>> _bridgeVolume2FaceInside;
    std::multimap<CATBody*, CATFace*> _bridgeBody2DanglingFace;
    std::multimap<CATBody*, CATVolume*> _bridgeBody2Volume;


    std::map<CATPolyCell*, integer> _bridgePolyCell2ID;
    std::map<integer, CATPolyCell*> _bridgeID2PolyCell;
    std::map<CATPolyBody*, integer> _bridgePolyBody2ID;
    std::map<integer, CATPolyBody*> _bridgeID2PolyBody;
    
    integer _bridgeLastID;

private:
    context_t *_legacyCADSurfContext;
    cadsurf_session_t *_legacyCADSurfSession;
    cad_t *_legacyCADSurfInputCAD;
    sizemap_t *_legacyCADSurfSizemapGeoFace;
    sizemap_t *_legacyCADSurfSizemapGeoEdge;
    mesh_t *_legacyCADSurfOutputMesh;

    std::vector<CATMshCVMLegacySizemapGeoData*> _legacySizemapGeoData;
    std::map<CATEdge*, CATMshCVMLegacySizemapGeoData*> _legacyEdge2SizemapGeoData;
    std::map<CATFace*, CATMshCVMLegacySizemapGeoData*> _legacyFace2SizemapGeoData;

    bool _discardInput;
};

#endif
