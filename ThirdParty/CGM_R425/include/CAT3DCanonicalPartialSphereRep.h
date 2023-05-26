#ifndef CAT3DCanonicalPartialSphereRep_h_
#define CAT3DCanonicalPartialSphereRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"
#include "CATMathDirection.h"
#include "CATMathAxis.h"
#include "CATMathConstant.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalPartialSphereRep represents a canonical rectangular spherical patch.
*/
class ExportedBySGInfra CAT3DCanonicalPartialSphereRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a partial 3D sphere from an axis system a radius and two angles.
    * For full 3D spheres: see CAT3DCanonicalSphereRep.
    *
    * @param iAxisSystem
    *     The (O,X,Y,Z) axis system, whose center is the sphere center.
    * @param iRadius
    *     The radius of the sphere (iRadius > 0.0).
    * @param iMeridianStartAngle
    *     The start of the circular span of the sphere geometry in the meridian (O,X,Y) plane (0.0 <= iMeridianStartAngle < 2*pi).
    * @param iMeridianEndAngle
    *     The end of the circular span of the sphere geometry in the meridian (O,X,Y) plane (0.0 < iMeridianEndAngle <= 2*pi).
    * @param iParallelStartAngle
    *     The start of the circular span of the sphere geometry in the parallel (O,X,Z) plane (-pi/2 <= iParallelStartAngle < pi/2).
    * @param iParallelEndAngle
    *     The end of the circular span of the sphere geometry in the parallel (O,X,Z) plane (-pi/2 < iParallelEndAngle <= pi/2).
    */
    static CAT3DCanonicalPartialSphereRep* CreateRep(const CATMathAxis& iAxisSystem,
                                                     const double       iRadius,
                                                     const CATAngle     iMeridianStartAngle,
                                                     const CATAngle     iMeridianEndAngle,
                                                     const CATAngle     iParallelStartAngle,
                                                     const CATAngle     iParallelEndAngle);
    static CAT3DCanonicalPartialSphereRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalPartialSphereRep();

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
    * The normalized (O,X,Y,Z) axis system that defines the meridian (O,X,Y) and parallel planes (O,X,Z) used in the creation of the sphere.
    */
    virtual HRESULT GetAxisSystem(CATMathDirection& oFirstAxis, CATMathDirection& oSecondAxis, CATMathDirection& oThirdAxis) const;

    /**
    * The circular span of the sphere geometry in the meridian (O,X,Y) and parallel (O,X,Z) planes.
    */
    virtual HRESULT GetAngles(CATAngle& oMeridianStartAngle, CATAngle& oMeridianEndAngle, CATAngle& oParallelStartAngle, CATAngle& oParallelEndAngle) const;

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
    virtual HRESULT Modify(const CATMathAxis&   iAxisSystem,
                           const double         iRadius,
                           const CATAngle       iMeridianStartAngle,
                           const CATAngle       iMeridianEndAngle,
                           const CATAngle       iParallelStartAngle,
                           const CATAngle       iParallelEndAngle);

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
    CAT3DCanonicalPartialSphereRep();

    // Canonical data = 52 bytes
    float   _center[3];
    float   _firstAxis[3]; // <- contains Radius
    float   _secondAxis[3];
    //float _thirdAxis[3]; // <- computed from FirstAxis & SecondAxis
    //float _radius; // <- computed from length of FirstAxis
    float   _meridianStartAngle;
    float   _meridianEndAngle;
    float   _parallelStartAngle;
    float   _parallelEndAngle;
};

#endif // !CAT3DCanonicalPartialSphereRep_h_
