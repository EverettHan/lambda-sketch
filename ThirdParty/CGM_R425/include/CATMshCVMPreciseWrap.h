#ifndef CATMshCVMPreciseWrap_h
#define CATMshCVMPreciseWrap_h

#include "CATMshCVM.h"
#include "ListPOfCATIMshMesh.h"
#include "ExportedByCATMshCVMPreciseWrap.h"

/**
 * CVMPreciseWrap API
 * Performs PreciseWrap on a given mesh.
 * Per default, an external wrap is performed, closing gaps and holes.
 * Additionally, internal wraps that wrap internal domains can be
 * performed for one or several internal domains.
 * For each internal domain, an internal wrap constraint has to
 * be given using the method AddInternalWrapConstraint.
*/
class ExportedByCATMshCVMPreciseWrap CATMshCVMPreciseWrap : protected CATMshCVM{

public:

	explicit CATMshCVMPreciseWrap() noexcept;
    virtual ~CATMshCVMPreciseWrap();

    CATMshCVMPreciseWrap& operator=(CATMshCVMPreciseWrap &&) noexcept = default;

    HRESULT Init(CATIMshMesh *mesh);
    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;
    using CATMshCVM::SetVerbose;

    using CATMshCVM::SetHoleSize;
    using CATMshCVM::SetWrapSurfaceTag;
    using CATMshCVM::SetRemoveInternalSurfaces;
    using CATMshCVM::SetSmoothWrapSurface;
    using CATMshCVM::SetAvoidExternalSurfaces;
    using CATMshCVM::SetWrapSmoothSurfaceAngle;
    using CATMshCVM::SetWrapSmoothSurfaceEffort;

    void SetGapSize(const double gapSize);


    /**
     * Add a constraint to wrap an internal domain
     * The internal domain has to be defined by indicating a face
     * that is part of the domain boundary and a side/orientation to define
     * on which side of the face the domain can be found.
     * In this case, the input is given as a CATMshTag and a CATMshElement::Orientation,
     *
     * If no InternalWrapConstraint is given, only the external wrap will be performed.
     *
     */
    HRESULT AddInternalWrapConstraint(const CATMshTag &tag, CATMshElement::Orientation orientation);

    /**
     * Add a constraint to wrap an internal domain
     * The internal domain has to be defined by indicating a face 
     * that is part of the domain boundary and a side/orientation to define 
     * on which side of the face the domain can be found.
     * In the discrete case, the input is given as a CATMshTag and a CATMshElement::Orientation,
     * in the continuous case, the input can be given as a CATFace* and a CATSide.
     * 
     * If no InternalWrapConstraint is given, only the external wrap will be performed.
     * 
     */
    HRESULT AddInternalWrapConstraint(CATListValCATMshTag &listOfTag, CATListValCATMshOrientation &listOfOrientation);

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

    /**
     * Get the mesh of an internal domain.
     * 
     * This method returns the mesh corresponding to the internal domain specified 
     by a call to the AddInternalWrapConstraint method.
     * @return
     *   The internal domain mesh.
     */
    virtual CATIMshMesh* GetMesh(CATListValCATMshTag& listOfTag, CATListValCATMshOrientation& listOfOrientation);

};

#endif
