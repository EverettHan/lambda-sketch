#ifndef CAT3DCanonicalConeRep_h_
#define CAT3DCanonicalConeRep_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"
// SGInfra (PrivateInterfaces)
#include "CAT3DCanonicalRep.h"

// Mathematics (PublicInterfaces)
#include "CATMathPoint.h"
#include "CATMathVector.h"

//
// WARNING: LIMITED USE ONLY!
//          YOU NEED TO ASK SCENEGRAPH TEAM (E8C, HQ4) BEFORE USING THIS CLASS!
//

/**
* CAT3DCanonicalConeRep represents a canonical cone pipe.
*/
class ExportedBySGInfra CAT3DCanonicalConeRep final : public CAT3DCanonicalRep
{
    CATDeclareClass;

public:
    /**
    * Constructs a 3D cone from its bottom face center coordinates, its top face center coordinates, and its bottom and top radii.
    *
    * @param iBottomCenterPoint
    *     The coordinates of the cone bottom face center.
    * @param iTopCenterPoint
    *     The coordinates of the cone top face center.
    * @param iBottomRadius
    *     The radius of the bottom face (iBottomRadius > 0.0).
    * @param iTopRadius
    *     The radius of the top face (iTopRadius >= 0.0 && iTopRadius < iBottomRadius).
    */
    static CAT3DCanonicalConeRep* CreateRep(const CATMathPoint& iBottomCenterPoint, const CATMathPoint& iTopCenterPoint, const double iBottomRadius, const double iTopRadius = 0.);
    static CAT3DCanonicalConeRep* CreateRep();

protected:
  
    virtual ~CAT3DCanonicalConeRep();

public:

    virtual CAT3DCanonicalRepType GetCanonicalType() const;

    virtual unsigned int GetSizeInBytes(int iIncludeStructuralSize = 1);

    /**
    * The bottom face center coordinates and top face center coordinates of the cone.
    */
    virtual HRESULT GetPoints(CATMathPoint& oBottomCenterPoint, CATMathPoint& oTopCenterPoint) const;

    /**
    * The bottom face radius and top face radius of the cone.
    */
    virtual HRESULT GetRadii(double& oBottomRadius, double& oTopRadius) const;

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
    virtual HRESULT Modify(const CATMathPoint& iBottomCenterPoint, const CATMathPoint& iTopCenterPoint, const double iBottomRadius, const double iTopRadius);

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
    CAT3DCanonicalConeRep();

    // Canonical data = 32 bytes
    float   _bottomCenter[3];
    float   _topCenter[3];
    float   _bottomRadius;
    float   _topRadius;
};

#endif // !CAT3DCanonicalConeRep_h_
