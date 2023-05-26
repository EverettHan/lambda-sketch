#ifndef CAT3DCanonicalCurvedPipeRep_h_
#define CAT3DCanonicalCurvedPipeRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathDirection.h"
#include "CATMathPoint.h"

#include <vector>

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalCurvedPipeRep represents a canonical pipe that follows a custom curve.
*/
class ExportedBySGInfra CAT3DCanonicalCurvedPipeRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a 3D pipe following the path of a given 3D curve. If the curve is a circle, please use CAT3DCanonicalTorusRep instead.
    * The pipe is made from the sweep of a 3D disk following the path of the curve.
    *
    * @param iCurvePoints
    *     The 3D points that describe the curve of the pipe.
    * @param iPipeRadius
    *     The radius of the pipe (iPipeRadius > 0.0).
    * @param iStartNormal
    *     The orientation of the first disk of the pipe.
    * @param iEndNormal
    *     The orientation of the last disk of the pipe.
    */
    static CAT3DCanonicalCurvedPipeRep* CreateRep(const std::vector<CATMathPoint>&  iCurvePoints,
                                                  const double                      iPipeRadius,
                                                  const CATMathDirection&           iStartNormal,
                                                  const CATMathDirection&           iEndNormal);
    static CAT3DCanonicalCurvedPipeRep* CreateRep();

protected:

    virtual ~CAT3DCanonicalCurvedPipeRep();

public:

    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The recorded 3D points that describe the curve of the pipe.
    */
    virtual HRESULT GetPipeCurve(std::vector<CATMathPoint>& oCurvePoints) const;

    /**
    * The radius of the pipe.
    */
    virtual HRESULT GetRadius(double& oRadius) const;

    /**
    * The orientation of the first and last disks of the pipe.
    */
    virtual HRESULT GetNormals(CATMathDirection& oStartNormal, CATMathDirection& oEndNormal) const;

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
    virtual HRESULT Modify(const std::vector<CATMathPoint>& iCurvePoints,
                           const double                     iPipeRadius,
                           const CATMathDirection&          iStartNormal,
                           const CATMathDirection&          iEndNormal);

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
    CAT3DCanonicalCurvedPipeRep();

    // Canonical data = 32 bytes + n*4*3 bytes for CircleCenters (+ 8 bytes in RAM for the pointer)
    CATUINT32   _nbCircles;
    float*      _circleCenters;
    float       _startNormal[3];
    float       _endNormal[3];
    float       _radius;
};

#endif // !CAT3DCanonicalCurvedPipeRep_h_
