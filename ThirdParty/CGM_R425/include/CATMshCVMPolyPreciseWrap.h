#ifndef CATMshCVMPolyPreciseWrap_h
#define CATMshCVMPolyPreciseWrap_h

#include "CATMshCVM.h"
#include "ListPOfCATIMshMesh.h"
#include "CATPolyBodyList.h"
#include "CATPolyBodyNaryObserver.h"
#include "ExportedByCATMshCVMPolyPreciseWrap.h"

/**
 * CVMPolyPreciseWrap API
 * Performs the geometric workflow of PreciseWrap that takes a CATPolyBody as input, 
 * transforms it into a mesh which is given to CVM Precise Wrap and returns the 
 * result as a CATPolyBody.
 * To extract internal domains, an internal wrap constraint has to be defined by 
 * calling the method AddInternalWrapConstraint. Otherwise, only external wrapping 
 * will be performed.
 * A typical workflow will consist in:
 * - construction of CATMshCVMPolyPreciseWrap instance with CATPolyBody input
 * - Init()
 * - AddInternalWrapConstraint
 * - setting of costumized parameters
 * - Mesh()
 * - GetPolyBody()
 * 
 */
class ExportedByCATMshCVMPolyPreciseWrap CATMshCVMPolyPreciseWrap : protected CATMshCVM{

public:
    
    explicit CATMshCVMPolyPreciseWrap() noexcept;
    virtual ~CATMshCVMPolyPreciseWrap();

    CATMshCVMPolyPreciseWrap& operator=(CATMshCVMPolyPreciseWrap &&) noexcept = default;

    /**
     * Initialize the mesher after creation.
     * The call to this function is MANDATORY.
     * 
     * FIXME: Multiple polybodies are not supported yet!! 
     (list with a single polybody can be treated)

     *  @return
     *   A HRESULT.
     */
    HRESULT Init(CATListPtrCATPolyBody& listOfPolyBody);


    using CATMshCVM::Release;

    using CATMshCVM::SetInterruptCallback;
    using CATMshCVM::SetMessageCallback;
    using CATMshCVM::SetVerbose;
    using CATMshCVM::SetNumericalResolution;

    /**
     * Size for gap closing
     * 
     * gaps are between two faces in their normal direction
     */
    void SetGapSize(const double gapSize);

    /**
     * Size for external gap closing
     *
     * Set the size for external gap closing (leaks) only. Gaps within an internal domain will not be closed.
     * (gaps are between two faces in their normal direction)
     */
    using CATMshCVM::SetExternalGapSize;

    /**
     * Size for hole closing
     *
     * holes are any kind of holes, also within faces, not necessarily in normal direction of a face
     * This size should be chosen corresponding to the size of the maximal leak detected in the model
     */
    using CATMshCVM::SetHoleSize;
    using CATMshCVM::SetWrapSurfaceTag;
    /**
     * Delete faces internal faces that are not in fluid domain
     * 
     * If this parameter is set, only the boundary faces of internal and/or external fluid domains will be kept.
     * All other internal faces (i.e. in solids) will be deleted.
     * 
     * For now, this option is enforced, until multi-material solutions are supported by this API.
     */
    using CATMshCVM::SetRemoveInternalSurfaces;
    using CATMshCVM::SetSmoothWrapSurface;
    using CATMshCVM::SetWrapSmoothSurfaceAngle;
    using CATMshCVM::SetWrapSmoothSurfaceEffort;

    /**
     * Add a constraint to wrap an internal domain
     * The internal domain has to be defined by indicating a face
     * that is part of the domain boundary and a side/orientation to define
     * on which side of the face the domain can be found.
     * In this case, the input is given as a CATMshTag corresponding to the cell tag
     * of the corresponding face in the input CATPolyBody and a CATMshElement::Orientation 
     * (Forward corresponds to CATSideRight for a CATFace,
     * Reverse corresponds to CATSideLeft).
     *
     * This method will create a constraint for each call, meaning that domains corresponding to two lids will be separated.
     * To avoid a separation when indicating multiple lids, the methods taking lists as input has to be used.
     */
    HRESULT AddInternalWrapConstraint(const CATMshTag& tag, CATMshElement::Orientation orientation);

    /**
     * Add a constraint to wrap an internal domain
     * The internal domain has to be defined by indicating a face
     * that is part of the domain boundary and a side/orientation to define
     * on which side of the face the domain can be found.
     * In this case, the input is given as a CATMshTag corresponding to the cell tag
     * of the corresponding face in the input CATPolyBody and a CATMshElement::Orientation 
     * (Forward corresponds to CATSideRight for a CATFace,
     * Reverse corresponds to CATSideLeft).
     *
     */
    HRESULT AddInternalWrapConstraint(CATListValCATMshTag& listOfTag, CATListValCATMshOrientation& listOfOrientation);

    HRESULT AddInternalWrapConstraint(CATPolyFace* pPolyFace, CATSide side);
    HRESULT AddInternalWrapConstraint(CATLISTP(CATPolyFace)& listOfPolyFaces, CATListOfInt& listOfSides);

    /**
     Add a constraint to wrap an internal domain
     * This method offers the possibility to define an internal domain only by a face (list of faces) without orientation.
     * PreciseWrap will extract following depending on the position of the face:
     * 1) the face separates the inside domain from the outside (gaps smaller than gap_size are ok):
     *      PW will extract the internal domain starting from the inside side of the face
     * 2) both sides of the face are outside (e.g. gaps/holes bigger than the iondicated sizes):
     *      PW will extract nothing and throw an error for non suitable input
     * 3) both sides of the face are inside:
     *      PW will extract the fluid domain on both side of the faces
     * 
     * FIXME: faces separating two fluid domains (as in case 3) are not supported yet 
     * in the output and will leads to unexpected results for now 
     *
     */
    HRESULT AddInternalWrapConstraint(CATListValCATMshTag& listOfTag);
    HRESULT AddInternalWrapConstraint(CATLISTP(CATPolyFace)& listOfPolyFaces);

    /**
     * Generate a mesh.
     * Perform the meshing and create the result as mesh and as a CATPolyBody.
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
     * Get the result as a CATPolyBody
     * @return
     *   The polyBody.
     * It is up to the user to release the PolyBody properly.
     */
    virtual CATPolyBody* GetPolyBody(CATPolyBodyNaryObserver* observer = nullptr);

protected: 

    /**
     * Import of input PolyBody
     *
     * The Polybody is imported, converted into a mesh to be handed to cvm, a bridge is created for associativity
     * (observer not implemented yet).
     * Furthermore, all CATPolyVolumes are added as explicit domains 
     * (to enable wrapping of these volumes in case of missing triangles after NRU).
     * The method is automatically called in Init().
     */
    HRESULT Import(CATPolyBody * polyBody);

};

#endif
