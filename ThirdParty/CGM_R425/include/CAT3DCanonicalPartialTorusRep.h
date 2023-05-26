#ifndef CAT3DCanonicalPartialTorusRep_h_
#define CAT3DCanonicalPartialTorusRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathAxis.h"
#include "CATMathConstant.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalPartialTorusRep represents a canonical torus pipe.
*/
class ExportedBySGInfra CAT3DCanonicalPartialTorusRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a partial 3D torus from an axis system, two radii, and an angle.
    * The torus is made from the revolution of a 3D disk (minor circle) following the path of a virtual ring (major circle) around the center of the axis system.
    * For full 3D torus: see CAT3DCanonicalTorusRep.
    *
    * @param iAxisSystem
    *     The (O,X,Y,Z) axis system.
    * @param iMinorRadius
    *     The minor circle radius on the (O,X,Z) plane (iMinorRadius > 0.0).
    * @param iMajorRadius
    *     The major circle radius on the (O,X,Y) plane (iMajorRadius > iMinorRadius).
    * @param iMajorAngle
    *     The circular span of the torus geometry in the (O,X,Y) plane (iMajorAngle > 0.0 && iMajorAngle < 2*pi).
    */
    static CAT3DCanonicalPartialTorusRep* CreateRep(const CATMathAxis& iAxisSystem, const double iMinorRadius, const double iMajorRadius, const CATAngle iMajorAngle);
    static CAT3DCanonicalPartialTorusRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalPartialTorusRep();

public:

    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The normalized (O,X,Y,Z) axis system used in the creation of the torus.
    */
    virtual HRESULT GetAxisSystem(CATMathAxis& oAxisSystem) const;

    /**
    * The radius of the pipe geometry (minor) and the radius of the pipe curvature (major).
    */
    virtual HRESULT GetRadii(double& oMinorRadius, double& oMajorRadius) const;

    /**
    * The circular span of the torus geometry in the (O,X,Y) plane.
    */
    virtual HRESULT GetMajorAngle(CATAngle& oMajorAngle) const;

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
    virtual HRESULT Modify(const CATMathAxis& iAxisSystem, const double iMinorRadius, const double iMajorRadius, const CATAngle iMajorAngle);

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
    CAT3DCanonicalPartialTorusRep();

    // Canonical data = 44 bytes
    float   _torusCenter[3];
    float   _torusFirstAxis[3]; // <- contains MajorRadius
    float   _torusSecondAxis[3];
    //float _torusThirdAxis[3]; // <- computed from FirstAxis & SecondAxis
    float   _minorRadius;
    //float _majorRadius; // <- computed from length of FirstAxis
    float   _majorAngle;
};

#endif // !CAT3DCanonicalPartialTorusRep_h_
