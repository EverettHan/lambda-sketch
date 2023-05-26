#ifndef CAT3DCanonicalSphereRep_h_
#define CAT3DCanonicalSphereRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalSphereRep represents a canonical sphere.
*/
class ExportedBySGInfra CAT3DCanonicalSphereRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a full 3D sphere from a center point and a radius.
    * For partial 3D spheres: see CAT3DCanonicalPartialSphereRep.
    *
    * @param iCenter
    *     The 3D position of the center of the sphere.
    * @param iRadius
    *     The radius of the sphere (iRadius > 0.0).
    */
    static CAT3DCanonicalSphereRep* CreateRep(const CATMathPoint& iCenter, const double iRadius);
    static CAT3DCanonicalSphereRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalSphereRep();

public:
    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The coordinates of the center point of the sphere.
    */
    virtual HRESULT GetCenter(CATMathPoint& oCenter) const;

    /**
    * The radius of the sphere.
    */
    virtual HRESULT GetRadius(double& oRadius) const;

    /**
     *	Compute BBox based on canonical information.
     */
    virtual HRESULT GetBoundingBox(CATMathPoint& oBBoxMin, CATMathPoint& oBBoxMax) const;

    /**
     *	@brief DMU stream
     */
    virtual void Stream(CATStreamer& oStream, int iSaveType = 0);

    /**
    *	@brief DMU stream
    */
    virtual void UnStream(CATStreamer& iStream);

    /**
     *	@brief Render handling
     */
    virtual void DrawShading(CATRender& iRender, int iInside);

protected:
    virtual HRESULT Modify(const CATMathPoint& iCenter, const double iRadius);

    virtual HRESULT BuildMesh(float const ** oVertices,
                              int          * oVerticesArraySize,
                              float const ** oNormals,
                              int          * oNormalsArraySize,
                              int   const ** oTriangleIndices,
                              int          * oNbTriangle,
                              int   const ** oTriangleStripIndices,
                              int          * oNbTriangleStrip,
                              int   const ** oNbVertexPerTriangleStrip,
                              int   const ** oTriangleFanIndices,
                              int          * oNbTriangleFan,
                              int   const ** oNbVertexPerTriangleFan,
                              int          * oNbVisuEdges,
                              int   const ** oNbVertexPerVisuEdge,
                              int   const ** oVisuEdgeIndices) override;

private:
    CAT3DCanonicalSphereRep();

    // Canonical data = 16 bytes
    float   _center[3];
    float   _radius;
};

#endif // !CAT3DCanonicalSphereRep_h_
