#ifndef CAT3DCanonicalTorusRep_h_
#define CAT3DCanonicalTorusRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"
#include "CATMathDirection.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalTorusRep represents a canonical torus pipe.
*/
class ExportedBySGInfra CAT3DCanonicalTorusRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a 3D torus from a center position, a plane, and two radii.
    * The torus is made from the revolution of a 3D disk (minor circle) following the path of a virtual ring (major circle) around a center point inside the torus plane.
    * For partial 3D torus: see CAT3DCanonicalPartialTorusRep.
    *
    * @param iTorusPlaneCenter
    *     The center of the virtual ring (major circle) that describes the pipe's curvature.
    * @param iTorusPlaneNormal
    *     The normal of the plane on which the virtual ring (major circle) is defined.
    * @param iMinorRadius
    *     The radius of the pipe geometry (minor circle).
    * @param iMajorRadius
    *     The radius of the pipe curvature (major circle).
    */
    static CAT3DCanonicalTorusRep* CreateRep(const CATMathPoint& iTorusPlaneCenter, const CATMathDirection& iTorusPlaneNormal, const double iMinorRadius, const double iMajorRadius);
    static CAT3DCanonicalTorusRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalTorusRep();

public:
    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The plane used in the construction of the torus pipe.
    */
    virtual HRESULT GetTorusPlane(CATMathPoint& oTorusPlaneCenter, CATMathDirection& oTorusPlaneNormal) const;

    /**
    * The radius of the pipe geometry (minor circle) and the radius of the pipe curvature (major circle).
    */
    virtual HRESULT GetRadii(double& oMinorRadius, double& oMajorRadius) const;

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
    virtual HRESULT Modify(const CATMathPoint& iTorusPlaneCenter, const CATMathDirection& iTorusPlaneNormal, const double iMinorRadius, const double iMajorRadius);

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
    CAT3DCanonicalTorusRep();

    // Canonical data = 28 bytes
    float   _torusPlaneCenter[3];
    float   _torusPlaneNormal[3]; // <- contains MajorRadius
    float   _minorRadius;
    //float _majorRadius; // <- stored in TorusPlaneNormal
};

#endif // !CAT3DCanonicalTorusRep_h_
